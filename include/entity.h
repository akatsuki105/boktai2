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

// EntityList.disableFlags
typedef u32 EntityDisableFlags;    // セットされるとき
#define ENTITY_DISABLE_0 (1 << 0)  //
#define ENTITY_DISABLE_1 (1 << 1)  //
#define ENTITY_DISABLE_2 (1 << 2)  // クイックチェンジ, スタートメニュー中 (ショップなどではセットされない)
#define ENTITY_DISABLE_3 (1 << 3)  // 会話中

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
  Entity* head;                     // 0x00
  EntityDisableFlags disableFlags;  // 0x04, (EntityList.disableFlags & gEntityDisableFlags) != 0 のときはEntityListのEntityを更新しない
} EntityList;

// --------------------------------------------

// FUN_080155e4 に渡す粒子1種類ぶんの発生パラメータ
typedef struct {
  u16 kind;              // 0x00
  u16 flags;             // 0x02
  u16 unk_04;            // 0x04
  u16 animSpeed;         // 0x06
  u16 speedY;            // 0x08
  s16 speedYRand;        // 0x0A, speedY に加える乱数の幅
  u16 speedXZ;           // 0x0C
  s16 speedXZRand;       // 0x0E, speedXZ に加える乱数の幅
  u16 angleY;            // 0x10
  u16 angleYRand;        // 0x12
  u16 angleXZ;           // 0x14
  u16 angleXZRand;       // 0x16
  u16 decayStartY;       // 0x18
  u16 decayStartYRand;   // 0x1A
  u16 unk_1c;            // 0x1C
  u16 unk_1e;            // 0x1E
  u16 decayStartXZ;      // 0x20
  u16 decayStartXZRand;  // 0x22
  u16 unk_24;            // 0x24
  u16 unk_26;            // 0x26
} ParticleSpawnParam;
static_assert(sizeof(ParticleSpawnParam) == 40);

// ------------------------------------------------------------------------------------------------------------------------------------

extern EntityList gEntityManager[ENTITY_KINDS];
extern EntityDisableFlags gEntityDisableFlags;  // 0x030044BC

// --------------------------------------------

void* CreateEntity(u32 kind, s32 bytesize);
void AddEntity(Entity* p);
u32 KillEntity(Entity* p);
void SetEntityRoutine(void* entity, void* entity_func_onupdate, void* entity_func_ondestroy);

#endif  // GUARD_ZOKTAI_ENTITY_H
