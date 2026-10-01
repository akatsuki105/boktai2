#include "entity.h"
#include "global.h"
#include "item.h"
#include "player.h"
#include "vm.h"

// メニューのインベントリ操作に関係してそう
typedef struct EntityCC28 {
  Entity e;  // 0x0, ENTITY_UNK_12
  u8 unk_18[0x9E0 - 0x18];
  struct Player* player;  // 0x9E0
  u8 unk_9e4[16476 - 0x9E4];
} EntityCC28;
static_assert(sizeof(EntityCC28) == 16476);

extern EntityCC28* gEntityCC28;  // 0x0300013C

const u16 u16_ARRAY_085ac064[16] = {
    0xD01B, 0xD000, 0xD000, 0xD41B, 0xD02B, 0xD000, 0xD000, 0xD42B, 0xD02B, 0xD000, 0xD000, 0xD42B, 0xD81B, 0xD000, 0xD000, 0xDC1B,
};

// TODO: 他のEntityのrodataもまだ混ざってるかもしれない
INCRODATA(".rodata", "data/rodata3.bin");  // ./tools/bin.ts ./baserom.gba 0x085ac084 0x085ad014 ./data/rodata3.bin

INCASM("asm/entity_cc28_part1.inc");

NAKED bool32 FUN_08090724(EntityCC28* p) { INCFUNC("asm/func/FUN_08090724.inc"); }

NAKED void FUN_080907f0(EntityCC28* p) { INCFUNC("asm/func/FUN_080907f0.inc"); }

NAKED void FUN_08090a00(EntityCC28* p) { INCFUNC("asm/func/FUN_08090a00.inc"); }

s32 FUN_08090b10(EntityCC28* p) {
  u8 kind = p->player->kind;

  if (kind == PLAYER_SOLAR_DJANGO) return 0;
  if (kind == PLAYER_SABATA) return 2;

  return 1;
}

NAKED void FUN_08090b38(EntityCC28* p) { INCFUNC("asm/func/FUN_08090b38.inc"); }

NAKED void FUN_08090ca4(EntityCC28* p) { INCFUNC("asm/func/FUN_08090ca4.inc"); }

NAKED void FUN_08090d54(EntityCC28* p) { INCFUNC("asm/func/FUN_08090d54.inc"); }

void FUN_08090ee0(void) {
  if (VM_SeekToNamedArg('i')) {
    s32 bitidx = VM_GetValue();

    gStat->unk_264 |= 1 << bitidx;
  }
}

u32 FUN_08090f0c(u32 bitidx) { return gStat->unk_264 & (1 << bitidx); }

NAKED void FUN_08090f24(EntityCC28* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08090f24.inc"); }

NAKED void FUN_0809107c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809107c.inc"); }

NAKED void FUN_08091270(EntityCC28* p) { INCFUNC("asm/func/FUN_08091270.inc"); }

NAKED void FUN_08091598(EntityCC28* p) { INCFUNC("asm/func/FUN_08091598.inc"); }

NAKED void FUN_08091684(void) { INCFUNC("asm/func/FUN_08091684.inc"); }

extern u16 u16_03002c10;

u32 FUN_080916bc(u32 bitidx) { return u16_03002c10 & (1 << bitidx); }

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
