#include "bg_pltt.h"
#include "entity.h"
#include "global.h"
#include "input.h"
#include "link_session.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

typedef struct {
  u8 status;    // 0x0, gLinkSession->connStatus[i] の写し,2 未満なら未参加で立ち絵は出ない
  u8 unk_1[3];  // 0x1, 読み手も書き手も見つかっていない, padding?
} LinkBattleLobbySlot;
static_assert(sizeof(LinkBattleLobbySlot) == 4);

// 通信の参加者一覧画面,4人分の枠に UI_LINK のアイコンと DJANGO_SABATA の立ち絵を並べ、gLinkSession の進行状況を表示する
typedef struct LinkBattleLobby {
  Entity e;                                         // 0x000, ENTITY_UNK_11
  Tilemaps* tilemap;                                // 0x018, LinkBattleLobby_InitBG が MP_LINK を入れ、Video_SetupBGLayout / Video_SetBGLayer に渡す
  rgb555* bgPltt;                                   // 0x01C, BGP_LINK
  MainSprite sprites[8];                            // 0x020, LinkBattleLobby_InitCharSprites が 0..3 に立ち絵を、LinkBattleLobby_InitIcons が 4..7 にアイコンを登録する
  MainSpriteGfx uiGfx;                              // 0x320, sprites[4..7] 用,LinkBattleLobby_InitIcons が uiSpriteFile から開く
  MainSpriteGfx charGfx;                            // 0x340, sprites[0..3] 用,LinkBattleLobby_InitCharSprites が charSpriteFile から開く
  u16 animID[8];                                    // 0x360, LinkBattleLobby_ResetAnimIDs が 4,4,4,4,0x3A,0x3B,0x3C,0x3D を入れ、LinkBattleLobby_UpdateSlots が状態に応じて差し替える
  s16 shownAnimID[8];                               // 0x370, 表示済みの animID,初期値 -1,違うときだけ LinkBattleLobby_UpdateSlots が貼り直す
  MainSpriteGfxFile* uiGfxFile;                     // 0x380, SPR_UI_LINK
  MainSpriteGfxFile* charGfxFile;                   // 0x384, SPR_DJANGO_SABATA
  rgb555 pltt[16];                                  // 0x388, LinkBattleLobby_SavePltt が bgPltt+0x40 から複写,LinkBattleLobby_UpdatePltt が点滅させて gBgPlttBuffer のバンク2へ送る
  u16 blinkTimer;                                   // 0x3A8, LinkBattleLobby_UpdatePltt が 0..0x31 で回し、選択中の枠の色を決める
  u8 unk_3aa[2];                                    // 0x3AA, 読み手も書き手も見つかっていない
  LinkBattleLobbySlot slots[4];                     // 0x3AC, 4人分,LinkBattleLobby_UpdateWait が毎フレーム gLinkSession から埋める
  void (*updateCallback)(struct LinkBattleLobby*);  // 0x3BC, Init は LinkBattleLobby_UpdateWait、キャンセルすると LinkBattleLobby_UpdateCancel
  u8* scriptPc;                                     // 0x3C0, '.s' の後の VM_GetPC_Proxy(), LinkBattleLobby_UpdateMarquee が VM_ParseStringRef に渡す
  u8 unk_3c4[4];                                    // 0x3C4, 読み手も書き手も見つかっていない
  s32 playerIdx;                                    // 0x3C8, LinkBattleLobby_UpdateWait が Sio_GetMultiId() を入れる,負なら通信していない
  u32 recordCount;                                  // 0x3CC, LinkBattleLobby_UpdateWait が gLinkSession->recordCount を入れる,セッションが無ければ -1
  u8 state;                                         // 0x3D0, 今の状態の番号 (0: 待機, 1: 取りやめ)
  s8 shownStringIdx;                                // 0x3D1, 表示済みの文字列番号,同じなら LinkBattleLobby_UpdateMarquee は引き直さない
  u8 shownRecordCount;                              // 0x3D2, recordCount の下位バイトの控え,LinkBattleLobby_UpdateMarquee が変化を見る
  u8 unk_3d3;                                       // 0x3D3, 読み手も書き手も見つかっていない
  bool8 needsInit;                                  // 0x3D4, Init が 1 を入れ、LinkBattleLobby_UpdateWait / LinkBattleLobby_UpdateCancel が初回だけの処理をして 0 に戻す
  u8 unk_3d5;                                       // 0x3D5, 読み手も書き手も見つかっていない
  u16 timer;                                        // 0x3D6, LinkBattleLobby_UpdateWait は 0x3C 未満の間 入力を受け付けない,LinkBattleLobby_UpdateCancel は 10 で LinkBattleLobby_Cancel を呼ぶ
  u16 unk_3d8;                                      // 0x3D8, FUN_081dc32c が VM_ExecByID に渡す,書き手が見つかっていない
  u16 exitScriptID;                                 // 0x3DA, '.e=0', LinkBattleLobby_Cancel がこれを実行して自分を消す
} LinkBattleLobby;
static_assert(sizeof(LinkBattleLobby) == 988);

static LinkBattleLobby* gLinkBattleLobby;  // 0x030001A8

// 状態関数を差し替えて, 切り替え直後の1フレームだけ立つフラグを付ける
static inline void LinkBattleLobby_SetState(LinkBattleLobby* p, void* fn, u8 state) {
  p->updateCallback = fn;
  p->needsInit = TRUE;
  p->state = state;
}

s32 Marquee_SetVarValue(s32 idx, s32 value);

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

// idx 番目の参加者の接続の状況, セッションが無ければ 0
static inline u8 LinkSession_GetConnStatus(s32 idx) {
  if (gLinkSession == NULL) {
    return 0;
  }
  return gLinkSession->connStatus[idx];
}

static inline bool8 LinkSession_IsUnk2cSet(void) {
  if (gLinkSession != NULL && gLinkSession->unk_2c[0] == 1) {
    return TRUE;
  }
  return FALSE;
}

void FUN_080e1238(s32 x, s32 y, s32 width, s32 height, u32 value, s32 bgIdx);
s32 Sio_GetMultiId(void);

// 枠ごとに立ち絵へ足すスプライトのフラグ, 右の列 (1, 3) は SPRFLAG_XFLIP で左を向かせる
const u8 sCharFlipFlags[4] = {0, SPRFLAG_XFLIP, 0, SPRFLAG_XFLIP};  // 0x085AE204

// BG2 にルール画面のタイルマップを敷き, パレットを BG パレットへ送る
void LinkBattleLobby_InitBG(LinkBattleLobby* p) {
  s32 layer;

  p->tilemap = GetFile(DIR_TILE_MAP, MP_LINK);
  layer = 7;
  Video_SetupBGLayout(2, 0, p->tilemap, 0, 0, 1, &layer);

  p->bgPltt = GetBgPlttFile(BGP_LINK)->body;
  CpuCopy16(p->bgPltt, gBgPlttBuffer, 256 * sizeof(rgb555));
}

// 背景パレットの後半16色を控えてから点滅タイマーを戻す
void LinkBattleLobby_SavePltt(LinkBattleLobby* p) {
  CpuCopy16(&p->bgPltt[32], p->pltt, 16 * sizeof(rgb555));
  p->blinkTimer = 0;
}

// 参加している枠を明るく, 自分の枠を50フレーム周期で点滅させて BG パレットへ送る, 通信していなければ全部暗くする
void LinkBattleLobby_UpdatePltt(LinkBattleLobby* p) {
  rgb555 color;

  if (p->playerIdx < 0) {
    p->pltt[9] = 0x6739;
    p->pltt[11] = 0x6739;
    p->pltt[13] = 0x6739;
    p->pltt[15] = 0x6739;
    CpuCopy16(p->pltt, &gBgPlttBuffer[32], 32);
    return;
  }

  if (p->blinkTimer < 10) {
    color = 31;
  } else if (p->blinkTimer < 18) {
    color = 27;
  } else if (p->blinkTimer < 26) {
    color = 18;
  } else if (p->blinkTimer < 34) {
    color = 10;
  } else if (p->blinkTimer < 42) {
    color = 18;
  } else {
    color = 27;
  }
  if (++p->blinkTimer > 49) {
    p->blinkTimer = 0;
  }
  if (p->slots[0].status == 0) {
    p->pltt[9] = 0x6739;
  } else {
    p->pltt[9] = 0x35B4;
  }
  if (p->slots[1].status == 0) {
    p->pltt[11] = 0x6739;
  } else {
    p->pltt[11] = 0x35B4;
  }
  if (p->slots[2].status == 0) {
    p->pltt[13] = 0x6739;
  } else {
    p->pltt[13] = 0x35B4;
  }
  if (p->slots[3].status == 0) {
    p->pltt[15] = 0x6739;
  } else {
    p->pltt[15] = 0x35B4;
  }
  switch (p->playerIdx) {
    case 0: {
      if (p->slots[0].status != 0) {
        p->pltt[9] = color;
      }
      break;
    }
    case 1: {
      if (p->slots[1].status != 0) {
        p->pltt[11] = color;
      }
      break;
    }
    case 2: {
      if (p->slots[2].status != 0) {
        p->pltt[13] = color;
      }
      break;
    }
    case 3: {
      if (p->slots[3].status != 0) {
        p->pltt[15] = color;
      }
      break;
    }
  }
  CpuCopy16(p->pltt, &gBgPlttBuffer[32], 32);
}

// 立ち絵4枚とアイコン4枚のアニメ番号を初期値に戻す
void LinkBattleLobby_ResetAnimIDs(LinkBattleLobby* p) {
  p->animID[0] = 4;
  p->animID[1] = 4;
  p->animID[2] = 4;
  p->animID[3] = 4;
  p->animID[4] = 0x3A;
  p->animID[5] = 0x3B;
  p->animID[6] = 0x3C;
  p->animID[7] = 0x3D;
}

// UI のスプライトを開き, sprites[4..7] にアイコンを登録する
void LinkBattleLobby_InitIcons(LinkBattleLobby* p) {
  s32 i;

  p->uiGfxFile = GetFile(DIR_MAIN_SPRITE, SPR_UI_LINK);
  OpenMainSpriteFile(&p->uiGfx, p->uiGfxFile);
  for (i = 4; i < 8; i++) {
    MainSprite_Add(&p->sprites[i], &p->uiGfx, p->animID[i], SPRFLAG_SCREEN_COORD, 0, 0, 0, NULL);
    p->shownAnimID[i] = -1;
  }
}

// 4人分の立ち絵を画面の四隅に置き, アイコンは原点に置く
void LinkBattleLobby_PlaceSprites(LinkBattleLobby* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    switch (i) {
      case 0: {
        p->sprites[i].pos.x = 29;
        p->sprites[i].pos.y = 64;
        break;
      }
      case 1: {
        p->sprites[i].pos.x = 211;
        p->sprites[i].pos.y = 64;
        break;
      }
      case 2: {
        p->sprites[i].pos.x = 29;
        p->sprites[i].pos.y = 112;
        break;
      }
      case 3: {
        p->sprites[i].pos.x = 211;
        p->sprites[i].pos.y = 112;
        break;
      }
      default: {
        p->sprites[i].pos.x = 0;
        p->sprites[i].pos.y = 0;
        break;
      }
    }
  }
}

// ジャンゴとサバタの立ち絵を sprites[0..3] に登録し, 枠ごとのパレットを当てる
void LinkBattleLobby_InitCharSprites(LinkBattleLobby* p) {
  s32 i;

  p->charGfxFile = GetFile(DIR_MAIN_SPRITE, SPR_DJANGO_SABATA);
  OpenMainSpriteFile(&p->charGfx, p->charGfxFile);
  for (i = 0; i < 4; i++) {
    s32 plttID;

    MainSprite_Add(&p->sprites[i], &p->charGfx, p->animID[i], SPRFLAG_SCREEN_COORD, 0, PLAYMODE_LOOP, 0, NULL);
    p->shownAnimID[i] = -1;
    switch (i) {
      case 0: {
        plttID = 34;
        break;
      }
      case 1: {
        plttID = 35;
        break;
      }
      case 2: {
        plttID = 36;
        break;
      }
      case 3: {
        plttID = 37;
        break;
      }
      default: {
        plttID = 0;
        break;
      }
    }
    p->sprites[i].pltt = &gObjPlttData[plttID * 16];
    p->sprites[i].plttID = plttID;
  }
}

// アニメを1コマ進め, 終わったか次のコマで終わるなら TRUE (呼び出し元は見つかっていない)
bool32 LinkBattleLobby_AdvanceSpriteAnim(MainSprite* sprite, MainSpriteGfx* gfx) {
  bool32 done = MainSprite_AdvanceAnim(sprite, gfx);

  if ((sprite->animEvents & MAIN_ANIM_EVENT_WILL_END) || done) {
    return TRUE;
  }
  return FALSE;
}

void LinkBattleLobby_HideSprites(LinkBattleLobby* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

void LinkBattleLobby_RemoveSprites(LinkBattleLobby* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

// 参加者ごとに, まだ揃っていなければ枠のアイコンを, 揃ったら武器の種類に合った立ち絵を出す
void LinkBattleLobby_UpdateSlots(LinkBattleLobby* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    LinkPlayerRecord* rec = LinkSession_GetRecord(i);

    if (rec == NULL) {
      p->sprites[i + 4].flags &= ~SPRFLAG_HIDDEN;
      p->animID[i + 4] = i + 0x3A;
      p->sprites[i].flags |= SPRFLAG_HIDDEN;
    } else if (p->slots[i].status >= 2) {
      s32 state = gLinkSession->state;

      if (state < 6) {
        p->sprites[i].flags |= SPRFLAG_HIDDEN;
        p->animID[i + 4] = i + 0x36;
        p->sprites[i + 4].flags &= ~SPRFLAG_HIDDEN;
      } else {
        p->sprites[i].flags &= ~SPRFLAG_HIDDEN;
        p->sprites[i + 4].flags |= SPRFLAG_HIDDEN;
        if (i < 2) {
          switch (rec->loadout[0]) {
            case 0: {
              p->animID[i] = 8;
              break;
            }
            case 1: {
              p->animID[i] = 0xCF;
              break;
            }
            case 2: {
              p->animID[i] = 0x1A6;
              break;
            }
          }
        } else {
          switch (rec->loadout[0]) {
            case 0: {
              p->animID[i] = 6;
              break;
            }
            case 1: {
              p->animID[i] = 0xCD;
              break;
            }
            case 2: {
              p->animID[i] = 0x1A4;
              break;
            }
          }
        }
      }
    } else {
      if (p->slots[i].status == 1) {
        p->sprites[i + 4].flags &= ~SPRFLAG_HIDDEN;
        p->animID[i + 4] = i + 0x36;
        p->sprites[i].flags |= SPRFLAG_HIDDEN;
      } else {
        p->sprites[i + 4].flags &= ~SPRFLAG_HIDDEN;
        p->animID[i + 4] = i + 0x3A;
        p->sprites[i].flags |= SPRFLAG_HIDDEN;
      }
    }
    if (p->animID[i + 4] != p->shownAnimID[i + 4]) {
      MainSprite_LoadPose(&p->sprites[i + 4], &p->uiGfx, p->animID[i + 4]);
    }
    if (p->animID[i] != p->shownAnimID[i]) {
      p->sprites[i].flags |= sCharFlipFlags[i];
      MainSprite_SetAnim(&p->sprites[i], &p->charGfx, p->animID[i], PLAYMODE_LOOP, 0);
      p->shownAnimID[i] = p->animID[i];
    }
    MainSprite_AdvanceAnim(&p->sprites[i], &p->charGfx);
  }
}

// 通信の進み具合と自分の接続の状況に合った案内を Marquee に出す, 出しているものと同じなら出し直さない
// 183/188命令 (この直書き), 案内を出す塊を (p, idx) の static inline, 子機判定を bool8 の inline にすると 188/188 まで揃い, 残りはレジスタ割当だけ (定数の一時レジスタ r0/r2, state を r2 に置く形)
// 試済: 接続状況をローカルに受ける, 宣言順, idx / state を u32, 早期 return をやめる形
NON_MATCH void LinkBattleLobby_UpdateMarquee(LinkBattleLobby* p) {
#ifdef NONMATCHING_C
  s32 status;
  s32 state;

  if (p->playerIdx < 0) {
    if (p->shownStringIdx != 2) {
      Marquee_Clear();
      Marquee_SetText(GetStringByID(VM_ParseStringRef(p->scriptPc) + 2));
      p->shownStringIdx = 2;
    }
    return;
  }
  state = FUN_081dfa04();
  if (state == 5 || state == 6) {
    if (p->shownStringIdx != 4) {
      Marquee_Clear();
      Marquee_SetText(GetStringByID(VM_ParseStringRef(p->scriptPc) + 4));
      p->shownStringIdx = 4;
    }
  } else if (gLinkSession != NULL && gLinkSession->sioID != 0 && state == 8) {
    if (p->shownStringIdx != 6) {
      Marquee_Clear();
      Marquee_SetText(GetStringByID(VM_ParseStringRef(p->scriptPc) + 6));
      p->shownStringIdx = 6;
    }
  } else {
    if (gLinkSession == NULL) {
      status = 0;
    } else {
      status = gLinkSession->connStatus[p->playerIdx];
    }
    switch (status) {
      case 0:
      case 1: {
        if (p->shownStringIdx != 1) {
          Marquee_Clear();
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->scriptPc) + 1));
          p->shownStringIdx = 1;
        }
        break;
      }
      case 2: {
        if (p->shownStringIdx != 2) {
          Marquee_Clear();
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->scriptPc) + 2));
          p->shownStringIdx = 2;
        }
        break;
      }
      case 3: {
        if (p->recordCount != p->shownRecordCount) {
          Marquee_Clear();
          Marquee_SetVarValue(0, p->recordCount);
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->scriptPc) + 3));
          p->shownStringIdx = 3;
        } else if (p->shownStringIdx != 3) {
          Marquee_Clear();
          Marquee_SetVarValue(0, p->recordCount);
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->scriptPc) + 3));
          p->shownStringIdx = 3;
        }
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/LinkBattleLobby_UpdateMarquee.inc");
#endif
}

// 画面を片付けて取りやめを通信へ知らせ, exitScriptID があれば実行して自分を消す
void LinkBattleLobby_Cancel(LinkBattleLobby* p) {
  Marquee_Clear();
  ClearBGTilemapBuffer(0);
  ClearBGTilemapBuffer(1);
  ClearBGTilemapBuffer(2);
  ClearBGTilemapBuffer(3);
  LinkBattleLobby_HideSprites(p);
  FUN_081df95c(2);
  if (p->exitScriptID != 0) {
    VM_ExecByID(p->exitScriptID, NULL);
    KillEntity((Entity*)p);
  }
}

// unk_3d8 のスクリプトがあれば実行して自分を消す
void FUN_081dc32c(LinkBattleLobby* p) {
  if (p->unk_3d8 != 0) {
    VM_ExecByID(p->unk_3d8, NULL);
    KillEntity((Entity*)p);
  }
}

// 取りやめたあと 10 フレーム待ってから画面を閉じる
void LinkBattleLobby_UpdateCancel(LinkBattleLobby* p) {
  if (p->needsInit) {
    p->timer = 0;
    p->needsInit = FALSE;
  }
  if (p->timer == 10) {
    LinkBattleLobby_Cancel(p);
  }
  p->timer++;
}

// 参加者の接続状況を読んで表示を更新し, B で取りやめる (対戦が始まったら案内を消す)
void LinkBattleLobby_UpdateWait(LinkBattleLobby* p) {
  s32 i;

  if (p->needsInit) {
    p->shownStringIdx = -1;
    Video_SetBGLayer(3, p->tilemap, 7);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    for (i = 0; i < 5; i++) {
      FUN_080e1238(i + 25, 16, 1, 1, i + 22, 3);
    }
    p->timer = 0;
    p->needsInit = FALSE;
  }
  p->playerIdx = Sio_GetMultiId();
  p->recordCount = LinkSession_GetRecordCount();
  for (i = 0; i < 4; i++) {
    if (p->playerIdx < 0) {
      p->slots[i].status = 0;
    } else {
      p->slots[i].status = LinkSession_GetConnStatus(i);
    }
  }
  LinkBattleLobby_UpdateSlots(p);
  LinkBattleLobby_UpdatePltt(p);
  LinkBattleLobby_UpdateMarquee(p);
  p->shownRecordCount = p->recordCount;
  if (p->timer < 60) {
    p->timer++;
  } else if (!LinkSession_IsUnk2cSet()) {
    if (gInput[0].pressed & B_BUTTON) {
      LinkBattleLobby_SetState(p, LinkBattleLobby_UpdateCancel, 1);
      PlaySound_082406e0(SE_CANCEL);
    } else {
      for (i = 0; i < 5; i++) {
        FUN_080e1238(i + 25, 16, 1, 1, i + 22, 3);
      }
    }
  } else {
    for (i = 0; i < 5; i++) {
      FUN_080e1238(i + 25, 16, 1, 1, 1, 3);
    }
  }
}

s32 LinkBattleLobby_Update(LinkBattleLobby* p) {
  if (!FUN_081dfa04()) {
    Marquee_CloseGlobal();
    KillEntity((Entity*)p);
    return -1;
  }
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  return 1;
}

s32 LinkBattleLobby_Destroy(LinkBattleLobby* p) {
  LinkBattleLobby_RemoveSprites(p);
  gLinkBattleLobby = NULL;
  return 1;
}

s32 LinkBattleLobby_Init(LinkBattleLobby* p) {
  void (*update)(LinkBattleLobby*);

  if (VM_SeekToNamedArg('s')) {
    p->scriptPc = VM_GetPC_Proxy();
    if (p->scriptPc == NULL) {
      return -1;
    }
  }
  p->exitScriptID = VM_GetNamedArgValue('e', 0);
  ClearBGTilemapBuffer(0);
  LinkBattleLobby_InitBG(p);
  LinkBattleLobby_ResetAnimIDs(p);
  LinkBattleLobby_InitIcons(p);
  LinkBattleLobby_InitCharSprites(p);
  LinkBattleLobby_PlaceSprites(p);
  LinkBattleLobby_SavePltt(p);
  update = LinkBattleLobby_UpdateWait;
  p->updateCallback = update;
  p->needsInit = TRUE;
  p->state = 0;
  if (VM_GetNamedArgValue('f', 0)) {
    StartBgObjPlttFade(2, 4, 4, 4, 4, 0xFFFF, 0);
  }
  gLinkBattleLobby = p;
  return 1;
}

LinkBattleLobby* LinkBattleLobby_Create(void) {
  LinkBattleLobby* p;

  if (gLinkBattleLobby != NULL) {
    return gLinkBattleLobby;
  }

  p = CreateEntity(ENTITY_UNK_11, sizeof(LinkBattleLobby));
  if (p != NULL) {
    SetEntityRoutine(p, LinkBattleLobby_Update, LinkBattleLobby_Destroy);
    if (LinkBattleLobby_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void LinkBattleLobby_ClearGlobal(void) { gLinkBattleLobby = NULL; }

// 一覧画面が出ていれば, 隠して BG とマーキーを消してから自分を消す
void LinkBattleLobby_Close(void) {
  if (gLinkBattleLobby != NULL) {
    LinkBattleLobby_HideSprites(gLinkBattleLobby);
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(1);
    ClearBGTilemapBuffer(2);
    ClearBGTilemapBuffer(3);
    Marquee_Clear();
    KillEntity((Entity*)gLinkBattleLobby);
  }
}
