#ifndef __INCLUDE_ENTITY_0B50_H__
#define __INCLUDE_ENTITY_0B50_H__

#include "entity.h"
#include "types.h"

typedef struct Entity0B50 {
  Entity e;                   // 0x000, ENTITY_UNK_9
  u8 unk_18[0x1E - 0x18];     // 0x018
  u16 unk_1e;                 // 0x01E, FUN_08068c6c がダッシュ速度から引く量
  u8 unk_20[0x1F5 - 0x20];    // 0x020
  u8 unk_1f5;                 // 0x1F5, FUN_08078844 が 1 か 0x10 のときだけ先に進む
  u8 unk_1f6[0x384 - 0x1F6];  // 0x1F6
  u8 unk_384;                 // 0x384, Player の unk_390 と同じビットを持つ, bit2 が立つとエレベータに乗っている
  u8 unk_385;                 // 0x385
  u16 elevatorID;             // 0x386, 搭乗中のエレベータのID
  u8 unk_388[1052 - 0x388];   // 0x388
} Entity0B50;
static_assert(sizeof(Entity0B50) == 1052);

extern Entity0B50* gEntity0B50;  // 0x03002C00

#endif /* __INCLUDE_ENTITY_0B50_H__ */
