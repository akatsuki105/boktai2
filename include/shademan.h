#ifndef __INCLUDE_SHADEMAN_H__
#define __INCLUDE_SHADEMAN_H__

#include "entity.h"
#include "hitbox.h"
#include "shadow.h"
#include "sprite_main.h"
#include "types.h"

// シェードマン(シングルプレイ用)
typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_8
  u8 unk_18[0x15C - 0x18];    // 0x018, まだ未解析
  HitboxData hitbox_15c;      // 0x15C
  u8 unk_1ac[0x2BC - 0x1AC];  // 0x1AC, まだ未解析
  MainSprite sprite_2bc;      // 0x2BC
  AuxShadow shadow_31c;       // 0x31C
  u8 unk_388[0x38C - 0x388];  // 0x388, まだ未解析
  u32 unk_38c;                // 0x38C, FUN_0821bd14 が bit8 を立てる
  u8 unk_390[3076 - 0x390];   // 0x390, まだ未解析
} Entity0623;
static_assert(sizeof(Entity0623) == 3076);

#endif  // __INCLUDE_SHADEMAN_H__
