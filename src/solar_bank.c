#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite_aux.h"
#include "sprite_main.h"
#include "video.h"

typedef struct Entity7F5E {
  Entity e;                        // ENTITY_UNK_11
  u8 unk_18[0x58 - 0x18];          // 0x018
  MainSprite sprites[13];          // 0x058
  AuxSprite auxSprites[2];         // 0x538
  u8 unk_590[0x5CC - 0x590];       // 0x590
  rgb555* bgPltt;                  // 0x5CC, GetFile(DIR_BGPLTT, 0xEAA8) + 218
  u8 unk_5d0[0x5F0 - 0x5D0];       // 0x5D0
  void (*fn)(struct Entity7F5E*);  // 0x5F0, Entity7F5E_Update が p->fn(p) として呼ぶ状態関数
} Entity7F5E;
static_assert(sizeof(Entity7F5E) == 1524);

NAKED void SolarBank_CalcInterestRate(void) { INCFUNC("asm/func/SolarBank_CalcInterestRate.inc"); }

INCASM("asm/solar_bank.inc");

s32 Entity7F5E_Update(Entity7F5E* p) {
  p->fn(p);
  return 0;
}

s32 Entity7F5E_Destroy(Entity7F5E* p) {
  s32 i;

  for (i = 0; i < 13; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  for (i = 0; i < 2; i++) {
    AuxSprite_Remove(&p->auxSprites[i]);
  }

  return 0;
}

NAKED void FUN_080b4414(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4414.inc"); }

void FUN_080b4454(Entity7F5E* p) {
  p->bgPltt = (rgb555*)GetFile(DIR_BGPLTT, 0xEAA8) + 218;
  CpuCopy32(p->bgPltt, &gBgPlttBuffer[208], 96);
}

NAKED void FUN_080b4490(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4490.inc"); }

NAKED void FUN_080b4740(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4740.inc"); }

NAKED s32 Entity7F5E_Init(Entity7F5E* p) { INCFUNC("asm/func/Entity7F5E_Init.inc"); }

Entity7F5E* Entity7F5E_Create(u32 unused1, u32 unused2) {
  Entity7F5E* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity7F5E));

  if (p != NULL) {
    SetEntityRoutine(p, Entity7F5E_Update, Entity7F5E_Destroy);
    if (Entity7F5E_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
