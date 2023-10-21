#include "weapon.h"

#include "global.h"

void FUN_0809c28c(void);

bool32 IsWeaponAlreadyFound(weapon32_t n) {
  if (n >= 32) {
    return (GAME->weaponDex[1]) & (1 << (n - 32));
  } else {
    return (GAME->weaponDex[0]) & (1 << n);
  }
}

void SetWeaponFoundFlag(weapon32_t n) {
  if (n >= 32) {
    (GAME->weaponDex[1]) |= (1 << (n - 32));
  } else {
    (GAME->weaponDex[0]) |= (1 << n);
  }
}

// 0x082429d8
struct Weapon* GetWeapon(s32 slot) { return WEAPONS(slot); }

weapon32_t GetWeaponID(s32 slot) { return GetWeapon(slot)->id; }

u32 GetWeaponKind(s32 slot) { return gWeaponDB[GetWeapon(slot)->id].kind; }

s8 GetWeaponQuality(s32 slot) { return GetWeapon(slot)->quality; }

u32 GetWeaponDurability(s32 slot) { return GetWeapon(slot)->durability; }

NAKED void FUN_08242a38(struct WeaponData* w, void* r1) { INCCODE("asm/todo/FUN_08242a38.inc"); }

NAKED void FUN_08242a98(struct Weapon* w, struct WeaponData* data) { INCCODE("asm/todo/FUN_08242a98.inc"); }

void FUN_08242b14(slot32_t n, struct WeaponData* data) {
  FUN_08242a98(GetWeapon(n), data);
  return;
}

NAKED void FUN_08242b28(s32 idx, struct WeaponData* data) { INCCODE("asm/todo/FUN_08242b28.inc"); }

void FUN_08242b6c(slot32_t n, const struct WeaponData* data) {
  struct Weapon* w = GetWeapon(n);
  FUN_08242a38((struct WeaponData*)data, w);
  SetWeaponFoundFlag(data->id);
}

WIP bool32 FUN_08242b88(struct WeaponData* data) {
#if MODERN
  struct Player* p;
  s32 slot = 0;
  while (TRUE) {
    if (slot > 15) {
      return FALSE;
    }
    if (GetWeaponID(slot) == WEAPON_NONE) {
      break;
    }
    slot++;
  }

  FUN_08242b6c(slot, data);
  if ((data->kind < 3) && (REGISTERED_WEAPON(data->kind) == -1)) {
    REGISTERED_WEAPON(data->kind) = slot;
    if (data->kind == 0) {
      GAME->equippedWeaponIdx = 0;
      if (gPlayerPtr[0] != NULL) {
        struct Weapon* w = GetWeapon(slot);
        weapon_08064664(gPlayerPtr[0], w);
      }
    }
    FUN_0809c28c();
  }
  return TRUE;
#else
  INCCODE("asm/wip/FUN_08242b88.inc");
#endif
}

WIP void FUN_08242c08(slot32_t n) {
#if MODERN
  s32 i;
  FUN_08242b6c(n, &gWeaponDB[0]);
  for (i = 0; i < ARRAY_COUNT(GAME->registeredWeapon[i]); i++) {
    if (GAME->registeredWeapon[i] == n) {
      GAME->registeredWeapon[i] = -1;
    }
  }
#else
  INCCODE("asm/wip/FUN_08242c08.inc");
#endif
}

NAKED void SwapWeaponSlot(slot32_t slot1, slot32_t slot2) {
  // TODO
  INCCODE("asm/todo/SwapWeaponSlot.inc");
}

NAKED void SortWeapons(slot32_t from) { INCCODE("asm/todo/SortWeapons.inc"); }

bool32 IsSpecialWeapon(weapon32_t w) {
  if ((u32)(w - 58) < 8) {
    return TRUE;
  }
  return FALSE;
}

NAKED bool32 FUN_08242d90(void) {
  // TODO
  INCCODE("asm/todo/FUN_08242d90.inc");
}

bool32 FUN_08242eb0(void) {
  s32 i, slot;
  weapon32_t w;

  if (prepare_08231510(102) != 0) {
    w = fetch_082316e4();
    if (prepare_08231510(116) == 0) {
      return FALSE;
    }

    slot = (s32)fetch_082316e4();
    for (i = 0; i < 16; i++) {
      if (GetWeaponID(i) == w) {
        FUN_08242b6c(i, &gWeaponDB[slot]);
        return TRUE;
      }
    }
  }
  return FALSE;
}

void FUN_08242f08(void) {
  FUN_08242c08(REGISTERED_WEAPON(GAME->equippedWeaponIdx));
  if (gPlayerPtr[0] != NULL) {
    weapon_08064664(gPlayerPtr[0], NULL);
    FUN_0809c464();
  }
}

NON_MATCH void FUN_08242f44(slot32_t n, s32 r1) {
#if MODERN
  s32 i;
  for (i = 0; i < 4; i++) {
    if (REGISTERED_WEAPON(i) == n) {
      REGISTERED_WEAPON(i) = -1;
    }
  }
  REGISTERED_WEAPON(r1) = n;
#else
  INCCODE("asm/wip/FUN_08242f44.inc");
#endif
}

void FUN_08242f84(s32 n) {
  REGISTERED_WEAPON(n) = -1;
  return;
}

bool32 FUN_08242f9c(void) {
  s32 len, i;
  weapon32_t w;

  if (prepare_08231510(119) != 0) {
    w = fetch_082316e4();
    if (prepare_08231510(100) != 0) {
      len = fetch_082316e4() ? 48 : 16;
    } else {
      len = 16;
    }
    for (i = 0; i < len; i++) {
      if (GetWeaponID(i) == w) {
        return TRUE;
      }
    }
  }

  return FALSE;
}

NAKED void FUN_08242fec(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #0x24\n\
	movs r4, #0\n\
	ldr r5, _08243050 @ =0x030046A0\n\
	movs r3, #0x92\n\
	lsls r3, r3, #4\n\
	movs r2, #0\n\
_08242FFA:\n\
	ldr r1, [r5]\n\
	lsls r0, r4, #2\n\
	adds r0, r0, r1\n\
	adds r0, r0, r3\n\
	str r2, [r0]\n\
	adds r4, #1\n\
	cmp r4, #1\n\
	ble _08242FFA\n\
	movs r4, #0\n\
_0824300C:\n\
	adds r0, r4, #0\n\
	ldr r1, _08243054 @ =gWeaponDB\n\
	bl FUN_08242b6c\n\
	adds r4, #1\n\
	cmp r4, #0x2f\n\
	ble _0824300C\n\
	movs r4, #0\n\
	ldr r5, _08243050 @ =0x030046A0\n\
	adds r3, r5, #0\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	adds r2, r0, #0\n\
_08243026:\n\
	ldr r1, [r3]\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r1\n\
	adds r0, #0x60\n\
	strh r2, [r0]\n\
	adds r4, #1\n\
	cmp r4, #3\n\
	ble _08243026\n\
	ldr r0, [r5]\n\
	adds r0, #0x58\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	movs r0, #0x6e\n\
	bl prepare_08231510\n\
	cmp r0, #0\n\
	beq _08243058\n\
	bl fetch_082316e4\n\
	adds r4, r0, #0\n\
	b _0824305A\n\
	.align 2, 0\n\
_08243050: .4byte 0x030046A0\n\
_08243054: .4byte gWeaponDB\n\
_08243058:\n\
	movs r4, #0\n\
_0824305A:\n\
	cmp r4, #0\n\
	ble _082430C4\n\
	movs r0, #0x77\n\
	bl prepare_08231510\n\
	cmp r0, #0\n\
	beq _082430A2\n\
	cmp r4, #0\n\
	ble _082430A2\n\
	ldr r6, _082430CC @ =gWeaponDB\n\
	mov r5, sp\n\
_08243070:\n\
	bl fetch_082316e4\n\
	lsls r1, r0, #3\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	mov r0, sp\n\
	adds r1, r1, r6\n\
	ldm r1!, {r2, r3, r7}\n\
	stm r0!, {r2, r3, r7}\n\
	ldm r1!, {r2, r3, r7}\n\
	stm r0!, {r2, r3, r7}\n\
	ldm r1!, {r2, r3, r7}\n\
	stm r0!, {r2, r3, r7}\n\
	ldrb r0, [r5]\n\
	bl IsSpecialWeapon\n\
	cmp r0, #0\n\
	bne _08243096\n\
	strb r0, [r5, #0x18]\n\
_08243096:\n\
	mov r0, sp\n\
	bl FUN_08242b88\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bne _08243070\n\
_082430A2:\n\
	movs r0, #0x71\n\
	bl prepare_08231510\n\
	cmp r0, #0\n\
	beq _082430C4\n\
	movs r4, #0\n\
	ldr r5, _082430D0 @ =0x030046A0\n\
_082430B0:\n\
	bl fetch_082316e4\n\
	ldr r2, [r5]\n\
	lsls r1, r4, #1\n\
	adds r1, r1, r2\n\
	adds r1, #0x60\n\
	strh r0, [r1]\n\
	adds r4, #1\n\
	cmp r4, #3\n\
	ble _082430B0\n\
_082430C4:\n\
	add sp, #0x24\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_082430CC: .4byte gWeaponDB\n\
_082430D0: .4byte 0x030046A0\n\
 .syntax divided\n");
}

bool32 FUN_082430d4(slot32_t n) {
  s32 i;
  for (i = 0; i < 4; i++) {
    if (REGISTERED_WEAPON(i) == n) {
      return TRUE;
    }
  }
  return FALSE;
}

s32 FUN_08243104(void) {
  slot32_t i;
  weapon32_t id;
  s32 retval;

  retval = 0;
  for (i = 0; i < 16; i++) {
    id = GetWeaponID(i);
    if ((gWeaponDB[id].unk_0a != 0) && (FUN_082430d4(i) == 0)) {
      retval++;
    }
  }
  return retval;
}

s32 FUN_08243140(void) {
  slot32_t i;
  weapon32_t id;
  s32 retval;

  retval = 0;
  for (i = 0; i < 16; i++) {
    id = GetWeaponID(i);
    if (((id == WEAPON_NONE) || (gWeaponDB[id].unk_0a != 0)) && (FUN_082430d4(i) == 0)) {
      retval++;
    }
  }
  return retval;
}

bool32 FUN_08243180(slot32_t n) {
  weapon32_t id;

  id = GetWeaponID(n);
  if (id == WEAPON_NONE) return FALSE;
  if (gWeaponDB[id].unk_0a == 0) return FALSE;
  if (FUN_082430d4(n)) return FALSE;
  return TRUE;
}
