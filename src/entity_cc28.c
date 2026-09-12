#include "entity.h"
#include "global.h"
#include "item.h"

// メニューのインベントリ操作に関係してそう
typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_12
  u8 unk_18[16476 - 0x18];
} EntityCC28;
static_assert(sizeof(EntityCC28) == 16476);

const u16 u16_ARRAY_085ac064[16] = {
    0xD01B, 0xD000, 0xD000, 0xD41B, 0xD02B, 0xD000, 0xD000, 0xD42B, 0xD02B, 0xD000, 0xD000, 0xD42B, 0xD81B, 0xD000, 0xD000, 0xDC1B,
};

// TODO: 他のEntityのrodataもまだ混ざってるのでちゃんと分ける
INCBIN(".rodata", "data/rodata3.bin");  // ./tmp/bin.sh ./baserom.gba 0x085ac084 0x085af0ec ./data/rodata3.bin

INCASM("asm/entity_cc28_part1.inc");

NAKED bool32 FUN_08090724(EntityCC28* p) { INCFUNC("asm/func/FUN_08090724.inc"); }

NAKED void FUN_080907f0(EntityCC28* p) { INCFUNC("asm/func/FUN_080907f0.inc"); }

NAKED void FUN_08090a00(EntityCC28* p) { INCFUNC("asm/func/FUN_08090a00.inc"); }

NAKED s32 FUN_08090b10(EntityCC28* p) { INCFUNC("asm/func/FUN_08090b10.inc"); }

NAKED void FUN_08090b38(EntityCC28* p) { INCFUNC("asm/func/FUN_08090b38.inc"); }

NAKED void FUN_08090ca4(EntityCC28* p) { INCFUNC("asm/func/FUN_08090ca4.inc"); }

NAKED void FUN_08090d54(EntityCC28* p) { INCFUNC("asm/func/FUN_08090d54.inc"); }

NAKED void FUN_08090ee0(void) { INCFUNC("asm/func/FUN_08090ee0.inc"); }

NAKED u32 FUN_08090f0c(u32 bitidx) { INCFUNC("asm/func/FUN_08090f0c.inc"); }

NAKED void FUN_08090f24(EntityCC28* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08090f24.inc"); }

NAKED void FUN_0809107c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809107c.inc"); }

NAKED void FUN_08091270(EntityCC28* p) { INCFUNC("asm/func/FUN_08091270.inc"); }

NAKED void FUN_08091598(EntityCC28* p) { INCFUNC("asm/func/FUN_08091598.inc"); }

NAKED void FUN_08091684(void) { INCFUNC("asm/func/FUN_08091684.inc"); }

NAKED u32 FUN_080916bc(u32 bitidx) { INCFUNC("asm/func/FUN_080916bc.inc"); }

NAKED void FUN_080916d0(u8* param_1, u32 param_2) { INCFUNC("asm/func/FUN_080916d0.inc"); }

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

INCASM("asm/entity_cc28_part2.inc");

EntityCC28* EntityCC28_Create_0809cb74(u32 val, unknown* param_2);
EntityCC28* EntityCC28_Create_0809ce04(u32 val, unknown* param_2);

EntityCC28* EntityCC28_Create(u32 val, unknown* param_2) {
  if (gFlag030047a4 & FLAG030047A4_UNK_11) {
    return EntityCC28_Create_0809cb74(val, param_2);
  }
  return EntityCC28_Create_0809ce04(val, param_2);
}
