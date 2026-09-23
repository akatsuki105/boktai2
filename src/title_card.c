#include "entity.h"
#include "global.h"
#include "input.h"
#include "random.h"
#include "sound.h"
#include "sprite_main.h"
#include "video.h"
#include "vm.h"

void FUN_0822f0d8(void);

extern s32 s32_03004040;
extern s32 s32_0300445c;

struct TitleCard;
typedef void (*TitleCardFunc)(struct TitleCard*);

// ダンジョンやボスラッシュに入るときに出すタイトルカード。デバッグ文字列に "mini dungeon title" / "boss rush title" とある
// 文字とアイコンをスプライトで並べ、HBlank テーブルでノイズの帯をかけながら開閉する
typedef struct TitleCard {
  Entity e;                  // 0x000, ENTITY_UNK_8
  MainSpriteGfx gfx;         // 0x018, TitleCard_Init が OpenSpriteSetFile でスプライトセット 0xE89F を展開する先
  u16 state;                 // 0x038, 0 = 開くまでの待ち, 1 = 開く, 2 = 開いたまま, 3 = 閉じる
  u16 stateTimer;            // 0x03A, state 0 と 2 で毎フレーム +1。openDelay / closeDelay を超えたら次の state へ
  s32 frameCounter;          // 0x03C, TitleCard_Update が毎フレーム +1。読み手が見つかっていない
  s32 scriptOnClose;         // 0x040, VM '.e'。閉じるときに Script_ExecById へ渡す
  s16 closable;              // 0x044, VM '.C'。0 以外なら A/B で閉じられる
  s16 unk_46;                // 0x046, VM '.n'。0 なら DAT_03004040 と s32_0300445c を進行度に連動させ、パレットのフェード設定もする
  s16 progress;              // 0x048, 0..progressMax。DAT_03004040 = progress * 64 / progressMax
  s16 openDelay;             // 0x04A, unk_46 が 0 なら 0x40、そうでなければ 0。state 0 の長さ
  s16 closeDelay;            // 0x04C, VM '.d' (既定 0x80)。state 2 の長さ
  s16 progressMax;           // 0x04E, 0x40 固定
  u8* text;                  // 0x050, VM '.r' があれば FUN_0823d340() の戻り値。0 でなければ TextBox_Start に渡して文字を出す
  u16 hblank[2][160];        // 0x054, 1画面160ライン分の HBlank テーブルを2面
  u16 bufIdx;                // 0x2D4, hblank のどちらの面を使うか。毎フレーム反転する
  s16 noiseAmp;              // 0x2D6, 0..0x80。乱数に掛けてノイズの振れ幅にする
  s16 noiseAmpStep;          // 0x2D8, 開くとき -2、閉じるとき +4
  u16 lineTop;               // 0x2DA, VM '.y' の1つ目。ノイズをかける最初のスキャンライン
  u16 lineBottom;            // 0x2DC, VM '.y' の2つ目。lineTop と等しければ効果音も鳴らさない
  s8 number;                 // 0x2DE, VM '.o' (既定 -1)。0 以上なら1の位と10の位を別々のスプライトで出す
  s8 unk_2df;                // 0x2DF, VM '.t' (既定 -1)。0 以上ならその番号のスプライトを sprites[3] に出す
  s8 unk_2e0;                // 0x2E0, VM '.l' (既定 0)。0 以外なら sprites[4] のスプライト番号が 1 でなく 0x26 になる
  u8 unk_2e1[3];             // 0x2E1
  TitleCardFunc progressFn;  // 0x2E4, 毎フレーム呼ぶ。TitleCard_UpdateOpen / TitleCard_UpdateClose。終わると自分で NULL を入れる
  TitleCardFunc hblankFn;    // 0x2E8, 毎フレーム呼ぶ。TitleCard_BuildHBlankTable だけが入る
  MainSprite sprites[6];     // 0x2EC
} TitleCard;
static_assert(sizeof(TitleCard) == 1324);

// lineTop から lineBottom までのスキャンラインに乱数のノイズを入れ、それ以外は 0 に戻す
// 129 命令対 138 命令。agbcc が行頭アドレスなどを畳みすぎていて、ターゲットより短くなる
NON_MATCH void TitleCard_BuildHBlankTable(TitleCard* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 n;

  for (i = 0; i < p->lineTop; i++) {
    p->hblank[p->bufIdx][i] = 0;
  }
  for (i = p->lineTop; i < p->lineBottom; i++) {
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    n = (p->noiseAmp * gRandomTable[gRandTableIdx]) >> 18;
    p->hblank[p->bufIdx][i] = n | (n << 8);
  }
  for (i = p->lineBottom; i < DISPLAY_HEIGHT; i++) {
    p->hblank[p->bufIdx][i] = 0;
  }
  p->noiseAmp += p->noiseAmpStep;
  if (p->noiseAmp < 0) {
    p->noiseAmp = 0;
  } else if (p->noiseAmp > 0x80) {
    p->noiseAmp = 0x80;
  }
#else
  INCFUNC("asm/func/TitleCard_BuildHBlankTable.inc");
#endif
}

// 開くほうの進行。progress を上げきったら自分を外す
void TitleCard_UpdateOpen(TitleCard* p) {
  if (p->unk_46 == 0) {
    s32_03004040 = Div(p->progress << 6, p->progressMax);
  }
  p->progress++;
  if (p->progress > p->progressMax) {
    p->progress = p->progressMax;
    p->progressFn = NULL;
  }
}

// 閉じるほうの進行。progress が 0 を切ったらスクリプトを走らせて自分を消す
void TitleCard_UpdateClose(TitleCard* p) {
  if (p->unk_46 == 0) {
    s32_03004040 = Div(p->progress << 6, p->progressMax);
  }
  p->progress--;
  if (p->progress < 0) {
    p->progress = 0;
    p->progressFn = NULL;
    if (p->scriptOnClose != 0) {
      Script_ExecById(p->scriptOnClose, NULL);
    }
    KillEntity((Entity*)p);
  }
}

// 202命令対202命令。スクラッチレジスタの番号だけがずれる
NON_MATCH s32 TitleCard_Update(TitleCard* p) {
#ifdef NONMATCHING_C
  if (p->unk_46 == 0) {
    s32_0300445c = s32_03004040;
  }
  if (p->closable != 0 && (gInput[0].pressed & (A_BUTTON | B_BUTTON))) {
    MainSprite_Hide(&p->sprites[0]);
    MainSprite_Hide(&p->sprites[1]);
    MainSprite_Hide(&p->sprites[2]);
    MainSprite_Hide(&p->sprites[3]);
    MainSprite_Hide(&p->sprites[4]);
    MainSprite_Hide(&p->sprites[5]);
    if (p->unk_46 == 0) {
      s32_03004040 = 0;
      s32_0300445c = 0;
    }
    if (p->scriptOnClose != 0) {
      Script_ExecById(p->scriptOnClose, NULL);
    }
    KillEntity((Entity*)p);
    return 0;
  }
  if (p->progressFn != NULL) {
    p->progressFn(p);
  }
  if (p->hblankFn != NULL) {
    p->hblankFn(p);
    Video_SetHBlankEffect(0, 2, p->hblank[p->bufIdx]);
    p->bufIdx = 1 - p->bufIdx;
  }
  switch (p->state) {
    case 0: {
      p->stateTimer++;
      if (p->stateTimer > p->openDelay) {
        p->state = 1;
        p->stateTimer = 0;
        p->progressFn = TitleCard_UpdateOpen;
        if (p->lineTop != p->lineBottom) {
          PlaySound_082406e0(0xE1);
        }
        p->noiseAmp = 0x80;
        p->noiseAmpStep = -2;
        p->hblankFn = TitleCard_BuildHBlankTable;
      }
      break;
    }
    case 1: {
      if (p->progressFn == NULL) {
        p->state = 2;
      }
      break;
    }
    case 2: {
      p->stateTimer++;
      if (p->stateTimer > p->closeDelay) {
        p->state = 3;
        p->stateTimer = 0;
        p->progressFn = TitleCard_UpdateClose;
        if (p->lineTop != p->lineBottom) {
          PlaySound_082406e0(0xE3);
        }
        p->noiseAmp = 0;
        p->noiseAmpStep = 4;
        p->hblankFn = TitleCard_BuildHBlankTable;
      }
      break;
    }
    default: {
      break;
    }
  }
  p->frameCounter++;
  return 0;
#else
  INCFUNC("asm/func/TitleCard_Update.inc");
#endif
}

s32 TitleCard_Destroy(TitleCard* p) {
  MainSprite* spr;
  s32 i;

  FUN_0822f0d8();
  Video_ClearMosaic();
  MainSprite_Remove(&p->sprites[0]);
  MainSprite_Remove(&p->sprites[1]);
  MainSprite_Remove(&p->sprites[2]);
  MainSprite_Remove(&p->sprites[3]);
  spr = &p->sprites[4];
  for (i = 0; i < 2; i++) {
    MainSprite_Remove(spr);
    spr++;
  }
  return 0;
}

NAKED s32 TitleCard_Init(TitleCard* p) { INCFUNC("asm/func/TitleCard_Init.inc"); }

TitleCard* TitleCard_Create(void) {
  TitleCard* p = CreateEntity(ENTITY_UNK_8, sizeof(TitleCard));

  if (p != NULL) {
    SetEntityRoutine(p, TitleCard_Update, TitleCard_Destroy);
    if (TitleCard_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
