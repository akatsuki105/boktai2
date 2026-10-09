#include "global.h"
#include "player.h"
#include "vm.h"

// TODO: このマクロを使わずに自然なCコードで一致するコードがかけるならこのマクロを削除する
#define REGISTERED_MAGIC(n) (*(gStat->registeredMagic + n))

void FUN_0809c2d0(void);

s32 GetMagicCategory(magic32_t id) {
  if (id < 10) {
    return MC_LUNA;
  } else if (id < 14) {
    return MC_SOL;
  } else {
    return MC_DARK;
  }
}

magic32_t UNUSED GetEquippedMagic(void) {
  const s32 idx = gStat->equippedMagicIdx;
  return REGISTERED_MAGIC(idx);
}

// 同じ魔法が他のスロットに入っていれば外してから idx のスロットに登録する
void RegisterMagic(s32 idx, magic32_t m) {
  s32 i;
  for (i = 0; i < 4; i++) {
    if (REGISTERED_MAGIC(i) == m) {
      REGISTERED_MAGIC(i) = -1;
    }
  }
  REGISTERED_MAGIC(idx) = m;
}

void UnlockMagic(magic32_t n) {
  s32 i;
  gStat->unlockedMagic |= (1 << n);
  for (i = 0; i < 4; i++) {
    if (REGISTERED_MAGIC(i) == MAGIC_NONE) {
      RegisterMagic(i, n);
      FUN_0809c2d0();
      if (i != gStat->equippedMagicIdx) {
        return;
      }
      if (gPlayerPtr[0] != NULL) {
        Player_EquipMagic(gPlayerPtr[0], n);
      }
      return;
    }
  }
}

// 0xE083
void UnlockMagicScripted(void) {
  if (VM_SeekToNamedArg('m')) {
    UnlockMagic(VM_GetValue());
  }
}

bool32 IsMagicUnlocked(magic32_t n) {
  const u32 unlocked = gStat->unlockedMagic & (1 << n);
  return unlocked;
}

bool32 FUN_08243584(void) {
  if (VM_SeekToNamedArg('m')) {
    return IsMagicUnlocked(VM_GetValue());
  }
}

void UnregisterMagic(s32 idx) {
  REGISTERED_MAGIC(idx) = -1;
  return;
}

// 0x1887
NAKED void magic_082435b8(void) { INCFUNC("asm/func/magic_082435b8.inc"); }
