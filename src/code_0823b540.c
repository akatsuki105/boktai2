#include "collision_map.h"
#include "file.h"
#include "global.h"

// Collision Map File が圧縮されてたら展開して返す、圧縮されてなかったらそのまま返す
NAKED CollisionMapFile* OpenCollisionMapFile(void* file) { INCFUNC("asm/func/OpenCollisionMapFile.inc"); }

NAKED s32 Map_LoadCollisionMapFile(FileID id) { INCFUNC("asm/func/Map_LoadCollisionMapFile.inc"); }

// a.k.a. Map_LoadMap
NAKED void Map_LoadMapScripted(void) { INCFUNC("asm/func/Map_LoadMapScripted.inc"); }
