#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "link_session.h"
#include "sound.h"
#include "sprite_main.h"
#include "sprite_pltt.h"
#include "text.h"
#include "video.h"
#include "vm.h"

// 通信対戦の対戦ルールを決める画面 (HashName("対戦ルール画面"))
// 3行の選択肢を持つ通信メニュー, 各行は values[i] を counts[i] で巻き戻しながら左右で切り替える
typedef struct LinkBattleRuleScreen {
  Entity e;                                              // 0x000, ENTITY_UNK_11
  Tilemaps* tilemap;                                     // 0x018, MP_LINK
  rgb555* bgPltt;                                        // 0x01C, BGP_LINK
  MainSprite sprites[7];                                 // 0x020
  MainSpriteGfx gfx;                                     // 0x2C0, SPR_UI_LINK
  MainSpriteGfxFile* gfxFile;                            // 0x2E0, SPR_UI_LINK
  rgb555 cursorPltt[16];                                 // 0x2E4, gObjPlttData+0x2930 の16色の写し, sprites[0] (カーソル) の pltt, 12 番を点滅させる
  u16 cursorBlinkTimer;                                  // 0x304, 0..49 を回るカーソル点滅の周期
  u16 unk_306;                                           // 0x306, 読み手も書き手も見つかっていない, padding?
  void (*updateCallback)(struct LinkBattleRuleScreen*);  // 0x308
  u8* scriptPc;                                          // 0x30C, Init が VM_GetPC_Proxy() を入れる, VM_ParseStringRef / MenuMessage_SetScript に渡す
  u32 flags;                                             // 0x310, bit0: Marquee を開いている (LinkBattleRuleScreen_InitPanels で落とし, 最初の更新で立てる)
  s32 panelID0;                                          // 0x314, MenuMessage_Create(22, 4, 6, 2)
  u32 unk_318;                                           // 0x318, 読み手も書き手も見つかっていない
  s32 panelID1;                                          // 0x31C, MenuMessage_Create(20, 12, 8, 2)
  u8 unk_320;                                            // 0x320, Init で 0
  u8 repeatTimer;                                        // 0x321, 十字キーを押しっぱなしの間 0xC まで数え、離すと 0 に戻る
  u8 values[3];                                          // 0x322, 各行の選択値, 左右で counts[i] を上限に巻き戻る
  u8 counts[3];                                          // 0x325, 各行の選択肢数, LinkBattleRuleScreen_InitChoices が 1か2, 3, 4 を入れる
  s8 shown[3];                                           // 0x328, 表示済みの values[], 変化した行だけ LinkBattleRuleScreen_RefreshChoice が貼り直す
  s8 shownStringIdx;                                     // 0x32B, 表示済みの文字列番号, 同じなら LinkBattleRuleScreen_UpdateMarquee は引き直さない
  u8 entered;                                            // 0x32C, Init で 1, 最初の更新で Marquee とカーソルを用意して 0 に戻す
  u8 cursor;                                             // 0x32D, 選択中の行 (0..2), 上下で巻き戻り、変わると LinkBattleRuleScreen_PlaceCursor がスプライトを動かす
  u16 timer;                                             // 0x32E, 30 未満の間は入力を受け付けない
} LinkBattleRuleScreen;
static_assert(sizeof(LinkBattleRuleScreen) == 816);

void FUN_080e1238(s32 x, s32 y, s32 width, s32 height, u32 value, s32 bgIdx);

const s32 sCursorPos[3][2] = {
    {0, 0 },
    {0, 32},
    {0, 64}
};  // 0x085AE1B4, 行ごとのカーソル (sprites[0]) の位置

const s32 sLeftArrowPos[3][2] = {
    {32, 0 },
    {32, 32},
    {16, 64}
};  // 0x085AE1CC, 行ごとの "◀" (sprites[1]) の位置

const s32 sRightArrowPos[3][2] = {
    {0, 0 },
    {0, 32},
    {0, 64}
};  // 0x085AE1E4, 行ごとの "▶" (sprites[2]) の位置

const u16 sTimeLimits[4] = {60, 90, 120, 0};  // 0x085AE1FC, 2行目の選択値ごとの制限時間

// 参加人数, セッションが無ければ -1
static inline s32 LinkSession_GetRecordCount(void) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return -1;
  }
  return p->recordCount;
}

// idx 番目の参加者の記録, セッションが無いか idx が負なら NULL
static inline LinkPlayerRecord* LinkSession_GetRecord(s32 idx) {
  LinkSession* p = gLinkSession;

  if (p == NULL || idx < 0) {
    return NULL;
  }
  return &p->records[idx];
}

// 3行の選択値を通信セッション側へ写す
s32 LinkBattleRuleScreen_SendRules(LinkBattleRuleScreen* p) {
  LinkSession* q = gLinkSession;
  u8* dst;

  if (q == NULL || (dst = q->rulesOut.values) == NULL) {
    return -1;
  }

  dst[0] = p->values[0];
  dst[1] = p->values[1];
  dst[2] = p->values[2];
  return 0;
}

void LinkBattleRuleScreen_InitBG(LinkBattleRuleScreen* p) {
  TilemapFile* f = GetFile(DIR_TILE_MAP, MP_LINK);
  s32 param;
  s32 i;

  p->tilemap = f;
  param = 8;
  Video_SetupBGLayout(2, 0, f, 0, 0, 1, &param);
  Video_GenerateBGMap(3, 0, 0, 0, 0);
  p->bgPltt = GetBgPlttFile(BGP_LINK)->body;
  CpuCopy16(p->bgPltt, gBgPlttBuffer, 256 * sizeof(rgb555));
  for (i = 0; i < 5; i++) {
    FUN_080e1238(i + 25, 16, 1, 1, i + 22, 3);
  }
}

// 3行の選択肢の数と初期値を決める, unk_18 が 3 未満の参加者がいれば1行目は選べない
void LinkBattleRuleScreen_InitChoices(LinkBattleRuleScreen* p) {
  bool32 found;
  s32 count;
  s32 i;

  p->cursor = 0;
  p->values[1] = 0;
  p->values[2] = 0;
  p->counts[1] = 3;
  p->counts[2] = 4;
  found = FALSE;
  count = LinkSession_GetRecordCount();
  for (i = 0; i < count; i++) {
    if (LinkSession_GetRecord(i)->unk_18 < 3) {
      found = TRUE;
    }
  }
  if (found) {
    p->counts[0] = 1;
    p->values[0] = 1;
  } else {
    p->counts[0] = 2;
    p->values[0] = 0;
  }
}

// 選択中の行と値に合った説明文を Marquee に出す, 出しているものと同じなら出し直さない
// 残差は id を置くレジスタだけ (52/52, 原典 r1, こちら r0)
// 試済: id + 9 を別のローカルに受ける (これで命令数が揃う), 宣言順, u32, 番号を返す inline (悪化)
NON_MATCH void LinkBattleRuleScreen_UpdateMarquee(LinkBattleRuleScreen* p) {
#ifdef NONMATCHING_C
  s32 id;
  s32 strIdx;

  switch (p->cursor) {
    case 0: {
      id = p->values[0];
      break;
    }
    case 1: {
      id = p->values[1] + 2;
      break;
    }
    case 2: {
      id = p->values[2] + 5;
      break;
    }
    default: {
      id = 0;
      break;
    }
  }
  strIdx = id + 9;
  if (p->shownStringIdx != strIdx) {
    Marquee_Clear();
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->scriptPc) + strIdx));
    p->shownStringIdx = strIdx;
  }
#else
  INCFUNC("asm/func/LinkBattleRuleScreen_UpdateMarquee.inc");
#endif
}

void LinkBattleRuleScreen_InitPanels(LinkBattleRuleScreen* p) {
  p->panelID0 = MenuMessage_Create(22, 4, 6, 2);
  p->panelID1 = MenuMessage_Create(20, 12, 8, 2);
  Marquee_Clear();
  Marquee_RequestClose();
  CLEAR_FLAGS(p->flags, 1);
  LinkBattleRuleScreen_InitChoices(p);
  MenuMessage_SetScript(p->panelID0, p->scriptPc);
  MenuMessage_SetMessage(p->panelID0, p->values[0]);
  MenuMessage_Start(p->panelID0);
  p->shown[0] = p->values[0];
  MenuMessage_SetScript(p->panelID1, p->scriptPc);
  MenuMessage_SetMessage(p->panelID1, p->values[2] + 5);
  MenuMessage_Start(p->panelID1);
  p->shown[2] = p->values[2];
}

void LinkBattleRuleScreen_HidePanels(LinkBattleRuleScreen* p) {
  MenuMessage_Hide(p->panelID0);
  MenuMessage_Hide(p->panelID1);
}

void LinkBattleRuleScreen_InitSprites(LinkBattleRuleScreen* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPR_UI_LINK);
  s32 i;

  p->gfxFile = f;
  OpenMainSpriteFile(&p->gfx, f);
  for (i = 0; i < 7; i++) {
    MainSpriteGfx* gfx;
    u16 pose;

    switch (i) {
      case 0: {
        pose = LINK_LONG_CURSOR, gfx = &p->gfx;
        break;
      }
      case 1: {
        pose = LINK_LEFT, gfx = &p->gfx;
        break;
      }
      case 2: {
        pose = LINK_RIGHT, gfx = &p->gfx;
        break;
      }
      case 3:
      case 4:
      case 5: {
        pose = LINK_NUMBER_S1(0), gfx = &p->gfx;
        break;
      }
      case 6: {
        pose = LINK_START_OWARI, gfx = &p->gfx;
        break;
      }
      default: {
        pose = 0, gfx = &p->gfx;
        break;
      }
    }
    MainSprite_Add(&p->sprites[i], gfx, pose, SPRFLAG_SCREEN_COORD, 0, 0, 0, NULL);
  }
}

// カーソルと左右の矢印を選択中の行へ動かす, 1行目の選択肢が1つなら矢印を隠す
void LinkBattleRuleScreen_PlaceCursor(LinkBattleRuleScreen* p) {
  s32 i;

  for (i = 0; i < 7; i++) {
    switch (i) {
      case 0: {
        p->sprites[i].pos.x = sCursorPos[p->cursor][0];
        p->sprites[i].pos.y = sCursorPos[p->cursor][1];
        break;
      }
      case 1: {
        p->sprites[i].pos.x = sLeftArrowPos[p->cursor][0];
        p->sprites[i].pos.y = sLeftArrowPos[p->cursor][1];
        break;
      }
      case 2: {
        p->sprites[i].pos.x = sRightArrowPos[p->cursor][0];
        p->sprites[i].pos.y = sRightArrowPos[p->cursor][1];
        break;
      }
    }
  }
  p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  if (p->cursor == 0 && p->counts[0] == 1) {
    p->sprites[1].flags |= SPRFLAG_HIDDEN;
    p->sprites[2].flags |= SPRFLAG_HIDDEN;
  }
  p->sprites[6].pos.x = 0;
  p->sprites[6].pos.y = 0;
}

void LinkBattleRuleScreen_HideSprites(LinkBattleRuleScreen* p) {
  s32 i;

  for (i = 0; i < 7; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

void LinkBattleRuleScreen_RemoveSprites(LinkBattleRuleScreen* p) {
  s32 i;

  for (i = 0; i < 7; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

void LinkBattleRuleScreen_SavePltt(LinkBattleRuleScreen* p) {
  rgb555* src = &gObjPlttData[659 * 16];
  s32 i;

  for (i = 0; i < 16; i++) {
    p->cursorPltt[i] = src[i];
  }
  p->sprites[0].pltt = p->cursorPltt;
  p->cursorBlinkTimer = 0;
}

// 50フレーム周期でカーソルの明るさを進める
void LinkBattleRuleScreen_BlinkCursor(LinkBattleRuleScreen* p) {
  rgb555 color;

  if (p->cursorBlinkTimer < 10) {
    color = 31;
  } else if (p->cursorBlinkTimer < 18) {
    color = 27;
  } else if (p->cursorBlinkTimer < 26) {
    color = 18;
  } else if (p->cursorBlinkTimer < 34) {
    color = 10;
  } else if (p->cursorBlinkTimer < 42) {
    color = 18;
  } else {
    color = 27;
  }
  if (++p->cursorBlinkTimer >= 50) {
    p->cursorBlinkTimer = 0;
  }
  p->cursorPltt[12] = color;
}

// 制限時間を sprites[3..5] の数字で描く, 100 未満なら百の位を隠して右に寄せる
void LinkBattleRuleScreen_DrawTimeLimit(LinkBattleRuleScreen* p, s32 value) {
  s32 d;

  if (value > 99) {
    p->sprites[3].pos.x = 204;
    p->sprites[3].pos.y = 64;
    p->sprites[4].pos.x = 196;
    p->sprites[4].pos.y = 64;
    p->sprites[5].pos.x = 188;
    p->sprites[5].pos.y = 64;
    p->sprites[5].flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprites[3].pos.x = 200;
    p->sprites[3].pos.y = 64;
    p->sprites[4].pos.x = 192;
    p->sprites[4].pos.y = 64;
    p->sprites[5].flags |= SPRFLAG_HIDDEN;
  }
  d = 0;
  while (value > 99) {
    d++;
    value -= 100;
  }
  MainSprite_LoadPose(&p->sprites[5], &p->gfx, d);
  d = 0;
  while (value > 9) {
    d++;
    value -= 10;
  }
  MainSprite_LoadPose(&p->sprites[4], &p->gfx, d);
  d = 0;
  while (value > 0) {
    d++;
    value -= 1;
  }
  MainSprite_LoadPose(&p->sprites[3], &p->gfx, d);
}

// 選択中の行の値が変わっていれば表示を貼り直す
void LinkBattleRuleScreen_RefreshChoice(LinkBattleRuleScreen* p) {
  switch (p->cursor) {
    case 0: {
      if (p->values[0] != p->shown[0]) {
        MenuMessage_SetScript(p->panelID0, p->scriptPc);
        MenuMessage_SetMessage(p->panelID0, p->values[0]);
        MenuMessage_Start(p->panelID0);
        p->shown[0] = p->values[0];
      }
      break;
    }
    case 1: {
      if (p->values[1] != p->shown[1]) {
        LinkBattleRuleScreen_DrawTimeLimit(p, sTimeLimits[p->values[1]]);
        p->shown[1] = p->values[1];
      }
      break;
    }
    case 2: {
      if (p->values[2] != p->shown[2]) {
        MenuMessage_SetScript(p->panelID1, p->scriptPc);
        MenuMessage_SetMessage(p->panelID1, p->values[2] + 5);
        MenuMessage_Start(p->panelID1);
        p->shown[2] = p->values[2];
      }
      break;
    }
  }
}

// 十字キーで行と値を選び, START で決めたルールを送って閉じ, B で取りやめて閉じる
void LinkBattleRuleScreen_UpdateSelect(LinkBattleRuleScreen* p) {
  u32 cursor;
  u32 keys;
  u8* repeat;
  u32 wait;
  bool32 changed;
  u32 v;

  if (p->entered != 0) {
    FUN_08049f5c();
    SET_FLAGS(p->flags, 1);
    Marquee_Clear();
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->scriptPc) + 9));
    LinkBattleRuleScreen_RefreshChoice(p);
    p->cursor = 0;
    p->timer = 0;
    p->entered = 0;
  }

  if (p->timer < 30) {
    LinkBattleRuleScreen_BlinkCursor(p);
    LinkBattleRuleScreen_UpdateMarquee(p);
    p->timer++;
    return;
  }

  cursor = p->cursor;
  repeat = &p->repeatTimer;
  keys = 0;
  if (gInput[0].pressed & DPAD_UP) {
    keys = 1;
  } else if (gInput[0].pressed & DPAD_DOWN) {
    keys = 2;
  } else if (gInput[0].pressed & DPAD_LEFT) {
    keys = 4;
  } else if (gInput[0].pressed & DPAD_RIGHT) {
    keys = 8;
  } else if (gInput[0].pressed & START_BUTTON) {
    keys = 32;
  } else if (gInput[0].pressed & B_BUTTON) {
    keys = 16;
  }

  wait = gInput[0].down & DPAD_ANY;
  if (wait != 0) {
    wait = *repeat;
    if (wait >= 12) {
      if (gInput[0].down & DPAD_UP) {
        keys |= 1;
      } else if (gInput[0].down & DPAD_DOWN) {
        keys |= 2;
      }
      if (gInput[0].down & DPAD_LEFT) {
        keys |= 4;
      } else if (gInput[0].down & DPAD_RIGHT) {
        keys |= 8;
      }
      wait = 0;
    } else {
      wait++;
    }
  }
  *repeat = wait;

  changed = FALSE;
  if (keys & 1) {
    if (cursor == 0) {
      cursor = 2;
    } else {
      cursor--;
    }
    p->repeatTimer = 0;
  } else if (keys & 2) {
    if (cursor == 2) {
      cursor = 0;
    } else {
      cursor++;
    }
    p->repeatTimer = 0;
  } else if (keys & 4) {
    switch (p->cursor) {
      case 0: {
        if (p->counts[0] != 1) {
          v = p->values[0];
          if (v == 0) {
            v = p->counts[0] - 1;
          } else {
            v--;
          }
          p->values[0] = v;
          changed = TRUE;
        }
        break;
      }
      case 1: {
        v = p->values[1];
        if (v == 0) {
          v = p->counts[1] - 1;
        } else {
          v--;
        }
        p->values[1] = v;
        changed = TRUE;
        break;
      }
      case 2: {
        v = p->values[2];
        if (v == 0) {
          v = p->counts[2] - 1;
        } else {
          v--;
        }
        p->values[2] = v;
        changed = TRUE;
        break;
      }
    }
    if (changed) {
      LinkBattleRuleScreen_RefreshChoice(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
    }
    p->repeatTimer = 0;
  } else if (keys & 8) {
    switch (p->cursor) {
      case 0: {
        if (p->counts[0] != 1) {
          v = p->values[0];
          if (v == p->counts[0] - 1) {
            v = 0;
          } else {
            v++;
          }
          p->values[0] = v;
          changed = TRUE;
        }
        break;
      }
      case 1: {
        v = p->values[1];
        if (v == p->counts[1] - 1) {
          v = 0;
        } else {
          v++;
        }
        p->values[1] = v;
        changed = TRUE;
        break;
      }
      case 2: {
        v = p->values[2];
        if (v == p->counts[2] - 1) {
          v = 0;
        } else {
          v++;
        }
        p->values[2] = v;
        changed = TRUE;
        break;
      }
    }
    if (changed) {
      LinkBattleRuleScreen_RefreshChoice(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
    }
    p->repeatTimer = 0;
  } else if (keys & 32) {
    LinkBattleRuleScreen_SendRules(p);
    FUN_081df95c(1);
    PlaySound_082406e0(SE_SELECT);
    Marquee_CloseGlobal();
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    LinkBattleRuleScreen_HideSprites(p);
    KillEntity((Entity*)p);
    return;
  } else if (keys & 16) {
    FUN_081df95c(2);
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    LinkBattleRuleScreen_HideSprites(p);
    PlaySound_082406e0(SE_CANCEL);
    KillEntity((Entity*)p);
    return;
  }

  if (p->cursor != cursor) {
    p->cursor = cursor;
    LinkBattleRuleScreen_PlaceCursor(p);
    PlaySound_082406e0(SE_CURSOR_MOVE);
  }
  LinkBattleRuleScreen_BlinkCursor(p);
  LinkBattleRuleScreen_UpdateMarquee(p);
}

s32 LinkBattleRuleScreen_Update(LinkBattleRuleScreen* p) {
  if (!FUN_081dfa04()) {
    Marquee_CloseGlobal();
    LinkBattleRuleScreen_HideSprites(p);
    KillEntity((Entity*)p);
    return -1;
  }

  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  return 1;
}

s32 LinkBattleRuleScreen_Destroy(LinkBattleRuleScreen* p) {
  LinkBattleRuleScreen_RemoveSprites(p);
  LinkBattleRuleScreen_HidePanels(p);
  return 1;
}

s32 LinkBattleRuleScreen_Init(LinkBattleRuleScreen* p) {
  void (*update)(LinkBattleRuleScreen*);

  if (VM_SeekToNamedArg('s')) {
    p->scriptPc = VM_GetPC_Proxy();
    if (p->scriptPc == NULL) {
      return -1;
    }
  }
  ClearBGTilemapBuffer(0);
  LinkBattleRuleScreen_InitBG(p);
  LinkBattleRuleScreen_InitPanels(p);
  LinkBattleRuleScreen_InitSprites(p);
  LinkBattleRuleScreen_PlaceCursor(p);
  LinkBattleRuleScreen_SavePltt(p);
  LinkBattleRuleScreen_DrawTimeLimit(p, 60);
  p->shown[1] = 0;
  update = LinkBattleRuleScreen_UpdateSelect;
  p->updateCallback = update;
  p->entered = 1;
  p->unk_320 = 0;
  return 1;
}

// 0x08F4, HashName("対戦ルール画面")
LinkBattleRuleScreen* LinkBattleRuleScreen_Create(void) {
  LinkBattleRuleScreen* p = CreateEntity(ENTITY_UNK_11, sizeof(LinkBattleRuleScreen));

  if (p != NULL) {
    SetEntityRoutine(p, LinkBattleRuleScreen_Update, LinkBattleRuleScreen_Destroy);
    if (LinkBattleRuleScreen_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
