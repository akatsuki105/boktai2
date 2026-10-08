#include "eff_082473e0.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "pile_driver.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"

static void (*const sGeneratorUpdates[8])(Generator*);

NAKED void Generator_SetState(Generator* p, s32 state) { INCFUNC("asm/func/Generator_SetState.inc"); }

// スプライトを本来の位置から ±5 揺らす
NON_MATCH void FUN_080b2888(Generator* p) {
#ifdef NONMATCHING_C
  u16* table;

  p->sprite.pos = p->pos;
  p->unk_ed = 1;
  table = gRandomTable;
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  p->sprite.pos.x = p->sprite.pos.x - 5 + Mod(table[gRandTableIdx], 10);
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  p->sprite.pos.z = p->sprite.pos.z - 5 + Mod(table[gRandTableIdx], 10);
#else
  INCFUNC("asm/func/FUN_080b2888.inc");
#endif
}

NAKED void Generator_PushPlayer(Generator* p) { INCFUNC("asm/func/Generator_PushPlayer.inc"); }

// 攻撃属性を持つ判定を受けたらダメージを溜め、上限に届いたら state 3 へ進む
NON_MATCH void FUN_080b29a4(HitboxData* a, HitboxData* b, Generator* p) {
#ifdef NONMATCHING_C
  if (Hitbox_TestAttribute(a, 0x7F) && p->unk_e0 == 0 && p->state == 2) {
    s32 power = a->power - b->power;

    if (power < 0) {
      power = 1;
    }
    p->unk_eb = 4;
    p->unk_d2 += power;
    if (p->unk_d2 < p->unk_d4) {
      p->unk_e0 = 12;
      PlaySound_082406e0(0x127);
    } else {
      p->unk_d2 = p->unk_d4;
      Generator_SetState(p, 3);
    }
  }
#else
  INCFUNC("asm/func/FUN_080b29a4.inc");
#endif
}

// state 0 のハンドラ
void FUN_080b2a14(Generator* p) {}

NAKED void FUN_080b2a18(Generator* p) { INCFUNC("asm/func/FUN_080b2a18.inc"); }

NAKED void FUN_080b2b68(Generator* p) { INCFUNC("asm/func/FUN_080b2b68.inc"); }

NAKED void FUN_080b2c70(Generator* p) { INCFUNC("asm/func/FUN_080b2c70.inc"); }

NAKED void FUN_080b2dec(Generator* p) { INCFUNC("asm/func/FUN_080b2dec.inc"); }

NAKED void FUN_080b2f0c(Generator* p) { INCFUNC("asm/func/FUN_080b2f0c.inc"); }

NAKED void FUN_080b31b4(Generator* p) { INCFUNC("asm/func/FUN_080b31b4.inc"); }

// 起動中はゲージ音を鳴らし、待機中は16フレームで state 4 へ進む
void FUN_080b32e0(Generator* p) {
  if (p->unk_f9 != 0) {
    p->unk_f9--;
  }
  if (p->unk_f2 == 0) {
    if (p->stateTimer == 0) {
      Eff082473e0Emitter_Reset(&p->eff_100);
    }
    p->stateTimer++;
    if (p->stateTimer > 15) {
      p->sprite.pos = p->pos;
      p->plttID = 453;
      Generator_SetState(p, 4);
      p->hitbox.damage = 0;
      p->stateTimer = 0;
    } else {
      p->plttID = p->unk_f0 - 1;
    }
  } else {
    p->plttID = p->unk_f0;
    p->unk_f2--;
    if (p->unk_f2 < p->unk_f4) {
      Eff082473e0Emitter_FadeParticle(&p->eff_100);
      p->unk_f4 -= 250;
    }
  }
}

static void (*const sGeneratorUpdates[8])(Generator*) = {
    FUN_080b2a14,
    FUN_080b2a18,
    FUN_080b2b68,
    FUN_080b2c70,
    FUN_080b2dec,
    FUN_080b2f0c,
    FUN_080b31b4,
    FUN_080b32e0,
};  // 0x085AD0B8

// 被弾フラグが立っていれば点滅を強め、収まったら元のパレットに戻していく
void Generator_UpdateFlash(Generator* p) {
  if (p->unk_e2 != 0) {
    if (p->flashTimer <= 11) {
      p->flashTimer++;
    }
    p->unk_e2 = 0;
  } else {
    if (p->flashTimer != 0) {
      p->flashTimer--;
    }
  }
  if (p->flashTimer == 12) {
    Video_SetAuxSpritePltt(&p->gfx, 455);
  } else if (p->flashTimer != 0) {
    Video_SetAuxSpritePltt(&p->gfx, 454);
  } else if (p->unk_eb != 0) {
    Video_SetAuxSpritePltt(&p->gfx, 306);
    p->unk_eb--;
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
}

s32 Generator_Update(Generator* p) {
  if (p->state != 0) Generator_PushPlayer(p);
  if (p->unk_da != 0) p->unk_da--;
  if (p->unk_e0 != 0) p->unk_e0--;
  p->updateCallback(p);
  Generator_UpdateFlash(p);
  if (p->unk_e8 != 0) {
    if (gEntityCBB0->unk_c10 == 0) {
      p->unk_e8 = 0;
    } else if (p->state != 4) {
      p->unk_e8 = 0;
    } else {
      p->hitbox.damage = 0;
      p->unk_e8--;
    }
  }
  return 0;
}

s32 Generator_Destroy(Generator* p) {
  AuxSprite_Remove(&p->sprite);
  Hitbox_Unregister(&p->hitbox);
  Eff082473e0Emitter_Destroy(&p->eff_100);
  return 0;
}

void Generator_InitHitbox(Generator* p, u32 power) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize;
  Vec3 offset;

  halfSize.x = 100, halfSize.y = 200, halfSize.z = 100;
  offset.x = 0, offset.y = 200, offset.z = 0;
  Hitbox_Init(hitbox, 0, HBFLAG_UNK_14 | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hitbox, power, 0, 0);
  Hitbox_SetPos(hitbox, &p->pos, 0);
  Hitbox_SetHandler(hitbox, FUN_080b29a4, p);
}

NAKED s32 Generator_Init(Generator* p, Vec3* pos, s32 param_3, s32 param_4, s32 state, s32 param_6, s32 param_7, u32 power, s32 param_9) { INCFUNC("asm/func/Generator_Init.inc"); }

Generator* Generator_Create(Vec3* pos, s32 param_2, s32 param_3, s32 state, s32 param_5, s32 param_6, u32 power, s32 param_8) {
  Generator* p = CreateEntity(ENTITY_UNK_8, sizeof(Generator));

  if (p != NULL) {
    SetEntityRoutine(p, Generator_Update, Generator_Destroy);
    if (Generator_Init(p, pos, param_2, param_3, state, param_5, param_6, power, param_8) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
