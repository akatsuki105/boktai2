#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "save.h"
#include "sound.h"
#include "sprite_main.h"
#include "sprite_pltt.h"
#include "text.h"
#include "video.h"
#include "vm.h"

// 上下で項目を選ぶメニュー, SPR_UI_LINK を使うので通信関連?
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_11
  u32 scriptIDs[4];       // 0x018, '.p' の4値, 選択結果 (result) の番号で引いて閉じるときに実行するスクリプト, 引数が無ければ末尾から 0 クリアされる
  u8 state;               // 0x028, gLinkMenuStateFuncs の添字
  bool8 stateChanged;     // 0x029, 各ハンドラの入り口で1回だけ行う処理用
  s8 cursor;              // 0x02A, 選択中の項目, 負なら count-1、count 以上なら 0 に折り返す
  s8 prevCursor;          // 0x02B, 前回描画した cursor, 変わったときだけ貼り替える
  u8 count;               // 0x02C, 項目数, gSystemSaveData->crossoverUnlocked が 0x369F なら 3、でなければ 2
  u8 secretKeyIdx;        // 0x02D, 隠しコマンドを何個目まで正しく入力したか, 16 に届くとクロスオーバーバトルを解放する
  u8 secretKeyTimer;      // 0x02E, 隠しコマンドの最後の正しい入力からのフレーム数, 120 で入力をやり直す
  s8 result;              // 0x02F, A なら cursor、B なら 3 が入る選択結果
  const u16* secretKeys;  // 0x030, 隠しコマンドのキーの並び, gLinkMenuSecretKeys
  u32 timer;              // 0x034, 毎フレーム +1, 30 を超えてから A/B を受け付ける
  MainSpriteGfx gfx;      // 0x038, SPR_UI_LINK
  MainSprite sprites[3];  // 0x058
  u16 animTimer;          // 0x178, 毎フレーム +1, gLinkMenuGlowDurations[animIdx] に達したら 0 に戻る
  u16 animIdx;            // 0x17A, 0..5 を巡回し、gLinkMenuGlowColors[animIdx] を pltt[12] に書く
  rgb555 pltt[128];       // 0x17C, gObjPlttData + 0x2930 から 0x100 バイトコピー, sprites[].pltt が指す
  s32 panelID;            // 0x27C, MenuMessage_Destroy に渡る
  u8* script;             // 0x280, '.r', NULL なら LinkMenu_Init が失敗する
} LinkMenu;
static_assert(sizeof(LinkMenu) == 644);

static s32 sLinkMenuLastCursor;  // 0x030000D4, 前回 A で決めた項目, 次に開いたときのカーソルの初期位置

bool8 Save_ReadCurrentSlot(void);

// state を切り替え, 入り口の処理を1回だけ行わせる
static inline void LinkMenu_SetState(LinkMenu* p, s32 state) {
  p->state = state;
  p->stateChanged = TRUE;
  p->timer = 0;
}

extern bool32 gRtcReadInhibit;

// クロスオーバーバトルを解放する隠しコマンド
const u16 gLinkMenuSecretKeys[16] = {
    L_BUTTON,
    R_BUTTON,
    L_BUTTON,
    R_BUTTON,
    L_BUTTON,
    L_BUTTON,
    R_BUTTON,
    R_BUTTON,
    R_BUTTON,
    R_BUTTON,
    L_BUTTON,
    L_BUTTON,
    SELECT_BUTTON,
    START_BUTTON,
    SELECT_BUTTON,
    START_BUTTON,
};  // 0x085AB564

void LinkMenu_StateStart(LinkMenu* p);
void LinkMenu_StateNoSave(LinkMenu* p);
void LinkMenu_StateSelectLocked(LinkMenu* p);
void LinkMenu_StateSelectUnlocked(LinkMenu* p);
void LinkMenu_StateExit(LinkMenu* p);

void (*const gLinkMenuStateFuncs[5])(LinkMenu*) = {
    LinkMenu_StateStart,
    LinkMenu_StateNoSave,
    LinkMenu_StateSelectLocked,
    LinkMenu_StateSelectUnlocked,
    LinkMenu_StateExit,
};  // 0x085AB584

const u16 gLinkMenuGlowDurations[6] = {10, 8, 8, 8, 8, 8};  // 0x085AB598

const u16 gLinkMenuGlowColors[6] = {31, 27, 18, 10, 18, 27};  // 0x085AB5A4

// 通信メニューの背景 (MP_LINK) とそのパレットを読み込む
s32 LinkMenu_LoadLinkBG(LinkMenu* p, s32 param_2) {
  s32 bgIndex = param_2;

  Video_SetupBGLayout(1, 0, GetFile(DIR_TILE_MAP, MP_LINK), 0, 0, 1, &bgIndex);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  CpuCopy16(GetBgPlttFile(BGP_LINK)->body, gBgPlttBuffer, 256 * sizeof(rgb555));
  return 0;
}

// メッセージ窓用のシステム背景 (MP_SYSTEM) とパレットの後半を読み込む
s32 LinkMenu_LoadSystemBG(LinkMenu* p, s32 param_2) {
  s32 bgIndex = param_2;

  Video_SetupBGLayout(0, 0, GetFile(DIR_TILE_MAP, MP_SYSTEM), 0, 0, 1, &bgIndex);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  CpuCopy16(&GetBgPlttFile(BGP_SYSTEM)->body[208], &gBgPlttBuffer[208], 48 * sizeof(rgb555));
  return 0;
}

// count 未満の項目だけ表示する
void LinkMenu_ShowItems(LinkMenu* p) {
  MainSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 3; i++, spr++) {
    if (i < p->count) {
      spr->flags &= ~SPRFLAG_HIDDEN;
    } else {
      spr->flags |= SPRFLAG_HIDDEN;
    }
  }
}

// A で選択を確定、B で取り消して state 4 へ進める, どちらも押されていなければ 0
s32 LinkMenu_ConfirmOrCancel(LinkMenu* p) {
  if (gInput[0].pressed & A_BUTTON) {
    sLinkMenuLastCursor = p->cursor;
    p->result = p->cursor;
    LinkMenu_SetState(p, 4);
    return 1;
  }
  if (gInput[0].pressed & B_BUTTON) {
    p->result = 3;
    LinkMenu_SetState(p, 4);
    return 1;
  }
  return 0;
}

// 残差1命令 (109/109), line = cursor + 1 の add を原典は script の読み出しの後に置く (LinkMenu_StateStart / StateSelectLocked と同じ壁)
// Tier A-C は試済 (line++ の2文, + line + 1 を式に, s8 / u32 の line), 未: この壁はスケジューラではなく展開順 (agbcc-internals §1)
NON_MATCH void LinkMenu_MoveCursor(LinkMenu* p) {
#ifdef NONMATCHING_C
  if (gInput[0].pressed & DPAD_UP) {
    p->cursor--;
    PlaySound_082406e0(SE_CURSOR_MOVE);
  } else if (gInput[0].pressed & DPAD_DOWN) {
    p->cursor++;
    PlaySound_082406e0(SE_CURSOR_MOVE);
  }

  if (p->cursor < 0) {
    p->cursor = p->count - 1;
  } else if (p->cursor >= p->count) {
    p->cursor = 0;
  }

  if (p->prevCursor != p->cursor) {
    MainSprite* spr = p->sprites;
    s32 line;
    s32 i;

    for (i = 0; i < p->count; i++, spr++) {
      s32 pose = i * 2 + 26;
      if (i != p->cursor) {
        pose++;
      }
      MainSprite_SetPose(spr, &p->gfx, pose, 0);
    }
    line = p->cursor + 1;
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + line));
  }
  p->prevCursor = p->cursor;
#else
  INCFUNC("asm/func/LinkMenu_MoveCursor.inc");
#endif
}

// 最初の state, セーブデータを読めたら項目の絵とマーキーを出して選択 (項目数で 2 か 3) へ, 読めなければ LinkMenu_StateNoSave へ
// 残差1命令 (92/92), line = cursor + 1 の add を原典は script の読み出しの後に置くがこちらは cursor を読んだ直後に置く
// Tier A-C は試済 (line ローカル無し, (cursor + 1) の括弧, マーキー表示の static inline), 未: LinkMenu_StateSelectUnlocked と同じ残差
NON_MATCH void LinkMenu_StateStart(LinkMenu* p) {
#ifdef NONMATCHING_C
  if (p->stateChanged) {
    p->stateChanged = FALSE;
  }

  if (Save_ReadCurrentSlot()) {
    MainSprite* spr = p->sprites;
    s32 line;
    s32 i;

    for (i = 0; i < p->count; i++, spr++) {
      s32 pose = i * 2 + 26;
      if (i != p->cursor) {
        pose++;
      }
      MainSprite_SetPose(spr, &p->gfx, pose, 0);
    }
    line = p->cursor + 1;
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + line));
    if (p->count == 3) {
      LinkMenu_SetState(p, 3);
    } else {
      LinkMenu_SetState(p, 2);
    }
  } else {
    LinkMenu_SetState(p, 1);
  }
#else
  INCFUNC("asm/func/LinkMenu_StateStart.inc");
#endif
}

// セーブデータを読めなかったときの state, メッセージ 0 を出して NG 音を鳴らし, 30 フレーム後の A か B で取り消しとして閉じる
void LinkMenu_StateNoSave(LinkMenu* p) {
  if (p->stateChanged) {
    s32* panel;

    p->stateChanged = FALSE;
    LinkMenu_LoadSystemBG(p, 3);
    panel = &p->panelID;
    *panel = MenuMessage_Create(1, 7, 28, 6);
    if (*panel >= 0) {
      MenuMessage_SetScript(*panel, p->script);
      MenuMessage_SetMessage(*panel, 0);
      MenuMessage_Start(*panel);
    }
    PlaySound_082406e0(SE_NG);
  }

  if (p->timer > 30 && (gInput[0].pressed & (A_BUTTON | B_BUTTON))) {
    p->result = 3;
    LinkMenu_SetState(p, 4);
    return;
  }
  p->timer++;
}

// 2 項目の選択画面, カーソル移動と決定・取り消しを受けつつ隠しコマンドを数え, 入力し終えるとクロスオーバーバトルを解放して 3 項目の画面へ移る
// 残差3箇所 (105/105), line = cursor + 1 の add の位置 (LinkMenu_StateStart と同じ), 入力列の添字で secretKeys の読みと lsls の順, crossoverUnlocked の格納で 0x369F を原典は番地より先に作る
// Tier A-C は試済 (比較の左右, 入力列のポインタローカル, cursor + 1 を先に置く式, 値のローカル), 未: line の add の位置は3関数共通の壁
NON_MATCH void LinkMenu_StateSelectLocked(LinkMenu* p) {
#ifdef NONMATCHING_C
  s32 line;
  u16* seq;

  if (p->stateChanged) {
    p->stateChanged = FALSE;
    p->count = 2;
    LinkMenu_LoadLinkBG(p, 0);
    line = p->cursor + 1;
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + line));
    FUN_08049f5c();
    LinkMenu_ShowItems(p);
    p->secretKeyIdx = 0;
    p->secretKeyTimer = 0;
  }

  if (p->timer > 30) {
    if (LinkMenu_ConfirmOrCancel(p)) {
      return;
    }
  }

  LinkMenu_MoveCursor(p);
  seq = (u16*)&p->secretKeys[p->secretKeyIdx];
  if (gInput[0].pressed == *seq) {
    p->secretKeyIdx++;
    p->secretKeyTimer = 0;
  } else if (gInput[0].pressed != 0) {
    p->secretKeyIdx = 0;
    p->secretKeyTimer = 0;
  }
  if (++p->secretKeyTimer > 119) {
    p->secretKeyIdx = 0;
    p->secretKeyTimer = 0;
  }
  if (p->secretKeyIdx > 15) {
    LinkMenu_SetState(p, 3);
    gSystemSaveData->crossoverUnlocked = 0x369F;
    PlaySound_082406e0(SE_ANS_CORRECT);
  }
  p->timer++;
#else
  INCFUNC("asm/func/LinkMenu_StateSelectLocked.inc");
#endif
}

// 3 項目 (クロスオーバーバトル解放後) の選択画面, カーソル移動と決定・取り消しを受ける
// 残差1命令 (46/46), line = cursor + 1 の add を原典は script の読み出しと bl の間に置く (LinkMenu_StateStart / StateSelectLocked / MoveCursor と同じ壁)
// Tier A-C は試済 (+ ++line で add は bl の後へ, ++line を左に置くと1命令増), 未: 引数評価後の emit_queue で出る形 (後置 ++ の値) を探す
NON_MATCH void LinkMenu_StateSelectUnlocked(LinkMenu* p) {
#ifdef NONMATCHING_C
  s32 line;

  if (p->stateChanged) {
    p->stateChanged = FALSE;
    p->count = 3;
    LinkMenu_LoadLinkBG(p, 0);
    line = p->cursor + 1;
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + line));
    FUN_08049f5c();
    LinkMenu_ShowItems(p);
  }

  if (p->timer > 30) {
    if (LinkMenu_ConfirmOrCancel(p)) {
      return;
    }
  }

  LinkMenu_MoveCursor(p);
  p->timer++;
#else
  INCFUNC("asm/func/LinkMenu_StateSelectUnlocked.inc");
#endif
}

// 選択結果を受けてフェードアウトし, 20 フレーム後に結果ごとのスクリプトを実行する, B で取り消したときは RTC の読み出し止めを解く
void LinkMenu_StateExit(LinkMenu* p) {
  if (p->stateChanged) {
    p->stateChanged = FALSE;
    StartBgObjPlttFade(3, 4, 4, 4, 4, 0xFFFF, 0);
    if (p->result == 3) {
      gRtcReadInhibit = FALSE;
      PlaySound_082406e0(SE_CANCEL);
    } else {
      PlaySound_082406e0(SE_SELECT);
    }
  }

  if (p->timer == 20 && p->scriptIDs[p->result] != 0) {
    VM_ExecByID(p->scriptIDs[p->result], NULL);
  }
  p->timer++;
}

// 状態ごとの処理を回し, パレットの 12 番の色を巡回させて光らせる
s32 LinkMenu_Update(LinkMenu* p) {
  gLinkMenuStateFuncs[p->state](p);

  if (++p->animTimer >= gLinkMenuGlowDurations[p->animIdx]) {
    p->animTimer = 0;
    if (++p->animIdx > 5) {
      p->animIdx = 0;
    }
    p->pltt[12] = gLinkMenuGlowColors[p->animIdx];
  }
  return 0;
}

s32 LinkMenu_Destroy(LinkMenu* p) {
  MainSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 3; i++, spr++) {
    MainSprite_Remove(spr);
  }

  Marquee_RequestClose();
  MenuMessage_Destroy(p->panelID);
  return 0;
}

s32 LinkMenu_Init(LinkMenu* p) {
  MainSpriteGfx* f;
  MainSprite* spr;
  Vec3 pos;
  s32 checkSave;
  s32 i;

  if (VM_SeekToNamedArg('r')) {
    p->script = VM_GetPC_Proxy();
    if (p->script == NULL) {
      return -1;
    }
  } else {
    return -1;
  }

  if (VM_SeekToNamedArg('p')) {
    for (i = 0; i < 4; i++) {
      p->scriptIDs[i] = VM_GetValue();
    }
  } else {
    for (i = 0; i < 4; i++) {
      p->scriptIDs[i] = 0;
    }
  }

  checkSave = VM_GetNamedArgValue('l', 0);
  f = GetFile(DIR_MAIN_SPRITE, SPR_UI_LINK);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  p->timer = 0;

  if (gSystemSaveData->crossoverUnlocked == 0x369F) {
    p->count = 3;
  } else {
    p->count = 2;
  }

  p->cursor = sLinkMenuLastCursor;
  if (p->cursor < 0) {
    p->cursor = 0;
  } else if (p->cursor >= p->count) {
    p->cursor = p->count - 1;
  }
  p->prevCursor = -1;

  if (checkSave) {
    LinkMenu_SetState(p, 0);
  } else if (p->count == 3) {
    LinkMenu_SetState(p, 3);
  } else {
    LinkMenu_SetState(p, 2);
  }

  VEC3_SET(pos, 0, 0, 0);
  p->secretKeys = gLinkMenuSecretKeys;
  p->result = 3;
  p->secretKeyIdx = 0;
  p->secretKeyTimer = 0;
  CopyMemory((u8*)p->pltt, (u8*)&gObjPlttData[0x2930], sizeof(p->pltt));

  spr = p->sprites;
  for (i = 0; i < 3; i++, spr++) {
    MainSprite_Add(spr, &p->gfx, i * 2 + 27, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, 0, 60, &pos);
    spr->pltt = p->pltt;
  }
  return 0;
}

// 0xB88C, HashName("通信メニュー")
LinkMenu* LinkMenu_Create(void) {
  LinkMenu* p = CreateEntity(ENTITY_UNK_11, sizeof(LinkMenu));

  if (p != NULL) {
    SetEntityRoutine(p, LinkMenu_Update, LinkMenu_Destroy);
    if (LinkMenu_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
