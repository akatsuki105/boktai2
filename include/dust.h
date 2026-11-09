#ifndef __INCLUDE_DUST_H__
#define __INCLUDE_DUST_H__

#include "gba/gba.h"
#include "types.h"

struct DustManager;

struct DustManager* DustManager_Create(u32 _, u32 __);
void DustManager_ClearGlobal(void);
s32 DustManager_Spawn(Vec3* pos, Vec3* velRange, Vec3* posRange, u32 count, u32 priority, u32 animFlags);
s32 DustManager_SpawnNoPause(Vec3* pos, Vec3* velRange, Vec3* posRange, u32 count, u32 priority, u32 animFlags);

#endif  // __INCLUDE_DUST_H__
