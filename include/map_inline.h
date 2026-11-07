#ifndef __INCLUDE_MAP_INLINE_H__
#define __INCLUDE_MAP_INLINE_H__

#include "collision_map.h"

// グローバル変数を参照する static inline は、 include したファイルのコンパイル結果に影響を与えることがある (たとえその関数を使わないとしても)
// これらは gCollisionMap といったグローバル変数を参照するため、 必要のない include は決してしないこと

static inline s32 GetCollisionTileIdx(WorldPos* pos) {
  s32 idx;

  s32 tileX = (s8)(pos->x >> 8);
  s32 tileZ = (s8)(pos->z >> 8);
  if (IsOutsideMap(tileX, tileZ)) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[tileZ] + tileX;
  }
  return idx;
}

// 索引 idx のタイルを返す, 上書きがあればそちらを返す
static inline CollisionMapTile* TileAtIndex(s32 idx) {
  MapTileOverride* ov = Map_FindTileOverride(idx, 1);

  if (ov != NULL) {
    return &ov->tile;
  }
  return &gCollisionMap->tiledata->tiles[idx];
}

// 索引 idx のタイルの高さを返す, 階段タイルなら上る向きの座標の端数ぶんだけ下げる
static inline u32 TileHeightAtIndex(s32 idx, WorldPos* pos) {
  CollisionMapTile* tile = TileAtIndex(idx);
  s32 stairs = tile->heightStairs >> 4;
  u32 height = (tile->heightStairs & 0xF) << 8;

  switch (stairs) {
    case STAIRS_VERTICAL: {
      height -= pos->z & 0xFF;
      break;
    }
    case STAIRS_HORIZONTAL: {
      height -= pos->x & 0xFF;
      break;
    }
  }
  return height;
}

#define GetTileAt(pos)                                               \
  ({                                                                 \
    s32 idx = GetCollisionTileIdx(pos);                              \
    MapTileOverride* ov = Map_FindTileOverride(idx, 1);              \
    (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx]; \
  })

// pos のタイルの高さを返す, 階段タイルなら上る向きの座標の端数ぶんだけ下げる
static inline s32 TileHeightAt(WorldPos* pos) {
  CollisionMapTile* tile = GetTileAt(pos);

  s32 stairs = tile->heightStairs >> 4;
  s32 height = (tile->heightStairs & 0xF) << 8;
  switch (stairs) {
    case STAIRS_VERTICAL: {
      height -= pos->z & 0xFF;
      break;
    }
    case STAIRS_HORIZONTAL: {
      height -= pos->x & 0xFF;
      break;
    }
  }

  return height;
}

static inline TileAttr GetTileAttrAt(WorldPos* pos) { return GetTileAt(pos)->attr; }

#endif  // __INCLUDE_MAP_INLINE_H__
