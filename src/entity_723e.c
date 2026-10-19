#include "entity.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"

// 通信対戦の結果画面, 2人のタイムと得点を出す
typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_11
  u32 timer;                  // 0x018, state が変わると 0 に戻り毎フレーム +1
  u8 state;                   // 0x01C, PTR_ARRAY_085ab724 の添字
  bool8 stateEntered;         // 0x01D, state を変えた直後だけ立つ
  u8 timeA[3];                // 0x01E, 秒数を時/分/100分の1秒に分けたもの
  u8 timeB[3];                // 0x021, もう1人のぶん
  u8 unk_24;                  // 0x024, Entity723E_Setup の第2引数
  u8 step;                    // 0x025, remain から total へ1フレームに移す量, 2 が入る
  u8 unk_26[2];               // 0x026, [0] に Entity723E_Setup の第1引数が入る
  s16 remain;                 // 0x028, total へ step ずつ移していく残り
  s16 total;                  // 0x02A, 移ってくる累計, 9999 で止まる
  TilemapFile* tilemap;       // 0x02C
  MainSpriteGfx gfx;          // 0x030, SPRITE_UI_LINK
  MainSpriteGfx portraitGfx;  // 0x050, SPRITE_PORTRAITS
  MainSprite sprites[21];     // 0x070
  MainSprite portrait;        // 0x850
  u32 unk_8b0;                // 0x8B0, Entity723E_Setup の第7引数
  u8* script;                 // 0x8B4, '.s'
  s32 textPanels[4];          // 0x8B8, TextPanel_Destroy に渡すID
  u8 unk_8c8[16];             // 0x8C8, FUN_0804f814(0) の 16 バイトの写し
  u8 unk_8d8[16];             // 0x8D8, FUN_0804f814(1) の 16 バイトの写し
} Entity723E;
static_assert(sizeof(Entity723E) == 2280);

IWRAM_DATA Entity723E* gEntity723E = NULL;  // 0x0300011C

void FUN_08052338(Entity723E*);
void FUN_0805234c(Entity723E*);
void FUN_080525d0(Entity723E*);
void FUN_080526d8(Entity723E*);
void FUN_08052798(Entity723E*);
void FUN_080528c4(Entity723E*);

bool32 FUN_0804e59c(void);

void (*const PTR_ARRAY_085ab724[6])(Entity723E*) = {
    FUN_08052338,
    FUN_0805234c,
    FUN_080525d0,
    FUN_080526d8,
    FUN_08052798,
    FUN_080528c4,
};  // 0x085AB724

// state を差し替えて MainSprite 4つ分の flags に bit0 を立てる
// ただし先頭は p+0x40 なので gfx の末尾と sprites[0..2] の途中を踏んでおり, 原典の書き間違いとみられる
s32 Entity723E_SetState(Entity723E* p, u8 state) {
  MainSprite* spr;
  s32 i;

  p->state = state;
  p->stateEntered = TRUE;
  p->timer = 0;
  p->timeA[0] = 0;

  spr = (MainSprite*)&p->gfx.anims;
  for (i = 0; i < 4; i++, spr++) {
    spr->flags |= SPRFLAG_HIDDEN;
  }
  return 0;
}

bool32 Entity723E_ConsumeStateEntered(Entity723E* p) {
  p->timeA[0] = 1;
  return FALSE;
}

Entity723E* GetEntity723E(void) { return gEntity723E; }

NAKED void FUN_080522d0(Entity723E* p) { INCFUNC("asm/func/FUN_080522d0.inc"); }

// 入場フラグを食うだけ
void FUN_08052338(Entity723E* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
  }
}

NAKED void FUN_0805234c(Entity723E* p) { INCFUNC("asm/func/FUN_0805234c.inc"); }

NAKED void FUN_080525d0(Entity723E* p) { INCFUNC("asm/func/FUN_080525d0.inc"); }

NAKED void FUN_080526d8(Entity723E* p) { INCFUNC("asm/func/FUN_080526d8.inc"); }

NAKED void FUN_08052798(Entity723E* p) { INCFUNC("asm/func/FUN_08052798.inc"); }

// 30フレーム経ったあと何かボタンが押されたら後始末して自分を消す
void FUN_080528c4(Entity723E* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
  }

  if (p->timer > 29 && (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON))) {
    Sound_FadeOutBGMTemporarily(4);
    PlaySound_082406e0(SE_SELECT);
    if (p->unk_8b0 != 0) {
      ((void (*)(void))p->unk_8b0)();
    }
    KillEntity((Entity*)p);
  } else {
    p->timer++;
  }
}

s32 Entity723E_Update(Entity723E* p) {
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
  gEntity723E = NULL;
  return 0;
}

NAKED s32 Entity723E_Init(Entity723E* p) { INCFUNC("asm/func/Entity723E_Init.inc"); }

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

NAKED s32 Entity723E_Setup(u8 param_1, u8 param_2, s32 param_3, s32 param_4, s16 param_5, s16 param_6, u32 param_7) { INCFUNC("asm/func/Entity723E_Setup.inc"); }
