#ifndef __INCLUDE_FILE_H__
#define __INCLUDE_FILE_H__

#include "gba/gba.h"
#include "types.h"

// directory id
#define DIR_OBJPLTT 0x9B1B            // 0x9B1B
#define DIR_BGPLTT BOKHASH("arr")     // 0x92B3, 背景マップファイルの名前が、 `pile_driver_night_col_arr`のように `_col_arr` で終わる
#define DIR_ANIMATION BOKHASH("anm")  // 0x922E, anim -> anm
#define DIR_FONT BOKHASH("fnt")       // 0xA635, font -> fnt
#define DIR_SCRIPT 0xA8D9             // 0xA8D9
#define DIR_AUX_SPRITE 0x98F5         // 0x98F5, BOKHASH("cdt")?, Chara DaTa で意味的には矛盾しない
#define DIR_COLLISION_MAP 0xAE6C      // 0xAE6C, BOKHASH("hpk")?
#define DIR_TILE_MAP BOKHASH("map")   // 0xC091
#define DIR_MAIN_SPRITE 0xCB05        // 0xCB05, BOKHASH("boss")?, BOKHASH("oud")?
#define DIR_TILESET BOKHASH("ptn")    // 0xCEEF, tile PaTterN
#define DIR_PARTICLE 0xCEAA

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
