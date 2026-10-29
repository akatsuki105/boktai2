#include "entity.h"
#include "global.h"
#include "particle.h"
#include "sound.h"
#include "sprite_aux.h"

typedef struct BlackHoleElem {
  Particle ptcl;                                       // 0x00
  u8 unk_28[4];                                        // 0x28, まだ未解析
  bool16 active;                                       // 0x2C
  u8 unk_2e[0x38 - 0x2E];                              // 0x2E, まだ未解析
  void (*updateCallback)(struct BlackHoleElem*, u32);  // 0x38, active != 0 のときのみ
} BlackHoleElem;
static_assert(sizeof(BlackHoleElem) == 60);

typedef struct BlackHole {
  Entity e;                                   // 0x000, ENTITY_UNK_10
  AuxSprite spr0;                             // 0x018
  AuxSpriteGfx gfx0;                          // 0x044, SPRITE_BLACKHOLE
  AuxSprite spr1;                             // 0x060
  AuxSpriteGfx gfx1;                          // 0x08C, SPRITE_BLACKHOLE
  u16 scale0;                                 // 0x0A8, 下位バイトが spr0.scaleX / scaleY へ毎フレームコピーされる
  u16 scale1;                                 // 0x0AA, 下位バイトが spr1.scaleX / scaleY へ毎フレームコピーされる
  u16 unk_ac;                                 // 0x0AC, _Init が 0 を書く
  u8 unk_ae;                                  // 0x0AE, '.p[0]' なければ 8
  u8 unk_af;                                  // 0x0AF, '.p[1]', なければ 12
  u8 unk_b0;                                  // 0x0B0, _Update が毎フレーム 0 にする
  u8 state;                                   // 0x0B1, sBlackHoleUpdates の添字, updateCallback と一緒に差し替えられる
  u16 stateTimer;                             // 0x0B2, state を変えるとき 0 に戻る
  u8 unk_b4;                                  // 0x0B4, _Init が 0x50 を書く
  u8 unk_b5;                                  // 0x0B5, _Init が 0 を書く
  u8 unk_b6[2];                               // 0x0B6, まだ未解析
  u16 unk_b8;                                 // 0x0B8, FUN_08084798 が引数をそのまま書く
  u8 unk_ba[0xC0 - 0xBA];                     // 0x0BA, まだ未解析
  Vec3 unk_c0;                                // 0x0C0, '.c' の座標
  Vec3 unk_c8;                                // 0x0C8, '.c' の座標から x-0x2D, y-0x40, z-0x2D した位置
  u32 unk_d0;                                 // 0x0D0, elems の fn に第2引数として渡される
  BlackHoleElem elems[12];                    // 0x0D4
  u8 unk_3a4[4];                              // 0x3A4, まだ未解析
  void (*updateCallback)(struct BlackHole*);  // 0x3A8
} BlackHole;
static_assert(sizeof(BlackHole) == 940);

COMMON_DATA BlackHole* gBlackHole = NULL;  // 0x03002BFC

void FUN_080846c8(void) {
  if (gBlackHole != NULL && gBlackHole->state == 6) {
    PlaySound_082406e0(SONG_526);
    gBlackHole->unk_b5 = 1;
  }
}

void BlackHole_SetState(BlackHole*, u8);

void FUN_080846f8(void) {
  if (gBlackHole != NULL) {
    BlackHole_SetState(gBlackHole, 7);
  }
}

bool32 FUN_08084710(void) {
  if (gBlackHole == NULL) {
    return FALSE;
  }

  if (gBlackHole->state == 6) {
    return TRUE;
  }
  return FALSE;
}

void FUN_08084734(Vec3* out) {
  if (gBlackHole != NULL) {
    *out = gBlackHole->unk_c0;
  }
}

void FUN_08084754(void) {
  if (gBlackHole != NULL) {
    gBlackHole->unk_ac += gBlackHole->unk_ae;
    if (gBlackHole->unk_ac >= 0x1400) {
      gBlackHole->unk_ac = 0x1400;
    }

    gBlackHole->unk_b0 = 1;
    gBlackHole->unk_b8 = 0;
  }
}

void FUN_08084798(s32 val) {
  if (gBlackHole != NULL) {
    gBlackHole->unk_b8 = val;
  }
}

NAKED void FUN_080847b0(unknown* p) { INCFUNC("asm/func/FUN_080847b0.inc"); }

NAKED void FUN_08084870(BlackHole* p) { INCFUNC("asm/func/FUN_08084870.inc"); }

NAKED void FUN_080849a4(Particle* p, ParticleGroup* group) { INCFUNC("asm/func/FUN_080849a4.inc"); }

NAKED void FUN_08084a14(BlackHole* p) { INCFUNC("asm/func/FUN_08084a14.inc"); }

// 生きている要素の updateCallback を順に呼ぶ
void FUN_08084b5c(BlackHole* p) {
  BlackHoleElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (elem->active) {
      p->elems[i].updateCallback(elem, p->unk_d0);
    }
    elem++;
  }
}

void FUN_08084b94(BlackHole* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    Particle_Remove(&p->elems[i].ptcl);
  }
}

NAKED void FUN_08084bb0(BlackHole* p) { INCFUNC("asm/func/FUN_08084bb0.inc"); }

void BlackHole_UpdateState0(BlackHole*);
void BlackHole_UpdateState1(BlackHole*);
void BlackHole_UpdateState2(BlackHole*);
void BlackHole_UpdateState3(BlackHole*);
void BlackHole_UpdateState4(BlackHole*);
void BlackHole_UpdateState5(BlackHole*);
void BlackHole_UpdateState6(BlackHole*);
void BlackHole_UpdateState7(BlackHole*);

// 状態を差し替える
void BlackHole_SetState(BlackHole* p, u8 state) {
  static void (*const sBlackHoleUpdates[8])(BlackHole*) = {
      BlackHole_UpdateState0,
      BlackHole_UpdateState1,
      BlackHole_UpdateState2,
      BlackHole_UpdateState3,
      BlackHole_UpdateState4,
      BlackHole_UpdateState5,
      BlackHole_UpdateState6,
      BlackHole_UpdateState7,
  };  // 0x085ABFC8

  p->state = state;
  p->updateCallback = sBlackHoleUpdates[p->state];
  p->stateTimer = 0;
}

void BlackHole_UpdateState0(BlackHole* p) {
  if (p->unk_ac != 0) {
    p->spr0.flags &= ~SPRFLAG_HIDDEN;
    p->spr1.flags &= ~SPRFLAG_HIDDEN;
    p->scale0 = 1, p->scale1 = 1;
    p->unk_b4 = 0x50, p->unk_b5 = 0;
    BlackHole_SetState(p, 1);
  }
}

// 開くアニメの拡大率を進め, 上限に達したら次の状態へ移る
// 残差1命令, 原典は 0xFFFF のプールロードを最初の if より前に置いて r6 に残すが
// agbcc は使う場所 (if の後のブロック) で読み込む
NON_MATCH void BlackHole_UpdateState1(BlackHole* p) {
#ifdef NONMATCHING_C
  s32 scale;

  p->scale1 += 4;
  if (p->scale1 > 0x1F) {
    p->scale1 = 0x20;
    BlackHole_SetState(p, 3);
  }

  scale = (p->scale1 * p->unk_b4) >> 7;
  p->scale0 = scale;
  if ((scale & 0xFFFF) == 0) {
    p->scale0 = 1;
  }
#else
  INCFUNC("asm/func/BlackHole_UpdateState1.inc");
#endif
}

void BlackHole_UpdateState2(BlackHole* p) {
  if (p->scale1 <= 4) {
    FUN_08084a14(p);
    p->unk_ac = 0;
    p->spr0.flags |= SPRFLAG_HIDDEN;
    p->spr1.flags |= SPRFLAG_HIDDEN;
    BlackHole_SetState(p, 0);
  } else {
    p->scale1 -= 4;
    p->scale0 = (p->scale1 * p->unk_b4) >> 7;
    if (p->scale0 == 0) {
      p->scale0 = 1;
    }
  }
}

NAKED void BlackHole_UpdateState3(BlackHole* p) { INCFUNC("asm/func/BlackHole_UpdateState3.inc"); }

NAKED void BlackHole_UpdateState4(BlackHole* p) { INCFUNC("asm/func/BlackHole_UpdateState4.inc"); }

NAKED void BlackHole_UpdateState5(BlackHole* p) { INCFUNC("asm/func/BlackHole_UpdateState5.inc"); }

NAKED void BlackHole_UpdateState6(BlackHole* p) { INCFUNC("asm/func/BlackHole_UpdateState6.inc"); }

NAKED void BlackHole_UpdateState7(BlackHole* p) { INCFUNC("asm/func/BlackHole_UpdateState7.inc"); }

NAKED void FUN_0808509c(BlackHole* p) { INCFUNC("asm/func/FUN_0808509c.inc"); }

s32 BlackHole_Update(BlackHole* p) {
  u16 scale;

  if (!TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    FUN_08084b5c(p);
    FUN_0808509c(p);
    p->updateCallback(p);
    scale = p->scale0;
    p->spr0.scaleY = scale;
    p->spr0.scaleX = scale;
    scale = p->scale1;
    p->spr1.scaleY = scale;
    p->spr1.scaleX = scale;
    p->unk_b0 = 0;
  }

  return 0;
}

s32 BlackHole_Destroy(BlackHole* p) {
  AuxSprite_Remove(&p->spr0);
  AuxSprite_Remove(&p->spr1);
  FUN_08084b94(p);
  gBlackHole = NULL;
  return 0;
}

NAKED s32 BlackHole_Init(BlackHole* p) { INCFUNC("asm/func/BlackHole_Init.inc"); }

// 0xBD74, HashName("ブラックホール"), リンゴ,ダーイン戦でサバタが作るブラックホール
BlackHole* BlackHole_Create(void) {
  BlackHole* p;

  if (gBlackHole != NULL) {
    return gBlackHole;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(BlackHole));
  if (p != NULL) {
    SetEntityRoutine(p, BlackHole_Update, BlackHole_Destroy);
    if (BlackHole_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
