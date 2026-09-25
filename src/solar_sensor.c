#include "solar_sensor.h"

#include "global.h"
#include "interrupts.h"

// 太陽センサーのドライバ

IWRAM_DATA s32 gSensorState = 0;             // 0x030026B4, Sensor_Tick の状態。0: リセット中, 1: 計測中, 2: 待機
IWRAM_DATA s32 gSensorCounter = 0;           // 0x030026B8, 0-511, counts half-cycles of the 74LV4040 counter chip
IWRAM_DATA s32 gSensorUnk0c = 0;             // 0x030026BC, 計測中のセンサー出力の最後の値。ROM 内に読む箇所なし
IWRAM_DATA s32 gSensorNextWrite = 0;         // 0x030026C0, next value to be written to GPIO_DATA
IWRAM_DATA bool32 gSensorIoEnabled = FALSE;  // 0x030026C4
COMMON_DATA u32 gSensorDrvUnk00 = 0;         // 0x030057B0, Sensor_DoEnableIO が 0xFF を書くだけで読む箇所なし
COMMON_DATA u32 gSensorDrvUnk04 = 0;         // 0x030057B4, 有効化時の GPIO_PORT_DATA の控え。読む箇所なし
COMMON_DATA bool32 gSensorEnabled = FALSE;   // 0x030057B8
COMMON_DATA u32 gSensorGpioData = 0;         // 0x030057BC, last read GPIO data (GPIO_DATA & 8)
COMMON_DATA s32 gSensorDrvUnk10 = 0;         // 0x030057C0, Sensor_DoEnableIO が 1 を書くだけで読む箇所なし
COMMON_DATA s32 gSensorDrvUnk14 = 0;         // 0x030057C4, Sensor_DoEnableIO が 4 を書くだけで読む箇所なし
COMMON_DATA s32 gSensorRawLevel = 0;         // 0x030057C8, light level (0: Max brightness, 0xFF: Dark)
COMMON_DATA s32 gSensorTickPeriod = 0;       // 0x030057CC, Sensor_Tick の周期。タイマー3 に -gSensorTickPeriod を再装填する

void Sensor_Tick(void);

// GPIO をセンサー読み出し用に開き、タイマー3 の割り込みで Sensor_Tick を回し始める
void Sensor_DoEnableIO(void) {
  u16 ie;

  gSensorNextWrite = (gSensorNextWrite & ~2) | 1;
  gSensorState = 0;
  gSensorCounter = 0;
  gSensorEnabled = FALSE;
  gSensorTickPeriod = 0x3128;
  gSensorDrvUnk10 = 1;
  gSensorDrvUnk00 = 0xFF;
  gSensorDrvUnk14 = 4;
  gSensorRawLevel = -1;
  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  REG_TM3CNT_L = 0;
  REG_TM3CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE;
  gIntrTable[2] = Sensor_Tick;
  gSensorDrvUnk04 = GPIO_PORT_DATA;
  GPIO_PORT_DIRECTION = 7;
  GPIO_PORT_READ_ENABLE = 1;
  ie |= INTR_FLAG_TIMER3;
  REG_IE = ie;
  REG_IME = 1;
}

// センサー用のタイマー3割り込みを止め、GPIO の読み出しを無効に戻す
void Sensor_DoDisableIO(void) {
  u16 ie;

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  REG_TM3CNT_H = 0;
  REG_TM3CNT_L = 0;
  gIntrTable[2] = IntrDummy;
  GPIO_PORT_READ_ENABLE = 0;
  ie &= ~INTR_FLAG_TIMER3;
  REG_IE = ie;
  REG_IME = 1;
}

// タイマー3 割り込み。GPIO を1段進めて、リセット -> 計測 -> 待機 を回しながら明るさを読む
void Sensor_Tick(void) {
  u32 data = GPIO_PORT_DATA;
  u32 gpio;

  GPIO_PORT_DATA = gSensorNextWrite;
  REG_TM3CNT_L = -gSensorTickPeriod;
  gpio = data & 8;
  gSensorGpioData = gpio;
  if (gSensorEnabled) {
    switch (gSensorState) {
      case 0: {
        if (gSensorCounter <= 9) {
          gSensorNextWrite |= 2;
        } else {
          gSensorNextWrite &= ~2;
        }
        if (gSensorCounter > 20 && gpio == 0) {
          gSensorState++;
          gSensorCounter = 0;
          gSensorUnk0c = 0;
        }
        break;
      }
      case 1: {
        if (gpio != 0) {
          gSensorRawLevel = gSensorCounter >> 1;
          gSensorState = 2;
        }
        gSensorUnk0c = gpio;
      }
      case 2: {
        gSensorNextWrite ^= 1;
        if (gSensorCounter > 511) {
          gSensorState = 0;
          gSensorCounter = 0;
        }
        break;
      }
    }
    gSensorCounter++;
  }
}

void Sensor_EnableIO(void) {
  gSensorDrvUnk04 = 0;
  gSensorIoEnabled = TRUE;
  Sensor_DoEnableIO();
}

void Sensor_DisableIO(void) {
  if (gSensorIoEnabled) {
    gSensorIoEnabled = FALSE;
    Sensor_DoDisableIO();
  }
}

void Sensor_Enable(void) {
  if (!gSensorIoEnabled) Sensor_EnableIO();
  gSensorEnabled = TRUE;
  gSensorState = 0;
  gSensorCounter = 0;
  gSensorRawLevel = -1;
}

void Sensor_Disable(void) {
  if (gSensorIoEnabled == TRUE) Sensor_DisableIO();
  gSensorEnabled = FALSE;
  gSensorRawLevel = -1;
}

s32 Sensor_GetRawLevel(void) {
  if (!gSensorEnabled) return -1;
  return gSensorRawLevel;
}

bool32 Sensor_IsIoEnabled(void) { return gSensorIoEnabled; }

s32 Sensor_GetState(void) { return gSensorState; }

s32 Sensor_GetCounter(void) { return gSensorCounter; }
