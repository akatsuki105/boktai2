#ifndef __INCLUDE_INVENTORY_H__
#define __INCLUDE_INVENTORY_H__

#include "gba/gba.h"
#include "types.h"

// ItemCategory8, ItemCategory16, ItemCategory32
#define INVENTORY_ITEM 0    // 消費アイテム, 貴重品
#define INVENTORY_WEAPON 1  // 武器
#define INVENTORY_ARMOR 2   // 防具
#define INVENTORY_MAGIC 3   // 魔法
#define INVENTORY_UNK4 4    // 不使用?

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
