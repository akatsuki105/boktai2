#include "entity.h"
#include "global.h"
#include "particle.h"
#include "sound.h"
#include "sprite_aux.h"

// elems の1要素, FUN_08084b5c が unk_2c が非0 のものだけ updateCallback を呼ぶ
typedef struct {
  Particle ptcl;           // 0x00
  u8 unk_28[4];            // 0x28, まだ未解析
  u16 unk_2c;              // 0x2C, 非0 の要素だけ updateCallback が呼ばれる
  u8 unk_2e[0x38 - 0x2E];  // 0x2E, まだ未解析
  void* updateCallback;    // 0x38, updateCallback(elem, p->unk_d0) として呼ばれる
} EntityBD74Elem;
static_assert(sizeof(EntityBD74Elem) == 60);

typedef struct EntityBD74 {
  Entity e;                                    // 0x000, ENTITY_UNK_10
  AuxSprite spr0;                              // 0x018
  AuxSpriteGfx gfx0;                           // 0x044, SPRITE_EFF_3641
  AuxSprite spr1;                              // 0x060
  AuxSpriteGfx gfx1;                           // 0x08C, SPRITE_EFF_3641
  u16 scale0;                                  // 0x0A8, 下位バイトが spr0.scaleX / scaleY へ毎フレームコピーされる
  u16 scale1;                                  // 0x0AA, 下位バイトが spr1.scaleX / scaleY へ毎フレームコピーされる
  u16 unk_ac;                                  // 0x0AC, _Init が 0 を書く
  u8 unk_ae;                                   // 0x0AE, '.p[0]' なければ 8
  u8 unk_af;                                   // 0x0AF, '.p[1]', なければ 12
  u8 unk_b0;                                   // 0x0B0, _Update が毎フレーム 0 にする
  u8 state;                                    // 0x0B1, PTR_ARRAY_085abfc8 の添字, updateCallback と一緒に差し替えられる
  u16 stateTimer;                              // 0x0B2, state を変えるとき 0 に戻る
  u8 unk_b4;                                   // 0x0B4, _Init が 0x50 を書く
  u8 unk_b5;                                   // 0x0B5, _Init が 0 を書く
  u8 unk_b6[2];                                // 0x0B6, まだ未解析
  u16 unk_b8;                                  // 0x0B8, FUN_08084798 が引数をそのまま書く
  u8 unk_ba[0xC0 - 0xBA];                      // 0x0BA, まだ未解析
  Vec3 unk_c0;                                 // 0x0C0, '.c' の座標
  Vec3 unk_c8;                                 // 0x0C8, '.c' の座標から x-0x2D, y-0x40, z-0x2D した位置
  u32 unk_d0;                                  // 0x0D0, elems の fn に第2引数として渡される
  EntityBD74Elem elems[12];                    // 0x0D4
  u8 unk_3a4[4];                               // 0x3A4, まだ未解析
  void (*updateCallback)(struct EntityBD74*);  // 0x3A8
} EntityBD74;
static_assert(sizeof(EntityBD74) == 940);

void FUN_08084a14(EntityBD74* p);
void FUN_08084b5c(EntityBD74* p);
void FUN_08084c30(EntityBD74* p, u8 param_2);
void FUN_0808509c(EntityBD74* p);

extern u32 u32_03002bc0;

static inline bool32 TestPauseFlag(u32 bits) { return u32_03002bc0 & bits; }

extern void (*const PTR_ARRAY_085abfc8[8])(EntityBD74*);

extern EntityBD74* gEntityBD74;  // 0x03002BFC

void FUN_080846c8(void) {
  if (gEntityBD74 != NULL && gEntityBD74->state == 6) {
    PlaySound_082406e0(0x20E);
    gEntityBD74->unk_b5 = 1;
  }
}

void FUN_080846f8(void) {
  if (gEntityBD74 != NULL) {
    FUN_08084c30(gEntityBD74, 7);
  }
}

bool32 FUN_08084710(void) {
  if (gEntityBD74 == NULL) {
    return FALSE;
  }

  if (gEntityBD74->state == 6) {
    return TRUE;
  }
  return FALSE;
}

void FUN_08084734(Vec3* out) {
  if (gEntityBD74 != NULL) {
    *out = gEntityBD74->unk_c0;
  }
}

void FUN_08084754(void) {
  if (gEntityBD74 != NULL) {
    gEntityBD74->unk_ac += gEntityBD74->unk_ae;
    if (gEntityBD74->unk_ac >= 0x1400) {
      gEntityBD74->unk_ac = 0x1400;
    }

    gEntityBD74->unk_b0 = 1;
    gEntityBD74->unk_b8 = 0;
  }
}

void FUN_08084798(s32 val) {
  if (gEntityBD74 != NULL) {
    gEntityBD74->unk_b8 = val;
  }
}

NAKED void FUN_080847b0(unknown* p) { INCFUNC("asm/func/FUN_080847b0.inc"); }

NAKED void FUN_08084870(EntityBD74* p) { INCFUNC("asm/func/FUN_08084870.inc"); }

NAKED void FUN_080849a4(Particle* p, ParticleGroup* group) { INCFUNC("asm/func/FUN_080849a4.inc"); }

NAKED void FUN_08084a14(EntityBD74* p) { INCFUNC("asm/func/FUN_08084a14.inc"); }

// 生きている要素の updateCallback を順に呼ぶ
void FUN_08084b5c(EntityBD74* p) {
  EntityBD74Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (elem->unk_2c != 0) {
      ((void (*)(EntityBD74Elem*, u32))p->elems[i].updateCallback)(elem, p->unk_d0);
    }
    elem++;
  }
}

void FUN_08084b94(EntityBD74* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    Particle_Remove(&p->elems[i].ptcl);
  }
}

NAKED void FUN_08084bb0(EntityBD74* p) { INCFUNC("asm/func/FUN_08084bb0.inc"); }

// 状態を差し替える
void FUN_08084c30(EntityBD74* p, u8 state) {
  p->state = state;
  p->updateCallback = PTR_ARRAY_085abfc8[p->state];
  p->stateTimer = 0;
}

void FUN_08084c58(EntityBD74* p) {
  if (p->unk_ac != 0) {
    p->spr0.flags &= ~SPRFLAG_HIDDEN;
    p->spr1.flags &= ~SPRFLAG_HIDDEN;
    p->scale0 = 1, p->scale1 = 1;
    p->unk_b4 = 0x50, p->unk_b5 = 0;
    FUN_08084c30(p, 1);
  }
}

NON_MATCH void FUN_08084c9c(EntityBD74* p) {
#ifdef NONMATCHING_C
  u32 scale;

  p->scale1 += 4;
  if (p->scale1 >= 0x20) {
    p->scale1 = 0x20;
    FUN_08084c30(p, 3);
  }

  scale = (p->scale1 * p->unk_b4) >> 7;
  p->scale0 = scale;
  if ((scale & 0xFFFF) == 0) {
    p->scale0 = 1;
  }
#else
  INCFUNC("asm/func/FUN_08084c9c.inc");
#endif
}

void FUN_08084ce8(EntityBD74* p) {
  if (p->scale1 <= 4) {
    FUN_08084a14(p);
    p->unk_ac = 0;
    p->spr0.flags |= SPRFLAG_HIDDEN;
    p->spr1.flags |= SPRFLAG_HIDDEN;
    FUN_08084c30(p, 0);
  } else {
    p->scale1 -= 4;
    p->scale0 = (p->scale1 * p->unk_b4) >> 7;
    if (p->scale0 == 0) {
      p->scale0 = 1;
    }
  }
}

NAKED void FUN_08084d44(EntityBD74* p) { INCFUNC("asm/func/FUN_08084d44.inc"); }

NAKED void FUN_08084dc8(EntityBD74* p) { INCFUNC("asm/func/FUN_08084dc8.inc"); }

NAKED void FUN_08084e54(EntityBD74* p) { INCFUNC("asm/func/FUN_08084e54.inc"); }

NAKED void FUN_08084ecc(EntityBD74* p) { INCFUNC("asm/func/FUN_08084ecc.inc"); }

NAKED void FUN_08084f7c(EntityBD74* p) { INCFUNC("asm/func/FUN_08084f7c.inc"); }

NAKED void FUN_0808509c(EntityBD74* p) { INCFUNC("asm/func/FUN_0808509c.inc"); }

s32 EntityBD74_Update(EntityBD74* p) {
  u16 scale;

  if (!TestPauseFlag(4)) {
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

s32 EntityBD74_Destroy(EntityBD74* p) {
  AuxSprite_Remove(&p->spr0);
  AuxSprite_Remove(&p->spr1);
  FUN_08084b94(p);
  gEntityBD74 = NULL;
  return 0;
}

NAKED s32 EntityBD74_Init(EntityBD74* p) { INCFUNC("asm/func/EntityBD74_Init.inc"); }

EntityBD74* EntityBD74_Create(void) {
  EntityBD74* p;

  if (gEntityBD74 != NULL) {
    return gEntityBD74;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(EntityBD74));
  if (p != NULL) {
    SetEntityRoutine(p, EntityBD74_Update, EntityBD74_Destroy);
    if (EntityBD74_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
