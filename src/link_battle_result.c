#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "link_session.h"
#include "menu.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// 結果画面の4行ぶんの値, 行は得点の降順に並べ替える
typedef struct {
  u16 shownScores[4];   // 0x00, 行ごとに表示中のスコア, 開くまでは乱数で回し, 開いたら rowScores を取り込む
  u16 revealTimers[4];  // 0x08, 行が開くまでの残りフレーム, 0 なら開いている
  u16 rowScores[4];     // 0x10, 行ごとの得点 (roundScores の写しを降順に並べたもの)
  u8 rowPlayers[4];     // 0x18, 行ごとのプレイヤー番号, rowScores と一緒に並べ替える
  u8 rowRanks[4];       // 0x1C, 行ごとの順位 (0 が1位, 同点は同じ順位)
} LinkBattleResultRows;

// 通信対戦終了後のリザルト画面(+再戦確認), 16枚のスプライトと4枚のテキストパネルを持ち、16色パレットをクロスフェードさせる
typedef struct LinkBattleResult {
  Entity e;                                          // 0x000, ENTITY_UNK_11
  MainSprite sprites[16];                            // 0x018, LinkBattleResult_InitSprites が MainSprite_Add(&sprites[i], &gfx0, poseIdx[i], ...) で16枚登録する
  MainSprite cursorSprite;                           // 0x618, MainSprite_Add(&cursorSprite, &gfx1, 4, ...)
  MainSpriteGfx gfx0;                                // 0x678, SPR_UI_LINK
  MainSpriteGfx gfx1;                                // 0x698, SPR_UI_START_MENU
  MainSpriteGfxFile* spriteFile0;                    // 0x6B8, SPR_UI_LINK
  MainSpriteGfxFile* spriteFile1;                    // 0x6BC, SPR_UI_START_MENU
  u16 poseIdx[16];                                   // 0x6C0, LinkBattleResult_InitSprites が 0 を入れて MainSprite_Add に渡す
  u16 cursorPose;                                    // 0x6E0, LinkBattleResult_InitSprites が 4 を入れる
  u16 unk_6e2;                                       // 0x6E2
  LinkBattleResultRows rows;                         // 0x6E4
  u16 unk_704;                                       // 0x704, LinkBattleResult_InitPltt が 0 を入れる
  s16 fadeSteps;                                     // 0x706, LinkBattleResult_StartPlttFade の第2引数 (_Init は 0x20), 1歩あたりの差分をこれで割る
  rgb555 plttCur[16];                                // 0x708, bgPltt+0x40 の複写, gBgPlttBuffer+0x20 へ流し、フェードの始点になる
  rgb555 plttA[16];                                  // 0x728, 同じ複写, fadeTarget が 0 以外のときの目標
  rgb555 plttB[16];                                  // 0x748, 同じ複写, fadeTarget が 0 のときの目標, 自分のスロットに 0x7FFF が入る
  s16 fadeR[16];                                     // 0x768, plttCur の赤成分を 5 ビット左シフトしたもの
  s16 fadeG[16];                                     // 0x788, 同じく緑
  s16 fadeB[16];                                     // 0x7A8, 同じく青
  s16 stepR[16];                                     // 0x7C8, (目標 - plttCur) の赤を 5 ビット左シフトして fadeSteps で割ったもの
  s16 stepG[16];                                     // 0x7E8, 同じく緑
  s16 stepB[16];                                     // 0x808, 同じく青
  u16 fadeTarget;                                    // 0x828, 0 なら plttB、それ以外なら plttA へ寄せる, LinkBattleResult_StartPlttFade が毎回反転する
  u16 fadeHoldTimer;                                 // 0x82A, plttB へ寄せ終えたあと止めておく残りフレーム (20), 0 でまた plttA へ寄せ始める
  Tilemaps* tilemap0;                                // 0x82C, MP_LINK, BG2 に敷く
  Tilemaps* tilemap1;                                // 0x830, MP_SYSTEM, BG0 に敷く
  rgb555* bgPltt;                                    // 0x834, BGP_LINK
  void (*updateCallback)(struct LinkBattleResult*);  // 0x838
  u8* scriptPc;                                      // 0x83C, '.s' の後の VM_GetPC_Proxy(), MenuMessage_SetScript に渡す
  u8 unk_840[4];                                     // 0x840
  s32 panelID[4];                                    // 0x844, MenuMessage_Create(12, 4 + i*4, 10, 2) の戻り値を4つ
  u8 state;                                          // 0x854, 今の状態の番号 (0: 集計, 1: 発表, 2: 結果, 3: 再戦の確認, 4: 退出待ち)
  bool8 stateEntered;                                // 0x855, 状態が変わった直後の最初の更新で 0 に戻す
  u16 stateTimer;                                    // 0x856, 状態に入ってからのフレーム数, 集計中は偶数フレームごとに効果音を鳴らす
  u8 revealedCount;                                  // 0x858, 開いた行の数, playerCount に達すると結果表示へ
  s8 playerCount;                                    // 0x859, gLinkSession->recordCount, 符号つきで負なら _Init は失敗する
  bool8 rematch;                                     // 0x85A, 再戦の確認で選んでいる方 (TRUE: はい, 左, FALSE: いいえ, 右), FUN_081df8a0 に渡す
  u8 unk_85b;                                        // 0x85B
} LinkBattleResult;
static_assert(sizeof(LinkBattleResult) == 2140);

// 通信相手の記録を1件引く, まだセッションが無ければ NULL
static inline LinkPlayerRecord* LinkSession_GetRecord(s32 idx) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return NULL;
  }
  return &p->records[idx];
}

// 自分が何番目の参加者かを返す, セッションが無ければ -1
static inline s32 LinkSession_GetPlayerIdx(void) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return -1;
  }
  return p->playerIdx;
}

// idx 番目の参加者のこの回の得点, セッションが無ければ 0
static inline s16 LinkSession_GetRoundScore(s32 idx) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return 0;
  }
  return p->roundScores[idx];
}

// 参加者ごとの名札の 4x2 タイル (BG3), 行のプレイヤー番号で引く
const u16 sPlayerLabelTiles[4][8] = {
    {32, 33, 34, 32, 48, 49, 50, 48},
    {35, 36, 37, 35, 51, 52, 53, 51},
    {38, 39, 40, 38, 54, 55, 56, 54},
    {41, 42, 43, 41, 57, 58, 59, 57},
};  // 0x085AE208

// 行ごとの名札のタイル位置 (x, y), 2段 x 4列
const u16 sPlayerLabelPos[4][2][4][2] = {
    {
     {{7, 4}, {8, 4}, {9, 4}, {10, 4}},
     {{7, 5}, {8, 5}, {9, 5}, {10, 5}},
     },
    {
     {{7, 8}, {8, 8}, {9, 8}, {10, 8}},
     {{7, 9}, {8, 9}, {9, 9}, {10, 9}},
     },
    {
     {{7, 12}, {8, 12}, {9, 12}, {10, 12}},
     {{7, 13}, {8, 13}, {9, 13}, {10, 13}},
     },
    {
     {{7, 16}, {8, 16}, {9, 16}, {10, 16}},
     {{7, 17}, {8, 17}, {9, 17}, {10, 17}},
     },
};  // 0x085AE248

// 順位の 5x2 タイル (BG3), 1位はパレット 3, ほかはパレット 2 で描く
const u16 sRankTiles[5][10] = {
    {14, 44, 45, 46, 14, 14, 60, 61, 62, 14},
    {1,  64, 65, 66, 1,  1,  80, 81, 82, 1 },
    {1,  67, 68, 66, 1,  1,  83, 84, 82, 1 },
    {1,  69, 70, 71, 1,  1,  85, 86, 87, 1 },
    {1,  47, 47, 47, 1,  1,  63, 63, 63, 1 },
};  // 0x085AE2C8

// 行ごとの順位のタイル位置 (x, y), 2段 x 5列
const u16 sRankLabelPos[4][2][5][2] = {
    {
     {{1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
     {{1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
     },
    {
     {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}},
     {{1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}},
     },
    {
     {{1, 12}, {2, 12}, {3, 12}, {4, 12}, {5, 12}},
     {{1, 13}, {2, 13}, {3, 13}, {4, 13}, {5, 13}},
     },
    {
     {{1, 16}, {2, 16}, {3, 16}, {4, 16}, {5, 16}},
     {{1, 17}, {2, 17}, {3, 17}, {4, 17}, {5, 17}},
     },
};  // 0x085AE32C

// 参加人数, セッションが無ければ -1
static inline s32 LinkSession_GetRecordCount(void) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return -1;
  }
  return p->recordCount;
}

// 状態関数を差し替えて、切り替え直後の1フレームだけ立つフラグを付ける
static inline void LinkBattleResult_SetState(LinkBattleResult* p, void* fn, u8 state) {
  p->updateCallback = fn;
  p->stateEntered = 1;
  p->state = state;
}

// BG2 と BG0 にタイルマップを敷き、背景パレットを作業用バッファへ流す
void LinkBattleResult_InitBG(LinkBattleResult* p) {
  s32 bgIndices[1];

  p->tilemap0 = GetFile(DIR_TILE_MAP, MP_LINK);
  p->tilemap1 = GetFile(DIR_TILE_MAP, MP_SYSTEM);
  bgIndices[0] = 9;
  Video_SetupBGLayout(2, 0, p->tilemap0, 0, 0, 1, bgIndices);
  bgIndices[0] = 3;
  Video_SetupBGLayout(0, 0, p->tilemap1, 0, 0, 1, bgIndices);
  Video_GenerateBGMap(3, 0, 0, 0, 0);
  p->bgPltt = GetBgPlttFile(BGP_LINK)->body;
  CpuCopy16(p->bgPltt, gBgPlttBuffer, 256 * sizeof(rgb555));
}

// 参加者4人分のテキストパネルを縦に並べて作り、最初は隠しておく
void LinkBattleResult_InitPanels(LinkBattleResult* p) {
  s32 i;

  p->panelID[0] = MenuMessage_Create(12, 4, 10, 2);
  p->panelID[1] = MenuMessage_Create(12, 8, 10, 2);
  p->panelID[2] = MenuMessage_Create(12, 12, 10, 2);
  p->panelID[3] = MenuMessage_Create(12, 16, 10, 2);
  for (i = 0; i < 4; i++) {
    MenuMessage_SetScript(p->panelID[i], p->scriptPc);
    MenuMessage_SetMessage(p->panelID[i], i);
    MenuMessage_Hide(p->panelID[i]);
  }
}

// idx 番目のテキストパネルに、その参加者の記録を差し込んで表示する
void LinkBattleResult_ShowRowPanel(LinkBattleResult* p, s32 idx) {
  LinkPlayerRecord* rec = LinkSession_GetRecord(p->rows.rowPlayers[idx]);

  if (rec != NULL) {
    MenuMessage_SetScript(p->panelID[idx], p->scriptPc);
    MenuMessage_SetMessage(p->panelID[idx], idx);
    FUN_0804a40c(p->panelID[idx], idx, (char*)rec);
    MenuMessage_Start(p->panelID[idx]);
  }
}

// 4枚のテキストパネルをすべて隠す
void LinkBattleResult_HidePanels(LinkBattleResult* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    MenuMessage_Hide(p->panelID[i]);
  }
}

// BG のタイルマップから (x, y) のエントリのアドレスを得る
BgMapEntry* LinkBattleResult_GetBgMapEntry(s32 bg, s32 x, s32 y) {
  BgState* state = &gBgStates[bg];
  BgMapEntry* tilemap = state->tilemap;

  return tilemap + (x & 31) + (y & 31) * 32;
}

// idx 番目の行に, その参加者の名札と順位のタイルを BG3 へ貼る
// 129/126命令, 原典は表の番地 (名札・順位のタイル, 位置) をループ外へ出さず毎回プールから読み, k をレジスタに持つ, こちらは表の番地を高位レジスタに出して k を退避する
// 試済: 位置の表を [4][2][8] にして x += 2 (131), dst をループ外で宣言 (130)
NON_MATCH void LinkBattleResult_DrawRowLabels(LinkBattleResult* p, s32 idx) {
#ifdef NONMATCHING_C
  s32 k;
  s32 y;
  s32 x;

  k = 0;
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 4; x++) {
      BgMapEntry* dst = LinkBattleResult_GetBgMapEntry(3, sPlayerLabelPos[idx][y][x][0], sPlayerLabelPos[idx][y][x][1]);

      *dst = sPlayerLabelTiles[p->rows.rowPlayers[idx]][k] | 0x2000;
      k++;
    }
  }
  k = 0;
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 5; x++) {
      BgMapEntry* dst = LinkBattleResult_GetBgMapEntry(3, sRankLabelPos[idx][y][x][0], sRankLabelPos[idx][y][x][1]);

      if (p->rows.rowRanks[idx] == 0) {
        *dst = sRankTiles[p->rows.rowRanks[idx]][k] | 0x3000;
      } else {
        *dst = sRankTiles[p->rows.rowRanks[idx]][k] | 0x2000;
      }
      k++;
    }
  }
#else
  INCFUNC("asm/func/LinkBattleResult_DrawRowLabels.inc");
#endif
}

// 数字の16枚とカーソルのスプライトを登録する, カーソルは隠しておく
void LinkBattleResult_InitSprites(LinkBattleResult* p) {
  s32 i;

  p->spriteFile0 = GetFile(DIR_MAIN_SPRITE, SPR_UI_LINK);
  OpenMainSpriteFile(&p->gfx0, p->spriteFile0);
  p->spriteFile1 = GetFile(DIR_MAIN_SPRITE, SPR_UI_START_MENU);
  OpenMainSpriteFile(&p->gfx1, p->spriteFile1);
  for (i = 0; i < 16; i++) {
    p->poseIdx[i] = 0;
    if (MainSprite_Add(&p->sprites[i], &p->gfx0, p->poseIdx[i], SPRFLAG_SCREEN_COORD, 0, 0, 0, NULL) != 0) {
      return;
    }
  }
  p->cursorPose = 4;
  if (MainSprite_Add(&p->cursorSprite, &p->gfx1, p->cursorPose, SPRFLAG_SCREEN_COORD, 0, 0, 0, NULL) != 0) {
    return;
  }
  p->cursorSprite.flags |= SPRFLAG_HIDDEN;
}

// 4人×4枚のスプライトを格子状に並べ、参加していない行は隠す
// 80/80命令, 残差は x と逆向きカウンタの r5/r6 の入れ替わりと, 原典は x の初期化と x -= 8 を誘導変数の初期化/更新の間に置く点
// 試済: for の初期化・更新に x を入れる (2 通り), 216 - i * 8 (式のまま/ループ内ローカル, いずれも 81), 1行目の x を他の行へ写す (84)
NON_MATCH void LinkBattleResult_PlaceSprites(LinkBattleResult* p) {
#ifdef NONMATCHING_C
  s32 x = 216;
  s32 i;

  for (i = 0; i < 4; i++) {
    p->sprites[i].pos.x = x;
    p->sprites[i + 4].pos.x = x;
    p->sprites[i + 8].pos.x = x;
    p->sprites[i + 12].pos.x = x;
    p->sprites[i].pos.y = 32;
    p->sprites[i + 4].pos.y = 64;
    p->sprites[i + 8].pos.y = 96;
    p->sprites[i + 12].pos.y = 128;
    x -= 8;
  }
  for (i = p->playerCount; i < 4; i++) {
    p->sprites[i * 4].flags |= SPRFLAG_HIDDEN;
    p->sprites[i * 4 + 1].flags |= SPRFLAG_HIDDEN;
    p->sprites[i * 4 + 2].flags |= SPRFLAG_HIDDEN;
    p->sprites[i * 4 + 3].flags |= SPRFLAG_HIDDEN;
  }
  p->cursorSprite.pos.x = -8;
  p->cursorSprite.pos.y = -56;
#else
  INCFUNC("asm/func/LinkBattleResult_PlaceSprites.inc");
#endif
}

// 17枚のスプライトをすべて隠す
void LinkBattleResult_HideSprites(LinkBattleResult* p) {
  s32 i;

  for (i = 0; i < 17; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

// 17枚のスプライトをすべて描画リストから外す
void LinkBattleResult_RemoveSprites(LinkBattleResult* p) {
  s32 i;

  for (i = 0; i < 17; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

// スコアを4桁に分解して、その参加者の行のスプライトに並べる
void LinkBattleResult_DrawScore(LinkBattleResult* p, s32 idx) {
  s32 v = p->rows.shownScores[idx];
  s32 n = idx * 4;
  s32 d;

  d = 0;
  while (v > 999) {
    d++;
    v -= 1000;
  }
  MainSprite_LoadPose(&p->sprites[n + 3], &p->gfx0, d);
  d = 0;
  while (v > 99) {
    d++;
    v -= 100;
  }
  MainSprite_LoadPose(&p->sprites[n + 2], &p->gfx0, d);
  d = 0;
  while (v > 9) {
    d++;
    v -= 10;
  }
  MainSprite_LoadPose(&p->sprites[n + 1], &p->gfx0, d);
  d = 0;
  while (v > 0) {
    d++;
    v -= 1;
  }
  MainSprite_LoadPose(&p->sprites[n], &p->gfx0, d);
}

// 経過時間と乱数からその参加者のスコアを決め、桁を並べ直す
void LinkBattleResult_RollScore(LinkBattleResult* p, s32 idx) {
  s32 score = p->stateTimer * p->stateTimer >> 2;
  score += (Random2() % 8) * 10;
  score += (Random2() % 8) * 100;
  score += (Random2() % 8) * 1000;
  if (score > 9999) {
    score = 9999;
  }
  p->rows.shownScores[idx] = score;
  LinkBattleResult_DrawScore(p, idx);
}

// 1フレームおきに効果音を鳴らしつつ、参加者ごとのスロットを更新する
void LinkBattleResult_RollScores(LinkBattleResult* p) {
  s32 i;

  if (Mod(p->stateTimer, 2) == 0) {
    PlaySound_082406e0(SE_COUNT_UP);
  }
  for (i = 0; i < p->playerCount; i++) {
    if (p->rows.revealTimers[i] != 0) {
      LinkBattleResult_RollScore(p, i);
    }
  }
}

// パレットを3面ぶん初期化し、自分のスロットだけ白にする
void LinkBattleResult_InitPltt(LinkBattleResult* p) {
  CpuCopy16(&p->bgPltt[32], p->plttCur, 32);
  CpuCopy16(&p->bgPltt[32], p->plttA, 32);
  CpuCopy16(&p->bgPltt[32], p->plttB, 32);
  p->unk_704 = 0;
  p->fadeTarget = 0;
  p->fadeHoldTimer = 0;
  switch (LinkSession_GetPlayerIdx()) {
    case 0: {
      p->plttB[8] = RGB_WHITE;
      break;
    }
    case 1: {
      p->plttB[10] = RGB_WHITE;
      break;
    }
    case 2: {
      p->plttB[12] = RGB_WHITE;
      break;
    }
    case 3: {
      p->plttB[14] = RGB_WHITE;
      break;
    }
    default: {
      p->plttB[8] = RGB_WHITE;
      break;
    }
  }
  CpuCopy16(p->plttCur, &gBgPlttBuffer[32], 32);
}

// plttCur から fadeTarget の向きのパレットへ steps 歩で寄せる準備をし, 次の向きへ切り替える
void LinkBattleResult_StartPlttFade(LinkBattleResult* p, s32 steps) {
  s32 i;

  for (i = 0; i < 16; i++) {
    s32 target;
    s32 color;

    if (p->fadeTarget != 0) {
      target = p->plttA[i];
    } else {
      target = p->plttB[i];
    }
    color = p->plttCur[i];

    p->stepR[i] = ((target & 31) - (color & 31)) << 5;
    p->stepG[i] = (((target >> 5) & 31) - ((color >> 5) & 31)) << 5;
    p->stepB[i] = (((target >> 10) & 31) - ((color >> 10) & 31)) << 5;
    p->stepR[i] = Div(p->stepR[i], steps);
    p->stepG[i] = Div(p->stepG[i], steps);
    p->stepB[i] = Div(p->stepB[i], steps);
    p->fadeR[i] = (color & 31) << 5;
    p->fadeG[i] = ((color >> 5) & 31) << 5;
    p->fadeB[i] = ((color >> 10) & 31) << 5;
  }
  p->fadeTarget ^= 1;
  p->fadeSteps = steps;
}

// パレットのクロスフェードを1歩進める, 歩数を使い切ったら次へ切り替えて 1 を返す
s32 LinkBattleResult_UpdatePlttFade(LinkBattleResult* p) {
  s32 i;

  if (p->fadeHoldTimer != 0) {
    if (--p->fadeHoldTimer == 0) {
      LinkBattleResult_StartPlttFade(p, 32);
      p->fadeHoldTimer = 0;
    }
  } else {
    for (i = 0; i < 16; i++) {
      p->fadeR[i] += p->stepR[i];
      p->fadeG[i] += p->stepG[i];
      p->fadeB[i] += p->stepB[i];
      p->plttCur[i] = FixToInt(5, p->fadeR[i]) | (FixToInt(5, p->fadeG[i]) << 5) | (FixToInt(5, p->fadeB[i]) << 10);
    }
    CpuCopy16(p->plttCur, &gBgPlttBuffer[32], 32);
    if (--p->fadeSteps == 0) {
      if (p->fadeTarget == 0) {
        p->fadeHoldTimer = 20;
      } else {
        LinkBattleResult_StartPlttFade(p, 32);
      }
      return 1;
    }
  }
  return 0;
}

// i 番目と j 番目の並びを入れ替える
void LinkBattleResult_SwapRows(LinkBattleResult* p, s32 i, s32 j) {
  LinkBattleResultRows tmp;

  tmp.rowScores[0] = p->rows.rowScores[i];
  tmp.rowPlayers[0] = p->rows.rowPlayers[i];
  p->rows.rowScores[i] = p->rows.rowScores[j];
  p->rows.rowPlayers[i] = p->rows.rowPlayers[j];
  p->rows.rowScores[j] = tmp.rowScores[0];
  p->rows.rowPlayers[j] = tmp.rowPlayers[0];
}

// スコアの降順になるまで隣同士を入れ替える
void LinkBattleResult_SortRows(LinkBattleResult* p) {
  s32 i;
  s32 j;

  for (i = 0; i < p->playerCount; i++) {
    for (j = 0; j < p->playerCount - 1; j++) {
      if (p->rows.rowScores[j] < p->rows.rowScores[j + 1]) {
        LinkBattleResult_SwapRows(p, j, j + 1);
      }
    }
  }
}

// 順位ごとの行が開くまでのフレーム数, 下位から先に開き1位は最後
const u16 sRevealDelays[4] = {100, 100, 40, 1};  // 0x085AE3CC

// 通信対戦の順位ごとの得点補正, [参加人数][順位] (64 で 1 倍), LinkSession_AddRankPoints が使う
const s8 sLinkRankBonus[5][4] = {
    {0,  0,   0,   0  },
    {0,  0,   0,   0  },
    {64, -64, 0,   0  },
    {48, 16,  -64, 0  },
    {48, 16,  -16, -48},
};  // 0x085AE3D4

// 並べ終えた行に順位と開くまでの待ちを付ける, 同点は同じ順位にして次の順位を飛ばす
void LinkBattleResult_AssignRanks(LinkBattleResult* p) {
  s32 rank = 0;
  s32 ties = 1;
  s32 i;

  for (i = 0; i < p->playerCount - 1; i++) {
    p->rows.rowRanks[i] = rank;
    p->rows.revealTimers[i] = sRevealDelays[rank];
    if (p->rows.rowScores[i] != p->rows.rowScores[i + 1]) {
      rank += ties;
      ties = 1;
    } else {
      ties++;
    }
  }
  p->rows.rowRanks[i] = rank;
  p->rows.revealTimers[i] = sRevealDelays[rank];
}

// 参加者ごとの待ち時間が切れたら、その枠を開いて効果音を鳴らす
void LinkBattleResult_TickRevealTimers(LinkBattleResult* p) {
  s32 i;

  for (i = 0; i < p->playerCount; i++) {
    if (p->rows.revealTimers[i] != 0) {
      if (--p->rows.revealTimers[i] == 0) {
        p->rows.shownScores[i] = p->rows.rowScores[i];
        LinkBattleResult_DrawScore(p, i);
        LinkBattleResult_DrawRowLabels(p, i);
        LinkBattleResult_ShowRowPanel(p, i);
        PlaySound_082406e0(SE_LINK_359);
        p->revealedCount++;
      }
    }
  }
}

// 自分が1位なら通信対戦の勝ち数を1つ増やす (9999 で止める)
void LinkBattleResult_CountWin(LinkBattleResult* p) {
  s32 playerIdx = LinkSession_GetPlayerIdx();
  s32 i;

  for (i = 0; i < p->playerCount; i++) {
    if (p->rows.rowPlayers[i] == playerIdx) {
      if (p->rows.rowRanks[i] == 0) {
        s32 count = gStat->linkBattleWins + 1;
        if (count > 9999) {
          count = 9999;
        }
        gStat->linkBattleWins = count;
      }
      return;
    }
  }
}

// 参加者のスコアを取り込み、並び順を初期化して整列させる
void LinkBattleResult_InitRows(LinkBattleResult* p) {
  s32 i;

  for (i = 0; i < p->playerCount; i++) {
    p->rows.rowScores[i] = LinkSession_GetRoundScore(i);
  }
  p->rows.rowPlayers[0] = 0;
  p->rows.rowPlayers[1] = 1;
  p->rows.rowPlayers[2] = 2;
  p->rows.rowPlayers[3] = 3;
  LinkBattleResult_SortRows(p);
  LinkBattleResult_AssignRanks(p);
  LinkBattleResult_CountWin(p);
}

// 自分が1位なら BGM_END を流す
// 36/38命令, LinkSession_GetPlayerIdx と count のローカル, ループ内 return で効果音の塊がループ前に出る形までは揃う, 残りは count の読み方 (原典は ldrb + lsl/asr で i の 0 を作る位置も違う)
// 試済: break で抜ける形, count を毎回読む形, 未: s8 count
NON_MATCH void LinkBattleResult_PlayEndBgm(LinkBattleResult* p) {
#ifdef NONMATCHING_C
  s32 playerIdx = LinkSession_GetPlayerIdx();
  s32 count;
  s32 i;

  if (playerIdx < 0) {
    return;
  }
  count = p->playerCount;
  for (i = 0; i < count; i++) {
    if (p->rows.rowPlayers[i] == playerIdx && p->rows.rowRanks[i] == 0) {
      sound_08240264(BGM_END);
      return;
    }
  }
#else
  INCFUNC("asm/func/LinkBattleResult_PlayEndBgm.inc");
#endif
}

// 開いた直後に効果音を鳴らし、10フレーム後に案内メッセージへ差し替える
void LinkBattleResult_UpdateExit(LinkBattleResult* p) {
  s32 state;

  if (p->stateEntered != 0) {
    FUN_081df8f0(1);
    p->stateTimer = 0;
    p->stateEntered = 0;
  }
  if (p->stateTimer <= 9) {
    p->stateTimer++;
  } else if (p->stateTimer == 10) {
    MenuMessage_SetMessage(p->panelID[0], 5);
    p->stateTimer++;
  }
  state = FUN_081dfa04();
  if (state == 0x11 || state == 0x14) {
    LinkBattleResult_HideSprites(p);
    KillEntity((Entity*)p);
  }
}

// 再戦するかを左右で選ばせ, A で決めて B で取りやめる
void LinkBattleResult_UpdateRematch(LinkBattleResult* p) {
  if (p->stateEntered != 0) {
    LinkBattleResult_HidePanels(p);
    LinkBattleResult_HideSprites(p);
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(1);
    ClearBGTilemapBuffer(2);
    ClearBGTilemapBuffer(3);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    MenuMessage_SetRect(p->panelID[0], 1, 7, 28, 6);
    MenuMessage_SetScript(p->panelID[0], p->scriptPc);
    MenuMessage_SetMessage(p->panelID[0], 4);
    MenuMessage_Start(p->panelID[0]);
    p->cursorSprite.flags &= ~SPRFLAG_HIDDEN;
    p->rematch = TRUE;
    p->stateTimer = 0;
    p->stateEntered = 0;
    MainSprite_SetAnim(&p->cursorSprite, &p->gfx1, p->cursorPose, PLAYMODE_LOOP, 0);
  }
  if (gInput[0].pressed & DPAD_LEFT) {
    if (!p->rematch) {
      p->cursorPose = 4;
      p->rematch = TRUE;
      PlaySound_082406e0(SE_CURSOR_MOVE);
      MainSprite_SetAnim(&p->cursorSprite, &p->gfx1, p->cursorPose, PLAYMODE_LOOP, 0);
    }
  } else if (gInput[0].pressed & DPAD_RIGHT) {
    if (p->rematch) {
      p->cursorPose = 5;
      p->rematch = FALSE;
      PlaySound_082406e0(SE_CURSOR_MOVE);
      MainSprite_SetAnim(&p->cursorSprite, &p->gfx1, p->cursorPose, PLAYMODE_LOOP, 0);
    }
  } else if (gInput[0].pressed & A_BUTTON) {
    p->cursorSprite.flags |= SPRFLAG_HIDDEN;
    FUN_081df8a0(p->rematch);
    LinkBattleResult_SetState(p, LinkBattleResult_UpdateExit, 4);
    if (p->rematch) {
      PlaySound_082406e0(SE_SELECT);
    } else {
      PlaySound_082406e0(SE_CANCEL);
    }
    return;
  } else if (gInput[0].pressed & B_BUTTON) {
    p->cursorSprite.flags |= SPRFLAG_HIDDEN;
    FUN_081df8a0(0);
    LinkBattleResult_SetState(p, LinkBattleResult_UpdateExit, 4);
    PlaySound_082406e0(SE_CANCEL);
    return;
  }
  MainSprite_AdvanceAnim(&p->cursorSprite, &p->gfx1);
}

// 結果を出し終えたら A / START で次の画面へ進む
void LinkBattleResult_UpdateResult(LinkBattleResult* p) {
  if (p->stateEntered != 0) {
    LinkBattleResult_PlayEndBgm(p);
    p->stateTimer = 0;
    p->stateEntered = 0;
  }
  LinkBattleResult_UpdatePlttFade(p);
  if (p->stateTimer <= 9) {
    p->stateTimer++;
  } else if (gInput[0].pressed & (A_BUTTON | START_BUTTON)) {
    PlaySound_082406e0(SE_SELECT);
    LinkBattleResult_SetState(p, LinkBattleResult_UpdateRematch, 3);
  }
}

// 結果表示中, ボタンが押されたら残り時間を詰め、全員出そろったら次の状態へ
void LinkBattleResult_UpdateReveal(LinkBattleResult* p) {
  s32 i;

  if (p->stateEntered != 0) {
    p->stateTimer = 0;
    p->stateEntered = 0;
  }
  if (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON)) {
    for (i = 0; i < p->playerCount; i++) {
      if (p->rows.revealTimers[i] > 1) {
        p->rows.revealTimers[i] = 1;
      }
    }
  }
  LinkBattleResult_RollScores(p);
  LinkBattleResult_TickRevealTimers(p);
  if (p->revealedCount >= p->playerCount) {
    LinkBattleResult_SetState(p, LinkBattleResult_UpdateResult, 2);
  } else {
    p->stateTimer++;
  }
}

// 集計の演出中, ボタンで飛ばすか、64フレーム経ったら結果表示へ
void LinkBattleResult_UpdateTally(LinkBattleResult* p) {
  s32 i;

  if (p->stateEntered != 0) {
    p->stateTimer = 0;
    p->stateEntered = 0;
  }
  if (p->stateTimer > 10 && (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON))) {
    for (i = 0; i < p->playerCount; i++) {
      p->rows.revealTimers[i] = 1;
    }
    LinkBattleResult_SetState(p, LinkBattleResult_UpdateReveal, 1);
  } else if (p->stateTimer > 64) {
    LinkBattleResult_SetState(p, LinkBattleResult_UpdateReveal, 1);
  } else {
    LinkBattleResult_RollScores(p);
    p->stateTimer++;
  }
}

s32 LinkBattleResult_Update(LinkBattleResult* p) {
  if (!FUN_081dfa04()) {
    KillEntity((Entity*)p);
    return -1;
  }
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  return 1;
}

s32 LinkBattleResult_Destroy(LinkBattleResult* p) {
  LinkBattleResult_HidePanels(p);
  LinkBattleResult_RemoveSprites(p);
  return 1;
}

s32 LinkBattleResult_Init(LinkBattleResult* p) {
  if (VM_SeekToNamedArg('s')) {
    p->scriptPc = VM_GetPC_Proxy();
    if (p->scriptPc == NULL) {
      return -1;
    }
  }
  FUN_081df8f0(0);
  p->playerCount = LinkSession_GetRecordCount();
  if (p->playerCount < 0) {
    return -1;
  }
  LinkBattleResult_InitBG(p);
  LinkBattleResult_InitPanels(p);
  LinkBattleResult_InitSprites(p);
  LinkBattleResult_PlaceSprites(p);
  LinkBattleResult_InitPltt(p);
  LinkBattleResult_StartPlttFade(p, 32);
  p->revealedCount = 0;
  LinkBattleResult_InitRows(p);
  LinkBattleResult_SetState(p, LinkBattleResult_UpdateTally, 0);
  HUD_SetMode(HUD_HIDDEN);
  return 1;
}

LinkBattleResult* LinkBattleResult_Create(void) {
  LinkBattleResult* p = CreateEntity(ENTITY_UNK_11, sizeof(LinkBattleResult));

  if (p != NULL) {
    SetEntityRoutine(p, LinkBattleResult_Update, LinkBattleResult_Destroy);
    if (LinkBattleResult_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
