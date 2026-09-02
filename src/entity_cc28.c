#include "entity.h"
#include "global.h"
#include "item.h"

// メニューのインベントリ操作に関係してそう
typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_12
  u8 unk_18[16476 - 0x18];
} EntityCC28;
static_assert(sizeof(EntityCC28) == 16476);

u32 item_08091774(item32_t n) { return gItemDB[n].unk_00 & 0xF; }
u32 item_08091788(item32_t n) { return (gItemDB[n].unk_00 & 0xF0) >> 4; }
u8 item_0809179c(item32_t n) { return (gItemDB[n].unk_00 & 0x100) >> 8; }
u8 item_080917b4(item32_t n) { return (gItemDB[n].unk_00 & 0x200) >> 9; }

// 0x080917cc
item32_t GetItemID(bool32 isValuable, s32 slot) {
  if (!isValuable) {
    return GetNormalItemID(slot);
  }
  return GetValuableItemID(slot);
}

INCASM("asm/entity_cc28.inc");

EntityCC28* EntityCC28_Create_0809cb74(u32 val, unknown* param_2);
EntityCC28* EntityCC28_Create_0809ce04(u32 val, unknown* param_2);

EntityCC28* EntityCC28_Create(u32 val, unknown* param_2) {
  if (gFlag030047a4 & FLAG030047A4_UNK_11) {
    return EntityCC28_Create_0809cb74(val, param_2);
  }
  return EntityCC28_Create_0809ce04(val, param_2);
}
