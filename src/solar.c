
#include "entity.h"
#include "global.h"
#include "save.h"
#include "solar_sensor.h"
#include "time.h"

// 太陽センサーを毎フレーム読んで lx と太陽ゲージを作り、その結果を gStat に流し込むシングルトン
typedef struct SunlightEntity {
  Entity e;                                        // 0x00, ENTITY_UNK_5
  u8 unk_18;                                       // 0x18, FUN_08241f28 が 1 を書く。読み手は見つかっていない
  u8 state;                                        // 0x19, 0 -> 1 -> 2 と進む。FUN_08241cf4 / FUN_08241e40 が回し、IsSunlightActive / CalibrateSunSensor / SuspendSunlight / FUN_0824172c が見る
  u16 unk_1a;                                      // 0x1A, このモジュールは触らない
  s16 lx;                                          // 0x1C, 太陽光の強さ
  s16 sunGauge;                                    // 0x1E, lx を 10段階に分けたもの
  u16 stateTimer;                                  // 0x20, FUN_08241cf4 のフレーム数。state 0 で 29 を超えるとセンサーを有効化し、state 1 で 59 を超えると計測に入る。state が変わるたび 0
  u16 adjustTimer;                                 // 0x22, FUN_08241da8 が A+L / A+R を押している間 +1 し、1フレームおきに u16_03004868 を増減させる
  u16 tickCounter;                                 // 0x24, solar_08241ac0 が毎フレーム +1。(tickCounter & 0x3F) == 0 と (& 0x7F) == 0 で処理を間引く
  u16 idleTimer;                                   // 0x26, solar_08241ac0 が入力のたび 0 に戻し、無操作なら 900 まで数える。900 に達すると太陽の恵みが止まる
  u16 solarStandFrac;                              // 0x28, solar_08241ac0 が sunGauge/2 + 5 をここに貯め、>> 4 した繰り上がりを gStat->solarStand に足す
  u16 unk_2a;                                      // 0x2A, padding?
  void (*updateCallback)(struct SunlightEntity*);  // 0x2C
} SunlightEntity;
static_assert(sizeof(SunlightEntity) == 48);

IWRAM_DATA SunlightEntity* gSunlightEntity = NULL;  // 0x03001708
IWRAM_DATA u32 u32_0300170c = 0;                    // 0x0300170C, EEPROM_BeginAccess が u32_0300481c を退避し、EEPROM_EndAccess が戻す

COMMON_DATA u16 u16_03004864 = 0;
COMMON_DATA ALIGNED(4) u16 u16_03004868 = 0;
COMMON_DATA ALIGNED(4) u16 gSunlightSuspended = 0;
COMMON_DATA ALIGNED(4) u16 gSavedLx = 0;
COMMON_DATA ALIGNED(4) u16 gSavedSunGauge[6] = {};

const u8 u8_ARRAY_ARRAY_08dbd798[6][2] = {
    {2, 2},
    {2, 0},
    {0, 0},
    {0, 1},
    {1, 2},
    {2, 2},
};  // 0x08DBD798

const u16 gSunLevelMaxLx[11] = {0, 5, 12, 22, 34, 49, 66, 86, 109, 139, 140};  // 0x08DBD7A4

const u16 gSunLevelMinLx[11] = {0, 1, 6, 13, 23, 35, 50, 67, 87, 110, 140};  // 0x08DBD7BA

// 太陽光まわりを初期状態に戻す
NON_MATCH void ResetSunlight(void) {
#ifdef NONMATCHING_C
  gSunlightEntity = NULL;
  gStat->lx = 0;
  gStat->sunGauge = 0;
  gSavedLx = 0;
  gSavedSunGauge[0] = 0;
  gSunlightSuspended = 0;
#else
  INCFUNC("asm/func/ResetSunlight.inc");
#endif
}

// センサーの値が今そのまま使えるか。state 2 が計測中
bool32 IsSunlightActive(void) {
  if (gSunlightEntity != NULL && gSunlightSuspended == 0 && gSunlightEntity->state == 2) {
    return TRUE;
  }
  return FALSE;
}

void FUN_082416bc(void) { u16_03004864 = 1; }

void FUN_082416c8(void) { u16_03004864 = 0; }

// 今のセンサー値を暗所の基準として控える。以降 lx は calibration からの差で出る
NON_MATCH bool32 CalibrateSunSensor(void) {
#ifdef NONMATCHING_C
  s32 raw;

  if (gSunlightEntity->state == 2) {
    raw = Sensor_GetRawLevel();
    if (raw >= 0) {
      gSystemSaveData->calibration = raw - 2;
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/CalibrateSunSensor.inc");
#endif
}

// 太陽光の更新を止める。センサーも切る
void SuspendSunlight(void) {
  if (gSunlightEntity != NULL) {
    if (gSunlightEntity->state != 0) {
      Sensor_Disable();
    }
    gSunlightSuspended = 1;
  }
}

void FUN_0824172c(void) {
  if (gSunlightEntity != NULL) {
    if (gSunlightEntity->state != 0) {
      gSunlightEntity->state = 1;
      gSunlightEntity->stateTimer = 0;
      Sensor_Enable();
    }
    gSunlightSuspended = 0;
  }
}

s32 FUN_0824175c(void) { return gStat->sunGauge; }

// 照度(lx)を 0〜10 の太陽レベルに変換する
Sunlevel GetSunLevel(s32 lx) {
  if (lx == 0) return 0;
  if (lx <= 5) return 1;
  if (lx <= 12) return 2;
  if (lx <= 22) return 3;
  if (lx <= 34) return 4;
  if (lx <= 49) return 5;
  if (lx <= 66) return 6;
  if (lx <= 86) return 7;
  if (lx <= 109) return 8;
  if (lx < 140) return 9;
  return 10;
}

// その太陽レベルに収まる lx の上限
s32 GetSunLevelMaxLx(Sunlevel slv) { return gSunLevelMaxLx[slv]; }

// その太陽レベルに収まる lx の下限
s32 GetSunLevelMinLx(Sunlevel slv) { return gSunLevelMinLx[slv]; }

NAKED s32 FUN_082417ec(s32 lx) { INCFUNC("asm/func/FUN_082417ec.inc"); }

s32 FUN_082418c0(void) {
  s32 n = Sensor_GetRawLevel();
  if ((n < 0) || (n > gSystemSaveData->calibration)) {
    return 0;
  }

  n = gSystemSaveData->calibration - n;
  if (n >= 140) {
    return 140;
  }
  return n;
}

// 最後に炎天下にいた時間を記録する(これが記録されてから一定時間経てば、オーバーヒート状態が解除される)
void SetOverheatTime(void) {
  (gStat->overheatTime).date.val = GetDate();
  (gStat->overheatTime).hour = GetHour();
  (gStat->overheatTime).minute = GetMinute();
  (gStat->overheatTime).second = GetSecond();
}

bool32 IsGunCooled(void) {
  u32 y0, m0, d0, y1, m1, d1;
  s32 elapsed;
  u32 curH, curM, curS;

  if (GetDate() == gStat->overheatTime.date.val) {
    elapsed = 0;
  } else {
    ParseBCDDate(&y0, &m0, &d0, (BCDDate)GetDate());
    ParseBCDDate(&y1, &m1, &d1, gStat->overheatTime.date);
    if (FUN_0823d9ec(y0, m0, d0, y1, m1, d1) > 1) {
      return TRUE;
    }
    elapsed = 86400;  // 1日分の秒数
  }

  curH = GetHour();
  curM = GetMinute();
  curS = GetSecond();
  elapsed += (curH * 60 + curM) * 60 + curS - ((gStat->overheatTime.hour * 60 + gStat->overheatTime.minute) * 60 + gStat->overheatTime.second);

  if (elapsed >= 180) {  // 3分経ったらクールダウン
    return TRUE;
  }
  return FALSE;
}

NON_MATCH void UpdateOverheat(SunlightEntity* _ UNUSED) {
#ifdef NONMATCHING_C
  if (gStat->thermal > 29999) {
    if ((gStat->sunGauge < 3) || (gStat->unk_934 & 0x4200)) {
      if (gStat->heatstroke > 0) {
        gStat->heatstroke--;
      }
      if (IsGunCooled()) {
        gStat->thermal = 0;
        gStat->heatstroke = 0;
      }
    } else {
      SetOverheatTime();
      gStat->heatstroke += gStat->sunGauge;
      if (gStat->heatstroke > 5000) gStat->heatstroke = 5000;
    }
  }
#else
  INCFUNC("asm/func/UpdateOverheat.inc");
#endif
}

NAKED void solar_08241ac0(SunlightEntity* p) { INCFUNC("asm/func/solar_08241ac0.inc"); }

NAKED void FUN_08241cf4(SunlightEntity* p) { INCFUNC("asm/func/FUN_08241cf4.inc"); }

NAKED u32 FUN_08241da8(SunlightEntity* p) { INCFUNC("asm/func/FUN_08241da8.inc"); }

NAKED void FUN_08241e40(SunlightEntity* p) { INCFUNC("asm/func/FUN_08241e40.inc"); }

s32 SunlightEntity_Update(SunlightEntity* p) {
  if (gSunlightSuspended == 0) {
    p->updateCallback(p);
  }
  return 0;
}

s32 SunlightEntity_Destroy(SunlightEntity* _) {
  Sensor_Disable();
  gSunlightEntity = NULL;
  return 0;
}

NON_MATCH void FUN_08241f28(SunlightEntity* p) {
#ifdef NONMATCHING_C
  u16 tmp;
  p->unk_18 = 1;
  p->updateCallback = FUN_08241cf4;
  p->state = 0;
  p->stateTimer = 0;
  p->adjustTimer = 0;
  gStat->lx = gSavedLx;
  tmp = gSavedSunGauge[0];
  gStat->sunGauge = tmp;
#else
  INCFUNC("asm/func/FUN_08241f28.inc");
#endif
}

NAKED u32 ReflectClock(void) { INCFUNC("asm/func/ReflectClock.inc"); }

NAKED void clock_08241fd0(SunlightEntity* p) { INCFUNC("asm/func/clock_08241fd0.inc"); }

s32 SunlightEntity_Init(SunlightEntity* p) {
  FUN_08241f28(p);
  clock_08241fd0(p);
  gSunlightEntity = p;
  return 0;
}

SunlightEntity* SunlightEntity_Create(void) {
  if (gSunlightEntity == NULL) {
    SunlightEntity* p = CreateEntity(ENTITY_UNK_5, 48);
    if (p != NULL) {
      SetEntityRoutine(p, SunlightEntity_Update, SunlightEntity_Destroy);
      if (SunlightEntity_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gSunlightEntity;
}
