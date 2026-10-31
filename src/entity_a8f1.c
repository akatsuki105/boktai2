#include "entity.h"
#include "global.h"
#include "msgbus.h"
#include "particle.h"
#include "sound.h"
#include "sprite_aux.h"

typedef struct {
  Particle ptcl;  // 0x00
  bool8 active;   // 0x28, 立っている枠だけ EntityA8F1_Update が FUN_080a251c に渡す
  u8 unk_29[11];  // 0x29, まだ未解析
} EntityA8F1Ptcl;
static_assert(sizeof(EntityA8F1Ptcl) == 52);

struct EntityA8F1;

typedef void(EntityA8F1Func)(struct EntityA8F1* p);

typedef struct EntityA8F1 {
  Entity e;                        // 0x000, ENTITY_UNK_9
  MsgQueue mq;                     // 0x018, targetClass 10
  u16 unk_4c;                      // 0x04C, まだ未解析
  u16 spriteParam;                 // 0x04E, sprite と sprite2 の +0x10 に入れる値
  AuxSprite sprite;                // 0x050, flags に 0x200 が立つ
  AuxSpriteGfx gfx;                // 0x07C, SPRITE_MAGIC_CIRCLE
  Vec3 pos;                        // 0x098, '.p', y はタイルの attr から計算し直す
  AuxSprite sprite2;               // 0x0A0
  AuxSpriteGfx gfx2;               // 0x0CC, SPRITE_MAGIC_CIRCLE
  AuxSprite subSprites[3];         // 0x0E8
  AuxSpriteGfx subGfx[3];          // 0x16C, SPRITE_MAGIC_CIRCLE, パレットは plttID + 2
  u16 unk_1c0;                     // 0x1C0, '.s' があるとき 7
  s8 unk_1c2;                      // 0x1C2, '.s' の値
  u8 unk_1c3;                      // 0x1C3, まだ未解析
  u16 plttID;                      // 0x1C4
  u16 unk_1c6;                     // 0x1C6, '.s' があるとき 8, 無いとき 0
  EntityA8F1Ptcl ptcls[8];         // 0x1C8
  u8 unk_368;                      // 0x368, '.s' があるとき 0x18, 無いとき 0
  s8 unk_369;                      // 0x369, '.a'
  u16 unk_36a;                     // 0x36A, '.s' があるとき 10, 無いとき 0
  s32 unk_36c;                     // 0x36C, '.C'
  s32 unk_370;                     // 0x370, '.i'
  u8 unk_374[4];                   // 0x374, まだ未解析
  s32 unk_378;                     // 0x378, '.n'
  s32 unk_37c;                     // 0x37C, '.c'
  u16 unk_380;                     // 0x380, '.s' があるとき 1
  u16 stateTimer;                  // 0x382, updateCallback を差し替えるたびに 0 に戻る
  EntityA8F1Func* updateCallback;  // 0x384
} EntityA8F1;
static_assert(sizeof(EntityA8F1) == 904);

NAKED void FUN_080a251c(EntityA8F1Ptcl* ptcl) { INCFUNC("asm/func/FUN_080a251c.inc"); }

NAKED void FUN_080a25c8(unknown* param_1, unknown* param_2) { INCFUNC("asm/func/FUN_080a25c8.inc"); }

NAKED void FUN_080a2678(unknown* param_1, unknown* param_2) { INCFUNC("asm/func/FUN_080a2678.inc"); }

NAKED s32 FUN_080a271c(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a271c.inc"); }

NAKED s32 FUN_080a2778(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a2778.inc"); }

NAKED void FUN_080a2804(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a2804.inc"); }

void FUN_080a2c58(EntityA8F1* p);
void FUN_080a3138(EntityA8F1* p);
void FUN_080a3208(EntityA8F1* p);
void FUN_080a32a4(EntityA8F1* p);

// 更新関数を差し替えて経過フレームを0に戻す
void FUN_080a2c2c(EntityA8F1* p);
void FUN_080a310c(EntityA8F1* p);

void FUN_080a2a14(EntityA8F1* p, EntityA8F1Func* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080a2a2c(EntityA8F1* p) {
  p->sprite.flags |= SPRFLAG_HIDDEN;
  Video_SetAuxSpritePltt(&p->gfx, p->plttID);
}

NAKED void FUN_080a2a4c(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a2a4c.inc"); }

void FUN_080a2b30(EntityA8F1* p) {
  p->unk_368 = 0x18;
  p->unk_1c6 = 8;
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  p->sprite.pos.y = p->pos.y + p->unk_368;
  Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
}

NAKED void FUN_080a2b78(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a2b78.inc"); }

void FUN_080a2bdc(EntityA8F1* p) {
  if (p->unk_1c0 <= 6) {
    p->unk_1c0++;
    FUN_080a2804(p);
  } else {
    p->stateTimer++;
    if (p->stateTimer > 0x1F) {
      PlaySound_082406e0(SE_WARP_START);
      FUN_080a2a14(p, FUN_080a2c2c);
    }
  }
}

void FUN_080a2c2c(EntityA8F1* p) {
  p->stateTimer++;
  if (p->stateTimer > 0xF) {
    FUN_080a2a14(p, FUN_080a2c58);
  }
}

NAKED void FUN_080a2c58(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a2c58.inc"); }

NAKED void FUN_080a2cb0(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a2cb0.inc"); }

NAKED void FUN_080a2d18(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a2d18.inc"); }

NAKED void FUN_080a2e20(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a2e20.inc"); }

NAKED void FUN_080a3004(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a3004.inc"); }

void FUN_080a30bc(EntityA8F1* p) {
  if (p->unk_1c0 <= 6) {
    p->unk_1c0++;
    FUN_080a2804(p);
  } else {
    p->stateTimer++;
    if (p->stateTimer > 0x1F) {
      PlaySound_082406e0(SE_WARP_START);
      FUN_080a2a14(p, FUN_080a310c);
    }
  }
}

void FUN_080a310c(EntityA8F1* p) {
  p->stateTimer++;
  if (p->stateTimer > 0xF) {
    FUN_080a2a14(p, FUN_080a3138);
  }
}

NAKED void FUN_080a3138(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a3138.inc"); }

void FUN_080a31dc(EntityA8F1* p) {
  p->stateTimer++;
  if (p->stateTimer > 0x3B) {
    FUN_080a2a14(p, FUN_080a3208);
  }
}

NAKED void FUN_080a3208(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a3208.inc"); }

void FUN_080a3278(EntityA8F1* p) {
  p->stateTimer++;
  if (p->stateTimer > 0xF) {
    FUN_080a2a14(p, FUN_080a32a4);
  }
}

NAKED void FUN_080a32a4(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a32a4.inc"); }

NAKED void FUN_080a3340(unknown* param_1) { INCFUNC("asm/func/FUN_080a3340.inc"); }

NAKED void FUN_080a3448(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a3448.inc"); }

s32 EntityA8F1_Update(EntityA8F1* p) {
  s32 i;

  FUN_080a3448(p);
  p->updateCallback(p);
  for (i = 0; i < 8; i++) {
    if (p->ptcls[i].active) {
      FUN_080a251c(&p->ptcls[i]);
    }
  }
  return 0;
}

s32 EntityA8F1_Destroy(EntityA8F1* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  AuxSprite_Remove(&p->sprite2);
  for (i = 0; i < 3; i++) {
    AuxSprite_Remove(&p->subSprites[i]);
  }
  for (i = 0; i < 8; i++) {
    Particle_Remove((Particle*)&p->ptcls[i]);
  }
  MsgQueue_Unregister(&p->mq);
  return 0;
}

NAKED void FUN_080a3568(EntityA8F1* p) { INCFUNC("asm/func/FUN_080a3568.inc"); }

NAKED s32 EntityA8F1_Init(EntityA8F1* p, u32 id, u32 param_3) { INCFUNC("asm/func/EntityA8F1_Init.inc"); }

EntityA8F1* EntityA8F1_Create(u32 id, u32 param_2) {
  EntityA8F1* p = CreateEntity(ENTITY_UNK_9, sizeof(EntityA8F1));

  if (p != NULL) {
    SetEntityRoutine(p, EntityA8F1_Update, EntityA8F1_Destroy);
    if (EntityA8F1_Init(p, id, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
