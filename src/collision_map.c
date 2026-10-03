#include "collision_map.h"

#include "file.h"
#include "global.h"
#include "malloc.h"
#include "mover.h"
#include "registry.h"

IWRAM_DATA bool32 bool32_0300077c = FALSE;  // 0x0300077C

bool32 Map_ResetCollisionMap(void);
void Map_ClearEvent(CollisionMapEvent* ev);
extern u32 gNextMapEventID;  // src/iwram2.c

void Map_InitCollisionMap(void) {
  CollisionMapData* p = Malloc(sizeof(CollisionMapData));
  ClearMemory(p, sizeof(CollisionMapData));
  Registry_Add(0x56C2, p, 1);
  gCollisionMap = p;
  Map_ResetCollisionMap();
}

// 読み込み済みのコリジョンマップを空にする, navMesh だけは消さない
bool32 Map_ResetCollisionMap(void) {
  s32 i;

  if (gCollisionMap == NULL) {
    return FALSE;
  }

  gCollisionMap->tiledata = NULL;
  gCollisionMap->unk_8 = 0;
  gCollisionMap->zones = NULL;
  gCollisionMap->paths = NULL;
  gCollisionMap->tileOverrides = NULL;
  gNextMapEventID = 0;
  gCollisionMap->eventCount = 0;

  for (i = 0; i < 64; i++) {
    Map_ClearEvent(&gCollisionMap->events[i]);
    gCollisionMap->unk_d24[i] = 0;
  }
  return TRUE;
}

// 隣接タイルへの索引差分を -w / 1 / w / -1 で埋める
void Map_BuildNeighborOffsets(void) {
  CollisionMapTileData* tiledata = gCollisionMap->tiledata;

  gCollisionMap->neighborOffsets[0] = -tiledata->width;
  gCollisionMap->neighborOffsets[1] = 1;
  gCollisionMap->neighborOffsets[2] = tiledata->width;
  gCollisionMap->neighborOffsets[3] = -1;
}

// 行ごとのタイル索引オフセット表を作る, rowOffsets[z] = z * width
// 残差1命令: 原典は rowOffsets の先頭を1本のレジスタに残したままカーソルへ複写する, こちらは先頭をそのままカーソルに使う
// Tier A/B と C の添字形・guard+do/while は試済
NON_MATCH void Map_BuildRowOffsets(void) {
#ifdef NONMATCHING_C
  s32 width = gCollisionMap->tiledata->width;
  u16* dst = gCollisionMap->rowOffsets;
  s32 offset = 0;
  s32 i;

  for (i = 0; i < gCollisionMap->tiledata->height; i++) {
    *dst = offset;
    offset += width;
    dst++;
  }
#else
  INCFUNC("asm/func/Map_BuildRowOffsets.inc");
#endif
}

void UpdateMapSize_0823279c(void) {
  gMapBlockW = (gCollisionMap->tiledata)->width;
  gMapBlockH = (gCollisionMap->tiledata)->height;
}

s32 Map_LoadTileData(FileID id) {
  gCollisionMap->tiledata = GetFile(0xAE1B, id);  // これNULLを返すっぽいけど...
  Map_BuildNeighborOffsets();
  Map_BuildRowOffsets();
  UpdateMapSize_0823279c();
  return 0;
}

void Map_SetTileData(CollisionMapTileData* tiledata) {
  gCollisionMap->tiledata = tiledata;
  Map_BuildNeighborOffsets();
  Map_BuildRowOffsets();
  UpdateMapSize_0823279c();
}

NAKED void FUN_0823280c(MoverTile* p, Vec3* pos) { INCFUNC("asm/func/FUN_0823280c.inc"); }

NAKED s32 FUN_08232888(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_08232888.inc"); }

NAKED u16 FUN_082328ec(Vec3* pos) { INCFUNC("asm/func/FUN_082328ec.inc"); }

// pos のタイルの obj と stairs/height を1語で返す, マップ外なら tiles[0] の値
u16 Map_GetTileObjAndHeight(Vec3* pos) {
  CollisionMapTileData* td;
  s32 bx;
  s32 bz;
  s32 idx;

  if (gCollisionMap->tiledata == NULL) {
    return 0;
  }

  td = gCollisionMap->tiledata;
  bx = (s8)(pos->x >> 8);
  bz = (s8)(pos->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  return *(u16*)&td->tiles[idx].obj;
}

NAKED u16 FUN_082329e0(Vec3* pos1, Vec3* pos2) { INCFUNC("asm/func/FUN_082329e0.inc"); }

NAKED bool32 FUN_08232b00(Vec3* pos1, Vec3* pos2, u8 val) { INCFUNC("asm/func/FUN_08232b00.inc"); }

NAKED s32 FUN_08232df8(unknown* param_1, unknown* param_2, unknown* param_3, u8 param_4) { INCFUNC("asm/func/FUN_08232df8.inc"); }

NAKED void FUN_082332f8(unknown* param_1, s32 param_2, unknown* param_3) { INCFUNC("asm/func/FUN_082332f8.inc"); }

NAKED void FUN_08233428(unknown* param_1, unknown* param_2, unknown* param_3, s32 param_4, u8 param_5) { INCFUNC("asm/func/FUN_08233428.inc"); }

NAKED void FUN_0823349c(MoverTile* p, Vec3* pos, Vec3* delta, u16 sizeX, u16 sizeZ, u8 unk_4) { INCFUNC("asm/func/FUN_0823349c.inc"); }

NAKED s32 FUN_08233d50(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_08233d50.inc"); }

NAKED s32 FUN_082340c8(unknown* param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_082340c8.inc"); }

void Map_InitTileOverride(MapTileOverride* p, s32 tileIdx, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
  p->tileIdx = tileIdx;
  p->flags = 0;
  p->height = (param_3 << 4) | param_4;
  p->unk_5 = param_5;
  p->unk_6 = param_6;
}

// tileIdx の上書き情報のうち、mask のビットを持たず height の下位4bitが最大のものを返す
MapTileOverride* Map_FindTileOverride(u32 tileIdx, u32 mask) {
  MapTileOverride* p = gCollisionMap->tileOverrides;
  MapTileOverride* best = NULL;

  while (p != NULL) {
    if (!(p->flags & mask) && p->tileIdx == tileIdx) {
      if (best == NULL || (best->height & 0xF) < (p->height & 0xF)) {
        best = p;
      }
    }

    p = p->next;
  }
  return best;
}

// 上書き情報を初期化して、コリジョンマップが持つ双方向リストの先頭に繋ぐ
s32 Map_AddTileOverride(MapTileOverride* p, s32 tileIdx, s32 param_3, s32 height, s32 param_5, s32 param_6) {
  Map_InitTileOverride(p, tileIdx, param_3, height, param_5, param_6);
  p->prev = NULL;
  p->next = gCollisionMap->tileOverrides;
  if (p->next != NULL) {
    p->next->prev = p;
  }

  gCollisionMap->tileOverrides = p;
  return 0;
}

// 衝突マップのタイル上書きリストからノードを外す
void Map_RemoveTileOverride(MapTileOverride* p) {
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

s32 Map_LoadZones(FileID id) {
  gCollisionMap->zones = GetFile(0xDCFB, id);
  bool32_0300077c = FALSE;
  return 0;
}

void Map_SetZones(ZoneData* zones) {
  gCollisionMap->zones = zones;
  bool32_0300077c = FALSE;
}

NAKED void FUN_0823463c(unknown* p) { INCFUNC("asm/func/FUN_0823463c.inc"); }

NAKED void FUN_08234660(unknown* p) { INCFUNC("asm/func/FUN_08234660.inc"); }

NAKED void FUN_08234868(unknown* param_1, CollisionMapEvent* ev, u32 param_3) { INCFUNC("asm/func/FUN_08234868.inc"); }

// id を持つゾーンが1つでもあるか
bool32 Map_HasZoneByID(ZoneID16 id) {
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

// id を持つイベントを返す, 無ければ NULL, 件数に events ではなく zones の件数を使っている
CollisionMapEvent* Map_FindEventByID(u32 id) {
  s32 i;

  for (i = 0; i < gCollisionMap->zones->count; i++) {
    if (gCollisionMap->events[i].id == id) {
      return &gCollisionMap->events[i];
    }
  }
  return NULL;
}

NAKED void Map_InsertEvent(CollisionMapEvent* ev, u32 param_2) { INCFUNC("asm/func/Map_InsertEvent.inc"); }

NAKED s32 FUN_08234b1c(void) { INCFUNC("asm/func/FUN_08234b1c.inc"); }

void Map_ClearEvent(CollisionMapEvent* ev) { ClearMemory(ev, sizeof(CollisionMapEvent)); }

NAKED s32 FUN_08234be4(void) { INCFUNC("asm/func/FUN_08234be4.inc"); }

// ゾーンの左上隅を Vec3 の単位 (z は 16 倍) で取り出す
void Map_GetZoneMin(u16 id, u16* out) {
  u16 count;
  Zone* zone = FindZonesByID(id, &count);

  if (zone != NULL) {
    out[0] = zone->x1;
    out[1] = zone->z1 << 4;
    out[2] = zone->y1;
  }
}

// ゾーンの右下隅を Vec3 の単位 (z は 16 倍) で取り出す
void Map_GetZoneMax(u16 id, u16* out) {
  u16 count;
  Zone* zone = FindZonesByID(id, &count);

  if (zone != NULL) {
    out[0] = zone->x2;
    out[1] = zone->z2 << 4;
    out[2] = zone->y2;
  }
}

NAKED bool8 FUN_08234d50(u16 areaFileId, Vec3* pos) { INCFUNC("asm/func/FUN_08234d50.inc"); }

s32 Map_LoadPaths(FileID id) {
  gCollisionMap->paths = GetFile(0xD4FB, id);
  return 0;
}

void Map_SetPaths(PathData* paths) { gCollisionMap->paths = paths; }

NAKED bool32 FUN_08234de8(unknown* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_08234de8.inc"); }

NAKED bool32 FUN_08234e3c(unknown* p) { INCFUNC("asm/func/FUN_08234e3c.inc"); }

NAKED s32 FUN_08234e78(unknown* param_1, s32 param_2, unknown* param_3, s32 param_4) { INCFUNC("asm/func/FUN_08234e78.inc"); }

Path* Map_GetPath(u8 idx) {
  PathData* d = gCollisionMap->paths;

  if (idx >= d->pathCount) return NULL;

  return &d->paths[idx];
}

// その経路の先頭ノードを指す
PathNode* Map_GetPathNodes(Path* path) {
  u8* base = (u8*)gCollisionMap->paths;

  return (PathNode*)(base + path->nodeOffset);
}

// 経路ノードの座標を Vec3 の X/Z に取り出す
void Map_ReadPathNodePos(Vec3* dst, PathNode* nodes, u8 idx) {
  dst->x = nodes[idx].x;
  dst->z = nodes[idx].y;
}

// パス pathIdx の nodeIdx 番目のノードの座標を *dst に入れる
s32 Map_GetPathNodePos(Vec3* dst, u8 pathIdx, u8 nodeIdx) {
  PathNode* nodes = Map_GetPathNodes(Map_GetPath(pathIdx));

  if (nodes == NULL) {
    dst->x = 0;
    dst->z = 0;
    return -1;
  }

  Map_ReadPathNodePos(dst, nodes, nodeIdx);
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

NON_MATCH s32 Map_LoadNavMesh(FileID id) {
#ifdef NONMATCHING_C
  gCollisionMap->navMesh = GetFile(0xF63B, id);
  return 0;
#else
  INCFUNC("asm/func/Map_LoadNavMesh.inc");
#endif
}

void Map_SetNavMesh(NavMesh* navMesh) { gCollisionMap->navMesh = navMesh; }

// pos が rects[idx] の矩形の中にあるか, 矩形は1タイル単位なので 8bit 左シフトして比べる
bool32 Map_IsPosInNavRect(struct NavRect* rects, Vec3* pos, u32 idx) {
  struct NavRect* rect = &rects[idx];

  if (pos->x >= (rect->minX << 8) && pos->x < (rect->maxX << 8) && pos->z >= (rect->minY << 8) && pos->z < (rect->maxY << 8)) {
    return TRUE;
  }
  return FALSE;
}

// a と b の距離を distanceMap (上三角だけを詰めた行列) から引く, 同じなら 0
// 残差は最後の4命令のレジスタだけ (原典は引き算の結果を左辺のレジスタに残す), 命令数は31で一致, Tier A/B と C の lo/hi 変数化・複合代入は試済
NON_MATCH u16 Map_GetNavDistance(u16* distanceMap, u16 n, s32 a, s32 b) {
#ifdef NONMATCHING_C
  s32 idx;

  if (a == b) {
    return 0;
  }

  if (a <= b) {
    idx = a * n + b - ((a + 2) * (a + 1) >> 1);
  } else {
    idx = b * n + a - ((b + 2) * (b + 1) >> 1);
  }

  return distanceMap[idx];
#else
  INCFUNC("asm/func/Map_GetNavDistance.inc");
#endif
}

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
