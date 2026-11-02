#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  Enemy e;
  u8 unk_654[64];
} Mimic;
static_assert(sizeof(Mimic) == 1684);

NAKED void FUN_081467bc(Mimic* p) { INCFUNC("asm/func/FUN_081467bc.inc"); }

NAKED void FUN_081468c8(Mimic* p) { INCFUNC("asm/func/FUN_081468c8.inc"); }

NAKED void FUN_08146970(Mimic* p) { INCFUNC("asm/func/FUN_08146970.inc"); }

NAKED void FUN_08146a34(Mimic* p) { INCFUNC("asm/func/FUN_08146a34.inc"); }

NAKED void FUN_08146ae8(Mimic* p) { INCFUNC("asm/func/FUN_08146ae8.inc"); }

NAKED void FUN_08146ce0(Mimic* p) { INCFUNC("asm/func/FUN_08146ce0.inc"); }

void (*const PTR_ARRAY_085ad874[18])(Mimic*) = {
    FUN_081467bc,
    (void*)FUN_080f2864,
    FUN_081468c8,
    (void*)FUN_080f2364,
    NULL,
    (void*)FUN_080f2ec0,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    FUN_08146ce0,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_08146a34,
    FUN_08146ae8,
    FUN_08146970,
};  // 0x085AD874

NAKED void FUN_08146fac(Mimic* p) { INCFUNC("asm/func/FUN_08146fac.inc"); }

NAKED s32 FUN_08146fc0(Mimic* p) { INCFUNC("asm/func/FUN_08146fc0.inc"); }

NAKED void FUN_08146fcc(Mimic* p) { INCFUNC("asm/func/FUN_08146fcc.inc"); }

NAKED void FUN_08147030(Mimic* p) { INCFUNC("asm/func/FUN_08147030.inc"); }

NAKED void FUN_081473ac(Mimic* p) { INCFUNC("asm/func/FUN_081473ac.inc"); }

NAKED void FUN_08147428(Mimic* p) { INCFUNC("asm/func/FUN_08147428.inc"); }

NAKED void FUN_081474e8(Mimic* p) { INCFUNC("asm/func/FUN_081474e8.inc"); }

NAKED void FUN_08147530(Mimic* p, s32 param_2) { INCFUNC("asm/func/FUN_08147530.inc"); }

NAKED void FUN_081475b8(Mimic* p) { INCFUNC("asm/func/FUN_081475b8.inc"); }

NAKED void FUN_081477dc(Mimic* p) { INCFUNC("asm/func/FUN_081477dc.inc"); }

NAKED void FUN_08147a38(Mimic* p) { INCFUNC("asm/func/FUN_08147a38.inc"); }

NAKED void FUN_08147bc0(HitboxData* a, HitboxData* b, Mimic* p) { INCFUNC("asm/func/FUN_08147bc0.inc"); }

NAKED void FUN_08147c00(HitboxData* a, HitboxData* b, Mimic* p) { INCFUNC("asm/func/FUN_08147c00.inc"); }

NAKED void FUN_081482bc(Mimic* p) { INCFUNC("asm/func/FUN_081482bc.inc"); }

NAKED void FUN_0814830c(Mimic* p) { INCFUNC("asm/func/FUN_0814830c.inc"); }

NAKED void FUN_0814842c(Mimic* p) { INCFUNC("asm/func/FUN_0814842c.inc"); }

NAKED bool32 FUN_081484b8(Mimic* p) { INCFUNC("asm/func/FUN_081484b8.inc"); }

NAKED bool32 FUN_0814856c(Mimic* p) { INCFUNC("asm/func/FUN_0814856c.inc"); }

NAKED bool32 FUN_08148638(Mimic* p) { INCFUNC("asm/func/FUN_08148638.inc"); }

NAKED void FUN_081486d8(Mimic* p) { INCFUNC("asm/func/FUN_081486d8.inc"); }

NAKED u32 FUN_08148750(u32 angle) { INCFUNC("asm/func/FUN_08148750.inc"); }

NAKED void FUN_08148780(void) { INCFUNC("asm/func/FUN_08148780.inc"); }

NAKED bool32 FUN_08148784(Mimic* p) { INCFUNC("asm/func/FUN_08148784.inc"); }

NAKED void FUN_081488bc(Mimic* p) { INCFUNC("asm/func/FUN_081488bc.inc"); }

NAKED bool32 FUN_081489a0(Mimic* p) { INCFUNC("asm/func/FUN_081489a0.inc"); }

NAKED void FUN_081489ec(Mimic* p) { INCFUNC("asm/func/FUN_081489ec.inc"); }

NAKED void FUN_081489f0(Mimic* p) { INCFUNC("asm/func/FUN_081489f0.inc"); }

NAKED bool32 FUN_08148af4(Mimic* p) { INCFUNC("asm/func/FUN_08148af4.inc"); }

NAKED void FUN_08148c00(Mimic* p) { INCFUNC("asm/func/FUN_08148c00.inc"); }

void (*const PTR_ARRAY_085ad8bc[1])(Mimic*) = {
    FUN_08148c00,
};  // 0x085AD8BC

NAKED void FUN_08148c6c(Mimic* p) { INCFUNC("asm/func/FUN_08148c6c.inc"); }

NAKED s32 FUN_08148c7c(Mimic* p) { INCFUNC("asm/func/FUN_08148c7c.inc"); }

NAKED void FUN_08148cb4(Mimic* p) { INCFUNC("asm/func/FUN_08148cb4.inc"); }

NAKED s32 EnemyMimic_Destroy(Mimic* p) { INCFUNC("asm/func/EnemyMimic_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 EnemyMimic_Init(Mimic* p) { INCFUNC("asm/func/EnemyMimic_Init.inc"); }

NAKED void EnemyMimic_Create(void) { INCFUNC("asm/func/EnemyMimic_Create.inc"); }
