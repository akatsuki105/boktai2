#ifndef __INCLUDE_STRUCT_H__
#define __INCLUDE_STRUCT_H__

#include "gba/gba.h"
#include "types.h"

// 用途不明の構造体　はここに置いておく

// gEntity5941 の単方向リストのノード, 敵は _Init で Entity5941_Register、_Destroy で FUN_0807f598 を呼んで出入りする
typedef struct Entity5941Node {
  void* owner;                  // 0x00, Entity5941_Register の第2引数 (敵の Mover)
  u32 flags;                    // 0x04, bit0 が立っているノードだけ Entity5941_FindNearestInCone の対象になる
  void* fn;                     // 0x08, Entity5941_Register の第3引数
  struct Entity5941Node* next;  // 0x0C
} Entity5941Node;
static_assert(sizeof(Entity5941Node) == 16);

bool32 Entity5941_Register(unknown* node, unknown* owner, void* fn);

// --------------------------------------------

#endif  // __INCLUDE_STRUCT_H__
