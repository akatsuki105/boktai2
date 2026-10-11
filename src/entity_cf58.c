#include "entity.h"
#include "global.h"

// _Create が 2種類ある (_Init, _Update, _Destroy は共通)
typedef struct {
  Entity e;  // ENTITY_UNK_4
  u8 unk_18[176 - 0x18];
} EntityCF58;
static_assert(sizeof(EntityCF58) == 176);

IWRAM_DATA EntityCF58* gEntityCF58 = NULL;  // 0x0300014C

INCASM("asm/entity_cf58.inc");
