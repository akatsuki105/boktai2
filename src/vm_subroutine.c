#include "global.h"
#include "vm.h"

extern u16 gSubroutineCount;

const ALIGNED(4) u8 u8_ARRAY_085a9108[256] = {0x0};  // 0x085A9108

#define INCDATA(file) \
  asm(".section .rodata\n\
  .include \"" file   \
      "\"\n\
 .syntax divided\n");

INCDATA("data/subroutine.inc");

extern Subroutine gSubroutineTable[643];

const u8 u8_ARRAY_085aa620[4] = {0x37, 0xC8, 0xEC, 0x40};  // 0x085aa620

void FUN_0823b158(void) {
  Subroutine* cur;
  gSubroutineCount = 0;
  for (cur = &gSubroutineTable[0]; cur->fn != NULL; cur++) {
    gSubroutineCount++;
  }
}

void FUN_0823b180(void) {
  gSubroutineTable[0].fn = NULL;  // why???
}

void FUN_0823b18c(void) {}

TaskFn VM_GetSubroutine_Internal(u32 subID, Subroutine* arr, s32 start, s32 len) {
  s32 i;
  // Binary search
  while (start < len) {
    i = Div(start + len, 2);
    if (arr[i].id < subID) {
      start = i + 1;
    } else {
      len = i;
    }
  }

  if (arr[start].id == subID) {
    return (TaskFn)arr[start].fn;
  }
  return NULL;
}

// Script_FindEngineCall
TaskFn VM_GetSubroutine(u32 subroutineID) {
  TaskFn fn = VM_GetSubroutine_Internal(subroutineID, gSubroutineTable, 0, gSubroutineCount);
  return fn;
}
