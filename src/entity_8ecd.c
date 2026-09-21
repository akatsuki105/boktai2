#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[2280 - 0x18];
} Entity8ECD;
static_assert(sizeof(Entity8ECD) == 2280);

IWRAM_DATA s32 s32_03000074 = 0;            // 0x03000074
IWRAM_DATA s32 s32_03000078 = 0;            // 0x03000078
IWRAM_DATA u32 u32_0300007c = 0;            // 0x0300007C
IWRAM_DATA s32 s32_03000080 = 0;            // 0x03000080
IWRAM_DATA Entity8ECD* gEntity8ECD = NULL;  // 0x03000084

bool32 FUN_08018118(Entity8ECD*);
bool32 FUN_08018250(Entity8ECD*);
bool32 FUN_08018284(Entity8ECD*);
bool32 FUN_08018324(Entity8ECD*);
bool32 FUN_080184ec(Entity8ECD*);

bool32 (*const PTR_ARRAY_085aa948[5])(Entity8ECD*) = {
    FUN_08018118, FUN_08018250, FUN_08018284, FUN_08018324, FUN_080184ec,
};  // 0x085AA948

INCASM("asm/entity_8ecd.inc");
