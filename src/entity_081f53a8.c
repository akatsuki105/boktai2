#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

typedef struct {
  AuxSprite sprite;        // 0x000, priority 1, flags に bit0 を立てて作る
  AuxSpriteGfx gfx;        // 0x02C, SPRITE_D45E, パレット 250
  AuxAnimState animState;  // 0x048, 親の anim のアニメ 0x14
  HitboxData hitbox0;      // 0x058
  HitboxData hitbox1;      // 0x0A8
  u8 unk_f8[118];          // 0x0F8, まだ未解析
  u8 state;                // 0x16E, PTR_FUN_081f48ac_1_085ae578 の添字
  u8 unk_16f[3];           // 0x16F, まだ未解析
  u8 unk_172;              // 0x172, FUN_081f4650 が 1 を書く
  u8 unk_173[17];          // 0x173, まだ未解析
} Entity081f53a8Elem;
static_assert(sizeof(Entity081f53a8Elem) == 388);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  AuxAnimFile* anim;            // 0x018, ANIM_1DC3
  u32 activeMask;               // 0x01C, 立っているビットの枠だけ Update と Destroy が触る
  Entity081f53a8Elem elems[8];  // 0x020
} Entity081f53a8;
static_assert(sizeof(Entity081f53a8) == 3136);

static Entity081f53a8* gEntity081f53a8;  // 0x030001F8

NAKED void FUN_081f4650(unknown* param_1, unknown* param_2, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f4650.inc"); }

NAKED void FUN_081f4704(unknown* param_1, u32 param_2, unknown* param_3) { INCFUNC("asm/func/FUN_081f4704.inc"); }

NAKED void FUN_081f4758(Entity081f53a8Elem* elem, u16 param_2, u16 param_3, u32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_081f4758.inc"); }

NAKED void FUN_081f4858(Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f4858.inc"); }

NAKED void FUN_081f48ac(Entity081f53a8* p, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f48ac.inc"); }

NAKED void FUN_081f48b0(Entity081f53a8* p, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f48b0.inc"); }

NAKED void FUN_081f4a08(Vec3* pos, u32 angle) { INCFUNC("asm/func/FUN_081f4a08.inc"); }

NAKED void FUN_081f4af4(Entity081f53a8* p, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f4af4.inc"); }

NAKED void FUN_081f4d80(Entity081f53a8* p, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f4d80.inc"); }

NAKED s32 FUN_081f5138(Entity081f53a8* p, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f5138.inc"); }

NAKED Entity081f53a8Elem* FUN_081f519c(Entity081f53a8* p) { INCFUNC("asm/func/FUN_081f519c.inc"); }

NAKED void FUN_081f51ac(Vec3* pos, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, s16 param_7, s16 param_8, u16 param_9, u8 param_10) { INCFUNC("asm/func/FUN_081f51ac.inc"); }

void (*const PTR_ARRAY_085ae578[4])(Entity081f53a8*, Entity081f53a8Elem*) = {
    FUN_081f48ac,
    FUN_081f4af4,
    FUN_081f4d80,
    FUN_081f48b0,
};  // 0x085AE578

NAKED s32 Entity081f53a8_Update(Entity081f53a8* p) { INCFUNC("asm/func/Entity081f53a8_Update.inc"); }

NAKED s32 Entity081f53a8_Destroy(Entity081f53a8* p) { INCFUNC("asm/func/Entity081f53a8_Destroy.inc"); }

NAKED s32 Entity081f53a8_Init(Entity081f53a8* p) { INCFUNC("asm/func/Entity081f53a8_Init.inc"); }

NAKED Entity081f53a8* Entity081f53a8_Create(void) { INCFUNC("asm/func/Entity081f53a8_Create.inc"); }

NAKED void FUN_081f53f4(void) { INCFUNC("asm/func/FUN_081f53f4.inc"); }

NAKED void FUN_081f5400(void) { INCFUNC("asm/func/FUN_081f5400.inc"); }
