#ifndef __INCLUDE_INVENTORY_H__
#define __INCLUDE_INVENTORY_H__

#include "gba/gba.h"
#include "types.h"

// ItemCategory8, ItemCategory16, ItemCategory32
#define ITEM_CATEGORY_USABLE 0  // 消費アイテム, 貴重品 (名前は後でもっといいものにする)
#define ITEM_CATEGORY_WEAPON 1
#define ITEM_CATEGORY_ARMOR 2
#define ITEM_CATEGORY_MAGIC 3
#define ITEM_CATEGORY_UNK4 4

void SwapNormalItem(slot32_t slot1, slot32_t slot2);
void SwapValuable(slot32_t slot1, slot32_t slot2);
void RemoveItem(slot32_t slot);
void RemoveValuable(slot32_t slot);
void SetItem(slot32_t slot, item32_t id);
void SetValuable(slot32_t slot, item32_t id);
s32 GetRotCount(slot32_t slot);
s32 GetRotCount2(slot32_t slot);
void SetRotCount(slot32_t slot, u32 value);
void SetRotCount2(slot32_t slot, u32 value);
void SortInventory(slot32_t slot);
void SortValuable(slot32_t slot);
void SortArmors(slot32_t from);
void RemoveWeapon(slot32_t n);
bool32 TryAddItem(item32_t n, s32 rotCount);

#endif  // __INCLUDE_INVENTORY_H__
