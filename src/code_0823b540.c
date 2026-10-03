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
NAKED s32 Map_LoadCollisionMapFile(s32 id) { INCFUNC("asm/func/Map_LoadCollisionMapFile.inc"); }

// 0x30AD
void Map_LoadMapScripted(void) {
  CollisionMapData* cm;
  CollisionMapTileData* td;
  s32 h;
  s32 t;
  s32 r;
  s32 z;
  s32 pf;
  s32 val;

  VM_GetNamedArgValue('n', 0);
  h = VM_GetNamedArgValue('h', 0);
  t = VM_GetNamedArgValue('t', 0);
  r = VM_GetNamedArgValue('r', 0);
  z = VM_GetNamedArgValue('z', 0);
  pf = VM_GetNamedArgValue('p', 0);
  if (pf != 0) {
    Map_LoadCollisionMapFile(pf);
  } else {
    if (h != 0) {
      FUN_082327c0(h);
    }
    if (t != 0) {
      FUN_082345f8(t);
    }
    if (r != 0) {
      FUN_08234db8(r);
    }
    if (z != 0) {
      FUN_082358f4(z);
    }
  }

  cm = Registry_Find(0x56C2);
  td = cm->tiledata;
  if (VM_SeekToNamedArg('v')) {
    val = VM_GetValue();
    if (val == 0) {
      Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
      gCameraCoords.tilemapX = td->tilemap_offset_x >> 4;
      gCameraCoords.tilemapY = td->tilemap_offset_y >> 4;
    } else {
      Video_SetDrawPasses(val, FUN_0822de64, FUN_0822ac90, MainSprite_DrawListScreen);
      gCameraCoords.tilemapX = 0;
      gCameraCoords.tilemapY = 0;
    }
  }
}
