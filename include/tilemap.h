#ifndef __INCLUDE_TILEMAP_H__
#define __INCLUDE_TILEMAP_H__

#include "constants/tilemap.h"
#include "gba/gba.h"

struct TilemapLayer;

typedef u16 MetatileIdx16;  // メタタイル番号, Tilemaps.metatiles[MetatileIdx16*4]

typedef struct {
  char magic[4];      // 0x00, "MP\0\0"
  u16 layerCount;     // 0x04, レイヤ数 (ダンジョンマップは基本的に1, ただし水や氷の特殊効果を使う場合は2)
  u16 tileCount;      // 0x06, GBAタイル数
  u16 metatileCount;  // 0x08, メタタイルの数 (メタタイル: GBAタイルを4枚まとめたもの(16x16px))
  u16 loadOffset;     // 0x0A, GBAタイルのコピー先(VRAMのタイル単位オフセット)

  // これらのメンバは、 ROMでは &Tilemaps からのオフセットでRAM読み込み時にポインタに変換される
  struct TilemapLayer* layers;  // 0x0C, TilemapLayer[layerCount]
  u8* tiles;                    // 0x10, GBAタイル, u8[tileCount * 32]
  BgMapEntry* metatiles;        // 0x14, BgMapEntry[metatileCount * 4], 各メタタイルは単に BgMapEntry[4] (0: 左上, 1:右上, 2:左下, 3:右下)

  // ROM では これ以降に
  //   TilemapLayer layers[layerCount];
  //   u8 tiles[tileCount * 32];
  //   BgMapEntry metatiles[metatileCount * 4];
  //   MetatileIdx16 mtmap[各レイヤの .width * .height の合計];
} Tilemaps;

typedef Tilemaps TilemapFile;  // ROM内のタイルマップファイルであることを示すためのエイリアス

// これがGBAのBGレイヤ1枚分
typedef struct TilemapLayer {
  u16 width;             // 0x0, メタタイル単位の幅
  u16 height;            // 0x2, メタタイル単位の高さ
  u16 id;                // 0x4
  u16 unk_6;             // 0x6, padding?
  MetatileIdx16* mtmap;  // 0x8, Tilemaps.mtmap の開始位置, ROMでは &Tilemaps からの オフセット で RAM読み込み時にポインタに変換される
} TilemapLayer;

#endif  // __INCLUDE_TILEMAP_H__
