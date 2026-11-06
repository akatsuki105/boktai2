#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "font.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "video.h"
#include "vm.h"

// 画面に1つしかない本文表示領域, 文字送り・顔グラ・送り矢印・オートモードを持つ
typedef struct MessageWindow {
  Entity e;                                       // 0x000, ENTITY_UNK_12
  TextRenderer renderer;                          // 0x018
  u8 rectX;                                       // 0x178, '.r[0]', TextRenderer_SetRect と Font_ReleaseRect に渡す
  u8 rectY;                                       // 0x179, '.r[1]'
  u8 rectW;                                       // 0x17A, '.r[2]'
  u8 rectH;                                       // 0x17B, '.r[3]'
  u16 lineIdx;                                    // 0x17C, '.i', MessageWindow_GetLine(p, lineIdx) が行頭ポインタを返す, 次の行へ進むとき +1
  bool8 unk_17e;                                  // 0x17E, 0 なら updateCallback = MessageWindow_StateType (1文字ずつ表示), 0 以外なら unk_198 を 0 にして updateCallback = MessageWindow_StateRenderAll
  u8 unk_17f;                                     // 0x17F, 入力待ちのフラグらしい, キー状態の bit1 が入る
  s8 shownFace;                                   // 0x180, 顔スプライトに実際に反映済みの renderer.face, 食い違うと MessageWindow_RefreshFace が貼り直す
  u8 unk_181;                                     // 0x181, MessageWindow_Init が 0 を入れるだけ
  u8 autoAdvance;                                 // 0x182, MessageWindow_EnableAutoAdvance (MessageWindow_SetAutoAdvance) の第1引数
  u8 fastForwardDelay;                            // 0x183, 行を出すと 3 を入れ, 0 になるまで A での早送りを受け付けない
  u16 autoAdvanceDelay;                           // 0x184, MessageWindow_SetAutoAdvance の第2引数, autoAdvanceTimer がこれ以上になると次へ進む
  u16 autoAdvanceTimer;                           // 0x186, 毎フレーム +1
  s32 waitFrames;                                 // 0x188, 次の行へ進む前に待つフレーム数, '.l' で初期化し、MessageWindow_Update が毎フレーム renderer.waitFrames で上書きする
  u32 waitTimer;                                  // 0x18C, waitFrames の経過フレーム数, MessageWindow_StateWaitInput が waitFrames に達するまで +1 し、達したら両方 0 に戻す
  FileID bgPlttFileID;                            // 0x190, '.c=BGP_519C'
  s16 pendingLine;                                // 0x192, 次に表示する行, -1 なら何もしない, MessageWindow_Update がこれを MessageWindow_ShowLine に渡す
  u32 unk_194;                                    // 0x194, '.m', MessageWindow_SetAutoAdvance の第3引数
  u32 unk_198;                                    // 0x198, 表示が終わると 1 になり MessageWindow_IsFinished が返す
  u8 unk_19c[4];                                  // 0x19C
  u8* scriptPc;                                   // 0x1A0, VM_GetPC_Proxy の戻り値、または MessageWindow_Start / MessageWindow_StartWithLabels の第1引数
  u16 labelIdx;                                   // 0x1A4, labels の添字, pendingLine = labels[labelIdx]
  u16 labelCount;                                 // 0x1A6, MessageWindow_StartWithLabels が 32 に丸める
  u16 labels[32];                                 // 0x1A8, MessageWindow_StartWithLabels が呼び出し側の配列をコピーする行番号表
  BgPlttFile* bgPltt;                             // 0x1E8, BGP_519C
  MainSpriteGfx arrowGfx;                         // 0x1EC, SPRITE_MARKERS
  MainSprite arrow;                               // 0x20C, 次ページ送りの矢印, MessageWindow_Update が pos を枠の右下に置き直す
  MainSpriteGfx faceGfx;                          // 0x26C, SPRITE_PORTRAITS
  MainSprite face;                                // 0x28C, 話者の顔, MessageWindow_RefreshFace が renderer.face のポーズを貼る
  void (*updateCallback)(struct MessageWindow*);  // 0x2EC
} MessageWindow;
static_assert(sizeof(MessageWindow) == 752);

IWRAM_DATA MessageWindow* gMessageWindow = NULL;  // 0x030000C4

void nop_0822ec58(void);
void Font_ClearGlyphVram(void);
char* MessageWindow_GetLine(MessageWindow* p, s32 lineIdx);
void MessageWindow_StateType(MessageWindow* p);
void MessageWindow_StateRenderAll(MessageWindow* p);
void MessageWindow_StateFastForward(MessageWindow* p);
void MessageWindow_StateWaitInput(MessageWindow* p);
void MessageWindow_StateIdle(MessageWindow* p);

static inline s32 GetTextSpeed(void) { return gStat->textSpeed; }  // 本体設定のメッセージ速度

// 次のフレームから呼ぶ状態関数を差し替える
static inline void MessageWindow_SetState(MessageWindow* p, void (*fn)(MessageWindow*)) { p->updateCallback = fn; }

void MessageWindow_ClearGlobal(void) { gMessageWindow = NULL; }

bool32 MessageWindow_IsOpen(void) { return gMessageWindow != NULL; }

s32 MessageWindow_LoadBgPltt(MessageWindow* p, s32 fileID) {
  BgPlttFile* f = GetBgPlttFile(fileID);

  if (f == NULL) return -1;

  p->bgPlttFileID = fileID;
  p->bgPltt = f;
  return 0;
}

// パレットファイルの 500 バイト目から 16色を BG パレットの最終ブロックへ送る
void MessageWindow_UploadBgPltt(MessageWindow* p) { CpuCopy32(&p->bgPltt->body[240], &gBgPlttBuffer[240], 16 * sizeof(rgb555)); }

s32 MessageWindow_RefreshFace(MessageWindow* p) {
  TextRenderer* r = &p->renderer;

  if (r->face == -1) {
    MainSprite_Hide(&p->face);
  } else {
    MainSprite_Show(&p->face);
    MainSprite_SetPose(&p->face, &p->faceGfx, r->face, PLAYMODE_PAUSE);
  }

  p->shownFace = r->face;
}

s32 MessageWindow_SetInstant(s32 instant) {
  MessageWindow* p = gMessageWindow;

  if (p == NULL) return 0;

  p->unk_17e = instant;
  if (p->unk_17e == 0) {
    MessageWindow_SetState(p, MessageWindow_StateType);
    p->fastForwardDelay = 3;
  } else {
    p->unk_198 = 0;
    MessageWindow_SetState(p, MessageWindow_StateRenderAll);
  }

  p->renderer.finished = FALSE;
  TextRenderer_SetFace(&p->renderer, -1);
  MessageWindow_RefreshFace(p);
}

s32 MessageWindow_SetInstantScripted(void) { return MessageWindow_SetInstant(VM_GetValue()); }

s32 MessageWindow_Close(void) {
  MessageWindow* p = gMessageWindow;

  if (p == NULL) return 0;

  Font_ReleaseRect(p->rectX, p->rectY, p->rectW, p->rectH);
  MessageWindow_SetState(p, MessageWindow_StateIdle);
  p->arrow.flags |= SPRFLAG_HIDDEN;
  TextRenderer_SetFace(&p->renderer, -1);
  MainSprite_Hide(&p->face);
  p->pendingLine = -1;
}

s32 MessageWindow_CloseScripted(void) { return MessageWindow_Close(); }

s32 MessageWindow_Start(u8* pc) {
  MessageWindow* p = gMessageWindow;

  if (p != NULL && pc != NULL) {
    TextRenderer* r = &p->renderer;

    p->scriptPc = pc;
    p->lineIdx = 0;
    r->text = MessageWindow_GetLine(p, 0);
    p->labelIdx = 0;
    p->labelCount = 1;
    p->pendingLine = 0;
    TextRenderer_ResetModeStack(r);
    p->arrow.flags |= SPRFLAG_HIDDEN;
  }

  return 0;
}

// 行番号表つきで表示を始める, labels を最大32件まで取り込んで labelIdx の行から出す
// 残差1命令 (84/83): 原典は p を r5, &renderer を r4 に置くが, agbcc は &renderer を高位レジスタに追い出して mov を1つ払う
NON_MATCH s32 MessageWindow_StartWithLabels(u8* pc, s32 labelCount, s32 labelIdx, u16* labels) {
#ifdef NONMATCHING_C
  MessageWindow* p = gMessageWindow;

  if (p != NULL) {
    TextRenderer* r = &p->renderer;
    s32 i;

    p->scriptPc = pc;
    r->text = MessageWindow_GetLine(p, 0);
    p->labelIdx = labelIdx;
    p->labelCount = labelCount;
    if ((u16)labelCount > 32) {
      p->labelCount = 32;
    }

    for (i = 0; i < p->labelCount; i++) {
      p->labels[i] = labels[i];
    }

    p->pendingLine = p->labels[p->labelIdx];
    TextRenderer_ResetModeStack(r);
    p->arrow.flags |= SPRFLAG_HIDDEN;
  }

  return 0;
#else
  INCFUNC("asm/func/MessageWindow_StartWithLabels.inc");
#endif
}

// '.r' があればそこを、なければ現在位置を本文の先頭にする
s32 MessageWindow_Open(void) { return MessageWindow_Start(!VM_SeekToNamedArg('r') ? VM_GetPC() : VM_GetPC_Proxy()); }

// 指定行の表示を始める, unk_17e が 0 なら1文字ずつ, それ以外なら一気に描く状態へ入る
// 残差0命令 (103/103), レジスタ割当だけ違う: 原典は定数 0x18 を r9 に残して p を r5 に置くが, こちらは p が r6 を取る
NON_MATCH s32 MessageWindow_ShowLine(s32 line) {
#ifdef NONMATCHING_C
  MessageWindow* p = gMessageWindow;

  if (p != NULL && p->scriptPc != NULL) {
    Font_ReleaseRect(p->rectX, p->rectY, p->rectW, p->rectH);
    TextRenderer_SetRect(&p->renderer, p->rectX, p->rectY, p->rectW, p->rectH);
    p->lineIdx = line;
    p->renderer.text = MessageWindow_GetLine(p, p->lineIdx);
    if (p->unk_17e == 0) {
      p->updateCallback = MessageWindow_StateType;
      p->fastForwardDelay = 3;
    } else {
      p->unk_198 = 0;
      p->updateCallback = MessageWindow_StateRenderAll;
    }

    TextRenderer_ResetModeStack(&p->renderer);
    p->pendingLine = -1;
    p->arrow.flags |= SPRFLAG_HIDDEN;
  }

  return 0;
#else
  INCFUNC("asm/func/MessageWindow_ShowLine.inc");
#endif
}

s32 MessageWindow_SetPendingLineScripted(void) {
  MessageWindow* p = gMessageWindow;

  if (p != NULL && p->scriptPc != NULL) {
    p->pendingLine = VM_GetValue();
  }

  return 0;
}

s32 MessageWindow_SetText(char* text) {
  MessageWindow* p = gMessageWindow;

  if (p != NULL) {
    TextRenderer* r = &p->renderer;

    p->scriptPc = NULL;
    p->pendingLine = 0;
    r->text = text;
    r->frameCounter = 0;
    r->mode = 0;
    p->arrow.flags |= SPRFLAG_HIDDEN;
  }

  return 0;
}

// 描画矩形を設定し直す, 古い矩形は Font_ReleaseRect に渡して後始末させる
s32 MessageWindow_SetRect(s32 x, s32 y, s32 w, s32 h) {
  MessageWindow* p = gMessageWindow;

  if (p == NULL) {
    return 0;
  }
  Font_ReleaseRect(p->rectX, p->rectY, p->rectW, p->rectH);
  p->rectX = x, p->rectY = y, p->rectW = w, p->rectH = h;
  TextRenderer_SetRect(&p->renderer, p->rectX, p->rectY, p->rectW, p->rectH);
}

// 0x930F
s32 Cmd_SetMessageWindowRect(void) {
  s32 x = VM_GetValue();
  s32 y = VM_GetValue();
  s32 w = VM_GetValue();
  return MessageWindow_SetRect(x, y, w, VM_GetValue());
}

// 文字列の <VAR=idx> に対応する値を設定する
s32 MessageWindow_SetVarValue(s32 idx, s32 value) {
  if (gMessageWindow == NULL) {
    return -1;
  }
  TextRenderer_SetVar(&gMessageWindow->renderer, idx, value);
  return 0;
}

// 0xAB3C
s32 Cmd_SetMessageWindowVar(void) {
  s32 idx = VM_GetValue();
  return MessageWindow_SetVarValue(idx, VM_GetValue());
}

s32 MessageWindow_SetExtendValue(s32 idx, char* text) {
  if (gMessageWindow != NULL) {
    return TextRenderer_SetExtend(&gMessageWindow->renderer, idx, text);
  }
  return 0;
}

// 0x2575
s32 Cmd_2575(void) {
  s32 idx = VM_GetValue();
  u8* pc = VM_GetPC_Proxy();
  s32 offset;

  if (pc == NULL) return -1;

  offset = VM_GetNamedArgValue('i', 0);
  MessageWindow_SetExtendValue(idx, GetStringByID(VM_ParseStringRef(pc) + offset));
  return 0;
}

// 0x352D
s32 MessageWindow_SetExtend(void) {
  s32 idx = VM_GetValue();
  return MessageWindow_SetExtendValue(idx, VM_GetValueSafe2_Proxy());
}

// 0x75AF
s32 MessageWindow_SetScriptIdsScripted(void) {
  MessageWindow* p = gMessageWindow;
  TextRenderer* r;

  if (p == NULL) return 0;

  r = &p->renderer;
  r->scriptIdCount = 0;
  if (VM_SeekToNamedArg('p')) {
    while (VM_GetPC() != NULL) {
      r->scriptIds[r->scriptIdCount] = VM_GetValue();
      r->scriptIdCount++;
    }
  } else {
    return -1;
  }

  return 0;
}

s32 MessageWindow_SetAutoAdvance(s32 enable, s32 delay, u32 unk_194) {
  MessageWindow* p = gMessageWindow;
  if (p == NULL) return 0;

  p->autoAdvance = enable;
  p->autoAdvanceDelay = delay;
  p->autoAdvanceTimer = 0;
  p->unk_194 = unk_194;
}

// 0xADD2
s32 MessageWindow_EnableAutoAdvance(void) {
  s32 enable = VM_GetValue();
  s32 delay = VM_GetValue();

  return MessageWindow_SetAutoAdvance(enable, delay, VM_GetNamedArgValue('m', enable != 0));
}

s32 MessageWindow_SetBgPltt(s32 fileID) {
  MessageWindow* p = gMessageWindow;
  if (p == NULL) {
    return -1;
  }
  if (MessageWindow_LoadBgPltt(p, fileID) < 0) {
    return -1;
  }
  MessageWindow_UploadBgPltt(p);
  return 0;
}

// 0x8F41
s32 MessageWindow_SetBgPlttScripted(void) { return MessageWindow_SetBgPltt(VM_GetValue()); }

// 0xDD91, 開いているメッセージウィンドウを名前付き引数で設定し直す, '.s' 文字列表, '.r' 矩形, '.c' パレット, '.i' 行, '.m' 文字送り音, '.w' 速度, '.d' オート送り, '.p' スクリプトID の並び, '.a' 早送りの解除
s32 MessageWindow_ConfigureScripted(void) {
  MessageWindow* p = gMessageWindow;
  TextRenderer* r;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  if (VM_SeekToNamedArg('s')) {
    p->scriptPc = VM_GetPC_Proxy();
    if (p->scriptPc == NULL) {
      return -1;
    }
    MessageWindow_Start(p->scriptPc);
  }
  if (VM_SeekToNamedArg('r')) {
    s32 x = VM_GetValue();
    s32 y = VM_GetValue();
    s32 w = VM_GetValue();

    MessageWindow_SetRect(x, y, w, VM_GetValue());
  }
  if (MessageWindow_LoadBgPltt(p, VM_GetNamedArgValue('c', p->bgPlttFileID)) < 0) {
    return -1;
  }
  MessageWindow_UploadBgPltt(p);
  p->lineIdx = VM_GetNamedArgValue('i', p->lineIdx);
  r->charSoundIdx = VM_GetNamedArgValue('m', r->charSoundIdx);
  r->speed = VM_GetNamedArgValue('w', GetTextSpeed());
  if (VM_SeekToNamedArg('d')) {
    p->autoAdvance = VM_GetValue();
    p->autoAdvanceDelay = VM_GetValue();
    p->unk_194 = 1;
  } else {
    p->autoAdvance = 0;
    p->autoAdvanceDelay = 0;
    p->unk_194 = 0;
  }
  p->autoAdvanceTimer = 0;
  if (VM_SeekToNamedArg('p')) {
    r->scriptIdCount = 0;
    while (VM_GetPC() != NULL) {
      r->scriptIds[r->scriptIdCount] = VM_GetValue();
      r->scriptIdCount++;
    }
  }
  if (VM_SeekToNamedArg('a')) {
    if (VM_GetValue() != 0) {
      p->unk_17f = 0;
    }
  } else {
    p->unk_17f = 0;
  }
}

s32 MessageWindow_SetWait(s32 frames) {
  if (gMessageWindow == NULL) {
    return -1;
  }
  gMessageWindow->waitFrames = frames;
  gMessageWindow->waitTimer = 0;
  return 0;
}

// 0x7974
s32 Cmd_SetMessageWindowWait(void) { return MessageWindow_SetWait(VM_GetValue()); }

s32 FUN_08047fbc(void) {
  if (gMessageWindow == NULL) {
    return -1;
  }
  return 0;
}

// スクリプトの文字列表の lineIdx 行目を引く
char* MessageWindow_GetLine(MessageWindow* p, s32 lineIdx) { return GetStringByID(VM_ParseStringRef(p->scriptPc) + lineIdx); }

// 行末で入力 (オート送りなら時間) を待ち, 次の行へ進んだら文字送りを再開する
void MessageWindow_StateWaitInput(MessageWindow* p) {
  TextRenderer* r = &p->renderer;
  s32 advance = 0;

  if (p->autoAdvance) {
    if (p->autoAdvanceTimer++ >= p->autoAdvanceDelay) {
      p->autoAdvanceTimer = 0;
      advance = 2;
    }
  } else if (p->waitTimer >= p->waitFrames) {
    p->waitFrames = 0;
    p->waitTimer = 0;
    if (gInput[0].down & B_BUTTON) {
      p->unk_17f = 1;
      advance = 1;
    }
    if (gInput[0].pressed & A_BUTTON) {
      advance = 1;
    }
    p->arrow.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->unk_17f = 0;
    p->arrow.flags |= SPRFLAG_HIDDEN;
    p->waitTimer++;
  }

  if ((p->unk_17f || advance) && p->scriptPc != NULL) {
    p->lineIdx++;
    if (p->unk_17f) {
      MessageWindow_SetState(p, MessageWindow_StateFastForward);
      r->speed = 0;
      r->frameCounter = 0;
    } else {
      MessageWindow_SetState(p, MessageWindow_StateType);
      p->fastForwardDelay = 3;
      r->speed = GetTextSpeed();
    }
    r->text = MessageWindow_GetLine(p, p->lineIdx);
    if (advance != 2) {
      PlaySound_082406e0(SE_TEXT_SHOW);
    }
    Font_ReleaseRect(p->rectX, p->rectY, p->rectW, p->rectH);
    TextRenderer_SetRect(r, p->rectX, p->rectY, p->rectW, p->rectH);
    TextRenderer_ResetModeStack(&p->renderer);
    p->arrow.flags |= SPRFLAG_HIDDEN;
  } else {
    MainSprite_AdvanceAnim(&p->arrow, &p->arrowGfx);
  }
}

// B を押している間の早送り, 1歩ずつ文字を進め, 行末なら入力待ちへ, B を離したら通常の文字送りに戻す
void MessageWindow_StateFastForward(MessageWindow* p) {
  TextRenderer* r = &p->renderer;

  if (p->unk_17f) {
    r->muteCharSound = TRUE;
  } else {
    r->muteCharSound = p->unk_194;
  }
  if (r->text != NULL) {
    if (r->mode == 0 && *r->text == '\0') {
      p->waitTimer = 0;
      MessageWindow_SetState(p, MessageWindow_StateWaitInput);
      if (p->autoAdvance == 0 && p->waitFrames == 0) {
        p->arrow.flags &= ~SPRFLAG_HIDDEN;
      }
      return;
    }
    r->frameCounter = 0;
    r->soundEveryChar = TRUE;
    if (TextRenderer_Advance(r) && r->finished) {
      MessageWindow_SetState(p, MessageWindow_StateIdle);
    }
  }
  if (p->updateCallback != MessageWindow_StateIdle && p->autoAdvance == 0 && p->unk_17f && !(gInput[0].down & B_BUTTON)) {
    MessageWindow_SetState(p, MessageWindow_StateType);
    p->unk_17f = 0;
  }
}

// 通常の文字送り, speed フレームごとに1歩進め, 行末なら入力待ちへ, A を押すか B を押し続けると早送りに移る
void MessageWindow_StateType(MessageWindow* p) {
  TextRenderer* r = &p->renderer;

  r->muteCharSound = p->unk_194;
  if (r->text != NULL) {
    if (r->mode == 0 && *r->text == '\0') {
      p->waitTimer = 0;
      MessageWindow_SetState(p, MessageWindow_StateWaitInput);
      if (p->autoAdvance == 0 && p->waitFrames == 0) {
        p->arrow.flags &= ~SPRFLAG_HIDDEN;
      }
      return;
    }
    if (r->frameCounter++ >= r->speed) {
      r->frameCounter = 0;
      r->soundEveryChar = FALSE;
      if (TextRenderer_Advance(r)) {
        if (r->finished) {
          MessageWindow_SetState(p, MessageWindow_StateIdle);
        } else if (r->stopAtTag) {
          r->frameCounter = r->speed;
        }
      }
    }
  }
  if (p->updateCallback != MessageWindow_StateIdle && p->autoAdvance == 0) {
    if (p->fastForwardDelay != 0) {
      p->fastForwardDelay--;
    } else if (gInput[0].pressed & A_BUTTON) {
      MessageWindow_SetState(p, MessageWindow_StateFastForward);
      return;
    }
    if (gInput[0].down & B_BUTTON) {
      MessageWindow_SetState(p, MessageWindow_StateFastForward);
      p->unk_17f = 1;
    }
  }
}

void MessageWindow_StateIdle(MessageWindow* p) { TextRenderer_SetFinished(&p->renderer, FALSE); }

void MessageWindow_StateDone(MessageWindow* p) {}

// 残りの文字を一気に描き切る, 1フレームで最大4歩進め, 行を描き終えたら次の状態へ移す
void MessageWindow_StateRenderAll(MessageWindow* p) {
  TextRenderer* r = &p->renderer;
  s32 i;

  r->muteCharSound = TRUE;
  for (i = 0; i < 4; i++) {
    if (r->text != NULL) {
      r->frameCounter = 0;
      if (TextRenderer_Advance(r)) {
        p->unk_198 = 1;
        if (r->finished) {
          MessageWindow_SetState(p, MessageWindow_StateIdle);
        } else {
          MessageWindow_SetState(p, MessageWindow_StateDone);
        }
        return;
      }
    }
  }
}

// 矢印を枠の上下どちらかに置き直し, updateCallback の状態に応じて顔スプライトを貼り直す
s32 MessageWindow_Update(MessageWindow* p) {
  TextRenderer* r = &p->renderer;

  if (r->waitFrames != 0) {
    p->waitFrames = r->waitFrames;
    r->waitFrames = 0;
  }
  TextRenderer_ClearPending(r);
  if (p->pendingLine >= 0) {
    MessageWindow_ShowLine(p->pendingLine);
  }
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }

  if (p->rectY + p->rectH < 10) {
    VEC3_SET(p->arrow.pos, 223, 41, 0);
  } else {
    VEC3_SET(p->arrow.pos, 223, 143, 0);
  }

  if (p->updateCallback != MessageWindow_StateIdle) {
    MessageWindow_UploadBgPltt(p);
    if (p->shownFace != r->face) {
      MessageWindow_RefreshFace(p);
    }
  } else if (p->shownFace != -1) {
    MainSprite_Hide(&p->face);
    p->shownFace = -1;
  }
  TextRenderer_RunPending(r);
  return 0;
}

s32 MessageWindow_Destroy(MessageWindow* p) {
  MainSprite_Remove(&p->arrow);
  MainSprite_Remove(&p->face);
  gMessageWindow = NULL;
  return 0;
}

// 生成時の初期化, '.r' 矩形, '.l' 待ちフレーム, '.s' 文字列表, '.c' パレット, '.i' 行, '.p' スクリプトID の並びを読み, 送り矢印と顔のスプライトを作る
// 残差: 294/298 命令, 原典は状態を StateIdle にした直後に unk_17e を ldrb で読んで捨てる (結果を使わない読み込み) が, こちらは出ない (空の if は試済)
NON_MATCH s32 MessageWindow_Init(MessageWindow* p, u32 _) {
#ifdef NONMATCHING_C
  TextRenderer* r;
  MainSpriteGfx* f;
  Vec3 pos;

  gMessageWindow = p;
  r = &p->renderer;
  nop_0822ec58();
  Font_ClearGlyphVram();
  if (VM_SeekToNamedArg('r')) {
    p->rectX = VM_GetValue();
    p->rectY = VM_GetValue();
    p->rectW = VM_GetValue();
    p->rectH = VM_GetValue();
  } else {
    p->rectX = 0;
    p->rectY = 0;
    p->rectW = 0;
    p->rectH = 0;
  }
  p->waitTimer = 0;
  p->waitFrames = VM_GetNamedArgValue('l', 0);
  TextRenderer_Init(r, p->rectX, p->rectY, p->rectW, p->rectH);
  p->unk_17e = 0;
  if (VM_SeekToNamedArg('s')) {
    p->scriptPc = VM_GetPC_Proxy();
    if (p->scriptPc == NULL) {
      return -1;
    }
    r->text = GetStringByID(VM_ParseStringRef(p->scriptPc));
    if (r->text == NULL) {
      return -1;
    }
  } else {
    p->scriptPc = NULL;
    r->text = NULL;
  }
  if (MessageWindow_LoadBgPltt(p, VM_GetNamedArgValue('c', BGP_519C)) < 0) {
    return -1;
  }
  MessageWindow_UploadBgPltt(p);
  r->charSoundIdx = 0;
  p->unk_181 = 0;
  p->lineIdx = VM_GetNamedArgValue('i', 0);
  p->fastForwardDelay = 3;
  p->unk_17f = 0;
  p->autoAdvance = 0;
  p->autoAdvanceDelay = 0;
  r->scriptIdCount = 0;
  if (VM_SeekToNamedArg('p')) {
    while (VM_GetPC() != NULL) {
      r->scriptIds[r->scriptIdCount] = VM_GetValue();
      r->scriptIdCount++;
    }
  } else {
    r->scriptIdCount = 0;
  }
  p->pendingLine = -1;
  MessageWindow_SetState(p, MessageWindow_StateIdle);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_MARKERS);
  if (f == NULL) {
    return -1;
  }
  p->arrowGfx = *f;
  OpenMainSpriteFile(&p->arrowGfx, f);
  pos.x = 223, pos.y = 143, pos.z = 0;
  MainSprite_Add(&p->arrow, &p->arrowGfx, 8, SPRFLAG_UNK_13 | SPRFLAG_GAMEOVER | SPRFLAG_NO_CLIP | SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, PLAYMODE_LOOP, 60, &pos);
  MainSprite_SetAnim(&p->arrow, &p->arrowGfx, 0, PLAYMODE_LOOP, 0);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_PORTRAITS);
  if (f == NULL) {
    return -1;
  }
  p->faceGfx = *f;
  OpenMainSpriteFile(&p->faceGfx, f);
  pos.x = 4, pos.y = 64, pos.z = 0;
  MainSprite_Add(&p->face, &p->faceGfx, 0, SPRFLAG_GAMEOVER | SPRFLAG_NO_CLIP | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, PLAYMODE_PAUSE, 60, &pos);
  return 0;
#else
  INCFUNC("asm/func/MessageWindow_Init.inc");
#endif
}

// 0x0E37
MessageWindow* MessageWindow_Create(u32 id) {
  MessageWindow* p = gMessageWindow;

  if (p != NULL) {
    return gMessageWindow;
  }

  p = CreateEntity(ENTITY_UNK_12, sizeof(MessageWindow));
  if (p != NULL) {
    SetEntityRoutine(p, MessageWindow_Update, MessageWindow_Destroy);
    if (MessageWindow_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

s32 MessageWindow_GetRect(s32* rect) {
  MessageWindow* p = gMessageWindow;

  if (p == NULL) {
    return -1;
  }

  rect[0] = p->renderer.rectX;
  rect[1] = p->renderer.rectY;
  rect[2] = p->renderer.rectW;
  rect[3] = p->renderer.rectH;
  return 0;
}

s32 MessageWindow_GetVarWidth(s32 idx) {
  if (gMessageWindow == NULL) {
    return 0;
  }
  return TextRenderer_GetVarWidth(&gMessageWindow->renderer, idx);
}

s32 MessageWindow_GetExtendWidth(s32 idx) {
  if (gMessageWindow == NULL) {
    return 0;
  }
  return TextRenderer_GetExtendWidth(&gMessageWindow->renderer, idx);
}

s32 FUN_080488dc(void) {
  if (gMessageWindow == NULL) {
    return 0;
  }
  return TextRenderer_GetTextWidth(&gMessageWindow->renderer);
}

s32 FUN_080488fc(void) { return gStat->unk_938; }

bool32 MessageWindow_IsFinished(void) {
  if (gMessageWindow == NULL) {
    return FALSE;
  }
  return gMessageWindow->unk_198;
}
