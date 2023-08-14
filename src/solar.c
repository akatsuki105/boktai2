#include "entity.h"
#include "global.h"
#include "time.h"

void SetOverheatTime(void) {
  (GAME->overheatTime).date.date = GetDate();
  (GAME->overheatTime).hour = GetHour();
  (GAME->overheatTime).minute = GetMinute();
  (GAME->overheatTime).second = GetSecond();
}

NAKED bool32 IsGunCooled(void) { INCCODE("asm/todo/IsGunCooled.inc"); }

WIP void overheat_08241a04(struct Entity5 *_ UNUSED) {
#if MODERN
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
  INCCODE("asm/wip/overheat_08241a04.inc");
#endif
}
