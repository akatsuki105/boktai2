#ifndef __INCLUDE_FILE_H__
#define __INCLUDE_FILE_H__

#include "gba/gba.h"
#include "types.h"

// directory id
#define DIR_OBJPLTT 0x9B1B
#define DIR_BGPLTT 0x92B3             // 0x92B3, BOKHASH("arr")?
#define DIR_ANIMATION BOKHASH("anm")  // 0x922E, anim -> anm
#define DIR_FONT BOKHASH("fnt")       // 0xA635, font -> fnt
#define DIR_SCRIPT 0xA8D9
#define DIR_AUX_SPRITE 0x98F5
#define DIR_COLLISION_MAP 0xAE6C
#define DIR_TILE_MAP BOKHASH("map")  // 0xC091
#define DIR_MAIN_SPRITE 0xCB05       // 0xCB05, BOKHASH("boss")?
#define DIR_TILESET BOKHASH("ptn")   // 0xCEEF, pattern -> ptn
#define DIR_PARTICLE 0xCEAA
#define DIR_NAV_MESH 0xF63B

typedef u16 FileID;

// directoryID
//   DIR_OBJPLTT         -> return &ObjPlttFile
//   DIR_BGPLTT          -> return &BgPlttFile
//   DIR_ANIMATION       -> return &AuxAnimFile
//   DIR_FONT            -> return &FontInfo
//   DIR_SCRIPT          -> return &ScriptDirectory
//   DIR_AUX_SPRITE      -> return &AuxSpriteFile
//   DIR_COLLISION_MAP   -> return &CollisionMapFile
//   DIR_TILE_MAP        -> return &TilemapFile
//   DIR_MAIN_SPRITE     -> return &MainSpriteGfxFile
//   DIR_TILESET         -> return &TileSetFile
//   DIR_PARTICLE        -> return &ParticleFile
void* GetFile(FileID directoryID, FileID fileID);

#endif  // __INCLUDE_FILE_H__
