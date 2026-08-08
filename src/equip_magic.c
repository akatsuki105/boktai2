#include "global.h"
#include "magic.h"
#include "player.h"

void FUN_0809c2d0(void);
void FUN_08064fd8(Player* p, magic32_t n);

s32 FUN_0824347c(s32 n) {
  if (n < 10) {
    return 0;
  } else if (n < 14) {
    return 1;
  } else {
    return 2;
  }
}

magic32_t GetEquippedMagic(void) {
  const s32 idx = GAME->equippedMagicIdx;
  return REGISTERED_MAGIC(idx);
}

NON_MATCH void RegisterMagic(s32 idx, magic32_t m) {
#ifdef NONMATCHING_C
  s32 i;
  for (i = 0; i <= 3; i++) {
    if (REGISTERED_MAGIC(i) == m) {
      REGISTERED_MAGIC(i) = -1;
    }
  }
  REGISTERED_MAGIC(idx) = m;
#else
  INCFUNC("asm/func/RegisterMagic.inc");
#endif
}

void magic_082434f0(magic32_t n) {
  s32 i;
  GAME->unlockedMagic |= (1 << n);
  for (i = 0; i < 4; i++) {
    if (REGISTERED_MAGIC(i) == MAGIC_NONE) {
      RegisterMagic(i, n);
      FUN_0809c2d0();
      if (i != GAME->equippedMagicIdx) {
        return;
      }
      if (gPlayerPtr[0] != NULL) {
        FUN_08064fd8(gPlayerPtr[0], n);
      }
      return;
    }
  }
}

void FUN_08243558(void) {
  if (prepare_08231510(109)) {
    magic_082434f0(fetch_082316e4());
  }
}

bool32 IsMagicUnlocked(magic32_t n) {
  const u32 unlocked = GAME->unlockedMagic & (1 << n);
  return unlocked;
}

bool32 FUN_08243584(void) {
  s32 x = prepare_08231510(109);
  if (x) {
    return IsMagicUnlocked(fetch_082316e4());
  }
}

void UnregisterMagic(s32 idx) {
  REGISTERED_MAGIC(idx) = -1;
  return;
}

NAKED void magic_082435b8(void) { INCFUNC("asm/func/magic_082435b8.inc"); }

s32 FUN_08243648(s32 n) {
  u32 val = n & (~7);
  if ((n & 7) != 0) {
    val += 8;
  }
  return val;
}
