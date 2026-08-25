#include "global.h"
#include "struct.h"

// 現在の経験値を確認して、レベルアップする場合はレベルアップ処理を行う。
// またその際のパーティクルやSEなどの演出処理も行う。
typedef struct LevelUpper {
  Entity e;    // ENTITY_UNK_9
  u32 unk_18;  // 0x18, なんかのフラグっぽい
  u8 unk_1c[0x68 - 0x1C];
  s16 weaponLv[5];  // 0x68, 武器レベル, = GameInfo.weaponExp[n]/100
  u8 unk_72[2];
  u32 nextExp;            // 0x74, 次にレベルアップする総経験値量
  u32* expTable;          // 0x78, 経験値テーブルの先頭アドレス, 常に 0x08D09FE8
  void* p_7c;             // 0x7C, なんかのアドレス, 根拠: 0x080a83c4
  UnkStruct60 unk_80[8];  // 0x80, 多分グラフィック周りのデータ
} LevelUpper;
static_assert(sizeof(LevelUpper) == 608);

extern LevelUpper* gLevelUpper;  // 0x03000154

// 次のレベルになるために必要な"総"経験値量を返す
u32 GetNextLvExp(LevelUpper* p, s32 lv) {
  // = return p->expTable[lv] * 10;
  u32* exp = p->expTable;
  exp += lv;
  return 10 * (*exp);
}

NAKED bool32 TryPlayerLevelUp(LevelUpper* p) { INCFUNC("asm/func/TryPlayerLevelUp.inc"); }

NAKED bool32 IsWeaponLevelChanged(LevelUpper* p) { INCFUNC("asm/func/IsWeaponLevelChanged.inc"); }

NAKED void FUN_080a8250(UnkStruct60* p) { INCFUNC("asm/func/FUN_080a8250.inc"); }

NAKED void FUN_080a8314(UnkStruct60* p, UNK_PTR param_2) { INCFUNC("asm/func/FUN_080a8314.inc"); }

NAKED void FUN_080a8384(LevelUpper* p) { INCFUNC("asm/func/FUN_080a8384.inc"); }

NAKED void FUN_080a83dc(LevelUpper* p) { INCFUNC("asm/func/FUN_080a83dc.inc"); }

NAKED void FUN_080a841c(LevelUpper* p) { INCFUNC("asm/func/FUN_080a841c.inc"); }

NAKED s32 LevelUpper_Update(LevelUpper* p) { INCFUNC("asm/func/LevelUpper_Update.inc"); }

NAKED s32 LevelUpper_Destroy(LevelUpper* p) { INCFUNC("asm/func/LevelUpper_Destroy.inc"); }

NAKED void LevelUpper_Init_Helper_080a86cc(LevelUpper* p) { INCFUNC("asm/func/LevelUpper_Init_Helper_080a86cc.inc"); }

NAKED void LevelUpper_Init_Helper_080a8704(LevelUpper* p) { INCFUNC("asm/func/LevelUpper_Init_Helper_080a8704.inc"); }

NAKED s32 LevelUpper_Init(LevelUpper* p) { INCFUNC("asm/func/LevelUpper_Init.inc"); }

NAKED LevelUpper* LevelUpper_Create(void) { INCFUNC("asm/func/LevelUpper_Create.inc"); }
