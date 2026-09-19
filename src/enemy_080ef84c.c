#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"

// Enemy の共通部分?

// gSubroutineTable の 0xD854 から生成されるシングルトン. 実体のポインタは 0x03000184
typedef struct {
  Entity e;      // 0x00, ENTITY_UNK_8
  u8 unk_18[8];  // 0x18
  u32 unk_20;    // 0x20, EntityD854_Update が毎フレーム +1
  u16 unk_24;    // 0x24, EntityD854_Init が引数をそのまま書く
  u8 unk_26[6];  // 0x26
} EntityD854;
static_assert(sizeof(EntityD854) == 44);

NAKED void FUN_080ef84c(Enemy* p, s32 val1, s32 val2, s32 val3) { INCFUNC("asm/func/FUN_080ef84c.inc"); }

NAKED void FUN_080ef86c(Enemy* p, s32 val1) { INCFUNC("asm/func/FUN_080ef86c.inc"); }

NAKED void FUN_080ef968(Enemy* p, s32 val1, u32 val2) { INCFUNC("asm/func/FUN_080ef968.inc"); }

NAKED void FUN_080efa6c(Enemy* p, s32 val1, u32 val2) { INCFUNC("asm/func/FUN_080efa6c.inc"); }

INCASM("asm/enemy_080ef84c.inc");

NAKED s32 EntityD854_Update(EntityD854* p) { INCFUNC("asm/func/EntityD854_Update.inc"); }

NAKED s32 EntityD854_Destroy(EntityD854* p) { INCFUNC("asm/func/EntityD854_Destroy.inc"); }

NAKED s32 EntityD854_Init(EntityD854* p, u16 id) { INCFUNC("asm/func/EntityD854_Init.inc"); }

NAKED EntityD854* EntityD854_Create(u16 id) { INCFUNC("asm/func/EntityD854_Create.inc"); }

NAKED void FUN_080f9bec(void) { INCFUNC("asm/func/FUN_080f9bec.inc"); }

NAKED s32 FUN_080f9bf8(unknown* p, s32 val) { INCFUNC("asm/func/FUN_080f9bf8.inc"); }

NAKED void FUN_080f9bfc(Enemy* p) { INCFUNC("asm/func/FUN_080f9bfc.inc"); }

NAKED void FUN_080f9c20(Enemy* p) { INCFUNC("asm/func/FUN_080f9c20.inc"); }

NAKED void FUN_080f9e34(Enemy* p) { INCFUNC("asm/func/FUN_080f9e34.inc"); }

NAKED void FUN_080f9ee0(Enemy* p) { INCFUNC("asm/func/FUN_080f9ee0.inc"); }

NAKED s32 FUN_080f9f20(Enemy* p) { INCFUNC("asm/func/FUN_080f9f20.inc"); }

NAKED s32 FUN_080fa2ac(Enemy* p, Vec3* pos, u32 param_3) { INCFUNC("asm/func/FUN_080fa2ac.inc"); }

NAKED s32 FUN_080fa354(unknown* param_1, u32 param_2, u8 param_3) { INCFUNC("asm/func/FUN_080fa354.inc"); }

NAKED s32 FUN_080fa384(Enemy* p) { INCFUNC("asm/func/FUN_080fa384.inc"); }

NAKED void FUN_080fa77c(Enemy* p) { INCFUNC("asm/func/FUN_080fa77c.inc"); }

NAKED s32 FUN_080fa7a4(Enemy* p) { INCFUNC("asm/func/FUN_080fa7a4.inc"); }

NAKED s32 FUN_080fa958(Vec3* pos) { INCFUNC("asm/func/FUN_080fa958.inc"); }

NAKED bool32 FUN_080faa98(Enemy* p) { INCFUNC("asm/func/FUN_080faa98.inc"); }

NAKED void FUN_080faad8(Enemy* p) { INCFUNC("asm/func/FUN_080faad8.inc"); }

NAKED void FUN_080fadd4(unknown* param_1, unknown* param_2, Enemy* enemy) { INCFUNC("asm/func/FUN_080fadd4.inc"); }

NAKED void FUN_080fae14(HitboxData* a, HitboxData* b, Enemy* enemy) { INCFUNC("asm/func/FUN_080fae14.inc"); }

NAKED void FUN_080fb4d0(unknown* p) { INCFUNC("asm/func/FUN_080fb4d0.inc"); }

NAKED void FUN_080fba28(Enemy* p) { INCFUNC("asm/func/FUN_080fba28.inc"); }

NAKED void FUN_080fba40(Enemy* p) { INCFUNC("asm/func/FUN_080fba40.inc"); }

NAKED void FUN_080fba64(Enemy* p) { INCFUNC("asm/func/FUN_080fba64.inc"); }

NAKED void FUN_080fc0b8(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc0b8.inc"); }

NAKED void FUN_080fc174(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc174.inc"); }

NAKED void FUN_080fc1e4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc1e4.inc"); }

NAKED void FUN_080fc28c(Enemy* p) { INCFUNC("asm/func/FUN_080fc28c.inc"); }

NAKED void FUN_080fc4ec(Enemy* p) { INCFUNC("asm/func/FUN_080fc4ec.inc"); }

NAKED void FUN_080fc548(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc548.inc"); }

NAKED void FUN_080fc6f4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc6f4.inc"); }

NAKED void FUN_080fd08c(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fd08c.inc"); }

NAKED void FUN_080fe1bc(Enemy* p) { INCFUNC("asm/func/FUN_080fe1bc.inc"); }

NAKED void FUN_080fe274(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fe274.inc"); }

NAKED void FUN_080fe704(Enemy* p) { INCFUNC("asm/func/FUN_080fe704.inc"); }

NAKED void FUN_080fe7f4(Enemy* p) { INCFUNC("asm/func/FUN_080fe7f4.inc"); }

NAKED void FUN_080ff05c(unknown* p) { INCFUNC("asm/func/FUN_080ff05c.inc"); }

NAKED void FUN_080ff06c(unknown* p) { INCFUNC("asm/func/FUN_080ff06c.inc"); }

NAKED void FUN_080ff270(unknown* p) { INCFUNC("asm/func/FUN_080ff270.inc"); }
