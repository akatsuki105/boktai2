#include "global.h"
#include "vm.h"

extern u16 gSubroutineCount;

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
