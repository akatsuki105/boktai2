#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "vm.h"

// 選択肢1つ分の位置と大きさ, TextBoxChoice_ParseTag が <ALTER> を見つけるたびに埋める
typedef struct {
  u8 x;      // 0x00, (col + winX) * 8
  u8 y;      // 0x01, winY * 8 + line * 16
  u8 width;  // 0x02, 文字数, <ALTER=n> なら n
  u8 line;   // 0x03
} TextBoxChoiceEntry;
static_assert(sizeof(TextBoxChoiceEntry) == 4);

// テキストボックスの文字列から <ALTER> で囲まれた部分を選択肢として拾い、左右にカーソルのスプライトを付けて選ばせる
typedef struct {
  Entity e;                        // 0x00, ENTITY_UNK_11
  s8 selected;                     // 0x18, 今カーソルが乗っている選択肢, 負ならまだどれも選んでいない
  s8 defaultIndex;                 // 0x19, 未選択の状態からカーソルを出すときに乗せる選択肢
  u8 startDelay;                   // 0x1A, Init が 2 を入れ、Update が減らす, 0 になるまで入力を読まない
  u8 choiceCount;                  // 0x1B
  u8 lineFirst[8];                 // 0x1C, 各行の先頭の選択肢番号
  u8 lineLast[8];                  // 0x24, 各行の末尾の選択肢番号
  u8 lineChoiceCount[8];           // 0x2C, 各行の選択肢の数, 0 の行は上下移動で飛ばす
  u8 lineCount;                    // 0x34, winH を超えない
  bool8 fromScript;                // 0x35, 0 なら callback、1 なら scriptID で結果を返す
  u8 winX;                         // 0x36, '.a', 以下4つはテキストボックスの矩形 (タイル単位)
  u8 winY;                         // 0x37
  u8 winW;                         // 0x38
  u8 winH;                         // 0x39, 行数の上限でもある
  u8 choiceWidth;                  // 0x3A, <ALTER> からの文字数
  u8 col;                          // 0x3B, 行頭からの文字数
  bool8 cancelable;                // 0x3C, '.c', 0 以外なら B でキャンセルできる
  u8 cursorDelay;                  // 0x3D, Init が 10 を入れる, 0 になるかキーが押されるまでカーソルを出さない
  u8 repeatDelay;                  // 0x3E, 移動のたびに 30, 同じキーを押し続けている間だけ減る
  u8 widthOverride;                // 0x3F, <ALTER=n> の n
  u32 heldKeys;                    // 0x40, 前のフレームに押されていた十字キー
  u32 scriptArgs[4];               // 0x44, '.A', scriptID に argv[1..4] として渡す
  u32 scriptID;                    // 0x54, '.p'
  void (*callback)(s32 selected);  // 0x58, fromScript が 0 のときに選択結果を渡して呼ぶ
  u8* textPC;                      // 0x5C, '.r' の位置, 選択肢の元になる文字列への参照がここにある
  s32 stringBase;                  // 0x60, '.i', Textbox_LookupString に渡す前に足す
  TextBoxChoiceEntry entries[16];  // 0x64
  u8 tagValue[64];                 // 0xA4, <TAG=...> の = 以降を詰める作業用バッファ
  MainSpriteGfx gfx;               // 0xE4, SPRITE_UI_START_MENU
  MainSprite cursorL;              // 0x104, 選択肢の左に付く
  MainSprite cursorR;              // 0x164, 選択肢の右に付く
} TextBoxChoice;
static_assert(sizeof(TextBoxChoice) == 452);

IWRAM_DATA TextBoxChoice* gTextBoxChoice = NULL;  // 0x03000028

u8* FUN_0823d340(void);
s32 FUN_080488fc(void);
u16 FUN_08048afc(u8* s);

const char s_ALTER_08251b3c[] = "ALTER";
const char s_EXTEND_08251b44[] = "EXTEND";
const char s_VAR_08251b4c[] = "VAR";
const char s_ALTER_08251b50[] = "/ALTER";

// 文字を n 個ぶん進める
static inline void TextBoxChoice_AdvanceCol(TextBoxChoice* p, s32 n) {
  p->choiceWidth += n;
  p->col += n;
}

void TextBoxChoice_ClearGlobal(void) { gTextBoxChoice = NULL; }

// 選んだ結果を呼び出し元へ返す, argv[0] が選択番号、argv[1..4] は '.A' で渡された引数
void TextBoxChoice_Finish(TextBoxChoice* p, s32 selected) {
  if (p->fromScript) {
    u32 argv[5];
    ScriptArgs args;
    s32 i;

    argv[0] = selected;
    for (i = 0; i < 4; i++) {
      argv[i + 1] = p->scriptArgs[i];
    }
    args.argc = 5, args.argv = argv;
    if (p->scriptID != 0) Script_ExecById(p->scriptID, &args);
  } else {
    p->callback(selected);
  }
}

// 選択肢を左右から挟むようにカーソルを置く
static inline void TextBoxChoice_PlaceCursors(TextBoxChoice* p, TextBoxChoiceEntry* e) {
  p->cursorL.pos.x = e->x - 7;
  p->cursorL.pos.y = e->y;
  p->cursorR.pos.x = e->x + 1 + e->width * 8;
  p->cursorR.pos.y = e->y;
}

// idx の選択肢にカーソルを合わせる, idx が負なら defaultIndex の位置で点滅させる
void TextBoxChoice_SetCursor(TextBoxChoice* p, s32 idx) {
  TextBoxChoiceEntry* e;

  if (idx >= 0) {
    if (idx >= p->choiceCount) {
      idx = p->choiceCount - 1;
    }
    e = &p->entries[idx];
    p->cursorL.flags &= ~SPRFLAG_BLINK_ODD;
    p->cursorR.flags &= ~SPRFLAG_BLINK_ODD;
    TextBoxChoice_PlaceCursors(p, e);
  } else {
    e = &p->entries[p->defaultIndex];
    p->cursorL.flags |= SPRFLAG_BLINK_ODD;
    p->cursorR.flags |= SPRFLAG_BLINK_ODD;
    TextBoxChoice_PlaceCursors(p, e);
  }
  if (idx != p->selected) {
    PlaySound_082406e0(0xDC);
  }
  p->selected = idx;
}

// line から step ずつ動かして、選択肢のある行を探す, 見つからなければ line のまま
s32 TextBoxChoice_FindLine(TextBoxChoice* p, s32 line, s32 step) {
  s32 cur = line;
  s32 i;

  for (i = 0; i < p->lineCount; i++) {
    cur += step;
    if (cur > p->lineCount) {
      cur = p->lineCount;
    } else if (cur < 0) {
      cur = 0;
    }
    if (p->lineChoiceCount[cur] != 0) {
      return cur;
    }
  }
  return line;
}

// 行をまたいでカーソルを動かす, 行内での位置はできるだけ保つ
static inline s32 TextBoxChoice_MoveLine(TextBoxChoice* p, TextBoxChoiceEntry* e, s32 idx, s32 step) {
  s32 offset = idx - p->lineFirst[e->line];
  s32 line = TextBoxChoice_FindLine(p, e->line, step);
  s32 next;

  if (e->line == line) {
    next = p->selected;
  } else {
    next = p->lineFirst[line] + offset;
  }
  if (next < p->lineFirst[line]) {
    next = p->lineFirst[line];
  } else if (next > p->lineLast[line]) {
    next = p->lineLast[line];
  }
  return next;
}

// 十字キーでカーソルを動かし、A で決定、B でキャンセルする
NON_MATCH void TextBoxChoice_HandleInput(TextBoxChoice* p) {
#ifdef NONMATCHING_C
  u32 keys;

  p->cursorL.flags &= ~SPRFLAG_HIDDEN;
  p->cursorR.flags &= ~SPRFLAG_HIDDEN;
  if (p->selected < 0) {
    if ((gInput[0].pressed & DPAD_ANY) == 0) {
      if (p->cursorDelay != 0) {
        p->cursorDelay--;
        return;
      }
      if ((gInput[0].pressed & (A_BUTTON | B_BUTTON)) == 0) {
        return;
      }
    }
    TextBoxChoice_SetCursor(p, p->defaultIndex);
    PlaySound_082406e0(0x107);
    return;
  }
  if (p->cursorDelay != 0) {
    p->cursorDelay--;
    return;
  }
  if ((p->heldKeys & gInput[0].down) != 0) {
    if (p->repeatDelay != 0) {
      p->repeatDelay--;
    }
  } else {
    p->repeatDelay = 0;
  }
  keys = gInput[0].down;
  p->heldKeys = keys & DPAD_ANY;
  if (p->repeatDelay == 0) {
    s32 idx = p->selected;
    TextBoxChoiceEntry* e = &p->entries[idx];
    s32 next;

    if (keys & DPAD_LEFT) {
      next = idx - 1;
      if (next < p->lineFirst[e->line]) {
        next = p->lineFirst[e->line];
      }
      TextBoxChoice_SetCursor(p, next);
      p->repeatDelay = 30;
    } else if (keys & DPAD_RIGHT) {
      next = idx + 1;
      if (next > p->lineLast[e->line]) {
        next = p->lineLast[e->line];
      }
      TextBoxChoice_SetCursor(p, next);
      p->repeatDelay = 30;
    } else if (keys & DPAD_UP) {
      TextBoxChoice_SetCursor(p, TextBoxChoice_MoveLine(p, e, idx, -1));
      p->repeatDelay = 30;
    } else if (keys & DPAD_DOWN) {
      TextBoxChoice_SetCursor(p, TextBoxChoice_MoveLine(p, e, idx, 1));
      p->repeatDelay = 30;
    }
  }
  if (gInput[0].pressed & B_BUTTON) {
    if (p->cancelable != 0) {
      PlaySound_082406e0(0xDE);
      TextBox_Close();
      TextBoxChoice_Finish(p, -1);
      KillEntity((Entity*)p);
    }
  } else if (gInput[0].pressed & A_BUTTON) {
    PlaySound_082406e0(0xDD);
    TextBox_Close();
    TextBoxChoice_Finish(p, p->selected);
    KillEntity((Entity*)p);
  }
#else
  INCFUNC("asm/func/TextBoxChoice_HandleInput.inc");
#endif
}

s32 TextBoxChoice_Update(TextBoxChoice* p) {
  if (p->textPC != NULL && TextBox_IsFinished() != 0) {
    if (p->startDelay == 0) {
      TextBoxChoice_HandleInput(p);
    } else {
      p->startDelay--;
    }
    MainSprite_AdvanceAnim(&p->cursorL, &p->gfx);
    MainSprite_AdvanceAnim(&p->cursorR, &p->gfx);
  }
  return 0;
}

s32 TextBoxChoice_Destroy(TextBoxChoice* p) {
  MainSprite_Remove(&p->cursorL);
  MainSprite_Remove(&p->cursorR);
  gTextBoxChoice = NULL;
  return 0;
}

// 選択肢の矩形でテキストボックスを開き、選択肢の元になる文字列を流し込む
void TextBoxChoice_OpenBox(TextBoxChoice* p) {
  TextBox_SetRect(p->winX, p->winY, p->winW, p->winH);
  TextBox_SetInstant(1);
  TextBox_Start(p->textPC);
  TextBox_ShowLine(p->stringBase);
}

// <ALTER> / </ALTER> / <EXTEND> / <VAR> を処理して、タグの次の位置を返す
NON_MATCH u8* TextBoxChoice_ParseTag(TextBoxChoice* p, u8* s) {
#ifdef NONMATCHING_C
  u8* q = s;

  if (*s != '/') {
    if (TextBox_StrNCmp(s, s_ALTER_08251b3c, 5) == 0) {
      bool32 found = FALSE;
      s32 len = 0;

      if (*q != '>') {
        if (*q == 0) {
          q = s + 1;
        } else {
          while (TRUE) {
            if (*q == '=') {
              found = TRUE;
            } else if (found) {
              p->tagValue[len] = *q;
              len++;
            }
            q++;
            if (*q == '>') {
              break;
            }
            if (*q == 0) {
              q++;
              break;
            }
          }
        }
      }
      p->tagValue[len] = 0;
      if (found && len != 0) {
        p->widthOverride = TextBox_ParseDecimal(p->tagValue, len);
      } else {
        p->widthOverride = 0;
      }
      q = TextBox_FindChar(q, '>');
      p->entries[p->choiceCount].x = (p->col + p->winX) * 8;
      p->entries[p->choiceCount].y = p->winY * 8 + p->lineCount * 16;
      p->entries[p->choiceCount].line = p->lineCount;
      p->choiceWidth = 0;
    } else if (TextBox_StrNCmp(s, s_EXTEND_08251b44, 6) == 0) {
      bool32 found = FALSE;
      s32 len = 0;
      s32 val;
      s32 w;

      if (*q != '>') {
        if (*q == 0) {
          q = s + 1;
        } else {
          while (TRUE) {
            if (*q == '=') {
              found = TRUE;
            } else if (found) {
              p->tagValue[len] = *q;
              len++;
            }
            q++;
            if (*q == '>') {
              break;
            }
            if (*q == 0) {
              q++;
              break;
            }
          }
        }
      }
      p->tagValue[len] = 0;
      if (found && len != 0) {
        val = TextBox_ParseDecimal(p->tagValue, len);
      } else {
        val = 0;
      }
      w = TextBox_GetExtendWidth(val);
      p->choiceWidth += w;
      p->col += w;
      q = TextBox_FindChar(q, '>');
    } else if (TextBox_StrNCmp(s, s_VAR_08251b4c, 3) == 0) {
      bool32 found = FALSE;
      s32 len = 0;
      s32 val;
      s32 w;

      if (*q != '>') {
        if (*q == 0) {
          q = s + 1;
        } else {
          while (TRUE) {
            if (*q == '=') {
              found = TRUE;
            } else if (found) {
              p->tagValue[len] = *q;
              len++;
            }
            q++;
            if (*q == '>') {
              break;
            }
            if (*q == 0) {
              q++;
              break;
            }
          }
        }
      }
      p->tagValue[len] = 0;
      if (found && len != 0) {
        val = TextBox_ParseDecimal(p->tagValue, len);
      } else {
        val = 0;
      }
      w = TextBox_GetVarWidth(val);
      p->choiceWidth += w;
      p->col += w;
      q = TextBox_FindChar(q, '>');
    } else {
      return TextBox_FindChar(s, '>');
    }
  } else {
    if (TextBox_StrNCmp(s, s_ALTER_08251b50, 6) != 0) {
      return TextBox_FindChar(s, '>');
    }
    q = TextBox_FindChar(s, '>');
    if (p->widthOverride != 0) {
      p->entries[p->choiceCount].width = p->widthOverride;
    } else {
      p->entries[p->choiceCount].width = p->choiceWidth;
    }
    p->choiceCount++;
    p->choiceWidth = 0;
    p->lineChoiceCount[p->lineCount]++;
  }
  return q + 1;
#else
  INCFUNC("asm/func/TextBoxChoice_ParseTag.inc");
#endif
}

// 文字列を頭から走査して行ごとの選択肢の範囲を数え直す
NON_MATCH void TextBoxChoice_ScanChoices(TextBoxChoice* p, u8* pc) {
#ifdef NONMATCHING_C
  u8* s = (u8*)Textbox_LookupString(VM_ParseStringRef(pc) + p->stringBase);
  s32 i;

  p->choiceCount = 0;
  p->choiceWidth = 0;
  for (i = 0; i < 8; i++) {
    p->lineFirst[i] = 0;
    p->lineLast[i] = 0;
    p->lineChoiceCount[i] = 0;
  }
  p->lineCount = 0;
  while (TRUE) {
    u8 c = *s;

    if ((s8)c < 0) {
      TextBoxChoice_AdvanceCol(p, 2);
      s += 2;
      continue;
    }
    if (c == 0) {
      break;
    }
    if (c == '<') {
      s++;
      if (*s == 0) {
        break;
      }
      s = TextBoxChoice_ParseTag(p, s);
      if (*s == 0) {
        break;
      }
      continue;
    }
    if (*s == '\n') {
      p->col = 0;
      p->choiceWidth = 0;
      if (p->lineCount < p->winH) {
        if (p->choiceCount == 0) {
          p->lineLast[p->lineCount] = 0;
        } else {
          p->lineLast[p->lineCount] = p->choiceCount - 1;
        }
        p->lineCount++;
        if (p->lineCount < p->winH) {
          p->lineFirst[p->lineCount] = p->choiceCount;
        }
      }
    } else if (*s == 0x1F) {
      u16 code = FUN_08048afc(s);

      if (code != 0xFFFF && (code & 0xFF00) == 0) {
        TextBoxChoice_AdvanceCol(p, 1);
      } else {
        TextBoxChoice_AdvanceCol(p, 2);
      }
      break;
    } else {
      TextBoxChoice_AdvanceCol(p, 1);
    }
    s++;
  }
  if (p->lineCount < p->winH) {
    if (p->choiceCount == 0) {
      p->lineLast[p->lineCount] = 0;
    } else {
      p->lineLast[p->lineCount] = p->choiceCount - 1;
    }
  }
#else
  INCFUNC("asm/func/TextBoxChoice_ScanChoices.inc");
#endif
}

// スタートメニューのスプライトからカーソルを2つ出し、settings の内容を写して選択肢を組み立てる
s32 TextBoxChoice_Init(TextBoxChoice* p, u8* textPC, s32 stringBase, s32* settings) {
  MainSpriteFile* f;
  Vec3 pos;
  s32 idx;

  gTextBoxChoice = p;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  p->textPC = textPC;
  p->stringBase = stringBase;
  if (settings[1] != 0) {
    p->selected = -1;
  } else {
    p->selected = settings[0];
  }
  idx = settings[0];
  if (idx < 0) {
    idx = 0;
  }
  p->defaultIndex = idx;
  p->cancelable = settings[2];
  p->cursorDelay = 10;
  p->repeatDelay = 0;
  p->heldKeys = gInput[0].down;
  p->winX = settings[3], p->winY = settings[4];
  p->winW = settings[5], p->winH = settings[6];
  p->startDelay = 2;
  pos.x = 1, pos.y = 0, pos.z = 0;
  MainSprite_Add(&p->cursorL, &p->gfx, 139, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, 0, 60, &pos);
  MainSprite_Add(&p->cursorR, &p->gfx, 143, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, 0, 60, &pos);
  MainSprite_SetAnim(&p->cursorL, &p->gfx, 6, 1, 0);
  MainSprite_SetAnim(&p->cursorR, &p->gfx, 7, 1, 0);
  if (p->textPC != NULL) {
    TextBoxChoice_ScanChoices(p, p->textPC);
    TextBoxChoice_SetCursor(p, p->selected);
    TextBoxChoice_OpenBox(p);
  }
  if (FUN_080488fc() == 0) {
    PlaySound_082406e0(0x107);
  }
  return 0;
}

TextBoxChoice* TextBoxChoice_Create(u8* textPC, s32 stringBase, void (*callback)(s32 selected), s32* settings) {
  TextBoxChoice* p;

  if (gTextBoxChoice != NULL) {
    return NULL;
  }
  p = CreateEntity(ENTITY_UNK_11, sizeof(TextBoxChoice));
  if (p != NULL) {
    SetEntityRoutine(p, TextBoxChoice_Update, TextBoxChoice_Destroy);
    p->fromScript = FALSE;
    p->callback = callback;
    if (TextBoxChoice_Init(p, textPC, stringBase, settings) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 選択肢を出すスクリプトコマンド, 'a' が無ければ今のテキストボックスの矩形を使う
TextBoxChoice* TextBoxChoice_CreateFromScript(void) {
  TextBoxChoice* p;
  s32 settings[7];
  u32 args[4];
  s32 rect[4];
  u8* textPC;
  s32 stringBase;
  u32 scriptID;
  s32 i;

  if (gTextBoxChoice != NULL) {
    return NULL;
  }
  textPC = VM_SeekToKeyword('r') ? FUN_0823d340() : NULL;
  stringBase = VM_GetKeywordValue('i', 0);
  scriptID = 0;
  if (VM_SeekToKeyword('p')) {
    scriptID = Script_GetValue();
  }
  settings[1] = VM_GetKeywordValue('l', 0);
  settings[0] = VM_GetKeywordValue('w', 0);
  settings[2] = VM_GetKeywordValue('c', 0);
  if (VM_SeekToKeyword('a')) {
    settings[3] = Script_GetValue();
    settings[4] = Script_GetValue();
    settings[5] = Script_GetValue();
    settings[6] = Script_GetValue();
  } else if (TextBox_GetRect(rect) == 0) {
    settings[3] = rect[0], settings[4] = rect[1], settings[5] = rect[2], settings[6] = rect[3];
  } else {
    settings[3] = 0, settings[4] = 0, settings[5] = 24, settings[6] = 3;
  }
  if (VM_SeekToKeyword('A')) {
    for (i = 0; i < 4; i++) {
      if (VM_GetPC() != NULL) {
        args[i] = Script_GetValue();
      } else {
        args[i] = 0;
      }
    }
  } else {
    for (i = 0; i < 4; i++) {
      args[i] = 0;
    }
  }

  p = CreateEntity(ENTITY_UNK_11, sizeof(TextBoxChoice));
  if (p != NULL) {
    SetEntityRoutine(p, TextBoxChoice_Update, TextBoxChoice_Destroy);
    p->fromScript = TRUE;
    p->scriptID = scriptID;
    for (i = 0; i < 4; i++) {
      p->scriptArgs[i] = args[i];
    }
    if (TextBoxChoice_Init(p, textPC, stringBase, settings) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 表示中の選択肢に別の文字列を読み直させるスクリプトコマンド
void TextBoxChoice_SetTextFromScript(void) {
  TextBoxChoice* p = gTextBoxChoice;

  if (p != NULL && VM_SeekToKeyword('r')) {
    p->textPC = FUN_0823d340();
    p->stringBase = VM_GetKeywordValue('i', 0);
    if (VM_SeekToKeyword('w')) p->selected = Script_GetValue();
    if (p->textPC != NULL) {
      TextBoxChoice_ScanChoices(p, p->textPC);
      TextBoxChoice_SetCursor(p, p->selected);
      TextBoxChoice_OpenBox(p);
    }
  }
}
