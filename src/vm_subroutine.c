#include "vm_subroutine.h"

#include "global.h"
#include "vm.h"

static u16 sCommandCount;  // 0x030016F4, このゲームでは 642
extern Subroutine gCommandList[];

// gCommandList の 要素数を数える (このゲームでは 642 になる)
void VM_CountSubroutine(void) {
  Subroutine* cur;
  sCommandCount = 0;
  for (cur = &gCommandList[0]; cur->fn.fn != NULL; cur++) {
    sCommandCount++;
  }
}

void FUN_0823b180(void) {
  gCommandList[0].fn.fn = NULL;  // .rodata だから意味ないよ...
}

void FUN_0823b18c(void) {}

static void* VM_GetSubroutine_Internal(u32 commandID, Subroutine* arr, s32 start, s32 len) {
  // Binary search
  while (start < len) {
    s32 i = Div(start + len, 2);
    if (arr[i].id < commandID) {
      start = i + 1;
    } else {
      len = i;
    }
  }

  if (arr[start].id == commandID) {
    return arr[start].fn.fn;
  }
  return NULL;
}

void* VM_GetSubroutine(u32 commandID) {
  void* fn = VM_GetSubroutine_Internal(commandID, gCommandList, 0, sCommandCount);
  return fn;
}
