#ifndef GUARD_ZOKTAI_ITEM_H
#define GUARD_ZOKTAI_ITEM_H

#include "global.h"

#define ITEM(slot) (*(gStat->items + slot))
#define VALUABLES(slot) (*(gStat->valuables + slot))
#define ROTCOUNT(slot) (*(gStat->rotTimer + slot))

typedef u16 ItemEffectType;  // see "include/constants/item.h", gItemEffectHandlers の idx

typedef struct {
  u16 unk_00;
  u16 effectType;  // see ItemEffectType
  u16 unk_04;
  u16 value;  // 回復アイテムの場合は回復する割合
  u16 unk_08;
  u16 unk_0a;
  u16 price;
  u16 unk_0e;
} ItemData;
static_assert(sizeof(ItemData) == 16);

extern const ItemData gItemDB[ITEM_NUM];

item32_t GetItemID(bool32 isValuable, s32 slot);
item32_t GetNormalItemID(s32 slot);
item32_t GetValuableItemID(s32 slot);
bool32 RemoveSpecifiedItem(item32_t id);

#endif  // GUARD_ZOKTAI_ITEM_H
