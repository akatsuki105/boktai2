#include "entity.h"
#include "global.h"

typedef struct Entity9A9F {
  Entity e;        // ENTITY_UNK_1
  s16 playerIdx;   // 0x18, gPlayerPtr の添字 (-1 は該当なし), 根拠: Entity9A9F_Create が 0xFFFF で初期化し、FUN_0823c450 が負を弾いて gPlayerPtr[playerIdx] を引く
  u8 unk_1a[730];  // 0x1A
} Entity9A9F;
static_assert(sizeof(Entity9A9F) == 756);

extern Entity9A9F* gEntity9A9F;  // 0x03002C68

Entity9A9F* FUN_081dd9a0(void) { return gEntity9A9F; }

void FUN_081dd9ac(void) { gEntity9A9F = NULL; }

INCASM("asm/entity_9a9f.inc");

NAKED s32 FUN_081dfa98(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dfa98.inc"); }

NAKED s32 Entity9A9F_Destroy(Entity9A9F* p) { INCFUNC("asm/func/Entity9A9F_Destroy.inc"); }

NAKED Entity9A9F* Entity9A9F_Create(void) { INCFUNC("asm/func/Entity9A9F_Create.inc"); }

void FUN_081dfe5c(void) {
  if (gEntity9A9F != NULL) {
    FUN_081dfa98(gEntity9A9F);
  }
}
