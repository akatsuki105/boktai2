#ifndef GUARD_ZOKTAI_ARMOR_H
#define GUARD_ZOKTAI_ARMOR_H

#include "constants/constants.h"
#include "gba/gba.h"
#include "types.h"

#define ARMORS(slot) (*(GAME->armors + slot))

struct ArmorData {
  u8 id;
  u8 defence;  // 耐久力
  u8 weight;   // 重量
  u8 effectType;
  u8 value;  // 特殊効果の効果値(Str+2なら2, Spe+10なら10みたいな)
  u8 unk_5;  // padding?
  s16 price;
};

// ------------------------------------------------------------------------------------------------------------------------------------

extern const struct ArmorData gArmorDB[ARMOR_NUM];

// --------------------------------------------

armor32_t GetInventoryArmor(slot32_t n);
void SetArmorIntoInventory(slot32_t n, armor32_t a);
bool32 IsArmorAlreadyFound(armor32_t);
void SetArmorFoundFlag(armor32_t n);

#endif  // GUARD_ZOKTAI_ARMOR_H
