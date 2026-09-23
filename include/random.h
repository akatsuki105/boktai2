#ifndef __INCLUDE_RANDOM_H__
#define __INCLUDE_RANDOM_H__

#include "gba/gba.h"

extern u32 gRngValue;

extern u32 gRandTableIdx;
extern u16 gRandomTable[1024];

extern u32 gRandTableIdx2;
extern const u16 gRandomTable2[1024];

void CreateRandomTable(void);
u32 Random(void);

#endif  // __INCLUDE_RANDOM_H__
