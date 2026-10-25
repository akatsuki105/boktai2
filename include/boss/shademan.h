#ifndef __INCLUDE_BOSS_SHADEMAN_H__
#define __INCLUDE_BOSS_SHADEMAN_H__

#include "entity.h"
#include "gba/gba.h"
#include "sprite_aux.h"
#include "types.h"

typedef struct {
  bool8 active;            // 0x00
  u8 state;                // 0x01, PTR_ARRAY_085aba70 の添字
  u8 unk_02[0x4C - 0x02];  // 0x02
} Entity0805ee80Elem;
static_assert(sizeof(Entity0805ee80Elem) == 76);

typedef struct Entity0805ee80 {
  Entity e;                               // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx[2];                    // 0x018, SPRITE_SPEAKER
  s32 unk_50;                             // 0x050, _Create の引数
  Entity0805ee80Elem elems[8];            // 0x054
  struct Entity0805f2dc* entity0805f2dc;  // 0x2B4
} Entity0805ee80;
static_assert(sizeof(Entity0805ee80) == 696);

#endif  // __INCLUDE_BOSS_SHADEMAN_H__
