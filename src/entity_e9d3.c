#include "entity.h"
#include "global.h"
#include "sprite.h"

typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_11
  MainSpriteGfx gfx0;         // 0x018, OpenSpriteSetFile(GetFile(DIR_SPRITE_SETS, 0x92F0))
  MainSpriteGfx gfx1;         // 0x038, OpenSpriteSetFile で開くスプライトセット
  MainSprite sprites[20];     // 0x058, _Destroy が stride 0x60 で20枚 MainSprite_Remove する
  AuxSprite auxSprite;        // 0x7D8, _Destroy が AuxSprite_Remove に渡す
  u8 unk_804[36];             // 0x804, _Init が CopyMemory の転送先に使う
  u8* script;                 // 0x828, TextBox_Start に渡す本文
  u16 unk_82c;                // 0x82C, _Init が書き込む
  u8 unk_82e[2];              // 0x82E, まだ未解析
  u32 unk_830;                // 0x830, _Init が VM キーワード 'd' を入れる (無ければ 0)
  u32 unk_834;                // 0x834, _Init が VM キーワード 'e' を入れる (無ければ 0)
  u8 unk_838[0x846 - 0x838];  // 0x838, まだ未解析
  u16 unk_846;                // 0x846, _Init が VM キーワード 'o' を入れる. 0 なら FUN_080b4b04、それ以外は FUN_080b4e8c を呼ぶ
  u8 unk_848[2128 - 0x848];   // 0x848, まだ未解析
} EntityE9D3;
static_assert(sizeof(EntityE9D3) == 2128);

INCASM("asm/entity_e9d3.inc");

NAKED void EntityE9D3_Init_Helper_080b5650(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Init_Helper_080b5650.inc"); }

NAKED void EntityE9D3_Init_Helper_080b593c(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Init_Helper_080b593c.inc"); }

NAKED s32 EntityE9D3_Init_Helper_080b5984(void) { INCFUNC("asm/func/EntityE9D3_Init_Helper_080b5984.inc"); }

NAKED s32 EntityE9D3_Init(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Init.inc"); }

NAKED EntityE9D3* EntityE9D3_Create(void) { INCFUNC("asm/func/EntityE9D3_Create.inc"); }
