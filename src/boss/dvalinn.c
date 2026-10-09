#include "boss.h"
#include "entity.h"
#include "global.h"

// ボス戦前の人型のイベント時もこれ使う
typedef struct Dvalinn {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[2120 - 0x18];
} Dvalinn;
static_assert(sizeof(Dvalinn) == 2120);

extern Dvalinn* gDvalinn;  // 0x03002C80
extern u32 u32_03002bc0;   // src/iwram2.c

static inline bool32 TestFlag03002bc0(u32 flags) { return (u32_03002bc0 & flags) != 0; }

void FUN_08022e20(Dvalinn*);  // asm/boss.inc
void FUN_08022ec0(Dvalinn*);  // asm/boss.inc
void FUN_081fc86c(Dvalinn*);
void FUN_081ff734(Dvalinn*);
void FUN_081ff740(Dvalinn*);
void FUN_081ffd9c(Dvalinn*);
void FUN_081ffdb0(Dvalinn*);

INCASM("asm/dvalinn.inc");

s32 Dvalinn_Update(Dvalinn* p) {
  if (!TestFlag03002bc0(4)) {
    FUN_08022e20(p);
    FUN_081ffd9c(p);
    FUN_081fc86c(p);
    FUN_081ff740(p);
    FUN_081ff734(p);
    FUN_08022ec0(p);
    FUN_081ffdb0(p);
  }
  return 0;
}

NAKED s32 Dvalinn_Destroy(Dvalinn* p) { INCFUNC("asm/func/Dvalinn_Destroy.inc"); }

NAKED s32 Dvalinn_Init(Dvalinn* p, u32 id) { INCFUNC("asm/func/Dvalinn_Init.inc"); }

Dvalinn* Dvalinn_Create(u32 id) {
  Dvalinn* p = FUN_08022a2c(BOSS_DVALINN);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Dvalinn));
  if (p != NULL) {
    SetEntityRoutine(p, Dvalinn_Update, Dvalinn_Destroy);
    if (Dvalinn_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  gDvalinn = p;
  return p;
}

NAKED void FUN_08200a6c(void) { INCFUNC("asm/func/FUN_08200a6c.inc"); }
