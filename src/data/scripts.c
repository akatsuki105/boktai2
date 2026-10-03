#include "global.h"
#include "sprite_common.h"
#include "vm.h"

// ScriptDirectory in include/vm.h

const u32 gScriptDirectory = 0x40A8186C;  // 0x08CBF248

// 0x08CBF24C
const ScriptOffset ScriptEntries[11539 + 1] = INCBIN_U32("data/script_entries.bin");

const u32 sOffsets[] = {
    298376,                     // Bytecode - sOffsets
    16,                         // gStringHeader - sOffsets
    16 + (7141 * sizeof(u32)),  // String_0000 - sOffsets
    298372,                     // unknown - sOffsets
};  // 0x08CCA69C

// 0x08CCA6AC, bit0..30: String_0000 からのオフセット, bit31: データの種類 (0=Binary, 1=String)
const u32 gStringHeader[7141] = INCBIN_U32("data/string_index.bin");

// clang-format off
#include "text/strings.h"
#include "text/string_3307.h"
#include "text/library.h"
#include "text/string_3790.h"
#include "text/chat_luis.h"
#include "text/chat_marcello.h"
#include "text/chat_snake.h"
#include "text/chat_zaji.h"
#include "text/staff_roll.h"
#include "text/map_codename.h"
#include "text/continue.h"
#include "text/start_menu.h"
#include "text/scripts_6297.h"
// clang-format on

const u8 unk08D13420[4] = {0xD8, 0x0E, 0x0A, 0x61};  // 0x08D13420

// 0x08D13424
const u32 Bytecode = 617012;
const u8 Bytecode_start[] = INCBIN_U8("data/scripts/scripts.bin");

// 0x08DA9E5C
const u32 SpecialScriptSize = 6;
const u8 SpecialScript[] = INCBIN_U8("data/scripts/special.bin");
