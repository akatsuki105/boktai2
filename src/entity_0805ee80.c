#include "boss/shademan.h"
#include "entity.h"
#include "global.h"

void FUN_0805eb58(Entity0805ee80*, Entity0805ee80Elem*, s32);
void FUN_0805eb5c(Entity0805ee80*, Entity0805ee80Elem*, s32);
void FUN_0805ebf4(Entity0805ee80*, Entity0805ee80Elem*, s32);
void FUN_0805ec20(Entity0805ee80*, Entity0805ee80Elem*, s32);
void FUN_0805ecb4(Entity0805ee80*, Entity0805ee80Elem*, s32);
void FUN_0805ed84(Entity0805ee80*, Entity0805ee80Elem*, s32);

void (*const PTR_ARRAY_085aba70[6])(Entity0805ee80*, Entity0805ee80Elem*, s32) = {
    FUN_0805eb58,
    FUN_0805eb5c,
    FUN_0805ebf4,
    FUN_0805ec20,
    FUN_0805ecb4,
    FUN_0805ed84,
};  // 0x085ABA70

NAKED s32 Entity0805ee80_InitElem(Entity0805ee80* p, Entity0805ee80Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805ee80_InitElem.inc"); }

NAKED void Entity0805ee80_RemoveElem(Entity0805ee80* p, Entity0805ee80Elem* elem) { INCFUNC("asm/func/Entity0805ee80_RemoveElem.inc"); }

NAKED void FUN_0805eb58(Entity0805ee80* p, Entity0805ee80Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805eb58.inc"); }

NAKED void FUN_0805eb5c(Entity0805ee80* p, Entity0805ee80Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805eb5c.inc"); }

NAKED void FUN_0805ebf4(Entity0805ee80* p, Entity0805ee80Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805ebf4.inc"); }

NAKED void FUN_0805ec20(Entity0805ee80* p, Entity0805ee80Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805ec20.inc"); }

NAKED void FUN_0805ecb4(Entity0805ee80* p, Entity0805ee80Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805ecb4.inc"); }

NAKED void FUN_0805ed84(Entity0805ee80* p, Entity0805ee80Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805ed84.inc"); }

NAKED s32 Entity0805ee80_Update(Entity0805ee80* p) { INCFUNC("asm/func/Entity0805ee80_Update.inc"); }

NAKED s32 Entity0805ee80_Destroy(Entity0805ee80* p) { INCFUNC("asm/func/Entity0805ee80_Destroy.inc"); }

NAKED s32 Entity0805ee80_Init(Entity0805ee80* p, s32 param_1) { INCFUNC("asm/func/Entity0805ee80_Init.inc"); }

NAKED Entity0805ee80* Entity0805ee80_Create(s32 param_1) { INCFUNC("asm/func/Entity0805ee80_Create.inc"); }

NAKED Entity0805ee80Elem* Entity0805ee80_FindFreeElem(Entity0805ee80* p) { INCFUNC("asm/func/Entity0805ee80_FindFreeElem.inc"); }

NAKED s32 FUN_0805eee4(Entity0805ee80* p, u32 angle, s32 param_3, s32 power, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, Vec3* pos) { INCFUNC("asm/func/FUN_0805eee4.inc"); }

NAKED s32 FUN_0805ef68(Entity0805ee80* p, u32 angle, s32 param_3, s32 power, s32 param_5, s32 param_6, s32 param_7, s32 param_8, Vec3* pos) { INCFUNC("asm/func/FUN_0805ef68.inc"); }
