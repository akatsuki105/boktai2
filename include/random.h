#ifndef __INCLUDE_RANDOM_H__
#define __INCLUDE_RANDOM_H__

#include "gba/gba.h"

extern u32 gRngValue;
extern u16 gRandomTable[1024];
extern u32 u32_030046b4;
extern u32 gRandTableIdx;

void CreateRandomTable(void);
u32 Random(void);

#endif  // __INCLUDE_RANDOM_H__
