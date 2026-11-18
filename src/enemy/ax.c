#include "enemy.h"
#include "global.h"
#include "malloc.h"

// ENEK_AX(見た目が斧の敵)
// variant: ENEID_AX, ENEID_AX_P
// 技: 接触, 回転斬り, 振り下ろし(小), 振り下ろし(大), シャドウアタック
typedef struct {
  Enemy e;
  u8 unk_654[3868 - sizeof(Enemy)];
} EneAx;
static_assert(sizeof(EneAx) == 3868);

const STRING_DATA char s_eneinline_082521a4[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_082521bc[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_082521d4[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_082521ec[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_08252204[] = "../system/eneinline.h";
const STRING_DATA char s_axcom_c_0825221c[] = "axcom.c";

void FUN_0819dc50(EneAx*);
void FUN_0819d89c(EneAx*);
void FUN_0819d664(EneAx*);
void FUN_0819d998(EneAx*);
void FUN_0819db7c(EneAx*);

void (*const sAxHandlerTable2[5])(EneAx*) = {
    FUN_0819dc50,
    FUN_0819d89c,
    FUN_0819d664,
    FUN_0819d998,
    FUN_0819db7c,
};  // 0x085ADDB8

const u16 u16_ARRAY_085addcc[8] = {12, 8, 4, 0, 4, 8, 12, 0};  // 0x085ADDCC

void FUN_081a057c(EneAx*);
void FUN_081a0680(EneAx*);
void FUN_081a0714(EneAx*);
void FUN_081a082c(EneAx*);
void FUN_081a08a4(EneAx*);
void FUN_081a09bc(EneAx*);
void FUN_081a0a34(EneAx*);
void FUN_081a0b70(EneAx*);
void FUN_081a0c2c(EneAx*);
void FUN_081a0d3c(EneAx*);
void FUN_081a1160(EneAx*);

void (*const sAxHandlerTable4[11])(EneAx*) = {
    FUN_081a057c,
    FUN_081a0680,
    FUN_081a0714,
    FUN_081a082c,
    FUN_081a08a4,
    FUN_081a09bc,
    FUN_081a0a34,
    FUN_081a0b70,
    FUN_081a0c2c,
    FUN_081a0d3c,
    FUN_081a1160,
};  // 0x085ADDDC

void Ax_StartChase(EneAx*);
void FUN_081a1630(EneAx*);

void (*const sAxHandlerTable3[2])(EneAx*) = {
    Ax_StartChase,
    FUN_081a1630,
};  // 0x085ADE08

NAKED void FUN_0819aa58(Hitbox* a, Hitbox* b, EneAx* p) { INCFUNC("asm/func/FUN_0819aa58.inc"); }

NAKED void FUN_0819aa5c(Hitbox* a, Hitbox* b, EneAx* p) { INCFUNC("asm/func/FUN_0819aa5c.inc"); }

NAKED void Ax_OnHit(Hitbox* a, Hitbox* b, EneAx* p) { INCFUNC("asm/func/Ax_OnHit.inc"); }

NAKED void Ax_OnHurt(Hitbox* a, Hitbox* b, EneAx* p) { INCFUNC("asm/func/Ax_OnHurt.inc"); }

NAKED void FUN_0819b230(EneAx* p) { INCFUNC("asm/func/FUN_0819b230.inc"); }

NAKED void FUN_0819b35c(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819b35c.inc"); }

NAKED void FUN_0819b478(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819b478.inc"); }

NAKED void FUN_0819baa0(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819baa0.inc"); }

NAKED void FUN_0819bbd8(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819bbd8.inc"); }

NAKED void FUN_0819bca0(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819bca0.inc"); }

NAKED void FUN_0819bd2c(EneAx* p) { INCFUNC("asm/func/FUN_0819bd2c.inc"); }

NAKED void FUN_0819be1c(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819be1c.inc"); }

NAKED void FUN_0819bedc(EneAx* p) { INCFUNC("asm/func/FUN_0819bedc.inc"); }

NAKED void FUN_0819bfa8(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819bfa8.inc"); }

NAKED void FUN_0819c02c(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819c02c.inc"); }

NAKED void FUN_0819c3dc(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819c3dc.inc"); }

NAKED void FUN_0819c4a4(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819c4a4.inc"); }

NAKED void FUN_0819c504(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819c504.inc"); }

NAKED void FUN_0819c5f8(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819c5f8.inc"); }

NAKED void FUN_0819c740(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819c740.inc"); }

NAKED void FUN_0819c7e4(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819c7e4.inc"); }

NAKED void FUN_0819c974(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819c974.inc"); }

NAKED void FUN_0819cc04(EneAx* p) { INCFUNC("asm/func/FUN_0819cc04.inc"); }

NAKED void Ax_StateMove(EneAx* p) { INCFUNC("asm/func/Ax_StateMove.inc"); }

NAKED void Ax_StateWait(EneAx* p) { INCFUNC("asm/func/Ax_StateWait.inc"); }

NAKED void Ax_StateTurn(EneAx* p) { INCFUNC("asm/func/Ax_StateTurn.inc"); }

NAKED void FUN_0819cfcc(EneAx* p, s32 timer) { INCFUNC("asm/func/FUN_0819cfcc.inc"); }

NAKED void Ax_StateDamaged(EneAx* p) { INCFUNC("asm/func/Ax_StateDamaged.inc"); }

NAKED void Ax_StateDying(EneAx* p, s32 timer) { INCFUNC("asm/func/Ax_StateDying.inc"); }

NAKED void FUN_0819d664(EneAx* p) { INCFUNC("asm/func/FUN_0819d664.inc"); }

NAKED void FUN_0819d89c(EneAx* p) { INCFUNC("asm/func/FUN_0819d89c.inc"); }

NAKED void FUN_0819d998(EneAx* p) { INCFUNC("asm/func/FUN_0819d998.inc"); }

NAKED void FUN_0819db7c(EneAx* p) { INCFUNC("asm/func/FUN_0819db7c.inc"); }

NAKED void FUN_0819dc50(EneAx* p) { INCFUNC("asm/func/FUN_0819dc50.inc"); }

NAKED void Ax_SetHandlerTable2(EneAx* p) { INCFUNC("asm/func/Ax_SetHandlerTable2.inc"); }

NAKED void FUN_0819dd10(EneAx* p) { INCFUNC("asm/func/FUN_0819dd10.inc"); }

NAKED void Ax_PickRandomPathNode(EneAx* p) { INCFUNC("asm/func/Ax_PickRandomPathNode.inc"); }

NAKED void Ax_InitHitboxes(EneAx* p) { INCFUNC("asm/func/Ax_InitHitboxes.inc"); }

NAKED s32 Ax_GetMoveSpeed(EneAx* p) { INCFUNC("asm/func/Ax_GetMoveSpeed.inc"); }

NAKED void Ax_StartCurve(EneAx* p, Vec3* pos) { INCFUNC("asm/func/Ax_StartCurve.inc"); }

NAKED bool8 Ax_StepCurve(EneAx* p) { INCFUNC("asm/func/Ax_StepCurve.inc"); }

NAKED void Ax_InitAnims(EneAx* p) { INCFUNC("asm/func/Ax_InitAnims.inc"); }

NAKED void Ax_OnReset(EneAx* p) { INCFUNC("asm/func/Ax_OnReset.inc"); }

NAKED void Ax_ResumeHover(EneAx* p) { INCFUNC("asm/func/Ax_ResumeHover.inc"); }

NAKED void Ax_GetAnimVariant(u16 angle, u32* variant, u32* xflip) { INCFUNC("asm/func/Ax_GetAnimVariant.inc"); }

NAKED void Ax_BeginCurveTo(EneAx* p, Vec3* pos) { INCFUNC("asm/func/Ax_BeginCurveTo.inc"); }

NAKED void Ax_StopChase(EneAx* p) { INCFUNC("asm/func/Ax_StopChase.inc"); }

NAKED void Ax_UpdateChaseTimeout(EneAx* p) { INCFUNC("asm/func/Ax_UpdateChaseTimeout.inc"); }

NAKED void FUN_0819e56c(EneAx* p) { INCFUNC("asm/func/FUN_0819e56c.inc"); }

NAKED void FUN_0819e5f4(EneAx* p) { INCFUNC("asm/func/FUN_0819e5f4.inc"); }

NAKED bool8 FUN_0819e620(EneAx* p) { INCFUNC("asm/func/FUN_0819e620.inc"); }

NAKED void Ax_ClearRecentNodes(EneAx* p) { INCFUNC("asm/func/Ax_ClearRecentNodes.inc"); }

NAKED void Ax_PushRecentNode(EneAx* p, s32 param_2) { INCFUNC("asm/func/Ax_PushRecentNode.inc"); }

NAKED s32 Ax_IsRecentNode(EneAx* p, s32 param_2) { INCFUNC("asm/func/Ax_IsRecentNode.inc"); }

NAKED bool8 Ax_TryDetectPlayer(EneAx* p) { INCFUNC("asm/func/Ax_TryDetectPlayer.inc"); }

NAKED void Ax_OnAttackRequest(EneAx* p) { INCFUNC("asm/func/Ax_OnAttackRequest.inc"); }

NAKED void FUN_0819e88c(EneAx* p) { INCFUNC("asm/func/FUN_0819e88c.inc"); }

NAKED void FUN_0819ea0c(EneAx* p) { INCFUNC("asm/func/FUN_0819ea0c.inc"); }

NAKED void FUN_0819eb30(EneAx* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0819eb30.inc"); }

NAKED s32 FUN_0819ec50(EneAx* p) { INCFUNC("asm/func/FUN_0819ec50.inc"); }

NAKED void FUN_0819edcc(EneAx* p) { INCFUNC("asm/func/FUN_0819edcc.inc"); }

NAKED void Ax_SetAfterimagePltt(EneAx* p, rgb555* pltt) { INCFUNC("asm/func/Ax_SetAfterimagePltt.inc"); }

NAKED void FUN_0819ee40(EneAx* p, unknown* param_2, u16 param_3) { INCFUNC("asm/func/FUN_0819ee40.inc"); }

NAKED void Ax_InitAfterimages(EneAx* p) { INCFUNC("asm/func/Ax_InitAfterimages.inc"); }

NAKED void FUN_0819ef24(EneAx* p) { INCFUNC("asm/func/FUN_0819ef24.inc"); }

NAKED void FUN_0819f150(EneAx* p, unknown* param_2, u8 param_3) { INCFUNC("asm/func/FUN_0819f150.inc"); }

NAKED void Ax_TickAfterimages(EneAx* p) { INCFUNC("asm/func/Ax_TickAfterimages.inc"); }

NAKED void Ax_RemoveAfterimages(EneAx* p) { INCFUNC("asm/func/Ax_RemoveAfterimages.inc"); }

NAKED void Ax_PickFarPathNode(EneAx* p, Vec3* to, Vec3* from, s32 minDist) { INCFUNC("asm/func/Ax_PickFarPathNode.inc"); }

NAKED void FUN_0819f530(EneAx* p, u32 param_2) { INCFUNC("asm/func/FUN_0819f530.inc"); }

NAKED void FUN_0819f694(EneAx* p, Vec3* pos, u32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0819f694.inc"); }

NAKED void FUN_0819f894(EneAx* p) { INCFUNC("asm/func/FUN_0819f894.inc"); }

NAKED s32 FUN_0819f8d8(u32* param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0819f8d8.inc"); }

NAKED s32 FUN_0819f934(u32* param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0819f934.inc"); }

NAKED void FUN_0819f990(EneAx* p) { INCFUNC("asm/func/FUN_0819f990.inc"); }

NAKED void FUN_0819fc5c(EneAx* p) { INCFUNC("asm/func/FUN_0819fc5c.inc"); }

NAKED void FUN_0819fca4(EneAx* p) { INCFUNC("asm/func/FUN_0819fca4.inc"); }

NAKED void FUN_0819fcf0(EneAx* p, Vec3* pos) { INCFUNC("asm/func/FUN_0819fcf0.inc"); }

NAKED void FUN_0819fd0c(EneAx* p, unknown* param_2, u16 param_3) { INCFUNC("asm/func/FUN_0819fd0c.inc"); }

NAKED void FUN_0819fd30(EneAx* p) { INCFUNC("asm/func/FUN_0819fd30.inc"); }

NAKED void FUN_0819fdf0(EneAx* p) { INCFUNC("asm/func/FUN_0819fdf0.inc"); }

NAKED void FUN_0819ff9c(EneAx* p) { INCFUNC("asm/func/FUN_0819ff9c.inc"); }

NAKED void FUN_0819ffc4(EneAx* p) { INCFUNC("asm/func/FUN_0819ffc4.inc"); }

NAKED void FUN_081a0248(EneAx* p) { INCFUNC("asm/func/FUN_081a0248.inc"); }

NAKED void FUN_081a0470(EneAx* p) { INCFUNC("asm/func/FUN_081a0470.inc"); }

NAKED s32 Ax_PreUpdate(EneAx* p) { INCFUNC("asm/func/Ax_PreUpdate.inc"); }

NAKED s32 Ax_PostUpdate(EneAx* p) { INCFUNC("asm/func/Ax_PostUpdate.inc"); }

NAKED void FUN_081a057c(EneAx* p) { INCFUNC("asm/func/FUN_081a057c.inc"); }

NAKED void FUN_081a0680(EneAx* p) { INCFUNC("asm/func/FUN_081a0680.inc"); }

NAKED void FUN_081a0714(EneAx* p) { INCFUNC("asm/func/FUN_081a0714.inc"); }

NAKED void FUN_081a082c(EneAx* p) { INCFUNC("asm/func/FUN_081a082c.inc"); }

NAKED void FUN_081a08a4(EneAx* p) { INCFUNC("asm/func/FUN_081a08a4.inc"); }

NAKED void FUN_081a09bc(EneAx* p) { INCFUNC("asm/func/FUN_081a09bc.inc"); }

NAKED void FUN_081a0a34(EneAx* p) { INCFUNC("asm/func/FUN_081a0a34.inc"); }

NAKED void FUN_081a0b70(EneAx* p) { INCFUNC("asm/func/FUN_081a0b70.inc"); }

NAKED void FUN_081a0c2c(EneAx* p) { INCFUNC("asm/func/FUN_081a0c2c.inc"); }

NAKED void FUN_081a0d3c(EneAx* p) { INCFUNC("asm/func/FUN_081a0d3c.inc"); }

NAKED void FUN_081a1160(EneAx* p) { INCFUNC("asm/func/FUN_081a1160.inc"); }

NAKED void Ax_SetHandlerTable4(EneAx* p) { INCFUNC("asm/func/Ax_SetHandlerTable4.inc"); }

NAKED void Ax_StartChase(EneAx* p) { INCFUNC("asm/func/Ax_StartChase.inc"); }

NAKED void FUN_081a1630(EneAx* p) { INCFUNC("asm/func/FUN_081a1630.inc"); }

NAKED void Ax_SetHandlerTable3(EneAx* p) { INCFUNC("asm/func/Ax_SetHandlerTable3.inc"); }

NAKED bool8 Ax_OnDamaged(EneAx* p) { INCFUNC("asm/func/Ax_OnDamaged.inc"); }

NAKED s32 Ax_UpdateFrame(EneAx* p) { INCFUNC("asm/func/Ax_UpdateFrame.inc"); }

NAKED s32 Ax_Update(EneAx* p) { INCFUNC("asm/func/Ax_Update.inc"); }

NAKED s32 Ax_Destroy(EneAx* p) { INCFUNC("asm/func/Ax_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
NAKED s32 Ax_Init(EneAx* p) { INCFUNC("asm/func/Ax_Init.inc"); }

NAKED void Ax_Create(void) { INCFUNC("asm/func/Ax_Create.inc"); }
