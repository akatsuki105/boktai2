#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

typedef struct {
  AuxSprite sprite;      // 0x00, EntityB6FF_Destroy が AuxSprite_Remove に渡す
  u8 unk_2c[92 - 0x2C];  // 0x2C, まだ未解析
} EntityB6FFElem;
static_assert(sizeof(EntityB6FFElem) == 92);

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_10
  u8 unk_18[4];              // 0x018, まだ未解析
  u8 unk_1c[36];             // 0x01C, _Init が stride 0xC で4回まわして u16 を3つずつ書く ('.c'/'.r'), 4回目は elems[0] の先頭に重なる
  EntityB6FFElem elems[24];  // 0x040, _Destroy が stride 0x5C で24枚 AuxSprite_Remove する
  u8 unk_8e0[2276 - 0x8E0];  // 0x8E0, まだ未解析
} EntityB6FF;
static_assert(sizeof(EntityB6FF) == 2276);

INCASM("asm/entity_b6ff.inc");
