#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "random.h"
#include "save.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// クロスオーバーバトルの結果画面, 2人のタイムと得点を出す
typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_11
  u32 timer;                  // 0x018, state が変わると 0 に戻り毎フレーム +1
  u8 state;                   // 0x01C, PTR_ARRAY_085ab724 の添字
  bool8 stateEntered;         // 0x01D, state を変えた直後だけ立つ
  u8 timeA[3];                // 0x01E, 秒数を時/分/100分の1秒に分けたもの
  u8 timeB[3];                // 0x021, もう1人のぶん
  u8 result;                  // 0x024, 0 なら勝ち (BGM_WIN, crossoverWins を増やす), 1 なら負け, それ以外は引き分け?
  u8 step;                    // 0x025, remain から total へ1フレームに移す量, 2 が入る
  u8 unk_26[2];               // 0x026, [0] に Entity723E_Setup の第1引数が入る
  s16 remain;                 // 0x028, total へ step ずつ移していく残り
  s16 total;                  // 0x02A, 移ってくる累計, 9999 で止まる
  TilemapFile* tilemap;       // 0x02C
  MainSpriteGfx gfx;          // 0x030, SPRITE_UI_LINK
  MainSpriteGfx portraitGfx;  // 0x050, SPRITE_PORTRAITS
  MainSprite sprites[21];     // 0x070
  MainSprite portrait;        // 0x850
  Procedure exitCallback;     // 0x8B0, ボタンで画面を閉じるときに呼ぶ, NULL 可
  u8* script;                 // 0x8B4, '.s'
  s32 textPanels[4];          // 0x8B8, TextPanel_Destroy に渡すID
  u8 unk_8c8[16];             // 0x8C8, GetCrossoverPlayerName(0) の 16 バイトの写し
  u8 unk_8d8[16];             // 0x8D8, GetCrossoverPlayerName(1) の 16 バイトの写し
} Entity723E;
static_assert(sizeof(Entity723E) == 2280);

static Entity723E* sEntity723E;  // 0x0300011C

bool32 FUN_0804e59c(void);
s32 MainMenu_SetHudMode(s32 mode);
u8* GetCrossoverPlayerName(s32 idx);

Entity723E* GetEntity723E(void) { return sEntity723E; }

// 結果画面の BG1 と BG パレットを読み込む
void Entity723E_SetupBG(Entity723E* p, s32 bgIndex) {
  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_CD91);
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, &bgIndex);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  CpuCopy16(GetBgPlttFile(BGP_LINK)->body, gBgPlttBuffer, 256 * sizeof(rgb555));
}

// 入場フラグを食うだけ
void Entity723E_UpdateIdle(Entity723E* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
  }
}

// 2人のタイムを乱数で回してから桁ごとに順に止める
void Entity723E_UpdateRollTimes(Entity723E* p) {
  s32 a0, a1, a2, b0, b1, b2;

  if (p->stateEntered) {
    p->stateEntered = FALSE;
  }
  if (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON)) {
    p->timer = 100;
  }
  if (p->timer < 30) {
    u16* table = gRandomTable;

    a0 = Mod(_Random(table), 99);
    b0 = Mod(_Random(table), 99);
  } else {
    a0 = p->timeA[0];
    b0 = p->timeB[0];
  }
  if (p->timer < 60) {
    u16* table = gRandomTable;

    a1 = Mod(_Random(table), 60);
    b1 = Mod(_Random(table), 60);
  } else {
    a1 = p->timeA[1];
    b1 = p->timeB[1];
  }
  if (p->timer < 90) {
    u16* table = gRandomTable;

    a2 = Mod(_Random(table), 99);
    b2 = Mod(_Random(table), 99);
  } else {
    a2 = p->timeA[2];
    b2 = p->timeB[2];
  }
  if (p->timer < 90 && Mod(p->timer, 2) == 0) {
    PlaySound_082406e0(SE_COUNT_UP);
  }
  if (a0 > 99) {
    a0 = 99;
  }
  if (b0 > 99) {
    b0 = 99;
  }
  if (a1 > 59) {
    a1 = 59;
  }
  if (b1 > 59) {
    b1 = 59;
  }
  if (a2 > 99) {
    a2 = 99;
  }
  if (b2 > 99) {
    b2 = 99;
  }
  MainSprite_SetNumber(&p->sprites[1], &p->gfx, a0, 2, 0, 168, 32, 8, 0);
  MainSprite_SetNumber(&p->sprites[3], &p->gfx, a1, 2, 0, 192, 32, 8, 0);
  MainSprite_SetNumber(&p->sprites[5], &p->gfx, a2, 2, 0, 216, 32, 8, 0);
  MainSprite_SetNumber(&p->sprites[7], &p->gfx, b0, 2, 0, 168, 56, 8, 0);
  MainSprite_SetNumber(&p->sprites[9], &p->gfx, b1, 2, 0, 192, 56, 8, 0);
  MainSprite_SetNumber(&p->sprites[11], &p->gfx, b2, 2, 0, 216, 56, 8, 0);
  if (p->timer >= 100) {
    p->state = 2;
    p->stateEntered = TRUE;
    p->timer = 0;
  } else {
    p->timer++;
  }
}

// 112/118命令, 原典は gSystemSaveData を書き戻す前にポインタを読み直し, 乱数の添字も2回目は読み直さずレジスタから進める, 試済: 回数ローカルを u16 に / 三項演算子 / 乱数を先に2つ取ってから書く
NON_MATCH void Entity723E_UpdateShowResult(Entity723E* p) {
#ifdef NONMATCHING_C
  if (p->stateEntered) {
    u16 pose;
    s32 n;
    MainSprite* spr;

    p->stateEntered = FALSE;
    if (p->result == 0) {
      pose = 0x48;
    } else if (p->result == 1) {
      pose = 0x49;
    } else {
      pose = 0x4A;
    }
    n = gSystemSaveData->crossoverCount + 1;
    if (n > 9999) {
      n = 9999;
    }
    gSystemSaveData->crossoverCount = n;
    if (p->result == 0) {
      sound_08240264(BGM_WIN);
      n = gSystemSaveData->crossoverWins + 1;
      if (n > 9999) {
        n = 9999;
      }
      gSystemSaveData->crossoverWins = n;
    } else if (p->result == 1) {
      sound_08240264(BGM_LOSE);
    } else {
      sound_08240264(BGM_LOSE);
    }
    spr = &p->sprites[0];
    spr->flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(spr, &p->gfx, pose, 0);
    spr->pos.x = 0;
    spr->pos.y = 0;
  }
  if (p->timer <= 7) {
    MainSprite* spr = &p->sprites[0];
    u16* table = gRandomTable;

    spr->pos.x = (_Random(table) & 3) - 2;
    spr->pos.y = (_Random(table) & 3) - 2;
  } else if (p->timer == 8) {
    MainSprite* spr = &p->sprites[0];

    spr->pos.x = 0;
    spr->pos.y = 0;
  }
  if (p->timer >= 30) {
    p->state = 3;
    p->stateEntered = TRUE;
    p->timer = 0;
  } else {
    p->timer++;
  }
#else
  INCFUNC("asm/func/Entity723E_UpdateShowResult.inc");
#endif
}

// 残りポイントを 64 フレームかけて数え上げて見せる
void Entity723E_UpdateRevealPoints(Entity723E* p) {
  u32 n;
  MainSprite* spr;
  s32 value;

  if (p->stateEntered) {
    p->stateEntered = FALSE;
  }
  if (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON)) {
    p->timer = 128;
  }
  if (p->timer <= 64) {
    n = (u32)(p->remain * p->timer) >> 6;
    if (n > 9999) {
      n = 9999;
    }
    if (n != 0 && Mod(p->timer, 2) == 0) {
      PlaySound_082406e0(SE_COUNT_UP);
    }
  } else {
    n = p->remain;
  }
  spr = &p->sprites[13];
  value = n;
  if (value > 9999) {
    value = 9999;
  } else if (value < 0) {
    value = 0;
  }
  MainSprite_SetNumber(spr, &p->gfx, value, 4, 0, 104, 96, 8, 0);
  if (p->timer >= 128) {
    p->state = 4;
    p->stateEntered = TRUE;
    p->timer = 0;
  } else {
    p->timer++;
  }
}

// 残りポイントを step ずつ合計へ移す
void Entity723E_UpdateTransferPoints(Entity723E* p) {
  MainSprite* spr;
  s32 value;

  if (p->stateEntered) {
    p->stateEntered = FALSE;
    p->step = 2;
  }
  if (p->remain > 8 && (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON))) {
    p->step = 8;
  }
  if (p->remain >= p->step) {
    p->remain -= p->step;
    p->total += p->step;
    if (Mod(p->timer, 2) == 0) {
      PlaySound_082406e0(SE_COUNT_UP);
    }
  } else {
    p->total += p->remain;
    p->remain = 0;
  }
  if (p->total > 9999) {
    p->total = 9999;
  }
  if (p->remain < 0) {
    p->remain = 0;
  }
  spr = &p->sprites[13];
  value = p->remain;
  if (value > 9999) {
    value = 9999;
  } else if (value < 0) {
    value = 0;
  }
  MainSprite_SetNumber(spr, &p->gfx, value, 4, 0, 104, 96, 8, 0);
  spr = &p->sprites[17];
  value = p->total;
  if (value > 9999) {
    value = 9999;
  } else if (value < 0) {
    value = 0;
  }
  MainSprite_SetNumber(spr, &p->gfx, value, 4, 0, 104, 136, 8, 0);
  if (p->remain == 0) {
    p->state = 5;
    p->stateEntered = TRUE;
    p->timer = 0;
  } else {
    p->timer++;
  }
}

// 30フレーム経ったあと何かボタンが押されたら後始末して自分を消す
void Entity723E_UpdateWaitExit(Entity723E* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
  }

  if (p->timer > 29 && (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON))) {
    Sound_FadeOutBGMTemporarily(4);
    PlaySound_082406e0(SE_SELECT);
    if (p->exitCallback != NULL) {
      p->exitCallback();
    }
    KillEntity((Entity*)p);
  } else {
    p->timer++;
  }
}

s32 Entity723E_Update(Entity723E* p) {
  static void (*const PTR_ARRAY_085ab724[6])(Entity723E*) = {
      Entity723E_UpdateIdle,
      Entity723E_UpdateRollTimes,
      Entity723E_UpdateShowResult,
      Entity723E_UpdateRevealPoints,
      Entity723E_UpdateTransferPoints,
      Entity723E_UpdateWaitExit,
  };  // 0x085AB724

  if (FUN_0804e59c()) {
    s32 i;

    for (i = 0; i < 4; i++) {
      TextPanel_Destroy(p->textPanels[i]);
    }
    KillEntity((Entity*)p);
  } else {
    PTR_ARRAY_085ab724[p->state](p);
  }
  return 0;
}

s32 Entity723E_Destroy(Entity723E* p) {
  s32 i;

  MainSprite* spr = &p->sprites[0];
  for (i = 0; i < 21; i++, spr++) {
    MainSprite_Remove(spr);
  }

  spr = &p->portrait;
  MainSprite_Remove(spr);

  for (i = 0; i < 4; i++) {
    TextPanel_Destroy(p->textPanels[i]);
  }
  sEntity723E = NULL;
  return 0;
}

s32 Entity723E_Init(Entity723E* p) {
  MainSpriteGfxFile* f;
  MainSprite* spr;
  s32 i;

  sEntity723E = p;
  if (VM_SeekToNamedArg('s')) {
    p->script = VM_GetPC_Proxy();
    if (p->script == NULL) {
      return -1;
    }
  } else {
    return -1;
  }
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_LINK);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_PORTRAITS);
  if (f == NULL) {
    return -1;
  }
  p->portraitGfx = *f;
  OpenMainSpriteFile(&p->portraitGfx, f);
  spr = p->sprites;
  for (i = 0; i < 21; i++, spr++) {
    MainSprite_Add(spr, &p->gfx, 0, SPRFLAG_UNK_13 | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, 0, 60, NULL);
  }
  spr = &p->portrait;
  MainSprite_Add(spr, &p->portraitGfx, 0, SPRFLAG_UNK_13 | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, 0, 60, NULL);
  CopyMemory(p->unk_8c8, GetCrossoverPlayerName(0), sizeof(p->unk_8c8));
  CopyMemory(p->unk_8d8, GetCrossoverPlayerName(1), sizeof(p->unk_8d8));
  p->state = 0;
  p->stateEntered = TRUE;
  p->timer = 0;
  p->exitCallback = NULL;
  return 0;
}

Entity723E* Entity723E_Create(void) {
  Entity723E* p = GetEntity723E();

  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_11, sizeof(Entity723E));
  if (p != NULL) {
    SetEntityRoutine(p, Entity723E_Update, Entity723E_Destroy);
    if (Entity723E_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 結果画面に勝敗, 2人のタイム, ポイントを渡して表示を組み立てる
s32 Entity723E_Setup(u32 param_1, u32 result, s32 framesA, s32 framesB, s32 remain, s32 total, Procedure exitCallback) {
  Entity723E* p = GetEntity723E();
  MainSprite* spr;
  s32* panel;
  s32 rest;
  s32 value;

  if (p == NULL) {
    return -1;
  }
  p->unk_26[0] = param_1;
  p->result = result;
  p->exitCallback = exitCallback;
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG2_ON | DISPCNT_BG3_ON);
  MainMenu_SetHudMode(7);
  ClearBGTilemapBuffer(0);
  Entity723E_SetupBG(p, 12);
  Video_SetDrawPasses(0, Particle_DrawListUnk13, AuxSprite_DrawListUnk13, FUN_0822f264);
  p->state = 1;
  p->stateEntered = TRUE;
  p->timer = 0;

  p->timeA[0] = Div(framesA, 3600);
  rest = Mod(framesA, 3600);
  p->timeA[1] = Div(rest, 60);
  p->timeA[2] = Div(Mod(rest, 60) * 100, 60);
  p->timeB[0] = Div(framesB, 3600);
  rest = Mod(framesB, 3600);
  p->timeB[1] = Div(rest, 60);
  p->timeB[2] = Div(Mod(rest, 60) * 100, 60);

  p->remain = remain;
  p->total = total;
  if (p->remain > 9999) {
    p->remain = 9999;
  } else if (p->remain < 0) {
    p->remain = 0;
  }
  if (p->total > 9999) {
    p->total = 9999;
  } else if (p->total < 0) {
    p->total = 0;
  }

  spr = &p->sprites[1];
  MainSprite_SetNumber(spr, &p->gfx, 0, 2, 0, 168, 32, 8, 0);
  spr = &p->sprites[3];
  MainSprite_SetNumber(spr, &p->gfx, 0, 2, 0, 192, 32, 8, 0);
  spr = &p->sprites[5];
  MainSprite_SetNumber(spr, &p->gfx, 0, 2, 0, 216, 32, 8, 0);
  spr = &p->sprites[7];
  MainSprite_SetNumber(spr, &p->gfx, 0, 2, 0, 168, 56, 8, 0);
  spr = &p->sprites[9];
  MainSprite_SetNumber(spr, &p->gfx, 0, 2, 0, 192, 56, 8, 0);
  spr = &p->sprites[11];
  MainSprite_SetNumber(spr, &p->gfx, 0, 2, 0, 216, 56, 8, 0);
  spr = &p->sprites[13];
  MainSprite_SetNumber(spr, &p->gfx, 0, 4, 0, 104, 96, 8, 0);
  spr = &p->sprites[17];
  value = p->total;
  if (value > 9999) {
    value = 9999;
  } else if (value < 0) {
    value = 0;
  }
  MainSprite_SetNumber(spr, &p->gfx, value, 4, 0, 104, 136, 8, 0);

  panel = &p->textPanels[0];
  *panel = TextPanel_Create(10, 4, 10, 2);
  if (*panel < 0) {
    return -1;
  }
  TextPanel_SetScript(*panel, p->script);
  FUN_0804a40c(*panel, 0, p->unk_8c8);
  TextPanel_SetMessage(*panel, 3);
  TextPanel_Start(*panel);
  panel = &p->textPanels[1];
  *panel = TextPanel_Create(10, 7, 10, 2);
  if (*panel < 0) {
    return -1;
  }
  TextPanel_SetScript(*panel, p->script);
  FUN_0804a40c(*panel, 1, p->unk_8d8);
  TextPanel_SetMessage(*panel, 4);
  TextPanel_Start(*panel);
  panel = &p->textPanels[2];
  *panel = TextPanel_Create(1, 10, 28, 2);
  if (*panel < 0) {
    return -1;
  }
  TextPanel_SetScript(*panel, p->script);
  TextPanel_SetMessage(*panel, 11);
  TextPanel_Start(*panel);
  panel = &p->textPanels[3];
  *panel = TextPanel_Create(1, 15, 28, 2);
  if (*panel < 0) {
    return -1;
  }
  TextPanel_SetScript(*panel, p->script);
  TextPanel_SetMessage(*panel, 12);
  TextPanel_Start(*panel);

  spr = &p->portrait;
  spr->flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(spr, &p->portraitGfx, 0, 0);
  spr->pos.x = 24;
  spr->pos.y = 32;
  return 0;
}
