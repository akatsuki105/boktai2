#include "entity.h"
#include "global.h"
#include "malloc.h"

typedef Entity Entity08240a54;  // ENTITY_UNK_3, サイズは Entity と同じ

// FUN_08240a90 が Malloc(12) して ID 0x757B で登録する
typedef struct {
  u16 unk_00;  // 0x00, まだ未解析
  u16 ids[4];  // 0x02, 空き枠は 0
  u16 unk_0a;  // 0x0A, まだ未解析
} Entity08240a54Data;
static_assert(sizeof(Entity08240a54Data) == 12);

IWRAM_DATA Entity08240a54Data* gEntity08240a54Data = NULL;  // 0x030016FC

// 空き枠に id を登録する
bool32 FUN_082409a0(u32 id) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (gEntity08240a54Data->ids[i] == 0) {
      gEntity08240a54Data->ids[i] = id;
      return TRUE;
    }
  }

  return FALSE;
}

// 登録済みの id の枠を空ける
bool32 FUN_082409d0(u32 id) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (gEntity08240a54Data->ids[i] == id) {
      gEntity08240a54Data->ids[i] = 0;
      return TRUE;
    }
  }

  return FALSE;
}

s32 Entity08240a54_Update(Entity08240a54* p) { return 0; }

s32 Entity08240a54_Destroy(Entity08240a54* p) {
  Free(gEntity08240a54Data);
  gEntity08240a54Data = NULL;
  return 0;
}

s32 Entity08240a54_Init(Entity08240a54* p) {
  s32 i;

  if (gEntity08240a54Data == NULL) {
    return -1;
  }

  for (i = 0; i < 4; i++) {
    gEntity08240a54Data->ids[i] = 0;
  }

  return 0;
}

Entity08240a54* Entity08240a54_Create(void) {
  Entity08240a54* p = CreateEntity(ENTITY_UNK_3, sizeof(Entity08240a54));

  if (p != NULL) {
    SetEntityRoutine(p, Entity08240a54_Update, Entity08240a54_Destroy);
    if (Entity08240a54_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

NAKED bool32 FUN_08240a90(void) { INCFUNC("asm/func/FUN_08240a90.inc"); }
