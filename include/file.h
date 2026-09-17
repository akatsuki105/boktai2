#ifndef __INCLUDE_FILE_H__
#define __INCLUDE_FILE_H__

#include "gba/gba.h"
#include "types.h"

// Awesome https://boktaihacking.net/wiki/Master_file_table

// directory id
#define DIR_OBJPLTT 0x9B1B
#define DIR_BGPLTT 0x92B3
#define DIR_ANIMATION 0x922E
#define DIR_FONT 0xA635
#define DIR_SCRIPT 0xA8D9
#define DIR_AUX_SPRITE 0x98F5
#define DIR_COLLISION_MAP 0xAE6C
#define DIR_TILE_MAP 0xC091
#define DIR_SPRITE_SETS 0xCB05
#define DIR_TILESET 0xCEEF
#define DIR_PARTICLE 0xCEAA

struct mft_directory;

typedef u16 FileID;

typedef struct {
  u32 id;
  const struct mft_directory* directory;
} mft_header;

// スクリプトは独自のフォーマットを持つ (see ScriptDirectory in "include/vm.h")
// 他のデータも1つしかファイルがなくて、そこに独自のフォーマットで複数の子データを格納している場合が多く、あまり有効にこの仕組みを使っていない
typedef struct mft_directory {
  u32 num_entries;
  u32 offset_to_id_array;    // Relative to the start of this struct
  u32 offset_to_file_array;  // Relative to the start of this struct
  u32 offset_to_first_file;  // Unused, ignorable. Relative to the start of this struct.

  FileID id_array[1];
  u32 file_array[1];  // Entries are relative to the start of this struct

  // File contents follow
} mft_directory;

// --------------------------------------------

// directoryID
//   DIR_OBJPLTT         -> return &ObjPlttFile
//   DIR_BGPLTT          -> return &BgPlttFile
//   DIR_ANIMATION       -> return &AuxAnimFile
//   DIR_FONT            -> return &FontHeader
//   DIR_SCRIPT          -> return &ScriptDirectory
//   DIR_AUX_SPRITE      -> return &AuxSpriteFile
//   DIR_COLLISION_MAP   -> return &CollisionMapFile
//   DIR_TILE_MAP        -> return &TilemapHeader
//   DIR_SPRITE_SETS     -> return &MainSpriteFile
//   DIR_TILESET         -> return &TileSetFile
//   DIR_PARTICLE        -> return &ParticleFile
void* GetFile(FileID directoryID, FileID fileID);

extern const mft_header gFS[12];  // 0x085B0D90

#endif  // __INCLUDE_FILE_H__
