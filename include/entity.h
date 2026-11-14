#ifndef GUARD_ZOKTAI_ENTITY_H
#define GUARD_ZOKTAI_ENTITY_H

#include "gba/gba.h"

// このゲームのすべてのものはEntityで表される

// idx for gEntityManager, 0x03004520
typedef u8 EntityKind;
#define ENTITY_SYSTEM 0
#define ENTITY_UNK_1 1
#define ENTITY_UNK_2 2
#define ENTITY_UNK_3 3
#define ENTITY_UNK_4 4
#define ENTITY_UNK_5 5
#define ENTITY_PLAYER 6
#define ENTITY_CAMERA 7
#define ENTITY_UNK_8 8
#define ENTITY_UNK_9 9
#define ENTITY_UNK_10 10
#define ENTITY_UNK_11 11
#define ENTITY_UNK_12 12
#define ENTITY_UNK_13 13
#define ENTITY_KINDS 14

// gSuspendFlags / EntityList.suspendMask, ゲームの進行を一時的に止めている原因, 原因がなくなれば再開する
typedef u32 SuspendFlags;
#define SUSPEND_LINK_WAIT (1 << 0)  // 0x1, 通信相手の応答待ち, 受信できない間は HUD の更新や通信のキー入力の取り込みも止まる
#define SUSPEND_PAUSE (1 << 1)      // 0x2, ポーズ中, BGM も止める
#define SUSPEND_MENU (1 << 2)       // 0x4, クイックチェンジ, スタートメニュー中 (ショップなどではセットされない)
#define SUSPEND_EVENT (1 << 3)      // 0x8, イベント中, GAMEFLAG_EVENT と一緒に立ち BGM も止める

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
  EntityKind kind;       // 0x14, see EntityKind
  u8 unk_15;             // 0x15
  u8 unk_16;             // 0x16
  u8 unk_17;             // 0x17
} Entity;
static_assert(sizeof(Entity) == 24);

// --------------------------------------------

typedef struct {
  Entity* head;              // 0x00
  SuspendFlags suspendMask;  // 0x04, このリストを止める原因, gSuspendFlags と重なるビットがあればリストの Entity を更新しない
} EntityList;

// ------------------------------------------------------------------------------------------------------------------------------------

extern EntityList gEntityManager[ENTITY_KINDS];
extern SuspendFlags gSuspendFlags;  // 0x030044BC

// --------------------------------------------

void* CreateEntity(u32 kind, s32 bytesize);
void AddEntity(Entity* p);
void RemoveEntity(Entity* p);
u32 KillEntity(Entity* p);
void SetEntityRoutine(void* entity, void* entity_func_onupdate, void* entity_func_ondestroy);

#endif  // GUARD_ZOKTAI_ENTITY_H
