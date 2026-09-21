#ifndef __INCLUDE_TILESETS_H__
#define __INCLUDE_TILESETS_H__

#include "gba/gba.h"

// https://boktaihacking.net/wiki/Tile_set_file

#define TILESET_PART_COUNT 257
#define TILESET_REF_COUNT 111526
#define TILESET_TILECOUNT 53062

typedef struct {
  u16 id;
  u16 tileCount;
  u32 startIndex;
} TileSetPart;
static_assert(sizeof(TileSetPart) == 8);

typedef struct {
  u16 partCount;                          // 0x00000, TileSetPart[partCount], TILESET_PART_COUNT
  u16 unk_2;                              // 0x00002
  u32 tileRefCount;                       // 0x00004, u16[tileRefCount]
  u32 tileCount;                          // 0x00008
  u32 offsetToPartList;                   // 0x0000C
  u32 offsetToTileRefs;                   // 0x00010
  u32 offsetToTiles;                      // 0x00014
  TileSetPart parts[TILESET_PART_COUNT];  // 0x00018
  u16 refs[TILESET_REF_COUNT];            // 0x00820
  u8 tiles[TILESET_TILECOUNT * 32];       // 0x36F6C
} TileSetFile;
static_assert(sizeof(TileSetFile) == 1923116);

// TileSetFile の先頭 0x18 バイトを、オフセットをポインタに直して積み直したもの
// (MainSpriteFile に対する MainSpriteGfx と同じ関係), 根拠: FUN_0822bc44 が組み立て、TileSet_FindPart が読む
typedef struct {
  u16 partCount;       // 0x00, TileSetFile.partCount
  u16 unk_2;           // 0x02, TileSetFile.unk_2
  u32 tileRefCount;    // 0x04, TileSetFile.tileRefCount
  u32 tileCount;       // 0x08, TileSetFile.tileCount
  TileSetPart* parts;  // 0x0C, TileSetFile.offsetToPartList をアドレスにしたもの
  u16* refs;           // 0x10, TileSetFile.offsetToTileRefs をアドレスにしたもの
  u8* tiles;           // 0x14, TileSetFile.offsetToTiles をアドレスにしたもの
} TileSet;
static_assert(sizeof(TileSet) == 24);

#endif  // __INCLUDE_TILESETS_H__
