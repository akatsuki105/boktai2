#include "file.h"

#include "global.h"
#include "vm.h"

// このゲームの(奇妙な)アセット管理システム

// スクリプトは独自のフォーマットを持つ (see ScriptDirectory in "include/vm.h")
// 他のデータも1つしかファイルがなくて、そこに独自のフォーマットで複数の子データを格納している場合が多く、あまり有効にこの仕組みを使っていない
typedef struct {
  u32 entryCount;       // ファイル数
  u32 offsetToIds;      // Directory から ids へのオフセット
  u32 offsetToOffsets;  // Directory から offsets へのオフセット (オフセットが入った配列の場所をオフセットで指定しているのややこしい)
  u32 offsetTo1stFile;  // Directory から 1つ目のファイルまでのオフセットが入っている (ゲーム中でこの値は使われていない)

  FileID ids[0];   // FileID の配列, 実際の要素数は entryCount
  u32 offsets[0];  // Directory から 各ファイルへの (Directory からの) オフセット の配列, 実際の要素数は entryCount
  // これ以降に各ファイルのデータが続く (データの内容は用途ごとに全く異なる)
  // FileData files[entryCount] が続く
} Directory;

extern const Directory gAnimDirectory;
extern const Directory gPlttDirectory;
extern const Directory gSpritePlttsDirectory;
extern const Directory gAuxSpritesDirectory;
extern const Directory gFontDirectory;
extern const u32 gScriptDirectory;
extern const Directory gCollisionMapsDirectory;
extern const Directory gTilemapDirectory;
extern const Directory gMainSpritesDirectory;
extern const Directory gTilesetsDirectory;
extern const Directory gParticlesDirectory;

typedef struct {
  u32 id;
  const Directory* directory;
} FSEntry;

const FSEntry gFS[12] = {
    {id : ((0x9225 << 16) | 0x5130), directory : &gAnimDirectory              },
    {id : ((0x9305 << 16) | 0xD710), directory : &gPlttDirectory              },
    {id : ((0x9A65 << 16) | 0x4679), directory : &gSpritePlttsDirectory       },
    {id : ((0x9B05 << 16) | 0x2117), directory : &gAuxSpritesDirectory        },
    {id : ((0xA705 << 16) | 0x6D24), directory : &gFontDirectory              },
    {id : ((0xA8D9 << 16) | 0xA41E), directory : (Directory*)&gScriptDirectory},
    {id : ((0xAF05 << 16) | 0xAC2C), directory : &gCollisionMapsDirectory     },
    {id : ((0xC305 << 16) | 0xE53E), directory : &gTilemapDirectory           },
    {id : ((0xC8E5 << 16) | 0x5F29), directory : &gMainSpritesDirectory       },
    {id : ((0xCEE5 << 16) | 0x4F2D), directory : &gTilesetsDirectory          },
    {id : ((0xCF05 << 16) | 0x0A4D), directory : &gParticlesDirectory         },
    {id : 0x0,                       directory : NULL                         },
};  // 0x085B0D90

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

// ディレクトリ d の中から fileID のファイルを探す, なければ NULL
void* GetFileFromDirectory(Directory* d, u32 directoryID, FileID fileID, FileID _) {
  s32 idx;

  // 相対オフセットをアドレスに変換
  struct DirectoryHeader {
    u32 entryCount;
    FileID* ids;
    u32* offsets;
    u32 offsetTo1stFile;
  } h = *((struct DirectoryHeader*)d);
  h.ids = (FileID*)((u8*)h.ids + (u32)d);
  h.offsets = (u32*)((u8*)h.offsets + (u32)d);

  idx = FindFile(fileID, h.ids, _, 0, h.entryCount - 1);
  if (idx < 0 || idx >= h.entryCount) {
    return NULL;
  }
  return (void*)(h.offsets[idx] + (u32)d);  // h.offsets は Directory から各ファイルへのオフセットの配列
}

// ソート済みの fs を ID で二分探索し、そのディレクトリを返す, なければ NULL
Directory* GetDirectory(u32 directoryID, const FSEntry* fs, s32 start, s32 end) {
  while (start < end) {
    s32 mid = (start + end) >> 1;
    if (fs[mid].id < directoryID) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  if (fs[start].id == directoryID) {
    return (Directory*)fs[start].directory;
  }
  return NULL;
}

// 複数ファイルを持つディレクトリなら gFS の ID に直してその中から探し、それ以外は ID をそのまま gFS から探す
void* GetFile(FileID directoryID, FileID fileID) {
  bool32 isNormalDir = FALSE;  // スクリプト(gScriptDirectory)だけディレクトリのフォーマットが違うのでそれを区別するためのフラグ

  u32 id;
  Directory* d;
  u32 file = fileID;

  switch (directoryID) {
    case DIR_ANIMATION: {
      directoryID = 0x9225;
      fileID = 0x5130;
      isNormalDir = TRUE;
      break;
    }
    case DIR_BGPLTT: {
      directoryID = 0x9305;
      fileID = 0xD710;
      isNormalDir = TRUE;
      break;
    }
    case DIR_OBJPLTT: {
      directoryID = 0x9A65;
      fileID = 0x4679;
      isNormalDir = TRUE;
      break;
    }
    case DIR_AUX_SPRITE: {
      directoryID = 0x9B05;
      fileID = 0x2117;
      isNormalDir = TRUE;
      break;
    }
    case DIR_FONT: {
      directoryID = 0xA705;
      fileID = 0x6D24;
      isNormalDir = TRUE;
      break;
    }
    case DIR_COLLISION_MAP: {
      directoryID = 0xAF05;
      fileID = 0xAC2C;
      isNormalDir = TRUE;
      break;
    }
    case DIR_TILE_MAP: {
      directoryID = 0xC305;
      fileID = 0xE53E;
      isNormalDir = TRUE;
      break;
    }
    case DIR_MAIN_SPRITE: {
      directoryID = 0xC8E5;
      fileID = 0x5F29;
      isNormalDir = TRUE;
      break;
    }
    case DIR_TILESET: {
      directoryID = 0xCEE5;
      fileID = 0x4F2D;
      isNormalDir = TRUE;
      break;
    }
    case DIR_PARTICLE: {
      directoryID = 0xCF05;
      fileID = 0x0A4D;
      isNormalDir = TRUE;
      break;
    }
  }
  id = (directoryID << 16) | fileID;
  d = GetDirectory(id, gFS, 0, 10);
  if (isNormalDir == TRUE) {  // gScriptDirectory は独自フォーマットなので fileの取得はそれ以外のものに対して行う
    return GetFileFromDirectory(d, directoryID, file, id);
  }
  return d;
}
