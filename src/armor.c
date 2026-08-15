#include "armor.h"

#include "global.h"
#include "player.h"
#include "vm.h"

bool32 IsArmorAlreadyFound(armor32_t a) {
  if (a >= 32) {
    return (gStat->armorDex[1]) & (1 << (a - 32));
  } else {
    return (gStat->armorDex[0]) & (1 << a);
  }
}

void SetArmorFoundFlag(armor32_t a) {
  if (a >= 32) {
    gStat->armorDex[1] |= (1 << (a - 32));
  } else {
    gStat->armorDex[0] |= (1 << a);
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

void SwapArmorSlot(slot32_t slot1, slot32_t slot2) {
  s32 a = ARMORS(slot1);
  armor16_t b = ARMORS(slot2);
  ARMORS(slot1) = b;
  ARMORS(slot2) = a;

  if (gStat->armor == slot1) {
    gStat->armor = slot2;
  } else if (gStat->armor == slot2) {
    gStat->armor = slot1;
  }
}

NON_MATCH void SortArmors(s32 from) {
#ifdef NONMATCHING_C
  s32 emptyCount;
  s32 validCount;
  s32 i;
  s32 slot;

  validCount = 0;
  emptyCount = 0;
  i = 0;
  do {
    slot = from + i;
    if (GetInventoryArmor(slot) < 0) {
      emptyCount += 1;
    } else {
      validCount += 1;
      if (emptyCount > 0) {
        SwapArmorSlot(slot, slot - emptyCount);
      }
    }
    i += 1;
  } while (i <= 0xf);

  if (validCount > 1) {
    s32 j;
    s32 k;
    s32 nextJ;
    s32 lastIdx;
    s32 pi;
    s32 pj;
    s32 vi;

    j = 0;
    lastIdx = validCount - 1;
    for (; j < lastIdx;) {
      k = j;
      nextJ = j + 1;
      for (; k < validCount; k++) {
        pi = from + j;
        vi = GetInventoryArmor(pi);
        pj = from + k;
        if (vi > GetInventoryArmor(pj)) {
          SwapArmorSlot(pi, pj);
        }
      }
      j = nextJ;
    }
  }
#else
  INCFUNC("asm/func/SortArmors.inc");
#endif
}

bool32 IsSlotArmorEpuipped(slot32_t n) {
  slot32_t equipped = gStat->armor;
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

  a = Script_GetValue();
  for (slot = 0; slot < 16; slot++) {
    if (GetInventoryArmor(slot) < 0) {
      SetArmorIntoInventory(slot, a);
      return TRUE;
    }
  }

  return FALSE;
}

NON_MATCH void armor_082433bc(void) {
#ifdef NONMATCHING_C
  s32 i;
  s32 count;

  for (i = 0; i <= 1; i++) {
    gStat->armorDex[i] = 0;
  }
  for (i = 0; i <= 31; i++) {
    RemoveArmorFromInventory(i);
  }
  gStat->armor = -1;

  if (prepare_08231510(0x6e)) {
    count = Script_GetValue();
  } else {
    count = 0;
  }

  if (count > 0) {
    if (prepare_08231510(0x61)) {
      for (i = 0; i < count; i++) {
        SetArmorIntoInventory(i, Script_GetValue());
      }
    }
    if (prepare_08231510(0x65)) {
      gStat->armor = Script_GetValue();
    }
  }
#else
  INCFUNC("asm/func/armor_082433bc.inc");
#endif
}

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
