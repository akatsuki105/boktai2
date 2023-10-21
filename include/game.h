#ifndef GUARD_ZOKTAI_GAME_H
#define GUARD_ZOKTAI_GAME_H

#include "global.h"
#include "time.h"
#include "weapon.h"

#define GAME ((*(&gGamePointer.s)))
#define REGISTERED_WEAPON(n) (*(GAME->registeredWeapon + n))
#define REGISTERED_MAGIC(n) (*(GAME->registeredMagic + n))

struct GameInfo {
  u32 unk_000;
  u8 unk_004[14];
  u16 unk_012;
  u8 unk_14[4];
  u16 vitality;
  u16 spirit;
  u16 strength;
  u16 agility;
  u8 unk_020[8];
  u16 savedHP;  // コンティニュー用？
  u16 savedMaxHP;
  u16 savedEne;
  u16 savedMaxEne;
  u16 unk_030[3];
  u8 unk_036[2];
  u16 sabataHP;
  u16 sabataEne;
  u8 unk_03c[4];
  u16 lv;
  u16 statusPoint;
  u16 unk_44;
  u16 swordExp;
  u16 spearExp;
  u16 hammerExp;
  u16 fistExp;
  u16 gunExp;
  u32 exp;
  u32 unlockedMagic;
  s16 equippedWeaponIdx;
  s16 equippedMagicIdx;  // 登録された4つの魔法のうち、フィールドで選択している魔法のインデックス(0~3)
  slot16_t armor;
  u8 unk_5e[2];
  slot16_t registeredWeapon[4];
  magic16_t registeredMagic[4];
  item_t items[16 + 16 + 16];
  s16 rotTimer[16 + 16 + 16];  // if MSB is set, item is chocolate-covered
  item_t valuables[16];
  armor_t armors[16];
  u8 unk_170[40];
  union Date date;
  u32 hour;
  u32 minute;
  bool32 isClockTowerBellDone;  // すでに夕方か(時計塔の鐘の音がなったか)
  struct Datetime overheatTime;
  s16 unk_1b8;
  u16 unk_1ba;
  s32 thermal;  // 30000に到達したらオーバーヒート
  u8 unk_1c0[4];
  u32 darkDebts;  // 実際に返す必要のある額
  u8 unk_1c8[16];
  u32 treeExp;
  u8 unk_1dc[20];
  s16 totalEnemyKillCount;
  s16 enemyKillCount[24];
  u16 unk_222;
  u8 unk_224[40];
  u32 unk_24c;
  s16 unk_250;
  coffin_t coffin;
  s16 unk_254;
  u8 unk_256[10];
  u32 unlockedMap;
  u8 unk_264[68];
  u32 darkDjangoAtkCounter;
  u32 unk_2ac;
  s16 unk_2b0[2];
  u32 playTime;
  u8 unk_2b8[232];
  u32 armorDex[2];
  u8 unk_3a8[20];
  u32 solarStand;
  u8 unk_3c0[16];
  struct Weapon weapons[16 + 16 + 16];
  u16 solarBank;
  u8 unk_912[14];
  u32 weaponDex[2];
  u8 unk_928[12];
  u16 unk_934;
  u8 unk_936[10];
  u16 unk_940;
  s16 unk_942;
  u8 unk_944[444];
};
static_assert(sizeof(struct GameInfo) == 2816);

struct GamePointer {
  void* unk_00;
  void* unk_04;
  void* unk_08;
  void* unk_0c;
  struct GameInfo* s;
};

// --------------------------------------------

extern struct GamePointer gGamePointer;

#endif  // GUARD_ZOKTAI_GAME_H
