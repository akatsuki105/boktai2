#ifndef __INCLUDE_INVENTORY_H__
#define __INCLUDE_INVENTORY_H__

#include "gba/gba.h"
#include "types.h"

void SwapNormalItem(slot32_t slot1, slot32_t slot2);
void SwapValuable(slot32_t slot1, slot32_t slot2);
void RemoveItem(slot32_t slot);
void RemoveValuable(slot32_t slot);
void SetItem(slot32_t slot, item32_t id);
void SetValuable(slot32_t slot, item32_t id);
s32 GetRotCount(slot32_t slot);
void SetRotCount2(slot32_t slot, u32 value);
void SortInventory(slot32_t slot);
void SortArmors(slot32_t from);
void FUN_08242c08(slot32_t n);
bool32 TryAddItem(item32_t n, s32 rotCount);

#endif  // __INCLUDE_INVENTORY_H__
