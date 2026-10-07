#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "sprite.h"
#include "tilemap.h"
#include "time.h"
#include "video.h"
#include "vm.h"

typedef u32 IntroFlags;
#define INTRO_FLAG_UNK_0 (1 << 0)    // 0x1, stateTimer を止める
#define INTRO_FLAG_UNK_1 (1 << 1)    // 0x2, timer_68 を止める
#define INTRO_FLAG_UNK_28 (1 << 28)  // 0x10000000, '.D' が 0 以外のとき立つ

// ゲーム起動時からタイトル画面でモード(GAMESTART, OPTION, LINK のどれか)を選択するまでの処理を行う
// モード(GAMESTART, OPTION, LINK のどれか) からBボタンに戻ると、またこのEntityが生成される
typedef struct Intro {
  Entity e;                               // 0x000, ENTITY_UNK_11
  MainSpriteGfx gfx;                      // 0x018, SPRITE_D353
  Tilemaps* tilemap;                      // 0x038, FileID は state ごとに違う
  rgb555* bgp;                            // 0x03C, FileID は state ごとに違う
  s32 unk_40;                             // 0x040, '.Y', 1 か 2 のとき初期状態が 3 になる
  IntroFlags flags;                       // 0x044
  s32 unk_48;                             // 0x048, '.g'
  s32 unk_4c;                             // 0x04C, '.o'
  s32 unk_50;                             // 0x050, '.l'
  s32 unk_54;                             // 0x054, '.s'
  s32 unk_58;                             // 0x058, '.d'
  s32 state;                              // 0x05C, sIntroUpdates[state]
  s32 stateTimer;                         // 0x060, 状態遷移で 0 に戻り, flags bit0 が落ちている間 Intro_Update が +1 する
  s32 unk_64;                             // 0x064, Intro_SetState が 0 にするだけ, 読み手は未発見
  s32 timer_68;                           // 0x068, 状態遷移で 0 に戻り, flags bit1 が落ちている間 Intro_Update が +1 する
  s32 unk_6c;                             // 0x06C, Intro_Init が -1 を入れる
  u16 unk_70[4][3];                       // 0x070, state で引く3値, 行は順に '.k' '.j' '.w' '.t'
  s32 unk_88;                             // 0x088, FUN_0821b21c に s32* として渡す
  s32 unk_8c;                             // 0x08C, unk_70[state][2] * gBgBrightness / 64
  s16 unk_90;                             // 0x090, '.K[0]'
  s16 unk_92;                             // 0x092, '.K[1]'
  MainSprite spr_94;                      // 0x094, ここから spr_334 まで配列かも?
  MainSprite spr_f4;                      // 0x0F4
  MainSprite spr_154;                     // 0x154
  MainSprite spr_1b4;                     // 0x1B4
  MainSprite spr_214;                     // 0x214
  MainSprite spr_274;                     // 0x274
  MainSprite spr_2d4;                     // 0x2D4
  MainSprite spr_334;                     // 0x334
  rgb555 obp[32];                         // 0x394, spr_f4.pltt をここへ向け替えて使う
  rgb555 savedObp[32];                    // 0x3D4, obp の元の内容
  u8 unk_414;                             // 0x414, 1..5 を巡回し Video_SetBGLayer の layerIdx になる
  u8 unk_415;                             // 0x415, gStat->sunGauge から決まる (0 で 14, 10 で 4)
  u8 unk_416[6];                          // 0x416
  s8 unk_41c;                             // 0x41C, gStat->unk_93c の下位バイト
  u8 unk_41d;                             // 0x41D, gSystemSaveData->unk_09 が 0 なら 3, それ以外は 4
  u8 unk_41e[2];                          // 0x41E
  u16 unk_420;                            // 0x420
  u16 unk_422;                            // 0x422
  u8 unk_424[4];                          // 0x424
  void (*updateCallback)(struct Intro*);  // 0x428
} Intro;
static_assert(sizeof(Intro) == 1068);

extern const u8 u8_ARRAY_08252778[8];

bool32 FUN_0821b21c(s32* p, s32 val1, s32 val2, u16 val3);
void FUN_0823d4ac(void);
void Intro_SetState(Intro* p, s32 state);

static inline void Intro_SetFlags(Intro* p, IntroFlags bits) { p->flags |= bits; }
static inline IntroFlags Intro_TestFlags(Intro* p, IntroFlags bits) { return p->flags & bits; }

void FUN_08211f20(Intro* p) {
  s32 idx;
  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_32A2);
  idx = 0;
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, &idx);
  SetBGPrioDirect(2, 2);
}

void FUN_08211f64(Intro* p) {
  p->bgp = GetBgPlttFile(BGP_D8C3)->body;
  CpuCopy32(p->bgp, gBgPlttBuffer, 48 * sizeof(rgb555));
}

NAKED void Intro_UpdateState0(Intro* p) { INCFUNC("asm/func/Intro_UpdateState0.inc"); }

NAKED void Intro_UpdateState1(Intro* p) { INCFUNC("asm/func/Intro_UpdateState1.inc"); }

// 残差14命令: 原典は関数の先頭で p + 0x88 を r8 に置き、case 2 の unk_8c への store だけにそれを使う (FUN_0821b21c の引数は毎回 p + 0x88 を作り直す) ため、r7/r8 の退避が増える
// さらに case 0 と case 1 の先頭に flags & INTRO_FLAG_UNK_1 を計算して捨てる ands が1つずつ入っている (使っているのは case 2 だけ)。Tier A-C 試済
NON_MATCH void Intro_UpdateState2(Intro* p) {
#ifdef NONMATCHING_C
  bool32 redraw = (p->flags & INTRO_FLAG_UNK_0) != 0;
  bool32 fade;

  p->flags &= ~INTRO_FLAG_UNK_0;
  if (redraw) {
    ClearBGTilemapBuffer(0);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    ClearBGTilemapBuffer(2);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    ClearBGTilemapBuffer(3);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    Video_SetBGLayer(2, p->tilemap, 2);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    p->unk_6c = 2;
  }

  if ((gInput[0].pressed & A_BUTTON) && p->unk_64 < 2) {
    p->unk_64 = 2;
    p->timer_68 = 0;
    Intro_SetFlags(p, INTRO_FLAG_UNK_1);
  }

  switch (p->unk_64) {
    case 0: {
      p->flags &= ~INTRO_FLAG_UNK_1;
      if (FUN_0821b21c(&p->unk_88, 0, p->unk_70[p->state][0], 7)) {
        p->unk_64 = 1;
        p->timer_68 = 0;
        Intro_SetFlags(p, INTRO_FLAG_UNK_1);
      }
      break;
    }
    case 1: {
      p->flags &= ~INTRO_FLAG_UNK_1;
      if (p->timer_68 >= p->unk_70[p->state][1]) {
        p->unk_64 = 2;
        p->timer_68 = 0;
        Intro_SetFlags(p, INTRO_FLAG_UNK_1);
      }
      break;
    }
    case 2: {
      fade = (p->flags & INTRO_FLAG_UNK_1) != 0;
      p->flags &= ~INTRO_FLAG_UNK_1;
      if (fade) {
        p->unk_8c = Div(p->unk_70[p->state][2] * gBgBrightness, 64);
      }
      if (FUN_0821b21c(&p->unk_88, 1, p->unk_70[p->state][p->unk_64], 7)) {
        Intro_SetState(p, 3);
        FUN_0823d4ac();
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/Intro_UpdateState2.inc");
#endif
}

// 夜なら 1, 日中なら 0, Time_GetSpanOfTime が範囲外を返したら -1
static s32 IsNight(void) {
  switch (Time_GetSpanOfTime()) {
    case TIME_MORNING:
    case TIME_DAYTIME:
    case TIME_SUNSET: {
      return 0;
    }
    case TIME_NIGHT:
    case TIME_UNK4:
    case TIME_UNK5: {
      return 1;
    }
  }
  return -1;
}

static s32 GetCurrentMonth(void) {
  s32 year, month, day;

  Time_ParseBCDDate(&year, &month, &day, (BCDDate)Time_GetDate());
  return month;
}

void FUN_08212510(Intro* p) {
  s32 idx;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_C423);
  idx = 0;
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, &idx);
  SetBGPrioDirect(2, 2);

  idx = 1;
  Video_SetupBGLayout(2, 0, p->tilemap, 0, 0, 1, &idx);
  SetBGPrioDirect(3, 3);
}

void FUN_08212570(Intro* p) {
  p->bgp = GetBgPlttFile(BGP_F0DC)->body;
  CpuCopy32(p->bgp, gBgPlttBuffer, 144 * sizeof(rgb555));
}

NAKED void Intro_SetupSprites(Intro* p) { INCFUNC("asm/func/Intro_SetupSprites.inc"); }

static void Intro_DestroyInternal(Intro* p) {
  MainSprite_Remove(&p->spr_94);
  MainSprite_Remove(&p->spr_f4);
  MainSprite_Remove(&p->spr_154);
  MainSprite_Remove(&p->spr_1b4);
  MainSprite_Remove(&p->spr_214);
  MainSprite_Remove(&p->spr_274);
  MainSprite_Remove(&p->spr_2d4);
  MainSprite_Remove(&p->spr_334);
}

// 残差3命令: 原典は関数の先頭で p + 0x94 を作り、末尾の unk_415 への strb をそこから +0x381 で組む。こちらは p をそのまま base にするので p + 0x94 が現れない。Tier A-C 試済
NON_MATCH void FUN_082127e4(Intro* p) {
#ifdef NONMATCHING_C
  s32 val;

  p->unk_414++;
  if (p->unk_414 > 5) {
    p->unk_414 = 1;
  }
  Video_SetBGLayer(3, p->tilemap, p->unk_414);
  Video_GenerateBGMap(3, 0, 0, 0, 0);

  switch (gStat->sunGauge) {
    case 0: {
      val = 14;
      break;
    }
    case 1: {
      val = 13;
      break;
    }
    case 2: {
      val = 12;
      break;
    }
    case 3: {
      val = 11;
      break;
    }
    case 4: {
      val = 10;
      break;
    }
    case 5: {
      val = 9;
      break;
    }
    case 7: {
      val = 7;
      break;
    }
    case 8: {
      val = 6;
      break;
    }
    case 9: {
      val = 5;
      break;
    }
    case 10: {
      val = 4;
      break;
    }
    default: {
      val = 8;
      break;
    }
  }
  p->unk_415 = val;
#else
  INCFUNC("asm/func/FUN_082127e4.inc");
#endif
}

void FUN_082128b0(Intro* p) { MainSprite_SetPose(&p->spr_f4, &p->gfx, p->unk_41c + 11, 1); }

void FUN_082128d8(Intro* p) {
  MainSprite_Show(&p->spr_214);
  MainSprite_Show(&p->spr_274);
  p->spr_2d4.flags &= ~SPRFLAG_HIDDEN;
  p->spr_334.flags &= ~SPRFLAG_HIDDEN;
}

void FUN_08212910(Intro* p) {
  p->spr_94.flags |= SPRFLAG_HIDDEN;
  p->spr_f4.flags |= SPRFLAG_HIDDEN;
  p->spr_154.flags |= SPRFLAG_HIDDEN;
  p->spr_1b4.flags |= SPRFLAG_HIDDEN;
  p->spr_214.flags |= SPRFLAG_HIDDEN;
  p->spr_274.flags |= SPRFLAG_HIDDEN;
  p->spr_2d4.flags |= SPRFLAG_HIDDEN;
  p->spr_334.flags |= SPRFLAG_HIDDEN;

  ClearBGTilemapBuffer(0);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  ClearBGTilemapBuffer(2);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  ClearBGTilemapBuffer(3);
  Video_GenerateBGMap(3, 0, 0, 0, 0);
}

NAKED void FUN_082129b8(Intro* p) { INCFUNC("asm/func/FUN_082129b8.inc"); }

NAKED void Intro_UpdateState3(Intro* p) { INCFUNC("asm/func/Intro_UpdateState3.inc"); }

void Intro_LoadGfx(Intro* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_D353);

  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  Intro_SetupSprites(p);
}

void Intro_SetState(Intro* p, s32 state) {
  static void (*const sIntroUpdates[4])(Intro*) = {
      Intro_UpdateState0,
      Intro_UpdateState1,
      Intro_UpdateState2,
      Intro_UpdateState3,
  };  // 0x085AFA20

  p->state = state;
  p->stateTimer = 0;
  p->updateCallback = sIntroUpdates[state];
  Intro_SetFlags(p, INTRO_FLAG_UNK_0);
  p->unk_64 = 0;
  p->timer_68 = 0;
  Intro_SetFlags(p, INTRO_FLAG_UNK_1);
  gBgBrightness = 0;
  gObjBrightness = 0;
  gBgPlttFadeRowMask |= ((1 << 1) | (1 << 0));
}

s32 Intro_Update(Intro* p) {
  if (!(p->flags & INTRO_FLAG_UNK_0)) p->stateTimer++;
  if (!(p->flags & INTRO_FLAG_UNK_1)) p->timer_68++;
  p->updateCallback(p);
  return 0;
}

s32 Intro_Destroy(Intro* p) {
  Intro_DestroyInternal(p);
  return 0;
}

s32 Intro_Init(Intro* p) {
  s32 d;

  if (VM_SeekToNamedArg('Y')) {
    p->unk_40 = VM_GetValue();
  }
  d = VM_GetNamedArgValue('D', 0);
  if (VM_SeekToNamedArg('K')) {
    p->unk_90 = VM_GetValue();
    p->unk_92 = VM_GetValue();
  }
  if (VM_SeekToNamedArg('k')) {
    p->unk_70[0][0] = VM_GetValue();
    p->unk_70[0][1] = VM_GetValue();
    p->unk_70[0][2] = VM_GetValue();
  }
  if (VM_SeekToNamedArg('j')) {
    p->unk_70[1][0] = VM_GetValue();
    p->unk_70[1][1] = VM_GetValue();
    p->unk_70[1][2] = VM_GetValue();
  }
  if (VM_SeekToNamedArg('w')) {
    p->unk_70[2][0] = VM_GetValue();
    p->unk_70[2][1] = VM_GetValue();
    p->unk_70[2][2] = VM_GetValue();
  }
  if (VM_SeekToNamedArg('t')) {
    p->unk_70[3][0] = VM_GetValue();
    p->unk_70[3][1] = VM_GetValue();
    p->unk_70[3][2] = VM_GetValue();
  }
  if (VM_SeekToNamedArg('g')) {
    p->unk_48 = VM_GetValue();
  }
  if (VM_SeekToNamedArg('o')) {
    p->unk_4c = VM_GetValue();
  }
  if (VM_SeekToNamedArg('l')) {
    p->unk_50 = VM_GetValue();
  }
  if (VM_SeekToNamedArg('s')) {
    p->unk_54 = VM_GetValue();
  }
  if (VM_SeekToNamedArg('d')) {
    p->unk_58 = VM_GetValue();
  }

  p->flags = (d == 0) ? 0 : INTRO_FLAG_UNK_28;
  p->state = 0;
  p->stateTimer = 0;
  p->unk_64 = 0;
  p->timer_68 = 0;
  p->unk_6c = -1;
  Intro_LoadGfx(p);

  if (p->unk_40 == 1 || p->unk_40 == 2 || Intro_TestFlags(p, INTRO_FLAG_UNK_28)) {
    Intro_SetState(p, 3);
  } else {
    Intro_SetState(p, 0);
  }
  return 0;
}

// 0xCF79
Intro* Intro_Create(void) {
  Intro* p = CreateEntity(ENTITY_UNK_11, sizeof(Intro));

  if (p != NULL) {
    SetEntityRoutine(p, Intro_Update, Intro_Destroy);
    if (Intro_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
