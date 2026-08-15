#ifndef __INCLUDE_ENTITY_UNK_H__
#define __INCLUDE_ENTITY_UNK_H__

#include "entity.h"
#include "gba/gba.h"
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

struct Unk_0200865c;

typedef struct {
  Entity e;  // ENTITY_UNK_2
  struct Unk_0200865c* unk_18;
  struct Unk_0200865c* unk_1c;
} Entity2;
static_assert(sizeof(Entity2) == 32);

extern Entity2* gEntity2;
Entity2* Entity2_Create(void);
void FUN_0823b1ec(void);

// --------------------------------------------

#endif  // __INCLUDE_ENTITY_UNK_H__
