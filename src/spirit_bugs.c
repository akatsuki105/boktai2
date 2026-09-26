#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "sprite_aux.h"

// 精霊虫1匹。state で PTR_ARRAY_085aa730[kind * 5 + state] のハンドラに分岐する, 根拠: Entity0800a89c_UpdateSwarm
typedef struct SpiritBug {
  u8 state;           // 0x00, ハンドラの添字。0 は未使用
  u8 speed;           // 0x01, gSineTable との積が速度になる, 根拠: FUN_0800b068
  u8 angle;           // 0x02, gSineTable の添字 (向き)
  s8 turnTimer;       // 0x03, 符号が旋回方向。0 になると gRandomTable から引き直す, 根拠: FUN_0800b068 の ldrsb
  u16 timer;          // 0x04, 状態ごとのカウンタ。生成時は寿命, 根拠: Entity0800a89c_Spawn / FUN_0800b068
  u16 unk_6;          // 0x06, 状態遷移用の第2カウンタ (点滅回数など)。生成時は u32_ARRAY_085aa700[kind], 根拠: FUN_0800b7a0
  Vec3 vel;           // 0x08, 毎フレーム ptcl.pos に加算される, 根拠: FUN_0800b068
  Vec3 target;        // 0x10, 向かう先。生成時は ptcl.pos のコピー, 根拠: Entity0800a89c_Spawn / ArcTan2_8 の入力
  AuxAnimState anim;  // 0x18, 根拠: FUN_08236fac に渡される
  Particle ptcl;      // 0x28, 根拠: FUN_0822da70 / Particle_Remove に渡される
} SpiritBug;
static_assert(sizeof(SpiritBug) == 80);

// 1回の発生でまとめて出る精霊虫の群れ。Entity0800a89c_Spawn が空きスロットを探して作る
typedef struct SpiritBugSwarm {
  bool8 active;       // 0x00
  u8 aliveCount;      // 0x01, 生存中の bugs の数 (最大4)。0 になると Entity0800a89c_ReleaseSwarm で解放, 根拠: FUN_0800be38
  u8 kind;            // 0x02, 0..2 (Sol/Luna/Dark)。PTR_ARRAY_085aa70c や gSpiritBugsSoundIDs の添字
  u8 amount;          // 0x03, PTR_ARRAY_085aa70c[kind](Player*, s32) の第2引数, 根拠: FUN_0800b068
  u8 soundDelay;      // 0x04, 0 になった瞬間に gSoundIDs_085aa724[kind] を鳴らす, 根拠: Entity0800a89c_Update
  u8 unk_5;           // 0x05, 読み手も書き手も未発見, padding?
  u16 timer;          // 0x06, 生成時 40。0 になるまでプレイヤーに回収されない, 根拠: Entity0800a89c_Spawn / FUN_0800b068
  SpiritBug bugs[4];  // 0x08
} SpiritBugSwarm;
static_assert(sizeof(SpiritBugSwarm) == 328);

// 精霊虫 (太陽虫/月光虫/暗黒虫) をまとめて管理するエンティティ。群れを6つまで同時に持てる
typedef struct {
  Entity e;                  // 0x0, ENTITY_UNK_8
  bool32 isSabata;           // 0x18
  u32 unk_1c;                // 0x1C, 毎フレーム +1。下位ビットで虫の更新を間引く, 根拠: Entity0800a89c_UpdateSwarm
  ParticleGroup* group0;     // 0x20, PTCL_GROUP_0
  AuxAnimFile* anim;         // 0x24
  SpiritBugSwarm swarms[6];  // 0x28, 根拠: Entity0800a89c_Init / _Destroy が stride 0x148 で6回まわす
  Player* player;            // 0x7D8, 根拠: 0x0800a860
} SpiritBugsManager;
static_assert(sizeof(SpiritBugsManager) == 2012);

IWRAM_DATA SpiritBugsManager* gSpiritBugsManager = NULL;  // 0x03000044

const u16 u16_ARRAY_085aa6d0[24] = {
    0x4, 0x0, 0x5, 0x0, 0x6, 0x0, 0x6, 0x0, 0x5, 0x0, 0x4, 0x0, 0x9, 0x0, 0xA, 0x0, 0xB, 0x0, 0xB, 0x0, 0xA, 0x0, 0x9, 0x0,
};

const u32 u32_ARRAY_085aa700[3] = {10, 10, 120};

// --------------------------------------------

// 精霊虫の効果
void Player_ApplySolarbug(Player* p, s32 amount);
void Player_ApplyMoonbug(Player* p, s32 amount);
void Player_ApplyDarkbug(Player* p, s32 amount);

void (*const PTR_ARRAY_085aa70c[3])(Player*, s32) = {
    Player_ApplySolarbug,  // 太陽虫 (Ene回復)
    Player_ApplyMoonbug,   // 月光虫 (HP回復)
    Player_ApplyDarkbug,   // 暗黒虫 (Eneが減る)
};  // 0x085AA70C

// --------------------------------------------

const SoundID32 gSpiritBugsSoundIDs[3] = {0x11C, 0x11B, 0x11A};

const SoundID32 gSoundIDs_085aa724[3] = {0x293, 0x292, 0x291};

// --------------------------------------------

// PTR_ARRAY_085aa730 の中身。frameBit/framePhase は SpiritBugsManager.unk_1c の下位ビットで、
// screenBox は Entity0800a89c_Update がスタックに組む回収判定用の枠 (未解析)。
// 表は kind * 5 + SpiritBug.state で引くので、横1行が1つの kind、列が state 0..4 に対応する。
// state 1 が徘徊+回収待ち、2 がプレイヤーへの吸い寄せ、3 が点滅して消滅、4 が回収成立。state 0 は空きスロットで何もしない
typedef void (*SpiritBugHandler)(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox);

void FUN_0800b064(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox);
void FUN_0800b068(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox);
void FUN_0800b7a0(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox);
void FUN_0800be38(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox);
void Entity0800a89c_UpdateCollectedBug(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox);
void FUN_0800b404(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox);
void FUN_0800ba78(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox);

// clang-format off
const SpiritBugHandler PTR_ARRAY_085aa730[15] = {
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
// clang-format on

// --------------------------------------------

void FUN_0800a488(void) { gSpiritBugsManager = NULL; }

// 群れの虫4匹の Particle を解放してスロットを空きに戻す
s32 Entity0800a89c_ReleaseSwarm(SpiritBugsManager* p, SpiritBugSwarm* swarm) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&swarm->bugs[i].ptcl);
  }
  swarm->active = 0;
}

// 出ている精霊虫を全部消す
s32 Entity0800a89c_ReleaseAll(void) {
  SpiritBugsManager* p = gSpiritBugsManager;
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

s32 FUN_0800a4f4(void) { return Entity0800a89c_ReleaseAll(); }

// 群れの虫4匹を、虫ごとの state に対応するハンドラに流す
s32 Entity0800a89c_UpdateSwarm(SpiritBugsManager* p, SpiritBugSwarm* swarm, void* screenBox) {
  u32 frameBit = p->unk_1c & 1;
  u32 framePhase = p->unk_1c & 3;
  SpiritBug* bug;
  s32 i;

  for (i = 0, bug = swarm->bugs; i < 4; i++) {
    PTR_ARRAY_085aa730[swarm->kind * 5 + bug->state](p, swarm, i, frameBit, framePhase, screenBox);
    bug++;
  }
}

NAKED s32 Entity0800a89c_Update(SpiritBugsManager* p) { INCFUNC("asm/func/Entity0800a89c_Update.inc"); }

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
  gSpiritBugsManager = NULL;
  return 0;
}

// 群れ6つ分の Particle を確保し、サバタかどうかを覚えておく (使うアニメーションが変わる)
s32 Entity0800a89c_Init(SpiritBugsManager* p, unknown* arg) {
  Player* player;
  s32 i, j;

  gSpiritBugsManager = p;
  p->group0 = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, 0xD1B8);
  for (i = 0; i < 6; i++) {
    SpiritBugSwarm* swarm = &p->swarms[i];

    swarm->active = 0;
    for (j = 0; j < 4; j++) {
      FUN_0822da70(&swarm->bugs[j].ptcl, p->group0, 1);
      FUN_0822dadc(&swarm->bugs[j].ptcl, 1);
    }
  }
  p->unk_1c = 0;
  player = gPlayerPtr[0];
  p->player = player;
  if (player == NULL) {
    return -1;
  }
  if (player->kind == PLAYER_SABATA) {
    p->isSabata = TRUE;
  } else {
    p->isSabata = FALSE;
  }
  return 0;
}

SpiritBugsManager* Entity0800a89c_Create(unknown* arg) {
  SpiritBugsManager* p = CreateEntity(ENTITY_UNK_8, sizeof(SpiritBugsManager));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0800a89c_Update, Entity0800a89c_Destroy);
    if (Entity0800a89c_Init(p, arg) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED s32 Entity0800a89c_Spawn(s32 count, u32 kindFlags, u8 amount, Vec3* pos, Vec3* spread, s16 lifetime, s32 lifetimeRand) { INCFUNC("asm/func/Entity0800a89c_Spawn.inc"); }

NAKED s32 Entity0800a89c_SpawnAt(s32 count, u32 kindFlags, u8 amount, Vec3* pos, Vec3* perBugPos, s16 lifetime, s32 lifetimeRand) { INCFUNC("asm/func/Entity0800a89c_SpawnAt.inc"); }

// 出ている精霊虫の総数を数える
u32 Entity0800a89c_CountBugs(void) {
  SpiritBugsManager* p = gSpiritBugsManager;
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
  SpiritBugsManager* p = gSpiritBugsManager;
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
          FUN_08236fac(&swarm->bugs[j].anim, p->anim, u16_ARRAY_085aa6d0[(p->isSabata * 3 + swarm->kind) * 2], 0, 0);
          if (swarm->bugs[j].state < 3 && swarm->bugs[j].timer < 180) {
            swarm->bugs[j].timer = 180;
          }
        }
      }
    }
  }
#else
  INCFUNC("asm/func/Entity0800a89c_PurifyDarkBugs.inc");
#endif
}

// state 0 (空きスロット) のハンドラ。何もしない
void FUN_0800b064(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox) {}

NAKED void FUN_0800b068(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox) { INCFUNC("asm/func/FUN_0800b068.inc"); }

NAKED void FUN_0800b404(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox) { INCFUNC("asm/func/FUN_0800b404.inc"); }

NAKED void FUN_0800b7a0(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox) { INCFUNC("asm/func/FUN_0800b7a0.inc"); }

NAKED void FUN_0800ba78(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox) { INCFUNC("asm/func/FUN_0800ba78.inc"); }

// state 4 (プレイヤーに回収された) のハンドラ。アニメを1コマ進め、一巡したら虫を消す
NON_MATCH void Entity0800a89c_UpdateCollectedBug(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox) {
#ifdef NONMATCHING_C
  SpiritBug* bug = &swarm->bugs[bugIdx];
  AuxAnimCmd* cmd = &bug->anim.cmds[bug->anim.cmdIdx];
  bool32 finished;

  bug->ptcl.tileNum = p->group0->tile + (*cmd >> 6) * (bug->ptcl.spriteWidth >> 3) * (bug->ptcl.spriteHeight >> 3);
  if ((bug->anim.flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    bug->ptcl.flags |= 4;
  } else {
    bug->ptcl.flags &= ~4;
  }
  if ((bug->anim.flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    bug->ptcl.flags |= 8;
  } else {
    bug->ptcl.flags &= ~8;
  }
  bug->anim.tick++;
  if (bug->anim.tick < bug->anim.wait) {
    finished = FALSE;
  } else {
    bug->anim.tick = 0;
    if (bug->anim.flags & ANIM_PLAY_REVERSE) {
      if (bug->anim.cmdIdx == 0) {
        bug->anim.cmdIdx = bug->anim.cmdCount - 1;
        finished = TRUE;
      } else {
        bug->anim.cmdIdx--;
        finished = FALSE;
      }
    } else {
      bug->anim.cmdIdx++;
      if (bug->anim.cmdIdx < bug->anim.cmdCount) {
        finished = FALSE;
      } else {
        bug->anim.cmdIdx = 0;
        finished = TRUE;
      }
    }
    bug->anim.wait = (bug->anim.speed * (bug->anim.cmds[bug->anim.cmdIdx] & 0xF)) >> 6;
  }
  if (finished) {
    bug->state = 0;
    bug->ptcl.flags |= 1;
    swarm->aliveCount--;
    if (swarm->aliveCount == 0) {
      Entity0800a89c_ReleaseSwarm(p, swarm);
    }
  }
#else
  INCFUNC("asm/func/Entity0800a89c_UpdateCollectedBug.inc");
#endif
}

NAKED void FUN_0800be38(SpiritBugsManager* p, SpiritBugSwarm* swarm, s32 bugIdx, u32 frameBit, u32 framePhase, void* screenBox) { INCFUNC("asm/func/FUN_0800be38.inc"); }
