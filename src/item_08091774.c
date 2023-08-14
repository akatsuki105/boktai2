#include "global.h"
#include "item.h"

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
