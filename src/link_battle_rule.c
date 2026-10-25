#include "entity.h"
#include "entity_9a9f.h"
#include "file.h"
#include "global.h"
#include "sprite_main.h"
#include "sprite_pltt.h"
#include "text.h"
#include "video.h"

// おそらく、通信対戦のルール設定
// 3行の選択肢を持つ通信メニュー, 各行は values[i] を counts[i] で巻き戻しながら左右で切り替える
typedef struct Entity08F4 {
  Entity e;                                    // 0x000, ENTITY_UNK_11
  Tilemaps* tilemap;                           // 0x018, TILEMAP_CD91
  rgb555* bgPltt;                              // 0x01C, bg_link_col_arr
  MainSprite sprites[7];                       // 0x020
  MainSpriteGfx gfx;                           // 0x2C0, SPRITE_UI_LINK
  MainSpriteGfxFile* gfxFile;                  // 0x2E0, SPRITE_UI_LINK
  rgb555 objPltt[16];                          // 0x2E4, Entity08F4_SavePltt が gObjPlttData+0x2930 から16色複写し、sprites[0].pltt をここへ向ける
  u16 unk_304;                                 // 0x304, Entity08F4_SavePltt が 0 を入れるだけ
  u16 unk_306;                                 // 0x306, 読み手も書き手も見つかっていない, padding?
  void (*updateCallback)(struct Entity08F4*);  // 0x308
  u8* scriptPc;                                // 0x30C, Init が VM_GetPC_Proxy() を入れる, VM_ParseStringRef / TextPanel_SetScript に渡す
  u32 unk_310;                                 // 0x310, FUN_081db074 が bit0 を落とし、FUN_081db57c が立てる
  s32 panelID0;                                // 0x314, TextPanel_Create(22, 4, 6, 2)
  u32 unk_318;                                 // 0x318, FUN_081db57c が初回だけの初期化を行うための番兵
  s32 panelID1;                                // 0x31C, TextPanel_Create(20, 12, 8, 2)
  u8 unk_320;                                  // 0x320, Init で 0
  u8 repeatTimer;                              // 0x321, 十字キーを押しっぱなしの間 0xC まで数え、離すと 0 に戻る
  u8 values[3];                                // 0x322, 各行の選択値, 左右で counts[i] を上限に巻き戻る
  u8 counts[3];                                // 0x325, 各行の選択肢数, FUN_081daf44 が 1か2, 3, 4 を入れる
  u8 shown[3];                                 // 0x328, 表示済みの values[], 変化した行だけ FUN_081db4b0 が貼り直す
  s8 shownStringIdx;                           // 0x32B, 表示済みの文字列番号, 同じなら FUN_081daff0 は引き直さない
  u8 unk_32c;                                  // 0x32C, Init で 1
  u8 cursor;                                   // 0x32D, 選択中の行 (0..2), 上下で巻き戻り、変わると FUN_081db1e8 がスプライトを動かす
  u16 timer;                                   // 0x32E, 30 未満の間は入力を受け付けない
} Entity08F4;
static_assert(sizeof(Entity08F4) == 816);

bool32 FUN_081dfa04(void);

const s32 s32_ARRAY_085ae1b4[6] = {0, 0, 0, 32, 0, 64};  // 0x085AE1B4

const s32 s32_ARRAY_085ae1cc[6] = {32, 0, 32, 32, 16, 64};  // 0x085AE1CC

const s32 s32_ARRAY_085ae1e4[6] = {0, 0, 0, 32, 0, 64};  // 0x085AE1E4

const u16 u16_ARRAY_085ae1fc[4] = {60, 90, 120, 0};  // 0x085AE1FC

// 3行の選択値を通信セッション側へ写す
s32 FUN_081dae74(Entity08F4* p) {
  Entity9A9F* q = gEntity9A9F;
  u8* dst;

  if (q == NULL || (dst = &q->unk_2c4) == NULL) {
    return -1;
  }

  dst[0] = p->values[0];
  dst[1] = p->values[1];
  dst[2] = p->values[2];
  return 0;
}

NAKED void FUN_081daeb8(unknown* param_1) { INCFUNC("asm/func/FUN_081daeb8.inc"); }

NAKED void FUN_081daf44(unknown* param_1) { INCFUNC("asm/func/FUN_081daf44.inc"); }

NAKED void FUN_081daff0(unknown* param_1) { INCFUNC("asm/func/FUN_081daff0.inc"); }

NAKED void FUN_081db074(unknown* param_1) { INCFUNC("asm/func/FUN_081db074.inc"); }

void Entity08F4_HidePanels(Entity08F4* p) {
  TextPanel_Hide(p->panelID0);
  TextPanel_Hide(p->panelID1);
}

NAKED void FUN_081db14c(unknown* param_1) { INCFUNC("asm/func/FUN_081db14c.inc"); }

NAKED void FUN_081db1e8(unknown* param_1) { INCFUNC("asm/func/FUN_081db1e8.inc"); }

void Entity08F4_HideSprites(Entity08F4* p) {
  s32 i;

  for (i = 0; i < 7; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

void Entity08F4_RemoveSprites(Entity08F4* p) {
  s32 i;

  for (i = 0; i < 7; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

void Entity08F4_SavePltt(Entity08F4* p) {
  rgb555* src = &gObjPlttData[659 * 16];
  s32 i;

  for (i = 0; i < 16; i++) {
    p->objPltt[i] = src[i];
  }
  p->sprites[0].pltt = p->objPltt;
  p->unk_304 = 0;
}

NAKED void FUN_081db370(unknown* param_1) { INCFUNC("asm/func/FUN_081db370.inc"); }

NAKED void FUN_081db3c0(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_081db3c0.inc"); }

NAKED void FUN_081db4b0(unknown* param_1) { INCFUNC("asm/func/FUN_081db4b0.inc"); }

NAKED void FUN_081db57c(unknown* param_1) { INCFUNC("asm/func/FUN_081db57c.inc"); }

s32 Entity08F4_Update(Entity08F4* p) {
  if (!FUN_081dfa04()) {
    Marquee_CloseGlobal();
    Entity08F4_HideSprites(p);
    KillEntity((Entity*)p);
    return -1;
  }

  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  return 1;
}

s32 Entity08F4_Destroy(Entity08F4* p) {
  Entity08F4_RemoveSprites(p);
  Entity08F4_HidePanels(p);
  return 1;
}

NAKED s32 Entity08F4_Init(Entity08F4* p) { INCFUNC("asm/func/Entity08F4_Init.inc"); }

Entity08F4* Entity08F4_Create(void) {
  Entity08F4* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity08F4));

  if (p != NULL) {
    SetEntityRoutine(p, Entity08F4_Update, Entity08F4_Destroy);
    if (Entity08F4_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
