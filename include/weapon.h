#ifndef GUARD_ZOKTAI_WEAPON_H
#define GUARD_ZOKTAI_WEAPON_H

#include "gba/gba.h"
#include "types.h"

#define WEAPONS(slot) (gStat->weapons + slot)

struct Player;

#define WEAPON_EFFECT_SLOT_COUNT 3  // 武器には3つまで特殊効果を付与できる

typedef u32 WeaponEffect;  // bit0-7: 特殊効果ID(see include/constants/weapon.h), bit8-31: 効果量

// WeaponData から ID+動的に変動しうるデータ を抜粋したもの, セーブ用にサイズを切り詰めたかった？
typedef struct {
  u8 id;                                           // 0x00, see include/constants/weapon.h
  u8 quality;                                      // 0x01
  u16 wear;                                        // 0x02, 武器の損傷度合い(新品は 0), 敵に攻撃を当てたりすると増えていき、 WeaponData.durability を超えると武器が壊れる, FUN_0813e944
  char PS[12];                                     // 0x04, 武器の説明欄に対する追記, e.g. "ジャンゴ作"
  WeaponEffect effects[WEAPON_EFFECT_SLOT_COUNT];  // 0x10, 武器に付与された特殊効果, see include/constants/weapon.h
} Weapon;
static_assert(sizeof(Weapon) == 28);

typedef struct {
  u8 id;                                           // 0x00, see "include/constants/weapon.h"
  u8 kind;                                         // 0x01, see WeaponKind in "include/constants/weapon.h"
  u8 rank;                                         // 0x02, 武器のランク, [C, B, A, S, R]
  u8 lv;                                           // 0x03
  u16 durability;                                  // 0x04, 武器の耐久値, これが大きいほど壊れにくい
  u16 wear;                                        // 0x06, これが .durability を超えると武器が壊れる
  u16 quality;                                     // 0x08
  u16 price;                                       // 0x0A, FUN_08243104
  char PS[12];                                     // 0x0C, 武器の説明欄に対する追記, e.g. "ジャンゴ作"
  WeaponEffect effects[WEAPON_EFFECT_SLOT_COUNT];  // 0x18, Weapon.effects に コピーされる
} WeaponData;
static_assert(sizeof(WeaponData) == 36);

extern const WeaponData gWeaponDB[66];

Weapon* GetWeapon(s32 slot);
weapon32_t GetWeaponID(s32 slot);
void SetWeaponFoundFlag(weapon32_t n);
void FUN_08064658(struct Player* p, Weapon* w);
void weapon_08064664(struct Player* p, Weapon* w);

#endif  // GUARD_ZOKTAI_WEAPON_H
