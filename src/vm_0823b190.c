#include "global.h"
#include "vm.h"

void FUN_08231780(void);
bool32 FUN_0823a8b0(void);
void FUN_08231be0(u32 n);
TaskFn Script_FindEngineCall(u32 n);

void* VM_Ctrl_Unused_0BB3(void) { return NULL; }

// https://boktaihacking.net/wiki/Bytecode#Control_0xc8bb_(load_map)
void* VM_Ctrl_LoadMap(void) {
  void* bVar2;
  u16 scriptID = (u16)Script_GetValue();
  u32_03004798 = 0x01;
  if ((prepare_08231510(0x6E) == 0) || ((VM_GetPC() != NULL) && (Script_GetValue() == 0))) {
    u32_03004798 |= 0x10;
  }
  FUN_08231be0((s16)scriptID);
  gStat->mapInitScriptID = scriptID;
  return NULL;
}

// Call, https://boktaihacking.net/wiki/Bytecode#Control_0x9906_(engine_call)
s32 VM_Ctrl_9906(void) {
  u16 subID = (u16)Script_GetValue();
  TaskFn fn = Script_FindEngineCall(subID);
  if (fn == NULL) {
    return -1;
  }
  subID = (u16)Script_GetValue();
  fn(subID, NULL);
  return 0;
}

// Call, https://boktaihacking.net/wiki/Bytecode#Control_0xb745_(engine_call)
s32 VM_Ctrl_B745(void) {
  u16 subID = (u16)Script_GetValue();
  TaskFnNoArg fn = (TaskFnNoArg)Script_FindEngineCall(subID);
  if (fn == NULL) {
    return -1;
  }
  gVM.result = fn();
  return 0;
}

// https://boktaihacking.net/wiki/Bytecode#Control_0x22ff_(TODO)
NAKED void* VM_Ctrl_22FF(void) { INCFUNC("asm/func/VM_Ctrl_22FF.inc"); }

void* VM_Ctrl_Unused_C091(void* _) { return _; }

// https://boktaihacking.net/wiki/Bytecode#Control_0xd4cb_(set_zone_callback)
NAKED s32 VM_Ctrl_D4CB(void* r0) { INCFUNC("asm/func/VM_Ctrl_D4CB.inc"); }

// https://boktaihacking.net/wiki/Bytecode#Control_0xe43c_(TODO)
void* VM_Ctrl_E43C(void) {
  bool32 bVar1 = FUN_0823a8b0();
  if (!bVar1) {
    u32_03004798 = 0x40;
    if (prepare_08231510(0x73) != 0) {
      u32_03004798 |= 0x10;
    } else if (prepare_08231510(0x72) != 0) {
      u32_03004798 |= 0x100;
    }
  }
  return NULL;
}

static void FUN_0823b12c(void) { return; }

s32 FUN_0823b130(void) {
  FUN_0823b12c();
  FUN_08231780();
  gCtrlHandlers2.next = NULL;
  gCtrlHandlers2.len = ARRAY_COUNT(gCtrlHandlers2_ROM);
  gCtrlHandlers2.arr = gCtrlHandlers2_ROM;
  return VM_AddCtrlHandlers(&gCtrlHandlers2);
}

void FUN_0823b158(void) {
  Subroutine* cur;
  gUnk085a9208Counter = 0;
  for (cur = &gSubroutineTable1[0]; cur->fn != NULL; cur++) {
    gUnk085a9208Counter++;
  }
}

void FUN_0823b180(void) {
  gSubroutineTable1[0].fn = NULL;  // why???
}

void FUN_0823b18c(void) {}

TaskFn FUN_0823b190(u32 subID, Subroutine* arr, s32 start, s32 len) {
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

TaskFn Script_FindEngineCall(u32 subroutineID) {
  TaskFn fn = FUN_0823b190(subroutineID, gSubroutineTable1, 0, gUnk085a9208Counter);
  return fn;
}
