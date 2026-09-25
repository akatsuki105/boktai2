#include "collision_map.h"
#include "file.h"
#include "global.h"
#include "malloc.h"

IWRAM_DATA bool32 bool32_0300077c = FALSE;  // 0x0300077C

void FUN_08230e30(u16 id, void* r1, s32 r2);
bool32 FUN_082326d8(void);

void FUN_082326a0(void) {
  CollisionMapData* p = Malloc(sizeof(CollisionMapData));
  ClearMemory(p, sizeof(CollisionMapData));
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

NAKED s32 FUN_08232df8(unknown* param_1, unknown* param_2, unknown* param_3, u8 param_4) { INCFUNC("asm/func/FUN_08232df8.inc"); }

NAKED void FUN_082332f8(unknown* param_1, s32 param_2, unknown* param_3) { INCFUNC("asm/func/FUN_082332f8.inc"); }

NAKED void FUN_08233428(unknown* param_1, unknown* param_2, unknown* param_3, s32 param_4, u8 param_5) { INCFUNC("asm/func/FUN_08233428.inc"); }

NAKED void FUN_0823349c(void* param_1, Vec3* pos, Vec3* delta, u16 unk_1c, u16 unk_1e, u8 unk_4) { INCFUNC("asm/func/FUN_0823349c.inc"); }

NAKED s32 FUN_08233d50(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_08233d50.inc"); }

NAKED s32 FUN_082340c8(unknown* param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_082340c8.inc"); }

NAKED void FUN_08234208(MapTileOverride* p, u16 tileIdx, u32 param_3, u32 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_08234208.inc"); }

NAKED MapTileOverride* FUN_08234224(u32 tileIdx, u32 mask) { INCFUNC("asm/func/FUN_08234224.inc"); }

NAKED s32 FUN_08234270(MapTileOverride* p, u16 tileIdx, u32 param_3, u32 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_08234270.inc"); }

NAKED void FUN_082342a8(MapTileOverride* p) { INCFUNC("asm/func/FUN_082342a8.inc"); }

NAKED s32 FUN_082342cc(unknown* param_1, unknown* param_2) { INCFUNC("asm/func/FUN_082342cc.inc"); }

bool32 FUN_082345ec(void) { return bool32_0300077c; }

NAKED s32 FUN_082345f8(FileID id) { INCFUNC("asm/func/FUN_082345f8.inc"); }

NAKED void FUN_08234624(ZoneData* zones) { INCFUNC("asm/func/FUN_08234624.inc"); }

NAKED void FUN_0823463c(unknown* p) { INCFUNC("asm/func/FUN_0823463c.inc"); }

NAKED void FUN_08234660(unknown* p) { INCFUNC("asm/func/FUN_08234660.inc"); }

NAKED void FUN_08234868(unknown* param_1, CollisionMapEvent* ev, u32 param_3) { INCFUNC("asm/func/FUN_08234868.inc"); }

NAKED bool32 FUN_082348f8(u16 zoneID) { INCFUNC("asm/func/FUN_082348f8.inc"); }

NAKED Zone* FUN_0823492c(u16 zoneID, u16* count) { INCFUNC("asm/func/FUN_0823492c.inc"); }

NAKED CollisionMapEvent* FUN_08234980(u32 id) { INCFUNC("asm/func/FUN_08234980.inc"); }

NAKED void FUN_082349b8(CollisionMapEvent* ev, u32 param_2) { INCFUNC("asm/func/FUN_082349b8.inc"); }

NAKED s32 FUN_08234b1c(void) { INCFUNC("asm/func/FUN_08234b1c.inc"); }

void FUN_08234bd8(CollisionMapEvent* ev) { ClearMemory(ev, sizeof(CollisionMapEvent)); }

NAKED s32 FUN_08234be4(void) { INCFUNC("asm/func/FUN_08234be4.inc"); }

NAKED void FUN_08234cf8(u16 param_1, u16* param_2) { INCFUNC("asm/func/FUN_08234cf8.inc"); }

NAKED void FUN_08234d24(u16 param_1, u16* param_2) { INCFUNC("asm/func/FUN_08234d24.inc"); }

NAKED bool8 FUN_08234d50(u16 areaFileId, Vec3* pos) { INCFUNC("asm/func/FUN_08234d50.inc"); }

NAKED s32 FUN_08234db8(FileID id) { INCFUNC("asm/func/FUN_08234db8.inc"); }

void FUN_08234ddc(PathData* paths) { gCollisionMap->paths = paths; }

NAKED bool32 FUN_08234de8(unknown* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_08234de8.inc"); }

NAKED bool32 FUN_08234e3c(unknown* p) { INCFUNC("asm/func/FUN_08234e3c.inc"); }

NAKED s32 FUN_08234e78(unknown* param_1, s32 param_2, unknown* param_3, s32 param_4) { INCFUNC("asm/func/FUN_08234e78.inc"); }

NAKED Path* FUN_08234f44(u8 idx) { INCFUNC("asm/func/FUN_08234f44.inc"); }

// その経路の先頭ノードを指す
PathNode* FUN_08234f6c(Path* path) {
  u8* base = (u8*)gCollisionMap->paths;

  return (PathNode*)(base + path->nodeOffset);
}

// 経路ノードの座標を Vec3 の X/Z に取り出す
void FUN_08234f80(Vec3* dst, PathNode* nodes, u8 idx) {
  dst->x = nodes[idx].x;
  dst->z = nodes[idx].y;
}

NAKED s32 FUN_08234f90(Vec3* dst, u8 pathIdx, u8 nodeIdx) { INCFUNC("asm/func/FUN_08234f90.inc"); }

NAKED s32 FUN_08234fc8(void) { INCFUNC("asm/func/FUN_08234fc8.inc"); }

NAKED s32 FUN_08235038(unknown* param_1, Vec3* pos, unknown* param_3, s32 param_4) { INCFUNC("asm/func/FUN_08235038.inc"); }

NAKED s32 FUN_08235090(Vec3* dst, u8 param_2) { INCFUNC("asm/func/FUN_08235090.inc"); }

NAKED s32 FUN_08235178(Vec3* dst, Vec3* pos, u8 param_3) { INCFUNC("asm/func/FUN_08235178.inc"); }

NAKED s32 FUN_082352c0(Vec3* dst, Vec3* pos, u8 param_3) { INCFUNC("asm/func/FUN_082352c0.inc"); }

NAKED s32 FUN_08235408(Vec3* dst, Vec3* pos, u8 param_3) { INCFUNC("asm/func/FUN_08235408.inc"); }

NAKED s32 FUN_0823556c(Vec3* dst, Vec3* pos, u8 param_3) { INCFUNC("asm/func/FUN_0823556c.inc"); }

NAKED s32 FUN_082356c4(Vec3* dst, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_082356c4.inc"); }

NAKED s32 FUN_0823585c(Vec3* dst, Vec3* pos, u32 kind, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_0823585c.inc"); }

NAKED s32 FUN_082358f4(FileID id) { INCFUNC("asm/func/FUN_082358f4.inc"); }

void FUN_08235918(NavMesh* navMesh) { gCollisionMap->navMesh = navMesh; }

NAKED bool32 FUN_08235924(struct NavRect* rects, Vec3* pos, u32 idx) { INCFUNC("asm/func/FUN_08235924.inc"); }

NAKED u16 FUN_0823595c(u16* distanceMap, u16 n, s32 a, s32 b) { INCFUNC("asm/func/FUN_0823595c.inc"); }

NAKED s32 FUN_0823599c(unknown* param_1, s32 param_2, Vec3* pos) { INCFUNC("asm/func/FUN_0823599c.inc"); }

NAKED s32 FUN_08235a84(unknown* param_1, Vec3* param_2, Vec3* param_3) { INCFUNC("asm/func/FUN_08235a84.inc"); }

NAKED s32 FUN_08235f40(unknown* param_1, Vec3* param_2, Vec3* param_3) { INCFUNC("asm/func/FUN_08235f40.inc"); }

void FUN_08235fd0(u16* p) { *p = 0; }

NAKED bool32 FUN_08235fd8(unknown* p) { INCFUNC("asm/func/FUN_08235fd8.inc"); }

NAKED void FUN_08235ffc(NavMesh* navMesh, unknown* param_2, Vec3* pos) { INCFUNC("asm/func/FUN_08235ffc.inc"); }

NAKED void FUN_08236130(NavMesh* navMesh, unknown* param_2, Vec3* pos) { INCFUNC("asm/func/FUN_08236130.inc"); }

NAKED void FUN_08236268(unknown* param_1, Vec3* pos) { INCFUNC("asm/func/FUN_08236268.inc"); }

NAKED s32 FUN_0823629c(Vec3* pos) { INCFUNC("asm/func/FUN_0823629c.inc"); }

NAKED s32 FUN_082362fc(unknown* param_1, Vec3* pos) { INCFUNC("asm/func/FUN_082362fc.inc"); }
