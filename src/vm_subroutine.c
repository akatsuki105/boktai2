#include "vm_subroutine.h"

#include "global.h"
#include "vm.h"

IWRAM_DATA u16 gSubroutineCount = 0;  // 0x030016F4, このゲームでは 642

const ALIGNED(4) u8 u8_ARRAY_085a9108[256] = {0x0};  // 0x085A9108

// 関数の型がわかっていないものも多いのでいったん asm にしている
asm("gSubroutineTable: .include \"data/subroutine.inc\"");
extern Subroutine gSubroutineTable[642 + 1];  // 最後は NULL

const u32 Time085aa620 = 1089259575;  // 2004-07-09 18:04:39 UTC

// gSubroutineTable の 要素数を数える (このゲームでは 642 になる)
void VM_CountSubroutine(void) {
  Subroutine* cur;
  gSubroutineCount = 0;
  for (cur = &gSubroutineTable[0]; cur->fn.fn != NULL; cur++) {
    gSubroutineCount++;
  }
}

void FUN_0823b180(void) {
  gSubroutineTable[0].fn.fn = NULL;  // .rodata だから意味ないよ...
}

void FUN_0823b18c(void) {}

static void* VM_GetSubroutine_Internal(u32 subroutineID, Subroutine* arr, s32 start, s32 len) {
  // Binary search
  while (start < len) {
    s32 i = Div(start + len, 2);
    if (arr[i].id < subroutineID) {
      start = i + 1;
    } else {
      len = i;
    }
  }

  if (arr[start].id == subroutineID) {
    return arr[start].fn.fn;
  }
  return NULL;
}

void* VM_GetSubroutine(u32 subroutineID) {
  void* fn = VM_GetSubroutine_Internal(subroutineID, gSubroutineTable, 0, gSubroutineCount);
  return fn;
}
