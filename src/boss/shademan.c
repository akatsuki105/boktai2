#include "boss.h"
#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[2396 - 0x18];
} BossShadeMan;
static_assert(sizeof(BossShadeMan) == 2396);

const u8 u8_ARRAY_085aaf2c[64] = {
    0, 2, 3, 4, 4, 3, 1, 6, 3, 0, 5, 0, 5, 3, 4, 6, 4, 3, 1, 6, 0, 4, 2, 3, 3, 0, 5, 0, 4, 6, 5, 3, 0, 3, 4, 2, 4, 3, 1, 6, 3, 0, 5, 0, 4, 6, 5, 3, 3, 4, 0, 2, 3, 0, 5, 0, 4, 3, 1, 6, 5, 3, 4, 6,
};  // 0x085AAF2C

void FUN_0803d8e4(BossShadeMan*);
void FUN_0803d93c(BossShadeMan*);
void FUN_0803d9b4(BossShadeMan*);
void FUN_0803da2c(BossShadeMan*);
void FUN_0803da90(BossShadeMan*);
void FUN_0803dd88(BossShadeMan*);
void FUN_0803de00(BossShadeMan*);
void FUN_0803de78(BossShadeMan*);
void FUN_0803def0(BossShadeMan*);
void FUN_0803df68(BossShadeMan*);
void FUN_0803dfe0(BossShadeMan*);
void FUN_0803e058(BossShadeMan*);
void FUN_0803e4f4(BossShadeMan*);

void (*const PTR_ARRAY_085aaf6c[13])(BossShadeMan*) = {
    FUN_0803d8e4, FUN_0803d93c, FUN_0803d9b4, FUN_0803da2c, FUN_0803da90, FUN_0803dd88, FUN_0803de00, FUN_0803de78, FUN_0803def0, FUN_0803df68, FUN_0803dfe0, FUN_0803e058, FUN_0803e4f4,
};  // 0x085AAF6C

void FUN_0803e578(BossShadeMan*);
void FUN_0803e5d8(BossShadeMan*);

void (*const PTR_ARRAY_085aafa0[2])(BossShadeMan*) = {
    FUN_0803e578,
    FUN_0803e5d8,
};  // 0x085AAFA0

void FUN_0803e5fc(BossShadeMan*);

void (*const PTR_ARRAY_085aafa8[1])(BossShadeMan*) = {
    FUN_0803e5fc,
};  // 0x085AAFA8

void FUN_0803e618(BossShadeMan*);

void (*const PTR_ARRAY_085aafac[1])(BossShadeMan*) = {
    FUN_0803e618,
};  // 0x085AAFAC

void FUN_0803e634(BossShadeMan*);
void FUN_0803e670(BossShadeMan*);

void (*const PTR_ARRAY_085aafb0[2])(BossShadeMan*) = {
    FUN_0803e634,
    FUN_0803e670,
};  // 0x085AAFB0

void FUN_0803e6b0(BossShadeMan*, s32);
void FUN_0803e860(BossShadeMan*, s32);
void FUN_0803e9f4(BossShadeMan*, s32);
void FUN_0803ea98(BossShadeMan*, s32);
void FUN_0803ebc4(BossShadeMan*, s32);
void FUN_0803ed40(BossShadeMan*, s32);
void FUN_0803ee50(BossShadeMan*, s32);
void FUN_0803ef80(BossShadeMan*, s32);
void FUN_0803f2f4(BossShadeMan*, s32);
void FUN_0803f5b8(BossShadeMan*, s32);
void FUN_0803f8cc(BossShadeMan*, s32);
void FUN_0803fc70(BossShadeMan*, s32);
void FUN_0803fef0(BossShadeMan*, s32);
void FUN_080400a4(BossShadeMan*, s32);

void (*const PTR_ARRAY_085aafb8[15])(BossShadeMan*, s32) = {
    NULL, FUN_0803e6b0, FUN_0803e860, FUN_0803e9f4, FUN_0803ea98, FUN_0803ebc4, FUN_0803ed40, FUN_0803ee50, FUN_0803ef80, FUN_0803f2f4, FUN_0803f5b8, FUN_0803f8cc, FUN_0803fc70, FUN_0803fef0, FUN_080400a4,
};  // 0x085AAFB8

s32 FUN_0803c1bc(void* _) { return BOSS_SHADEMAN; }

INCASM("asm/shademan.inc");

NAKED s32 BossShadeMan_Update(BossShadeMan* p) { INCFUNC("asm/func/BossShadeMan_Update.inc"); }

NAKED s32 BossShadeMan_Destroy(BossShadeMan* p) { INCFUNC("asm/func/BossShadeMan_Destroy.inc"); }

NAKED s32 BossShadeMan_Init(BossShadeMan* p, u32 id) { INCFUNC("asm/func/BossShadeMan_Init.inc"); }

BossShadeMan* BossShadeMan_Create(u32 id) {
  BossShadeMan* p = FUN_08022a2c(BOSS_SHADEMAN);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(BossShadeMan));
  if (p != NULL) {
    SetEntityRoutine(p, BossShadeMan_Update, BossShadeMan_Destroy);
    if (BossShadeMan_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
