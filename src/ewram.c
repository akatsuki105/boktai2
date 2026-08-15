#include "global.h"
#include "malloc.h"

EWRAM_DATA u32 gSentinel02020400 = 0;  // AgbMainでEWRAMをクリアする前に退避されるのでソフトリセットを検知するためのセンチネル？
EWRAM_DATA u32 u32_02020404 = 0;       // gSentinel02020400と同様にAgbMainでEWRAMをクリアする前に退避されるが、用途は不明

EWRAM_DATA u8 u8_02020408[0x14FF8] = {};  // todo

EWRAM_DATA u8 u8_02035400[0x800] = {};  // 0x02035400, 0x0822e8b6 で 0x800 バイトで ClearMemory されるので内容は不明だが、ここが1つのメモリの塊であることは確か

EWRAM_DATA u8 u8_02035c00[0x1200] = {};  // todo

EWRAM_DATA u16 gSlowBgPlttBuffer[256] = {};  // 0x02036e00

EWRAM_DATA u8 gTilemapBuffer[BG_SCREEN_SIZE * 4] = {};  // 0x02037000, BG0, BG1, BG2, BG3 のタイルマップのバッファ

EWRAM_DATA u8 u8_02039000[0x2000] = {};  // todo
EWRAM_DATA Unk_0203b000 gUnk_0203b000[128] = {};
EWRAM_DATA u16 gRandomTable[1024] = {};
EWRAM_DATA u16 sUnused_0203bc00[1024] = {};

EWRAM_DATA u8 gGameStateBuffer[12288] = {};  // 0x0203C400, RandomizeGameStateAddr で このバッファのランダムなアドレスに gScratch, gWorldBackup, gWorld, gStatBackup, gStat の各要素の実態が配置される (チート対策と思われる)

EWRAM_DATA u32 u32_ARRAY_0203f400[256] = {};
EWRAM_DATA u32 u32_ARRAY_0203f800[256] = {};
// todo...
