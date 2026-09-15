#include "file.h"

#include "global.h"
#include "vm.h"

extern const mft_directory gAnimDirectory;
extern const mft_directory gPlttDirectory;
extern const mft_directory gSpriteSetPlttsDirectory;
extern const mft_directory gActorSpritesDirectory;
extern const mft_directory gFontDirectory;
extern const ScriptDirectory gScriptDirectory;
extern const mft_directory gCollisionMapsDirectory;
extern const mft_directory gTilemapDirectory;
extern const mft_directory gSpriteSetsDirectory;
extern const mft_directory gTilesetsDirectory;
extern const mft_directory gParticlesDirectory;

const mft_header gFS[12] = {
    {id : ((0x9225 << 16) | 0x5130), directory : &gAnimDirectory                  },
    {id : ((0x9305 << 16) | 0xD710), directory : &gPlttDirectory                  },
    {id : ((0x9A65 << 16) | 0x4679), directory : &gSpriteSetPlttsDirectory        },
    {id : ((0x9B05 << 16) | 0x2117), directory : &gActorSpritesDirectory          },
    {id : ((0xA705 << 16) | 0x6D24), directory : &gFontDirectory                  },
    {id : ((0xA8D9 << 16) | 0xA41E), directory : (mft_directory*)&gScriptDirectory},
    {id : ((0xAF05 << 16) | 0xAC2C), directory : &gCollisionMapsDirectory         },
    {id : ((0xC305 << 16) | 0xE53E), directory : &gTilemapDirectory               },
    {id : ((0xC8E5 << 16) | 0x5F29), directory : &gSpriteSetsDirectory            },
    {id : ((0xCEE5 << 16) | 0x4F2D), directory : &gTilesetsDirectory              },
    {id : ((0xCF05 << 16) | 0x0A4D), directory : &gParticlesDirectory             },
    {id : 0x0,                       directory : NULL                             },
};

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
    case DIR_BGPLTT: {
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
    case DIR_ACTOR_SPRITE: {
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
    case DIR_COLLISION_MAP: {
      directoryID = 0xAF05;
      fileID = 0xAC2C;
      isAsset = TRUE;
      break;
    }
    case DIR_TILE_MAP: {
      directoryID = 0xC305;
      fileID = 0xE53E;
      isAsset = TRUE;
      break;
    }
    case DIR_SPRITE_SETS: {
      directoryID = 0xC8E5;
      fileID = 0x5F29;
      isAsset = TRUE;
      break;
    }
    case DIR_TILESET: {
      directoryID = 0xCEE5;
      fileID = 0x4F2D;
      isAsset = TRUE;
      break;
    }
    case DIR_PARTICLE: {
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
