#include "boss.h"
#include "entity.h"
#include "global.h"

// "Typo Beast"
typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[9744 - 0x18];
} Jormungandr;
static_assert(sizeof(Jormungandr) == 9744);

const u16 u16_ARRAY_085ad0d8[3] = {341, 345, 349};  // 0x085AD0D8

const u16 u16_ARRAY_085ad0de[14] = {0, 2, 5, 9, 13, 17, 21, 24, 27, 29, 31, 33, 35, 37};  // 0x085AD0DE

const SoundID16 u16_ARRAY_085ad0fa[3] = {0x2FB, 0x2FD, 0x2FF};  // 0x085AD0FA

INCASM("asm/jormungandr.inc");

NAKED s32 Jormungandr_Update(Jormungandr* p) { INCFUNC("asm/func/Jormungandr_Update.inc"); }

NAKED s32 Jormungandr_Destroy(Jormungandr* p) { INCFUNC("asm/func/Jormungandr_Destroy.inc"); }

NAKED s32 Jormungandr_Init(Jormungandr* p, unknown* param) { INCFUNC("asm/func/Jormungandr_Init.inc"); }

Jormungandr* Jormungandr_Create(unknown* param) {
  Jormungandr* p = FUN_08022a2c(BOSS_JORMUNGANDR);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Jormungandr));
  if (p != NULL) {
    SetEntityRoutine(p, Jormungandr_Update, Jormungandr_Destroy);
    if (Jormungandr_Init(p, param) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
