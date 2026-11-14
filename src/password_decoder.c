#include "global.h"
#include "malloc.h"
#include "vm.h"

// パスワードから読み出した値, 1 つの値を u16 に1つずつ入れる
typedef struct {
  u16 unk_00;   // 0x00, 9 ビット
  u16 unk_02;   // 0x02, 6 ビット, gStat->unk_00a へ
  u16 unk_04;   // 0x04, 6 ビット
  u16 unk_06;   // 0x06, 6 ビット
  u16 unk_08;   // 0x08, 3 ビット
  u16 unk_0a;   // 0x0A, 5 ビット
  u16 unk_0c;   // 0x0C, 3 ビット
  u16 unk_0e;   // 0x0E, 4 ビット
  u16 unk_10;   // 0x10, 5 ビット
  u16 unk_12;   // 0x12, 7 ビット
  u16 unk_14;   // 0x14, 4 ビット, gStat->unk_00c へ
  u16 unk_16;   // 0x16, 5 ビット, gStat->unk_00e へ
  u16 name[5];  // 0x18, 名前の 2 バイト目, 0 で終わり, 0xF0 は名前の文字表の 0xA0 番の文字
  u16 unk_22;   // 0x22
  u16 unk_24;   // 0x24, 6 ビット, PasswordDecoder.version が 1 のときだけ
  u16 unk_26;   // 0x26, 6 ビット, PasswordDecoder.version が 1 のときだけ
  u16 unk_28;   // 0x28, 8 ビット, PasswordDecoder.version が 1 のときだけ
  u16 unk_2a;   // 0x2A
} PasswordData;
static_assert(sizeof(PasswordData) == 44);

// パスワード (ふっかつのじゅもん) の解析用に FUN_08011584 が一時的に確保する作業領域
typedef struct {
  u8 decoded[24];       // 0x00, FUN_080111a4 が password を2文字ずつ charTable の添字に直して入れる
  char password[0x30];  // 0x18, タグを除いたパスワード文字列
  PasswordData data;    // 0x48
  char* charTable;      // 0x74, パスワードに使える文字の並び
  u8* nameTablePc;      // 0x78, 名前に使える文字テーブルの VM バイトコード位置
  u32 rngState;         // 0x7C, 線形合同法の内部状態, 初期値 0x0008C159
  u32 version;          // 0x80, 3 ビット, 1 なら unk_24 / unk_26 / unk_28 も入っている
  u32 crc;              // 0x84, 16 ビット, decoded の 5 文字目以降の CRC-16 の反転と一致しなければ不正
  u32 key;              // 0x88, パスワードに入っている鍵 (PasswordScreen.key), 文字を解く乱数をこの回数 + 4 だけ空回しする
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

// 名前の文字がどちらの文字表にも無ければ 1 を返す, 0xEC だけは 0xF0 に置き換えて許す
// 残差: 58/58 命令, 原典は文字表を探す内側のループを回転させず (先頭の判定へ飛び込む形), *c を毎回読み直し, c のポインタを外側用と内側用の2本に持つ
// 試済: 文字をローカルに受ける, for (;;), 探索を (u8* table, u16* c) の static inline に分ける (読み直しと t + 1 の位置は揃うが回転は残る), 外側を p->data.name[i] の直接参照にする
NON_MATCH s32 PasswordDecoder_IsIllegalName(PasswordDecoder* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 5; i++) {
    u16* c = &p->data.name[i];

    if (*c != 0) {
      bool32 found = FALSE;
      s32 t;

      for (t = 0; t < 2; t++) {
        u8* s = GetStringByID(VM_ParseStringRef(p->nameTablePc) + t);

        while (s[0] != 0) {
          if (s[1] == *c) {
            found = TRUE;
            break;
          }
          s += 2;
        }
      }
      if (!found) {
        if (*c != 0xEC) {
          return 1;
        }
        *c = 0xF0;
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/PasswordDecoder_IsIllegalName.inc");
#endif
}

// decoded から CRC を確かめて値を読み出す, CRC が合わなければ -2, 名前や値が不正なら -1
s32 PasswordDecoder_Parse(PasswordDecoder* p) {
  PasswordData* data = &p->data;
  s32 pos;
  u32 crc;
  s32 i;
  u32 j;

  p->version = PasswordDecoder_GetBits(p->decoded, 0, 3);
  p->crc = PasswordDecoder_GetBits(p->decoded, 3, 16);
  p->key = PasswordDecoder_GetBits(p->decoded, 19, 2);
  pos = 21;

  crc = 0xFFFF;
  for (i = 4; i < 24; i++) {
    crc ^= p->decoded[i] << 8;
    for (j = 0; j < 8; j++) {
      if (crc & 0x8000) {
        crc = (crc << 1) ^ 0x1021;
      } else {
        crc <<= 1;
      }
    }
  }
  if ((~crc & 0xFFFF) != p->crc) {
    return -2;
  }

  PasswordDecoder_UnscrambleChars(p);
  data->unk_00 = PasswordDecoder_GetBits(p->decoded, pos, 9);
  pos += 9;
  data->unk_02 = PasswordDecoder_GetBits(p->decoded, pos, 6);
  pos += 6;
  data->unk_04 = PasswordDecoder_GetBits(p->decoded, pos, 6);
  pos += 6;
  data->unk_06 = PasswordDecoder_GetBits(p->decoded, pos, 6);
  pos += 6;
  data->unk_08 = PasswordDecoder_GetBits(p->decoded, pos, 3);
  pos += 3;
  data->unk_0a = PasswordDecoder_GetBits(p->decoded, pos, 5);
  pos += 5;
  data->unk_0c = PasswordDecoder_GetBits(p->decoded, pos, 3);
  pos += 3;
  data->unk_0e = PasswordDecoder_GetBits(p->decoded, pos, 4);
  pos += 4;
  data->unk_10 = PasswordDecoder_GetBits(p->decoded, pos, 5);
  pos += 5;
  data->unk_12 = PasswordDecoder_GetBits(p->decoded, pos, 7);
  pos += 7;
  data->unk_14 = PasswordDecoder_GetBits(p->decoded, pos, 4);
  pos += 4;
  data->unk_16 = PasswordDecoder_GetBits(p->decoded, pos, 5);
  pos += 5;
  for (i = 0; i < 5; i++) {
    data->name[i] = PasswordDecoder_GetBits(p->decoded, pos, 8);
    pos += 8;
  }
  if (p->version == 1) {
    data->unk_24 = PasswordDecoder_GetBits(p->decoded, pos, 6);
    pos += 6;
    data->unk_26 = PasswordDecoder_GetBits(p->decoded, pos, 6);
    pos += 6;
    data->unk_28 = PasswordDecoder_GetBits(p->decoded, pos, 8);
  }

  if (data->name[0] == 0 || PasswordDecoder_IsIllegalName(p) != 0 || data->unk_0c == 0 || (data->unk_04 == 0 && data->unk_06 == 0)) {
    return -1;
  }
  return 0;
}

void PasswordDecoder_NOP(PasswordDecoder* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
  }
}

// パスワードの名前を 2 バイト文字に直して name へ書き, パスワードの値を gStat に入れる
// 残差: 52/54 命令, 原典は gStat への3つの書き込みのたびに gStat を読み直し, 引数 name を r4 へ写すのを data / src を作った後にする
// 試済: gStat の書き込みを *(&gStat->x) にする, 0x08-0x0E を s16 の配列にして *(gStat->arr + n) で書く (読み直しは起きない)
NON_MATCH void PasswordDecoder_SaveChanges(PasswordDecoder* p, u8* name) {
#ifdef NONMATCHING_C
  PasswordData* data = &p->data;
  u16* src = data->name;
  u16 c;
  s32 i;

  for (i = 0; i < 5 && (c = *src) != 0; i++, name += 2, src++) {
    if (c == 0xF0) {
      char* table = GetStringByID(VM_ParseStringRef(p->nameTablePc));

      name[0] = table[0xA0];
      name[1] = table[0xA1];
    } else {
      name[0] = 0x80;
      name[1] = c;
    }
  }
  *name = 0;
  gStat->unk_00a = data->unk_02;
  gStat->unk_00c = data->unk_14;
  gStat->unk_00e = data->unk_16;
#else
  INCFUNC("asm/func/PasswordDecoder_SaveChanges.inc");
#endif
}

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
