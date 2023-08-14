#include "armor.h"

#include "global.h"
#include "player.h"

bool32 IsArmorAlreadyFound(armor32_t a) {
  if (a >= 32) {
    return (GAME->armorDex[1]) & (1 << (a - 32));
  } else {
    return (GAME->armorDex[0]) & (1 << a);
  }
}

void SetArmorFoundFlag(armor32_t a) {
  if (a >= 32) {
    GAME->armorDex[1] |= (1 << (a - 32));
  } else {
    GAME->armorDex[0] |= (1 << a);
  }
}

void SetArmorIntoInventory(slot32_t n, armor32_t a) {
  SetArmorFoundFlag(a);
  ARMORS(n) = a;
  return;
}

armor32_t GetInventoryArmor(slot32_t n) {
  armor32_t result = ARMORS(n);
  return result;
}

void RemoveArmorFromInventory(slot32_t n) {
  ARMORS(n) = ARMOR_NONE;
  return;
}

WIP void SwapArmorSlot(slot32_t slot1, slot32_t slot2) {
#if MODERN
  armor_t a = ARMORS(slot1);
  armor_t b = ARMORS(slot2);
  ARMORS(slot1) = b;
  ARMORS(slot2) = a;

  if (GAME->armor == slot1) {
    GAME->armor = slot2;
  } else if (GAME->armor == slot2) {
    GAME->armor = slot1;
  }
#else
  INCCODE("asm/wip/SwapArmorSlot.inc");
#endif
}

NAKED void SortArmors(s32 from) { INCCODE("asm/todo/SortArmors.inc"); }

bool32 IsSlotArmorEpuipped(slot32_t n) {
  slot32_t equipped = GAME->armor;
  if (equipped == n) {
    return TRUE;
  }
  return FALSE;
}

bool32 FUN_08243380(void) {
  slot32_t slot;
  armor32_t a;
  if (prepare_08231510(97) == 0) {
    return FALSE;
  }

  a = fetch_082316e4();
  for (slot = 0; slot < 16; slot++) {
    if (GetInventoryArmor(slot) < 0) {
      SetArmorIntoInventory(slot, a);
      return TRUE;
    }
  }

  return FALSE;
}

NAKED void armor_082433bc(void) { INCCODE("asm/todo/armor_082433bc.inc"); }

s32 CountFoundArmors(void) {
  s32 i;
  s32 count = 0;
  for (i = 0; i < ARMOR_NUM; i++) {
    if (3 < (u32)(i - 33)) {
      if (IsArmorAlreadyFound(i)) {
        count++;
      }
    }
  }
  return count;
}
