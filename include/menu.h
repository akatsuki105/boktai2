#ifndef __INCLUDE_MENU_H__
#define __INCLUDE_MENU_H__

#include "gba/gba.h"
#include "types.h"

void HUD_ShowWeaponCrashEffect(void);
void HUD_StartCountdown(u16* remainingTime);
void HUD_RemoveCountdown(void);
void FUN_0809c464(void);

#endif  // __INCLUDE_MENU_H__
