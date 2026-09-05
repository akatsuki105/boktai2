#include "global.h"
#include "vm.h"

void FUN_08231780(void);
void SetMapInitScriptID(u32 n);
bool32 FUN_0823a8b0(void);

TaskFn VM_GetSubroutine(u32 subroutineID);

void* VM_Ctrl_Unused_0BB3(void) { return NULL; }

// https://boktaihacking.net/wiki/Bytecode#Control_0xc8bb_(load_map)
void* VM_Ctrl_LoadMap(void) {
  void* bVar2;
  u16 scriptID = (u16)Script_GetValue();
  u32_03004798 = 0x01;
  if ((VM_SeekToKeyword(0x6E) == 0) || ((VM_GetPC() != NULL) && (Script_GetValue() == 0))) {
    u32_03004798 |= 0x10;
  }
  SetMapInitScriptID((s16)scriptID);
  gStat->mapInitScriptID = scriptID;
  return NULL;
}

// Script_Ctrl_9906, CallWithArg, https://boktaihacking.net/wiki/Bytecode#Control_0x9906_(engine_call)
s32 VM_Ctrl_CallWithArg(void) {
  u16 subID = (u16)Script_GetValue();
  TaskFn fn = VM_GetSubroutine(subID);
  if (fn == NULL) {
    return -1;
  }
  fn((u16)Script_GetValue(), NULL);
  return 0;
}

// Script_Ctrl_b745, https://boktaihacking.net/wiki/Bytecode#Control_0xb745_(engine_call)
s32 VM_Ctrl_Call(void) {
  u16 subID = (u16)Script_GetValue();
  TaskFnNoArg fn = (TaskFnNoArg)VM_GetSubroutine(subID);
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
    if (VM_SeekToKeyword(0x73) != 0) {
      u32_03004798 |= 0x10;
    } else if (VM_SeekToKeyword(0x72) != 0) {
      u32_03004798 |= 0x100;
    }
  }
  return NULL;
}

static void nop_0823b12c(void) { return; }

s32 FUN_0823b130(void) {
  nop_0823b12c();
  FUN_08231780();
  gCtrlHandlers2.next = NULL;
  gCtrlHandlers2.len = ARRAY_COUNT(gCtrlHandlers2_ROM);
  gCtrlHandlers2.arr = gCtrlHandlers2_ROM;
  return VM_AddCtrlHandlers(&gCtrlHandlers2);
}
