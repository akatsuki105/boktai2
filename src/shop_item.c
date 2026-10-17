#include "armor.h"
#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "inventory.h"
#include "item.h"
#include "menu.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

struct ItemShop;
typedef void(ItemShopFunc)(struct ItemShop*);

// 果実屋(リタ) と 道具屋(キッド) のショップメニュー
typedef struct ItemShop {
  Entity e;                      // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx0;            // 0x0018, SPRITE_UI_START_MENU
  MainSpriteGfx gfx1;            // 0x0038, SPRITE_INVENTORY_ICONS
  MainSpriteGfx gfx2;            // 0x0058, SPRITE_UI_MISC
  MainSprite sprites[49];        // 0x0078, [35] がカーソル
  Tilemaps* tilemap;             // 0x12D8, TILEMAP_9F57
  rgb555* bgPltt;                // 0x12DC, BGP_A41A[208]
  u8* unk_12e0;                  // 0x12E0, '.s' があれば VM_GetPC_Proxy の戻り値
  u8* unk_12e4;                  // 0x12E4, '.i' があれば VM_GetPC_Proxy の戻り値
  u8* unk_12e8;                  // 0x12E8, '.a' があれば VM_GetPC_Proxy の戻り値
  s8 unk_12ec;                   // 0x12EC, _Init の第2引数, 1 なら items1 も読む (RitaShop_Create は 0, KidShop_Create は 1)
  u8 unk_12ed;                   // 0x12ED, FUN_080bb160 が 0 を入れる
  u8 unk_12ee;                   // 0x12EE, FUN_080ba048 が FUN_080ba054 の第3引数を入れる
  u8 unk_12ef;                   // 0x12EF, FUN_080baae8 などが読む
  u16 stateTimer;                // 0x12F0, ItemShop_SetState が差し替えのたびに 0 に戻す
  u16 unk_12f2;                  // 0x12F2, FUN_080baa40 の戻り値
  s8 items0[16];                 // 0x12F4, '.I' の個数だけ '.T' から読んで残りは -1. [12..15] には [8..11] の写し
  s8 items1[16];                 // 0x1304, '.A' の個数だけ '.R' から読んで残りは -1. [12..15] には [8..11] の写し
  MenuSpritePair pair0;          // 0x1314, _Destroy が FUN_080b9a0c に渡す
  u8 unk_13f4[0x1408 - 0x13F4];  // 0x13F4, まだ未解析
  MenuCursor cursor;             // 0x1408, MenuCursor_Init(&cursor, 1, 4, 0, 20)
  MenuSpritePair pair1;          // 0x1438, _Destroy が FUN_080b9894 に渡す
  u8 unk_1518[2];                // 0x1518, まだ未解析
  u8 kind;                       // 0x151A, _Update が FUN_080b94cc / FUN_080b9400 に渡す
  u8 unk_151b;                   // 0x151B, _Init が 0 を入れる
  u8 unk_151c;                   // 0x151C, _Init が 0 を入れる
  u8 unk_151d[0x1534 - 0x151D];  // 0x151D, まだ未解析
  u32 unk_1534;                  // 0x1534, '.e' (なければ 0)
  ItemShopFunc* updateCallback;  // 0x1538
  ItemShopFunc* unk_153c;        // 0x153C, FUN_080ba054 が入れる, 読み手は未調査
} ItemShop;
static_assert(sizeof(ItemShop) == 5440);

void FUN_080bca7c(ItemShop* p);

void ItemShop_SetState(ItemShop* p, ItemShopFunc* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080ba048(ItemShop* p, s32 val) { p->unk_12ee = val; }

void FUN_080ba054(ItemShop* p, ItemShopFunc* fn, s32 val) {
  p->unk_153c = fn;
  FUN_080ba048(p, val);
  p->stateTimer = 0;
}

void FUN_080ba07c(ItemShop* p, s32 line) {
  FUN_08049e5c();
  p->sprites[33].flags |= SPRFLAG_HIDDEN;
  MessageWindow_Start(p->unk_12e0);
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_ShowLine(line);
}

// value を百の位・十の位・一の位に分解する
void SplitDecimal3_080ba0c0(s32 value, s32* digits) {
  digits[0] = Div(value, 100);
  value -= digits[0] * 100;
  digits[1] = Div(value, 10);
  digits[2] = value - digits[1] * 10;
}

NAKED void FUN_080ba0f0(ItemShop* p, s32 param_2) { INCFUNC("asm/func/FUN_080ba0f0.inc"); }

u32 item_08092034(s32 slot);  // src/entity_cc28.c

NAKED s32 FUN_080ba220(u32 param_1) { INCFUNC("asm/func/FUN_080ba220.inc"); }

// アイテムの売値, 腐敗の段階ごとに買値の 50% から 10% ずつ下げ, 20% を下限にする
s32 FUN_080ba288(s32 slot) {
  u32 stage = item_08092034(slot);
  s32 pct = 50;
  s32 price;

  if (stage != 0xCF) {
    pct = 50 - (stage - 0xD0) * 10;
    if (pct > 50) {
      pct = 50;
    }
    if (pct < 20) {
      pct = 20;
    }
  }

  price = Div(pct * FUN_080ba220(GetNormalItemID(slot)), 100);
  if (price <= 0) {
    price = 1;
  }
  if (price > 9999) {
    price = 9999;
  }
  return price;
}

NAKED void FUN_080ba2d8(ItemShop* p) { INCFUNC("asm/func/FUN_080ba2d8.inc"); }

NAKED void FUN_080ba410(ItemShop* p) { INCFUNC("asm/func/FUN_080ba410.inc"); }

NAKED void FUN_080ba57c(ItemShop* p) { INCFUNC("asm/func/FUN_080ba57c.inc"); }

NAKED void FUN_080ba624(ItemShop* p) { INCFUNC("asm/func/FUN_080ba624.inc"); }

NAKED void FUN_080ba710(ItemShop* p) { INCFUNC("asm/func/FUN_080ba710.inc"); }

NAKED void FUN_080ba7bc(ItemShop* p) { INCFUNC("asm/func/FUN_080ba7bc.inc"); }

NAKED void FUN_080ba85c(ItemShop* p, s32 param_2) { INCFUNC("asm/func/FUN_080ba85c.inc"); }

NAKED s32 FUN_080ba980(ItemShop* p) { INCFUNC("asm/func/FUN_080ba980.inc"); }

// 道具欄の空きスロット番号を返す, 空きがなければ -1
s32 FUN_080baa40(void) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (GetNormalItemID(i) < 0) {
      return i;
    }
  }
  return -1;
}

NAKED void FUN_080baa64(ItemShop* p) { INCFUNC("asm/func/FUN_080baa64.inc"); }

NAKED void FUN_080baae8(ItemShop* p) { INCFUNC("asm/func/FUN_080baae8.inc"); }

NAKED void FUN_080bad30(ItemShop* p) { INCFUNC("asm/func/FUN_080bad30.inc"); }

NAKED void FUN_080baeb0(ItemShop* p) { INCFUNC("asm/func/FUN_080baeb0.inc"); }

// 決定されたらカーソルの退避位置と現在位置のアイテムを入れ替える
void ItemShop_SwapSelectedItem(ItemShop* p) {
  if (FUN_080b9adc(&p->pair0)) {
    SwapNormalItem((u8)p->cursor.savedSlot, (u8)p->cursor.slot);
    FUN_080baa64(p);
  }
}

void FUN_080bafa4(ItemShop* p);

// カーソル確定の入力待ち, 決定なら FUN_080bafa4 へ, キャンセルなら SE を鳴らして戻る
void FUN_080baf50(ItemShop* p) {
  s32 r = FUN_080b977c(&p->sprites[48], &p->gfx0, &p->unk_12ef);

  if (r == 1) {
    MessageWindow_Close();
    FUN_080ba7bc(p);
    FUN_080ba054(p, FUN_080bafa4, 0);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080baa64(p);
  }
}

NAKED void FUN_080bafa4(ItemShop* p) { INCFUNC("asm/func/FUN_080bafa4.inc"); }

void FUN_080bb070(ItemShop* p);

// カーソル確定の入力待ち, 決定なら FUN_080bb070 へ, キャンセルなら SE を鳴らして戻る
void FUN_080bb01c(ItemShop* p) {
  s32 r = FUN_080b977c(&p->sprites[48], &p->gfx0, &p->unk_12ef);

  if (r == 1) {
    MessageWindow_Close();
    FUN_080ba710(p);
    FUN_080ba054(p, FUN_080bb070, 0);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080baa64(p);
  }
}

NAKED void FUN_080bb070(ItemShop* p) { INCFUNC("asm/func/FUN_080bb070.inc"); }

NAKED void FUN_080bb0e8(ItemShop* p) { INCFUNC("asm/func/FUN_080bb0e8.inc"); }

NAKED void FUN_080bb160(ItemShop* p) { INCFUNC("asm/func/FUN_080bb160.inc"); }

NAKED void FUN_080bb294(ItemShop* p) { INCFUNC("asm/func/FUN_080bb294.inc"); }

NAKED void FUN_080bb388(ItemShop* p) { INCFUNC("asm/func/FUN_080bb388.inc"); }

NAKED void FUN_080bb5bc(ItemShop* p) { INCFUNC("asm/func/FUN_080bb5bc.inc"); }

NAKED void FUN_080bb688(ItemShop* p) { INCFUNC("asm/func/FUN_080bb688.inc"); }

NAKED void FUN_080bb798(ItemShop* p) { INCFUNC("asm/func/FUN_080bb798.inc"); }

NAKED void FUN_080bb854(ItemShop* p) { INCFUNC("asm/func/FUN_080bb854.inc"); }

NAKED void FUN_080bb8f4(ItemShop* p, s32 param_2) { INCFUNC("asm/func/FUN_080bb8f4.inc"); }

NAKED s32 FUN_080bba88(ItemShop* p) { INCFUNC("asm/func/FUN_080bba88.inc"); }

// 空いている鎧スロットの番号を返す, 無ければ -1
s32 FindEmptyArmorSlot(void) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (gStat->armors[i] < 0) {
      return i;
    }
  }

  return -1;
}

NAKED void FUN_080bbbdc(ItemShop* p) { INCFUNC("asm/func/FUN_080bbbdc.inc"); }

NAKED void FUN_080bbc60(ItemShop* p) { INCFUNC("asm/func/FUN_080bbc60.inc"); }

NAKED void FUN_080bbeec(ItemShop* p) { INCFUNC("asm/func/FUN_080bbeec.inc"); }

NAKED void FUN_080bc07c(ItemShop* p) { INCFUNC("asm/func/FUN_080bc07c.inc"); }

// 決定されたらカーソルの退避位置と現在位置の鎧を入れ替える
void ItemShop_SwapSelectedArmor(ItemShop* p) {
  if (FUN_080b9adc(&p->pair0)) {
    SwapArmorSlot((u8)p->cursor.savedSlot, (u8)p->cursor.slot);
    FUN_080bbbdc(p);
  }
}

void FUN_080bc170(ItemShop* p);

// カーソル確定の入力待ち, 決定なら FUN_080bc170 へ, キャンセルなら SE を鳴らして戻る
void FUN_080bc11c(ItemShop* p) {
  s32 r = FUN_080b977c(&p->sprites[48], &p->gfx0, &p->unk_12ef);

  if (r == 1) {
    MessageWindow_Close();
    FUN_080bb854(p);
    FUN_080ba054(p, FUN_080bc170, 0);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080bbbdc(p);
  }
}

NAKED void FUN_080bc170(ItemShop* p) { INCFUNC("asm/func/FUN_080bc170.inc"); }

void FUN_080bc240(ItemShop* p);

// カーソル確定の入力待ち, 決定なら FUN_080bc240 へ, キャンセルなら SE を鳴らして戻る
void FUN_080bc1ec(ItemShop* p) {
  s32 r = FUN_080b977c(&p->sprites[48], &p->gfx0, &p->unk_12ef);

  if (r == 1) {
    MessageWindow_Close();
    FUN_080bb798(p);
    FUN_080ba054(p, FUN_080bc240, 0);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080bbbdc(p);
  }
}

NAKED void FUN_080bc240(ItemShop* p) { INCFUNC("asm/func/FUN_080bc240.inc"); }

NAKED void FUN_080bc2d8(ItemShop* p) { INCFUNC("asm/func/FUN_080bc2d8.inc"); }

NAKED void FUN_080bc350(ItemShop* p) { INCFUNC("asm/func/FUN_080bc350.inc"); }

NAKED void FUN_080bc400(ItemShop* p) { INCFUNC("asm/func/FUN_080bc400.inc"); }

// BGP_A41A[208]以降を BG パレットバッファの 208 色目にコピーする
void ItemShop_LoadBgPltt(ItemShop* p) {
  p->bgPltt = &GetBgPlttFile(BGP_A41A)->body[208];
  CpuCopy32(p->bgPltt, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

NAKED void FUN_080bc498(ItemShop* p) { INCFUNC("asm/func/FUN_080bc498.inc"); }

void FUN_080bc8c8(ItemShop* p) {
  if (VM_SeekToNamedArg('s')) {
    p->unk_12e0 = VM_GetPC_Proxy();
  }

  FUN_08049f5c();
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_SetBgPltt(BGP_A41A);
}

NAKED void FUN_080bc908(ItemShop* p) { INCFUNC("asm/func/FUN_080bc908.inc"); }

NAKED void FUN_080bc994(ItemShop* p) { INCFUNC("asm/func/FUN_080bc994.inc"); }

// VM の e 引数を unk_1534 に取り込む
void FUN_080bca20(ItemShop* p) {
  if (VM_SeekToNamedArg('e')) {
    p->unk_1534 = VM_GetValue();
  } else {
    p->unk_1534 = 0;
  }
}

void FUN_080bca50(ItemShop* p) {
  p->stateTimer++;
  if (p->stateTimer > 31) {
    ItemShop_SetState(p, FUN_080bca7c);
  }
}

NAKED void FUN_080bca7c(ItemShop* p) { INCFUNC("asm/func/FUN_080bca7c.inc"); }

NAKED void FUN_080bcbf4(ItemShop* p) { INCFUNC("asm/func/FUN_080bcbf4.inc"); }

s32 ItemShop_Update(ItemShop* p) {
  FUN_080b94cc(p->kind);
  FUN_080b9400(p->kind);
  p->updateCallback(p);
  return 0;
}

s32 ItemShop_Destroy(ItemShop* p) {
  s32 i;

  for (i = 0; i < (s32)ARRAY_COUNT(p->sprites); i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  FUN_080b9a0c(&p->pair0);
  FUN_080b9894(&p->pair1);
  return 0;
}

NAKED s32 ItemShop_Init(ItemShop* p, s8 param_2) { INCFUNC("asm/func/ItemShop_Init.inc"); }

// 0x3019, 果実屋(リタ), Hash元まだ未特定
ItemShop* RitaShop_Create(void) {
  ItemShop* p = CreateEntity(ENTITY_UNK_11, sizeof(ItemShop));

  if (p != NULL) {
    SetEntityRoutine(p, ItemShop_Update, ItemShop_Destroy);
    if (ItemShop_Init(p, 0) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 0x7300, HashName("道具屋")
ItemShop* KidShop_Create(void) {
  ItemShop* p = CreateEntity(ENTITY_UNK_11, sizeof(ItemShop));

  if (p != NULL) {
    SetEntityRoutine(p, ItemShop_Update, ItemShop_Destroy);
    if (ItemShop_Init(p, 1) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
