#include "collision_map.h"
#include "file.h"
#include "global.h"
#include "malloc.h"

// code_0823b540.c でも CollisionMap を扱っている?

typedef struct Unk030046a4 {
  u8 unk_0[4];
  CollisionMapTileData* tiledata;  // 0x004
  u8 unk_8[4];
  ZoneData* zones;   // 0x00C
  PathData* paths;   // 0x010
  NavMesh* navMesh;  // 0x014
  u8 unk_18[3620 - 0x18];
} Unk030046a4;
static_assert(sizeof(Unk030046a4) == 3620);

extern Unk030046a4* gUnk030046a4;
extern s32 gMapBlockW;
extern s32 gMapBlockH;

void FUN_08230e30(u16 id, void* r1, s32 r2);
bool32 FUN_082326d8(void);

void FUN_082326a0(void) {
  void* p = Malloc(3620);
  ClearMemory(p, 3620);
  FUN_08230e30(0x56c2, p, 1);
  gUnk030046a4 = p;
  FUN_082326d8();
}

NAKED bool32 FUN_082326d8(void) { INCFUNC("asm/func/FUN_082326d8.inc"); }

NAKED void FUN_0823273c(void) { INCFUNC("asm/func/FUN_0823273c.inc"); }

NAKED void FUN_08232760(void) { INCFUNC("asm/func/FUN_08232760.inc"); }

void UpdateMapSize_0823279c(void) {
  gMapBlockW = (gUnk030046a4->tiledata)->width;
  gMapBlockH = (gUnk030046a4->tiledata)->height;
}

s32 FUN_082327c0(FileID id) {
  gUnk030046a4->tiledata = GetFile(0xAE1B, id);  // これNULLを返すっぽいけど...
  FUN_0823273c();
  FUN_08232760();
  UpdateMapSize_0823279c();
  return 0;
}
