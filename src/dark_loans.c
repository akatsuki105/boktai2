#include "bg_pltt.h"
#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "text.h"
#include "vm.h"

// 暗黒ローンのメニュー(太陽バンクや暗黒カードは別)
typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_11
  MainSpriteGfx gfx0;         // 0x018, SPRITE_UI_DARKLOAN
  MainSpriteGfx gfx1;         // 0x038
  MainSprite sprites[20];     // 0x058
  AuxSprite auxSprite;        // 0x7D8
  u8 unk_804[36];             // 0x804
  u8* script;                 // 0x828, MessageWindow_Start に渡す本文
  u16 unk_82c;                // 0x82C
  u8 unk_82e[2];              // 0x82E, まだ未解析
  u32 unk_830;                // 0x830, '.d'
  u32 unk_834;                // 0x834, '.e'
  u8 unk_838[0x846 - 0x838];  // 0x838, まだ未解析
  bool16 unk_846;             // 0x846, '.o', 0 なら FUN_080b4b04、それ以外は FUN_080b4e8c を呼ぶ
  u8 unk_848[8];              // 0x848, まだ未解析
} EntityE9D3;
static_assert(sizeof(EntityE9D3) == 2128);

NAKED void FUN_080b4818(unknown* param_1) { INCFUNC("asm/func/FUN_080b4818.inc"); }

NAKED void dark_loans_080b48c8(unknown* param_1) { INCFUNC("asm/func/dark_loans_080b48c8.inc"); }

NAKED void FUN_080b4a50(unknown* param_1) { INCFUNC("asm/func/FUN_080b4a50.inc"); }

NAKED void FUN_080b4abc(unknown* param_1) { INCFUNC("asm/func/FUN_080b4abc.inc"); }

NAKED s32 FUN_080b4aec(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_080b4aec.inc"); }

NAKED void FUN_080b4b04(unknown* param_1) { INCFUNC("asm/func/FUN_080b4b04.inc"); }

NAKED void FUN_080b4ba4(unknown* param_1) { INCFUNC("asm/func/FUN_080b4ba4.inc"); }

NAKED void FUN_080b4c5c(unknown* param_1) { INCFUNC("asm/func/FUN_080b4c5c.inc"); }

NAKED void FUN_080b4d98(unknown* param_1) { INCFUNC("asm/func/FUN_080b4d98.inc"); }

NAKED void FUN_080b4e04(unknown* param_1) { INCFUNC("asm/func/FUN_080b4e04.inc"); }

NAKED void FUN_080b4e8c(unknown* param_1) { INCFUNC("asm/func/FUN_080b4e8c.inc"); }

NAKED void FUN_080b4f08(unknown* param_1) { INCFUNC("asm/func/FUN_080b4f08.inc"); }

NAKED void FUN_080b4f48(unknown* param_1) { INCFUNC("asm/func/FUN_080b4f48.inc"); }

NAKED s32 FUN_080b4ffc(s32 param_1) { INCFUNC("asm/func/FUN_080b4ffc.inc"); }

NAKED void dark_loans_080b5020(unknown* param_1) { INCFUNC("asm/func/dark_loans_080b5020.inc"); }

NAKED void FUN_080b539c(unknown* param_1) { INCFUNC("asm/func/FUN_080b539c.inc"); }

NAKED void FUN_080b5434(unknown* param_1) { INCFUNC("asm/func/FUN_080b5434.inc"); }

NAKED void FUN_080b54a0(unknown* param_1) { INCFUNC("asm/func/FUN_080b54a0.inc"); }

NAKED void FUN_080b54ec(unknown* param_1) { INCFUNC("asm/func/FUN_080b54ec.inc"); }

NAKED void FUN_080b5528(unknown* param_1) { INCFUNC("asm/func/FUN_080b5528.inc"); }

NAKED s32 EntityE9D3_Update(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Update.inc"); }

NAKED s32 EntityE9D3_Destroy(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Destroy.inc"); }

NAKED void FUN_080b55d4(unknown* param_1) { INCFUNC("asm/func/FUN_080b55d4.inc"); }

NAKED void FUN_080b5614(unknown* param_1) { INCFUNC("asm/func/FUN_080b5614.inc"); }

NAKED void EntityE9D3_Init_Helper_080b5650(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Init_Helper_080b5650.inc"); }

// '.r' があれば本文を差し替えて, メッセージ枠を開く
void EntityE9D3_Init_Helper_080b593c(EntityE9D3* p) {
  if (VM_SeekToNamedArg('r')) {
    p->script = VM_GetPC_Proxy();
  }

  MessageWindow_SetBgPltt(BGP_EAA8);
  MessageWindow_Start(p->script);
  MessageWindow_SetRect(1, 15, 28, 4);
  MessageWindow_SetInstant(1);
}

// 太陽ゲージが低いほど大きい値を返す
s32 EntityE9D3_Init_Helper_080b5984(void) {
  s32 sun = gStat->sunGauge;

  if (sun <= 1) return 9;
  if (sun > 9) return 2;

  return 11 - sun;
}

NAKED s32 EntityE9D3_Init(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Init.inc"); }

s32 EntityE9D3_Update(EntityE9D3* p);
s32 EntityE9D3_Destroy(EntityE9D3* p);

// 0xE9D3, HashName("暗黒ローン")
EntityE9D3* EntityE9D3_Create(void) {
  EntityE9D3* p = CreateEntity(ENTITY_UNK_11, sizeof(EntityE9D3));

  if (p != NULL) {
    SetEntityRoutine(p, EntityE9D3_Update, EntityE9D3_Destroy);
    if (EntityE9D3_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
