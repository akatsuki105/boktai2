#include "entity.h"
#include "global.h"

// 上下キーで選ぶ縦並びのメニュー, 項目は '.s' から値の対として読む
typedef struct {
  Entity e;         // 0x00, ENTITY_UNK_4
  u8* listPC;       // 0x18, '.s' の読み出し位置, 選択を動かすたびにここへ戻して読み直す
  s32 curValue;     // 0x1C, 選択中の項目の1つめの値
  s32 curScriptID;  // 0x20, 選択中の項目の2つめの値, A ボタンを離すと実行して自分を消す
  s32 index;        // 0x24, 選択中の添字, 終端に当たるとそこで止まる
  s32 repeatTimer;  // 0x28, キーを押し続けたときの待ちフレーム, 押し始めは 0x14 で以降は 4
  s32 lastDir;      // 0x2C, 前のフレームに押していた方向 (-1 上 / 1 下 / 0 なし)
} Entity8D5C;
static_assert(sizeof(Entity8D5C) == 48);

NAKED void Entity8D5C_MoveSelection(Entity8D5C* p, s32 delta) { INCFUNC("asm/func/Entity8D5C_MoveSelection.inc"); }

NAKED s32 Entity8D5C_Update(Entity8D5C* p) { INCFUNC("asm/func/Entity8D5C_Update.inc"); }

NAKED s32 Entity8D5C_Init(Entity8D5C* p) { INCFUNC("asm/func/Entity8D5C_Init.inc"); }

NAKED Entity8D5C* Entity8D5C_Create(void) { INCFUNC("asm/func/Entity8D5C_Create.inc"); }
