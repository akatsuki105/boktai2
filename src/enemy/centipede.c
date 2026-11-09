#include "enemy.h"
#include "global.h"
#include "malloc.h"

// ENEID_CENTIPEDE
typedef struct {
  Enemy e;
  u8 unk_654[2964 - sizeof(Enemy)];
} Centipede;
static_assert(sizeof(Centipede) == 2964);

const STRING_DATA char s_eneinline_08252030[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_08252048[] = "../system/eneinline.h";

void FUN_08134ccc(Centipede*);
void FUN_08134fb4(Centipede*);
void FUN_08134448(Centipede*);
void FUN_0813544c(Centipede*);
void FUN_081352d4(Centipede*);
void FUN_08134e88(Centipede*);
void FUN_08134738(Centipede*);
void FUN_081349dc(Centipede*);

void (*const PTR_ARRAY_085ad72c[12])(Centipede*) = {
    FUN_08134ccc,
    FUN_08134fb4,
    FUN_08134448,
    (void*)FUN_080f2364,
    FUN_0813544c,
    FUN_081352d4,
    FUN_08134e88,
    FUN_08134738,
    FUN_081349dc,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
};  // 0x085AD72C

const u32 u32_ARRAY_085ad75c[4] = {28, 31, 38, 48};  // 0x085AD75C

void FUN_08138b34(Centipede*);

void (*const PTR_ARRAY_085ad76c[1])(Centipede*) = {
    FUN_08138b34,
};  // 0x085AD76C

NAKED void Centipede_OnHit(HitboxData* a, HitboxData* b, Centipede* p) { INCFUNC("asm/func/Centipede_OnHit.inc"); }

NAKED void Centipede_OnHurt(HitboxData* a, HitboxData* b, Centipede* p) { INCFUNC("asm/func/Centipede_OnHurt.inc"); }

NAKED void FUN_08132a24(Centipede* p) { INCFUNC("asm/func/FUN_08132a24.inc"); }

NAKED void FUN_08132c24(Centipede* p) { INCFUNC("asm/func/FUN_08132c24.inc"); }

NAKED void FUN_08132d30(Centipede* p) { INCFUNC("asm/func/FUN_08132d30.inc"); }

NAKED void FUN_08132d34(Centipede* p, s32 timer) { INCFUNC("asm/func/FUN_08132d34.inc"); }

NAKED void FUN_08132df0(Centipede* p, s32 timer) { INCFUNC("asm/func/FUN_08132df0.inc"); }

NAKED void FUN_08132e60(Centipede* p, s32 timer) { INCFUNC("asm/func/FUN_08132e60.inc"); }

NAKED void FUN_08132f08(Centipede* p) { INCFUNC("asm/func/FUN_08132f08.inc"); }

NAKED void FUN_08133168(Centipede* p) { INCFUNC("asm/func/FUN_08133168.inc"); }

NAKED void FUN_081331b4(Centipede* p) { INCFUNC("asm/func/FUN_081331b4.inc"); }

NAKED void FUN_0813344c(Centipede* p, s32 timer) { INCFUNC("asm/func/FUN_0813344c.inc"); }

NAKED void FUN_08133700(Centipede* p) { INCFUNC("asm/func/FUN_08133700.inc"); }

NAKED void FUN_08133820(Centipede* p, s32 timer) { INCFUNC("asm/func/FUN_08133820.inc"); }

NAKED void FUN_08133ad8(Centipede* p) { INCFUNC("asm/func/FUN_08133ad8.inc"); }

NAKED void FUN_08133cd4(Centipede* p, s32 timer) { INCFUNC("asm/func/FUN_08133cd4.inc"); }

NAKED void FUN_08133ed4(Centipede* p) { INCFUNC("asm/func/FUN_08133ed4.inc"); }

NAKED void Centipede_StateDamaged(Centipede* p) { INCFUNC("asm/func/Centipede_StateDamaged.inc"); }

NAKED void Centipede_StateDying(Centipede* p, s32 timer) { INCFUNC("asm/func/Centipede_StateDying.inc"); }

NAKED void FUN_08134448(Centipede* p) { INCFUNC("asm/func/FUN_08134448.inc"); }

NAKED void FUN_08134738(Centipede* p) { INCFUNC("asm/func/FUN_08134738.inc"); }

NAKED void FUN_081349dc(Centipede* p) { INCFUNC("asm/func/FUN_081349dc.inc"); }

NAKED void FUN_08134ccc(Centipede* p) { INCFUNC("asm/func/FUN_08134ccc.inc"); }

NAKED void FUN_08134e88(Centipede* p) { INCFUNC("asm/func/FUN_08134e88.inc"); }

NAKED void FUN_08134fb4(Centipede* p) { INCFUNC("asm/func/FUN_08134fb4.inc"); }

NAKED void FUN_081352d4(Centipede* p) { INCFUNC("asm/func/FUN_081352d4.inc"); }

NAKED void FUN_0813544c(Centipede* p) { INCFUNC("asm/func/FUN_0813544c.inc"); }

NAKED void FUN_081355ac(Centipede* p) { INCFUNC("asm/func/FUN_081355ac.inc"); }

NAKED void Centipede_GetAnimVariant(u16 angle, u32* variant, u32* xflip) { INCFUNC("asm/func/Centipede_GetAnimVariant.inc"); }

NAKED void FUN_081355f0(Centipede* p) { INCFUNC("asm/func/FUN_081355f0.inc"); }

NAKED void FUN_081360d0(Centipede* p, Vec3* pos) { INCFUNC("asm/func/FUN_081360d0.inc"); }

NAKED void FUN_08136140(Centipede* p, SpriteID32 sprite, u32 anim, u32 angle) { INCFUNC("asm/func/FUN_08136140.inc"); }

NAKED void FUN_081362b0(Centipede* p) { INCFUNC("asm/func/FUN_081362b0.inc"); }

NAKED void FUN_0813632c(Centipede* p, s32 param_2) { INCFUNC("asm/func/FUN_0813632c.inc"); }

NAKED void FUN_0813652c(Centipede* p, s32 param_2) { INCFUNC("asm/func/FUN_0813652c.inc"); }

NAKED void FUN_08136720(Centipede* p, s32 timer) { INCFUNC("asm/func/FUN_08136720.inc"); }

NAKED void FUN_081367a0(Centipede* p, s32 param_2, u8 param_3, u32 param_4) { INCFUNC("asm/func/FUN_081367a0.inc"); }

NAKED void FUN_0813697c(Centipede* p) { INCFUNC("asm/func/FUN_0813697c.inc"); }

NAKED void FUN_081369d0(Centipede* p) { INCFUNC("asm/func/FUN_081369d0.inc"); }

NAKED void FUN_08136a0c(Centipede* p) { INCFUNC("asm/func/FUN_08136a0c.inc"); }

NAKED void FUN_08136ac8(Centipede* p) { INCFUNC("asm/func/FUN_08136ac8.inc"); }

NAKED void FUN_08136aec(Centipede* p) { INCFUNC("asm/func/FUN_08136aec.inc"); }

NAKED void FUN_08136b3c(Centipede* p) { INCFUNC("asm/func/FUN_08136b3c.inc"); }

NAKED void FUN_08136be4(Centipede* p) { INCFUNC("asm/func/FUN_08136be4.inc"); }

NAKED void FUN_08136ca0(Centipede* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08136ca0.inc"); }

NAKED void FUN_08136d00(Centipede* p) { INCFUNC("asm/func/FUN_08136d00.inc"); }

NAKED void FUN_08136d18(Centipede* p) { INCFUNC("asm/func/FUN_08136d18.inc"); }

NAKED void FUN_08136de4(Centipede* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08136de4.inc"); }

NAKED void FUN_08136f20(Centipede* p, Vec3* from, Vec3* to, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08136f20.inc"); }

NAKED void FUN_081370f4(Centipede* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_081370f4.inc"); }

NAKED void FUN_08137360(Centipede* p, Vec3* pos) { INCFUNC("asm/func/FUN_08137360.inc"); }

NAKED void Centipede_InitHitboxes(Centipede* p) { INCFUNC("asm/func/Centipede_InitHitboxes.inc"); }

NAKED void Centipede_OnReset(Centipede* p) { INCFUNC("asm/func/Centipede_OnReset.inc"); }

NAKED void FUN_08137580(Centipede* p) { INCFUNC("asm/func/FUN_08137580.inc"); }

NAKED void FUN_081377ec(Centipede* p) { INCFUNC("asm/func/FUN_081377ec.inc"); }

NAKED s32 FUN_08137858(Centipede* p) { INCFUNC("asm/func/FUN_08137858.inc"); }

NAKED void FUN_081378fc(Centipede* p) { INCFUNC("asm/func/FUN_081378fc.inc"); }

NAKED void FUN_081379a4(Centipede* p) { INCFUNC("asm/func/FUN_081379a4.inc"); }

NAKED void FUN_08137a30(Centipede* p, s32 param_2) { INCFUNC("asm/func/FUN_08137a30.inc"); }

NAKED void FUN_08137a50(Centipede* p) { INCFUNC("asm/func/FUN_08137a50.inc"); }

NAKED void FUN_08137bd0(Centipede* p) { INCFUNC("asm/func/FUN_08137bd0.inc"); }

NAKED void FUN_08137d80(Centipede* p) { INCFUNC("asm/func/FUN_08137d80.inc"); }

NAKED void FUN_08137e98(Centipede* p) { INCFUNC("asm/func/FUN_08137e98.inc"); }

NAKED void FUN_08137f2c(HitboxData* a, HitboxData* b, unknown* seg) { INCFUNC("asm/func/FUN_08137f2c.inc"); }

NAKED void FUN_08137f30(HitboxData* a, HitboxData* b, unknown* seg) { INCFUNC("asm/func/FUN_08137f30.inc"); }

NAKED void FUN_08138058(Centipede* p) { INCFUNC("asm/func/FUN_08138058.inc"); }

NAKED void FUN_081380d8(Centipede* p) { INCFUNC("asm/func/FUN_081380d8.inc"); }

NAKED void Centipede_InitAnims(Centipede* p) { INCFUNC("asm/func/Centipede_InitAnims.inc"); }

NAKED s32 Centipede_GetMoveSpeed(Centipede* p) { INCFUNC("asm/func/Centipede_GetMoveSpeed.inc"); }

NAKED void FUN_081382ec(Centipede* p) { INCFUNC("asm/func/FUN_081382ec.inc"); }

NAKED void FUN_08138504(WorldPos* pos) { INCFUNC("asm/func/FUN_08138504.inc"); }

NAKED void FUN_08138678(Centipede* p) { INCFUNC("asm/func/FUN_08138678.inc"); }

NAKED void FUN_08138710(Centipede* p) { INCFUNC("asm/func/FUN_08138710.inc"); }

NAKED bool8 FUN_08138744(Centipede* p, u32 param_2) { INCFUNC("asm/func/FUN_08138744.inc"); }

NAKED void FUN_08138770(Centipede* p, u32 param_2) { INCFUNC("asm/func/FUN_08138770.inc"); }

NAKED void FUN_081387a0(Centipede* p) { INCFUNC("asm/func/FUN_081387a0.inc"); }

NAKED void FUN_08138808(Centipede* p) { INCFUNC("asm/func/FUN_08138808.inc"); }

NAKED bool8 FUN_0813880c(Centipede* p) { INCFUNC("asm/func/FUN_0813880c.inc"); }

NAKED void FUN_081388f4(Centipede* p) { INCFUNC("asm/func/FUN_081388f4.inc"); }

NAKED void FUN_08138998(Centipede* p) { INCFUNC("asm/func/FUN_08138998.inc"); }

NAKED void FUN_08138b34(Centipede* p) { INCFUNC("asm/func/FUN_08138b34.inc"); }

NAKED void FUN_08138c54(Centipede* p) { INCFUNC("asm/func/FUN_08138c54.inc"); }

NAKED s32 FUN_08138c68(Centipede* p) { INCFUNC("asm/func/FUN_08138c68.inc"); }

NAKED s32 FUN_08138c74(Centipede* p) { INCFUNC("asm/func/FUN_08138c74.inc"); }

NAKED bool8 FUN_08138cb0(Centipede* p) { INCFUNC("asm/func/FUN_08138cb0.inc"); }

NAKED s32 FUN_08138de0(Centipede* p) { INCFUNC("asm/func/FUN_08138de0.inc"); }

NAKED s32 Centipede_Update(Centipede* p) { INCFUNC("asm/func/Centipede_Update.inc"); }

NAKED s32 Centipede_Destroy(Centipede* p) { INCFUNC("asm/func/Centipede_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
NAKED s32 Centipede_Init(Centipede* p) { INCFUNC("asm/func/Centipede_Init.inc"); }

NAKED void Centipede_Create(void) { INCFUNC("asm/func/Centipede_Create.inc"); }

NAKED void FUN_0813a160(Centipede* p) { INCFUNC("asm/func/FUN_0813a160.inc"); }

NAKED void FUN_0813a250(Centipede* p, s32 idx, Vec3* pos) { INCFUNC("asm/func/FUN_0813a250.inc"); }
