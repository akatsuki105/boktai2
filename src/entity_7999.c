#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// 通信対戦関連?
typedef struct Entity7999 {
  Entity e;                                    // 0x000, ENTITY_UNK_11
  Tilemaps* tilemap;                           // 0x018, TILEMAP_CD91
  rgb555* bgp;                                 // 0x01C, bg_link_col_arr
  MainSprite sprites[5];                       // 0x020, FUN_081da468 が stride 0x60 で pos を書き換える5枚
  MainSpriteGfx gfxLink;                       // 0x200, SPRITE_UI_LINK
  MainSpriteGfx gfxIcon;                       // 0x220, SPRITE_INVENTORY_ICONS
  MainSpriteGfxFile* fileLink;                 // 0x240, SPRITE_UI_LINK
  MainSpriteGfxFile* fileIcon;                 // 0x244, SPRITE_INVENTORY_ICONS
  rgb555 savedPltt[16];                        // 0x248, _SavePltt が gObjPlttData + 0x2930 から16色コピーする
  u16 unk_268;                                 // 0x268, _SavePltt が 0 を入れる
  u8 unk_26a[2];                               // 0x26A, 読み手も書き手も見つかっていない, padding?
  void (*updateCallback)(struct Entity7999*);  // 0x26C, _Init で FUN_081da930
  u8* script;                                  // 0x270, '.s' の後の VM_GetPC_Proxy() の戻り値, NULL なら _Init が失敗する
  u32 flags;                                   // 0x274, _InitPanels が bit0 を立てる
  s32 windowID0;                               // 0x278, TextPanel_Create(18, 4, 10, 2)
  s32 windowID1;                               // 0x27C, TextPanel_Create(18, 8, 10, 2)
  s32 windowID2;                               // 0x280, TextPanel_Create(16, 12, 12, 2)
  u8 unk_284;                                  // 0x284, _Init が 0 を入れる
  u8 unk_285;                                  // 0x285, 読み手も書き手も見つかっていない
  u8 unk_286;                                  // 0x286, gEntity9A9F->unk_15c + 0x40 の写し, 0/1/2 で分岐する種別
  u8 unk_287;                                  // 0x287, 同 +0x41 の写し
  u8 unk_288;                                  // 0x288, 同 +0x42 の写し
  u8 unk_289[2];                               // 0x289, まだ未解析
  u8 unk_28b;                                  // 0x28B, 種別ごとに magicCount / 2 / 1 のどれかが入る
  u16 magicCount;                              // 0x28C, magicIDs に詰めた数
  u8 unk_28e[0x290 - 0x28E];                   // 0x28E, まだ未解析
  u8 magicIDs[0x298 - 0x290];                  // 0x290, 解放済みの魔法ID, u32_ARRAY_085ae144 から詰める
  u8 unk_298;                                  // 0x298, _Init が -1 を入れる
  u8 unk_299;                                  // 0x299, _Init が -1 を入れる
  u8 unk_29a;                                  // 0x29A, _Init が -1 を入れる
  u8 unk_29b;                                  // 0x29B, _Init が 0xFF を入れる
  u8 unk_29c;                                  // 0x29C, _Init が 1 を入れる
  u8 unk_29d;                                  // 0x29D, FUN_081da468 が添字として読む
  u16 state_29e;                               // 0x29E, FUN_081da890 が毎フレーム +1 し, 10 で終了処理へ入る
  u16 unk_2a0;                                 // 0x2A0, _Init が '.l' を入れる
  u16 unk_2a2;                                 // 0x2A2, _Init が '.e' を入れる
} Entity7999;

bool32 IsMagicUnlocked(magic32_t n);
void FUN_081df974(void);
bool32 FUN_081dfa04(void);

void Entity7999_HidePanels(Entity7999* p);
void Entity7999_HideSprites(Entity7999* p);
static_assert(sizeof(Entity7999) == 676);

const u32 u32_ARRAY_085ae144[7] = {0, 2, 3, 4, 5, 11, 13};  // 0x085AE144

// FUN_081d9da4 / FUN_081d9e50 / FUN_081da14c が引く
const u32 u32_ARRAY_085ae160[3] = {1, 16, 8};  // 0x085AE160

// FUN_081d9e50 / FUN_081da468 が引く
const s32 s32_ARRAY_085ae16c[3][6] = {
    {0, 0, 0, 32, 0,   64},
    {0, 0, 0, 32, -16, 64},
    {0, 0, 0, 32, 0,   64},
};  // 0x085AE16C

NAKED s32 FUN_081d9da4(unknown* param_1) { INCFUNC("asm/func/FUN_081d9da4.inc"); }

NAKED void FUN_081d9e50(unknown* param_1) { INCFUNC("asm/func/FUN_081d9e50.inc"); }

void FUN_081d9ef4(Entity7999* p) {
  Entity7999_HidePanels(p);
  ClearBGTilemapBuffer(0);
  ClearBGTilemapBuffer(1);
  ClearBGTilemapBuffer(2);
  ClearBGTilemapBuffer(3);
  Marquee_Clear();
  Entity7999_HideSprites(p);
  if (p->unk_2a0 != 0) {
    VM_ExecByID(p->unk_2a0, 0);
    KillEntity((Entity*)p);
  }
}

void FUN_081d9f3c(Entity7999* p) {
  Marquee_CloseGlobal();
  Entity7999_HidePanels(p);
  ClearBGTilemapBuffer(0);
  ClearBGTilemapBuffer(1);
  ClearBGTilemapBuffer(2);
  ClearBGTilemapBuffer(3);
  Entity7999_HideSprites(p);
  FUN_081df974();
  if (p->unk_2a2 != 0) {
    VM_ExecByID(p->unk_2a2, NULL);
    KillEntity((Entity*)p);
  }
}

NAKED void Entity7999_InitBG(Entity7999* p) { INCFUNC("asm/func/Entity7999_InitBG.inc"); }

// 解放済みの魔法だけを magicIDs に詰め直す
void FUN_081da038(Entity7999* p) {
  s32 count = 0;
  const u32* id = u32_ARRAY_085ae144;
  s32 i;

  for (i = 0; i < 7; id++, i++) {
    if (IsMagicUnlocked(*id)) {
      p->magicIDs[count] = *id;
      count++;
    }
  }
  p->magicCount = count;
}

// 種別ごとに unk_28b を決める
void FUN_081da074(Entity7999* p) {
  switch (p->unk_286) {
    case 0: {
      p->unk_28b = p->magicCount;
      break;
    }
    case 1: {
      p->unk_28b = 2;
      break;
    }
    case 2: {
      p->unk_28b = 1;
      break;
    }
  }
}

NAKED void FUN_081da0c4(unknown* param_1) { INCFUNC("asm/func/FUN_081da0c4.inc"); }

NAKED void FUN_081da14c(unknown* param_1) { INCFUNC("asm/func/FUN_081da14c.inc"); }

NAKED void FUN_081da218(unknown* param_1) { INCFUNC("asm/func/FUN_081da218.inc"); }

NAKED void Entity7999_InitPanels(Entity7999* p) { INCFUNC("asm/func/Entity7999_InitPanels.inc"); }

void Entity7999_HidePanels(Entity7999* p) {
  TextPanel_Hide(p->windowID0);
  TextPanel_Hide(p->windowID1);
  TextPanel_Hide(p->windowID2);
}

NAKED void Entity7999_InitSprites(Entity7999* p) { INCFUNC("asm/func/Entity7999_InitSprites.inc"); }

NAKED void FUN_081da468(unknown* param_1) { INCFUNC("asm/func/FUN_081da468.inc"); }

void Entity7999_HideSprites(Entity7999* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

void Entity7999_RemoveSprites(Entity7999* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

void Entity7999_SavePltt(Entity7999* p) {
  rgb555* src = &gObjPlttData[0x2930];
  s32 i;

  for (i = 0; i < 16; i++) {
    p->savedPltt[i] = src[i];
  }
  p->sprites[0].pltt = p->savedPltt;
  p->unk_268 = 0;
}

NAKED void FUN_081da64c(unknown* param_1) { INCFUNC("asm/func/FUN_081da64c.inc"); }

NAKED void FUN_081da69c(unknown* param_1) { INCFUNC("asm/func/FUN_081da69c.inc"); }

NAKED void FUN_081da730(unknown* param_1) { INCFUNC("asm/func/FUN_081da730.inc"); }

NAKED void FUN_081da814(unknown* param_1) { INCFUNC("asm/func/FUN_081da814.inc"); }

void FUN_081da890(Entity7999* p) {
  if (p->unk_29c != 0) {
    p->state_29e = 0;
    p->unk_29c = 0;
  }

  if (p->state_29e == 10) {
    FUN_081d9da4(p);
    FUN_081d9ef4(p);
  }
  p->state_29e++;
}

NAKED void FUN_081da8d4(unknown* param_1) { INCFUNC("asm/func/FUN_081da8d4.inc"); }

NAKED void FUN_081da930(unknown* param_1) { INCFUNC("asm/func/FUN_081da930.inc"); }

s32 Entity7999_Update(Entity7999* p) {
  if (!FUN_081dfa04()) {
    Marquee_CloseGlobal();
    Entity7999_HideSprites(p);
    KillEntity((Entity*)p);
    return -1;
  }

  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  return 1;
}

s32 Entity7999_Destroy(Entity7999* p) {
  Entity7999_RemoveSprites(p);
  Entity7999_HidePanels(p);
  return 1;
}

NAKED s32 Entity7999_Init(Entity7999* p) { INCFUNC("asm/func/Entity7999_Init.inc"); }

Entity7999* Entity7999_Create(void) {
  Entity7999* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity7999));

  if (p != NULL) {
    SetEntityRoutine(p, Entity7999_Update, Entity7999_Destroy);
    if (Entity7999_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
