#ifndef __INCLUDE_SOLAR_H__
#define __INCLUDE_SOLAR_H__

// ファイル名は暫定

#include "entity.h"
#include "gba/gba.h"
#include "types.h"

typedef struct {
  Entity e;
  u8 unk_18;
  u8 unk_19;
  u16 unk_1a;
  u32 unk_1c;
  u16 unk_20;
  u16 unk_22;
  u16 unk_24;
  u16 unk_26;
  u16 unk_28;
  u16 unk_2a;
  EntityFunc unk_2c;
} UnkSolarEntity;
static_assert(sizeof(UnkSolarEntity) == 48);

extern UnkSolarEntity* gUnkSolarEntity;

#endif  // __INCLUDE_SOLAR_H__
