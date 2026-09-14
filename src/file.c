#include "file.h"

#include "global.h"

// ソート済みのファイルID配列を二分探索し、見つからなければ -1 を返す
s32 FindFile(u32 fileID, FileID* list, u32 _, s32 start, s32 end) {
  while (start < end) {
    s32 mid = (start + end) >> 1;
    if (list[mid] < fileID) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  if (list[start] == fileID) {
    return start;
  }
  return -1;
}

// mft_directory の先頭 16 バイト, GetAssetFile がコピーしてオフセットをポインタに直す
typedef struct {
  u32 num_entries;
  FileID* id_array;
  u32* file_array;
  u32 offset_to_first_file;
} mft_directory_header;

// ディレクトリ d の中から fileID のファイルを探す, なければ NULL
void* GetAssetFile(mft_directory* d, u32 directoryID, FileID fileID, FileID _) {
  mft_directory_header h;
  s32 idx;

  h = *(mft_directory_header*)d;
  h.id_array = (FileID*)((u8*)h.id_array + (u32)d);
  h.file_array = (u32*)((u8*)h.file_array + (u32)d);
  idx = FindFile(fileID, h.id_array, _, 0, h.num_entries - 1);
  if (idx < 0 || idx >= h.num_entries) {
    return NULL;
  }
  return (void*)(h.file_array[idx] + (u32)d);
}

// ソート済みの fs を ID で二分探索し、そのディレクトリを返す, なければ NULL
mft_directory* GetDirectory(u32 directoryID, const mft_header* fs, s32 start, s32 end) {
  while (start < end) {
    s32 mid = (start + end) >> 1;
    if (fs[mid].id < directoryID) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  if (fs[start].id == directoryID) {
    return (mft_directory*)fs[start].directory;
  }
  return NULL;
}

// 複数ファイルを持つディレクトリなら gFS の ID に直してその中から探し、それ以外は ID をそのまま gFS から探す
void* GetFile(FileID directoryID, FileID fileID) {
  bool32 isAsset = FALSE;
  u32 id;
  mft_directory* d;
  u32 file = fileID;

  switch (directoryID) {
    case DIR_ANIMATION: {
      directoryID = 0x9225;
      fileID = 0x5130;
      isAsset = TRUE;
      break;
    }
    case 0x92B3: {
      directoryID = 0x9305;
      fileID = 0xD710;
      isAsset = TRUE;
      break;
    }
    case DIR_OBJPLTT: {
      directoryID = 0x9A65;
      fileID = 0x4679;
      isAsset = TRUE;
      break;
    }
    case 0x98F5: {
      directoryID = 0x9B05;
      fileID = 0x2117;
      isAsset = TRUE;
      break;
    }
    case DIR_FONT: {
      directoryID = 0xA705;
      fileID = 0x6D24;
      isAsset = TRUE;
      break;
    }
    case 0xAE6C: {
      directoryID = 0xAF05;
      fileID = 0xAC2C;
      isAsset = TRUE;
      break;
    }
    case 0xC091: {
      directoryID = 0xC305;
      fileID = 0xE53E;
      isAsset = TRUE;
      break;
    }
    case 0xCB05: {
      directoryID = 0xC8E5;
      fileID = 0x5F29;
      isAsset = TRUE;
      break;
    }
    case 0xCEEF: {
      directoryID = 0xCEE5;
      fileID = 0x4F2D;
      isAsset = TRUE;
      break;
    }
    case 0xCEAA: {
      directoryID = 0xCF05;
      fileID = 0x0A4D;
      isAsset = TRUE;
      break;
    }
  }
  id = (directoryID << 16) | fileID;
  d = GetDirectory(id, gFS, 0, 10);
  if (isAsset == TRUE) {
    return GetAssetFile(d, directoryID, file, id);
  }
  return d;
}

extern const mft_directory gAnimDirectory;
extern const mft_directory gPlttDirectory;
extern const mft_directory gSpriteSetPlttsDirectory;
extern const mft_directory gActorSpritesDirectory;
extern const mft_directory gFontDirectory;
extern const mft_directory gScriptDirectory;
extern const mft_directory gCollisionMapsDirectory;
extern const mft_directory gTilemapDirectory;
extern const mft_directory gSpriteSetsDirectory;
extern const mft_directory gTilesetsDirectory;
extern const mft_directory gParticlesDirectory;

// clang-format off
const mft_header gFS[12] = {
    {
        .id = 0x92255130,
        .directory = &gAnimDirectory
    },
    {
        .id = 0x9305D710,
        .directory = &gPlttDirectory
    },
    {
        .id = 0x9A654679,
        .directory = &gSpriteSetPlttsDirectory
    },
    {
        .id = 0x9B052117,
        .directory = &gActorSpritesDirectory
    },
    {
        .id = 0xA7056D24,
        .directory = &gFontDirectory
    },
    {
        .id = 0xA8D9A41E,
        .directory = &gScriptDirectory
    },
    {
        .id = 0xAF05AC2C,
        .directory = &gCollisionMapsDirectory
    },
    {
        .id = 0xC305E53E,
        .directory = &gTilemapDirectory
    },
    {
        .id = 0xC8E55F29,
        .directory = &gSpriteSetsDirectory
    },
    {
        .id = 0xCEE54F2D,
        .directory = &gTilesetsDirectory
    },
    {
        .id = 0xCF050A4D,
        .directory = &gParticlesDirectory
    },
    {
        .id = 0x0,
        .directory = (void*)0x0
    }
};
// clang-format on

// gAnimDirectory
INCBIN(".rodata", "data/gAnimDirectory.bin");  // ./tmp/bin.sh ./baserom.gba 0x085b0df0 0x085b26e4 ./data/gAnimDirectory.bin

// gTilemapDirectory
INCBIN(".rodata", "data/gTilemapDirectory.bin");  // ./tmp/bin.sh ./baserom.gba 0x085b26e4 0x087b260c ./data/gTilemapDirectory.bin

// gCollisionMapsDirectory
INCBIN(".rodata", "data/gCollisionMapsDirectory.bin");  // ./tmp/bin.sh ./baserom.gba 0x087b260c 0x087fa08c ./data/gCollisionMapsDirectory.bin

// gPlttDirectory
INCBIN(".rodata", "data/gPlttDirectory.bin");  // ./tmp/bin.sh ./baserom.gba 0x087fa08c 0x0881882c ./data/gPlttDirectory.bin
