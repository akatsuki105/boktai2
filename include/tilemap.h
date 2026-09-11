#ifndef __INCLUDE_TILEMAP_H__
#define __INCLUDE_TILEMAP_H__

#include "gba/gba.h"

// https://boktaihacking.net/wiki/Tile_map_file

typedef struct {
  char magic[4];                 // 0x00, "MP\0\0"
  u16 layerCount;                // 0x04, Number of layers in this file
  u16 tileCount;                 // 0x06, Number of tiles in this file's tileset (if it exists)
  u16 metatileCount;             // 0x08, Number of metatiles in this file
  u16 loadOffset;                // 0x0A, Offset into VRAM at which the tileset should be copied to, in tiles.
  u32 offsetToLayerDefinitions;  // 0x0C, Byte offset from start of this struct to the layerDefinitions[] array
  u32 offsetToTileset;           // 0x10, Byte offset from start of this struct to the tileset[] array. If it's zero, then this file does not contain a tileset.
  u32 offsetToMetatiles;         // 0x14, Byte offset from start of this struct to the metatiles[] array

  // TilemapLayer layerDefintions[layerCount];
  // u8 tileset[];
  // u16 metatiles[];
  // u16 layerData[];
} TilemapHeader;

typedef struct {
  u16 width;            // 0x0, Width of layer in metatiles
  u16 height;           // 0x2, Height of layer in metatiles
  u16 id;               // 0x4
  u16 unk_6;            // 0x6
  u32 offsetToTilemap;  // 0x8, Byte offset from start of **the TilemapHeader struct** to the layer data
} TilemapLayer;

#endif  // __INCLUDE_TILEMAP_H__
