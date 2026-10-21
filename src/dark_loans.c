#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// solar_bank.c と同形

// 暗黒ローンのメニュー(太陽バンクや暗黒カードは別)
typedef struct DarkLoans {
  Entity e;                                   // 0x000, ENTITY_UNK_11
  MainSpriteGfx gfx0;                         // 0x018, SPRITE_UI_DARKLOAN
  MainSpriteGfx gfx1;                         // 0x038
  MainSprite sprites[20];                     // 0x058
  AuxSprite auxSprite;                        // 0x7D8
  u8 unk_804[0x820 - 0x804];                  // 0x804, まだ未解析
  TilemapFile* tilemap;                       // 0x820, TILEMAP_C091
  rgb555* pltt;                               // 0x824, BGP_EAA8 の body[208]
  u8* script;                                 // 0x828, MessageWindow_Start に渡す本文
  u16 unk_82c;                                // 0x82C
  u8 unk_82e[2];                              // 0x82E, まだ未解析
  u32 unk_830;                                // 0x830, '.d'
  u32 unk_834;                                // 0x834, '.e'
  u8 unk_838[0x844 - 0x838];                  // 0x838, まだ未解析
  u16 unk_844;                                // 0x844, DarkLoans_SetUpdate が updateCallback を差し替えるときに 0 に戻す
  bool16 unk_846;                             // 0x846, '.o', 0 なら FUN_080b4b04、それ以外は FUN_080b4e8c を呼ぶ
  u8 unk_848[4];                              // 0x848, まだ未解析
  void (*updateCallback)(struct DarkLoans*);  // 0x84C, DarkLoans_Update が毎フレーム呼ぶ
} DarkLoans;
static_assert(sizeof(DarkLoans) == 2128);

void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
void FUN_080b54ec(DarkLoans* p);

NAKED void FUN_080b4818(unknown* param_1) { INCFUNC("asm/func/FUN_080b4818.inc"); }

NAKED void dark_loans_080b48c8(unknown* param_1) { INCFUNC("asm/func/dark_loans_080b48c8.inc"); }

NAKED void FUN_080b4a50(unknown* param_1) { INCFUNC("asm/func/FUN_080b4a50.inc"); }

void FUN_080b4abc(DarkLoans* p) {
  s32 i;

  for (i = 0; i < 20; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
  p->auxSprite.flags |= SPRFLAG_HIDDEN;
}

// 毎フレーム呼ぶ処理を差し替える
void DarkLoans_SetUpdate(DarkLoans* p, void* fn) {
  p->updateCallback = fn;
  p->unk_844 = 0;
}

NAKED void FUN_080b4b04(unknown* param_1) { INCFUNC("asm/func/FUN_080b4b04.inc"); }

NAKED void FUN_080b4ba4(unknown* param_1) { INCFUNC("asm/func/FUN_080b4ba4.inc"); }

NAKED void FUN_080b4c5c(unknown* param_1) { INCFUNC("asm/func/FUN_080b4c5c.inc"); }

NAKED void FUN_080b4d98(unknown* param_1) { INCFUNC("asm/func/FUN_080b4d98.inc"); }

NAKED void FUN_080b4e04(unknown* param_1) { INCFUNC("asm/func/FUN_080b4e04.inc"); }

NAKED void FUN_080b4e8c(unknown* param_1) { INCFUNC("asm/func/FUN_080b4e8c.inc"); }

void FUN_080b4f08(DarkLoans* p) {
  MainSprite_AdvanceAnim(&p->sprites[0], &p->gfx0);
  if (p->unk_844 == 0x20) {
    PlaySound_082406e0(0x2C0);
  }
  p->unk_844++;
  if (p->unk_844 > 0x68) {
    FUN_080b4ba4(p);
  }
}

NAKED void FUN_080b4f48(unknown* param_1) { INCFUNC("asm/func/FUN_080b4f48.inc"); }

// 残差1命令 (19/18): agbcc は3ケースの switch を必ず中央 (case 2) 根で木にするが, 原典は case 1 根の一直線な木になる
NON_MATCH s32 FUN_080b4ffc(s32 val) {
#ifdef NONMATCHING_C
  switch (val >> 2) {
    case 1: {
      return 1;
    }
    case 2: {
      return 2;
    }
    case 3: {
      return 1;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_080b4ffc.inc");
#endif
}

NAKED void dark_loans_080b5020(unknown* param_1) { INCFUNC("asm/func/dark_loans_080b5020.inc"); }

NAKED void FUN_080b539c(unknown* param_1) { INCFUNC("asm/func/FUN_080b539c.inc"); }

NAKED void FUN_080b5434(unknown* param_1) { INCFUNC("asm/func/FUN_080b5434.inc"); }

void FUN_080b54a0(DarkLoans* p) {
  p->unk_844++;
  if (p->unk_844 > 0x95) {
    FUN_0823ce68(3, 5, 4, 4, 4, 0xFFFF, 0);
    DarkLoans_SetUpdate(p, FUN_080b54ec);
  }
}

void FUN_080b54ec(DarkLoans* p) {
  p->unk_844++;
  if (p->unk_844 > 0x1F && p->unk_834 != 0) {
    VM_ExecByID(p->unk_834, NULL);
    KillEntity((Entity*)p);
  }
}

NAKED void FUN_080b5528(unknown* param_1) { INCFUNC("asm/func/FUN_080b5528.inc"); }

s32 DarkLoans_Update(DarkLoans* p) {
  p->updateCallback(p);
  return 0;
}

s32 DarkLoans_Destroy(DarkLoans* p) {
  s32 i;

  for (i = 0; i < 20; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
  AuxSprite_Remove(&p->auxSprite);
  return 0;
}

void FUN_080b55d4(DarkLoans* p) {
  s32 indices[1];

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_83C0);
  indices[0] = 0;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, indices);
}

// 後半48色のパレットを読み込んで BG パレットへ流す
void FUN_080b5614(DarkLoans* p) {
  BgPlttFile* f = GetBgPlttFile(BGP_EAA8);

  p->pltt = &f->body[208];
  CpuCopy32(p->pltt, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

NAKED void DarkLoans_Init_Helper_080b5650(DarkLoans* p) { INCFUNC("asm/func/DarkLoans_Init_Helper_080b5650.inc"); }

// '.r' があれば本文を差し替えて, メッセージ枠を開く
void DarkLoans_Init_Helper_080b593c(DarkLoans* p) {
  if (VM_SeekToNamedArg('r')) {
    p->script = VM_GetPC_Proxy();
  }

  MessageWindow_SetBgPltt(BGP_EAA8);
  MessageWindow_Start(p->script);
  MessageWindow_SetRect(1, 15, 28, 4);
  MessageWindow_SetInstant(1);
}

// 太陽ゲージが低いほど大きい値を返す
s32 DarkLoans_Init_Helper_080b5984(void) {
  s32 sun = gStat->sunGauge;

  if (sun <= 1) return 9;
  if (sun > 9) return 2;

  return 11 - sun;
}

NAKED s32 DarkLoans_Init(DarkLoans* p) { INCFUNC("asm/func/DarkLoans_Init.inc"); }

// 0xE9D3, HashName("暗黒ローン")
DarkLoans* DarkLoans_Create(void) {
  DarkLoans* p = CreateEntity(ENTITY_UNK_11, sizeof(DarkLoans));

  if (p != NULL) {
    SetEntityRoutine(p, DarkLoans_Update, DarkLoans_Destroy);
    if (DarkLoans_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
