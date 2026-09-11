#include "entity.h"
#include "global.h"

typedef struct EntityE435 {
  Entity e;    // 0x0, ENTITY_UNK_9 or ENTITY_UNK_11
  u16 id;      // 0x018
  u16 unk_1a;  // 0x01A
  u16 unk_1c;  // 0x01C
  u8 unk_1e;   // 0x01E
  u8 unk_1f;   // 0x01F
  u8 unk_20[628 - 0x20];
} EntityE435;
static_assert(sizeof(EntityE435) == 628);

extern EntityE435* gEntityE435;  // 0x03000070

void FUN_0822f0d8(void);

void FUN_080179ac(void) { gEntityE435 = NULL; }

NAKED s32 EntityE435_Update(EntityE435* p) { INCFUNC("asm/func/EntityE435_Update.inc"); }

s32 EntityE435_Destroy(EntityE435* p) {
  FUN_0822f0d8();
  gEntityE435 = NULL;
  return 0;
}

NAKED s32 EntityE435_Init(EntityE435* p, u32 id) { INCFUNC("asm/func/EntityE435_Init.inc"); }

NAKED EntityE435* EntityE435_Create(u32 id) { INCFUNC("asm/func/EntityE435_Create.inc"); }
