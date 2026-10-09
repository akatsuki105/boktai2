#include "global.h"
#include "malloc.h"
#include "vm.h"

// パスワード (ふっかつのじゅもん) の解析用に FUN_08011584 が一時的に確保する作業領域
typedef struct {
  u8 unk_00[0x18];         // 0x00, まだ未解析
  char password[0x30];     // 0x18, タグを除いたパスワード文字列
  u8 unk_48[0x74 - 0x48];  // 0x48, まだ未解析
  char* charTable;         // 0x74, パスワードに使える文字の並び
  u8* nameTablePc;         // 0x78, 名前に使える文字テーブルの VM バイトコード位置
  u32 rngState;            // 0x7C, 線形合同法の内部状態, 初期値 0x0008C159
  u8 unk_80[140 - 0x80];   // 0x80, まだ未解析
} PasswordDecoder;
static_assert(sizeof(PasswordDecoder) == 140);

// 線形合同法で乱数を1ステップ進める
u32 FUN_08011110(PasswordDecoder* p) {
  p->rngState = p->rngState * 0x6262C05D + 1;
  return p->rngState;
}

NAKED s32 FUN_08011124(PasswordDecoder* p) { INCFUNC("asm/func/FUN_08011124.inc"); }

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

NAKED s32 FUN_080111a4(PasswordDecoder* p) { INCFUNC("asm/func/FUN_080111a4.inc"); }

NAKED u32 FUN_080111d8(u8* p, s32 start, s32 count) { INCFUNC("asm/func/FUN_080111d8.inc"); }

NAKED s32 PasswordDecoder_IsIllegalName(PasswordDecoder* p) { INCFUNC("asm/func/PasswordDecoder_IsIllegalName.inc"); }

NAKED s32 PasswordDecoder_Parse(PasswordDecoder* p) { INCFUNC("asm/func/PasswordDecoder_Parse.inc"); }

void PasswordDecoder_NOP(PasswordDecoder* p) {
  s32 i;

  for (i = 4; i >= 0; i--) {
  }
}

NAKED void PasswordDecoder_SaveChanges(PasswordDecoder* p, u8* name) { INCFUNC("asm/func/PasswordDecoder_SaveChanges.inc"); }

NAKED s32 PasswordDecoder_StripTags(char* dst, char* src, s32 max) { INCFUNC("asm/func/PasswordDecoder_StripTags.inc"); }

// パスワード文字列を解析してセーブデータに反映する, 戻り値が負なら失敗
// 残差は53/53命令でレジスタ割当のみ, 原典は p を r5, charTablePc と ret を r4 に置くが逆になる, 宣言順の入れ替えと宣言/代入の分離は試済
NON_MATCH s32 FUN_08011584(char* password, u8* charTablePc, u8* nameTablePc, u8* name) {
#ifdef NONMATCHING_C
  s32 ret;
  PasswordDecoder* p = Malloc(sizeof(PasswordDecoder));

  if (p == NULL) {
    return -1;
  }

  ClearMemory(p, sizeof(PasswordDecoder));
  p->charTable = Textbox_LookupString(VM_ParseStringRef(charTablePc));
  p->nameTablePc = nameTablePc;
  p->rngState = 0x0008C159;
  PasswordDecoder_StripTags(p->password, password, 0x30);

  ret = FUN_080111a4(p);
  if (ret >= 0) {
    ret = PasswordDecoder_Parse(p);
    if (ret >= 0) {
      PasswordDecoder_SaveChanges(p, name);
      PasswordDecoder_NOP(p);
    }
  }
  Free(p);
  return ret;
#else
  INCFUNC("asm/func/FUN_08011584.inc");
#endif
}

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
