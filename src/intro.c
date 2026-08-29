#include "global.h"
#include "sprite.h"

// ゲーム起動時からタイトル画面でモード(GAMESTART, OPTION, LINK のどれか)を選択するまでの処理を行う
// モード(GAMESTART, OPTION, LINK のどれか) からBボタンに戻ると、またこのEntityが生成される

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[0x94 - 0x18];
  SpriteState spr_94;   // 0x094
  SpriteState spr_f4;   // 0x0F4
  SpriteState spr_154;  // 0x154
  SpriteState spr_1b4;  // 0x1B4
  SpriteState spr_214;  // 0x214
  SpriteState spr_274;  // 0x274
  SpriteState spr_2d4;  // 0x2D4
  SpriteState spr_334;  // 0x334
  u8 unk_394[1068 - 0x394];
} Intro;
static_assert(sizeof(Intro) == 1068);

void Intro_DestroyInternal(Intro* p);

INCASM("asm/intro.inc");

NAKED s32 Intro_Update(Intro* p) { INCFUNC("asm/func/Intro_Update.inc"); }

s32 Intro_Destroy(Intro* p) {
  Intro_DestroyInternal(p);
  return 0;
}

NAKED s32 Intro_Init(Intro* p) { INCFUNC("asm/func/Intro_Init.inc"); }

NAKED Intro* Intro_Create(void) { INCFUNC("asm/func/Intro_Create.inc"); }
