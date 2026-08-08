#include "entity.h"
#include "global.h"
#include "time.h"

s32 FUN_082477e0(void);
void FUN_082477b4(void);
void FUN_0823db08(u32* y, u32* m, u32* d, u32 date);
u32 FUN_0823d9ec(u32 y0, u32 m0, u32 d0, u32 y1, u32 m1, u32 d1);

s32 FUN_082418c0(void) {
  s32 n = FUN_082477e0();
  if ((n < 0) || (n > gUnkPtr_030047a8->unk_4)) {
    return 0;
  }

  n = gUnkPtr_030047a8->unk_4 - n;
  if (n > 0x8B) {
    return 0x8C;
  }
  return n;
}

void SetOverheatTime(void) {
  (GAME->overheatTime).date.date = GetDate();
  (GAME->overheatTime).hour = GetHour();
  (GAME->overheatTime).minute = GetMinute();
  (GAME->overheatTime).second = GetSecond();
}

bool32 IsGunCooled(void) {
  u32 y0, m0, d0, y1, m1, d1;
  s32 elapsed;
  u32 curH, curM, curS;

  if (GetDate() == GAME->overheatTime.date.date) {
    elapsed = 0;
  } else {
    FUN_0823db08(&y0, &m0, &d0, GetDate());
    FUN_0823db08(&y1, &m1, &d1, GAME->overheatTime.date.date);
    if (FUN_0823d9ec(y0, m0, d0, y1, m1, d1) > 1) {
      return TRUE;
    }
    elapsed = 0x15180;
  }

  curH = GetHour();
  curM = GetMinute();
  curS = GetSecond();
  elapsed += (curH * 60 + curM) * 60 + curS - ((GAME->overheatTime.hour * 60 + GAME->overheatTime.minute) * 60 + GAME->overheatTime.second);

  if (elapsed > 0xb3) {
    return TRUE;
  }
  return FALSE;
}

NON_MATCH void overheat_08241a04(Entity5* _ UNUSED) {
#ifdef NONMATCHING_C
  if (GAME->thermal > 29999) {
    if ((GAME->unk_942 < 3) || (GAME->unk_934 & 0x4200)) {
      if (GAME->unk_1ba > 0) {
        GAME->unk_1ba--;
      }
      if (IsGunCooled()) {
        GAME->thermal = 0;
        GAME->unk_1ba = 0;
      }

    } else {
      SetOverheatTime();
      GAME->unk_1ba += GAME->unk_942;
      if ((s16)GAME->unk_1ba > 5000) {
        GAME->unk_1ba = 5000;
      }
    }
  }
#else
  INCFUNC("asm/func/overheat_08241a04.inc");
#endif
}

NAKED void solar_08241ac0(Entity5* p) { INCFUNC("asm/func/solar_08241ac0.inc"); }

NAKED void FUN_08241cf4(Entity5* p) { INCFUNC("asm/func/FUN_08241cf4.inc"); }

NAKED u32 FUN_08241da8(Entity5* p) { INCFUNC("asm/func/FUN_08241da8.inc"); }

NAKED void FUN_08241e40(Entity5* p) { INCFUNC("asm/func/FUN_08241e40.inc"); }

Entity5* FUN_08241ef4(Entity5* p) {
  if (u16_0300486c == 0) {
    p->unk_2c((Entity*)p);
  }
  return NULL;
}

Entity* FUN_08241f14(Entity* _) {
  FUN_082477b4();
  PTR_03001708 = NULL;
  return NULL;
}

NON_MATCH void FUN_08241f28(Entity5* p) {
#ifdef NONMATCHING_C
  u16 tmp;
  p->unk_18 = 1;
  p->unk_2c = (EntityFunc)FUN_08241cf4;
  p->unk_19 = 0;
  p->unk_20 = 0;
  p->unk_22 = 0;
  GAME->unk_940 = u16_03004870;
  tmp = u16_ARRAY_03004874[0];
  GAME->unk_942 = tmp;
#else
  INCFUNC("asm/func/FUN_08241f28.inc");
#endif
}
