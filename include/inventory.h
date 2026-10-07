#ifndef __INCLUDE_INVENTORY_H__
#define __INCLUDE_INVENTORY_H__

#include "gba/gba.h"
#include "types.h"

void SwapNormalItem(slot32_t slot1, slot32_t slot2);
void SwapValuable(slot32_t slot1, slot32_t slot2);

#endif  // __INCLUDE_INVENTORY_H__
