#include "collision_map.h"
#include "global.h"
#include "vm.h"

void FUN_08231780(void);
void SetMapInitScriptID(u32 n);
bool32 FUN_0823a8b0(void);
void FUN_08230eec(ScriptRecord*);
bool32 FUN_082345ec(void);
void FUN_082349b8(CollisionMapEvent* ev, u32 param_2);
Zone* FindZonesByID(ZoneID16 id, u16* count);

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
s32 VM_Ctrl_SetZoneCallback(void* r0) {
  CollisionMapEvent ev;
  s32 type;
  u32 val;
  u8* pc;
  s32 i;

  FUN_082345ec();
  ClearMemory(&ev, sizeof(ev));
  ev.zoneID = VM_GetValue();
  ev.unk_6 = VM_GetValue();
  if (VM_SeekToNamedArg('m')) {
    ev.unk_4 = VM_GetValue();
  } else {
    ev.unk_4 = 0xDD2;
  }

  ev.unk_a = VM_GetNamedArgValue('t', 0);
  ev.flags = 0;
  if (ev.unk_6 == 0x3F) {
    ev.unk_6 = 0x14C9;
  }
  if (ev.unk_4 == 0x3F) {
    ev.unk_4 = 0x14C9;
  } else if (ev.unk_4 == 0x2A) {
    ev.unk_4 = 0x1516;
  }

  for (i = 0; i < 4; i++) {
    ev.args1[i] = 0;
  }
  if (VM_SeekToNamedArg('w')) {
    for (i = 0; i < 4; i++) {
      pc = VM_GetPC();
      if (pc == NULL) {
        break;
      }
      ev.args1[i] = VM_GetValueAt(pc);
    }
  }

  for (i = 0; i < 4; i++) {
    ev.args2[i] = 0;
  }
  if (VM_SeekToNamedArg('s')) {
    for (i = 0; i < 4; i++) {
      pc = VM_GetPC();
      if (pc == NULL) {
        break;
      }
      ev.args2[i] = VM_GetValueAt(pc);
    }
  }

  if (VM_SeekToNamedArg('b')) {
    ev.flags |= 0x10;
    ev.unk_20 = (u8*)VM_GetValue();
  }

  if (VM_SeekToNamedArg('e')) {
    VM_DecodeValue(VM_GetPC(), &type, &val);
    ev.scriptPC = (u8*)val;
  } else if (VM_SeekToNamedArg('p')) {
    ev.flags |= 0x20;
    ev.scriptPC = (u8*)VM_GetValue();
  }

  ev.flags |= 0;  // 原典のまま, 読み書きするだけで値は変わらない
  ev.zoneCount = 0;
  ev.zones = FindZonesByID(ev.zoneID, &ev.zoneCount);
  if (ev.zones == NULL) {
    return -1;
  }

  FUN_082349b8(&ev, (u32)r0);
  return 0;
}

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
