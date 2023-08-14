#ifndef GUARD_ZOKTAI_ITEM_H
#define GUARD_ZOKTAI_ITEM_H

#include "global.h"

#define ITEM(slot) (*(GAME->items + slot))
#define VALUABLES(slot) (*(GAME->valuables + slot))
#define ROTCOUNT(slot) (*(GAME->rotTimer + slot))

// ItemData.effectType
enum ItemEffectType {
  ITEM_EFFECT_UNK0,
  ITEM_EFFECT_HP,          // HP回復
  ITEM_EFFECT_MP,          // Ene回復
  ITEM_EFFECT_BAD_STATUS,  // 毒などの状態異常回復
  ITEM_EFFECT_UNK4,
  ITEM_EFFECT_UNK5,
  // anymore?
};

struct ItemData {
  u16 unk_00;
  u16 effectType;
  u16 unk_04;
  u16 value;  // 回復アイテムの場合は回復する割合
  u16 unk_08;
  u16 unk_0a;
  u16 price;
  u16 unk_0e;
};
static_assert(sizeof(struct ItemData) == 16);

extern const struct ItemData gItemDB[ITEM_NUM];

item32_t GetItemID(bool32 isValuable, s32 slot);
item32_t GetNormalItemID(s32 slot);
item32_t GetValuableItemID(s32 slot);

#endif  // GUARD_ZOKTAI_ITEM_H
