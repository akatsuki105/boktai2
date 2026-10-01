#include "collision_map.h"
#include "global.h"
#include "vm.h"

void FUN_08231780(void);
void SetMapInitScriptID(u32 n);
bool32 FUN_0823a8b0(void);
void FUN_08230eec(ScriptRecord*);
bool32 FUN_082345ec(void);
void FUN_082349b8(CollisionMapEvent* ev, u32 param_2);

TaskFn VM_GetSubroutine(u32 subroutineID);

IWRAM_DATA SubroutineTable gCtrlHandlers2 = {};  // 0x030016E8

void* VM_Ctrl_Unused_0BB3(void) { return NULL; }

// https://boktaihacking.net/wiki/Bytecode#Control_0xc8bb_(load_map)
void* VM_Ctrl_LoadMap(void) {
  u16 scriptID = (u16)VM_GetValue();
  u32_03004798 = 0x01;
  if ((!VM_SeekToNamedArg('n')) || ((VM_GetPC() != NULL) && (VM_GetValue() == 0))) {
    u32_03004798 |= 0x10;
  }
  SetMapInitScriptID((s16)scriptID);
  gStat->mapInitScriptID = scriptID;
  return NULL;
}

// VM_Ctrl_9906, CallWithArg, https://boktaihacking.net/wiki/Bytecode#Control_0x9906_(engine_call)
s32 VM_Ctrl_CallWithArg(void) {
  u16 subID = (u16)VM_GetValue();
  TaskFn fn = VM_GetSubroutine(subID);
  if (fn == NULL) {
    return -1;
  }
  fn((u16)VM_GetValue(), NULL);
  return 0;
}

// VM_Ctrl_b745, https://boktaihacking.net/wiki/Bytecode#Control_0xb745_(engine_call)
s32 VM_Ctrl_Call(void) {
  u16 subID = (u16)VM_GetValue();
  TaskFnNoArg fn = (TaskFnNoArg)VM_GetSubroutine(subID);
  if (fn == NULL) {
    return -1;
  }
  gVM.result = fn();
  return 0;
}

// https://boktaihacking.net/wiki/Bytecode#Control_0x22ff_(TODO)
// スクリプトからIDと可変個のu16値を読み取り、1件のレコードとして FUN_08230eec のテーブルに登録する
s32 VM_Ctrl_22FF(void) {
  u16 args[16];
  ScriptRecord rec;
  u16* p;
  s16 count;

  rec.id = VM_GetValue();
  rec.values = args;
  p = args;
  for (count = 0; VM_GetPC() != NULL; count++) {
    *p++ = VM_GetValue();
  }
  rec.count = count;
  FUN_08230eec(&rec);
  return 0;
}

void* VM_Ctrl_Unused_C091(void* _) { return _; }

// Zone (in "collision_map.h") の示す範囲に重なったときに呼ばれるコールバックを設定する
NAKED s32 VM_Ctrl_SetZoneCallback(void* r0) { INCFUNC("asm/func/VM_Ctrl_SetZoneCallback.inc"); }

// https://boktaihacking.net/wiki/Bytecode#Control_0xe43c_(TODO)
void* VM_Ctrl_E43C(void) {
  bool32 bVar1 = FUN_0823a8b0();
  if (!bVar1) {
    u32_03004798 = 0x40;
    if (VM_SeekToNamedArg('s')) {
      u32_03004798 |= 0x10;
    } else if (VM_SeekToNamedArg('r')) {
      u32_03004798 |= 0x100;
    }
  }
  return NULL;
}

static void nop_0823b12c(void) { return; }

static const Subroutine sCtrlHandlers2[8] = {
    {id : 0x22FF, fn : (void*)VM_Ctrl_22FF           },
    {id : 0xB745, fn : (void*)VM_Ctrl_Call           },
    {id : 0x9906, fn : (void*)VM_Ctrl_CallWithArg    },
    {id : 0xD4CB, fn : (void*)VM_Ctrl_SetZoneCallback},
    {id : 0xC8BB, fn : (void*)VM_Ctrl_LoadMap        },
    {id : 0x0BB3, fn : (void*)VM_Ctrl_Unused_0BB3    },
    {id : 0xC091, fn : (void*)VM_Ctrl_Unused_C091    },
    {id : 0xE43C, fn : (void*)VM_Ctrl_E43C           },
};  // 0x08DBD758

s32 FUN_0823b130(void) {
  nop_0823b12c();
  FUN_08231780();
  gCtrlHandlers2.next = NULL;
  gCtrlHandlers2.len = ARRAY_COUNT(sCtrlHandlers2);
  gCtrlHandlers2.arr = sCtrlHandlers2;
  return VM_AddCtrlHandlers(&gCtrlHandlers2);
}
