#ifndef GUARD_ZOKTAI_ENTITY_H
#define GUARD_ZOKTAI_ENTITY_H

#include "gba/gba.h"

// idx for gEntityManager, 0x03004520
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
  ENTITY_NPC = 9,  // 果実屋のリタ、宿屋の太陽ダケ
  ENTITY_UNK_10 = 10,
  ENTITY_UNK_11 = 11,  // プレイヤーや敵との衝突判定？、背景のパレット？
  ENTITY_UI = 12,
  ENTITY_UNK_13 = 13,  // これを削除すると画面のスクロールがおかしくなる
};

struct Entity;
typedef struct Entity* (*EntityFunc)(struct Entity*);

struct EntityHeader {
  struct Entity* entity;
  u32 unk_04;
};

struct Entity {
  struct Entity* prev;
  struct Entity* next;
  EntityFunc unk_08;
  EntityFunc unk_0c;
  u16 id;      // Entity全体のID
  u16 unk_12;  // 01 にするとEntityを削除
  u8 kind;
  u8 unk_15;
  u8 unk_16;
  u8 unk_17;
};

struct Entity5 {
  struct Entity e;
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
};

// 0x0200865c
struct Unk_0200865c {
  u16 id;
  u8 unk_02[58];
  struct Unk_0200865c* prev;
  struct Unk_0200865c* next;
};

struct Entity2 {
  struct Entity e;
  struct Unk_0200865c* unk_18;
  struct Unk_0200865c* unk_1c;
  void* unk_20;
  void* unk_24;
  // anymore
};

// ------------------------------------------------------------------------------------------------------------------------------------

extern struct EntityHeader gEntityManager[14];
extern struct EntityHeader gDefaultEntityManager[14];
extern struct Entity2* PTR_030016f8;
extern struct Entity5* PTR_03001708;

// --------------------------------------------

struct Entity* AllocateEntity(u32 r0);
struct Entity* CreateEntity(u32 kind, u32 r1);
u32 KillEntity(struct Entity* p);
void SetEntityRoutine(struct Entity* p, EntityFunc fn1, EntityFunc fn2);
void FUN_082309cc(struct Entity* p, u32 r1);

#endif  // GUARD_ZOKTAI_ENTITY_H
