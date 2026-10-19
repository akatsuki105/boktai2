#include "entity.h"
#include "global.h"
#include "player.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

// 芋虫1匹, 自分の速度で動き, sprite.pos の x と z は画面内に丸められる
typedef struct {
  u8 unk_00[2];       // 0x00
  u8 state;           // 0x02, PTR_ARRAY_085ab998 の添字
  u8 unk_03;          // 0x03
  u8 unk_04;          // 0x04
  u8 unk_05;          // 0x05
  s16 timer;          // 0x06, 毎フレーム +1
  u8 unk_08;          // 0x08, 0 のときだけ sprite.pos が範囲内に丸められる
  u8 unk_09[3];       // 0x09
  Vec3 vel;           // 0x0C, 毎フレーム sprite.pos に足される
  AuxSpriteGfx gfx;   // 0x14, SPRITE_61F9, パレット行 0x224
  AuxSprite sprite;   // 0x30, pose 0xC, priority 2
  AuxAnimState anim;  // 0x5C, animFile のアニメ3番から始まる
} Entity08056728Elem;
static_assert(sizeof(Entity08056728Elem) == 108);

// 芋虫を32匹まで同時に動かすシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  AuxAnimFile* animFile;         // 0x018, ANIM_31F4
  u32 usedMask;                  // 0x01C, elems のどのスロットが使用中かのビットマスク
  u32 unk_20;                    // 0x020, 下位2bitを添字 & 3 と比べる
  s16 unk_24;                    // 0x024, 毎フレーム 0 に戻してから elems が積む
  s16 unk_26;                    // 0x026, unk_24 * 12 を足して 0x40 に達すると発火するカウンタ
  s16 unk_28;                    // 0x028, 毎フレーム 0 に戻してから elems が積む
  u8 unk_2a;                     // 0x02A, 1 のとき player を見る分岐に入る
  u8 unk_2b;                     // 0x02B
  Entity08056728Elem elems[32];  // 0x02C
  Player* player;                // 0xDAC, gPlayerPtr[0]
} Entity08056728;
static_assert(sizeof(Entity08056728) == 3504);

IWRAM_DATA Entity08056728* gEntity08056728 = NULL;  // 0x03000128

void FUN_08055fe4(Entity08056728*, unknown*, s32);
void FUN_080561b8(Entity08056728*, unknown*, s32);
void FUN_080563b0(Entity08056728*, unknown*, s32);

const u16 u16_ARRAY_085ab990[4] = {4, 1, 2, 4};  // 0x085AB990

void (*const PTR_ARRAY_085ab998[3])(Entity08056728*, unknown*, s32) = {
    FUN_08055fe4,
    FUN_080561b8,
    FUN_080563b0,
};  // 0x085AB998

INCASM("asm/entity_08056728.inc");
