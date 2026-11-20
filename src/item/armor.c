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

// 防具欄の from から 16 枠の空きを詰め, 防具番号の小さい順に並べる
void SortArmors(slot32_t from) {
  s32 validCount = 0;
  s32 emptyCount = 0;
  s32 i;

  for (i = 0; i < 16; i++) {
    s32 slot = from + i;

    if (GetInventoryArmor(slot) < 0) {
      emptyCount++;
    } else {
      validCount++;
      if (emptyCount > 0) {
        SwapArmorSlot(slot, slot - emptyCount);
      }
    }
  }

  if (validCount > 1) {
    s32 j;

    for (i = 0; i < validCount - 1; i++) {
      for (j = i; j < validCount; j++) {
        if (GetInventoryArmor(from + i) > GetInventoryArmor(from + j)) {
          SwapArmorSlot(from + i, from + j);
        }
      }
    }
  }
}

bool32 IsSlotArmorEpuipped(slot32_t n) {
  slot32_t equipped = gStat->armor;
  if (equipped == n) {
    return TRUE;
  }
  return FALSE;
}

bool32 Cmd_7B7D(void) {
  slot32_t slot;
  armor32_t a;
  if (!VM_SeekToNamedArg('a')) {
    return FALSE;
  }

  a = VM_GetValue();
  for (slot = 0; slot < 16; slot++) {
    if (GetInventoryArmor(slot) < 0) {
      SetArmorIntoInventory(slot, a);
      return TRUE;
    }
  }
  return FALSE;
}

// 0xFEF2, HashName("防具初期化"), 防具図鑑と所持枠と装備を空にし, .n 個の防具を .a から所持枠に入れ, .e を装備枠にする
void Cmd_ResetArmors(void) {
  s32 i;
  s32 count;

  for (i = 0; i < 2; i++) {
    ARMOR_DEX(i) = 0;
  }
  for (i = 0; i < 32; i++) {
    RemoveArmorFromInventory(i);
  }
  EQUIPPED_ARMOR = ARMOR_NONE;

  if (VM_SeekToNamedArg('n')) {
    count = VM_GetValue();
  } else {
    count = 0;
  }

  if (count > 0) {
    if (VM_SeekToNamedArg('a')) {
      for (i = 0; i < count; i++) {
        SetArmorIntoInventory(i, VM_GetValue());
      }
    }
    if (VM_SeekToNamedArg('e')) {
      EQUIPPED_ARMOR = VM_GetValue();
    }
  }
}

// 収集数を数える, ロックマン系のコラボ装備4つ (33..36) は数に入れない
s32 Cmd_CountFoundArmors(void) {
  s32 i;
  s32 count = 0;
  for (i = 0; i < ARMOR_NUM; i++) {
    if (i < ARMOR_MEGA_POWER || i > ARMOR_TOAD_POWER) {
      if (IsArmorAlreadyFound(i)) {
        count++;
      }
    }
  }
  return count;
}
