#include "font.h"
#include "global.h"
#include "player.h"
#include "sound.h"
#include "text.h"
#include "vm.h"

// 本文中に書けるタグの一覧, TextRenderer_HandleTag が '<' の次からタグ名を引いて処理する
//
// <WEIGHT> / </WEIGHT>  style を 1 / 0 にする
// <ALTER> / </ALTER>    同じく style を 1 / 0 にする
// <NONSEL> / </NONSEL>  style を 2 / 0 にする
// <UVMOJI> / </UVMOJI>  同じく style を 2 / 0 にする
// <WAIT=n>              文字送り速度を n にする, 値が無ければ本体設定の速度に戻す
// <LOCK=n>              waitFrames に n を入れて次の行へ進むのを待たせる, 値が無ければ 0
// <LABEL=名前>          名前に対応する顔番号を face に入れ, 出している間は無音かつ速度 0 にする
// </LABEL>              <LABEL> が退避した速度に戻す
// <FACEOFF>             face を -1 にして顔を消す
// <NAME>                プレイヤー名を差し込む, mode 1 に切り替えて textAlt を読ませる
// <VAR=n>               vars[n] を10進に直して差し込む, mode 2 に切り替えて numBuf を読ませる
// <EXTEND=n>            extends[n] の文字列を差し込む, mode 3 に切り替えて extendText を読ませる
// <PROC=n>              n を pending に積む, TextRenderer_RunPending が scriptIds の添字として実行する
// <SOUND=n>             効果音 n を鳴らす, 値が無ければ 0xDD
// <MOJISE=名前>         文字送り音を切り替える, MOJISE_SYSTEM で gCharSounds[0], MOJISE_TALK で gCharSounds[1]
// <END>                 finished を立てて本文を終わらせる
// <PAREN> / </PAREN>    parenEnabled が立っているときだけ括弧を実際に1文字描く
//
// <LABEL> の値は顔番号への名前表 (0x08251B9C 以降) で, NONE だけ 0xFF (顔なし) で, あとは R_DJUNGO が 0 から HATENA が 0x1A まで並ぶ (KURO_BAN だけ 0x1D)
// 値が PLAYER と FUTARI のときだけ固定値ではなく Text_GetPlayerFace / Text_GetPairFace がプレイヤーを見て決める
// src/data/text に実際に出てくるのは PROC / END / LABEL / EXTEND / VAR / NAME / ALTER / WEIGHT / LOCK / WAIT / MOJISE / FACEOFF の12種類だけで, NONSEL / UVMOJI / SOUND / PAREN は本文側には現れない

const s16 gCharSounds[2] = {0x105, 0x106};  // 0x085AB458, TextRenderer_PlayCharSound が charSoundIdx で選ぶ文字送り音

// 0x1F エスケープの次のバイトと文字コードの組, bit15 が立っていれば全角 (Video_DrawCharWide 側)
const u16 gEscapeCharcodes[118] = {
    0x4C, 0x61, 0x68, 0x62, 0x66, 0x60, 0x1, 0x63, 0x3, 0x64, 0x6A, 0x66, 0x4, 0x67, 0x67, 0x65, 0x69, 0x68, 0x6E, 0x6A, 0x6B, 0x6B, 0x6C, 0x69, 0x6D, 0x6C, 0x72, 0x6E, 0x6F, 0x6F, 0x70, 0x6D, 0x6, 0x70, 0x75, 0x72, 0x73, 0x73, 0x74, 0x71, 0x7, 0x74, 0x5A, 0x75, 0x28, 0x8F, 0x9, 0x78, 0x8, 0x79, 0xA, 0x77, 0xD, 0x94, 0xB, 0x7A, 0xE, 0x7B, 0x10, 0x7D, 0xF, 0x7E, 0x11, 0x7C, 0x12, 0x7F, 0x14, 0x81, 0x13, 0x82, 0x15, 0x80, 0x16, 0x83, 0x19, 0x85, 0x18, 0x86, 0x1A, 0x84, 0x1B, 0x87, 0x1E, 0x89, 0x1D, 0x8A, 0x1F, 0x88, 0x20, 0x8B, 0x58, 0x8C, 0x59, 0x8D, 0x4F, 0x8015, 0x50, 0x8016, 0x29, 0x0, 0x48, 0x90, 0x49, 0x91, 0x4A, 0x0, 0x22, 0x95, 0x42, 0x93, 0x41, 0x92, 0x17, 0x8E, 0x5, 0x76, 0xFF81, 0x0,
};  // 0x085AB45C, 終端の 0 は無く、ループは隣の gBlankText のゼロ埋めで止まる

extern u16 u16_030047d8;             // src/camera.c
extern const char s_VAR_08251cc4[];  // src/data.c

static inline s32 GetMessageSpeed(void) { return gStat->messageSpeed; }  // 本体設定のメッセージ速度

// いまの mode を退避して新しい mode に切り替える, 7段まで
void TextRenderer_PushMode(TextRenderer* p, s32 mode) {
  if (p->stackDepth < 7) {
    p->stack[p->stackDepth] = p->mode;
    p->stackDepth++;
    p->mode = mode;
  }
}

// 退避しておいた mode を1つ取り出して戻す
void TextRenderer_PopMode(TextRenderer* p) {
  if (p->stackDepth != 0) {
    p->stackDepth--;
    p->mode = p->stack[p->stackDepth];
  }
}

// 改行: 描画位置を矩形の左端に戻して2行ぶん下げる
void TextRenderer_NewLine(TextRenderer* p) {
  p->cursorX = p->rectX;
  p->cursorY += 2;
}

// カーソルを半角なら1セル、全角なら2セル進める, 矩形の右端に届いたら左端へ巡回させる
s32 TextRenderer_AdvanceCursor(TextRenderer* p, s32 wide) {
  s32 x;
  s32 right;

  if (wide == 0) {
    p->cursorX += 1;
  } else {
    p->cursorX += 2;
  }

  x = p->cursorX;
  right = p->rectX + p->rectW;
  if (x >= right) {
    p->cursorX = x - right;
  }
}

// 文字送り音を鳴らす, soundToggle が 0/1 を往復して1文字おきに鳴る
void TextRenderer_PlayCharSound(TextRenderer* p, u32 charcode) {
  if (p->unk_0a != 0) {
    return;
  }
  if (p->silent != 0) {
    return;
  }

  if ((p->speed > 1 && p->soundEveryChar == 0) || p->soundToggle == 0) {
    if (charcode != 0 && charcode != u16_030047d8) {
      PlaySound_082406e0(gCharSounds[p->charSoundIdx]);
    }
  }
  if (p->soundToggle != 0) {
    p->soundToggle = 0;
  } else {
    p->soundToggle++;
  }
}

s32 TextRenderer_DrawCharNarrow(TextRenderer* p, u16 charcode) {
  TextRenderer_PlayCharSound(p, charcode);
  Video_DrawCharNarrow(charcode, p->cursorX, p->cursorY, p->style);
  TextRenderer_AdvanceCursor(p, 0);
  p->drewWide = 0;
}

s32 TextRenderer_DrawCharWide(TextRenderer* p, u16 charcode) {
  TextRenderer_PlayCharSound(p, charcode);
  Video_DrawCharWide(charcode, p->cursorX, p->cursorY, p->style);
  TextRenderer_AdvanceCursor(p, 1);
  p->drewWide = 1;
}

s32 Text_TakeDigit(s32* p, s32 n) {
  s32 count = 0;
  s32 v = *p;

  while (v >= n) {
    count++;
    v -= n;
    *p = v;
  }
  return count;
}

// スクリプトの文字列参照2つを引いて dst に連結する, どちらかが無ければ dst を空にして -1
// 残差は s と文字テンポラリのレジスタが逆 (原典は s が r1, 文字が r0) で adds の移動3命令ぶん少ない, Tier A/B と C のローカル分割・宣言順は試済
NON_MATCH s32 Text_ConcatStringRefs(char* dst, u8* pc1, u8* pc2, s32 off1, s32 off2) {
#ifdef NONMATCHING_C
  char* s;
  s32 ref;

  ref = VM_ParseStringRef(pc1);
  s = Textbox_LookupString(ref + off1);
  if (s == NULL) {
    *dst = 0;
    return -1;
  }
  while (*s != 0) {
    *dst++ = *s++;
  }

  ref = VM_ParseStringRef(pc2);
  s = Textbox_LookupString(ref + off2);
  if (s == NULL) {
    *dst = 0;
    return -1;
  }
  while (*s != 0) {
    *dst++ = *s++;
  }

  *dst = *s;
  return 0;
#else
  INCFUNC("asm/func/Text_ConcatStringRefs.inc");
#endif
}

// 0x1F エスケープの次の1バイトを文字コードに変換する, 表に無ければ 0xFFFF
u16 Text_GetEscapeCharcode(u8* s) {
  const u16* t = gEscapeCharcodes;

  while (t[0] != 0) {
    if (t[0] == s[1]) {
      return t[1];
    }
    t += 2;
  }

  return 0xFFFF;
}

// n を10進で dst に書く, 上の桁の 0 は詰める, 負なら先頭に '-'
void Text_FormatDecimal(char* dst, s32 n) {
  s32 hasDigit = 0;
  char* out = dst;
  s32 d;
  s32 i;

  for (i = 0; i < 12; i++) {
    dst[i] = 0;
  }

  if (n < 0) {
    *out = '-';
    out++;
    n = -n;
  }

  d = Text_TakeDigit(&n, 100000);
  if (d != 0) {
    *out = d + '0';
    hasDigit = 1;
    out++;
  }

  d = Text_TakeDigit(&n, 10000);
  if (d != 0 || hasDigit) {
    *out = d + '0';
    hasDigit = 1;
    out++;
  }

  d = Text_TakeDigit(&n, 1000);
  if (d != 0 || hasDigit) {
    *out = d + '0';
    hasDigit = 1;
    out++;
  }

  d = Text_TakeDigit(&n, 100);
  if (d != 0 || hasDigit) {
    *out = d + '0';
    hasDigit = 1;
    out++;
  }

  d = Text_TakeDigit(&n, 10);
  if (d != 0 || hasDigit) {
    *out = d + '0';
    out++;
  }

  d = 0;
  while (n > 0) {
    d++;
    n--;
  }

  *out++ = d + '0';
  *out = 0;
}

// s の先頭 n 文字を lit と比べる, s が先に終われば -1、文字が違えば 1、n 文字一致すれば 0
s32 Text_StrNCmp(u8* s, const char* lit, s32 n) {
  s32 i;

  for (i = 0; i < n; i++) {
    if (s[i] == 0) {
      if (lit[0] != 0) {
        return -1;
      }

      return 0;
    }

    if (s[i] != lit[0]) {
      return 1;
    }

    lit++;
  }

  return 0;
}

// 末尾の桁から見て10進の数値にする
NON_MATCH s32 Text_ParseDecimal(u8* s, s32 len) {
#ifdef NONMATCHING_C
  s32 v = 0;
  s32 mul = 1;
  u8* p = s + len - 1;
  s32 i;

  for (i = 0; i < len; i++) {
    v += (*p-- - '0') * mul;
    mul *= 10;
  }

  return v;
#else
  INCFUNC("asm/func/Text_ParseDecimal.inc");
#endif
}

// text の表示幅をセル数で数える, 全角と全角エスケープは2, タグ <...> は 0, 255 で打ち止め
s32 TextRenderer_GetTextWidth(TextRenderer* p) {
  u8* s = (u8*)p->text;
  s32 w = 0;

  while (*s != 0) {
    if ((s8)*s >= 0) {
      if (*s == '<') {
        do {
          s++;
        } while (*s != '>' && *s != 0 && *s != '\n');
        s++;
      } else if (*s == 0x1F) {
        u16 charcode = Text_GetEscapeCharcode(s);

        if (charcode == 0xFFFF) {
          w += 1;
          s += 1;
        } else {
          if ((charcode & 0xFF00) != 0) {
            w += 2;
          } else {
            w += 1;
          }

          s += 2;
        }
      } else {
        w += 1;
        s += 1;
      }
    } else {
      w += 2;
      s += 2;
    }

    if (w > 254) {
      w = 255;
      break;
    }
  }

  return w;
}

// c か終端に当たるまで進めた位置を返す
u8* Text_FindChar(u8* s, u8 c) {
  while (*s != c && *s != 0) {
    s++;
  }
  return s;
}

// タグの '=' から '>' までを tagValue に写して、'>' か終端の位置を返す (例: <VAR=1>, <PROC=0>)
// 残差は c のレジスタ1つ (原典は ldrb で直接 r2, こちらは r0 経由で1命令多い) だけ, Tier A/B と C のローカル分割は試済
NON_MATCH char* TextRenderer_ReadTagValue(TextRenderer* p, char* s) {
#ifdef NONMATCHING_C
  s32 i;

  p->tagHasValue = 0;
  p->tagValueLen = 0;
  i = 0;
  while (*s != '>' && *s != 0) {
    char c = *s;

    if (c == '=') {
      p->tagHasValue = 1;
    } else if (p->tagHasValue != 0) {
      p->tagValue[p->tagValueLen++] = c;
    }

    i++;
    s++;
    if (i > 63) {
      break;
    }
  }

  p->tagValue[p->tagValueLen] = 0;
  return s;
#else
  INCFUNC("asm/func/TextRenderer_ReadTagValue.inc");
#endif
}

s32 Text_GetPlayerFace(void) {
  switch (gStat->playerKind) {
    case PLAYER_SOLAR_DJANGO: {
      return 0;
    }
    case PLAYER_DARK_DJANGO: {
      return 1;
    }
    case PLAYER_SABATA: {
      return 3;
    }
    default: {
      return 1;
    }
  }
}

NON_MATCH s32 Text_GetPairFace(void) {
#ifdef NONMATCHING_C
  if (gStat->playerKind == PLAYER_SOLAR_DJANGO) return 27;

  return 28;
#else
  INCFUNC("asm/func/Text_GetPairFace.inc");
#endif
}

// '<' の次から始まるタグ名を表引きして適用し, '>' の次の位置を返す, 閉じタグ ('/' 始まり) も同じ関数が見る
NAKED char* TextRenderer_HandleTag(TextRenderer* p, char* s) { INCFUNC("asm/func/TextRenderer_HandleTag.inc"); }

// 文字を1つ描いて次の位置を返す, タグと改行は描かずに読み飛ばして続ける
// ループ形 (while ((s8)*s >= 0) + 全角をループ外) は原典と一致した (入口ジャンプと底のテストが出る)
// 残差5命令: 原典は *s の値を lsls#24 の結果から lsrs#24 で復元して 0/<の判定に使い回し, 先頭のテストが latch ブロックに合流している
NON_MATCH char* TextRenderer_DrawNextChar(TextRenderer* p, char* s) {
#ifdef NONMATCHING_C
  u16 c;

  while ((s8)*s >= 0) {
    if (*s == 0) {
      return s;
    }

    if (*s == '<') {
      s++;
      if (*s == 0) {
        return s;
      }

      s = TextRenderer_HandleTag(p, s);
      if (p->unk_0e != 0) {
        return s;
      }
      if (*s == 0) {
        return s;
      }

      s++;
      continue;
    }

    if (*s == '\n') {
      TextRenderer_NewLine(p);
      s++;
      continue;
    }

    if (*s == 0x1F) {
      u16 charcode = Text_GetEscapeCharcode(s);

      if (charcode == 0xFFFF) {
        c = *s - 0x20;
        TextRenderer_DrawCharNarrow(p, c);
      } else if ((charcode & 0xFF00) != 0) {
        TextRenderer_DrawCharNarrow(p, charcode & 0x7FFF);
      } else {
        TextRenderer_DrawCharNarrow(p, charcode);
      }

      s += 2;
      return s;
    }

    c = *s - 0x20;
    TextRenderer_DrawCharNarrow(p, c);
    s++;
    return s;
  }

  c = (*s & 0x7F) << 8;
  s++;
  c |= *s;
  if (c < Video_GetZenkakuCharCount()) {
    TextRenderer_DrawCharWide(p, c);
  } else {
    TextRenderer_AdvanceCursor(p, 1);
  }

  s++;
  return s;
#else
  INCFUNC("asm/func/TextRenderer_DrawNextChar.inc");
#endif
}

// mode が選ぶ文字列を1歩進める, 進めている文字列が終わって mode も戻り切ったら 1
s32 TextRenderer_Advance(TextRenderer* p) {
  char* s;

  p->unk_0e = 0;
  switch (p->mode) {
    case 0: {
      s = TextRenderer_DrawNextChar(p, p->text);
      p->text = s;
      if (p->finished != 0) {
        return 1;
      }
      if (p->mode != 0) {
        return 0;
      }
      if (*s != 0) {
        return 0;
      }
      return 1;
    }
    case 1: {
      s = TextRenderer_DrawNextChar(p, p->textAlt);
      p->textAlt = s;
      if (p->mode != 1) {
        return 0;
      }
      if (*s != 0) {
        return 0;
      }

      TextRenderer_PopMode(p);
      if (p->mode != 0) {
        return 0;
      }
      if (p->finished != 0) {
        return 1;
      }
      if (*p->text != 0) {
        return 0;
      }
      return 1;
    }
    case 2: {
      s = TextRenderer_DrawNextChar(p, p->numText);
      p->numText = s;
      if (p->mode != 2) {
        return 0;
      }
      if (*s != 0) {
        return 0;
      }

      TextRenderer_PopMode(p);
      if (p->mode != 0) {
        return 0;
      }
      if (p->finished != 0) {
        return 1;
      }
      if (*p->text != 0) {
        return 0;
      }
      return 1;
    }
    case 3: {
      s = TextRenderer_DrawNextChar(p, p->extendText);
      p->extendText = s;
      if (p->mode != 3) {
        return 0;
      }
      if (*s != 0) {
        return 0;
      }

      TextRenderer_PopMode(p);
      if (p->mode != 0) {
        return 0;
      }
      if (p->finished != 0) {
        return 1;
      }
      if (*p->text != 0) {
        return 0;
      }
      return 1;
    }
    default: {
      return 0;
    }
  }
}

// mode が選ぶ4本の文字列のうち、いま進めているものを返す
char* TextRenderer_GetCurrentText(TextRenderer* p) {
  switch (p->mode) {
    case 0: {
      return p->text;
    }
    case 1: {
      return p->textAlt;
    }
    case 2: {
      return p->numText;
    }
    case 3: {
      return p->extendText;
    }
  }

  return NULL;
}

void TextRenderer_ResetModeStack(TextRenderer* p) {
  p->style = 0;
  p->stackDepth = 0;
  p->mode = 0;
}

// 描画矩形を設定し、カーソルを左上へ戻す
void TextRenderer_SetRect(TextRenderer* p, s32 x, s32 y, s32 width, s32 height) {
  p->rectX = x;
  p->rectY = y;
  p->rectW = width;
  p->rectH = height;
  p->cursorX = x;
  p->cursorY = y;
}

// 文字送り速度を設定から取り込む
void TextRenderer_ResetSpeed(TextRenderer* p) {
  p->unk_08 = 0;
  p->speed = GetMessageSpeed();
}

void TextRenderer_Init(TextRenderer* p, s32 x, s32 y, s32 width, s32 height) {
  TextRenderer_SetRect(p, x, y, width, height);
  TextRenderer_ResetModeStack(p);
  TextRenderer_ResetSpeed(p);
  p->unk_0a = 0;
  p->silent = 0;
  p->savedSpeed = p->speed;
  p->drewWide = 0;
  p->scriptIdCount = 0;
  p->text = NULL;
  p->textAlt = NULL;
  p->numText = NULL;
  p->extendText = NULL;
  p->face = -1;
  p->unk_14 = 1;
  p->waitFrames = 0;
}

s32 TextRenderer_SetVar(TextRenderer* p, s32 idx, u32 val) { p->vars[idx] = val; }

s32 TextRenderer_SetExtend(TextRenderer* p, s32 idx, char* str) { p->extends[idx] = str; }

s32 TextRenderer_SetScriptIds(TextRenderer* p, s32 count, u32* ids) {
  s32 i;

  for (i = 0; i < count; i++) {
    p->scriptIds[i] = ids[i];
  }

  p->scriptIdCount = count;
}

// vars[idx] を10進で書いたときの文字数, 負数なら符号の1文字を足す
// 残差は1命令, 原典は v を r1 / width を r2 に置いて abs の一時値を n へ移す, Tier A/B と C のローカル分割・if/else 変形は試済
NON_MATCH s32 TextRenderer_GetVarWidth(TextRenderer* p, s32 idx) {
#ifdef NONMATCHING_C
  s32 v = p->vars[idx];
  s32 width = (u32)v >> 31;
  s32 n = (v < 0) ? -v : v;

  if (n > 9999999) {
    width += 8;
  } else if (n > 999999) {
    width += 7;
  } else if (n > 99999) {
    width += 6;
  } else if (n > 9999) {
    width += 5;
  } else if (n > 999) {
    width += 4;
  } else if (n > 99) {
    width += 3;
  } else if (n > 9) {
    width += 2;
  } else {
    width += 1;
  }

  return width;
#else
  INCFUNC("asm/func/TextRenderer_GetVarWidth.inc");
#endif
}

// extends[idx] の表示幅をセル数で数える, <VAR=n> は vars[n] の桁数に置き換える
// 残差は s と q のレジスタが逆 (原典は s が r5, q が r4) とそれに伴うブロック配置だけで命令数は117で一致, Tier A/B と C の宣言位置・while(1) 形は試済
NON_MATCH s32 TextRenderer_GetExtendWidth(TextRenderer* p, s32 idx) {
#ifdef NONMATCHING_C
  u8* s = (u8*)p->extends[idx];
  s32 w = 0;

  while (*s != 0 && *s != '\n') {
    if ((s8)*s >= 0) {
      if (*s == '<') {
        u8* q;

        s++;
        if (*s == 0) {
          break;
        }

        q = s;
        if (Text_StrNCmp(s, s_VAR_08251cc4, 3) == 0) {
          bool32 hasEq = FALSE;
          s32 n = 0;
          s32 var;

          if (*s != '>') {
            if (*s == 0) {
              q = s + 1;
            } else {
              do {
                if (*q == '=') {
                  hasEq = TRUE;
                } else if (hasEq) {
                  p->tagValue[n++] = *q;
                }

                q++;
              } while (*q != '>' && *q != 0);

              if (*q == 0) {
                q++;
              }
            }
          }

          p->tagValue[n] = 0;
          if (hasEq && n != 0) {
            var = Text_ParseDecimal(p->tagValue, n);
          } else {
            var = 0;
          }

          w += TextRenderer_GetVarWidth(p, var);
          Text_FindChar(q, '>');  // 戻り値を捨てている, 原典のまま
        } else {
          Text_FindChar(s, '>');  // 同上
        }

        if (*s == 0) {
          break;
        }
      } else if (*s == 0x1F) {
        u16 charcode = Text_GetEscapeCharcode(s);

        if (charcode == 0xFFFF || (charcode & 0xFF00) != 0) {
          w += 2;
          s += 2;
        } else {
          w += 1;
          s += 2;
        }
      } else {
        w += 1;
        s += 1;
      }
    } else {
      w += 2;
      s += 2;
    }
  }

  return w;
#else
  INCFUNC("asm/func/TextRenderer_GetExtendWidth.inc");
#endif
}

void TextRenderer_ClearPending(TextRenderer* p) { p->pendingCount = 0; }

void TextRenderer_RunPending(TextRenderer* p) {
  u32 i;

  for (i = 0; i < p->pendingCount; i++) {
    VM_ExecByID(p->scriptIds[p->pending[i]], NULL);
  }
}
