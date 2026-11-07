#include "spirit_bugs.h"

#include "entity.h"
#include "file.h"
#include "global.h"
#include "inline.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"

// 精霊虫1匹, state で sSwarmUpdates[kind * 5 + state] のハンドラに分岐する, 根拠: Entity0800a89c_UpdateSwarm
typedef struct {
  u8 state;           // 0x00, ハンドラの添字, 0 は未使用
  u8 speed;           // 0x01, gSineTable との積が速度になる, 根拠: FUN_0800b068
  u8 angle;           // 0x02, gSineTable の添字 (向き)
  s8 turnTimer;       // 0x03, 符号が旋回方向, 0 になると gRandomTable から引き直す, 根拠: FUN_0800b068 の ldrsb
  u16 timer;          // 0x04, 状態ごとのカウンタ, 生成時は寿命, 根拠: SpawnSpiritBugs / FUN_0800b068
  u16 unk_6;          // 0x06, 状態遷移用の第2カウンタ (点滅回数など), 生成時は u32_ARRAY_085aa700[kind], 根拠: FUN_0800b7a0
  Vec3 vel;           // 0x08, 毎フレーム ptcl.pos に加算される, 根拠: FUN_0800b068
  Vec3 target;        // 0x10, 向かう先, 生成時は ptcl.pos のコピー, 根拠: SpawnSpiritBugs / ArcTan2_8 の入力
  AuxAnimState anim;  // 0x18
  Particle ptcl;      // 0x28
} SpiritBug;
static_assert(sizeof(SpiritBug) == 80);

// 1回の発生でまとめて出る精霊虫の群れ, SpawnSpiritBugs が空きスロットを探して作る
typedef struct {
  bool8 active;       // 0x00
  u8 aliveCount;      // 0x01, 生存中の bugs の数 (最大4), 0 になると Entity0800a89c_ReleaseSwarm で解放, 根拠: FUN_0800be38
  u8 kind;            // 0x02, 0..2 (Sol/Luna/Dark), sSpiritBugHandler や gSpiritBugsSoundIDs の添字
  u8 amount;          // 0x03, sSpiritBugHandler[kind](Player*, s32) の第2引数, 根拠: FUN_0800b068
  u8 soundDelay;      // 0x04, 0 になった瞬間に gSoundIDs_085aa724[kind] を鳴らす, 根拠: Entity0800a89c_Update
  u8 unk_5;           // 0x05, 読み手も書き手も未発見, padding?
  u16 timer;          // 0x06, 生成時 40, 0 になるまでプレイヤーに回収されない
  SpiritBug bugs[4];  // 0x08
} SpiritBugSwarm;
static_assert(sizeof(SpiritBugSwarm) == 328);

// 精霊虫 (太陽虫/月光虫/暗黒虫) をまとめて管理するエンティティ, 群れを6つまで同時に持てる
typedef struct {
  Entity e;                  // 0x0, ENTITY_UNK_8
  bool32 isSabata;           // 0x18
  u32 frameCounter;          // 0x1C, 下位ビットで虫の更新を間引く
  ParticleGroup* group0;     // 0x20, PTCL_GROUP_0 (PTCL0_SOLARBUG, PTCL0_MOONBUG, PTCL0_DARKBUG)
  AuxAnimFile* anim;         // 0x24
  SpiritBugSwarm swarms[6];  // 0x28, 根拠: Entity0800a89c_Init / _Destroy が stride 0x148 で6回まわす
  Player* player;            // 0x7D8, 根拠: 0x0800a860
} SpiritBugsManager;
static_assert(sizeof(SpiritBugsManager) == 2012);

// Entity0800a89c_Update が群れごとに組んで虫のハンドラに渡す回収判定の枠, min/max は視点座標
typedef struct {
  WorldPos pos;    // 0x00, 暗黒虫はプレイヤーの位置, それ以外はプレイヤーの横上 (向きで左右が変わる)
  Vec3 posMin;     // 0x08, pos の視点座標から (5, 5) 引いた点
  Vec3 posMax;     // 0x10, pos の視点座標に (5, 5) 足した点
  Vec3 playerMin;  // 0x18, プレイヤーの視点座標から (8, 20) 引いた点
  Vec3 playerMax;  // 0x20, プレイヤーの視点座標に (8, 20) 足した点
} SpiritBugScreenBox;

static SpiritBugsManager* sSpiritBugsManager;  // 0x03000044

const u16 sBugsAnimIdx[12] = {4, 0, 5, 0, 6, 0, 6, 0, 5, 0, 4, 0};  // 0x085AA6D0

// 回収されたときのアニメ番号, 並びは sBugsAnimIdx と同じ
const u16 sBugsCollectedAnimIdx[12] = {9, 0, 10, 0, 11, 0, 11, 0, 10, 0, 9, 0};  // 0x085AA6E8

const u32 u32_ARRAY_085aa700[3] = {10, 10, 120};  // 0x085AA700

// 精霊虫の効果
void Player_ApplySolarbug(Player*, s32);
void Player_ApplyMoonbug(Player*, s32);
void Player_ApplyDarkbug(Player*, s32);

void (*const sSpiritBugHandler[3])(Player*, s32) = {
    [SOLARBUG] = Player_ApplySolarbug,
    [MOONBUG] = Player_ApplyMoonbug,
    [DARKBUG] = Player_ApplyDarkbug,
};  // 0x085AA70C

const SoundID32 gSpiritBugsSoundIDs[3] = {
    [SOLARBUG] = SE_TOUCH_SOLARBUG,
    [MOONBUG] = SE_TOUCH_MOONBUG,
    [DARKBUG] = SE_SPIRIT_BUGS_282,
};  // 0x085AA718

const SoundID32 gSoundIDs_085aa724[3] = {
    [SOLARBUG] = SE_SPIRIT_BUGS_659,
    [MOONBUG] = SE_SPIRIT_BUGS_658,
    [DARKBUG] = SE_SPIRIT_BUGS_657,
};  // 0x085AA724

static inline Player* GetPlayer(s32 idx) { return gPlayerPtr[idx]; }

void FUN_0800a488(void) { sSpiritBugsManager = NULL; }

// 群れの虫4匹の Particle を解放してスロットを空きに戻す
s32 Entity0800a89c_ReleaseSwarm(SpiritBugsManager* p, SpiritBugSwarm* swarm) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&swarm->bugs[i].ptcl);
  }
  swarm->active = FALSE;
}

// 出ている精霊虫を全部消す
s32 Entity0800a89c_ReleaseAll(void) {
  SpiritBugsManager* p = sSpiritBugsManager;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  for (i = 0; i < 6; i++) {
    if (p->swarms[i].active) {
      Entity0800a89c_ReleaseSwarm(p, &p->swarms[i]);
    }
  }
  return 0;
}

// 0x4631
s32 Cmd_RemoveAllSpiritBugs(void) { return Entity0800a89c_ReleaseAll(); }

// sSwarmUpdates の中身, frameBit/framePhase は SpiritBugsManager.frameCounter の下位ビットで、 box は Entity0800a89c_Update がスタックに組む回収判定用の枠
// 表は kind * 5 + SpiritBug.state で引くので、横1行が1つの kind、列が state 0..4 に対応する
// state 1 が徘徊+回収待ち、2 がプレイヤーへの吸い寄せ、3 が点滅して消滅、4 が回収成立, state 0 は空きスロットで何もしない
typedef void (*SpiritBugHandler)(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, SpiritBugScreenBox* box);

void FUN_0800b064(SpiritBugsManager*, SpiritBugSwarm*, s32, u32, u32, SpiritBugScreenBox*);
void FUN_0800b068(SpiritBugsManager*, SpiritBugSwarm*, s32, u32, u32, SpiritBugScreenBox*);
void FUN_0800b7a0(SpiritBugsManager*, SpiritBugSwarm*, s32, u32, u32, SpiritBugScreenBox*);
void FUN_0800be38(SpiritBugsManager*, SpiritBugSwarm*, s32, u32, u32, SpiritBugScreenBox*);
void Entity0800a89c_UpdateCollectedBug(SpiritBugsManager*, SpiritBugSwarm*, s32, u32, u32, SpiritBugScreenBox*);
void FUN_0800b404(SpiritBugsManager*, SpiritBugSwarm*, s32, u32, u32, SpiritBugScreenBox*);
void FUN_0800ba78(SpiritBugsManager*, SpiritBugSwarm*, s32, u32, u32, SpiritBugScreenBox*);

// 群れの虫4匹を、虫ごとの state に対応するハンドラに流す
s32 Entity0800a89c_UpdateSwarm(SpiritBugsManager* p, SpiritBugSwarm* swarm, SpiritBugScreenBox* box) {
  static const SpiritBugHandler sSwarmUpdates[15] = {
      FUN_0800b064,
      FUN_0800b068,
      FUN_0800b7a0,
      FUN_0800be38,
      Entity0800a89c_UpdateCollectedBug,
      FUN_0800b064,
      FUN_0800b068,
      FUN_0800b7a0,
      FUN_0800be38,
      Entity0800a89c_UpdateCollectedBug,
      FUN_0800b064,
      FUN_0800b404,
      FUN_0800ba78,
      FUN_0800be38,
      Entity0800a89c_UpdateCollectedBug,
  };  // 0x085AA730

  u32 frameBit = p->frameCounter & 1;
  u32 framePhase = p->frameCounter & 3;
  SpiritBug* bug;
  s32 i;

  for (i = 0, bug = swarm->bugs; i < 4; i++) {
    sSwarmUpdates[swarm->kind * 5 + bug->state](p, swarm, i, frameBit, framePhase, box);
    bug++;
  }
}

// 群れごとに回収判定の枠を組んでハンドラを回し, 出現音の遅延と回収待ちのタイマーを進める
// 下書き (277/279命令): 原典は群れを2本の誘導変数で回す (呼び出しに &p->swarms[i], 読み書きに swarm を使うと 278 命令で形が揃う), 残りは p と swarm のレジスタの入れ替わり
NON_MATCH s32 Entity0800a89c_Update(SpiritBugsManager* p) {
#ifdef NONMATCHING_C
  WorldPos playerPos;
  Vec3 playerVp;
  SpiritBugSwarm* swarm;
  s32 i;

  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_EVENT) && !TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_UNK_8)) {
    return 0;
  }

  playerPos.x = p->player->mover.pos.x;
  playerPos.y = p->player->mover.pos.y + 0x80;
  playerPos.z = p->player->mover.pos.z;
  WorldToVp(&playerVp, &playerPos);

  for (i = 0, swarm = p->swarms; i < 6; i++, swarm++) {
    if (swarm->active) {
      SpiritBugScreenBox box;

      if (swarm->kind == DARKBUG) {
        box.pos.x = playerPos.x;
        box.pos.y = playerPos.y;
        box.pos.z = playerPos.z;
      } else if (p->player->facing == 0) {
        box.pos.x = p->player->mover.pos.x + 24;
        box.pos.y = 350 + p->player->mover.pos.y;
        box.pos.z = p->player->mover.pos.z - 24;
      } else {
        box.pos.x = p->player->mover.pos.x - 32;
        box.pos.y = 320 + p->player->mover.pos.y;
        box.pos.z = p->player->mover.pos.z + 32;
      }
      WorldToVp(&box.posMin, &box.pos);
      box.posMax = box.posMin;
      box.posMin.x -= 5;
      box.posMin.y -= 5;
      box.posMax.x += 5;
      box.posMax.y += 5;
      box.playerMin = playerVp;
      box.playerMax = playerVp;
      box.playerMin.x -= 8;
      box.playerMin.y -= 20;
      box.playerMax.x += 8;
      box.playerMax.y += 20;
      Entity0800a89c_UpdateSwarm(p, swarm, &box);
      if (swarm->soundDelay != 0 && --swarm->soundDelay == 0) {
        PlaySound_0824078c(gSoundIDs_085aa724[swarm->kind]);
      }
      if (swarm->timer != 0) {
        swarm->timer--;
      }
    }
  }
  p->frameCounter++;
  return 0;
#else
  INCFUNC("asm/func/Entity0800a89c_Update.inc");
#endif
}

s32 Entity0800a89c_Destroy(SpiritBugsManager* p) {
  s32 i, j;

  for (i = 0; i < 6; i++) {
    SpiritBugSwarm* swarm = &p->swarms[i];

    if (swarm->active) {
      for (j = 0; j < 4; j++) {
        Particle_Remove(&swarm->bugs[j].ptcl);
      }
    }
  }
  sSpiritBugsManager = NULL;
  return 0;
}

// 群れ6つ分の Particle を確保し、サバタかどうかを覚えておく (使うアニメーションが変わる)
s32 Entity0800a89c_Init(SpiritBugsManager* p, u32 id) {
  s32 i, j;

  sSpiritBugsManager = p;
  p->group0 = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, ANIM_D1B8);
  for (i = 0; i < 6; i++) {
    SpiritBugSwarm* swarm = &p->swarms[i];

    swarm->active = FALSE;
    for (j = 0; j < 4; j++) {
      Particle_Setup(&swarm->bugs[j].ptcl, p->group0, SPRFLAG_HIDDEN);
      Particle_SetPltt(&swarm->bugs[j].ptcl, 1);
    }
  }
  p->frameCounter = 0;

  p->player = GetPlayer(0);
  if (p->player == NULL) {
    return -1;
  }
  if (p->player->kind == PLAYER_SABATA) {
    p->isSabata = TRUE;
  } else {
    p->isSabata = FALSE;
  }
  return 0;
}

SpiritBugsManager* Entity0800a89c_Create(u32 id) {
  SpiritBugsManager* p = CreateEntity(ENTITY_UNK_8, sizeof(SpiritBugsManager));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0800a89c_Update, Entity0800a89c_Destroy);
    if (Entity0800a89c_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// kind = SpiritBugKind (bit4 以降は別の意味?), amount = 効果量 (sSpiritBugHandler の 第2引数)
NAKED s32 SpawnSpiritBugs(u32 count, s32 kind, s32 amount, Vec3* pos, Vec3* spread, s32 lifetime, s32 lifetimeRand) { INCFUNC("asm/func/SpawnSpiritBugs.inc"); }

// kind = SpiritBugKind, amount = 効果量 (sSpiritBugHandler の 第2引数)
NAKED s32 SpawnSpiritBugsAt(u32 count, s32 kind, s32 amount, Vec3* pos, Vec3* perBugPos, s32 lifetime, s32 lifetimeRand) { INCFUNC("asm/func/SpawnSpiritBugsAt.inc"); }

// 出ている精霊虫の総数を数える
u32 Entity0800a89c_CountBugs(void) {
  SpiritBugsManager* p = sSpiritBugsManager;
  u32 count;
  s32 i;

  if (p == NULL) {
    return 0;
  }
  count = 0;
  for (i = 0; i < 6; i++) {
    if (p->swarms[i].active) {
      count += p->swarms[i].aliveCount;
    }
  }
  return count;
}

// kind 2 (Dark) の群れを kind 0 に変えてアニメと寿命を入れ直す
NON_MATCH void Entity0800a89c_PurifyDarkBugs(void) {
#ifdef NONMATCHING_C
  SpiritBugsManager* p = sSpiritBugsManager;
  s32 i, j;

  if (p == NULL) {
    return;
  }
  for (i = 0; i < 6; i++) {
    SpiritBugSwarm* swarm = &p->swarms[i];

    if (swarm->active && swarm->kind == 2) {
      swarm->kind = 0;
      for (j = 0; j < 4; j++) {
        if (swarm->bugs[j].state != 0) {
          AuxAnim_SetAnim(&swarm->bugs[j].anim, p->anim, sBugsAnimIdx[(p->isSabata * 3 + swarm->kind) * 2], 0, 0);
          if (swarm->bugs[j].state < 3 && swarm->bugs[j].timer < SECOND(3)) {
            swarm->bugs[j].timer = SECOND(3);
          }
        }
      }
    }
  }
#else
  INCFUNC("asm/func/Entity0800a89c_PurifyDarkBugs.inc");
#endif
}

// state 0 (空きスロット) のハンドラ, 何もしない
void FUN_0800b064(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, SpiritBugScreenBox* box) {}

// 太陽虫と月光虫の state 1, 目標の周りを旋回しながら漂い, 画面上でプレイヤーの枠に入ったら回収して効果を与える, 手をかざされたら state 2 へ
// 下書き (432/432命令): 残差は FUN_0800be38 と同じく旋回で angle へ書く2か所 (原典は &bug->angle のレジスタ経由, こちらは bug+2) と乱数テーブルのレジスタだけ
NON_MATCH void FUN_0800b068(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, SpiritBugScreenBox* box) {
#ifdef NONMATCHING_C
  SpiritBug* bug = &swarm->bugs[bugIdx];
  Vec3* target = &bug->target;
  Particle* ptcl = &bug->ptcl;
  u8* angle = &bug->angle;

  if ((bugIdx & 1) == frameBit) {
    s32 diff = ArcTan2_8(target->x - ptcl->pos.x, target->z - ptcl->pos.z) - bug->angle;

    if (bug->turnTimer < 0) {
      *angle = bug->angle + (abs(diff) <= 4 ? diff : 4);
      if (++bug->turnTimer == 0) {
        bug->turnTimer = (Random() & 0x3F) + 0x40;
      }
    } else {
      *angle = bug->angle - (abs(diff) <= 4 ? diff : 4);
      if (--bug->turnTimer == 0) {
        bug->turnTimer = -(Random() & 0x3F) - 0x40;
      }
    }
    bug->vel.x = (COS(*angle) * bug->speed) >> 12;
    bug->vel.z = (SIN(*angle) * bug->speed) >> 12;
  } else if (swarm->timer == 0) {
    Vec3 vp;

    WorldToVp(&vp, &ptcl->pos);
    if (!TEST_FLAGS(gPlayerModes[0], PMODE_DEAD) && box->playerMin.x <= vp.x && box->playerMax.x >= vp.x && box->playerMin.y <= vp.y && box->playerMax.y >= vp.y) {
      bug->state = 4;
      AuxAnim_SetAnim(&bug->anim, p->anim, sBugsCollectedAnimIdx[(p->isSabata * 3 + swarm->kind) * 2], 0, 0);
      if (!TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
        PlaySound_0824078c(gSpiritBugsSoundIDs[swarm->kind]);
        sSpiritBugHandler[swarm->kind](p->player, swarm->amount);
      }
      return;
    }
  }

  ptcl->pos.x += bug->vel.x;
  {
    s32 dy = box->pos.y - ptcl->pos.y;

    if (dy > 16) {
      ptcl->pos.y += 16;
    } else if (dy < -16) {
      ptcl->pos.y -= 16;
    } else {
      ptcl->pos.y = box->pos.y;
    }
  }
  ptcl->pos.z += bug->vel.z;
  Particle_AdvanceAnim(&bug->ptcl, p->group0, &bug->anim);
  if (swarm->timer == 0 && Player_TestFlag20(p->player, PFLAG20_PALM_UP)) {
    bug->state = 2;
    bug->speed = 18;
  }
  if (--bug->timer == 0) {
    bug->state = 3;
    bug->unk_6 = 10;
  }
#else
  INCFUNC("asm/func/FUN_0800b068.inc");
#endif
}

// 暗黒虫の state 1, 目標の周りを旋回しながら漂い, 画面上で box の枠に入ったら回収して効果を与える, unk_6 が尽きたら state 2 でプレイヤーへ向かう
// 下書き (427/427命令): 残差は FUN_0800be38 / FUN_0800b068 と同じく旋回で angle へ書く2か所 (原典は &bug->angle のレジスタ経由) と乱数テーブルのレジスタだけ
NON_MATCH void FUN_0800b404(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, SpiritBugScreenBox* box) {
#ifdef NONMATCHING_C
  SpiritBug* bug = &swarm->bugs[bugIdx];
  Vec3* target = &bug->target;
  Particle* ptcl = &bug->ptcl;
  u8* angle = &bug->angle;

  if ((bugIdx & 1) == frameBit) {
    s32 diff = ArcTan2_8(target->x - ptcl->pos.x, target->z - ptcl->pos.z) - bug->angle;

    if (bug->turnTimer < 0) {
      *angle = bug->angle + (abs(diff) <= 4 ? diff : 4);
      if (++bug->turnTimer == 0) {
        bug->turnTimer = (Random() & 0x3F) + 0x40;
      }
    } else {
      *angle = bug->angle - (abs(diff) <= 4 ? diff : 4);
      if (--bug->turnTimer == 0) {
        bug->turnTimer = -(Random() & 0x3F) - 0x40;
      }
    }
    bug->vel.x = (COS(*angle) * bug->speed) >> 12;
    bug->vel.z = (SIN(*angle) * bug->speed) >> 12;
  } else if (swarm->timer == 0) {
    Vec3 vp;

    WorldToVp(&vp, &ptcl->pos);
    if (!TEST_FLAGS(gPlayerModes[0], PMODE_DEAD) && box->posMin.x <= vp.x && box->posMax.x >= vp.x && box->posMin.y <= vp.y && box->posMax.y >= vp.y) {
      bug->state = 4;
      AuxAnim_SetAnim(&bug->anim, p->anim, sBugsCollectedAnimIdx[(p->isSabata * 3 + swarm->kind) * 2], 0, 0);
      if (!TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
        PlaySound_0824078c(gSpiritBugsSoundIDs[swarm->kind]);
        sSpiritBugHandler[swarm->kind](p->player, swarm->amount);
      }
      return;
    }
  }

  ptcl->pos.x += bug->vel.x;
  {
    s32 dy = box->pos.y - ptcl->pos.y;

    if (dy > 16) {
      ptcl->pos.y += 16;
    } else if (dy < -16) {
      ptcl->pos.y -= 16;
    } else {
      ptcl->pos.y = box->pos.y;
    }
  }
  ptcl->pos.z += bug->vel.z;
  Particle_AdvanceAnim(&bug->ptcl, p->group0, &bug->anim);
  if (bug->unk_6 == 0) {
    bug->state = 2;
    bug->speed = 15;
    bug->unk_6 = 10;
    bug->timer = (Random() & 0x1F) + 60;
  } else {
    bug->unk_6--;
  }
#else
  INCFUNC("asm/func/FUN_0800b404.inc");
#endif
}

// 太陽虫と月光虫の state 2, 手をかざしているプレイヤーへ吸い寄せられ, 近づいたら回収して効果を与える, かざすのをやめたら state 1 へ戻る
void FUN_0800b7a0(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, SpiritBugScreenBox* box) {
  SpiritBug* bug = &swarm->bugs[bugIdx];
  Particle* ptcl = &bug->ptcl;

  if ((bugIdx & 1) == frameBit) {
    s32 dx = box->pos.x - ptcl->pos.x;
    s32 dy = box->pos.y - ptcl->pos.y + 164;
    s32 dz = box->pos.z - ptcl->pos.z;

    bug->angle = ArcTan2_8(dx, dz);
    bug->vel.x = (COS(bug->angle) * bug->speed) >> 12;
    bug->vel.z = (SIN(bug->angle) * bug->speed) >> 12;
    if (!TEST_FLAGS(gPlayerModes[0], PMODE_DEAD) && swarm->timer == 0 && abs(dy) <= 179 && dx * dx + dz * dz <= 399) {
      bug->state = 4;
      AuxAnim_SetAnim(&bug->anim, p->anim, sBugsCollectedAnimIdx[(p->isSabata * 3 + swarm->kind) * 2], 0, 0);
      if (!TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
        PlaySound_0824078c(gSpiritBugsSoundIDs[swarm->kind]);
        sSpiritBugHandler[swarm->kind](p->player, swarm->amount);
      }
      return;
    }
  }

  ptcl->pos.x += bug->vel.x;
  {
    s32 dy = box->pos.y - ptcl->pos.y;

    if (dy > 16) {
      ptcl->pos.y += 16;
    } else if (dy < -16) {
      ptcl->pos.y -= 16;
    } else {
      ptcl->pos.y = box->pos.y;
    }
  }
  ptcl->pos.z += bug->vel.z;
  Particle_AdvanceAnim(&bug->ptcl, p->group0, &bug->anim);
  if (!Player_TestFlag20(p->player, PFLAG20_PALM_UP) || TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    u16* table;

    bug->state = 1;
    table = gRandomTable;
    bug->speed = (_Random(table) & 3) + 4;
    bug->angle = _Random(table);
  }
  if (--bug->timer == 0) {
    bug->state = 3;
    bug->unk_6 = 10;
  }
}

// 暗黒虫の state 2, プレイヤーへ向かって飛び, 近づいたら回収して効果を与える, 寿命が切れたら state 3 へ
// 下書き (294/296命令): 原典は box を sl に置くが, こちらは引数のスタックから毎回読む, 先頭で SpiritBugScreenBox* のローカルに写すと 296 命令になり swarm / box / 定数 4 の高位レジスタの割り当てだけが入れ替わる (同形の FUN_0800b7a0 は一致)
NON_MATCH void FUN_0800ba78(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, SpiritBugScreenBox* box) {
#ifdef NONMATCHING_C
  SpiritBug* bug = &swarm->bugs[bugIdx];
  Particle* ptcl = &bug->ptcl;

  if ((bugIdx & 1) == frameBit) {
    s32 dx = box->pos.x - ptcl->pos.x;
    s32 dy = box->pos.y - ptcl->pos.y + 0x80;
    s32 dz = box->pos.z - ptcl->pos.z;

    bug->angle = ArcTan2_8(dx, dz);
    bug->vel.x = (COS(bug->angle) * bug->speed) >> 12;
    bug->vel.z = (SIN(bug->angle) * bug->speed) >> 12;
    if (!TEST_FLAGS(gPlayerModes[0], PMODE_DEAD) && swarm->timer == 0 && abs(dy) <= 129 && dx * dx + dz * dz <= 399) {
      bug->state = 4;
      AuxAnim_SetAnim(&bug->anim, p->anim, sBugsCollectedAnimIdx[(p->isSabata * 3 + swarm->kind) * 2], 0, 0);
      if (!TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
        PlaySound_0824078c(gSpiritBugsSoundIDs[swarm->kind]);
        sSpiritBugHandler[swarm->kind](p->player, swarm->amount);
      }
      return;
    }
  }

  ptcl->pos.x += bug->vel.x;
  {
    s32 dy = box->pos.y - ptcl->pos.y;

    if (dy > 16) {
      ptcl->pos.y += 16;
    } else if (dy < -16) {
      ptcl->pos.y -= 16;
    } else {
      ptcl->pos.y = box->pos.y;
    }
  }
  ptcl->pos.z += bug->vel.z;
  Particle_AdvanceAnim(&bug->ptcl, p->group0, &bug->anim);
  if (--bug->timer == 0) {
    bug->state = 3;
    bug->unk_6 = 15;
  }
#else
  INCFUNC("asm/func/FUN_0800ba78.inc");
#endif
}

// state 4 (プレイヤーに回収された) のハンドラ, アニメを1コマ進め、一巡したら虫を消す
void Entity0800a89c_UpdateCollectedBug(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, SpiritBugScreenBox* box) {
  SpiritBug* bug = &swarm->bugs[bugIdx];
  Particle* ptcl = &bug->ptcl;

  if (Particle_AdvanceAnim(&bug->ptcl, p->group0, &bug->anim)) {
    bug->state = 0;
    ptcl->flags |= SPRFLAG_HIDDEN;
    swarm->aliveCount--;
    if (swarm->aliveCount == 0) {
      Entity0800a89c_ReleaseSwarm(p, swarm);
    }
  }
}

// 目標へ向き直りながら飛び, 点滅しながら unk_6 を減らして 0 になったら消える
// 残差は旋回時の angle への書き込み2か所 (原典は &bug->angle のレジスタ経由, こちらは bug+2) と乱数テーブルのレジスタのみ (295/295), 手動送りは Particle_AdvanceAnim で一致
// 旋回部分の inline 化 (if の内外), 差分を bug->angle で取る形, 加算を if/else に分ける形は試済
NON_MATCH void FUN_0800be38(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, SpiritBugScreenBox* box) {
#ifdef NONMATCHING_C
  SpiritBug* bug = &swarm->bugs[bugIdx];
  Vec3* target = &bug->target;
  Particle* ptcl = &bug->ptcl;
  u8* angle = &bug->angle;

  if ((bugIdx & 1) == frameBit) {
    s32 diff = ArcTan2_8(target->x - ptcl->pos.x, target->z - ptcl->pos.z) - *angle;

    if (bug->turnTimer < 0) {
      *angle += abs(diff) <= 4 ? diff : 4;
      if (++bug->turnTimer == 0) {
        bug->turnTimer = (Random() & 0x3F) + 0x40;
      }
    } else {
      *angle -= abs(diff) <= 4 ? diff : 4;
      if (--bug->turnTimer == 0) {
        bug->turnTimer = -(Random() & 0x3F) - 0x40;
      }
    }
    bug->vel.x = (COS(*angle) * bug->speed) >> 12;
    bug->vel.z = (SIN(*angle) * bug->speed) >> 12;
  }
  ptcl->pos.x += bug->vel.x;
  ptcl->pos.z += bug->vel.z;
  Particle_AdvanceAnim(&bug->ptcl, p->group0, &bug->anim);
  if (bug->speed > 5) {
    bug->speed--;
  }
  if (bug->timer >= bug->unk_6) {
    bug->ptcl.flags |= SPRFLAG_HIDDEN;
    bug->unk_6--;
    bug->timer = 0;
  } else {
    bug->ptcl.flags &= ~SPRFLAG_HIDDEN;
  }
  bug->timer++;
  if (bug->unk_6 == 0) {
    bug->state = 0;
    ptcl->flags |= SPRFLAG_HIDDEN;
    swarm->aliveCount--;
    if (swarm->aliveCount == 0) {
      Entity0800a89c_ReleaseSwarm(p, swarm);
    }
  }
#else
  INCFUNC("asm/func/FUN_0800be38.inc");
#endif
}
