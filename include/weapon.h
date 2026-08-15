#ifndef GUARD_ZOKTAI_WEAPON_H
#define GUARD_ZOKTAI_WEAPON_H

#include "gba/gba.h"
#include "types.h"

#define WEAPONS(slot) (gStat->weapons + slot)

struct Player;

enum WeaponKind {
  WK_SWORD,   // 剣(ソード)
  WK_SPEAR,   // 槍(スピア)
  WK_HAMMER,  // 槌(ハンマー)
  WK_OTHERS,
  WK_GUN,  // 銃(ガン)
};

// ソース: bokpass.tcl, https://web.archive.org/web/20250420030710/https://notabug.org/UvHCxXJp/bokpass/src/master/bokpass.tcl
enum WeaponStyle {
  STYLE_SWORD,
  STYLE_SPEAR,
  STYLE_HAMMER,
  STYLE_GUN,
  STYLE_FIST,
  STYLE_NONE,
};

typedef struct {
  u8 id;           // 0x00, see include/constants/weapon.h
  u8 quality;      // 0x01
  u16 durability;  // 0x02
  u8 unk_04[24];   // 0x04, 現時点では用途不明
} Weapon;
static_assert(sizeof(Weapon) == 28);

// ROM内での静的な武器データの構造体
typedef struct {
  u8 id;    // 0x00, see include/constants/weapon.h
  u8 kind;  // 0x01, see enum WeaponKind
  u8 unk_02;
  u8 lv;
  u32 unk_04;
  u16 unk_08;
  u16 unk_0a;
  u32 unk_0c[6];
} WeaponData;
static_assert(sizeof(WeaponData) == 36);

extern const WeaponData gWeaponDB[66];

Weapon* GetWeapon(s32 slot);
weapon32_t GetWeaponID(s32 slot);
void SetWeaponFoundFlag(weapon32_t n);
void FUN_08064658(struct Player* p, Weapon* w);
void weapon_08064664(struct Player* p, Weapon* w);

#endif  // GUARD_ZOKTAI_WEAPON_H
