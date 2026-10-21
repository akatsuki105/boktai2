#ifndef __INCLUDE_ITEM_H__
#define __INCLUDE_ITEM_H__

#include "global.h"

typedef u16 ItemEffectType;  // see "include/constants/item.h", gItemEffectHandlers の idx

typedef struct {
  u16 unk_00;                 // 0x00
  ItemEffectType effectType;  // 0x02, see ItemEffectType
  u16 durability;             // 0x04, 腐りにくさ (0: 腐らない, 大きいほど腐りにくい)
  u16 value1;                 // 0x06, パラメータ1, ItemEffectType に依存 e.g. 回復アイテム(IET_HP)の場合は回復するHPの割合, gItemEffectHandlers の 第2引数
  u16 value2;                 // 0x08, パラメータ2 e.g. IET_GOOD は value1 がバフ種類で, value2 がバフの効果時間, gItemEffectHandlers の 第3引数
  u32 price;                  // 0x0C
} ItemData;
static_assert(sizeof(ItemData) == 16);

extern const ItemData gItemDB[ITEM_NUM];

item32_t GetItemID(bool32 isValuable, s32 slot);
item32_t GetNormalItemID(s32 slot);
item32_t GetValuableItemID(s32 slot);
bool32 CheckItemOwn(item32_t id);
bool32 RemoveSpecifiedItem(item32_t id);
void RotItem(s32 rotDelta);

#endif  // __INCLUDE_ITEM_H__
