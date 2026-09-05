#include "global.h"

INCASM("asm/code_080a6c94.inc");

bool32 FUN_080a6f20(void) {
  if (gFlag030047a4 & FLAG030047A4_UNK_9) return TRUE;
  return FALSE;
}

s32 VM_Sub15B3(void) { gFlag030047a4 |= FLAG030047A4_UNK_11; }
