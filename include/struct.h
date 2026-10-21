#ifndef __INCLUDE_STRUCT_H__
#define __INCLUDE_STRUCT_H__

#include "gba/gba.h"
#include "types.h"

// 用途不明の構造体　はここに置いておく

struct Mover;

// ノードの持ち主に用件を伝えるコールバック, 根拠: EntityF41A_OnMessage が Entity5941_Register の第3引数に渡る
typedef bool32 Entity5941Callback(struct Mover* owner, s32 msg, s32 value);

// gEntity5941 の単方向リストのノード, 敵は _Init で Entity5941_Register、_Destroy で Entity5941_Unregister を呼んで出入りする
typedef struct Entity5941Node {
  struct Mover* owner;          // 0x00, Entity5941_Register の第2引数 (敵の Mover)
  u32 flags;                    // 0x04, bit0 が落ちているノードだけ Entity5941_FindNearestInCone の対象になる
  Entity5941Callback* fn;       // 0x08, Entity5941_Register の第3引数
  struct Entity5941Node* next;  // 0x0C
} Entity5941Node;
static_assert(sizeof(Entity5941Node) == 16);

static inline void Entity5941Node_ClearFlags(Entity5941Node* n, u32 bits) { n->flags &= ~bits; }

bool32 Entity5941_Register(Entity5941Node* node, void* owner, void* fn);
void Entity5941_Unregister(Entity5941Node* node);

// --------------------------------------------

#endif  // __INCLUDE_STRUCT_H__
