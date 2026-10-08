#ifndef __INCLUDE_INVENTORY_H__
#define __INCLUDE_INVENTORY_H__

#include "gba/gba.h"
#include "types.h"

void SwapNormalItem(slot32_t slot1, slot32_t slot2);
void SwapValuable(slot32_t slot1, slot32_t slot2);
void RemoveItem(slot32_t slot);
void RemoveValuable(slot32_t slot);
void SetRotCount2(slot32_t slot, u32 value);

#endif  // __INCLUDE_INVENTORY_H__
