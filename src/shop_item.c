#include "armor.h"
#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "inventory.h"
#include "menu.h"
#include "sprite.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

struct Entity3019;
typedef void(Entity3019Func)(struct Entity3019*);

// 果実屋(リタ) と 道具屋(キッド) のショップメニュー
typedef struct Entity3019 {
  Entity e;                        // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx0;              // 0x0018, SPRITE_UI_START_MENU
  MainSpriteGfx gfx1;              // 0x0038, SPRITE_INVENTORY_ICONS
  MainSpriteGfx gfx2;              // 0x0058, SPRITE_UI_MISC
  MainSprite sprites[49];          // 0x0078, [35] がカーソル
  Tilemaps* tilemap;               // 0x12D8, TILEMAP_9F57
  rgb555* bgPltt;                  // 0x12DC, BGP_A41A[208]
  u8* unk_12e0;                    // 0x12E0, '.s' があれば FUN_0823d340 の戻り値
  u8* unk_12e4;                    // 0x12E4, '.i' があれば FUN_0823d340 の戻り値
  u8* unk_12e8;                    // 0x12E8, '.a' があれば FUN_0823d340 の戻り値
  s8 unk_12ec;                     // 0x12EC, _Init の第2引数, 1 なら items1 も読む (Entity3019_Create は 0, FUN_080bcd94 は 1)
  u8 unk_12ed;                     // 0x12ED, FUN_080bb160 が 0 を入れる
  u8 unk_12ee;                     // 0x12EE, FUN_080ba048 が FUN_080ba054 の第3引数を入れる
  u8 unk_12ef;                     // 0x12EF, FUN_080baae8 などが読む
  u16 stateTimer;                  // 0x12F0, Entity3019_SetState が差し替えのたびに 0 に戻す
  u16 unk_12f2;                    // 0x12F2, FUN_080baa40 の戻り値
  s8 items0[16];                   // 0x12F4, '.I' の個数だけ '.T' から読んで残りは -1. [12..15] には [8..11] の写し
  s8 items1[16];                   // 0x1304, '.A' の個数だけ '.R' から読んで残りは -1. [12..15] には [8..11] の写し
  MenuSpritePair pair0;            // 0x1314, _Destroy が FUN_080b9a0c に渡す
  u8 unk_13f4[0x1408 - 0x13F4];    // 0x13F4, まだ未解析
  MenuCursor cursor;               // 0x1408, MenuCursor_Init(&cursor, 1, 4, 0, 20)
  MenuSpritePair pair1;            // 0x1438, _Destroy が FUN_080b9894 に渡す
  u8 unk_1518[2];                  // 0x1518, まだ未解析
  u8 kind;                         // 0x151A, _Update が FUN_080b94cc / FUN_080b9400 に渡す
  u8 unk_151b;                     // 0x151B, _Init が 0 を入れる
  u8 unk_151c;                     // 0x151C, _Init が 0 を入れる
  u8 unk_151d[0x1534 - 0x151D];    // 0x151D, まだ未解析
  u32 unk_1534;                    // 0x1534, '.e' (なければ 0)
  Entity3019Func* updateCallback;  // 0x1538
  Entity3019Func* unk_153c;        // 0x153C, FUN_080ba054 が入れる, 読み手は未調査
} Entity3019;
static_assert(sizeof(Entity3019) == 5440);

// BG のタイルマップ上の (x, y) のアドレスを返す
static BgMapEntry* GetBgTilemapAddr(s32 bgID, u32 x, u32 y) {
  BgState* bg = &gBgStates[bgID];
  BgMapEntry* tilemap = bg->tilemap;

  return tilemap + (x & 0x1F) + (y & 0x1F) * 32;
}

NAKED void FUN_080b93b0(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s16 param_5) { INCFUNC("asm/func/FUN_080b93b0.inc"); }

NAKED void FUN_080b9400(s32 kind) { INCFUNC("asm/func/FUN_080b9400.inc"); }

NAKED void FUN_080b94cc(s32 kind) { INCFUNC("asm/func/FUN_080b94cc.inc"); }

// MainSprite_SetPlttID と同じことをするもう1つの実装
void FUN_080b95bc(MainSprite* p, u16 plttID) {
  p->plttID = plttID;
  p->pltt = &gObjPlttData[p->plttID * 16];
}

NAKED void FUN_080b95d0(s32 param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080b95d0.inc"); }

NAKED void FUN_080b9658(MainSpriteGfx* gfx, MainSprite* sprite, unknown* param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080b9658.inc"); }

void FUN_080b9724(MainSprite* sprites) {
  MainSprite* p = sprites;
  s32 i;

  for (i = 0; i < 5; i++) {
    p->flags |= SPRFLAG_HIDDEN;
    p++;
  }
}

NAKED void FUN_080b9740(MainSprite* sprite, MainSpriteGfx* gfx, char* param_3, s8 param_4) { INCFUNC("asm/func/FUN_080b9740.inc"); }

NAKED s32 FUN_080b977c(MainSprite* sprite, MainSpriteGfx* gfx, u8* param_3) { INCFUNC("asm/func/FUN_080b977c.inc"); }

NAKED void FUN_080b9814(MenuSpritePair* p) { INCFUNC("asm/func/FUN_080b9814.inc"); }

void FUN_080b9894(MenuSpritePair* p) {
  s32 i;
  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

s32 FUN_080b98b0(s32 param_1) {
  if (param_1 != 0) {
    param_1 += 0xA0;
  } else {
    param_1 = 0x93;
  }

  return param_1;
}

NAKED void FUN_080b98c0(MainSpriteGfx* gfx, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080b98c0.inc"); }

NAKED void FUN_080b9938(s16* param_1, s32 param_2) { INCFUNC("asm/func/FUN_080b9938.inc"); }

NAKED void FUN_080b99a0(MenuSpritePair* p) { INCFUNC("asm/func/FUN_080b99a0.inc"); }

void FUN_080b9a0c(MenuSpritePair* p) {
  s32 i;
  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

NAKED void FUN_080b9a28(MainSpriteGfx* gfx, s32* param_2, unknown* param_3, unknown* param_4, u16* param_5, s32 param_6, u16 param_7) { INCFUNC("asm/func/FUN_080b9a28.inc"); }

NAKED bool32 FUN_080b9adc(unknown* p) { INCFUNC("asm/func/FUN_080b9adc.inc"); }

// 行と列から実際のスロット番号を引く
s32 MenuCursor_GetSlot(MenuCursor* p) { return p->slots[p->row * 4 + p->col]; }

NAKED void FUN_080b9b88(MenuCursor* p) { INCFUNC("asm/func/FUN_080b9b88.inc"); }

void FUN_080b9d94(MenuCursor* p, u32 unk) {
  p->unk_7 = unk;
  FUN_080b9b88(p);
}

u8 FUN_080b9da0(MenuCursor* p, u8 mask) { return p->unk_7 & mask; }

NAKED s32 FUN_080b9da8(MenuCursor* p) { INCFUNC("asm/func/FUN_080b9da8.inc"); }

NAKED s32 FUN_080b9df0(MenuCursor* p) { INCFUNC("asm/func/FUN_080b9df0.inc"); }

NAKED s32 FUN_080b9e50(MenuCursor* p) { INCFUNC("asm/func/FUN_080b9e50.inc"); }

NAKED s32 FUN_080b9eb0(MenuCursor* p) { INCFUNC("asm/func/FUN_080b9eb0.inc"); }

NAKED s32 FUN_080b9f10(MenuCursor* p) { INCFUNC("asm/func/FUN_080b9f10.inc"); }

NAKED s32 FUN_080b9f70(MenuCursor* p) { INCFUNC("asm/func/FUN_080b9f70.inc"); }

void FUN_080b9fc4(MenuCursor* p, MainSprite* sprite) { FUN_080b9938(&sprite->pos.x, (u8)p->slot); }

// カーソルの位置を退避する
void FUN_080b9fd8(MenuCursor* p) {
  p->savedRow = p->row;
  p->savedCol = p->col;
  p->savedSlot = p->slot;
}

// 退避したカーソルの位置を戻す
void FUN_080b9fe8(MenuCursor* p) {
  p->row = p->savedRow;
  p->col = p->savedCol;
  p->slot = p->savedSlot;
}

// カーソルを初期化して行と列から実際のスロット番号を引く
void MenuCursor_Init(MenuCursor* p, u32 kind, u32 row, u32 col, u32 unk) {
  p->kind = kind;
  FUN_080b9d94(p, unk);
  p->row = row;
  p->col = col;
  p->slot = MenuCursor_GetSlot(p);
  p->unk_8 = 0;
}

void FUN_080bca7c(Entity3019* p);

void Entity3019_SetState(Entity3019* p, Entity3019Func* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080ba048(Entity3019* p, u8 val) { p->unk_12ee = val; }

// 残差は 17 命令 vs 15 命令 で、原典は p を保持したレジスタを stateTimer のアドレス計算で潰している
NON_MATCH void FUN_080ba054(Entity3019* p, Entity3019Func* fn, u8 val) {
#ifdef NONMATCHING_C
  p->unk_153c = fn;
  FUN_080ba048(p, val);
  p->stateTimer = 0;
#else
  INCFUNC("asm/func/FUN_080ba054.inc");
#endif
}

NAKED void FUN_080ba07c(Entity3019* p, s32 param_2) { INCFUNC("asm/func/FUN_080ba07c.inc"); }

// value を百の位・十の位・一の位に分解する
void SplitDecimal3_080ba0c0(s32 value, s32* digits) {
  digits[0] = Div(value, 100);
  value -= digits[0] * 100;
  digits[1] = Div(value, 10);
  digits[2] = value - digits[1] * 10;
}

NAKED void FUN_080ba0f0(Entity3019* p, s32 param_2) { INCFUNC("asm/func/FUN_080ba0f0.inc"); }

NAKED s32 FUN_080ba220(u32 param_1) { INCFUNC("asm/func/FUN_080ba220.inc"); }

NAKED s32 FUN_080ba288(s32 slot) { INCFUNC("asm/func/FUN_080ba288.inc"); }

NAKED void FUN_080ba2d8(Entity3019* p) { INCFUNC("asm/func/FUN_080ba2d8.inc"); }

NAKED void FUN_080ba410(Entity3019* p) { INCFUNC("asm/func/FUN_080ba410.inc"); }

NAKED void FUN_080ba57c(Entity3019* p) { INCFUNC("asm/func/FUN_080ba57c.inc"); }

NAKED void FUN_080ba624(Entity3019* p) { INCFUNC("asm/func/FUN_080ba624.inc"); }

NAKED void FUN_080ba710(Entity3019* p) { INCFUNC("asm/func/FUN_080ba710.inc"); }

NAKED void FUN_080ba7bc(Entity3019* p) { INCFUNC("asm/func/FUN_080ba7bc.inc"); }

NAKED void FUN_080ba85c(Entity3019* p, s32 param_2) { INCFUNC("asm/func/FUN_080ba85c.inc"); }

NAKED s32 FUN_080ba980(Entity3019* p) { INCFUNC("asm/func/FUN_080ba980.inc"); }

NAKED s32 FUN_080baa40(void) { INCFUNC("asm/func/FUN_080baa40.inc"); }

NAKED void FUN_080baa64(Entity3019* p) { INCFUNC("asm/func/FUN_080baa64.inc"); }

NAKED void FUN_080baae8(Entity3019* p) { INCFUNC("asm/func/FUN_080baae8.inc"); }

NAKED void FUN_080bad30(Entity3019* p) { INCFUNC("asm/func/FUN_080bad30.inc"); }

NAKED void FUN_080baeb0(Entity3019* p) { INCFUNC("asm/func/FUN_080baeb0.inc"); }

// 決定されたらカーソルの退避位置と現在位置のアイテムを入れ替える
void Entity3019_SwapSelectedItem(Entity3019* p) {
  if (FUN_080b9adc(&p->pair0)) {
    SwapNormalItem((u8)p->cursor.savedSlot, (u8)p->cursor.slot);
    FUN_080baa64(p);
  }
}

NAKED void FUN_080baf50(Entity3019* p) { INCFUNC("asm/func/FUN_080baf50.inc"); }

NAKED void FUN_080bafa4(Entity3019* p) { INCFUNC("asm/func/FUN_080bafa4.inc"); }

NAKED void FUN_080bb01c(Entity3019* p) { INCFUNC("asm/func/FUN_080bb01c.inc"); }

NAKED void FUN_080bb070(Entity3019* p) { INCFUNC("asm/func/FUN_080bb070.inc"); }

NAKED void FUN_080bb0e8(Entity3019* p) { INCFUNC("asm/func/FUN_080bb0e8.inc"); }

NAKED void FUN_080bb160(Entity3019* p) { INCFUNC("asm/func/FUN_080bb160.inc"); }

NAKED void FUN_080bb294(Entity3019* p) { INCFUNC("asm/func/FUN_080bb294.inc"); }

NAKED void FUN_080bb388(Entity3019* p) { INCFUNC("asm/func/FUN_080bb388.inc"); }

NAKED void FUN_080bb5bc(Entity3019* p) { INCFUNC("asm/func/FUN_080bb5bc.inc"); }

NAKED void FUN_080bb688(Entity3019* p) { INCFUNC("asm/func/FUN_080bb688.inc"); }

NAKED void FUN_080bb798(Entity3019* p) { INCFUNC("asm/func/FUN_080bb798.inc"); }

NAKED void FUN_080bb854(Entity3019* p) { INCFUNC("asm/func/FUN_080bb854.inc"); }

NAKED void FUN_080bb8f4(Entity3019* p, s32 param_2) { INCFUNC("asm/func/FUN_080bb8f4.inc"); }

NAKED s32 FUN_080bba88(Entity3019* p) { INCFUNC("asm/func/FUN_080bba88.inc"); }

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

NAKED void FUN_080bbbdc(Entity3019* p) { INCFUNC("asm/func/FUN_080bbbdc.inc"); }

NAKED void FUN_080bbc60(Entity3019* p) { INCFUNC("asm/func/FUN_080bbc60.inc"); }

NAKED void FUN_080bbeec(Entity3019* p) { INCFUNC("asm/func/FUN_080bbeec.inc"); }

NAKED void FUN_080bc07c(Entity3019* p) { INCFUNC("asm/func/FUN_080bc07c.inc"); }

// 決定されたらカーソルの退避位置と現在位置の鎧を入れ替える
void Entity3019_SwapSelectedArmor(Entity3019* p) {
  if (FUN_080b9adc(&p->pair0)) {
    SwapArmorSlot((u8)p->cursor.savedSlot, (u8)p->cursor.slot);
    FUN_080bbbdc(p);
  }
}

NAKED void FUN_080bc11c(Entity3019* p) { INCFUNC("asm/func/FUN_080bc11c.inc"); }

NAKED void FUN_080bc170(Entity3019* p) { INCFUNC("asm/func/FUN_080bc170.inc"); }

NAKED void FUN_080bc1ec(Entity3019* p) { INCFUNC("asm/func/FUN_080bc1ec.inc"); }

NAKED void FUN_080bc240(Entity3019* p) { INCFUNC("asm/func/FUN_080bc240.inc"); }

NAKED void FUN_080bc2d8(Entity3019* p) { INCFUNC("asm/func/FUN_080bc2d8.inc"); }

NAKED void FUN_080bc350(Entity3019* p) { INCFUNC("asm/func/FUN_080bc350.inc"); }

NAKED void FUN_080bc400(Entity3019* p) { INCFUNC("asm/func/FUN_080bc400.inc"); }

// BGP_A41A[208]以降を BG パレットバッファの 208 色目にコピーする
void Entity3019_LoadBgPltt(Entity3019* p) {
  p->bgPltt = &GetBgPlttFile(BGP_A41A)->body[208];
  CpuCopy32(p->bgPltt, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

NAKED void FUN_080bc498(Entity3019* p) { INCFUNC("asm/func/FUN_080bc498.inc"); }

NAKED void FUN_080bc8c8(Entity3019* p) { INCFUNC("asm/func/FUN_080bc8c8.inc"); }

NAKED void FUN_080bc908(Entity3019* p) { INCFUNC("asm/func/FUN_080bc908.inc"); }

NAKED void FUN_080bc994(Entity3019* p) { INCFUNC("asm/func/FUN_080bc994.inc"); }

// VM の e 引数を unk_1534 に取り込む
void FUN_080bca20(Entity3019* p) {
  if (VM_SeekToNamedArg('e')) {
    p->unk_1534 = VM_GetValue();
  } else {
    p->unk_1534 = 0;
  }
}

void FUN_080bca50(Entity3019* p) {
  p->stateTimer++;
  if (p->stateTimer > 31) {
    Entity3019_SetState(p, FUN_080bca7c);
  }
}

NAKED void FUN_080bca7c(Entity3019* p) { INCFUNC("asm/func/FUN_080bca7c.inc"); }

NAKED void FUN_080bcbf4(Entity3019* p) { INCFUNC("asm/func/FUN_080bcbf4.inc"); }

NAKED s32 Entity3019_Update(Entity3019* p) { INCFUNC("asm/func/Entity3019_Update.inc"); }

s32 Entity3019_Destroy(Entity3019* p) {
  s32 i;

  for (i = 0; i < (s32)ARRAY_COUNT(p->sprites); i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  FUN_080b9a0c(&p->pair0);
  FUN_080b9894(&p->pair1);
  return 0;
}

NAKED s32 Entity3019_Init(Entity3019* p, s8 param_2) { INCFUNC("asm/func/Entity3019_Init.inc"); }

// 0x3019, 果実屋(リタ)
NAKED Entity3019* Entity3019_Create(void) { INCFUNC("asm/func/Entity3019_Create.inc"); }

// 0x7300, 道具屋(キッド)
NAKED Entity3019* FUN_080bcd94(void) { INCFUNC("asm/func/FUN_080bcd94.inc"); }
