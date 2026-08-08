#ifndef GUARD_ZOKTAI_ENTITY_H
#define GUARD_ZOKTAI_ENTITY_H

#include "gba/gba.h"

// このゲームのすべてのものはEntityで表される。

// idx for gEntityManager, 0x03004520
// WARNING: これらに決まった意味はなくて、ただのEntityのリソース確保の優先順位かもしれない
enum EntityKind {
  ENTITY_UNK_0 = 0,
  ENTITY_UNK_1 = 1,  // ここ(0x03004528)をnullにした状態でエリア移動するとフリーズした
  ENTITY_UNK_2 = 2,
  ENTITY_UNK_3 = 3,
  ENTITY_DESCRIPTION = 4,  // メニューのアイテムや武器の説明文？
  ENTITY_UNK_5 = 5,
  ENTITY_PLAYER = 6,
  ENTITY_UNK_7 = 7,  // これを削除すると画面のスクロールがおかしくなる
  ENTITY_UNK_8 = 8,
  ENTITY_UNK_9 = 9,  // 果実屋のリタ、宿屋の太陽ダケ
  ENTITY_UNK_10 = 10,
  ENTITY_UNK_11 = 11,  // プレイヤーや敵との衝突判定？、背景のパレット？
  ENTITY_UI = 12,
  ENTITY_UNK_13 = 13,  // これを削除すると画面のスクロールがおかしくなる
};

// Entity.unk_12
#define E_FLAG_DELETE (1 << 0)  // 1 にすると Entity を削除する

struct Entity;

typedef struct Entity* (*EntityFunc)(struct Entity*);

// Entity
#define ENTITY                                                                        \
  struct Entity* prev; /* 0x00 */                                                     \
  struct Entity* next; /* 0x04 */                                                     \
  EntityFunc onUpdate; /* 0x08 */                                                     \
  EntityFunc onExit;   /* 0x0C, Entityが削除される時汎用的な削除処理の前に呼ばれる */ \
  u16 id;              /* 0x10, Entity全体のID */                                     \
  u16 unk_12;          /* 0x12, 01 にするとEntityを削除 */                            \
  u8 kind;             /* 0x14, see EntityKind */                                     \
  u8 unk_15;           /* 0x15 */                                                     \
  u8 unk_16;           /* 0x16 */                                                     \
  u8 unk_17;           /* 0x17 */

typedef struct Entity {
  ENTITY;
} Entity;

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
} Entity5;

// 0x0200865c
typedef struct Unk_0200865c {
  u16 id;
  u8 unk_02[58];
  struct Unk_0200865c* prev;
  struct Unk_0200865c* next;
} Unk_0200865c;

typedef struct {
  Entity e;
  Unk_0200865c* unk_18;
  Unk_0200865c* unk_1c;
  void* unk_20;
  void* unk_24;
  // anymore
} Entity2;

// --------------------------------------------

typedef struct {
  Entity* entity;
  u32 unk_04;
} EntityHeader;

// ------------------------------------------------------------------------------------------------------------------------------------

extern EntityHeader gEntityManager[14];
extern EntityHeader gDefaultEntityManager[14];
extern Entity2* PTR_030016f8;
extern Entity5* PTR_03001708;

// --------------------------------------------

Entity* CreateEntity(u32 kind, s32 bytesize);
u32 KillEntity(Entity* p);
void SetEntityRoutine(Entity* p, EntityFunc fn1, EntityFunc fn2);

#endif  // GUARD_ZOKTAI_ENTITY_H
