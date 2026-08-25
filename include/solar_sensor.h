#ifndef __INCLUDE_SOLAR_SENSOR_H__
#define __INCLUDE_SOLAR_SENSOR_H__

#include "entity.h"
#include "gba/gba.h"
#include "types.h"

struct Player4c4;

typedef struct SolarSensorEntity {
  Entity e;                  // 0x00
  u32 unk_18;                // 0x18
  void* anim;                // 0x1C
  struct Player4c4* unk_20;  // 0x20
} SolarSensorEntity;
static_assert(sizeof(SolarSensorEntity) == 36);  // 0x082473e0 で 36バイトで作っている

// SolarSensorManager との違いはまだ不明 (結構アドレスが離れてる)
// Entityを持っているのでゲームが太陽センサーとやり取りするための(高レベルな)インターフェースの可能性が高い
// ただ、 agbrtc と IWRAM が隣接していて、 agbrtc が 0x030026c8 から始まる、つまり16バイトアラインされていないので、 GBA SDKのライブラリ由来の可能性もある (わからん)
typedef struct {
  SolarSensorEntity* e;  // 0x00
  s32 state;             // 0x04, 0: measuring, 1: resetting, 2: idle
  s32 counter;           // 0x08, 0-511, counts half-cycles of the 74LV4040 counter chip
  s32 unk_0c;            // 0x0C
  s32 nextWrite;         // 0x10, next value to be written to GPIO_DATA
  bool32 unk_14;         // 0x14
} SolarSensorInterface;
static_assert(sizeof(SolarSensorInterface) == 24);

// SolarSensorInterface が高レベルなインターフェースだったなら、こっちは低レベルなインターフェース(ドライバ)だと思われる
typedef struct {
  u32 unk_00;        // 0x00
  u32 unk_04;        // 0x04
  bool32 isEnabled;  // 0x08
  u32 gpiodata;      // 0x0C, last read GPIO data (GPIO_DATA & 8)
  s32 unk_10;        // 0x10
  s32 unk_14;        // 0x14
  s32 rawLevel;      // 0x18, light level (0: Max brightness, 0xFF: Dark)
  s32 unk_1c;        // 0x1C, おそらく Sensor_Tick の周期
} SolarSensorManager;
static_assert(sizeof(SolarSensorManager) == 32);

extern SolarSensorManager gSolarSensorManager;  // 0x030057B0

// --------------------------------------------

void Sensor_Disable(void);
s32 Sensor_GetRawLevel(void);

#endif  // __INCLUDE_SOLAR_SENSOR_H__
