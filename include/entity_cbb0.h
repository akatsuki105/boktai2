#ifndef __INCLUDE_ENTITY_CBB0_H__
#define __INCLUDE_ENTITY_CBB0_H__

#include "entity.h"
#include "types.h"

typedef struct EntityCBB0 {
  Entity e;          // 0x0, ENTITY_UNK_9
  u16 subroutineID;  // 0x18, このゲーム中では 0xCBB0
  u8 unk_1a[3062];   // 0x01A
  u8 unk_c10;        // 0xC10, 0 でない間だけ Generator_Update が unk_e8 を減らす
  u8 unk_c11[3019];  // 0xC11
} EntityCBB0;
static_assert(sizeof(EntityCBB0) == 6108);

extern EntityCBB0* gEntityCBB0;  // 0x03002C58

#endif  // __INCLUDE_ENTITY_CBB0_H__
