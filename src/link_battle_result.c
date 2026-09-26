#include "bg_pltt.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"

struct LinkBattleResult;
typedef void (*EntityB85FFunc)(struct LinkBattleResult* p);

// 通信対戦終了後のリザルト画面(+再戦確認), 16枚のスプライトと4枚のテキストパネルを持ち、16色パレットをクロスフェードさせる
typedef struct LinkBattleResult {
  Entity e;                     // 0x000, ENTITY_UNK_11
  MainSprite sprites[16];       // 0x018, FUN_081dc9dc が MainSprite_Add(&sprites[i], &gfx0, poseIdx[i], ...) で16枚登録する
  MainSprite cursorSprite;      // 0x618, MainSprite_Add(&cursorSprite, &gfx1, 4, ...)
  MainSpriteGfx gfx0;           // 0x678, OpenMainSpriteFile(&gfx0, spriteFile0)
  MainSpriteGfx gfx1;           // 0x698, OpenMainSpriteFile(&gfx1, spriteFile1)
  MainSpriteFile* spriteFile0;  // 0x6B8, SPRITE_UI_LINK
  MainSpriteFile* spriteFile1;  // 0x6BC, SPRITE_UI_START_MENU
  u16 poseIdx[16];              // 0x6C0, FUN_081dc9dc が 0 を入れて MainSprite_Add に渡す
  u16 cursorPose;               // 0x6E0, FUN_081dc9dc が 4 を入れる
  u16 unk_6e2;                  // 0x6E2
  u16 unk_6e4[4];               // 0x6E4, タイマーが切れたときに unk_6f4 の値を取り込む
  u16 unk_6ec[4];               // 0x6EC, 0 でないスロットだけ FUN_081dcc48 が処理する
  u16 unk_6f4[4];               // 0x6F4, FUN_081dd2dc が u16 として走査する
  u8 unk_6fc[4];                // 0x6FC, FUN_081dd2dc が 0, 1, 2, 3 を入れる
  u8 unk_700[4];                // 0x700
  u16 unk_704;                  // 0x704, FUN_081dcd50 が 0 を入れる
  s16 fadeSteps;                // 0x706, FUN_081dce14 の第2引数 (_Init は 0x20), 1歩あたりの差分をこれで割る
  rgb555 plttCur[16];           // 0x708, bgPltt+0x40 の複写, gBgPlttBuffer+0x20 へ流し、フェードの始点になる
  rgb555 plttA[16];             // 0x728, 同じ複写, fadeTarget が 0 以外のときの目標
  rgb555 plttB[16];             // 0x748, 同じ複写, fadeTarget が 0 のときの目標, 自分のスロットに 0x7FFF が入る
  s16 fadeR[16];                // 0x768, plttCur の赤成分を 5 ビット左シフトしたもの
  s16 fadeG[16];                // 0x788, 同じく緑
  s16 fadeB[16];                // 0x7A8, 同じく青
  s16 stepR[16];                // 0x7C8, (目標 - plttCur) の赤を 5 ビット左シフトして fadeSteps で割ったもの
  s16 stepG[16];                // 0x7E8, 同じく緑
  s16 stepB[16];                // 0x808, 同じく青
  u16 fadeTarget;               // 0x828, 0 なら plttB、それ以外なら plttA へ寄せる, FUN_081dce14 が毎回反転する
  u16 unk_82a;                  // 0x82A, FUN_081dcd50 が 0 を入れる
  TilemapHeader* tilemap0;      // 0x82C, GetFile(DIR_TILE_MAP, 0xCD91), BG2 に敷く
  TilemapHeader* tilemap1;      // 0x830, GetFile(DIR_TILE_MAP, 0xA413), BG0 に敷く
  rgb555* bgPltt;               // 0x834, GetFile(DIR_BGPLTT, 0x26BB) + 0x14
  EntityB85FFunc fn;            // 0x838, _Update が毎フレーム呼ぶ, _Init が 0x081DD774 を入れる
  u8* scriptPc;                 // 0x83C, '.s' の後の FUN_0823d340(), TextPanel_SetScript に渡す
  u8 unk_840[4];                // 0x840
  s32 panelID[4];               // 0x844, TextPanel_Create(0xC, 4 + i*4, 10, 2) の戻り値を4つ
  u8 unk_854;                   // 0x854, _Init が 0 を入れる
  u8 unk_855;                   // 0x855, _Init が 1 を入れる
  u16 unk_856;                  // 0x856, 偶数フレームごとに効果音を鳴らすためのカウンタ
  u8 unk_858;                   // 0x858, _Init が 0 を入れる
  s8 playerCount;               // 0x859, gEntity9A9F->recordCount, 符号つきで負なら _Init は失敗する
  u8 unk_85a[2];                // 0x85A
} LinkBattleResult;
static_assert(sizeof(LinkBattleResult) == 2140);

s32 FUN_0804a40c(s32 id, s32 idx, u32 str);
s32 FUN_081dfa04(void);
void FUN_081df8f0(s32 n);

void FUN_081dd628(LinkBattleResult* p);
void FUN_081dd434(LinkBattleResult* p);
s32 FUN_081dcf34(LinkBattleResult* p);

// 状態関数を差し替えて、切り替え直後の1フレームだけ立つフラグを付ける
static inline void EntityB85F_SetState(LinkBattleResult* p, EntityB85FFunc fn, u8 state) {
  p->fn = fn;
  p->unk_855 = 1;
  p->unk_854 = state;
}

// BG2 と BG0 にタイルマップを敷き、背景パレットを作業用バッファへ流す
void FUN_081dc6d0(LinkBattleResult* p) {
  s32 bgIndices[1];

  p->tilemap0 = GetFile(DIR_TILE_MAP, 0xCD91);
  p->tilemap1 = GetFile(DIR_TILE_MAP, 0xA413);
  bgIndices[0] = 9;
  Video_SetupBGLayout(2, 0, p->tilemap0, 0, 0, 1, bgIndices);
  bgIndices[0] = 3;
  Video_SetupBGLayout(0, 0, p->tilemap1, 0, 0, 1, bgIndices);
  Video_GenerateBGMap(3, 0, 0, 0, 0);
  p->bgPltt = GetBgPlttFile(0x26BB)->body;
  CpuCopy16(p->bgPltt, gBgPlttBuffer, 512);
}

// 参加者4人分のテキストパネルを縦に並べて作り、最初は隠しておく
void FUN_081dc788(LinkBattleResult* p) {
  s32 i;

  p->panelID[0] = TextPanel_Create(12, 4, 10, 2);
  p->panelID[1] = TextPanel_Create(12, 8, 10, 2);
  p->panelID[2] = TextPanel_Create(12, 12, 10, 2);
  p->panelID[3] = TextPanel_Create(12, 16, 10, 2);
  for (i = 0; i < 4; i++) {
    TextPanel_SetScript(p->panelID[i], p->scriptPc);
    TextPanel_SetMessage(p->panelID[i], i);
    TextPanel_Hide(p->panelID[i]);
  }
}

// idx 番目のテキストパネルに、その参加者の記録を差し込んで表示する
void FUN_081dc818(LinkBattleResult* p, s32 idx) {
  Entity9A9FRecord* rec = Entity9A9F_GetRecord(p->unk_6fc[idx]);

  if (rec != NULL) {
    TextPanel_SetScript(p->panelID[idx], p->scriptPc);
    TextPanel_SetMessage(p->panelID[idx], idx);
    FUN_0804a40c(p->panelID[idx], idx, (u32)rec);
    TextPanel_Start(p->panelID[idx]);
  }
}

// 4枚のテキストパネルをすべて隠す
void FUN_081dc880(LinkBattleResult* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    TextPanel_Hide(p->panelID[i]);
  }
}

// BG のタイルマップから (x, y) のエントリのアドレスを得る
u16* FUN_081dc8a0(s32 bg, s32 x, s32 y) {
  BgState* state = &gBgStates[bg];
  u16* tilemap = state->tilemap;

  return tilemap + (x & 31) + (y & 31) * 32;
}

NAKED void FUN_081dc8c0(LinkBattleResult* p, s32 idx) { INCFUNC("asm/func/FUN_081dc8c0.inc"); }

NAKED void FUN_081dc9dc(LinkBattleResult* p) { INCFUNC("asm/func/FUN_081dc9dc.inc"); }

// 4人×4枚のスプライトを格子状に並べ、参加していない行は隠す
NON_MATCH void FUN_081dcaa4(LinkBattleResult* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 x;

  x = 216;
  for (i = 0; i < 4; i++, x -= 8) {
    p->sprites[i].pos.x = x;
    p->sprites[i + 4].pos.x = x;
    p->sprites[i + 8].pos.x = x;
    p->sprites[i + 12].pos.x = x;
    p->sprites[i].pos.y = 32;
    p->sprites[i + 4].pos.y = 64;
    p->sprites[i + 8].pos.y = 96;
    p->sprites[i + 12].pos.y = 128;
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
  INCFUNC("asm/func/FUN_081dcaa4.inc");
#endif
}

// 17枚のスプライトをすべて隠す
void FUN_081dcb54(LinkBattleResult* p) {
  s32 i;

  for (i = 0; i < 17; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

// 17枚のスプライトをすべて描画リストから外す
void FUN_081dcb70(LinkBattleResult* p) {
  s32 i;

  for (i = 0; i < 17; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

// スコアを4桁に分解して、その参加者の行のスプライトに並べる
void FUN_081dcb8c(LinkBattleResult* p, s32 idx) {
  s32 v = p->unk_6e4[idx];
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
NON_MATCH void FUN_081dcc48(LinkBattleResult* p, s32 idx) {
#ifdef NONMATCHING_C
  s32 score = p->unk_856 * p->unk_856 >> 2;

  gRandTableIdx2 = (gRandTableIdx2 + 1) & 0x3FF;
  score += (gRandomTable2[gRandTableIdx2] & 7) * 10;
  gRandTableIdx2 = (gRandTableIdx2 + 1) & 0x3FF;
  score += (gRandomTable2[gRandTableIdx2] & 7) * 100;
  gRandTableIdx2 = (gRandTableIdx2 + 1) & 0x3FF;
  score += (gRandomTable2[gRandTableIdx2] & 7) * 1000;
  if (score > 9999) {
    score = 9999;
  }
  p->unk_6e4[idx] = score;
  FUN_081dcb8c(p, idx);
#else
  INCFUNC("asm/func/FUN_081dcc48.inc");
#endif
}

// 1フレームおきに効果音を鳴らしつつ、参加者ごとのスロットを更新する
void FUN_081dccec(LinkBattleResult* p) {
  s32 i;

  if (Mod(p->unk_856, 2) == 0) {
    PlaySound_082406e0(0x2A5);
  }
  for (i = 0; i < p->playerCount; i++) {
    if (p->unk_6ec[i] != 0) {
      FUN_081dcc48(p, i);
    }
  }
}

// パレットを3面ぶん初期化し、自分のスロットだけ白にする
NON_MATCH void FUN_081dcd50(LinkBattleResult* p) {
#ifdef NONMATCHING_C
  rgb555* slot;
  s32 playerIdx;

  CpuCopy16(&p->bgPltt[32], p->plttCur, 32);
  CpuCopy16(&p->bgPltt[32], p->plttA, 32);
  CpuCopy16(&p->bgPltt[32], p->plttB, 32);
  p->unk_704 = 0;
  p->fadeTarget = 0;
  p->unk_82a = 0;
  playerIdx = Entity9A9F_GetPlayerIdx();
  switch (playerIdx) {
    case 0: {
      slot = &p->plttB[8];
      break;
    }
    case 1: {
      slot = &p->plttB[10];
      break;
    }
    case 2: {
      slot = &p->plttB[12];
      break;
    }
    case 3: {
      slot = &p->plttB[14];
      break;
    }
    default: {
      slot = &p->plttB[8];
      break;
    }
  }
  *slot = 0x7FFF;
  CpuCopy16(p->plttCur, &gBgPlttBuffer[32], 32);
#else
  INCFUNC("asm/func/FUN_081dcd50.inc");
#endif
}

NAKED void FUN_081dce14(LinkBattleResult* p, s32 steps) { INCFUNC("asm/func/FUN_081dce14.inc"); }

NAKED s32 FUN_081dcf34(LinkBattleResult* p) { INCFUNC("asm/func/FUN_081dcf34.inc"); }

// i 番目と j 番目の並びを入れ替える
NON_MATCH void FUN_081dd074(LinkBattleResult* p, s32 i, s32 j) {
#ifdef NONMATCHING_C
  u16 tmp = p->unk_6f4[i];
  u8 tmp2 = p->unk_6fc[i];

  p->unk_6f4[i] = p->unk_6f4[j];
  p->unk_6fc[i] = p->unk_6fc[j];
  p->unk_6f4[j] = tmp;
  p->unk_6fc[j] = tmp2;
#else
  INCFUNC("asm/func/FUN_081dd074.inc");
#endif
}

// スコアの降順になるまで隣同士を入れ替える
void FUN_081dd0b8(LinkBattleResult* p) {
  s32 i;
  s32 j;

  for (i = 0; i < p->playerCount; i++) {
    for (j = 0; j < p->playerCount - 1; j++) {
      if (p->unk_6f4[j] < p->unk_6f4[j + 1]) {
        FUN_081dd074(p, j, j + 1);
      }
    }
  }
}

NAKED void FUN_081dd124(LinkBattleResult* p) { INCFUNC("asm/func/FUN_081dd124.inc"); }

// 参加者ごとの待ち時間が切れたら、その枠を開いて効果音を鳴らす
void FUN_081dd1d8(LinkBattleResult* p) {
  s32 i;

  for (i = 0; i < p->playerCount; i++) {
    if (p->unk_6ec[i] != 0) {
      if (--p->unk_6ec[i] == 0) {
        p->unk_6e4[i] = p->unk_6f4[i];
        FUN_081dcb8c(p, i);
        FUN_081dc8c0(p, i);
        FUN_081dc818(p, i);
        PlaySound_082406e0(0x167);
        p->unk_858++;
      }
    }
  }
}

// 自分の枠がまだ開いていなければ通信参加の回数を1つ増やす
void FUN_081dd25c(LinkBattleResult* p) {
  s32 playerIdx = Entity9A9F_GetPlayerIdx();
  s32 i;

  for (i = 0; i < p->playerCount; i++) {
    if (p->unk_6fc[i] == playerIdx) {
      if (p->unk_700[i] == 0) {
        s32 count = gStat->unk_916 + 1;
        if (count > 9999) {
          count = 9999;
        }
        gStat->unk_916 = count;
      }
      return;
    }
  }
}

// 参加者のスコアを取り込み、並び順を初期化して整列させる
NON_MATCH void FUN_081dd2dc(LinkBattleResult* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < p->playerCount; i++) {
    if (gEntity9A9F == NULL) {
      p->unk_6f4[i] = 0;
    } else {
      p->unk_6f4[i] = gEntity9A9F->unk_130[i];
    }
  }
  p->unk_6fc[0] = 0;
  p->unk_6fc[1] = 1;
  p->unk_6fc[2] = 2;
  p->unk_6fc[3] = 3;
  FUN_081dd0b8(p);
  FUN_081dd124(p);
  FUN_081dd25c(p);
#else
  INCFUNC("asm/func/FUN_081dd2dc.inc");
#endif
}

// 自分のスロットがまだ未確定なら効果音を鳴らす
NON_MATCH void FUN_081dd36c(LinkBattleResult* p) {
#ifdef NONMATCHING_C
  Entity9A9F* mgr = gEntity9A9F;
  s32 playerIdx;
  s8 count;
  s32 i;

  if (mgr == NULL) {
    return;
  }
  playerIdx = mgr->playerIdx;
  if (playerIdx < 0) {
    return;
  }
  count = p->playerCount;
  for (i = 0; i < count; i++) {
    if (p->unk_6fc[i] == playerIdx && p->unk_700[i] == 0) {
      sound_08240264(0xA9);
      return;
    }
  }
#else
  INCFUNC("asm/func/FUN_081dd36c.inc");
#endif
}

// 開いた直後に効果音を鳴らし、10フレーム後に案内メッセージへ差し替える
void FUN_081dd3c8(LinkBattleResult* p) {
  s32 state;

  if (p->unk_855 != 0) {
    FUN_081df8f0(1);
    p->unk_856 = 0;
    p->unk_855 = 0;
  }
  if (p->unk_856 <= 9) {
    p->unk_856++;
  } else if (p->unk_856 == 10) {
    TextPanel_SetMessage(p->panelID[0], 5);
    p->unk_856++;
  }
  state = FUN_081dfa04();
  if (state == 0x11 || state == 0x14) {
    FUN_081dcb54(p);
    KillEntity((Entity*)p);
  }
}

NAKED void FUN_081dd434(LinkBattleResult* p) { INCFUNC("asm/func/FUN_081dd434.inc"); }

// 結果を出し終えたら A / START で次の画面へ進む
void FUN_081dd628(LinkBattleResult* p) {
  if (p->unk_855 != 0) {
    FUN_081dd36c(p);
    p->unk_856 = 0;
    p->unk_855 = 0;
  }
  FUN_081dcf34(p);
  if (p->unk_856 <= 9) {
    p->unk_856++;
  } else if (gInput[0].pressed & (A_BUTTON | START_BUTTON)) {
    PlaySound_082406e0(0xDD);
    EntityB85F_SetState(p, FUN_081dd434, 3);
  }
}

// 結果表示中, ボタンが押されたら残り時間を詰め、全員出そろったら次の状態へ
void FUN_081dd6ac(LinkBattleResult* p) {
  s32 i;

  if (p->unk_855 != 0) {
    p->unk_856 = 0;
    p->unk_855 = 0;
  }
  if (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON)) {
    for (i = 0; i < p->playerCount; i++) {
      if (p->unk_6ec[i] > 1) {
        p->unk_6ec[i] = 1;
      }
    }
  }
  FUN_081dccec(p);
  FUN_081dd1d8(p);
  if (p->unk_858 >= p->playerCount) {
    EntityB85F_SetState(p, FUN_081dd628, 2);
  } else {
    p->unk_856++;
  }
}

// 集計の演出中, ボタンで飛ばすか、64フレーム経ったら結果表示へ
void FUN_081dd774(LinkBattleResult* p) {
  s32 i;

  if (p->unk_855 != 0) {
    p->unk_856 = 0;
    p->unk_855 = 0;
  }
  if (p->unk_856 > 10 && (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON))) {
    for (i = 0; i < p->playerCount; i++) {
      p->unk_6ec[i] = 1;
    }
    EntityB85F_SetState(p, FUN_081dd6ac, 1);
  } else if (p->unk_856 > 64) {
    EntityB85F_SetState(p, FUN_081dd6ac, 1);
  } else {
    FUN_081dccec(p);
    p->unk_856++;
  }
}

s32 EntityB85F_Update(LinkBattleResult* p) {
  if (!FUN_081dfa04()) {
    KillEntity((Entity*)p);
    return -1;
  }
  if (p->fn != NULL) {
    p->fn(p);
  }
  return 1;
}

s32 EntityB85F_Destroy(LinkBattleResult* p) {
  FUN_081dc880(p);
  FUN_081dcb70(p);
  return 1;
}

NAKED s32 EntityB85F_Init(LinkBattleResult* p) { INCFUNC("asm/func/EntityB85F_Init.inc"); }

LinkBattleResult* EntityB85F_Create(void) {
  LinkBattleResult* p = CreateEntity(ENTITY_UNK_11, sizeof(LinkBattleResult));

  if (p != NULL) {
    SetEntityRoutine(p, EntityB85F_Update, EntityB85F_Destroy);
    if (EntityB85F_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
