#include "vm.h"

#include "entity.h"
#include "global.h"
#include "malloc.h"

void FUN_08230e30(u16 id, void* r1, s32 r2);
bool32 FUN_082326d8(void);

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

INCASM("asm/vm.inc");

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

// 0x082324dc, a.k.a Script_RunOperator
s32 Arithmetic(u32 opcode, s32 a, s32 b) {
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

NAKED void* Script_RunExpression(u8* code) { INCFUNC("asm/func/Script_RunExpression.inc"); }

void FUN_082326a0(void) {
  void* p = Malloc(3620);
  ClearMemory(p, 3620);
  FUN_08230e30(0x56c2, p, 1);
  gUnkPtr = p;
  FUN_082326d8();
}
