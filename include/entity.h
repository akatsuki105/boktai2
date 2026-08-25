#ifndef GUARD_ZOKTAI_ENTITY_H
#define GUARD_ZOKTAI_ENTITY_H

#include "gba/gba.h"

// このゲームのすべてのものはEntityで表される。

// idx for gEntityManager, 0x03004520
// WARNING: これらに決まった意味はなくて、ただのEntityのリソース確保の優先順位かもしれない
enum EntityKind {
  ENTITY_SYSTEM = 0,
  ENTITY_UNK_1 = 1,  // ここ(0x03004528)をnullにした状態でエリア移動するとフリーズした
  ENTITY_UNK_2 = 2,
  ENTITY_UNK_3 = 3,
  ENTITY_UNK_4 = 4,
  ENTITY_UNK_5 = 5,
  ENTITY_PLAYER = 6,
  ENTITY_CAMERA = 7,  // これを削除すると画面のスクロールがおかしくなる
  ENTITY_UNK_8 = 8,
  ENTITY_UNK_9 = 9,
  ENTITY_UNK_10 = 10,
  ENTITY_UNK_11 = 11,
  ENTITY_UNK_12 = 12,
  ENTITY_UNK_13 = 13,  // これを削除すると画面のスクロールがおかしくなる
};
#define ENTITY_KINDS 14

// Entity.unk_12
#define E_FLAG_DELETE (1 << 0)  // 1 にすると Entity を削除する

struct Entity;

typedef s32 (*EntityFunc)(struct Entity*);

// Entity, 24bytes
typedef struct Entity {
  struct Entity* prev;   // 0x00
  struct Entity* next;   // 0x04
  EntityFunc onUpdate;   // 0x08, 毎フレーム呼ばれる
  EntityFunc onDestroy;  // 0x0C, Entityが削除される時汎用的な削除処理の前に呼ばれる,
  u16 id;                // 0x10, Entity全体のID
  u16 unk_12;            // 0x12, 01 にするとEntityを削除
  u8 kind;               // 0x14, see EntityKind
  u8 unk_15;             // 0x15
  u8 unk_16;             // 0x16
  u8 unk_17;             // 0x17
} Entity;
static_assert(sizeof(Entity) == 24);

// --------------------------------------------

typedef struct {
  Entity* head;      // 0x00
  u32 disableFlags;  // 0x04, (EntityList.disableFlags & gEntityDisableFlags) != 0 のときはEntityListのEntityを更新しない
} EntityList;

// ------------------------------------------------------------------------------------------------------------------------------------

extern EntityList gEntityManager[ENTITY_KINDS];

// --------------------------------------------

Entity* CreateEntity(u32 kind, s32 bytesize);
u32 KillEntity(Entity* p);
void SetEntityRoutine(void* entity, void* entity_func_onupdate, void* entity_func_ondestroy);

#endif  // GUARD_ZOKTAI_ENTITY_H
