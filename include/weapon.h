#ifndef GUARD_ZOKTAI_WEAPON_H
#define GUARD_ZOKTAI_WEAPON_H

#include "gba/gba.h"
#include "types.h"

#define WEAPONS(slot) (GAME->weapons + slot)

struct Player;

enum WeaponKind {
  WK_SWORD,
  WK_SPEAR,
  WK_HAMMER,
  WK_OTHERS,
  WK_GUN,
};

struct Weapon {
  u8 id;
  u8 quality;
  u16 durability;
  u8 unk_04[24];
};

struct WeaponData {
  u8 id;
  u8 kind;
  u8 unk_02;
  u8 lv;
  u32 unk_04;
  u16 unk_08;
  u16 unk_0a;
  u32 unk_0c[6];
};
static_assert(sizeof(struct WeaponData) == 36);

extern const struct WeaponData gWeaponDB[66];

struct Weapon *GetWeapon(s32 slot);
weapon32_t GetWeaponID(s32 slot);
void SetWeaponFoundFlag(weapon32_t n);
void weapon_08064664(struct Player *p, struct Weapon *w);

#endif  // GUARD_ZOKTAI_WEAPON_H
