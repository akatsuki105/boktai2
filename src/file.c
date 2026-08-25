#include "file.h"

#include "global.h"

NAKED s32 FindFile(u32 fileID, FileID* list, u32 _, s32 start, s32 end) { INCFUNC("asm/func/FindFile.inc"); }

NAKED void* GetAssetFile(mft_directory* d, u32 directoryID, FileID fileID, FileID _) { INCFUNC("asm/func/GetAssetFile.inc"); }

NAKED mft_directory* GetDirectory(u32 directoryID, mft_header* fs, s32 idx1, s32 idx2) { INCFUNC("asm/func/GetDirectory.inc"); }

NAKED void* GetFile(FileID directoryID, FileID fileID) { INCFUNC("asm/func/GetFile.inc"); }

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

// gTilesetsDirectory
INCBIN(".rodata", "data/gTilesetsDirectory.bin");  // ./tmp/bin.sh ./baserom.gba 0x0881882c 0x089ee074 ./data/gTilesetsDirectory.bin
