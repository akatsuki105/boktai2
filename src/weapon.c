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

void FUN_08242b6c(slot32_t n, struct WeaponData* data) {
  struct Weapon* w = GetWeapon(n);
  FUN_08242a38(data, w);
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
  FUN_08242b6c(n, (struct WeaponData*)&gWeaponDB[0]);
  for (i = 0; i < ARRAY_COUNT(GAME->registeredWeapon[i]); i++) {
    if (GAME->registeredWeapon[i] == n) {
      GAME->registeredWeapon[i] = -1;
    }
  }
#else
  INCCODE("asm/wip/FUN_08242c08.inc");
#endif
}

NAKED void SwapWeaponSlot(slot32_t slot1, slot32_t slot2) { INCCODE("asm/todo/SwapWeaponSlot.inc"); }

NAKED void SortWeapons(slot32_t from) { INCCODE("asm/todo/SortWeapons.inc"); }

bool32 IsSpecialWeapon(weapon32_t w) {
  if ((u32)(w - 58) < 8) {
    return TRUE;
  }
  return FALSE;
}
