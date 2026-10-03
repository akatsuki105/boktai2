#include "camera.h"
#include "collision_map.h"
#include "file.h"
#include "global.h"
#include "registry.h"
#include "video.h"
#include "vm.h"

s32 FUN_082327c0(FileID id);
s32 FUN_082345f8(FileID id);
s32 FUN_08234db8(FileID id);
s32 FUN_082358f4(FileID id);

// Collision Map File が圧縮されてたら展開して返す、圧縮されてなかったらそのまま返す
CollisionMapFile* OpenCollisionMapFile(void* file) {
  u8* magic = file;

  if (magic[0] == 'H' && magic[1] == 'P') {  // "HP"
    return (CollisionMapFile*)file;
  }
  LZ77UnCompWram(file, gDecompressedCollisionMapHeader);
  return (CollisionMapFile*)gDecompressedCollisionMapFile;
}

// id is HP_XXXX in "include/constants/collision_map.h"
NAKED s32 Map_LoadCollisionMapFile(FileID id) { INCFUNC("asm/func/Map_LoadCollisionMapFile.inc"); }

// 0x30AD
NAKED void Map_LoadMapScripted(void) { INCFUNC("asm/func/Map_LoadMapScripted.inc"); }
