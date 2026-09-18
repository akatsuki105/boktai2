#include "entity.h"
#include "global.h"

// Enemy関連のEntityなのは間違いない
typedef struct EntityEC2A {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[640 - 0x18];
} EntityEC2A;
static_assert(sizeof(EntityEC2A) == 640);

extern EntityEC2A gEntityEC2A;  // 0x03002C5C

INCASM("asm/entity_ec2a.inc");

// 後続の enemy_080ef84c.s も entity_ec2a.c に含めるかは不明
