#include "entity.h"
#include "font.h"
#include "global.h"
#include "malloc.h"
#include "text.h"
#include "vm.h"

struct TextPanel;
struct TextPanelManager;
typedef void (*TextPanelFunc)(struct TextPanelManager* mgr, struct TextPanel* p);

// メッセージ枠1つ。TextPanel_Create が Malloc(0x1C4) して TextPanelManager のリストに繋ぐ
typedef struct TextPanel {
  s32 id;                  // 0x00, TextPanelManager_AllocID が 1..999999 で配る。TextPanelManager_FindByID の検索キー
  u8 x;                    // 0x04, TextPanel_SetRect の第2引数。FUN_0822EA60 と TextRenderer_SetRect に渡す
  u8 y;                    // 0x05, TextPanel_SetRect の第3引数
  u8 width;                // 0x06, TextPanel_SetRect の第4引数
  u8 height;               // 0x07, TextPanel_SetRect の第5引数
  u16 unk_08;              // 0x08, TextPanel_Create が 0 を入れる
  u16 msgIdx;              // 0x0A, TextPanel_SetMessage の引数。FUN_08049FE8 に渡す
  s16 pendingMsgIdx;       // 0x0C, 0 以上の間 TextPanelManager_Update が TextPanel_SetMessage に流す。適用後は -1 に戻る
  u16 unk_0e;              // 0x0E, 読み手も書き手も見つかっていない
  u8* scriptPc;            // 0x10, TextPanel_SetScript の第2引数。本文のあるスクリプト位置
  u16 unk_14;              // 0x14, TextPanel_Create と TextPanel_SetScript が 0 を入れる
  u16 unk_16;              // 0x16, TextPanel_Create と TextPanel_SetScript が 1 を入れる
  u16 unk_18[32];          // 0x18, FUN_0804a27c が選択肢ごとのメッセージ番号を unk_16 個だけ書き込む
  TextPanelFunc fn;        // 0x58, TextPanelManager_Update が fn(mgr, box) で呼ぶ。0x0804A4A0 が待機、0x0804A4A8 が表示中
  TextRenderer renderer;   // 0x5C, FUN_0804967C / FUN_08049640 / TextRenderer_SetRect / TextRenderer_Advance がこのアドレスを取る
  struct TextPanel* prev;  // 0x1BC, TextPanel_Create が繋ぎ TextPanel_Destroy が外す
  struct TextPanel* next;  // 0x1C0
} TextPanel;
static_assert(sizeof(TextPanel) == 452);

// 開いているメッセージ枠を双方向リストで抱えるシングルトン
typedef struct TextPanelManager {
  Entity e;         // 0x00, ENTITY_UNK_12
  s32 nextID;       // 0x18, TextPanelManager_AllocID が +1 する。999999 を超えたら 1 に戻す
  TextPanel* head;  // 0x1C, リストの先頭
} TextPanelManager;
static_assert(sizeof(TextPanelManager) == 32);

IWRAM_DATA TextPanelManager* gTextPanelManager = NULL;  // 0x030000CC

void TextPanel_StateDone(TextPanelManager* mgr, TextPanel* p);
void TextPanel_StateIdle(TextPanelManager* mgr, TextPanel* p);
void TextPanel_StateTyping(TextPanelManager* mgr, TextPanel* p);

// エンティティを消さずにシングルトンの参照だけ手放す
void TextPanelManager_ClearGlobal(void) { gTextPanelManager = NULL; }

bool32 TextPanelManager_Exists(void) { return gTextPanelManager != NULL; }

// 枠のスクリプト位置から文字列テーブルを引く。offset は同じ参照内での何番目かを指す
char* TextPanel_LookupText(TextPanel* p, s32 offset) { return Textbox_LookupString(VM_ParseStringRef(p->scriptPc) + offset); }

TextPanel* TextPanelManager_FindByID(TextPanelManager* mgr, s32 id) {
  TextPanel* p = mgr->head;

  while (p != NULL) {
    TextPanel* next = p->next;
    if (p->id == id) {
      return p;
    }
    p = next;
  }
  return NULL;
}

TextPanel* TextPanel_FindByID(s32 id) {
  if (gTextPanelManager == NULL) {
    return NULL;
  }
  return TextPanelManager_FindByID(gTextPanelManager, id);
}

// 未使用の枠 ID を探して返す。4回試して空きがなければ -1
s32 TextPanelManager_AllocID(TextPanelManager* mgr) {
  s32 i;

  for (i = 0; i < 4; i++) {
    mgr->nextID++;
    if (mgr->nextID > 999999) {
      mgr->nextID = 1;
    }
    if (TextPanelManager_FindByID(mgr, mgr->nextID) == NULL) {
      return mgr->nextID;
    }
  }
  return -1;
}

static inline void TextPanelManager_Link(TextPanelManager* mgr, TextPanel* p) {
  if (mgr->head != NULL) {
    mgr->head->prev = p;
  }
  p->prev = NULL;
  p->next = mgr->head;
  mgr->head = p;
}

// 枠を1つ確保してマネージャのリストの先頭に繋ぐ。戻り値は割り当てた id
s32 TextPanel_Create(s32 x, s32 y, s32 width, s32 height) {
  TextPanelManager* mgr = gTextPanelManager;
  TextPanel* p;
  TextRenderer* r;

  if (mgr == NULL) {
    return -1;
  }
  p = Malloc(sizeof(TextPanel));
  if (p == NULL) {
    return -1;
  }
  ClearMemory(p, sizeof(TextPanel));
  p->id = TextPanelManager_AllocID(mgr);
  if (p->id < 0) {
    Free(p);
    return -1;
  }
  p->x = x;
  p->y = y;
  p->width = width;
  p->height = height;
  p->unk_08 = 0;
  p->msgIdx = 0;
  p->pendingMsgIdx = -1;
  p->scriptPc = NULL;
  p->unk_14 = 0;
  p->unk_16 = 1;
  p->prev = NULL;
  p->next = NULL;
  p->fn = TextPanel_StateIdle;
  r = &p->renderer;
  TextRenderer_Init(r, p->x, p->y, p->width, p->height);
  r->finished = FALSE;
  r->unk_0b = 1;
  TextPanelManager_Link(mgr, p);
  return p->id;
}

static inline void TextPanelManager_Unlink(TextPanelManager* mgr, TextPanel* p) {
  if (p->prev != NULL) {
    p->prev->next = p->next;
  } else {
    mgr->head = p->next;
  }
  if (p->next != NULL) {
    p->next->prev = p->prev;
  }
  p->prev = NULL;
  p->next = NULL;
}

// 枠をリストから外して解放する。戻り値は消した枠の id
s32 TextPanel_Destroy(s32 id) {
  TextPanelManager* mgr = gTextPanelManager;
  TextPanel* p;

  if (mgr == NULL) {
    return -1;
  }
  p = TextPanelManager_FindByID(mgr, id);
  if (p == NULL) {
    return -1;
  }
  FUN_0822ea60(p->x, p->y, p->width, p->height);
  p->fn = TextPanel_StateIdle;
  TextPanelManager_Unlink(mgr, p);
  Free(p);
  return id;
}

// 枠を本文送り中の状態に切り替える
s32 TextPanel_Start(s32 id) {
  TextPanel* p = TextPanel_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  p->fn = TextPanel_StateTyping;
  return 0;
}

// 枠の中身を消して待機状態に戻す。枠自体は残る
s32 TextPanel_Hide(s32 id) {
  TextPanel* p = TextPanel_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  FUN_0822ea60(p->x, p->y, p->width, p->height);
  p->fn = TextPanel_StateIdle;
  return 0;
}

// スクリプト上の本文位置を枠に結びつけ、先頭メッセージを読み込んで表示準備をする
s32 TextPanel_SetScript(s32 id, u8* scriptPc) {
  TextPanel* p = TextPanel_FindByID(id);
  TextRenderer* r;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  p->scriptPc = scriptPc;
  r->text = TextPanel_LookupText(p, p->msgIdx);
  p->msgIdx = 0;
  p->unk_14 = 0;
  p->unk_16 = 1;
  p->pendingMsgIdx = 0;
  FUN_08049640(r);
  return 0;
}

// スクリプトの本文に加えて、選択肢ごとのメッセージ番号表を枠へ流し込む
NON_MATCH s32 FUN_0804a27c(s32 id, u8* scriptPc, s32 count, s32 selected, u16* msgIndices) {
#ifdef NONMATCHING_C
  TextPanel* p = TextPanel_FindByID(id);
  TextRenderer* r;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  p->scriptPc = scriptPc;
  r->text = TextPanel_LookupText(p, 0);
  p->unk_14 = selected;
  p->unk_16 = count;
  if (p->unk_16 > 32) {
    p->unk_16 = 32;
  }
  for (i = 0; i < p->unk_16; i++) {
    p->unk_18[i] = msgIndices[i];
  }
  p->pendingMsgIdx = p->unk_18[p->unk_14];
  FUN_08049640(r);
  return 0;
#else
  INCFUNC("asm/func/FUN_0804a27c.inc");
#endif
}

// 枠に表示するメッセージを差し替えて、本文送りを頭から始める
s32 TextPanel_SetMessage(s32 id, s32 msgIdx) {
  TextPanel* p = TextPanel_FindByID(id);
  TextRenderer* r;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  if (p->scriptPc != NULL) {
    FUN_0822ea60(p->x, p->y, p->width, p->height);
    TextRenderer_SetRect(r, p->x, p->y, p->width, p->height);
    p->msgIdx = msgIdx;
    r->text = TextPanel_LookupText(p, p->msgIdx);
    p->fn = TextPanel_StateTyping;
    FUN_08049640(r);
    p->pendingMsgIdx = -1;
  }
  return 0;
}

// スクリプトを介さず C の文字列をそのまま流し込む
s32 TextPanel_SetText(s32 id, char* text) {
  TextPanel* p = TextPanel_FindByID(id);
  TextRenderer* r;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  p->scriptPc = NULL;
  p->pendingMsgIdx = 0;
  r->text = text;
  r->unk_08 = 0;
  r->mode = 0;
  return 0;
}

// 枠の位置と大きさを変える。元の矩形は消してから書き直す
s32 TextPanel_SetRect(s32 id, s32 x, s32 y, s32 width, s32 height) {
  TextPanel* p = TextPanel_FindByID(id);
  TextRenderer* r;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  FUN_0822ea60(p->x, p->y, p->width, p->height);
  p->x = x;
  p->y = y;
  p->width = width;
  p->height = height;
  TextRenderer_SetRect(r, p->x, p->y, p->width, p->height);
}

s32 FUN_0804a3e4(s32 id, s32 idx, u32 value) {
  TextPanel* p = TextPanel_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  TextRenderer_SetVar(&p->renderer, idx, value);
  return 0;
}

s32 FUN_0804a40c(s32 id, s32 idx, u32 str) {
  TextPanel* p = TextPanel_FindByID(id);

  if (p != NULL) {
    return TextRenderer_SetExtend(&p->renderer, idx, str);
  }
  return -1;
}

// 枠の矩形を x, y, 幅, 高さ の順で out に書き出す
s32 TextPanel_GetRect(s32 id, u32* out) {
  TextPanel* p = TextPanel_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  TextRenderer_GetRect(&p->renderer, out);
  return 0;
}

s32 FUN_0804a460(s32 id, s32 idx) {
  TextPanel* p = TextPanel_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  return TextRenderer_GetVarWidth(&p->renderer, idx);
}

s32 FUN_0804a480(s32 id, s32 idx) {
  TextPanel* p = TextPanel_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  return TextRenderer_GetExtendWidth(&p->renderer, idx);
}

// 表示前の待機状態。本文送りが止まったままになるよう毎フレーム終了フラグを落とす
void TextPanel_StateIdle(TextPanelManager* mgr, TextPanel* p) { TextRenderer_SetFinished(&p->renderer, FALSE); }

// 本文送り中の状態。1フレームに1歩だけ進め、送り切ったら次の状態へ移す
void TextPanel_StateTyping(TextPanelManager* mgr, TextPanel* p) {
  TextRenderer* r = &p->renderer;
  s32 i;

  for (i = 0; i < 1; i++) {
    if (r->text != NULL) {
      r->unk_08 = 0;
      if (TextRenderer_Advance(r) != 0) {
        if (r->finished) {
          p->fn = TextPanel_StateIdle;
        } else {
          p->fn = TextPanel_StateDone;
        }
        break;
      }
    }
  }
}

// 表示し終えた枠の待機状態。TextPanelManager_Update から毎フレーム呼ばれるが何もしない
void TextPanel_StateDone(TextPanelManager* mgr, TextPanel* p) {}

s32 TextPanelManager_Update(TextPanelManager* mgr) {
  TextPanel* p = mgr->head;

  while (p != NULL) {
    TextPanel* next = p->next;
    TextRenderer* r = &p->renderer;

    TextRenderer_ClearPending(r);
    if (p->pendingMsgIdx >= 0) {
      TextPanel_SetMessage(p->id, p->pendingMsgIdx);
    }
    if (p->fn != NULL) {
      p->fn(mgr, p);
    }
    TextRenderer_RunPending(r);
    p = next;
  }
  return 0;
}

s32 TextPanelManager_Destroy(TextPanelManager* p) {
  TextPanel* panel = p->head;

  while (panel != NULL) {
    TextPanel* next = panel->next;
    TextPanel_Destroy(panel->id);
    panel = next;
  }
  gTextPanelManager = NULL;
  return 0;
}

s32 TextPanelManager_Init(TextPanelManager* p) {
  gTextPanelManager = p;
  p->nextID = 0;
  p->head = NULL;
  return 0;
}

TextPanelManager* TextPanelManager_Create(void) {
  TextPanelManager* p = gTextPanelManager;

  if (p == NULL) {
    p = CreateEntity(ENTITY_UNK_12, sizeof(TextPanelManager));
    if (p != NULL) {
      SetEntityRoutine(p, TextPanelManager_Update, TextPanelManager_Destroy);
      if (TextPanelManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
  }
  return p;
}

// 開いている枠を全部閉じる。マネージャ自体は残る
void TextPanelManager_DestroyAll(void) {
  if (gTextPanelManager != NULL) {
    TextPanel* p = gTextPanelManager->head;

    while (p != NULL) {
      TextPanel* next = p->next;
      TextPanel_Destroy(p->id);
      p = next;
    }
  }
}
