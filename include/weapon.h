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

#define WEAPON_EFFECT_SLOT_COUNT 3  // 武器には3つまで特殊効果を付与できる

typedef u32 WeaponEffect;  // bit0-7: 特殊効果ID(see include/constants/weapon.h), bit8-31: 効果量

typedef struct {
  u8 id;                                           // 0x00, see include/constants/weapon.h
  u8 quality;                                      // 0x01
  u16 durability;                                  // 0x02
  char PS[12];                                     // 0x04, 武器の説明欄に対する追記, e.g. "ジャンゴ作"
  WeaponEffect effects[WEAPON_EFFECT_SLOT_COUNT];  // 0x10, 武器に付与された特殊効果, see include/constants/weapon.h
} Weapon;
static_assert(sizeof(Weapon) == 28);

// 武器のテンプレートデータだが、書き込みをしてるときもある, あとで WeaponTemplateV2 で置き換える
typedef struct {
  u8 id;      // 0x00, see include/constants/weapon.h
  u8 kind;    // 0x01, see enum WeaponKind
  u8 unk_02;  // 0x02
  u8 lv;      // 0x03
  u32 unk_04;
  u16 unk_08;  // 0x08
  u16 unk_0a;  // 0x0A, FUN_08243104
  WeaponEffect unk_0c[6];
} WeaponTemplate;
static_assert(sizeof(WeaponTemplate) == 36);

typedef struct {
  u8 id;                                           // 0x00, see include/constants/weapon.h
  u8 kind;                                         // 0x01, see enum WeaponKind
  u8 unk_02;                                       // 0x02
  u8 lv;                                           // 0x03
  u16 unk_04;                                      // 0x04
  u16 durability;                                  // 0x06
  u16 quality;                                     // 0x08
  u16 unk_0a;                                      // 0x0A, FUN_08243104
  char PS[12];                                     // 0x0C, 武器の説明欄に対する追記, e.g. "ジャンゴ作"
  WeaponEffect effects[WEAPON_EFFECT_SLOT_COUNT];  // 0x18, Weapon.effects に コピーされる
} WeaponTemplateV2;
static_assert(sizeof(WeaponTemplateV2) == 36);

extern const WeaponTemplate gWeaponDB[66];

Weapon* GetWeapon(s32 slot);
weapon32_t GetWeaponID(s32 slot);
void SetWeaponFoundFlag(weapon32_t n);
void FUN_08064658(struct Player* p, Weapon* w);
void weapon_08064664(struct Player* p, Weapon* w);

#endif  // GUARD_ZOKTAI_WEAPON_H
