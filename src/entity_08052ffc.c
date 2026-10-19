#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

// SPRITE_OJAMA_BAT を使うのでオジャマバット用のエンティティ (つまりクロスオーバーのEntity)
// src の位置に貼り付いて 20 フレームかけて縮みながら上がり, 消えるときに粒子を散らす1枚
typedef struct {
  u8 unk_00;         // 0x00
  bool8 active;      // 0x01, 0 以外の間だけ _Update が処理する
  u8 unk_02[2];      // 0x02
  u32 timer;         // 0x04, 20 に達すると sprite を隠して active を落とし粒子を出す
  Vec3 pos;          // 0x08, src の写し
  Vec3* src;         // 0x10, 追従する位置
  AuxSprite sprite;  // 0x14, pos.y + timer * 0x40 の高さに出る, scaleX は timer * 2 + 1
} Entity08052ffcElem;
static_assert(sizeof(Entity08052ffcElem) == 64);

// SPRITE_OJAMA_BAT を使うのでオジャマバット用のエンティティ (つまりクロスオーバーのEntity)
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_11
  AuxSpriteGfx gfx;             // 0x018, SPRITE_OJAMA_BAT
  Entity08052ffcElem elems[4];  // 0x034
} Entity08052ffc;
static_assert(sizeof(Entity08052ffc) == 308);

const u8 u8_ARRAY_085ab73c[4] = {26, 29, 18, 33};  // 0x085AB73C

const u16 u16_ARRAY_085ab740[4] = {0x760, 0x800, 0x8A0, 0x800};  // 0x085AB740

INCASM("asm/entity_08052ffc.inc");
