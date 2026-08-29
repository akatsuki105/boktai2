#include "vm.h"

#include "entity.h"
#include "file.h"
#include "global.h"
#include "malloc.h"

static void FUN_08231c80(void);
void FUN_082324b0(void);
void VM_ClearScratchpad(void);

const u8 u8_ARRAY_085b01c8[8] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

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
NAKED bool32 prepare_08231510(u8 keyword) { INCFUNC("asm/func/prepare_08231510.inc"); }

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
 * @param scriptID スクリプトID, gScriptTable.entries のインデックスに変換する際に -1 することに注意
 * @param unk ScriptDirectory.script_entries のエントリの bit24..31 をここに書き込む (用途不明)
 */
u8* Script_LookupById(u32 scriptID, u32* unk) {
  u32 idx = (scriptID & 0x7FFFFFFF) - 1;
  u8* ptr = (u8*)&gScriptTable.entries[idx];
  *unk = ptr[3];
  return &gScriptTable.bytecode[(*(s32*)ptr) & 0x00FFFFFF];
}

NAKED s32 Script_ExecById(u32 scriptID, UNK_PTR r1) { INCFUNC("asm/func/Script_ExecById.inc"); }

NAKED s32 FUN_082318d0(u8* pc) { INCFUNC("asm/func/FUN_082318d0.inc"); }

NAKED UNK_PTR FUN_0823193c(UNK_PTR p, u32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0823193c.inc"); }

NAKED char* Textbox_LookupString(s32 stringID) { INCFUNC("asm/func/Textbox_LookupString.inc"); }

/**
 * @param d &gScriptDirectory (0x08CBF248)
 * @note 0x082319A8
 * @note a.k.a. Script_LoadIndex
 */
NAKED static s32 VM_MountScriptDirectory(ScriptDirectory* d) { INCFUNC("asm/func/VM_MountScriptDirectory.inc"); }

NAKED UNK_PTR FUN_08231a74(void) { INCFUNC("asm/func/FUN_08231a74.inc"); }

NAKED void VM_SaveScriptTable(ScriptTable* tbl) { INCFUNC("asm/func/VM_SaveScriptTable.inc"); }

NAKED void VM_RestoreScriptTable(ScriptTable* tbl) { INCFUNC("asm/func/VM_RestoreScriptTable.inc"); }

NAKED bool32 Script_ExecBlock(u8* pc, UNK_PTR param_2, s32 param_3) { INCFUNC("asm/func/Script_ExecBlock.inc"); }

NAKED s32 Script_ExecByPointer(u8* pc, UNK_PTR param_2) { INCFUNC("asm/func/Script_ExecByPointer.inc"); }

NAKED s32 Script_Exec(u8* pc, UNK_PTR param_2, UNK_PTR param_3) { INCFUNC("asm/func/Script_Exec.inc"); }

NAKED void FUN_08231ba8(void) { INCFUNC("asm/func/FUN_08231ba8.inc"); }

NAKED s32 FUN_08231bcc(void) { INCFUNC("asm/func/FUN_08231bcc.inc"); }

void FUN_08231be0(u32 scriptID) { gMapInitScriptID = scriptID; }

void FUN_08231bec(void) {
  FUN_08231770();
  FUN_08231c80();
  FUN_08231780();
  FUN_082324b0();
  VM_MountScriptDirectory(GetFile(DIR_SCRIPT, 0xA41E));
  FUN_08231be0(0);
}

void VM_ClearScratchpad_Proxy(void) { VM_ClearScratchpad(); }

NAKED void RandomizeGameStateAddr(void) { INCFUNC("asm/func/RandomizeGameStateAddr.inc"); }

static void FUN_08231c80(void) {
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
