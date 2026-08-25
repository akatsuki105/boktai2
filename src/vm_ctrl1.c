#include "global.h"
#include "vm.h"

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

// clang-format off
static const Subroutine sCtrlHandlers1[6] = {
    {.id = 0x0D86, .fn = (void*)VM_Ctrl_If},
    {.id = 0x4A6F, .fn = (void*)VM_Ctrl_Switch},
    {.id = 0x64C0, .fn = (void*)VM_Ctrl_Unused_64C0},
    {.id = 0x121F, .fn = (void*)VM_Ctrl_CallIndirect},
    {.id = 0xCD3A, .fn = (void*)VM_Ctrl_Return},
    {.id = 0xB96E, .fn = (void*)VM_Ctrl_B96E},
}; // 0x085B01D0
// clang-format on

void FUN_082324b0(void) {
  gCtrlHandlers1.next = NULL;
  gCtrlHandlers1.len = Div(sizeof(sCtrlHandlers1), sizeof(Subroutine));
  gCtrlHandlers1.arr = sCtrlHandlers1;
  VM_AddCtrlHandlers(&gCtrlHandlers1);
}
