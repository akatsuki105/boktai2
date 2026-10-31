#ifndef __INCLUDE_MAP_INLINE_H__
#define __INCLUDE_MAP_INLINE_H__

#include "collision_map.h"

// グローバル変数を参照する static inline は、 include したファイルのコンパイル結果に影響を与えることがある (たとえその関数を使わないとしても)
// これらは gCollisionMap といったグローバル変数を参照するため、 必要のない include は決してしないこと

#define IsOutsideMap(blockX, blockZ) ((blockX) < 0 || (blockZ) < 0 || ((u32)(blockX)) >= (u32)gMapBlockW || ((u32)(blockZ)) >= (u32)gMapBlockH)

static inline s32 GetCollisionTileIdx(WorldPos* pos) {
  s32 idx;

  s32 bx = (s8)(pos->x >> 8);
  s32 bz = (s8)(pos->z >> 8);
  if (IsOutsideMap(bx, bz)) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  return idx;
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
