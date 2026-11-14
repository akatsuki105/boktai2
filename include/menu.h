#ifndef __INCLUDE_MENU_H__
#define __INCLUDE_MENU_H__

#include "gba/gba.h"
#include "types.h"
#include "weapon.h"

// MainMenu.hudMode, HUD_SetMode で切り替える
typedef enum {
  HUD_FIELD = 0,        // 通常の HUD, 上部には雑魚敵の HP ゲージを出す
  HUD_BOSS_BATTLE = 1,  // 通常の HUD に加え, 上部にボス戦のボスの HP ゲージを出す (残りは緑, 減った分は赤)
  HUD_PILE_DRIVER = 2,  // 通常の HUD に加え, 上部に棺桶に封印したボスをパイルドライバーで浄化するゲージを出す (残りは赤, 減った分は灰色)
  HUD_WINDOW_1 = 3,     // 3〜6 は HUD を隠して BG0 を menuTilemap の層 (mode - 2) にする, 3 は選択肢・ゲームオーバー・セーブ
  HUD_WINDOW_2 = 4,
  HUD_WINDOW_3 = 5,  // 通信対戦 (LinkSession)
  HUD_WINDOW_4 = 6,
  HUD_HIDDEN = 7,  // 全部隠す
} HUDMode;

void HUD_SetMode(s32 mode);
void HUD_ShowWeaponCrashEffect(void);
void HUD_StartCountdown(u16* remainingTime);
void HUD_RemoveCountdown(void);
void QC_Rebuild(void);
s32 GetCurrentMapNameLine(void);
s32 GetWeaponWearPose(WeaponData* w);
void HUD_OpenCrossoverInterval(void);
void HUD_CloseCrossoverInterval(void);
void QC_RebuildWeapons(void);
void QC_RebuildMagic(void);
void HUD_ShowCoffinGauge(s32 hp, s32 maxHP, s32 flash);
u32 Item_GetRotStageIcon(s32 slot);
void WeaponData_ShowNameInWindow(u8* weapon, s8* suffix);

#endif  // __INCLUDE_MENU_H__
