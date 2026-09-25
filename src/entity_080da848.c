#include "entity.h"
#include "particle.h"
#include "sprite.h"
#include "global.h"

// 8枠ぶんの演出要素。activeMask のビットが立っている枠だけ生きている
typedef struct {
  u8 unk_0[0x38];     // 0x000
  u8 ptclMask;        // 0x038, bit0..2 が立っている枠だけ _Destroy が Particle_Remove する
  u8 unk_39[11];      // 0x039
  u8 hasSprite;       // 0x044, 0 以外なら _Destroy が spr を AuxSprite_Remove する
  u8 unk_45[0x17];    // 0x045
  AuxSprite spr;      // 0x05C, _Destroy が AuxSprite_Remove に渡す
  Particle ptcls[3];  // 0x088, 根拠: _Destroy の stride 0x28 × 3
  u8 unk_100[0x34];   // 0x100
} Entity080da848Elem;
static_assert(sizeof(Entity080da848Elem) == 308);

typedef struct Entity080da848 {
  Entity e;                     // 0x000, ENTITY_UNK_9
  u8 unk_18[0x44];              // 0x018
  Entity080da848Elem elems[8];  // 0x05C, 根拠: _Destroy の stride 0x134 × 8
  u32 activeMask;               // 0x9FC, 使用中の elems のビットマスク
} Entity080da848;
static_assert(sizeof(Entity080da848) == 2560);

extern Entity080da848* gEntity080da848;  // 0x0300015C

INCASM("asm/entity_080da848.inc");
