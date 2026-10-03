#include "global.h"
#include "vm.h"

NAKED u32 FUN_08011110(unknown* p) { INCFUNC("asm/func/FUN_08011110.inc"); }

NAKED s32 FUN_08011124(unknown* p) { INCFUNC("asm/func/FUN_08011124.inc"); }

// 2バイト1組のテーブル64エントリから (lo, hi) の組を探して添字を返す, 無ければ -1
s32 FUN_08011178(u8* table, s32 lo, s32 hi) {
  s32 i;

  for (i = 0; i < 64; i++, table += 2) {
    if (table[0] == lo && table[1] == hi) {
      return i;
    }
  }
  return -1;
}

NAKED s32 FUN_080111a4(unknown* p) { INCFUNC("asm/func/FUN_080111a4.inc"); }

NAKED u32 FUN_080111d8(u8* p, s32 start, s32 count) { INCFUNC("asm/func/FUN_080111d8.inc"); }

NAKED s32 PasswordDecoder_IsIllegalName(unknown* p) { INCFUNC("asm/func/PasswordDecoder_IsIllegalName.inc"); }

NAKED s32 PasswordDecoder_Parse(unknown* p) { INCFUNC("asm/func/PasswordDecoder_Parse.inc"); }

void PasswordDecoder_NOP(unknown* p) {
  s32 i;

  for (i = 4; i >= 0; i--) {
  }
}

NAKED void PasswordDecoder_SaveChanges(unknown* p, char* name) { INCFUNC("asm/func/PasswordDecoder_SaveChanges.inc"); }

NAKED s32 PasswordDecoder_StripTags(char* dst, char* src, s32 max) { INCFUNC("asm/func/PasswordDecoder_StripTags.inc"); }

NAKED s32 FUN_08011584(char* password, u8* charTablePc, u8* nameTablePc, u8* name) { INCFUNC("asm/func/FUN_08011584.inc"); }

// '.c' と '.n' の文字テーブルと '.d' のパスワード文字列で FUN_08011584 を呼ぶ
void FUN_08011608(void) {
  if (VM_SeekToNamedArg('c')) {
    u8* charTablePc = VM_GetPC();

    if (VM_SeekToNamedArg('n')) {
      u8* nameTablePc = VM_GetPC();

      if (nameTablePc != NULL && VM_SeekToNamedArg('d')) {
        u8* passwordPc = VM_GetPC();

        if (passwordPc != NULL) {
          FUN_08011584(Textbox_LookupString(VM_ParseStringRef(passwordPc)), charTablePc, nameTablePc, gStat->name);
        }
      }
    }
  }
}
