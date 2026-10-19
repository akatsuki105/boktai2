#include "entity.h"
#include "global.h"
#include "sprite_aux.h"
#include "sprite_main.h"

// オジャマバット1体, AuxSprite 2枚 (本体と影) を抱えて state ごとに動く
typedef struct {
  u8 state;           // 0x00, PTR_ARRAY_085ab6d4 の添字
  u8 unk_01;          // 0x01, 初期値 1
  u8 unk_02;          // 0x02, 自分の添字 & 3
  u8 unk_03;          // 0x03
  u8 unk_04[4];       // 0x04
  u32 unk_08;         // 0x08
  u8 unk_0c[0x18];    // 0x0C
  AuxSprite sprite1;  // 0x24, gfx2 を使う
  AuxSprite sprite2;  // 0x50, gfx1 を使う, poseIdx は添字 & 3
} Entity08051b70Elem;
static_assert(sizeof(Entity08051b70Elem) == 124);

// オジャマバットを8体出す通信画面のシングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_11
  u32 unk_18;                   // 0x018
  u8 state;                     // 0x01C, PTR_ARRAY_085ab6f0 の添字
  u8 unk_1d;                    // 0x01D, 初期値 1
  u8 unk_1e[15];                // 0x01E
  u8 shakeTimer;                // 0x02D, 0 でない間 sprite.pos を乱数で揺らしながら減る
  u8 unk_2e[6];                 // 0x02E
  AuxSpriteGfx gfx1;            // 0x034, SPRITE_OJAMA_BAT
  AuxSpriteGfx gfx2;            // 0x050, 0x18A9
  MainSpriteGfx mainGfx;        // 0x06C, SPRITE_UI_LINK
  MainSprite sprite;            // 0x08C
  Entity08051b70Elem elems[8];  // 0x0EC
} Entity08051b70;
static_assert(sizeof(Entity08051b70) == 1228);

IWRAM_DATA Entity08051b70* gEntity08051b70 = NULL;  // 0x03000118

void FUN_08050f80(Entity08051b70*, unknown*, unknown*);
void FUN_08050fa0(Entity08051b70*, unknown*, unknown*);
void FUN_080510e0(Entity08051b70*, unknown*, unknown*);
void FUN_080511b0(Entity08051b70*, unknown*, unknown*);
void FUN_0805128c(Entity08051b70*, unknown*, unknown*);
void FUN_0805136c(Entity08051b70*, unknown*, unknown*);
void FUN_080514f0(Entity08051b70*, unknown*, unknown*);

void (*const PTR_ARRAY_085ab6d4[7])(Entity08051b70*, unknown*, unknown*) = {
    FUN_08050f80,
    FUN_08050fa0,
    FUN_080510e0,
    FUN_080511b0,
    FUN_0805128c,
    FUN_0805136c,
    FUN_080514f0,
};  // 0x085AB6D4

void FUN_08051640(Entity08051b70*);
void FUN_08051658(Entity08051b70*);
void FUN_0805169c(Entity08051b70*);
void FUN_08051710(Entity08051b70*);
void FUN_08051830(Entity08051b70*);
void FUN_08051898(Entity08051b70*);
void FUN_08051950(Entity08051b70*);

void (*const PTR_ARRAY_085ab6f0[7])(Entity08051b70*) = {
    FUN_08051640,
    FUN_08051658,
    FUN_0805169c,
    FUN_08051710,
    FUN_08051830,
    FUN_08051898,
    FUN_08051950,
};  // 0x085AB6F0

INCASM("asm/entity_08051b70.inc");
