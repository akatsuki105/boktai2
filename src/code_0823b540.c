#include "collision_map.h"
#include "file.h"
#include "global.h"

// Collision Map File が圧縮されてたら展開して返す、圧縮されてなかったらそのまま返す
CollisionMapFile* OpenCollisionMapFile(void* file) {
  u8* magic = file;

  if (magic[0] == 0x48 && magic[1] == 0x50) {  // "HP"
    return (CollisionMapFile*)file;
  }
  LZ77UnCompWram(file, gDecompressedCollisionMapHeader);
  return (CollisionMapFile*)gDecompressedCollisionMapFile;
}

NAKED s32 Map_LoadCollisionMapFile(FileID id) { INCFUNC("asm/func/Map_LoadCollisionMapFile.inc"); }

// a.k.a. Map_LoadMap
NAKED void Map_LoadMapScripted(void) { INCFUNC("asm/func/Map_LoadMapScripted.inc"); }
