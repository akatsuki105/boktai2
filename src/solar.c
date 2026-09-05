
#include "solar.h"

#include "global.h"
#include "solar_sensor.h"
#include "time.h"

IWRAM_DATA UnkSolarEntity* gUnkSolarEntity = NULL;  // 0x03001708

u32 FUN_0823d9ec(u32 y0, u32 m0, u32 d0, u32 y1, u32 m1, u32 d1);

NAKED void FUN_08241650(void) { INCFUNC("asm/func/FUN_08241650.inc"); }

NAKED bool32 FUN_08241690(void) { INCFUNC("asm/func/FUN_08241690.inc"); }

NAKED void FUN_082416bc(void) { INCFUNC("asm/func/FUN_082416bc.inc"); }

NAKED void FUN_082416c8(void) { INCFUNC("asm/func/FUN_082416c8.inc"); }

NAKED bool32 FUN_082416d4(void) { INCFUNC("asm/func/FUN_082416d4.inc"); }

NAKED void FUN_08241704(void) { INCFUNC("asm/func/FUN_08241704.inc"); }

NAKED void FUN_0824172c(void) { INCFUNC("asm/func/FUN_0824172c.inc"); }

NAKED s32 FUN_0824175c(void) { INCFUNC("asm/func/FUN_0824175c.inc"); }

// 照度(lx)を 0〜10 の太陽レベルに変換する
Sunlevel GetSunLevel(s32 lx) {
  if (lx == 0x0) return 0;
  if (lx <= 0x5) return 1;
  if (lx <= 0xC) return 2;
  if (lx <= 0x16) return 3;
  if (lx <= 0x22) return 4;
  if (lx <= 0x31) return 5;
  if (lx <= 0x42) return 6;
  if (lx <= 0x56) return 7;
  if (lx <= 0x6D) return 8;
  if (lx <= 0x8B) return 9;
  return 10;
}

NAKED s32 FUN_082417cc(Sunlevel slv) { INCFUNC("asm/func/FUN_082417cc.inc"); }

NAKED s32 FUN_082417dc(Sunlevel slv) { INCFUNC("asm/func/FUN_082417dc.inc"); }

NAKED s32 FUN_082417ec(s32 lx) { INCFUNC("asm/func/FUN_082417ec.inc"); }

s32 FUN_082418c0(void) {
  s32 n = Sensor_GetRawLevel();
  if ((n < 0) || (n > gSystemSaveData->calibration)) {
    return 0;
  }

  n = gSystemSaveData->calibration - n;
  if (n > 0x8B) {
    return 0x8C;
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
    elapsed = 86400;
  }

  curH = GetHour();
  curM = GetMinute();
  curS = GetSecond();
  elapsed += (curH * 60 + curM) * 60 + curS - ((gStat->overheatTime.hour * 60 + gStat->overheatTime.minute) * 60 + gStat->overheatTime.second);

  if (elapsed >= 180) {
    return TRUE;
  }
  return FALSE;
}

NON_MATCH void UpdateOverheat(UnkSolarEntity* _ UNUSED) {
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

NAKED void solar_08241ac0(UnkSolarEntity* p) { INCFUNC("asm/func/solar_08241ac0.inc"); }

NAKED void FUN_08241cf4(UnkSolarEntity* p) { INCFUNC("asm/func/FUN_08241cf4.inc"); }

NAKED u32 FUN_08241da8(UnkSolarEntity* p) { INCFUNC("asm/func/FUN_08241da8.inc"); }

NAKED void FUN_08241e40(UnkSolarEntity* p) { INCFUNC("asm/func/FUN_08241e40.inc"); }

UnkSolarEntity* FUN_08241ef4(UnkSolarEntity* p) {
  if (u16_0300486c == 0) {
    p->unk_2c((Entity*)p);
  }
  return NULL;
}

Entity* FUN_08241f14(Entity* _) {
  Sensor_Disable();
  gUnkSolarEntity = NULL;
  return NULL;
}

NON_MATCH void FUN_08241f28(UnkSolarEntity* p) {
#ifdef NONMATCHING_C
  u16 tmp;
  p->unk_18 = 1;
  p->unk_2c = (EntityFunc)FUN_08241cf4;
  p->unk_19 = 0;
  p->unk_20 = 0;
  p->unk_22 = 0;
  gStat->lx = u16_03004870;
  tmp = u16_ARRAY_03004874[0];
  gStat->sunGauge = tmp;
#else
  INCFUNC("asm/func/FUN_08241f28.inc");
#endif
}

NAKED u32 ReflectClock(void) { INCFUNC("asm/func/ReflectClock.inc"); }

NAKED void clock_08241fd0(UnkSolarEntity* p) { INCFUNC("asm/func/clock_08241fd0.inc"); }

s32 UnkSolarEntity_Init(UnkSolarEntity* p) {
  FUN_08241f28(p);
  clock_08241fd0(p);
  gUnkSolarEntity = p;
  return 0;
}

UnkSolarEntity* UnkSolarEntity_Create(void) {
  if (gUnkSolarEntity == NULL) {
    UnkSolarEntity* p = CreateEntity(ENTITY_UNK_5, 48);
    if (p != NULL) {
      SetEntityRoutine(p, FUN_08241ef4, FUN_08241f14);
      if (UnkSolarEntity_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gUnkSolarEntity;
}
