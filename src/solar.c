
#include "entity.h"
#include "entity_9a9f.h"
#include "global.h"
#include "input.h"
#include "player.h"
#include "save.h"
#include "solar_sensor.h"
#include "time.h"

// 太陽センサーを毎フレーム読んで lx と太陽ゲージを作り、その結果を gStat に流し込むシングルトン
typedef struct SunlightEntity {
  Entity e;                                        // 0x00, ENTITY_UNK_5
  u8 unk_18;                                       // 0x18, FUN_08241f28 が 1 を書く。読み手は見つかっていない
  u8 state;                                        // 0x19, 0 -> 1 -> 2 と進む。UpdateSunlight / UpdateSunlightDebug が回し、IsSunlightActive / CalibrateSunSensor / SuspendSunlight / FUN_0824172c が見る
  u16 unk_1a;                                      // 0x1A, このモジュールは触らない
  s16 lx;                                          // 0x1C, 太陽光の強さ
  s16 sunGauge;                                    // 0x1E, lx を 10段階に分けたもの
  u16 stateTimer;                                  // 0x20, UpdateSunlight のフレーム数。state 0 で 29 を超えるとセンサーを有効化し、state 1 で 59 を超えると計測に入る。state が変わるたび 0
  u16 adjustTimer;                                 // 0x22, UpdateDebugLx が A+L / A+R を押している間 +1 し、1フレームおきに gDebugLx を増減させる
  u16 tickCounter;                                 // 0x24, ApplySunlightGain が毎フレーム +1。(tickCounter & 0x3F) == 0 と (& 0x7F) == 0 で処理を間引く
  u16 idleTimer;                                   // 0x26, ApplySunlightGain が入力のたび 0 に戻し、無操作なら 900 まで数える。900 に達すると太陽の恵みが止まる
  u16 solarStandFrac;                              // 0x28, ApplySunlightGain が sunGauge/2 + 5 をここに貯め、>> 4 した繰り上がりを gStat->solarStand に足す
  u16 unk_2a;                                      // 0x2A, padding?
  void (*updateCallback)(struct SunlightEntity*);  // 0x2C
} SunlightEntity;
static_assert(sizeof(SunlightEntity) == 48);

IWRAM_DATA SunlightEntity* gSunlightEntity = NULL;  // 0x03001708
extern u16 u16_03002b80;                            // 0x03002B80, FUN_0807e854 が 0 に戻す。1 で太陽レベル +4、2 で日光なし

IWRAM_DATA u32 u32_0300170c = 0;  // 0x0300170C, EEPROM_BeginAccess が u32_0300481c を退避し、EEPROM_EndAccess が戻す

COMMON_DATA u16 u16_03004864 = 0;
COMMON_DATA ALIGNED(4) u16 gDebugLx = 0;                   // 0x03004868
COMMON_DATA ALIGNED(4) bool16 gSunlightSuspended = FALSE;  // 0x0300486C
COMMON_DATA ALIGNED(4) u16 gSavedLx = 0;                   // 0x03004870
COMMON_DATA ALIGNED(4) u16 gSavedSunGauge[6] = {};         // 0x03004874

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
  gSunlightSuspended = FALSE;
#else
  INCFUNC("asm/func/ResetSunlight.inc");
#endif
}

// センサーの値が今そのまま使えるか。state 2 が計測中
bool32 IsSunlightActive(void) {
  if (gSunlightEntity != NULL && !gSunlightSuspended && gSunlightEntity->state == 2) {
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
    gSunlightSuspended = TRUE;
  }
}

void FUN_0824172c(void) {
  if (gSunlightEntity != NULL) {
    if (gSunlightEntity->state != 0) {
      gSunlightEntity->state = 1;
      gSunlightEntity->stateTimer = 0;
      Sensor_Enable();
    }
    gSunlightSuspended = FALSE;
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

// 生の lx に環境要因を掛ける。ライジングサン、天候、屋内判定でここが最終的な明るさを決める
NON_MATCH s32 ApplyLxModifiers(s32 lx) {
#ifdef NONMATCHING_C
  if ((gFlag030047a4 & FLAG030047A4_UNK_11) == 0) {
    s32 slv;

    if (gPlayerPtr[0] != NULL && (gPlayerPtr[0]->flag378 & FLAG378_AET_SUNLIGHT)) {
      slv = GetSunLevel(lx) * 2;  // 光のガーブ装備時は(太陽センサー由来の)太陽ゲージを2倍にする
      if (slv > 10) {
        slv = 10;
      }
      lx = GetSunLevelMaxLx(slv);
    }
    if (gStat->unk_2b0[0] == 0) {
      if (gStat->unk_2b0[1] != 0 && GetSunLevel(lx) > 2) {
        lx = GetSunLevelMaxLx(2);
      }
    } else if (GetSunLevel(lx) < 2) {
      lx = GetSunLevelMinLx(2);
    }
    if (u16_03002b80 == 1) {
      slv = GetSunLevel(lx) + 4;
      if (slv > 10) {
        slv = 10;
      }
      lx = GetSunLevelMaxLx(slv);
    } else if (u16_03002b80 == 2) {
      lx = 0;
    }
  }
  return lx;
#else
  INCFUNC("asm/func/ApplyLxModifiers.inc");
#endif
}

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

// 日なたにいる間の毎フレームの取り分。樹の経験値・ソーラースタンド・熱量を進める
NON_MATCH void ApplySunlightGain(SunlightEntity* p) {
#ifdef NONMATCHING_C
  if (gPlayerPtr[0] != NULL && (gFlag030047a4 & (FLAG030047A4_UNK_11 | FLAG030047A4_UNK_12)) == 0) {
    if ((gFlag030047a4 & FLAG030047A4_UNK_9) == 0 && gPlayerPtr[0]->unk_1c != 2) {
      if (gInput[0].down == 0) {
        if (p->idleTimer < 900) {
          p->idleTimer++;
        }
      } else {
        p->idleTimer = 0;
      }
      if (gStat->lx > 0 && (p->tickCounter & 0x3F) == 0) {
        if (p->idleTimer < 900) {
          u32 exp = gStat->treeExp;

          if (exp != 0x7FFFFFFF) {
            exp += gStat->sunGauge;
            if ((s32)exp < 0) {
              exp = 0x7FFFFFFF;
            }
            gStat->treeExp = exp;
          }
          if ((s32)gStat->solarStand < 9999) {
            u16 carry;

            if (gPlayerPtr[0]->flag378 & FLAG378_AET_RES_SOL) {
              p->solarStandFrac += ((gStat->sunGauge >> 1) + 5) * 2;  // メイルオブソル装備時
            } else {
              p->solarStandFrac += (gStat->sunGauge >> 1) + 5;
            }
            carry = p->solarStandFrac >> 4;
            p->solarStandFrac -= carry * 16;
            gStat->solarStand += carry;
            if ((s32)gStat->solarStand > 9999) {
              gStat->solarStand = 9999;
            }
          }
          if (gStat->unk_1e0 != 0x7FFFFFFF) {
            s32 n = gStat->unk_1e0 + gStat->sunGauge;

            if (n < 0) {
              n = 0x7FFFFFFF;
            }
            gStat->unk_1e0 = n;
            gStat->unk_1e4++;
          }
          if ((p->tickCounter & 0x7F) == 0) {
            RotItem(gStat->sunGauge);
          }
        }
        if (gStat->thermal < 30000) {
          gStat->thermal += (u16)p->sunGauge;
          if (gStat->thermal > 29999) {
            gStat->thermal = 30000;
            SetOverheatTime();
          }
        }
      }
      UpdateOverheat(p);
    } else if (gStat->thermal < 30000) {
      if (gStat->lx > 0 && (p->tickCounter & 0x3F) == 0) {
        gStat->thermal += (u16)p->sunGauge;
        if (gStat->thermal > 29999) {
          gStat->thermal = 30000;
          SetOverheatTime();
        }
      }
    } else if (gStat->sunGauge > 2) {
      SetOverheatTime();
    }
    p->tickCounter++;
  }
#else
  INCFUNC("asm/func/ApplySunlightGain.inc");
#endif
}

// 毎フレームの本体。センサーを温めてから計測に入り、結果を gStat に流す
NON_MATCH void UpdateSunlight(SunlightEntity* p) {
#ifdef NONMATCHING_C
  switch (p->state) {
    case 0: {
      p->stateTimer++;
      if (p->stateTimer > 29) {
        Sensor_Enable();
        p->state = 1;
        p->stateTimer = 0;
      }
      break;
    }
    case 1: {
      p->stateTimer++;
      if (p->stateTimer > 59) {
        p->state = 2;
        p->stateTimer = 0;
      }
      break;
    }
    case 2: {
      p->lx = FUN_082418c0();
      p->sunGauge = GetSunLevel(p->lx);
      gStat->lx = ApplyLxModifiers(p->lx);
      gStat->sunGauge = GetSunLevel(gStat->lx);
      ApplySunlightGain(p);
      gSavedLx = gStat->lx;
      gSavedSunGauge[0] = gStat->sunGauge;
      break;
    }
  }
#else
  INCFUNC("asm/func/UpdateSunlight.inc");
#endif
}

// デバッグ用。A+L / A+R で lx を手動で上下させ、その値を返す
NON_MATCH u32 UpdateDebugLx(SunlightEntity* p) {
#ifdef NONMATCHING_C
  Keys16 down;

  if (gFlag030047a4 & FLAG030047A4_UNK_11) {
    s32 idx = Entity9A9F_GetPlayerIdx();

    down = gInput[idx].down;
  } else {
    down = gInput->down;
  }
  if (down & A_BUTTON) {
    if (down & L_BUTTON) {
      p->adjustTimer++;
      if ((p->adjustTimer & 1) == 0 && gDebugLx <= 139) {
        gDebugLx++;
      }
    } else if (down & R_BUTTON) {
      p->adjustTimer++;
      if ((p->adjustTimer & 1) == 0 && gDebugLx != 0) {
        gDebugLx--;
      }
    }
  }
  return gDebugLx;
#else
  INCFUNC("asm/func/UpdateDebugLx.inc");
#endif
}

// UpdateSunlight のデバッグ版。lx をセンサーでなく手動値から取る。呼び出し元は見つかっていない
NON_MATCH void UpdateSunlightDebug(SunlightEntity* p) {
#ifdef NONMATCHING_C
  switch (p->state) {
    case 0: {
      p->stateTimer++;
      if (p->stateTimer > 29) {
        Sensor_Enable();
        p->state = 1;
        p->stateTimer = 0;
      }
      break;
    }
    case 1: {
      p->stateTimer++;
      if (p->stateTimer > 59) {
        p->state = 2;
        p->stateTimer = 0;
      }
      break;
    }
    case 2: {
      p->lx = UpdateDebugLx(p);
      p->sunGauge = GetSunLevel(p->lx);
      gStat->lx = ApplyLxModifiers(p->lx);
      gStat->sunGauge = GetSunLevel(gStat->lx);
      ApplySunlightGain(p);
      gSavedLx = gStat->lx;
      gSavedSunGauge[0] = gStat->sunGauge;
      break;
    }
  }
#else
  INCFUNC("asm/func/UpdateSunlightDebug.inc");
#endif
}

s32 SunlightEntity_Update(SunlightEntity* p) {
  if (!gSunlightSuspended) p->updateCallback(p);
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
  p->updateCallback = UpdateSunlight;
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

// RTC の現在時刻を gStat に写し、まだ日没前かどうかを控える
u32 ReflectClock(void) {
  s32 sunsetHour, sunsetMinute;
  bool32 beforeSunset;

  gStat->date.val = GetDate();
  gStat->hour = GetHour();
  gStat->minute = GetMinute();
  sunsetHour = gClock.sunset.hour;
  sunsetMinute = gClock.sunset.minute;
  beforeSunset = FALSE;
  if (gStat->hour < sunsetHour || (gStat->hour == sunsetHour && gStat->minute < sunsetMinute)) {
    beforeSunset = TRUE;
  }
  gStat->isBeforeSunset = beforeSunset;
}

// 日付をまたいだか、最後に起動してから日没を越えたかを見て、熱と天候の状態を1日ぶん巻き戻す
NON_MATCH void ApplyDayRollover(SunlightEntity* _ UNUSED) {
#ifdef NONMATCHING_C
  u32 y0, m0, d0;
  u32 y1, m1, d1;
  s32 curHour, curMinute;
  s32 sunsetHour, sunsetMinute;
  u32 days;
  bool32 reset;
  BCDDate date;

  date.val = GetDate();
  curHour = GetHour();
  curMinute = GetMinute();
  sunsetHour = gClock.sunset.hour;
  sunsetMinute = gClock.sunset.minute;
  ParseBCDDate(&y0, &m0, &d0, date);
  ParseBCDDate(&y1, &m1, &d1, gStat->date);
  days = FUN_0823d9ec(y0, m0, d0, y1, m1, d1);
  reset = FALSE;
  if (days >= 2) {
    reset = TRUE;
  } else if (days == 1) {
    if (gStat->isBeforeSunset != 0 || sunsetHour < curHour || (curHour == sunsetHour && sunsetMinute <= curMinute)) {
      reset = TRUE;
    }
  } else {
    bool32 wasBeforeSunset = FALSE;
    bool32 isAfterSunset = FALSE;

    if (gStat->hour < sunsetHour || (gStat->hour == sunsetHour && gStat->minute < sunsetMinute)) {
      wasBeforeSunset = TRUE;
    }
    if (sunsetHour < curHour || (curHour == sunsetHour && sunsetMinute <= curMinute)) {
      isAfterSunset = TRUE;
    }
    if (wasBeforeSunset && isAfterSunset) {
      reset = TRUE;
    }
  }
  if (reset) {
    gStat->unk_1b8 = 0;
    gStat->heatstroke = 0;
    gStat->thermal = 0;
    gStat->unk_1c0 = 0;
    gStat->unk_2b0[0] = 0;
    gStat->unk_2b0[1] = 0;
  }
  if (gStat->thermal > 29999 && IsGunCooled()) {
    gStat->thermal = 0;
    gStat->heatstroke = 0;
  }
  ReflectClock();
#else
  INCFUNC("asm/func/ApplyDayRollover.inc");
#endif
}

s32 SunlightEntity_Init(SunlightEntity* p) {
  FUN_08241f28(p);
  ApplyDayRollover(p);
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
