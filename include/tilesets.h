#ifndef __INCLUDE_TILESETS_H__
#define __INCLUDE_TILESETS_H__

#include "gba/gba.h"

// https://boktaihacking.net/wiki/Tile_set_file

struct TileSetPart;

// ゲームのタイルセットがこの1つのTileSetにまとめられていて、 目的に応じて TileSetPart で分割されている
typedef struct {
  u16 partCount;     // 0x00
  u16 unk_2;         // 0x02, padding?
  u32 tileRefCount;  // 0x04
  u32 tileCount;     // 0x08

  // これらのメンバは、 ROMでは &TileSetFile からのオフセットでRAM読み込み時にポインタに変換される
  struct TileSetPart* parts;  // 0x0C, TileSetPart[partCount]
  u16* refs;                  // 0x10, u16[tileRefCount]
  u8* tiles;                  // 0x14, GBAタイル, u8[tileCount * 32]

  // ROM (TileSetFile) では これ以降に
  // TileSetPart parts[partCount];
  // u16 refs[tileRefCount];
  // u8 tiles[tileCount * 32];
} TileSet;
static_assert(sizeof(TileSet) == 24);

typedef struct TileSetPart {
  u16 id;
  u16 tileCount;
  u32 startIndex;
} TileSetPart;
static_assert(sizeof(TileSetPart) == 8);

typedef TileSet TileSetFile;  // ROM内のタイルセットであることを示すためのエイリアス

#endif  // __INCLUDE_TILESETS_H__
