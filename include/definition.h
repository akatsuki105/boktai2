#ifndef GUARD_ZOKTAI_DEFINITION_H
#define GUARD_ZOKTAI_DEFINITION_H

#include "gba/types.h"
#include "types.h"

typedef void* (*TaskFn)(u32, void*);
typedef void* (*TaskFnNoArg)(void);

extern s32 gCount_Unk_0203b000;
extern u32 u32_030044bc;
extern u16 gEntityCount;
extern u32 u32_03004798;
extern u32 u32_030047a4;
extern u16 gUnk085a9208Counter;
extern u16 u16_03002b98;
extern u16 u16_0300486c;
extern u16 u16_03004870;
extern u16 u16_ARRAY_03004874[6];
extern u32 u32_ARRAY_0203f400[256];
extern void* gUnkPtr;

// --------------------------------------------

s32 Div(s32 a, s32 b);
s32 Mod(s32 a, s32 b);
bool32 prepare_08231510(u8 n);
u32 fetch_082316e4(void);
void FUN_0809c464(void);

#endif  // GUARD_ZOKTAI_DEFINITION_H
