#include "collision_map.h"

#include "file.h"
#include "global.h"
#include "malloc.h"
#include "mover.h"
#include "random.h"
#include "registry.h"
#include "vm.h"

IWRAM_DATA bool32 bool32_0300077c = FALSE;  // 0x0300077C

bool32 Map_ResetCollisionMap(void);
void Map_ClearEvent(CollisionMapEvent* ev);
s32 FUN_0823a88c(u8* pc, ScriptArgs* args);                      // src/entity_0823acbc.c
s32 VM_ExecById_Proxy_0823a8a4(u32 scriptID, ScriptArgs* args);  // src/entity_0823acbc.c
extern u32 gNextMapEventID;                                      // src/iwram2.c

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

// このゲームでこの関数が呼ばれることはない
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

// pos のタイルを MoverTile に取り込む, 前と今を同じ値で埋める
void Map_InitMoverTile(MoverTile* p, Vec3* pos) {
  CollisionMapTileData* td;
  CollisionMapTile* tile;
  s32 bx;
  s32 bz;
  s32 idx;

  if (gCollisionMap->tiledata == NULL) {
    return;
  }

  td = gCollisionMap->tiledata;
  bx = (s8)(pos->x >> 8);
  bz = (s8)(pos->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  p->tileIdx[0] = p->tileIdx[1] = idx;

  tile = &td->tiles[p->tileIdx[1]];
  p->height[1] = tile->heightStairs & 0xF;
  p->stairs[1] = tile->heightStairs >> 4;
  p->attr[1] = tile->attr;
  p->height[0] = p->height[1];
  p->stairs[0] = p->stairs[1];
  p->attr[0] = p->attr[1];
}

// from から to へ 4タイル以内で真っ直ぐ行ける向きを 8bit の角度で返す, 無ければ -1
// 残差7命令: 原典は & 3 と & 0xFF をループ内で実際に計算し、配列先頭と定数2つを高位レジスタ (r8/r9/sl) に抱えている
// こちらは dir が 0..3 と分かるので agbcc が両方のマスクを畳んでしまう, マスクが残る書き方が未発見
NON_MATCH s32 Map_FindDirToTile(s32 from, s32 to) {
#ifdef NONMATCHING_C
  s32 angle = 0xC0;
  s32 dir;

  for (dir = 0; dir < 4; dir++) {
    s32 step = gCollisionMap->neighborOffsets[dir & 3];
    s32 idx = from;
    s32 i;

    for (i = 0; i < 4; i++) {
      idx += step;
      if (idx == to) {
        return (u8)angle;
      }
    }

    angle += 0x40;
  }
  return -1;
#else
  INCFUNC("asm/func/Map_FindDirToTile.inc");
#endif
}

// pos のタイルの高さを返す, 階段タイルなら上る向きの座標の端数ぶんだけ下げる
u16 Map_GetTileHeightAt(Vec3* pos) {
  MapTileOverride* ov;
  CollisionMapTile* tile;
  s32 stairs;
  s32 height;
  s32 bx;
  s32 bz;
  s32 idx;

  bx = (s8)(pos->x >> 8);
  bz = (s8)(pos->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }

  ov = Map_FindTileOverride(idx, 1);
  if (ov != NULL) {
    tile = &ov->tile;
  } else {
    tile = &gCollisionMap->tiledata->tiles[idx];
  }

  stairs = tile->heightStairs >> 4;
  height = (tile->heightStairs & 0xF) << 8;
  switch (stairs) {
    case 1: {
      height -= (u8)pos->z;
      break;
    }
    case 2: {
      height -= (u8)pos->x;
      break;
    }
  }
  return height;
}

// pos のタイルの attr を返す, マップ外なら tiles[0] の値
TileAttr Map_GetTileAttr(Vec3* pos) {
  CollisionMapTileData* td;
  CollisionMapTile* tile;
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
  tile = &td->tiles[idx];
  return tile->attr;
}

NAKED u16 FUN_082329e0(Vec3* pos1, Vec3* pos2) { INCFUNC("asm/func/FUN_082329e0.inc"); }

NAKED bool32 FUN_08232b00(Vec3* pos1, Vec3* pos2, u8 val) { INCFUNC("asm/func/FUN_08232b00.inc"); }

NAKED s32 FUN_08232df8(MoverTile* tile, Vec3* pos, Vec3* dst, u8 param_4) { INCFUNC("asm/func/FUN_08232df8.inc"); }

NAKED void FUN_082332f8(MoverTile* tile, Vec3* pos, Vec3* dst) { INCFUNC("asm/func/FUN_082332f8.inc"); }

// pos から offset だけ動いた先のタイルを MoverTile に反映する
// unused_4 と unused_5 は読まれていない
void FUN_08233428(MoverTile* tile, Vec3* pos, Vec3* offset, s32 unused_4, s32 unused_5, u8 param_6) {
  Vec3 dst;

  dst.x = pos->x + offset->x;
  dst.y = pos->y + offset->y;
  dst.z = pos->z + offset->z;
  dst.val = 16;
  tile->unk_0[0] = FUN_08232df8(tile, pos, &dst, param_6);
  FUN_082332f8(tile, pos, &dst);
}

NAKED void FUN_0823349c(MoverTile* p, Vec3* pos, Vec3* delta, u16 sizeX, u16 sizeZ, u8 unk_4) { INCFUNC("asm/func/FUN_0823349c.inc"); }

NAKED s32 FUN_08233d50(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_08233d50.inc"); }

NAKED s32 FUN_082340c8(unknown* param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_082340c8.inc"); }

void Map_InitTileOverride(MapTileOverride* p, s32 tileIdx, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
  p->tileIdx = tileIdx;
  p->flags = 0;
  p->tile.heightStairs = (param_3 << 4) | param_4;
  p->tile.obj = param_5;
  p->tile.attr = param_6;
}

// tileIdx の上書き情報のうち、mask のビットを持たず height の下位4bitが最大のものを返す
MapTileOverride* Map_FindTileOverride(u32 tileIdx, u32 mask) {
  MapTileOverride* p = gCollisionMap->tileOverrides;
  MapTileOverride* best = NULL;

  while (p != NULL) {
    if (!(p->flags & mask) && p->tileIdx == tileIdx) {
      if (best == NULL || (best->tile.heightStairs & 0xF) < (p->tile.heightStairs & 0xF)) {
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

// このゲームでこの関数が呼ばれることはない
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

NAKED void FUN_08234660(ZoneEventSource* src) { INCFUNC("asm/func/FUN_08234660.inc"); }

// ゾーンイベントのスクリプトを 14 個の引数付きで起動する
// 原典は args[2] から args[13] までを1本のカーソルで書くが, agbcc が先頭4本だけ固定オフセットに畳んでしまう
// 命令数は68で一致, 残差はその畳み込み1箇所のみ, Tier A-C は試済
NON_MATCH void Map_RunZoneEventScript(ZoneEventSource* src, CollisionMapEvent* ev, u16 msg) {
#ifdef NONMATCHING_C
  u32 args[14];
  ScriptArgs sa;
  u32* arg;
  s32 i;

  args[0] = src->id;
  args[1] = ev->zoneID;
  arg = &args[2];
  *arg++ = msg;
  *arg++ = src->pos->x;
  *arg++ = src->pos->y;
  *arg++ = src->pos->z;
  for (i = 0; i < 4; i++) {
    *arg++ = ev->args1[i];
  }
  for (i = 0; i < 4; i++) {
    *arg++ = ev->args2[i];
  }

  sa.argc = 14;
  sa.argv = args;
  if (ev->flags & 0x20) {
    VM_ExecById_Proxy_0823a8a4((u32)ev->scriptPC, &sa);
  } else {
    FUN_0823a88c(ev->scriptPC, &sa);
  }
#else
  INCFUNC("asm/func/Map_RunZoneEventScript.inc");
#endif
}

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

// スクリプトの 'n' 引数に並んだゾーンIDのイベントを events から取り除いて前へ詰める
// 命令数は84で一致, 残差はレジスタ割当のみ (原典は events を r4, unk_d24 を sl, 書き込み先のバイトオフセットを r3 に置く)
// Tier A/B と C の宣言順は試済
NON_MATCH s32 VM_Ctrl_RemoveZoneEvents(void) {
#ifdef NONMATCHING_C
  s32 count = gCollisionMap->eventCount;

  VM_SeekToNamedArg('n');
  while (VM_GetPC() != NULL) {
    CollisionMapEvent* events = gCollisionMap->events;
    u32* aux = gCollisionMap->unk_d24;
    s32 n = 0;
    u32 id = VM_GetValue();
    s32 i;

    for (i = 0; i < count; i++) {
      if (id != events[i].zoneID) {
        gCollisionMap->events[n] = events[i];
        gCollisionMap->unk_d24[n] = aux[i];
        n++;
      }
    }
    count = n;
  }

  gCollisionMap->eventCount = count;
  return 0;
#else
  INCFUNC("asm/func/VM_Ctrl_RemoveZoneEvents.inc");
#endif
}

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

// id のゾーンのどれかが pos を含んでいるか
bool8 Map_IsPosInZoneByID(ZoneID16 id, Vec3* pos) {
  u16 count;
  Zone* zone = FindZonesByID(id, &count);
  u16 i;

  if (zone == NULL) {
    return FALSE;
  }

  for (i = 0; i < count; i++) {
    if (pos->x >= zone->x1 && pos->x < zone->x2 && pos->z >= zone->y1 && pos->z < zone->y2) {
      return TRUE;
    }
    zone++;
  }
  return FALSE;
}

// このゲームでこの関数が呼ばれることはない
s32 Map_LoadPaths(FileID id) {
  gCollisionMap->paths = GetFile(0xD4FB, id);
  return 0;
}

void Map_SetPaths(PathData* paths) { gCollisionMap->paths = paths; }

// 経路をたどるカーソルを pathIdx / nodeIdx で初期化する
// 残差2命令: 原典は2回目の nodeCount をポインタと同じレジスタに読んで潰すため、先に path のコピーを1本持つ (callee-saved が1本多い)
NON_MATCH bool32 Map_InitPathWalker(PathWalker* p, u32 pathIdx, u32 param_3, u32 nodeIdx) {
#ifdef NONMATCHING_C
  PathData* d = gCollisionMap->paths;
  Path* path;
  PathNode* nodes;

  if (pathIdx >= d->pathCount) {
    return FALSE;
  }

  path = &d->paths[pathIdx];
  if ((u8)path->nodeCount == 0) {
    return FALSE;
  }

  if (nodeIdx >= (u8)path->nodeCount) {
    nodeIdx = 0;
  }

  nodes = (PathNode*)((u8*)d + path->nodeOffset);
  p->pathIdx = pathIdx;
  p->unk_1 = param_3;
  p->nodeIdx = nodeIdx;
  p->unk_3 = 0;
  p->path = path;
  p->node = &nodes[p->nodeIdx];
  return TRUE;
#else
  INCFUNC("asm/func/Map_InitPathWalker.inc");
#endif
}

// 次のノードへ進める, 末尾まで行ったら先頭に戻る
bool32 Map_AdvancePathWalker(PathWalker* p) {
  u8* base;
  PathNode* nodes;

  p->nodeIdx++;
  if (p->nodeIdx >= (u8)p->path->nodeCount) {
    p->nodeIdx = 0;
  }

  p->unk_3 = 0;
  base = (u8*)gCollisionMap->paths;
  nodes = (PathNode*)(base + p->path->nodeOffset);
  p->node = &nodes[p->nodeIdx];
  return TRUE;
}

// カーソルの指すノードへ向かう移動量を out に入れる, rx/rz の範囲内なら差分をそのまま入れて 1 を返す
s32 Map_GetStepToPathNode(PathWalker* w, Vec3* pos, Vec3* out, u8* outAngle, u32 rx, u32 rz, s32 speed) {
  PathNode* node = w->node;
  Vec3 nodePos;
  s32 dx;
  s32 dz;
  s32 sin;
  u8 angle;

  nodePos.x = node->x;
  nodePos.z = node->y;
  dx = nodePos.x - pos->x;
  dz = nodePos.z - pos->z;
  angle = ArcTan2_8(dx, dz);
  *outAngle = angle;
  if (abs(dx) <= rx && abs(dz) <= rz) {
    out->x = dx;
    out->z = dz;
    return 1;
  }

  sin = speed * gSineTable[(angle + 0x40) & 0xFF];
  if (sin >= 0) {
    out->x = sin >> 12;
  } else {
    out->x = -((-sin) >> 12);
  }
  sin = speed * gSineTable[angle];
  if (sin >= 0) {
    out->z = sin >> 12;
  } else {
    out->z = -((-sin) >> 12);
  }
  return 0;
}

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

// スクリプトから経路番号とノード番号を読み、そのノードの座標を配列変数に3つ書き込む
// 残差2命令: 原典は pos をスタック先頭 (sp+0)、desc を sp+8 に置くが、agbcc はこちらでは逆に並べる
// 宣言順の入れ替え・ブロック内宣言は効かなかった
NON_MATCH s32 VM_GetPathNodePos(void) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 pathIdx = VM_GetValue();
  s32 nodeIdx = VM_GetValue();
  u8 desc[8];

  if (Map_GetPathNodePos(&pos, pathIdx, nodeIdx) < 0) {
    return -1;
  }

  FUN_0823167c(desc);
  FUN_0823206c(desc, 0, pos.x);
  FUN_0823167c(desc);
  FUN_0823206c(desc, 0, pos.y);
  FUN_0823167c(desc);
  FUN_0823206c(desc, 0, pos.z);
  return 0;
#else
  INCFUNC("asm/func/VM_GetPathNodePos.inc");
#endif
}

// pos がカーソルの指すノードから rx, rz の範囲内にあるか調べる, 外なら 1
// 残差は nodePos.z のレジスタコピー1命令のみ (41/42), Tier A-C は試済
NON_MATCH s32 Map_IsPosOutsidePathNode(PathWalker* w, Vec3* pos, u32 rx, u32 rz) {
#ifdef NONMATCHING_C
  Vec3 nodePos;
  PathNode* node = w->node;

  nodePos.x = node->x;
  nodePos.z = node->y;
  if (abs(pos->x - nodePos.x) > rx) {
    return 1;
  }
  if (abs(pos->z - nodePos.z) > rz) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/Map_IsPosOutsidePathNode.inc");
#endif
}

// パス pathIdx のノードを1つランダムに選び, その座標と足元の高さを dst に入れてノード番号を返す
// 原典は (u8)path->nodeCount を2回読むが, agbcc が2回目を1回目の値で済ませてしまう (94/95)
// Tier A/B と C のガード分割は試済, 同種の CSE 残差は JudgementParticle_UpdateStill などにもある
NON_MATCH s32 Map_PickRandomPathNode(Vec3* dst, s32 pathIdx) {
#ifdef NONMATCHING_C
  Path* path = Map_GetPath(pathIdx);
  CollisionMapTile* tile;
  MapTileOverride* ov;
  s32 nodeIdx;
  s32 stairs;
  s32 height;
  s32 bx;
  s32 bz;
  s32 idx;

  if (path == NULL || (u8)path->nodeCount == 0) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return -1;
  }

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  nodeIdx = Mod(gRandomTable[gRandTableIdx], (u8)path->nodeCount);
  Map_GetPathNodePos(dst, pathIdx, nodeIdx);

  bx = (s8)(dst->x >> 8);
  bz = (s8)(dst->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }

  ov = Map_FindTileOverride(idx, 1);
  if (ov != NULL) {
    tile = &ov->tile;
  } else {
    tile = &gCollisionMap->tiledata->tiles[idx];
  }

  stairs = tile->heightStairs >> 4;
  height = (tile->heightStairs & 0xF) << 8;
  switch (stairs) {
    case 1: {
      height -= (u8)dst->z;
      break;
    }
    case 2: {
      height -= (u8)dst->x;
      break;
    }
  }
  dst->y = height;
  return nodeIdx;
#else
  INCFUNC("asm/func/Map_PickRandomPathNode.inc");
#endif
}

NAKED s32 FUN_08235178(Vec3* dst, Vec3* pos, s32 param_3) { INCFUNC("asm/func/FUN_08235178.inc"); }

NAKED s32 FUN_082352c0(Vec3* dst, Vec3* pos, s32 param_3) { INCFUNC("asm/func/FUN_082352c0.inc"); }

NAKED s32 FUN_08235408(Vec3* dst, Vec3* pos, s32 param_3) { INCFUNC("asm/func/FUN_08235408.inc"); }

NAKED s32 FUN_0823556c(Vec3* dst, Vec3* pos, s32 param_3) { INCFUNC("asm/func/FUN_0823556c.inc"); }

NAKED s32 FUN_082356c4(Vec3* dst, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_082356c4.inc"); }

// kind ごとの移動判定に振り分ける, どれも失敗したら Map_PickRandomPathNode で戻す
// 原典は param_5 の2乗を求めてから switch に入るが, その値をどこでも読まないので agbcc が消してしまう
// 残差はその4命令と dst/pos のレジスタ入れ替えのみ, Tier A-C は試済
NON_MATCH s32 FUN_0823585c(Vec3* dst, Vec3* pos, u32 kind, s32 param_4, s32 param_5, s32 param_6, s32 param_7) {
#ifdef NONMATCHING_C
  s32 ret = -1;

  switch (kind) {
    case 0: {
      ret = Map_PickRandomPathNode(dst, param_4);
      break;
    }
    case 1: {
      ret = FUN_08235178(dst, pos, param_4);
      break;
    }
    case 2: {
      ret = FUN_082352c0(dst, pos, param_4);
      break;
    }
    case 3: {
      ret = FUN_08235408(dst, pos, param_4);
      break;
    }
    case 4: {
      ret = FUN_0823556c(dst, pos, param_4);
      break;
    }
    case 5: {
      ret = FUN_082356c4(dst, param_6, param_7, param_4);
      break;
    }
  }

  if (ret < 0) {
    ret = Map_PickRandomPathNode(dst, param_4);
  }
  return ret;
#else
  INCFUNC("asm/func/FUN_0823585c.inc");
#endif
}

// このゲームでこの関数が呼ばれることはない
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

// pos を含むナビ島が agent->islandIdx と同じかを返す, 壁タイルの上なら FALSE
NAKED bool32 Map_IsPosInAgentIsland(NavAgent* agent, s32 param_2, Vec3* pos) { INCFUNC("asm/func/Map_IsPosInAgentIsland.inc"); }

NAKED s32 FUN_08235a84(NavAgent* agent, Vec3* param_2, Vec3* pos) { INCFUNC("asm/func/FUN_08235a84.inc"); }

// pos のタイルが壁なら進行をやめさせ, そうでなければ FUN_08235a84 に任せる
s32 FUN_08235f40(NavAgent* agent, Vec3* param_2, Vec3* pos) {
  CollisionMapTile* tile;
  MapTileOverride* ov;
  TileAttr attr;
  s32 bx;
  s32 bz;
  s32 idx;

  bx = (s8)(pos->x >> 8);
  bz = (s8)(pos->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }

  ov = Map_FindTileOverride(idx, 1);
  if (ov != NULL) {
    tile = &ov->tile;
  } else {
    tile = &gCollisionMap->tiledata->tiles[idx];
  }

  attr = tile->attr;
  if (attr & TATTR_WALL) {
    agent->flags = 0;
    return 0;
  }
  return FUN_08235a84(agent, param_2, pos);
}

void FUN_08235fd0(u16* p) { *p = 0; }

bool32 FUN_08235fd8(u16* p) {
  if (*p & 2) {
    *p &= ~2;
    return TRUE;
  }

  return FALSE;
}

NAKED void FUN_08235ffc(NavMesh* navMesh, NavAgent* agent, Vec3* pos) { INCFUNC("asm/func/FUN_08235ffc.inc"); }

NAKED void FUN_08236130(NavMesh* navMesh, NavAgent* agent, Vec3* pos) { INCFUNC("asm/func/FUN_08236130.inc"); }

// ナビメッシュ上の移動を1歩進める, flags の bit0 が立っているときだけ後段も回す
void Map_StepNavPath(NavAgent* agent, Vec3* pos) {
  NavMesh* navMesh = gCollisionMap->navMesh;

  FUN_08235ffc(navMesh, agent, pos);
  if (agent->flags & 1) {
    FUN_08236130(navMesh, agent, pos);
  }
}

// pos を含むナビ矩形の番号を返す, 見つからなければ 0xFF
s32 Map_FindNavRectAt(Vec3* pos) {
  NavMesh* navMesh = gCollisionMap->navMesh;
  s32 i;

  for (i = 0; i < navMesh->countIslands; i++) {
    NavIsland* island = (NavIsland*)((u8*)navMesh + navMesh->islandOffsets[i]);
    struct NavRect* rects = (struct NavRect*)((u8*)island + island->offsetToRects);
    s32 j;

    for (j = 0; j < island->countRects; j++) {
      if (Map_IsPosInNavRect(rects, pos, j)) {
        return j;
      }
    }
  }
  return 0xFF;
}

// pos を含むナビ矩形を総当たりで探して NavAgent を初期化する, 見つからなければ 0xFF のまま
s32 Map_InitNavAgent(NavAgent* agent, Vec3* pos) {
  NavMesh* navMesh = gCollisionMap->navMesh;
  s32 i;

  agent->islandIdx = 0xFF;
  agent->rectIdx = 0xFF;
  for (i = 0; i < navMesh->countIslands; i++) {
    NavIsland* island = (NavIsland*)((u8*)navMesh + navMesh->islandOffsets[i]);
    struct NavRect* rects = (struct NavRect*)((u8*)island + island->offsetToRects);
    s32 j;

    for (j = 0; j < island->countRects; j++) {
      if (Map_IsPosInNavRect(rects, pos, j)) {
        agent->islandIdx = i;
        agent->rectIdx = j;
      }
    }
  }

  agent->flags = 0;
  agent->unk_0c = *pos;
  agent->unk_1c = *pos;
  agent->unk_14 = *pos;
}
