#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

typedef struct {
  Entity e;                // 0x00, ENTITY_UNK_8
  u32 timer;               // 0x18, Init が 0 を書き Update が読み書きする
  AuxSpriteGfx gfx;        // 0x1C, SPRITE_BAT
  AuxSprite sprite;        // 0x38
  AuxAnimState animState;  // 0x64
  AuxAnimFile* anim;       // 0x74, ANIM_BAT
} EntityD438;
static_assert(sizeof(EntityD438) == 120);

IWRAM_DATA EntityD438* gEntityD438 = NULL;  // 0x03000124

NAKED void FUN_080558b8(void) { INCFUNC("asm/func/FUN_080558b8.inc"); }

NAKED void FUN_080558bc(void) { INCFUNC("asm/func/FUN_080558bc.inc"); }

NAKED void FUN_080558c0(void) { INCFUNC("asm/func/FUN_080558c0.inc"); }

NAKED s32 EntityD438_Update(EntityD438* p) { INCFUNC("asm/func/EntityD438_Update.inc"); }

NAKED s32 EntityD438_Destroy(EntityD438* p) { INCFUNC("asm/func/EntityD438_Destroy.inc"); }

NAKED s32 EntityD438_Init(EntityD438* p, u32 param_2) { INCFUNC("asm/func/EntityD438_Init.inc"); }

NAKED EntityD438* EntityD438_Create(u32 param_1) { INCFUNC("asm/func/EntityD438_Create.inc"); }
