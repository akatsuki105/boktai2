#include "boss.h"
#include "entity.h"
#include "global.h"
#include "shadow.h"
#include "sprite_main.h"

// シェードマン(クロスオーバーバトル用)
typedef struct {
  Entity e;                  // 0x0, ENTITY_UNK_8
  u8 unk_18[0x34C - 0x18];   // 0x034C, まだ未解析
  MainSprite sprite;         // 0x34C, _Destroy が MainSprite_Remove に渡す
  AuxShadow shadow;          // 0x3AC, _Destroy が AuxShadow_Remove に渡す
  u8 unk_418[2396 - 0x418];  // 0x418, まだ未解析
} ShadeManCrossover;
static_assert(sizeof(ShadeManCrossover) == 2396);

const u8 u8_ARRAY_085aaf2c[64] = {0, 2, 3, 4, 4, 3, 1, 6, 3, 0, 5, 0, 5, 3, 4, 6, 4, 3, 1, 6, 0, 4, 2, 3, 3, 0, 5, 0, 4, 6, 5, 3, 0, 3, 4, 2, 4, 3, 1, 6, 3, 0, 5, 0, 4, 6, 5, 3, 3, 4, 0, 2, 3, 0, 5, 0, 4, 3, 1, 6, 5, 3, 4, 6};  // 0x085AAF2C

void FUN_0803c264(ShadeManCrossover*);
void FUN_0803c76c(ShadeManCrossover*);

void FUN_0803d8e4(ShadeManCrossover*);
void FUN_0803d93c(ShadeManCrossover*);
void FUN_0803d9b4(ShadeManCrossover*);
void FUN_0803da2c(ShadeManCrossover*);
void FUN_0803da90(ShadeManCrossover*);
void FUN_0803dd88(ShadeManCrossover*);
void FUN_0803de00(ShadeManCrossover*);
void FUN_0803de78(ShadeManCrossover*);
void FUN_0803def0(ShadeManCrossover*);
void FUN_0803df68(ShadeManCrossover*);
void FUN_0803dfe0(ShadeManCrossover*);
void FUN_0803e058(ShadeManCrossover*);
void FUN_0803e4f4(ShadeManCrossover*);

void (*const PTR_ARRAY_085aaf6c[13])(ShadeManCrossover*) = {
    FUN_0803d8e4,
    FUN_0803d93c,
    FUN_0803d9b4,
    FUN_0803da2c,
    FUN_0803da90,
    FUN_0803dd88,
    FUN_0803de00,
    FUN_0803de78,
    FUN_0803def0,
    FUN_0803df68,
    FUN_0803dfe0,
    FUN_0803e058,
    FUN_0803e4f4,
};  // 0x085AAF6C

void FUN_0803e578(ShadeManCrossover*);
void FUN_0803e5d8(ShadeManCrossover*);

void (*const PTR_ARRAY_085aafa0[2])(ShadeManCrossover*) = {
    FUN_0803e578,
    FUN_0803e5d8,
};  // 0x085AAFA0

void FUN_0803e5fc(ShadeManCrossover*);

void (*const PTR_ARRAY_085aafa8[1])(ShadeManCrossover*) = {
    FUN_0803e5fc,
};  // 0x085AAFA8

void FUN_0803e618(ShadeManCrossover*);

void (*const PTR_ARRAY_085aafac[1])(ShadeManCrossover*) = {
    FUN_0803e618,
};  // 0x085AAFAC

void FUN_0803e634(ShadeManCrossover*);
void FUN_0803e670(ShadeManCrossover*);

void (*const PTR_ARRAY_085aafb0[2])(ShadeManCrossover*) = {
    FUN_0803e634,
    FUN_0803e670,
};  // 0x085AAFB0

void FUN_0803e6b0(ShadeManCrossover*, s32);
void FUN_0803e860(ShadeManCrossover*, s32);
void FUN_0803e9f4(ShadeManCrossover*, s32);
void FUN_0803ea98(ShadeManCrossover*, s32);
void FUN_0803ebc4(ShadeManCrossover*, s32);
void FUN_0803ed40(ShadeManCrossover*, s32);
void FUN_0803ee50(ShadeManCrossover*, s32);
void FUN_0803ef80(ShadeManCrossover*, s32);
void FUN_0803f2f4(ShadeManCrossover*, s32);
void FUN_0803f5b8(ShadeManCrossover*, s32);
void FUN_0803f8cc(ShadeManCrossover*, s32);
void FUN_0803fc70(ShadeManCrossover*, s32);
void FUN_0803fef0(ShadeManCrossover*, s32);
void FUN_080400a4(ShadeManCrossover*, s32);

void (*const PTR_ARRAY_085aafb8[15])(ShadeManCrossover*, s32) = {
    NULL,
    FUN_0803e6b0,
    FUN_0803e860,
    FUN_0803e9f4,
    FUN_0803ea98,
    FUN_0803ebc4,
    FUN_0803ed40,
    FUN_0803ee50,
    FUN_0803ef80,
    FUN_0803f2f4,
    FUN_0803f5b8,
    FUN_0803f8cc,
    FUN_0803fc70,
    FUN_0803fef0,
    FUN_080400a4,
};  // 0x085AAFB8

s32 FUN_0803c1bc(void* _) { return BOSS_SHADEMAN_CROSSOVER; }

INCASM("asm/shademan_crossover.inc");

void FUN_0803cee4(ShadeManCrossover*);
void FUN_0803e68c(ShadeManCrossover*);
void FUN_08040184(ShadeManCrossover*);
void FUN_0803d0a4(ShadeManCrossover*);

s32 ShadeManCrossover_Update(ShadeManCrossover* p) {
  FUN_0803cee4(p);
  FUN_0803e68c(p);
  FUN_08040184(p);
  FUN_0803d0a4(p);
  return 0;
}

s32 ShadeManCrossover_Destroy(ShadeManCrossover* p) {
  AuxShadow_Remove(&p->shadow);
  FUN_0803c264(p);
  FUN_0803c76c(p);
  MainSprite_Remove(&p->sprite);
  FUN_08022b04((Boss*)p);
  return 0;
}

NAKED s32 ShadeManCrossover_Init(ShadeManCrossover* p, u32 id) { INCFUNC("asm/func/ShadeManCrossover_Init.inc"); }

// 0x4AB1, HashName("クロスオーバーシェードマン")
ShadeManCrossover* ShadeManCrossover_Create(u32 id) {
  ShadeManCrossover* p = FUN_08022a2c(BOSS_SHADEMAN_CROSSOVER);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(ShadeManCrossover));
  if (p != NULL) {
    SetEntityRoutine(p, ShadeManCrossover_Update, ShadeManCrossover_Destroy);
    if (ShadeManCrossover_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
