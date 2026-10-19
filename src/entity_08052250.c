#include "entity.h"
#include "global.h"
#include "sprite_main.h"

// 通信画面の UI スプライト4枚を state ごとに動かすシングルトン
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_11
  u32 unk_18;             // 0x018
  u8 state;               // 0x01C, PTR_ARRAY_085ab70c の添字
  u8 unk_1d;              // 0x01D, 初期値 1
  u8 unk_1e;              // 0x01E
  u8 unk_1f;              // 0x01F
  MainSpriteGfx gfx;      // 0x020, SPRITE_UI_LINK
  MainSprite sprites[4];  // 0x040, 全部 pose 0x43 で追加される
} Entity08052250;
static_assert(sizeof(Entity08052250) == 448);

void FUN_08051dfc(Entity08052250*);
void FUN_08051e30(Entity08052250*);
void FUN_08051e7c(Entity08052250*);
void FUN_08051efc(Entity08052250*);
void FUN_08052084(Entity08052250*);
void FUN_0805212c(Entity08052250*);

void (*const PTR_ARRAY_085ab70c[6])(Entity08052250*) = {
    FUN_08051dfc,
    FUN_08051e30,
    FUN_08051e7c,
    FUN_08051efc,
    FUN_08052084,
    FUN_0805212c,
};  // 0x085AB70C

INCASM("asm/entity_08052250.inc");
