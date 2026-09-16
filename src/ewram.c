#include "global.h"

// 圧縮されたTilemapFileはここに展開して読み出す, 圧縮されてないならROMから直接読み込むのでここは使われない
EWRAM_DATA u8 gTilemapFileBufferHead[4] = {};   // 0x02021400, 展開先の先頭4バイト, TilemapHeader より手前にある, 用途不明
EWRAM_DATA u8 gTilemapFileBuffer[65532] = {};   // 0x02021404, 展開された TilemapHeader 本体, 根拠: GetTilemapFile がここを返す

// CollisionMapFile が圧縮されている場合、ここに展開してファイル内容を読み込む, 圧縮されていないならROMから直接読み込むのでここは使われない
EWRAM_DATA u8 gDecompressedCollisionMapHeader[4] = {};    // 0x02031400, 展開先の先頭4バイト, CollisionMapFile より手前にある, 用途不明
EWRAM_DATA u8 gDecompressedCollisionMapFile[16380] = {};  // 0x02031404, 展開された CollisionMapFile 本体, 根拠: OpenCollisionMapFile がここを返す

EWRAM_DATA u8 u8_02035400[0x800] = {};  // 0x02035400, 0x0822e8b6 で 0x800 バイトで ClearMemory されるので内容は不明だが、ここが1つのメモリの塊であることは確か

EWRAM_DATA u8 u8_02035c00[0x1000] = {};  // todo

EWRAM_DATA u8 u8_ARRAY_02036c00[512] = {};  // 0x02036C00

EWRAM_DATA rgb555 gSlowBgPlttBuffer[256] = {};  // 0x02036e00

EWRAM_DATA u8 gTilemapBuffer[BG_SCREEN_SIZE * 4] = {};  // 0x02037000, BG0, BG1, BG2, BG3 のタイルマップのバッファ

EWRAM_DATA u8 u8_02039000[0x2000] = {};  // todo
EWRAM_DATA Unk_0203b000 gUnk_0203b000[128] = {};
EWRAM_DATA u16 gRandomTable[1024] = {};  // 0x0203B400
EWRAM_DATA u16 sUnused_0203bc00[1024] = {};

EWRAM_DATA u8 gGameStateBuffer[12288] = {};  // 0x0203C400, RandomizeGameStateAddr で このバッファのランダムなアドレスに gScratch, gWorldBackup, gWorld, gStatBackup, gStat の各要素の実態が配置される (チート対策と思われる)

EWRAM_DATA u32 u32_ARRAY_0203f400[256] = {};
EWRAM_DATA u32 u32_ARRAY_0203f800[256] = {};
// todo...
