#include "entity.h"
#include "global.h"
#include "sprite.h"

// 暗黒ローンのメニュー(太陽バンクや暗黒カードは別)
typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_11
  MainSpriteGfx gfx0;         // 0x018, SPRITE_92F0
  MainSpriteGfx gfx1;         // 0x038
  MainSprite sprites[20];     // 0x058
  AuxSprite auxSprite;        // 0x7D8
  u8 unk_804[36];             // 0x804
  u8* script;                 // 0x828, TextBox_Start に渡す本文
  u16 unk_82c;                // 0x82C
  u8 unk_82e[2];              // 0x82E, まだ未解析
  u32 unk_830;                // 0x830, '.d'
  u32 unk_834;                // 0x834, '.e'
  u8 unk_838[0x846 - 0x838];  // 0x838, まだ未解析
  bool16 unk_846;             // 0x846, '.o', 0 なら FUN_080b4b04、それ以外は FUN_080b4e8c を呼ぶ
  u8 unk_848[8];              // 0x848, まだ未解析
} EntityE9D3;
static_assert(sizeof(EntityE9D3) == 2128);

INCASM("asm/dark_loans.inc");

NAKED void EntityE9D3_Init_Helper_080b5650(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Init_Helper_080b5650.inc"); }

NAKED void EntityE9D3_Init_Helper_080b593c(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Init_Helper_080b593c.inc"); }

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
