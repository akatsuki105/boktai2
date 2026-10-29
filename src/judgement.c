#include "camera_inline.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "trig.h"

// 演出で飛ばす粒子1個ぶんの枠, 8個を使い回す
typedef struct JudgementParticle {
  Particle ptcl;                              // 0x00
  u16 timer;                                  // 0x28, JudgementParticle_UpdateStill が毎フレーム +1, 7 を超えると枠を畳む
  bool16 active;                              // 0x2A
  Vec3 vel;                                   // 0x2C, JudgementParticle_UpdateFalling が毎フレーム ptcl.pos に足す, y は8フレームごとに +1 されて重力になる, 根拠: JudgementParticle_StartMoving が pos.x/y/z を書いた直後に同じ形で x/y/z を初期化する
  ParticleGroup* group;                       // 0x34, PTCL_GROUP_2
  void (*update)(struct JudgementParticle*);  // 0x38
} JudgementParticle;
static_assert(sizeof(JudgementParticle) == 60);

// "審判のカード" (ITEM_JUDGEMENT, 全回復して復活) の 効果処理 及び 演出
typedef struct Judgement {
  Entity e;                                   // 0x000, ENTITY_UNK_11
  Player* player;                             // 0x018, _Init の第2引数
  MainSprite icon;                            // 0x01C, SPRITE_INVENTORY_ICONS
  Vec3 iconPos;                               // 0x07C, icon を置くスクリーン座標
  Vec3 screen;                                // 0x084, player->mover.pos の y に +0x96 した点を投影した画面座標
  JudgementParticle ptcls[8];                 // 0x08C, 根拠: _Destroy の stride 0x3C × 8
  u16 frame;                                  // 0x26C, Judgement_UpdateHeal が毎フレーム +1, 8 と 16 の倍数で粒子を出す
  u16 ptclIdx;                                // 0x26E, 次に使う ptcls の添字 (0..7)
  u16 timer;                                  // 0x270, _Init が 0, 各状態関数が +1 する
  void (*updateCallback)(struct Judgement*);  // 0x274
} Judgement;
static_assert(sizeof(Judgement) == 632);

// 16フレームで畳む, その間は2コマのアニメを出しながら vel ぶん動かし, 8フレームごとに vel.y を増やして落とす
void JudgementParticle_UpdateFalling(JudgementParticle* ptcl) {
  if (++ptcl->timer > 15) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    ptcl->active = FALSE;
  } else {
    Particle_SetPose(&ptcl->ptcl, ptcl->group, PTCL2_SOL_L + ((ptcl->timer >> 2) & 1));
    ptcl->ptcl.pos.x += ptcl->vel.x;
    ptcl->ptcl.pos.y += ptcl->vel.y;
    if ((ptcl->timer & 7) == 0) {
      ptcl->vel.y++;
    }
  }
}

// 8 個の粒子を放射状に飛ばして落とす (JudgementParticle_UpdateFalling)
// 残差 107/109 命令: ループ外へ出す定数の選び方が違う, 原典は &gRandTableIdx と 0x3FF と gSineTable をレジスタに持ち gRandomTable を毎回プールから読む, こちらは gRandomTable を持って &gRandTableIdx を毎回読む
// Tier A-C は試済 (枠をポインタで受ける, 式の項の順, 乱数をローカルに受ける)
NON_MATCH void Judgement_SpawnFallingParticles(Judgement* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    s32 angle, speed;

    p->ptcls[i].ptcl.pos.x = 16;
    p->ptcls[i].ptcl.pos.y = 32;
    angle = i * 32 + ((Random() >> 3) & 15) - 8;
    speed = ((Random() >> 3) & 3) + 4;
    p->ptcls[i].vel.x = POLAR_X(speed, angle);
    p->ptcls[i].vel.y = POLAR_Z(speed, angle);
    p->ptcls[i].ptcl.flags &= ~SPRFLAG_HIDDEN;
    p->ptcls[i].active = TRUE;
    p->ptcls[i].timer = 0;
    p->ptcls[i].update = JudgementParticle_UpdateFalling;
  }
#else
  INCFUNC("asm/func/Judgement_SpawnFallingParticles.inc");
#endif
}

// 16フレームで畳む, その間は2コマのアニメを出しながら vel.y ぶん動かす
void JudgementParticle_UpdateMoving(JudgementParticle* ptcl) {
  if (++ptcl->timer > 15) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    ptcl->active = FALSE;
  } else {
    Particle_SetPose(&ptcl->ptcl, ptcl->group, PTCL2_SOL_L + ((ptcl->timer >> 2) & 1));
    ptcl->ptcl.pos.y += ptcl->vel.y;
  }
}

// 粒子を乱数の位置に出し, 上向きの速さを付けて動かす (JudgementParticle_UpdateMoving)
void JudgementParticle_StartMoving(JudgementParticle* ptcl) {
  u16* table;

  ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
  Particle_SetPose(&ptcl->ptcl, ptcl->group, PTCL2_FLAME_L);
  table = gRandomTable;
  ptcl->ptcl.pos.x = Mod(_Random(table) >> 3, 16) + 8;
  ptcl->ptcl.pos.y = Mod(_Random(table) >> 3, 16) + 24;
  ptcl->ptcl.pos.z = 0;
  ptcl->vel.x = 0;
  ptcl->vel.y = -(Mod(_Random(table) >> 3, 2) + 2);
  ptcl->vel.z = 0;
  ptcl->active = TRUE;
  ptcl->timer = 0;
  ptcl->update = JudgementParticle_UpdateMoving;
}

// 8フレームで畳む, その間はその場で2コマのアニメを出す
void JudgementParticle_UpdateStill(JudgementParticle* ptcl) {
  if (++ptcl->timer > 7) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    ptcl->active = FALSE;
  } else {
    Particle_SetPose(&ptcl->ptcl, ptcl->group, PTCL2_SOL_L + ((ptcl->timer >> 2) & 1));
  }
}

// 粒子を左上の乱数の位置に出し, その場でアニメさせる (JudgementParticle_UpdateStill)
void JudgementParticle_StartStill(JudgementParticle* ptcl) {
  u16* table;

  ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
  Particle_SetPose(&ptcl->ptcl, ptcl->group, PTCL2_SOL_L);
  table = gRandomTable;
  ptcl->ptcl.pos.x = Mod(_Random(table) >> 3, 80) + 24;
  ptcl->ptcl.pos.y = ((_Random(table) >> 3) & 7) + 8;
  ptcl->ptcl.pos.z = 0;
  ptcl->active = TRUE;
  ptcl->timer = 0;
  ptcl->update = JudgementParticle_UpdateStill;
}

void Judgement_UpdateParticles(Judgement* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (p->ptcls[i].active) {
      p->ptcls[i].update(&p->ptcls[i]);
    }
  }
}

// 状態 3, 30 フレーム目で粒子を出して効果音を鳴らしアイコンを隠し, 60 フレームで操作の制限を解いて自分を消す
void Judgement_UpdateFinish(Judgement* p) {
  if (p->timer == 30) {
    Judgement_SpawnFallingParticles(p);
    PlaySound_082406e0(SONG_645);
    p->icon.flags |= SPRFLAG_HIDDEN;
  }
  p->timer++;
  if (p->timer > 59) {
    Sound_Resume();
    CLEAR_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    gGameFlags &= ~FLAG030047A4_UNK_0;
    KillEntity((Entity*)p);
  }
}

// 状態 2, 1P の HP を 0 から最大 HP の 1/150 ずつ回復させながらアイコンを揺らして粒子を出し, 満タンで終了の状態へ移る
// 残差3箇所 (163/164 命令): 原典は 0xFFFF をレジスタに置いたまま hp を lsls/lsrs で切り詰めて符号なしで比べ, その 0xFFFF を1つ目の ptclIdx の切り詰めに ands で使う, こちらは hp & 0xFFFF が ands と符号付き比較になる
// Tier A-B は試済 (hp += step を直接比べる, u16 / s32 / u32 のローカルに受ける, (u16) キャスト)
NON_MATCH void Judgement_UpdateHeal(Judgement* p) {
#ifdef NONMATCHING_C
  bool32 done;
  s32 step;
  u16* table;
  s32 hp;

  if (p->timer == 0) {
    p->player->hp = 0;
    p->timer++;
  }
  done = FALSE;
  step = Div(p->player->maxHP, 150);
  if (step == 0) {
    step = 1;
  }
  hp = p->player->hp + step;
  p->player->hp = hp;
  if ((hp & 0xFFFF) >= p->player->maxHP) {
    p->player->hp = p->player->maxHP;
    sound_08240740(SONG_601);
    done = TRUE;
  }
  table = gRandomTable;
  p->icon.pos.x = p->iconPos.x + Mod(_Random(table) >> 3, 3) - 1;
  p->icon.pos.y = p->iconPos.y + Mod(_Random(table) >> 3, 3) - 1;
  if ((p->frame & 7) == 0) {
    JudgementParticle_StartMoving(&p->ptcls[p->ptclIdx]);
    if (++p->ptclIdx > 7) {
      p->ptclIdx = 0;
    }
  }
  if ((p->frame & 15) == 0) {
    JudgementParticle_StartStill(&p->ptcls[p->ptclIdx]);
    if (++p->ptclIdx > 7) {
      p->ptclIdx = 0;
    }
  }
  p->frame++;
  if (done) {
    p->updateCallback = Judgement_UpdateFinish;
    p->timer = 0;
  }
#else
  INCFUNC("asm/func/Judgement_UpdateHeal.inc");
#endif
}

// 状態 1, アイコンを 8 フレームかけて揺れが収まるように揺らし, 30 フレームで回復の状態へ移る
void Judgement_UpdateShake(Judgement* p) {
  if (++p->timer <= 7) {
    s32 range = 8 - p->timer;
    u16* table = gRandomTable;

    p->icon.pos.x = p->iconPos.x + Mod(_Random(table) >> 3, range) - (range >> 1);
    p->icon.pos.y = p->iconPos.y + Mod(_Random(table) >> 3, range) - (range >> 1);
  }
  if (p->timer > 29) {
    p->updateCallback = Judgement_UpdateHeal;
    PlaySound_082406e0(SONG_601);
    p->timer = 0;
  }
}

// 状態 0, カードのアイコンを 1P の頭上から iconPos へ跳ねながら飛ばし, 16 フレームで落ちる粒子を出して揺れの状態へ移る
void Judgement_UpdateAppear(Judgement* p) {
  if (p->timer == 0) {
    FUN_082407e0();
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
  } else if (p->timer == 1) {
    PlaySound_082406e0(SE_DAMAGE);
    p->icon.flags &= ~SPRFLAG_HIDDEN;
  }
  if (++p->timer > 15) {
    p->icon.flags &= ~SPRFLAG_AFFINE;
    Judgement_SpawnFallingParticles(p);
    p->updateCallback = Judgement_UpdateShake;
    p->timer = 0;
    PlaySound_082406e0(SONG_644);
  } else {
    s32 y;

    p->icon.scaleX = p->icon.scaleY = p->timer + 34;
    p->icon.pos.x = Div(p->iconPos.x * p->timer + p->screen.x * (16 - p->timer), 16);
    y = Div(p->iconPos.y * p->timer + p->screen.y * (16 - p->timer), 16);
    p->icon.pos.y = y - FixToInt(12, SIN(Div(p->timer << 7, 20)) * 16);
  }
}

s32 Judgement_Update(Judgement* p) {
  Judgement_UpdateParticles(p);
  p->updateCallback(p);
  return 0;
}

s32 Judgement_Destroy(Judgement* p) {
  s32 i;

  MainSprite_Remove(&p->icon);
  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
  return 0;
}

// SPRITE_INVENTORY_ICONS を開き, 審判のカードのアイコンを iconPos に隠して置く
void Judgement_InitSprite(Judgement* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  MainSpriteGfx gfx = *f;

  OpenMainSpriteFile(&gfx, f);
  VEC3_SET(p->iconPos, 8, 24, 0);
  MainSprite_Add(&p->icon, &gfx, ICON_ITEM(ITEM_JUDGEMENT), SPRFLAG_HIDDEN | SPRFLAG_AFFINE | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &p->iconPos);
}

void Judgement_InitParticles(Judgement* p) {
  ParticleGroup* group = GetParticleGroup(PTCL_GROUP_2);
  s32 i;

  for (i = 0; i < 8; i++) {
    p->ptcls[i].group = group;
    Particle_Add(&p->ptcls[i].ptcl, group, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD);
    Particle_SetOffset(&p->ptcls[i].ptcl, -4, -4);
    Particle_SetPose(&p->ptcls[i].ptcl, p->ptcls[i].group, PTCL2_SOL_L);
    Particle_SetPltt(&p->ptcls[i].ptcl, 1);
    p->ptcls[i].ptcl.priority = 0;
    p->ptcls[i].timer = 0;
    p->ptcls[i].active = FALSE;
  }
}

// 1P の頭上の画面座標を出し, アイコンと粒子を用意して最初の状態から始める, 再生中は START/SELECT を止める
s32 Judgement_Init(Judgement* p, Player* player) {
  WorldPos pos;

  p->player = player;
  pos = player->mover.pos;
  pos.y += Q8(0.586);
  WorldToScreen(&p->screen, &pos);
  Judgement_InitSprite(p);
  Judgement_InitParticles(p);
  p->updateCallback = Judgement_UpdateAppear;
  p->timer = 0;
  gGameFlags |= FLAG030047A4_UNK_0;
  return 0;
}

Judgement* Judgement_Create(Player* player) {
  Judgement* p = CreateEntity(ENTITY_UNK_11, sizeof(Judgement));

  if (p != NULL) {
    SetEntityRoutine(p, Judgement_Update, Judgement_Destroy);
    if (Judgement_Init(p, player) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
