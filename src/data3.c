#include "global.h"

const ALIGNED(4) u8 u8_ARRAY_085a9108[256] = {0x0};

INCBIN(".rodata", "data/rodata.bin");  // ./tmp/bin.sh ./baserom.gba 0x085a9208 0x08cbf248 ./data/rodata.bin

// gScriptDirectory:
// C や asm ではなく 専用のデータ形式で記述されたものをコンマイ独自のツールでビルドしてると思われる (ROMとは異なるビルド時刻や忌々しい相対オフセットが根拠)
INCBIN(".rodata", "data/scripts.bin");  // ./tmp/bin.sh ./baserom.gba 0x08cbf248 0x08da9e68 ./data/scripts.bin
