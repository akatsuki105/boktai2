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

extern Unk030046a4* gCollisionMap;
extern s32 gMapBlockW;
extern s32 gMapBlockH;

IWRAM_DATA bool32 bool32_0300077c = FALSE;  // 0x0300077C

void FUN_08230e30(u16 id, void* r1, s32 r2);
bool32 FUN_082326d8(void);

void FUN_082326a0(void) {
  void* p = Malloc(sizeof(Unk030046a4));
  ClearMemory(p, sizeof(Unk030046a4));
  FUN_08230e30(0x56C2, p, 1);
  gCollisionMap = p;
  FUN_082326d8();
}

NAKED bool32 FUN_082326d8(void) { INCFUNC("asm/func/FUN_082326d8.inc"); }

NAKED void FUN_0823273c(void) { INCFUNC("asm/func/FUN_0823273c.inc"); }

NAKED void FUN_08232760(void) { INCFUNC("asm/func/FUN_08232760.inc"); }

void UpdateMapSize_0823279c(void) {
  gMapBlockW = (gCollisionMap->tiledata)->width;
  gMapBlockH = (gCollisionMap->tiledata)->height;
}

s32 FUN_082327c0(FileID id) {
  gCollisionMap->tiledata = GetFile(0xAE1B, id);  // これNULLを返すっぽいけど...
  FUN_0823273c();
  FUN_08232760();
  UpdateMapSize_0823279c();
  return 0;
}

void FUN_082327f0(CollisionMapTileData* tiledata) {
  gCollisionMap->tiledata = tiledata;
  FUN_0823273c();
  FUN_08232760();
  UpdateMapSize_0823279c();
}

NAKED void FUN_0823280c(unknown* p, Vec3* pos) { INCFUNC("asm/func/FUN_0823280c.inc"); }

NAKED s32 FUN_08232888(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_08232888.inc"); }

NAKED u16 FUN_082328ec(Vec3* pos) { INCFUNC("asm/func/FUN_082328ec.inc"); }

NAKED u16 FUN_0823297c(Vec3* pos) { INCFUNC("asm/func/FUN_0823297c.inc"); }

NAKED u16 FUN_082329e0(Vec3* pos1, Vec3* pos2) { INCFUNC("asm/func/FUN_082329e0.inc"); }

NAKED bool32 FUN_08232b00(Vec3* pos1, Vec3* pos2, u8 val) { INCFUNC("asm/func/FUN_08232b00.inc"); }

INCASM("asm/code_082326a0.inc");

NAKED s32 FUN_08234b1c(void) { INCFUNC("asm/func/FUN_08234b1c.inc"); }

void FUN_08234bd8(void* p) { ClearMemory(p, 44); }

NAKED s32 FUN_08234be4(void) { INCFUNC("asm/func/FUN_08234be4.inc"); }

NAKED void FUN_08234cf8(u16 param_1, u16* param_2) { INCFUNC("asm/func/FUN_08234cf8.inc"); }

NAKED void FUN_08234d24(u16 param_1, u16* param_2) { INCFUNC("asm/func/FUN_08234d24.inc"); }

NAKED void FUN_08234d50(u16 param_1, Vec3* pos) { INCFUNC("asm/func/FUN_08234d50.inc"); }

NAKED s32 FUN_08234db8(FileID id) { INCFUNC("asm/func/FUN_08234db8.inc"); }

INCASM("asm/code_082326a0_part2.inc");
