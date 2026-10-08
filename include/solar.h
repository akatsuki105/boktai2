#ifndef __INCLUDE_SOLAR_H__
#define __INCLUDE_SOLAR_H__

#include "gba/gba.h"
#include "types.h"

extern u16 gSunGaugeOverride;  // 0x03002B80, おてんきゲタやテルテルボーズ系は別
#define SUN_OVERRIDE_RISING 1  // ライジングサン発動中 (+4)
#define SUN_OVERRIDE_BLACK 2   // ブラックサン発動中 (強制的に 0)

s32 Taiyo_GetGameGauge(void);  // ライジングサンなどを考慮した太陽ゲージ
void Taiyo_Enable(void);
void Taiyo_Disable(void);

#endif  // __INCLUDE_SOLAR_H__
