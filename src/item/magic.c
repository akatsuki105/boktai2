#include "global.h"
#include "player.h"
#include "vm.h"

void HUD_RebuildQCMagic(void);

#define REGISTERED_MAGIC(n) (*(gStat->registeredMagic + (n)))

s32 GetMagicCategory(magic32_t id) {
  if (id < 10) {
    return MC_LUNA;
  } else if (id < 14) {
    return MC_SOL;
  } else {
    return MC_DARK;
  }
}

magic32_t UNUSED GetEquippedMagic(void) { return REGISTERED_MAGIC(gStat->equippedMagicIdx); }

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
      HUD_RebuildQCMagic();
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

// 0xE083, HashName("魔法取得")
void Cmd_UnlockMagic(void) {
  if (VM_SeekToNamedArg('m')) {
    UnlockMagic(VM_GetValue());
  }
}

bool32 IsMagicUnlocked(magic32_t id) {
  const u32 unlocked = gStat->unlockedMagic & (1 << id);
  return unlocked;
}

// 0x83E7
bool32 Cmd_IsMagicUnlocked(void) {
  if (VM_SeekToNamedArg('m')) {
    return IsMagicUnlocked(VM_GetValue());
  }
}

void UnregisterMagic(s32 idx) { REGISTERED_MAGIC(idx) = -1; }

// 0x1887, HashName("魔法初期化"), 魔法を全て未取得にし, .n 個の魔法を .m から取得し, .q の4つを登録枠に入れる
void Cmd_InitMagicData(void) {
  s32 i;
  s32 count;

  gStat->unlockedMagic = 0;
  for (i = 0; i < 4; i++) {
    REGISTERED_MAGIC(i) = MAGIC_NONE;
  }
  gStat->equippedMagicIdx = 0;

  if (VM_SeekToNamedArg('n')) {
    count = VM_GetValue();
  } else {
    count = 0;
  }

  if (count > 0) {
    if (VM_SeekToNamedArg('m')) {
      for (i = 0; i < count; i++) {
        UnlockMagic(VM_GetValue());
      }
    }
    if (VM_SeekToNamedArg('q')) {
      for (i = 0; i < 4; i++) {
        REGISTERED_MAGIC(i) = VM_GetValue();
      }
    }
  }
}
