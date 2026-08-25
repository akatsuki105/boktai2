#ifndef __INCLUDE_ENTITY_UNK_H__
#define __INCLUDE_ENTITY_UNK_H__

#include "entity.h"
#include "gba/gba.h"
#include "struct.h"
#include "types.h"

// 正体不明の Entity を一旦ここに置いておく

// --------------------------------------------

typedef struct {
  Entity e;  // ENTITY_UNK_1
  s32 unk_18;
  s32 unk_1c;
} Entity1_030016a0;
static_assert(sizeof(Entity1_030016a0) == 32);

extern Entity1_030016a0 gEntity1_030016a0;  // 0x030016A0
void FUN_0823acbc(void);                    // Init

// --------------------------------------------

typedef struct {
  Entity e;  // ENTITY_UNK_1
  u8 unk_18[732];
} Entity_03002c68;
static_assert(sizeof(Entity_03002c68) == 756);

extern Entity_03002c68* gEntity_03002c68;
Entity_03002c68* FUN_081dfc64(void);  // Create

// --------------------------------------------

struct Entity2UnkData;

typedef struct {
  Entity e;  // ENTITY_UNK_2
  struct Entity2UnkData* unk_18;
  struct Entity2UnkData* unk_1c;
} EntityB8B9;
static_assert(sizeof(EntityB8B9) == 32);

extern EntityB8B9* gEntityB8B9;
EntityB8B9* EntityB8B9_Create(void);
void FUN_0823b1ec(void);

// --------------------------------------------

typedef struct Entity4E69 {
  Entity e;  // ENTITY_UNK_2
  u8 unk_18[96];
  UnkStruct52 unk_78;  // 0x78
} Entity4E69;
static_assert(sizeof(Entity4E69) == 172);

extern Entity4E69* gEntity4E69;  // 0x03002B4C

// --------------------------------------------

typedef struct Entity28CB {
  Entity e;            // ENTITY_UNK_8
  UnkStruct52 unk_18;  // 0x18
  u8 unk_4c[400 - 76];
} Entity28CB;
static_assert(sizeof(Entity28CB) == 400);

// --------------------------------------------

typedef struct EntityE534 {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[0xCD4 - 24];
  UnkStruct52 unk_cd4;  // 0xCD4, 根拠: 0x08012bfc
} EntityE534;
static_assert(sizeof(EntityE534) == 3336);

// --------------------------------------------

#endif  // __INCLUDE_ENTITY_UNK_H__
