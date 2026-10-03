#include "entity.h"
#include "global.h"
#include "shadow.h"
#include "sprite_aux.h"

typedef struct {
  AuxSprite sprite;        // 0x00, Entity8CC7_Destroy が AuxSprite_Remove に渡す
  u8 unk_2c[0x79 - 0x2C];  // 0x2C, まだ未解析
  u8 noShadow;             // 0x79, 0 なら _Destroy が ParticleShadow_Remove を呼ぶ
  u8 unk_7a[2];            // 0x7A, まだ未解析
  ParticleShadow shadow;   // 0x7C, noShadow が 0 のとき生きている影
} Entity8CC7Elem;
static_assert(sizeof(Entity8CC7Elem) == 188);

typedef struct Entity8CC7 {
  Entity e;                  // 0x000, ENTITY_UNK_9
  AuxAnimFile* anim;         // 0x018, ANIM_7B03
  Entity8CC7Elem elems[20];  // 0x01C, usedMask のビットが立っている要素だけ _Destroy が片付ける
  u32 usedMask;              // 0xECC, elems[i] が使用中なら bit i が立つ, _Init が 0 クリアする
  u32 unk_ed0;               // 0xED0, _Init が 0xE10 (3600) を入れる
} Entity8CC7;
static_assert(sizeof(Entity8CC7) == 3796);

INCASM("asm/entity_8cc7.inc");
