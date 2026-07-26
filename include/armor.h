#ifndef GUARD_ZOKTAI_ARMOR_H
#define GUARD_ZOKTAI_ARMOR_H

#include "constants/constants.h"
#include "gba/gba.h"
#include "types.h"

#define ARMORS(slot) (*(GAME->armors + slot))

typedef struct {
  u8 id;          // 0x00, see include/constants/armor.h
  u8 defence;     // 0x01, 耐久力
  u8 weight;      // 0x02, 重量
  u8 effectType;  // 0x03
  u8 value;       // 0x04, 特殊効果の効果値(Str+2なら2, Spe+10なら10みたいな)
  u8 unk_5;       // 0x05, padding?
  s16 price;      // 0x06
} ArmorData;
static_assert(sizeof(ArmorData) == 8);

extern const ArmorData gArmorDB[ARMOR_NUM];

// --------------------------------------------

armor32_t GetInventoryArmor(slot32_t n);
void SetArmorIntoInventory(slot32_t n, armor32_t a);
bool32 IsArmorAlreadyFound(armor32_t);
void SetArmorFoundFlag(armor32_t n);

#endif  // GUARD_ZOKTAI_ARMOR_H
