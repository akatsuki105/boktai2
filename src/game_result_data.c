#include "global.h"

// 全部 game_result.c から参照されるデータだが、 game_result.c にはすでに Update関数のポインタテーブル (0x085B0080) がある
// アドレスがかけ離れているため、別ファイルに分けている

const u8 u8_ARRAY_08252894[8] = {0x90, 0x98, 0xA8, 0xB0, 0xB8, 0xC8, 0xD0, 0xD8};

const char s_RED_0825289c[3][6] = {"  RED", "BLACK", " GRAY"};
const char s_STYLE_082528ae[6][9] = {"   SWORD", "   SPEAR", "  HAMMER", "    FIST", "     GUN", "NO STYLE"};
const char s_PUSH_A_BUTTON_082528e4[] = "PUSH A BUTTON";
