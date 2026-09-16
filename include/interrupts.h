#ifndef __INCLUDE_INTERRUPTS_H__
#define __INCLUDE_INTERRUPTS_H__

#include "gba/gba.h"

extern IntrFunc gIntrTable[13];

void IntrDummy(void);

#endif  // __INCLUDE_INTERRUPTS_H__
