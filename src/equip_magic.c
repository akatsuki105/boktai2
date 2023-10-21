#include "global.h"
#include "magic.h"
#include "player.h"

void FUN_0809c2d0(void);
void FUN_08064fd8(struct Player* p, magic32_t n);

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

WIP void RegisterMagic(s32 idx, magic32_t m) {
#if MODERN
  s32 i;
  for (i = 0; i <= 3; i++) {
    if (REGISTERED_MAGIC(i) == m) {
      REGISTERED_MAGIC(i) = -1;
    }
  }
  REGISTERED_MAGIC(idx) = m;
#else
  INCCODE("asm/wip/RegisterMagic.inc");
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

WIP bool32 FUN_08243584(void) {
#if MODERN
  if (prepare_08231510(109)) {
    return IsMagicUnlocked(fetch_082316e4());
  }
  return FALSE;
#else
  INCCODE("asm/wip/FUN_08243584.inc");
#endif
}

void UnregisterMagic(s32 idx) {
  REGISTERED_MAGIC(idx) = -1;
  return;
}

NAKED void magic_082435b8(void) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r2, _082435F4 @ =0x030046A0\n\
	ldr r1, [r2]\n\
	movs r0, #0\n\
	str r0, [r1, #0x54]\n\
	movs r4, #0\n\
	adds r5, r2, #0\n\
	subs r0, #1\n\
	adds r3, r0, #0\n\
_082435CA:\n\
	ldr r1, [r2]\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r1\n\
	adds r0, #0x68\n\
	strh r3, [r0]\n\
	adds r4, #1\n\
	cmp r4, #3\n\
	ble _082435CA\n\
	ldr r0, [r5]\n\
	adds r0, #0x5a\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	movs r0, #0x6e\n\
	bl prepare_08231510\n\
	cmp r0, #0\n\
	beq _082435F8\n\
	bl fetch_082316e4\n\
	adds r4, r0, #0\n\
	b _082435FA\n\
	.align 2, 0\n\
_082435F4: .4byte 0x030046A0\n\
_082435F8:\n\
	movs r4, #0\n\
_082435FA:\n\
	cmp r4, #0\n\
	ble _0824363C\n\
	movs r0, #0x6d\n\
	bl prepare_08231510\n\
	cmp r0, #0\n\
	beq _0824361A\n\
	cmp r4, #0\n\
	ble _0824361A\n\
_0824360C:\n\
	bl fetch_082316e4\n\
	bl magic_082434f0\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bne _0824360C\n\
_0824361A:\n\
	movs r0, #0x71\n\
	bl prepare_08231510\n\
	cmp r0, #0\n\
	beq _0824363C\n\
	movs r4, #0\n\
	ldr r5, _08243644 @ =0x030046A0\n\
_08243628:\n\
	bl fetch_082316e4\n\
	ldr r2, [r5]\n\
	lsls r1, r4, #1\n\
	adds r1, r1, r2\n\
	adds r1, #0x68\n\
	strh r0, [r1]\n\
	adds r4, #1\n\
	cmp r4, #3\n\
	ble _08243628\n\
_0824363C:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08243644: .4byte 0x030046A0\n\
 .syntax divided\n");
}

s32 FUN_08243648(s32 n) {
  u32 val = n & (~7);
  if ((n & 7) != 0) {
    val += 8;
  }
  return val;
}
