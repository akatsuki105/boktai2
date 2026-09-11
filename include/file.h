#ifndef __INCLUDE_FILE_H__
#define __INCLUDE_FILE_H__

#include "gba/gba.h"
#include "types.h"

// Awesome https://boktaihacking.net/wiki/Master_file_table

// directory id
#define DIR_OBJPLTT 0x9B1B
#define DIR_ANIMATION 0x922E
#define DIR_FONT 0xA635
#define DIR_SCRIPT 0xA8D9

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

void* GetFile(FileID directoryID, FileID fileID);

extern const mft_header gFS[12];  // 0x085B0D90

#endif  // __INCLUDE_FILE_H__
