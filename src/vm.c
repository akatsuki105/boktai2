#include "vm.h"

#include "entity.h"
#include "global.h"
#include "malloc.h"

void VM_ClearScratchpad(void);

// a.k.a. Script_ReadLength, https://boktaihacking.net/wiki/Bytecode#Container_lengths
NAKED u8* VM_ReadContainerLength(u8* pc, u32* length) { INCFUNC("asm/func/VM_ReadContainerLength.inc"); }

// 次のキーワード命令または終了命令（いずれか先に出現する方）までのバイト数 を取得
// https://boktaihacking.net/wiki/Bytecode#Opcode_0x60_(control)
NAKED u8* VM_ReadCtrlNextKeyword(u8* pc, u32* length) { INCFUNC("asm/func/VM_ReadCtrlNextKeyword.inc"); }

// a.k.a. Script_GetValueCore
NAKED u8* VM_Step(u8* pc, u32* val, UNK_PTR r2) { INCFUNC("asm/func/VM_Step.inc"); }

void FUN_08231438(void) { gVM.unk_6c = &gVM.unk_70[0]; }

NAKED UNK_PTR FUN_08231448(UNK_PTR r0, s32 idx) { INCFUNC("asm/func/FUN_08231448.inc"); }

void FUN_0823146c(void* ptr) {
  if (ptr != NULL) {
    gVM.unk_6c = ptr;
  }
}

NAKED u32 VM_ParseParameter(u32 idx) { INCFUNC("asm/func/VM_ParseParameter.inc"); }

NAKED u32 VM_GetVariable(u32 varidx) { INCFUNC("asm/func/VM_GetVariable.inc"); }

NAKED void VM_StoreVariable(u32 varidx, u32 val) { INCFUNC("asm/func/VM_StoreVariable.inc"); }

NAKED void FUN_082314d4(void) { INCFUNC("asm/func/FUN_082314d4.inc"); }

NAKED void FUN_082314e4(u8* pc) { INCFUNC("asm/func/FUN_082314e4.inc"); }

NAKED void FUN_082314f4(void) { INCFUNC("asm/func/FUN_082314f4.inc"); }

void VM_SetPC(u8* addr) { gVM.pc = addr; }

// a.k.a. Script_SeekToKeyword
NAKED bool32 prepare_08231510(u8 val) { INCFUNC("asm/func/prepare_08231510.inc"); }

NAKED u32 VM_Ctrl_Switch_Internal(void) { INCFUNC("asm/func/VM_Ctrl_Switch_Internal.inc"); }

// a.k.a. Script_GetValueAt
NAKED void* VM_GetValueAt(u8* addr) { INCFUNC("asm/func/VM_GetValueAt.inc"); }

NAKED s32 FUN_082315c0(u8* pc, UNK_PTR r1) { INCFUNC("asm/func/FUN_082315c0.inc"); }

NAKED s32 FUN_082315f4(u8* pc, UNK_PTR r1) { INCFUNC("asm/func/FUN_082315f4.inc"); }

// a.k.a. Script_GetValueAtSafe
NAKED void* VM_GetValueAtSafe(u8* addr) { INCFUNC("asm/func/VM_GetValueAtSafe.inc"); }

void* VM_GetValueAtSafe_Proxy(u8* addr) { return VM_GetValueAtSafe(addr); }

// a.k.a. Script_ParseStringRef
NAKED s32 VM_ParseStringRef(u8* pc) { INCFUNC("asm/func/VM_ParseStringRef.inc"); }

NAKED void FUN_0823167c(UNK_PTR p) { INCFUNC("asm/func/FUN_0823167c.inc"); }

NAKED u8* FUN_08231698(u8* pc) { INCFUNC("asm/func/FUN_08231698.inc"); }

// a.k.a. Script_GetPc
NAKED u8* VM_GetPC(void) { INCFUNC("asm/func/VM_GetPC.inc"); }

NAKED u32 Script_GetValue(void) { INCFUNC("asm/func/Script_GetValue.inc"); }

NAKED s32 FUN_082316f4(UNK_PTR p) { INCFUNC("asm/func/FUN_082316f4.inc"); }

NAKED s32 FUN_08231708(UNK_PTR p) { INCFUNC("asm/func/FUN_08231708.inc"); }

// VM_GetValueSafe2 と全く同じ
void* VM_GetValueSafe1(void) { return VM_GetValueAtSafe(VM_GetPC()); }

// VM_GetValueSafe1 と全く同じ
void* VM_GetValueSafe2(void) { return VM_GetValueAtSafe(VM_GetPC()); }

s32 Unused_FUN_0823173c(void) { return VM_ParseStringRef(VM_GetPC()); }

NAKED s32 Script_GetKeywordValue(u8 val, s32 fallback) { INCFUNC("asm/func/Script_GetKeywordValue.inc"); }

void FUN_08231770(void) {
  FUN_08231438();
  FUN_082314d4();
}

void FUN_08231780(void) { gCtrlHandlers = NULL; }

s32 VM_AddCtrlHandlers(SubroutineTable* p) {
  p->next = gCtrlHandlers;
  gCtrlHandlers = p;
  return 0;
}

NAKED s32 FUN_0823179c(SubroutineTable* p) { INCFUNC("asm/func/FUN_0823179c.inc"); }

NAKED Subroutine* VM_GetControlHandler(u32 subID) { INCFUNC("asm/func/VM_GetControlHandler.inc"); }

NAKED bool32 Script_RunControl(u8* pc) { INCFUNC("asm/func/Script_RunControl.inc"); }

/**
 * @brief ScriptDirectory.script_entries をパースするだけ
 * @param offsets ScriptDirectory.script_entries (= 0x08cbf24c)
 * @param length ここにスクリプトの数を書き込む
 * @return &ScriptDirectory.offsets (= 0x08cca69c)
 */
NAKED void* VM_Parse_ScriptDirectory_ScriptEntries(s32* offsets, s32* length) { INCFUNC("asm/func/VM_Parse_ScriptDirectory_ScriptEntries.inc"); }

/**
 * @param unk ScriptDirectory.script_entries のエントリの bit24..31 をここに書き込む (用途不明)
 */
NAKED u8* Script_LookupById(u32 scriptID, u32* unk) { INCFUNC("asm/func/Script_LookupById.inc"); }

NAKED s32 Script_ExecById(u32 scriptID, UNK_PTR r1) { INCFUNC("asm/func/Script_ExecById.inc"); }

NAKED s32 FUN_082318d0(u8* pc) { INCFUNC("asm/func/FUN_082318d0.inc"); }

NAKED UNK_PTR FUN_0823193c(UNK_PTR p, u32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0823193c.inc"); }

NAKED char* Textbox_LookupString(s32 stringID) { INCFUNC("asm/func/Textbox_LookupString.inc"); }

/**
 * @param d &gScriptDirectory (0x08cbf248)
 */
NAKED s32 Script_LoadIndex(ScriptDirectory* d) { INCFUNC("asm/func/Script_LoadIndex.inc"); }

NAKED UNK_PTR FUN_08231a74(void) { INCFUNC("asm/func/FUN_08231a74.inc"); }

NAKED void VM_SaveScriptTable(ScriptTable* tbl) { INCFUNC("asm/func/VM_SaveScriptTable.inc"); }

NAKED void VM_RestoreScriptTable(ScriptTable* tbl) { INCFUNC("asm/func/VM_RestoreScriptTable.inc"); }

NAKED bool32 Script_ExecBlock(u8* pc, UNK_PTR param_2, s32 param_3) { INCFUNC("asm/func/Script_ExecBlock.inc"); }

NAKED s32 Script_ExecByPointer(u8* pc, UNK_PTR param_2) { INCFUNC("asm/func/Script_ExecByPointer.inc"); }

NAKED s32 Script_Exec(u8* pc, UNK_PTR param_2, UNK_PTR param_3) { INCFUNC("asm/func/Script_Exec.inc"); }

NAKED void FUN_08231ba8(void) { INCFUNC("asm/func/FUN_08231ba8.inc"); }

NAKED s32 FUN_08231bcc(void) { INCFUNC("asm/func/FUN_08231bcc.inc"); }

void FUN_08231be0(u32 scriptID) { gMapInitScriptID = scriptID; }

NAKED void FUN_08231bec(void) { INCFUNC("asm/func/FUN_08231bec.inc"); }

void VM_ClearScratchpad_Proxy(void) { VM_ClearScratchpad(); }

NAKED void RandomizeGameStateAddr(void) { INCFUNC("asm/func/RandomizeGameStateAddr.inc"); }

void FUN_08231c80(void) {
  ClearMemory(gWorld, sizeof(World));
  ClearMemory(gStat, sizeof(GameInfo));
}

NAKED void FUN_08231ca8(void) { INCFUNC("asm/func/FUN_08231ca8.inc"); }

void Save_BackupStatAndWorld(void) {
  FUN_08230ab0((void*)gStatBackup, (void*)gStat, sizeof(GameInfo));
  FUN_08230ab0((void*)gWorldBackup, (void*)gWorld, sizeof(World));
}

void RestoreGameState(void) {
  FUN_08230ab0((void*)gStat, (void*)gStatBackup, sizeof(GameInfo));
  FUN_08230ab0((void*)gWorld, (void*)gWorldBackup, sizeof(World));
}

// gStat を フィールド単位でバックアップするための関数
void FUN_08231d5c(void* statFieldPtr, s32 bytesize) {
  s32 offset = (s32)statFieldPtr - (s32)gStat;
  FUN_08230ab0((u8*)gStatBackup + offset, (u8*)statFieldPtr, bytesize);
}

// gStatのフィールドのアドレスを受け取り、gStatBackupの対応するフィールドのアドレスを返す
void* FUN_08231d80(void* statFieldPtr) {
  s32 offset = (s32)statFieldPtr - (s32)gStat;
  return (u8*)gStatBackup + offset;
}

void VM_ClearScratchpad(void) { ClearMemory(gScratch, sizeof(UnkGameStruct)); }

// https://boktaihacking.net/wiki/Bytecode#Opcode_0x10_(pointer), https://boktaihacking.net/wiki/Bytecode#Opcode_0x20_(indexed_pointer)
NAKED void Script_LoadPointer(void* src, s32 cmdAndArgs, s32 offset, void* out) { INCFUNC("asm/func/Script_LoadPointer.inc"); }

NAKED u8* ReadMemory(u8* pc, u32* op, void* out) { INCFUNC("asm/func/ReadMemory.inc"); }

NAKED void Script_StorePointerCore(void* dst, s32 cmdAndArgs, s32 offset, u32 val) { INCFUNC("asm/func/Script_StorePointerCore.inc"); }

NAKED u8* Script_StorePointer(u8* pc, u32 val) { INCFUNC("asm/func/Script_StorePointer.inc"); }

NAKED u8* FUN_0823201c(u8* pc, u8* dst) { INCFUNC("asm/func/FUN_0823201c.inc"); }

NAKED void FUN_0823206c(u8* pc, s32 offset, u32 val) { INCFUNC("asm/func/FUN_0823206c.inc"); }

NAKED void* FUN_082320e4(u8* pc, s32 offset) { INCFUNC("asm/func/FUN_082320e4.inc"); }

NAKED u8* FUN_08232160(u8* pc) { INCFUNC("asm/func/FUN_08232160.inc"); }

NAKED UNK_PTR FUN_082321e0(u8* pc) { INCFUNC("asm/func/FUN_082321e0.inc"); }

GameInfo* FUN_08232254(void) { return gStatBackup; }

World* FUN_08232260(void) { return gWorldBackup; }

NAKED void VM_Ctrl_B96E_Internal(UNK_PTR r1, UNK_PTR r2) { INCFUNC("asm/func/VM_Ctrl_B96E_Internal.inc"); }

NAKED u8* VM_Ctrl_If_Internal(u8* pc) { INCFUNC("asm/func/VM_Ctrl_If_Internal.inc"); }

// 0x0D86
NAKED bool32 VM_Ctrl_If(u8* pc) { INCFUNC("asm/func/VM_Ctrl_If.inc"); }

// 0x4A6F
NAKED bool32 VM_Ctrl_Switch(u8* pc) { INCFUNC("asm/func/VM_Ctrl_Switch.inc"); }

NAKED bool32 VM_Ctrl_Unused_64C0(u8* pc) { INCFUNC("asm/func/VM_Ctrl_Unused_64C0.inc"); }

// 0xCD3A: 現在実行中のスクリプトを終了(オプションで戻り値を返す)
NAKED bool32 VM_Ctrl_Return(u8* _) { INCFUNC("asm/func/VM_Ctrl_Return.inc"); }

// https://boktaihacking.net/wiki/Bytecode#Control_0xb96e_(TODO)
NAKED bool32 VM_Ctrl_B96E(u8* _) { INCFUNC("asm/func/VM_Ctrl_B96E.inc"); }

// https://boktaihacking.net/wiki/Bytecode#Control_0x121f_(call_indirect)
NAKED bool32 VM_Ctrl_CallIndirect(u8* _) { INCFUNC("asm/func/VM_Ctrl_CallIndirect.inc"); }

void FUN_082324b0(void) {
  gCtrlHandlers1.next = NULL;
  gCtrlHandlers1.len = Div(sizeof(gCtrlHandlers1_ROM), sizeof(Subroutine));
  gCtrlHandlers1.arr = gCtrlHandlers1_ROM;
  VM_AddCtrlHandlers(&gCtrlHandlers1);
}

/**
 * @param opcode 0xA1..0xBF, https://boktaihacking.net/wiki/Bytecode#Opcode_0xa0-0xbf_(operator)
 */
s32 VM_RunOperator(u32 opcode, s32 a, s32 b) {
  switch (opcode - 1) {
    case 0: {
      return -b;
    }
    case 1: {
      return b == 0;
    }
    case 2: {
      return ~b;
    }
    case 3: {
      return a + b;
    }
    case 4: {
      return a - b;
    }
    case 5: {
      return a * b;
    }
    case 6: {
      return Div(a, b);
    }
    case 7: {
      return Mod(a, b);
    }
    case 8: {
      return a << b;
    }
    case 9: {
      return ((u32)a) >> b;
    }
    case 10: {
      return a == b;
    }
    case 11: {  // 同じ符号か
      return ((u32)(-(a ^ b) | (a ^ b))) >> 31;
    }
    case 12: {
      return a < b;
    }
    case 13: {
      return a <= b;
    }
    case 14: {
      return a > b;
    }
    case 15: {
      return a >= b;
    }
    case 16: {
      return a | b;
    }
    case 17: {
      return a & b;
    }
    case 18: {
      return a ^ b;
    }
    case 19: {
      return ((a != 0) || (b != 0));
    }
    case 20: {
      bool32 result = FALSE;
      if (a != 0) {
        result = ((u32)((-b) | b)) >> 31;
      }
      return result;
    }
    case 22: {
      return b;
    }
    case 21:
    default: {
      return 0;
    }
  }
}

NAKED u32 VM_RunExpression(u8* pc) { INCFUNC("asm/func/VM_RunExpression.inc"); }
