#include "global.h"
#include "malloc.h"
#include "vm.h"

// パスワード (ふっかつのじゅもん) の解析用に FUN_08011584 が一時的に確保する作業領域
typedef struct {
  u8 decoded[24];          // 0x00, FUN_080111a4 が password を2文字ずつ charTable の添字に直して入れる
  char password[0x30];     // 0x18, タグを除いたパスワード文字列
  u8 unk_48[0x74 - 0x48];  // 0x48, まだ未解析
  char* charTable;         // 0x74, パスワードに使える文字の並び
  u8* nameTablePc;         // 0x78, 名前に使える文字テーブルの VM バイトコード位置
  u32 rngState;            // 0x7C, 線形合同法の内部状態, 初期値 0x0008C159
  u8 unk_80[0x88 - 0x80];  // 0x80, まだ未解析
  u32 key;                 // 0x88, パスワードに入っている鍵 (PasswordScreen.key), 文字を解く乱数をこの回数 + 4 だけ空回しする
} PasswordDecoder;
static_assert(sizeof(PasswordDecoder) == 140);

// 線形合同法で乱数を1ステップ進める
u32 PasswordDecoder_NextRandom(PasswordDecoder* p) {
  p->rngState = p->rngState * 0x6262C05D + 1;
  return p->rngState;
}

// 乱数を key + 4 回空回ししてから, decoded の後半20文字を乱数列で XOR して解く
// 残差6命令 (44 対 38), gcc は 0x3F をループ外へ出して r8 まで使い出すが, 原典は毎回 movs で作り直す, PasswordScreen_ScrambleChars と同じ壁
// 添字形 / ポインタ形 / % 64 は試済, xor の結果を u8 のローカルに受けると巻き上げは止まるが u8 への切り詰め (lsl/lsr) が残る, u32 のローカルでは巻き上がる
NON_MATCH s32 PasswordDecoder_UnscrambleChars(PasswordDecoder* p) {
#ifdef NONMATCHING_C
  u32 acc = 0xFFFF;
  u32 i;

  for (i = 0; i < p->key + 4; i++) {
    acc ^= PasswordDecoder_NextRandom(p);
  }

  for (i = 0; i < 20; i++) {
    p->decoded[4 + i] = (acc ^ p->decoded[4 + i]) & 0x3F;
    acc ^= PasswordDecoder_NextRandom(p);
  }
  return 0;
#else
  INCFUNC("asm/func/PasswordDecoder_UnscrambleChars.inc");
#endif
}

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

// password を2文字ずつ charTable の添字に直して decoded へ入れる, 表に無い組があれば -1
s32 FUN_080111a4(PasswordDecoder* p) {
  u8* s = (u8*)p->password;
  s32 i;

  for (i = 0; i < 24; i++, s += 2) {
    u32 idx = FUN_08011178(p->charTable, s[0], s[1]);

    if (idx > 0x3F) {
      return -1;
    }
    p->decoded[i] = idx;
  }
  return 0;
}

// 1 文字 6 ビットの p の start ビット目から count ビットを下位から順に読む, 144 ビットを越えた分は 0
u32 PasswordDecoder_GetBits(u8* p, s32 start, s32 count) {
  u32 value = 0;
  s32 i;

  for (i = 0; i < count; i++) {
    s32 pos = start + i;
    s32 idx;
    s32 shift;

    if (pos >= 144) {
      break;
    }
    idx = Div(pos, 6);
    shift = Mod(pos, 6);
    value |= ((p[idx] >> shift) & 1) << i;
  }
  return value;
}

NAKED s32 PasswordDecoder_IsIllegalName(PasswordDecoder* p) { INCFUNC("asm/func/PasswordDecoder_IsIllegalName.inc"); }

NAKED s32 PasswordDecoder_Parse(PasswordDecoder* p) { INCFUNC("asm/func/PasswordDecoder_Parse.inc"); }

void PasswordDecoder_NOP(PasswordDecoder* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
  }
}

NAKED void PasswordDecoder_SaveChanges(PasswordDecoder* p, u8* name) { INCFUNC("asm/func/PasswordDecoder_SaveChanges.inc"); }

// src から <...> のタグを除いて dst へ写す, 2 バイト文字はそのまま写して max バイトで止め, 写した数を返す
// 残差: 51/50 命令, 原典はループの判定で読んだ *src をそのまま c に使い, 符号の判定を lsl で行う, こちらは本体で読み直して & 0x80 で判定する
// 試済: c を s8 (ldrsb になる), while ((c = *src) != 0) と (s8)c (ループの形が崩れる)
NON_MATCH s32 PasswordDecoder_StripTags(char* dst, char* src, s32 max) {
#ifdef NONMATCHING_C
  bool32 inTag = FALSE;
  s32 n = 0;

  while (*src != '\0') {
    u8 c = *src;

    if (!(c & 0x80)) {
      if (c == '<') {
        inTag = TRUE;
      } else if (c == '>') {
        inTag = FALSE;
      } else if (!inTag) {
        *dst++ = c;
        n++;
        if (n >= max) {
          break;
        }
      }
      src++;
    } else {
      inTag = FALSE;
      *dst++ = c;
      src++;
      n++;
      if (n >= max) {
        break;
      }
      if (*src == '\0') {
        break;
      }
      *dst++ = *src;
      src++;
      n++;
      if (n >= max) {
        break;
      }
    }
  }
  return n;
#else
  INCFUNC("asm/func/PasswordDecoder_StripTags.inc");
#endif
}

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
  p->charTable = GetStringByID(VM_ParseStringRef(charTablePc));
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
void Cmd_C673(void) {
  if (VM_SeekToNamedArg('c')) {
    u8* charTablePc = VM_GetPC();

    if (VM_SeekToNamedArg('n')) {
      u8* nameTablePc = VM_GetPC();

      if (nameTablePc != NULL && VM_SeekToNamedArg('d')) {
        u8* passwordPc = VM_GetPC();

        if (passwordPc != NULL) {
          FUN_08011584(GetStringByID(VM_ParseStringRef(passwordPc)), charTablePc, nameTablePc, gStat->name);
        }
      }
    }
  }
}
