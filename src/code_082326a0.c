#include "collision_map.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "mover.h"
#include "registry.h"

IWRAM_DATA bool32 bool32_0300077c = FALSE;  // 0x0300077C

bool32 FUN_082326d8(void);

void FUN_082326a0(void) {
  CollisionMapData* p = Malloc(sizeof(CollisionMapData));
  ClearMemory(p, sizeof(CollisionMapData));
  Registry_Add(0x56C2, p, 1);
  gCollisionMap = p;
  FUN_082326d8();
}

NAKED bool32 FUN_082326d8(void) { INCFUNC("asm/func/FUN_082326d8.inc"); }

// 隣接タイルへの索引差分を -w / 1 / w / -1 で埋める
void FUN_0823273c(void) {
  CollisionMapTileData* tiledata = gCollisionMap->tiledata;

  gCollisionMap->neighborOffsets[0] = -tiledata->width;
  gCollisionMap->neighborOffsets[1] = 1;
  gCollisionMap->neighborOffsets[2] = tiledata->width;
  gCollisionMap->neighborOffsets[3] = -1;
}

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

NAKED void FUN_0823280c(MoverTile* p, Vec3* pos) { INCFUNC("asm/func/FUN_0823280c.inc"); }

NAKED s32 FUN_08232888(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_08232888.inc"); }

NAKED u16 FUN_082328ec(Vec3* pos) { INCFUNC("asm/func/FUN_082328ec.inc"); }

NAKED u16 FUN_0823297c(Vec3* pos) { INCFUNC("asm/func/FUN_0823297c.inc"); }

NAKED u16 FUN_082329e0(Vec3* pos1, Vec3* pos2) { INCFUNC("asm/func/FUN_082329e0.inc"); }

NAKED bool32 FUN_08232b00(Vec3* pos1, Vec3* pos2, u8 val) { INCFUNC("asm/func/FUN_08232b00.inc"); }

NAKED s32 FUN_08232df8(unknown* param_1, unknown* param_2, unknown* param_3, u8 param_4) { INCFUNC("asm/func/FUN_08232df8.inc"); }

NAKED void FUN_082332f8(unknown* param_1, s32 param_2, unknown* param_3) { INCFUNC("asm/func/FUN_082332f8.inc"); }

NAKED void FUN_08233428(unknown* param_1, unknown* param_2, unknown* param_3, s32 param_4, u8 param_5) { INCFUNC("asm/func/FUN_08233428.inc"); }

NAKED void FUN_0823349c(MoverTile* p, Vec3* pos, Vec3* delta, u16 sizeX, u16 sizeZ, u8 unk_4) { INCFUNC("asm/func/FUN_0823349c.inc"); }

NAKED s32 FUN_08233d50(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_08233d50.inc"); }

NAKED s32 FUN_082340c8(unknown* param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_082340c8.inc"); }

void FUN_08234208(MapTileOverride* p, u16 tileIdx, u32 param_3, u32 param_4, u8 param_5, u16 param_6) {
  p->tileIdx = tileIdx;
  p->unk_0 = 0;
  p->height = (param_3 << 4) | param_4;
  p->unk_5 = param_5;
  p->unk_6 = param_6;
}

NAKED MapTileOverride* FUN_08234224(u32 tileIdx, u32 mask) { INCFUNC("asm/func/FUN_08234224.inc"); }

NAKED s32 FUN_08234270(MapTileOverride* p, u16 tileIdx, u32 param_3, u32 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_08234270.inc"); }

// 衝突マップのタイル上書きリストからノードを外す
void FUN_082342a8(MapTileOverride* p) {
  MapTileOverride* prev = p->prev;
  MapTileOverride* next = p->next;

  if (prev != NULL) {
    prev->next = next;
  } else {
    gCollisionMap->tileOverrides = next;
  }

  if (next != NULL) {
    next->prev = prev;
  }
}

NAKED s32 FUN_082342cc(unknown* param_1, unknown* param_2) { INCFUNC("asm/func/FUN_082342cc.inc"); }

bool32 FUN_082345ec(void) { return bool32_0300077c; }

s32 FUN_082345f8(FileID id) {
  gCollisionMap->zones = GetFile(0xDCFB, id);
  bool32_0300077c = FALSE;
  return 0;
}

void FUN_08234624(ZoneData* zones) {
  gCollisionMap->zones = zones;
  bool32_0300077c = FALSE;
}

NAKED void FUN_0823463c(unknown* p) { INCFUNC("asm/func/FUN_0823463c.inc"); }

NAKED void FUN_08234660(unknown* p) { INCFUNC("asm/func/FUN_08234660.inc"); }

NAKED void FUN_08234868(unknown* param_1, CollisionMapEvent* ev, u32 param_3) { INCFUNC("asm/func/FUN_08234868.inc"); }

// id を持つゾーンが1つでもあるか
bool32 FUN_082348f8(ZoneID16 id) {
  s32 i;

  for (i = 0; i < gCollisionMap->zones->count; i++) {
    if (gCollisionMap->zones->zones[i].id == id) {
      return TRUE;
    }
  }
  return FALSE;
}

// id を持つゾーンのうち最初の1つを返し、同じIDのゾーンの数を count に書く
Zone* FindZonesByID(ZoneID16 id, u16* count) {
  Zone* first;
  s32 i;

  *count = 0;
  first = NULL;
  for (i = 0; i < gCollisionMap->zones->count; i++) {
    Zone* zone = &gCollisionMap->zones->zones[i];

    if (zone->id == id) {
      if (first == NULL) {
        first = zone;
      }
      (*count)++;
    }
  }
  return first;
}

NAKED CollisionMapEvent* FUN_08234980(u32 id) { INCFUNC("asm/func/FUN_08234980.inc"); }

NAKED void FUN_082349b8(CollisionMapEvent* ev, u32 param_2) { INCFUNC("asm/func/FUN_082349b8.inc"); }

NAKED s32 FUN_08234b1c(void) { INCFUNC("asm/func/FUN_08234b1c.inc"); }

void FUN_08234bd8(CollisionMapEvent* ev) { ClearMemory(ev, sizeof(CollisionMapEvent)); }

NAKED s32 FUN_08234be4(void) { INCFUNC("asm/func/FUN_08234be4.inc"); }

// ゾーンの左上隅を Vec3 の単位 (z は 16 倍) で取り出す
void FUN_08234cf8(u16 id, u16* out) {
  u16 count;
  Zone* zone = FindZonesByID(id, &count);

  if (zone != NULL) {
    out[0] = zone->x1;
    out[1] = zone->z1 << 4;
    out[2] = zone->y1;
  }
}

// ゾーンの右下隅を Vec3 の単位 (z は 16 倍) で取り出す
void FUN_08234d24(u16 id, u16* out) {
  u16 count;
  Zone* zone = FindZonesByID(id, &count);

  if (zone != NULL) {
    out[0] = zone->x2;
    out[1] = zone->z2 << 4;
    out[2] = zone->y2;
  }
}

NAKED bool8 FUN_08234d50(u16 areaFileId, Vec3* pos) { INCFUNC("asm/func/FUN_08234d50.inc"); }

s32 FUN_08234db8(FileID id) {
  gCollisionMap->paths = GetFile(0xD4FB, id);
  return 0;
}

void FUN_08234ddc(PathData* paths) { gCollisionMap->paths = paths; }

NAKED bool32 FUN_08234de8(unknown* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_08234de8.inc"); }

NAKED bool32 FUN_08234e3c(unknown* p) { INCFUNC("asm/func/FUN_08234e3c.inc"); }

NAKED s32 FUN_08234e78(unknown* param_1, s32 param_2, unknown* param_3, s32 param_4) { INCFUNC("asm/func/FUN_08234e78.inc"); }

Path* FUN_08234f44(u8 idx) {
  PathData* d = gCollisionMap->paths;

  if (idx >= d->pathCount) return NULL;

  return &d->paths[idx];
}

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

// パス pathIdx の nodeIdx 番目のノードの座標を *dst に入れる
s32 FUN_08234f90(Vec3* dst, u8 pathIdx, u8 nodeIdx) {
  PathNode* nodes = FUN_08234f6c(FUN_08234f44(pathIdx));

  if (nodes == NULL) {
    dst->x = 0;
    dst->z = 0;
    return -1;
  }

  FUN_08234f80(dst, nodes, nodeIdx);
  return 0;
}

NAKED s32 FUN_08234fc8(void) { INCFUNC("asm/func/FUN_08234fc8.inc"); }

NAKED s32 FUN_08235038(unknown* param_1, Vec3* pos, unknown* param_3, s32 param_4) { INCFUNC("asm/func/FUN_08235038.inc"); }

NAKED s32 FUN_08235090(Vec3* dst, u8 param_2) { INCFUNC("asm/func/FUN_08235090.inc"); }

NAKED s32 FUN_08235178(Vec3* dst, Vec3* pos, u8 param_3) { INCFUNC("asm/func/FUN_08235178.inc"); }

NAKED s32 FUN_082352c0(Vec3* dst, Vec3* pos, u8 param_3) { INCFUNC("asm/func/FUN_082352c0.inc"); }

NAKED s32 FUN_08235408(Vec3* dst, Vec3* pos, u8 param_3) { INCFUNC("asm/func/FUN_08235408.inc"); }

NAKED s32 FUN_0823556c(Vec3* dst, Vec3* pos, u8 param_3) { INCFUNC("asm/func/FUN_0823556c.inc"); }

NAKED s32 FUN_082356c4(Vec3* dst, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_082356c4.inc"); }

NAKED s32 FUN_0823585c(Vec3* dst, Vec3* pos, u32 kind, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_0823585c.inc"); }

NON_MATCH s32 FUN_082358f4(FileID id) {
#ifdef NONMATCHING_C
  gCollisionMap->navMesh = GetFile(0xF63B, id);
  return 0;
#else
  INCFUNC("asm/func/FUN_082358f4.inc");
#endif
}

void FUN_08235918(NavMesh* navMesh) { gCollisionMap->navMesh = navMesh; }

NAKED bool32 FUN_08235924(struct NavRect* rects, Vec3* pos, u32 idx) { INCFUNC("asm/func/FUN_08235924.inc"); }

NAKED u16 FUN_0823595c(u16* distanceMap, u16 n, s32 a, s32 b) { INCFUNC("asm/func/FUN_0823595c.inc"); }

NAKED s32 FUN_0823599c(unknown* param_1, s32 param_2, Vec3* pos) { INCFUNC("asm/func/FUN_0823599c.inc"); }

NAKED s32 FUN_08235a84(unknown* param_1, Vec3* param_2, Vec3* param_3) { INCFUNC("asm/func/FUN_08235a84.inc"); }

NAKED s32 FUN_08235f40(unknown* param_1, Vec3* param_2, Vec3* param_3) { INCFUNC("asm/func/FUN_08235f40.inc"); }

void FUN_08235fd0(u16* p) { *p = 0; }

bool32 FUN_08235fd8(u16* p) {
  if (*p & 2) {
    *p &= ~2;
    return TRUE;
  }

  return FALSE;
}

NAKED void FUN_08235ffc(NavMesh* navMesh, unknown* param_2, Vec3* pos) { INCFUNC("asm/func/FUN_08235ffc.inc"); }

NAKED void FUN_08236130(NavMesh* navMesh, unknown* param_2, Vec3* pos) { INCFUNC("asm/func/FUN_08236130.inc"); }

NAKED void FUN_08236268(unknown* param_1, Vec3* pos) { INCFUNC("asm/func/FUN_08236268.inc"); }

NAKED s32 FUN_0823629c(Vec3* pos) { INCFUNC("asm/func/FUN_0823629c.inc"); }

NAKED s32 FUN_082362fc(unknown* param_1, Vec3* pos) { INCFUNC("asm/func/FUN_082362fc.inc"); }
