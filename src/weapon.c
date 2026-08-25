#include "weapon.h"

#include "global.h"
#include "vm.h"

void FUN_0809c28c(void);

bool32 IsWeaponAlreadyFound(weapon32_t n) {
  if (n >= 32) {
    return (gStat->weaponDex[1]) & (1 << (n - 32));
  } else {
    return (gStat->weaponDex[0]) & (1 << n);
  }
}

void SetWeaponFoundFlag(weapon32_t n) {
  if (n >= 32) {
    (gStat->weaponDex[1]) |= (1 << (n - 32));
  } else {
    (gStat->weaponDex[0]) |= (1 << n);
  }
}

// 0x082429d8
Weapon* GetWeapon(s32 slot) { return WEAPONS(slot); }

weapon32_t GetWeaponID(s32 slot) { return GetWeapon(slot)->id; }

u32 GetWeaponKind(s32 slot) { return gWeaponDB[GetWeapon(slot)->id].kind; }

s8 GetWeaponQuality(s32 slot) { return GetWeapon(slot)->quality; }

u32 GetWeaponDurability(s32 slot) { return GetWeapon(slot)->durability; }

NAKED void FUN_08242a38(WeaponTemplate* tmpl, Weapon* w) { INCFUNC("asm/func/FUN_08242a38.inc"); }

NAKED void FUN_08242a98(Weapon* w, WeaponTemplate* data) { INCFUNC("asm/func/FUN_08242a98.inc"); }

void FUN_08242b14(slot32_t n, WeaponTemplate* data) {
  FUN_08242a98(GetWeapon(n), data);
  return;
}

void FUN_08242b28(s32 idx, WeaponTemplate* data) {
  if (REGISTERED_WEAPON(idx) < 0) {
    *data = gWeaponDB[0];
  } else {
    FUN_08242b14(REGISTERED_WEAPON(idx), data);
  }
}

void FUN_08242b6c(slot32_t n, const WeaponTemplate* data) {
  Weapon* w = GetWeapon(n);
  FUN_08242a38((WeaponTemplate*)data, w);
  SetWeaponFoundFlag(data->id);
}

NON_MATCH bool32 FUN_08242b88(WeaponTemplate* data) {
#ifdef NONMATCHING_C
  Player* p;
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
      gStat->equippedWeaponIdx = 0;
      if (gPlayerPtr[0] != NULL) {
        Weapon* w = GetWeapon(slot);
        weapon_08064664(gPlayerPtr[0], w);
      }
    }
    FUN_0809c28c();
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_08242b88.inc");
#endif
}

NON_MATCH void FUN_08242c08(slot32_t n) {
#ifdef NONMATCHING_C
  s32 i;
  FUN_08242b6c(n, &gWeaponDB[0]);
  for (i = 0; i <= 3; i++) {
    if (REGISTERED_WEAPON(i) == n) {
      REGISTERED_WEAPON(i) = -1;
    }
  }
#else
  INCFUNC("asm/func/FUN_08242c08.inc");
#endif
}

void SwapWeaponSlot(slot32_t slot1, slot32_t slot2) {
  Weapon tmp;
  Weapon *w1, *w2;
  s32 i;

  w1 = GetWeapon(slot1);
  w2 = GetWeapon(slot2);

  tmp = *w1;
  *w1 = *w2;
  *w2 = tmp;

  for (i = 0; i <= 3; i++) {
    if (REGISTERED_WEAPON(i) == slot1) {
      REGISTERED_WEAPON(i) = slot2;
      FUN_08064658(gPlayerPtr[0], w2);
    } else if (REGISTERED_WEAPON(i) == slot2) {
      REGISTERED_WEAPON(i) = slot1;
      FUN_08064658(gPlayerPtr[0], w1);
    }
  }
}

NAKED void SortWeapons(slot32_t from) { INCFUNC("asm/func/SortWeapons.inc"); }

bool32 IsSpecialWeapon(weapon32_t w) {
  if ((u32)(w - 58) < 8) {
    return TRUE;
  }
  return FALSE;
}

NAKED bool32 FUN_08242d90(void) { INCFUNC("asm/func/FUN_08242d90.inc"); }

bool32 FUN_08242eb0(void) {
  s32 i, slot;
  weapon32_t w;

  if (prepare_08231510(102) != 0) {
    w = Script_GetValue();
    if (prepare_08231510(116) == 0) {
      return FALSE;
    }

    slot = (s32)Script_GetValue();
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
  FUN_08242c08(REGISTERED_WEAPON(gStat->equippedWeaponIdx));
  if (gPlayerPtr[0] != NULL) {
    weapon_08064664(gPlayerPtr[0], NULL);
    FUN_0809c464();
  }
}

NON_MATCH void FUN_08242f44(slot32_t n, s32 r1) {
#ifdef NONMATCHING_C
  s32 i;
  for (i = 0; i < 4; i++) {
    if (REGISTERED_WEAPON(i) == n) {
      REGISTERED_WEAPON(i) = -1;
    }
  }
  REGISTERED_WEAPON(r1) = n;
#else
  INCFUNC("asm/func/FUN_08242f44.inc");
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
    w = Script_GetValue();
    if (prepare_08231510(100) != 0) {
      len = Script_GetValue() ? 48 : 16;
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

NAKED void FUN_08242fec(void) { INCFUNC("asm/func/FUN_08242fec.inc"); }

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
