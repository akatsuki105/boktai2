#include "entity.h"
#include "global.h"
#include "sprite_aux.h"
#include "video.h"

// 1発ぶんのエフェクト
typedef struct {
  AuxSprite sprite;        // 0x00
  u8 unk_2c[0xF3 - 0x2C];  // 0x2C, まだ未解析
  u8 unk_f3;               // 0xF3, FUN_080df478 が 1 を入れる
  u16 flags;               // 0xF4, FUN_080de344 が bit2 を立てる
  u8 state;                // 0xF6, _Update が 0x085AD354 の関数表の添字として引く
  u8 index;                // 0xF7, FUN_080de174 が確保したスロット番号を入れる
  s16 timer;               // 0xF8, FUN_080de344 が毎フレーム減らし, 0 になると 3 に戻す
  u8 unk_fa[2];            // 0xFA, まだ未解析, padding?
} Entity080df420Elem;
static_assert(sizeof(Entity080df420Elem) == 252);

typedef struct Entity080df420 {
  Entity e;                      // 0x00, ENTITY_UNK_10
  AuxSpriteGfx gfx;              // 0x18, SPRITE_EFF_F422
  u8 unk_34[4];                  // 0x34, まだ未解析
  u32 usedMask;                  // 0x38, elems のどのスロットが使用中か, FUN_080de174 が立てる
  s16 frame;                     // 0x3C, _Update が毎フレーム 1 足す
  s16 count;                     // 0x3E, FUN_080de174 が確保のたびに 1 足す
  Entity080df420Elem elems[24];  // 0x40
} Entity080df420;
static_assert(sizeof(Entity080df420) == 6112);

extern Entity080df420* gEntity080df420;  // 0x03000178

void FUN_080de81c(Entity080df420*, Entity080df420Elem*);
void FUN_080de820(Entity080df420*, Entity080df420Elem*);

void (*const sEntity080df420Updates[2])(Entity080df420*, Entity080df420Elem*) = {
    FUN_080de81c,
    FUN_080de820,
};  // 0x085AD354

void FUN_080debbc(unknown*, unknown*);
void FUN_080defd0(unknown*, unknown*);

void (*const PTR_ARRAY_085ad35c[2])(unknown*, unknown*) = {
    FUN_080debbc,
    FUN_080defd0,
};  // 0x085AD35C

INCASM("asm/entity_080df420.inc");

void FUN_080df46c(void) { gEntity080df420 = NULL; }

NAKED void FUN_080df478(void) { INCFUNC("asm/func/FUN_080df478.inc"); }
