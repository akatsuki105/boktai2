#include "collision_map.h"
#include "global.h"
#include "vm.h"
#include "vm_subroutine.h"

void VM_ClearCtrlHandlers(void);
bool32 GameSystem_IsMapChangeBlocked(void);
void FUN_08230eec(ScriptRecord*);
bool32 Map_HasCheckedZoneEvents(void);

void* VM_GetSubroutine(u32 subroutineID);

static CtrlHandlerTable gCtrlHandlers2;  // 0x030016E8, 制御命令ではこのハンドラ自体を直接みるのではなく、初期化時に gCtrlHandlers に登録してそれを制御命令が参照する

void* VM_Ctrl_Unused_0BB3(void) { return NULL; }

void* VM_Ctrl_LoadMap(void) {
  u16 scriptID = (u16)VM_GetValue();
  gMapChangeFlags = MAPCHANGE_LOAD;
  if ((!VM_SeekToNamedArg('n')) || ((VM_GetPC() != NULL) && (VM_GetValue() == 0))) {
    gMapChangeFlags |= MAPCHANGE_BACKUP;
  }
  SetMapInitScriptID((s16)scriptID);
  gStat->mapInitScriptID = scriptID;
  return NULL;
}

// 0x9906, EntityCreate
// IDは EUC-JPの文字列をハッシュ化した値
//   HashName("プレイヤー") -> 0xF5EB
//   HashName("シャイアン") -> 0x8E9F
s32 VM_Ctrl_CreateEntity(void) {
  u16 subID = (u16)VM_GetValue();
  EntityCreateFn fn = VM_GetSubroutine(subID);
  if (fn == NULL) {
    return -1;
  }
  fn((u16)VM_GetValue(), NULL);
  return 0;
}

// 0xB745, .bokc の NativeCall_B745
s32 VM_Ctrl_CallSubroutine(void) {
  u16 subID = (u16)VM_GetValue();
  SubroutineFn fn = VM_GetSubroutine(subID);
  if (fn == NULL) {
    return -1;
  }
  gVM.result = fn();
  return 0;
}

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
s32 VM_Ctrl_SetZoneCallback(u32 param) {
  CollisionMapEvent ev;
  s32 type;
  u32 val;
  u8* pc;
  s32 i;

  Map_HasCheckedZoneEvents();
  ClearMemory(&ev, sizeof(ev));
  ev.zoneID = VM_GetValue();
  ev.sourceID = VM_GetValue();
  if (VM_SeekToNamedArg('m')) {
    ev.trigger = VM_GetValue();
  } else {
    ev.trigger = 0xDD2;
  }

  ev.unk_a = VM_GetNamedArgValue('t', 0);
  ev.flags = 0;
  if (ev.sourceID == 0x3F) {
    ev.sourceID = 0x14C9;
  }
  if (ev.trigger == 0x3F) {
    ev.trigger = 0x14C9;
  } else if (ev.trigger == 0x2A) {
    ev.trigger = 0x1516;
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
    ev.keys = VM_GetValue();
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

  Map_InsertEvent(&ev, param);
  return 0;
}

void* VM_Ctrl_Restart(void) {
  bool32 bVar1 = GameSystem_IsMapChangeBlocked();
  if (!bVar1) {
    gMapChangeFlags = MAPCHANGE_RESTART;
    if (VM_SeekToNamedArg('s')) {
      gMapChangeFlags |= MAPCHANGE_BACKUP;
    } else if (VM_SeekToNamedArg('r')) {
      gMapChangeFlags |= MAPCHANGE_RESTORE;
    }
  }
  return NULL;
}

static void nop_0823b12c(void) { return; }

// こっちはランタイムに関係のないものばかりに見える
static const Subroutine sCtrlHandlers2[8] = {
    {id : 0x22FF,             fn : VM_Ctrl_22FF           },
    {id : BOKHASH("command"), fn : VM_Ctrl_CallSubroutine },
    {id : BOKHASH("chara"),   fn : VM_Ctrl_CreateEntity   },
    {id : BOKHASH("trap"),    fn : VM_Ctrl_SetZoneCallback},
    {id : BOKHASH("load"),    fn : VM_Ctrl_LoadMap        },
    {id : 0x0BB3,             fn : VM_Ctrl_Unused_0BB3    },
    {id : BOKHASH("map"),     fn : VM_Ctrl_Unused_C091    },
    {id : BOKHASH("restart"), fn : VM_Ctrl_Restart        },
};  // 0x08DBD758

s32 FUN_0823b130(void) {
  nop_0823b12c();
  VM_ClearCtrlHandlers();
  gCtrlHandlers2.next = NULL;
  gCtrlHandlers2.len = ARRAY_COUNT(sCtrlHandlers2);
  gCtrlHandlers2.arr = sCtrlHandlers2;
  return VM_AddCtrlHandlers(&gCtrlHandlers2);
}
