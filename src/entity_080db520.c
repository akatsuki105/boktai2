#include "animation.h"
#include "entity.h"
#include "hitbox.h"
#include "sprite.h"
#include "global.h"

// 8枠ぶんの要素。activeMask のビットが立っている枠だけ生きている
typedef struct {
  AuxSprite spr;      // 0x00, _Destroy が AuxSprite_Remove に渡す
  u8 unk_2c[0x20];    // 0x2C
  HitboxData hitbox;  // 0x4C, _Destroy が Hitbox_Unregister に渡す
  u8 unk_9c[8];       // 0x9C
} Entity080db520Elem;
static_assert(sizeof(Entity080db520Elem) == 164);

typedef struct Entity080db520 {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx sprite_18;       // 0x018
  AuxAnimFile* anim_34;         // 0x034
  u32 activeMask;               // 0x038, 使用中の elems のビットマスク
  Entity080db520Elem elems[8];  // 0x03C, 根拠: _Destroy の stride 0xA4 × 8
} Entity080db520;
static_assert(sizeof(Entity080db520) == 1372);

extern Entity080db520* gEntity080db520;  // 0x03000160

INCASM("asm/entity_080db520.inc");
