#include "entity.h"
#include "font.h"
#include "global.h"
#include "malloc.h"
#include "text.h"
#include "vm.h"

struct MenuMessage;
struct MenuMessageManager;
typedef void (*MenuMessageFunc)(struct MenuMessageManager* mgr, struct MenuMessage* p);

// メニュー画面に置く文字の枠1つ, スタートメニュー, アルバムや魔物図鑑, パスワード入力, 通信対戦のメニュー, セーブ画面などで使う
// 画面の側が MenuMessage_Create で好きな位置に開き, 返ってきた id で本文を渡して送らせ, 使い終わったら閉じる
// 本文はスクリプト中の文字列参照の何番目かで選ぶか (MenuMessage_SetScript / _SetMessage), C の文字列を直接渡す (MenuMessage_SetText)
// MessageWindow (会話の枠) は画面に1つだけの共有の枠を借りて使い, 顔グラや送り矢印, ボタン待ちがある, こちらは画面の側が必要なだけ同時に開けて, ボタンを待たずに本文を書き切るだけ
typedef struct MenuMessage {
  s32 id;                          // 0x00, 画面の側が持つ枠の番号, 1..999999 を順に配る
  u8 x;                            // 0x04, 枠の位置と大きさ, BG のタイル単位
  u8 y;                            // 0x05
  u8 width;                        // 0x06
  u8 height;                       // 0x07
  u16 unk_08;                      // 0x08, MenuMessage_Create が 0 を入れる
  u16 msgIdx;                      // 0x0A, いま出している本文が scriptPc の文字列参照の何番目か
  s16 pendingMsgIdx;               // 0x0C, 次の更新で出す本文の番号, -1 なら差し替えなし
  u8* scriptPc;                    // 0x10, 本文の文字列参照があるスクリプト位置, NULL なら MenuMessage_SetText で渡した文字列を出している
  u16 unk_14;                      // 0x14, 選択肢つきのとき, いま選ばれている選択肢の番号 (FUN_0804a27c)
  u16 unk_16;                      // 0x16, 選択肢の数, 最大 32
  u16 unk_18[32];                  // 0x18, 選択肢ごとに出す本文の番号, 選ばれた選択肢の本文が pendingMsgIdx に入る
  MenuMessageFunc updateCallback;  // 0x58, 枠の状態, MenuMessage_StateIdle 送っていない (開いた直後や Hide のあと), _StateTyping 本文を送っている, _StateDone 送り終えて出したまま
  TextRenderer renderer;           // 0x5C, 枠の中に本文を1文字ずつ描く
  struct MenuMessage* prev;        // 0x1BC, MenuMessageManager の枠のリスト
  struct MenuMessage* next;        // 0x1C0
} MenuMessage;
static_assert(sizeof(MenuMessage) == 452);

// メニュー画面で開いている MenuMessage を全部抱えて毎フレーム送るシングルトン, HashName("メニューメッセージマネージャ")
// マップに入るときにスクリプトが作り, 画面の側は MenuMessage_* を枠の id で呼ぶだけでよい
typedef struct MenuMessageManager {
  Entity e;           // 0x00, ENTITY_UNK_12
  s32 nextID;         // 0x18, 次に配る枠の番号の手前, 999999 を超えたら 1 に戻る
  MenuMessage* head;  // 0x1C, 開いている枠のリスト
} MenuMessageManager;
static_assert(sizeof(MenuMessageManager) == 32);

IWRAM_DATA MenuMessageManager* gMenuMessageManager = NULL;  // 0x030000CC

void MenuMessage_StateDone(MenuMessageManager* mgr, MenuMessage* p);
void MenuMessage_StateIdle(MenuMessageManager* mgr, MenuMessage* p);
void MenuMessage_StateTyping(MenuMessageManager* mgr, MenuMessage* p);

static inline void MenuMessageManager_Link(MenuMessageManager* mgr, MenuMessage* p) {
  if (mgr->head != NULL) {
    mgr->head->prev = p;
  }
  p->prev = NULL;
  p->next = mgr->head;
  mgr->head = p;
}

static inline void MenuMessageManager_Unlink(MenuMessageManager* mgr, MenuMessage* p) {
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

void MenuMessageManager_ClearGlobal(void) { gMenuMessageManager = NULL; }

bool32 MenuMessageManager_Exists(void) { return gMenuMessageManager != NULL; }

// 枠のスクリプト位置から文字列テーブルを引く, offset は同じ参照内での何番目かを指す
char* MenuMessage_LookupText(MenuMessage* p, s32 offset) { return GetStringByID(VM_ParseStringRef(p->scriptPc) + offset); }

MenuMessage* MenuMessageManager_FindByID(MenuMessageManager* mgr, s32 id) {
  MenuMessage* p = mgr->head;

  while (p != NULL) {
    MenuMessage* next = p->next;
    if (p->id == id) {
      return p;
    }
    p = next;
  }
  return NULL;
}

MenuMessage* MenuMessage_FindByID(s32 id) {
  if (gMenuMessageManager == NULL) {
    return NULL;
  }
  return MenuMessageManager_FindByID(gMenuMessageManager, id);
}

// 未使用の枠 ID を探して返す, 4回試して空きがなければ -1
s32 MenuMessageManager_AllocID(MenuMessageManager* mgr) {
  s32 i;

  for (i = 0; i < 4; i++) {
    mgr->nextID++;
    if (mgr->nextID > 999999) {
      mgr->nextID = 1;
    }
    if (MenuMessageManager_FindByID(mgr, mgr->nextID) == NULL) {
      return mgr->nextID;
    }
  }
  return -1;
}

// 枠を1つ確保してマネージャのリストの先頭に繋ぐ, 戻り値は割り当てた id
s32 MenuMessage_Create(s32 x, s32 y, s32 width, s32 height) {
  MenuMessageManager* mgr = gMenuMessageManager;
  MenuMessage* p;
  TextRenderer* r;

  if (mgr == NULL) {
    return -1;
  }
  p = Malloc(sizeof(MenuMessage));
  if (p == NULL) {
    return -1;
  }
  ClearMemory(p, sizeof(MenuMessage));
  p->id = MenuMessageManager_AllocID(mgr);
  if (p->id < 0) {
    Free(p);
    return -1;
  }
  p->x = x, p->y = y;
  p->width = width, p->height = height;
  p->unk_08 = 0;
  p->msgIdx = 0;
  p->pendingMsgIdx = -1;
  p->scriptPc = NULL;
  p->unk_14 = 0;
  p->unk_16 = 1;
  p->prev = NULL, p->next = NULL;
  p->updateCallback = MenuMessage_StateIdle;
  r = &p->renderer;
  TextRenderer_Init(r, p->x, p->y, p->width, p->height);
  r->finished = FALSE;
  r->silent = TRUE;
  MenuMessageManager_Link(mgr, p);
  return p->id;
}

// 枠をリストから外して解放する, 戻り値は消した枠の id
s32 MenuMessage_Destroy(s32 id) {
  MenuMessageManager* mgr = gMenuMessageManager;
  MenuMessage* p;

  if (mgr == NULL) {
    return -1;
  }
  p = MenuMessageManager_FindByID(mgr, id);
  if (p == NULL) {
    return -1;
  }
  Font_ReleaseRect(p->x, p->y, p->width, p->height);
  p->updateCallback = MenuMessage_StateIdle;
  MenuMessageManager_Unlink(mgr, p);
  Free(p);
  return id;
}

// 枠を本文送り中の状態に切り替える
s32 MenuMessage_Start(s32 id) {
  MenuMessage* p = MenuMessage_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  p->updateCallback = MenuMessage_StateTyping;
  return 0;
}

// 枠の中身を消して待機状態に戻す, 枠自体は残る
s32 MenuMessage_Hide(s32 id) {
  MenuMessage* p = MenuMessage_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  Font_ReleaseRect(p->x, p->y, p->width, p->height);
  p->updateCallback = MenuMessage_StateIdle;
  return 0;
}

// スクリプト上の本文位置を枠に結びつけ、先頭メッセージを読み込んで表示準備をする
s32 MenuMessage_SetScript(s32 id, u8* scriptPc) {
  MenuMessage* p = MenuMessage_FindByID(id);
  TextRenderer* r;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  p->scriptPc = scriptPc;
  r->text = MenuMessage_LookupText(p, p->msgIdx);
  p->msgIdx = 0;
  p->unk_14 = 0;
  p->unk_16 = 1;
  p->pendingMsgIdx = 0;
  TextRenderer_ResetModeStack(r);
  return 0;
}

// スクリプトの本文に加えて、選択肢ごとのメッセージ番号表を枠へ流し込む
NON_MATCH s32 FUN_0804a27c(s32 id, u8* scriptPc, s32 count, s32 selected, u16* msgIndices) {
#ifdef NONMATCHING_C
  MenuMessage* p = MenuMessage_FindByID(id);
  TextRenderer* r;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  p->scriptPc = scriptPc;
  r->text = MenuMessage_LookupText(p, 0);
  p->unk_14 = selected;
  p->unk_16 = count;
  if (p->unk_16 > 32) {
    p->unk_16 = 32;
  }
  for (i = 0; i < p->unk_16; i++) {
    p->unk_18[i] = msgIndices[i];
  }
  p->pendingMsgIdx = p->unk_18[p->unk_14];
  TextRenderer_ResetModeStack(r);
  return 0;
#else
  INCFUNC("asm/func/FUN_0804a27c.inc");
#endif
}

// 枠に表示するメッセージを差し替えて、本文送りを頭から始める
s32 MenuMessage_SetMessage(s32 id, s32 msgIdx) {
  MenuMessage* p = MenuMessage_FindByID(id);
  TextRenderer* r;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  if (p->scriptPc != NULL) {
    Font_ReleaseRect(p->x, p->y, p->width, p->height);
    TextRenderer_SetRect(r, p->x, p->y, p->width, p->height);
    p->msgIdx = msgIdx;
    r->text = MenuMessage_LookupText(p, p->msgIdx);
    p->updateCallback = MenuMessage_StateTyping;
    TextRenderer_ResetModeStack(r);
    p->pendingMsgIdx = -1;
  }
  return 0;
}

// スクリプトを介さず C の文字列をそのまま流し込む
s32 MenuMessage_SetText(s32 id, char* text) {
  MenuMessage* p = MenuMessage_FindByID(id);
  TextRenderer* r;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  p->scriptPc = NULL;
  p->pendingMsgIdx = 0;
  r->text = text;
  r->frameCounter = 0;
  r->mode = 0;
  return 0;
}

// 枠の位置と大きさを変える, 元の矩形は消してから書き直す
s32 MenuMessage_SetRect(s32 id, s32 x, s32 y, s32 width, s32 height) {
  MenuMessage* p = MenuMessage_FindByID(id);
  TextRenderer* r;

  if (p == NULL) {
    return -1;
  }
  r = &p->renderer;
  Font_ReleaseRect(p->x, p->y, p->width, p->height);
  p->x = x, p->y = y;
  p->width = width, p->height = height;
  TextRenderer_SetRect(r, p->x, p->y, p->width, p->height);
}

s32 FUN_0804a3e4(s32 id, s32 idx, u32 value) {
  MenuMessage* p = MenuMessage_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  TextRenderer_SetVar(&p->renderer, idx, value);
  return 0;
}

s32 FUN_0804a40c(s32 id, s32 idx, char* str) {
  MenuMessage* p = MenuMessage_FindByID(id);

  if (p != NULL) {
    return TextRenderer_SetExtend(&p->renderer, idx, str);
  }
  return -1;
}

// 枠の矩形を x, y, 幅, 高さ の順で out に書き出す
s32 MenuMessage_GetRect(s32 id, u32* out) {
  MenuMessage* p = MenuMessage_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  TextRenderer_GetRect(&p->renderer, out);
  return 0;
}

s32 FUN_0804a460(s32 id, s32 idx) {
  MenuMessage* p = MenuMessage_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  return TextRenderer_GetVarWidth(&p->renderer, idx);
}

s32 FUN_0804a480(s32 id, s32 idx) {
  MenuMessage* p = MenuMessage_FindByID(id);

  if (p == NULL) {
    return -1;
  }
  return TextRenderer_GetExtendWidth(&p->renderer, idx);
}

// 表示前の待機状態, 本文送りが止まったままになるよう毎フレーム終了フラグを落とす
void MenuMessage_StateIdle(MenuMessageManager* mgr, MenuMessage* p) { TextRenderer_SetFinished(&p->renderer, FALSE); }

// 本文送り中の状態, 1フレームに1歩だけ進め、送り切ったら次の状態へ移す
void MenuMessage_StateTyping(MenuMessageManager* mgr, MenuMessage* p) {
  TextRenderer* r = &p->renderer;
  s32 i;

  for (i = 0; i < 1; i++) {
    if (r->text != NULL) {
      r->frameCounter = 0;
      if (TextRenderer_Advance(r) != 0) {
        if (r->finished) {
          p->updateCallback = MenuMessage_StateIdle;
        } else {
          p->updateCallback = MenuMessage_StateDone;
        }
        break;
      }
    }
  }
}

// 表示し終えた枠の待機状態, MenuMessageManager_Update から毎フレーム呼ばれるが何もしない
void MenuMessage_StateDone(MenuMessageManager* mgr, MenuMessage* p) {}

s32 MenuMessageManager_Update(MenuMessageManager* mgr) {
  MenuMessage* p = mgr->head;

  while (p != NULL) {
    MenuMessage* next = p->next;
    TextRenderer* r = &p->renderer;

    TextRenderer_ClearPending(r);
    if (p->pendingMsgIdx >= 0) {
      MenuMessage_SetMessage(p->id, p->pendingMsgIdx);
    }
    if (p->updateCallback != NULL) {
      p->updateCallback(mgr, p);
    }
    TextRenderer_RunPending(r);
    p = next;
  }
  return 0;
}

s32 MenuMessageManager_Destroy(MenuMessageManager* p) {
  MenuMessage* panel = p->head;

  while (panel != NULL) {
    MenuMessage* next = panel->next;
    MenuMessage_Destroy(panel->id);
    panel = next;
  }
  gMenuMessageManager = NULL;
  return 0;
}

s32 MenuMessageManager_Init(MenuMessageManager* p) {
  gMenuMessageManager = p;
  p->nextID = 0;
  p->head = NULL;
  return 0;
}

// 0x6273, HashName("メニューメッセージマネージャ")
MenuMessageManager* MenuMessageManager_Create(void) {
  MenuMessageManager* p = gMenuMessageManager;

  if (p == NULL) {
    p = CreateEntity(ENTITY_UNK_12, sizeof(MenuMessageManager));
    if (p != NULL) {
      SetEntityRoutine(p, MenuMessageManager_Update, MenuMessageManager_Destroy);
      if (MenuMessageManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
  }
  return p;
}

// 開いている枠を全部閉じる, マネージャ自体は残る
void MenuMessageManager_DestroyAll(void) {
  if (gMenuMessageManager != NULL) {
    MenuMessage* p = gMenuMessageManager->head;

    while (p != NULL) {
      MenuMessage* next = p->next;
      MenuMessage_Destroy(p->id);
      p = next;
    }
  }
}
