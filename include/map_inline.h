#ifndef __INCLUDE_MAP_INLINE_H__
#define __INCLUDE_MAP_INLINE_H__

#include "collision_map.h"

// グローバル変数を参照する static inline は、 include したファイルのコンパイル結果に影響を与えることがある (たとえその関数を使わないとしても)
// これらは gCollisionMap といったグローバル変数を参照するため、 必要のない include は決してしないこと

// pos のタイルの高さを返す, 階段タイルなら上る向きの座標の端数ぶんだけ下げる
static inline s32 TileHeightAt(WorldPos* pos) {
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

#endif  // __INCLUDE_MAP_INLINE_H__
