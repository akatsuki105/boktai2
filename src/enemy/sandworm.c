#include "enemy.h"
#include "global.h"
#include "malloc.h"

// 中ボス, ENEK_SANDWORM(ENEID_SANDWORM)
typedef struct {
  Enemy e;
  u8 unk_654[4200 - sizeof(Enemy)];
} Sandworm;
static_assert(sizeof(Sandworm) == 4200);

const STRING_DATA char s_eneinline_08252168[] = "../system/eneinline.h";

void FUN_081730a4(Sandworm*);
void FUN_08173318(Sandworm*);
void FUN_08172848(Sandworm*);
void FUN_08173a28(Sandworm*);
void FUN_081736b0(Sandworm*);
void FUN_0817324c(Sandworm*);
void FUN_08172b4c(Sandworm*);
void FUN_08172df4(Sandworm*);
void FUN_08173b88(Sandworm*);
void FUN_081741f0(Sandworm*);
void FUN_0817456c(Sandworm*);
void FUN_0817497c(Sandworm*);
void FUN_08174ae8(Sandworm*);
void FUN_081750ec(Sandworm*);
void FUN_08173f2c(Sandworm*);
void FUN_08175234(Sandworm*);
void FUN_081738e0(Sandworm*);
void FUN_0817552c(Sandworm*);

// clang-format off
void (*const PTR_ARRAY_085adae4[22])(Sandworm*) = {
    FUN_081730a4,
    FUN_08173318,
    FUN_08172848,
    (void*)FUN_080f2364,
    FUN_08173a28,
    FUN_081736b0,
    FUN_0817324c,
    FUN_08172b4c,
    FUN_08172df4,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    FUN_08173b88,
    FUN_081741f0,
    FUN_0817456c,
    FUN_0817497c,
    FUN_08174ae8,
    FUN_081750ec,
    FUN_08173f2c,
    FUN_08175234,
    FUN_081738e0,
    FUN_0817552c,
};  // 0x085ADAE4
// clang-format on

const u32 u32_ARRAY_085adb3c[4] = {14, 15, 19, 24};  // 0x085ADB3C

void FUN_0817a05c(Sandworm*);

void (*const PTR_ARRAY_085adb4c[1])(Sandworm*) = {
    FUN_0817a05c,
};  // 0x085ADB4C

void FUN_0817568c(Sandworm*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085adb50[7])(Sandworm*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_0817568c,
};  // 0x085ADB50

NAKED void Sandworm_OnHit(HitboxData* a, HitboxData* b, Sandworm* p) { INCFUNC("asm/func/Sandworm_OnHit.inc"); }

NAKED void Sandworm_OnHurt(HitboxData* a, HitboxData* b, Sandworm* p) { INCFUNC("asm/func/Sandworm_OnHurt.inc"); }

NAKED void FUN_08170d4c(Sandworm* p) { INCFUNC("asm/func/FUN_08170d4c.inc"); }

NAKED void FUN_08170f88(Sandworm* p) { INCFUNC("asm/func/FUN_08170f88.inc"); }

NAKED void FUN_08171188(Sandworm* p) { INCFUNC("asm/func/FUN_08171188.inc"); }

NAKED void FUN_08171294(Sandworm* p) { INCFUNC("asm/func/FUN_08171294.inc"); }

NAKED void FUN_08171298(Sandworm* p, s32 timer) { INCFUNC("asm/func/FUN_08171298.inc"); }

NAKED void FUN_08171354(Sandworm* p, s32 timer) { INCFUNC("asm/func/FUN_08171354.inc"); }

NAKED void FUN_081713c4(Sandworm* p, s32 timer) { INCFUNC("asm/func/FUN_081713c4.inc"); }

NAKED void FUN_0817146c(Sandworm* p) { INCFUNC("asm/func/FUN_0817146c.inc"); }

NAKED void FUN_081716cc(Sandworm* p) { INCFUNC("asm/func/FUN_081716cc.inc"); }

NAKED void FUN_08171718(Sandworm* p) { INCFUNC("asm/func/FUN_08171718.inc"); }

NAKED void FUN_081719b4(Sandworm* p) { INCFUNC("asm/func/FUN_081719b4.inc"); }

NAKED void FUN_081719b8(Sandworm* p) { INCFUNC("asm/func/FUN_081719b8.inc"); }

NAKED void FUN_08171ba8(Sandworm* p) { INCFUNC("asm/func/FUN_08171ba8.inc"); }

NAKED void FUN_08171cc8(Sandworm* p, s32 timer) { INCFUNC("asm/func/FUN_08171cc8.inc"); }

NAKED void FUN_08171f98(Sandworm* p) { INCFUNC("asm/func/FUN_08171f98.inc"); }

NAKED void FUN_08172188(Sandworm* p, s32 timer) { INCFUNC("asm/func/FUN_08172188.inc"); }

NAKED void FUN_08172384(Sandworm* p) { INCFUNC("asm/func/FUN_08172384.inc"); }

NAKED void Sandworm_StateDamaged(Sandworm* p) { INCFUNC("asm/func/Sandworm_StateDamaged.inc"); }

NAKED void Sandworm_StateDying(Sandworm* p, s32 timer) { INCFUNC("asm/func/Sandworm_StateDying.inc"); }

NAKED void FUN_08172848(Sandworm* p) { INCFUNC("asm/func/FUN_08172848.inc"); }

NAKED void FUN_08172b4c(Sandworm* p) { INCFUNC("asm/func/FUN_08172b4c.inc"); }

NAKED void FUN_08172df4(Sandworm* p) { INCFUNC("asm/func/FUN_08172df4.inc"); }

NAKED void FUN_081730a4(Sandworm* p) { INCFUNC("asm/func/FUN_081730a4.inc"); }

NAKED void FUN_0817324c(Sandworm* p) { INCFUNC("asm/func/FUN_0817324c.inc"); }

NAKED void FUN_08173318(Sandworm* p) { INCFUNC("asm/func/FUN_08173318.inc"); }

NAKED void FUN_081736b0(Sandworm* p) { INCFUNC("asm/func/FUN_081736b0.inc"); }

NAKED void FUN_081738e0(Sandworm* p) { INCFUNC("asm/func/FUN_081738e0.inc"); }

NAKED void FUN_08173a28(Sandworm* p) { INCFUNC("asm/func/FUN_08173a28.inc"); }

NAKED void FUN_08173b88(Sandworm* p) { INCFUNC("asm/func/FUN_08173b88.inc"); }

NAKED void FUN_08173f2c(Sandworm* p) { INCFUNC("asm/func/FUN_08173f2c.inc"); }

NAKED void FUN_081741f0(Sandworm* p) { INCFUNC("asm/func/FUN_081741f0.inc"); }

NAKED void FUN_0817456c(Sandworm* p) { INCFUNC("asm/func/FUN_0817456c.inc"); }

NAKED void FUN_0817497c(Sandworm* p) { INCFUNC("asm/func/FUN_0817497c.inc"); }

NAKED void FUN_08174ae8(Sandworm* p) { INCFUNC("asm/func/FUN_08174ae8.inc"); }

NAKED void FUN_081750ec(Sandworm* p) { INCFUNC("asm/func/FUN_081750ec.inc"); }

NAKED void FUN_08175234(Sandworm* p) { INCFUNC("asm/func/FUN_08175234.inc"); }

NAKED void FUN_0817552c(Sandworm* p) { INCFUNC("asm/func/FUN_0817552c.inc"); }

NAKED void FUN_08175678(Sandworm* p) { INCFUNC("asm/func/FUN_08175678.inc"); }

NAKED void FUN_0817568c(Sandworm* p, u16* msg) { INCFUNC("asm/func/FUN_0817568c.inc"); }

NAKED void FUN_081756e0(Sandworm* p) { INCFUNC("asm/func/FUN_081756e0.inc"); }

NAKED void Sandworm_GetAnimVariant(u16 angle, u32* variant, u32* xflip) { INCFUNC("asm/func/Sandworm_GetAnimVariant.inc"); }

NAKED void FUN_08175898(Sandworm* p) { INCFUNC("asm/func/FUN_08175898.inc"); }

NAKED void FUN_08176334(Sandworm* p, Vec3* pos) { INCFUNC("asm/func/FUN_08176334.inc"); }

NAKED void FUN_081763a8(Sandworm* p, SpriteID32 spriteId, u32 animFileID, u32 angle) { INCFUNC("asm/func/FUN_081763a8.inc"); }

NAKED void FUN_08176530(Vec3* pos, s32 count) { INCFUNC("asm/func/FUN_08176530.inc"); }

NAKED void FUN_081765f8(Sandworm* p) { INCFUNC("asm/func/FUN_081765f8.inc"); }

NAKED void FUN_08176698(Sandworm* p, Vec3* pos) { INCFUNC("asm/func/FUN_08176698.inc"); }

NAKED void FUN_0817697c(Sandworm* p, Vec3* pos) { INCFUNC("asm/func/FUN_0817697c.inc"); }

NAKED s32 FUN_08176c60(Sandworm* p) { INCFUNC("asm/func/FUN_08176c60.inc"); }

NAKED void FUN_08176e14(Sandworm* p) { INCFUNC("asm/func/FUN_08176e14.inc"); }

NAKED void FUN_08176e6c(Sandworm* p, s32 param_2) { INCFUNC("asm/func/FUN_08176e6c.inc"); }

NAKED void FUN_08176ed4(Sandworm* p, s32 param_2) { INCFUNC("asm/func/FUN_08176ed4.inc"); }

NAKED void FUN_081770d0(Sandworm* p, s32 param_2) { INCFUNC("asm/func/FUN_081770d0.inc"); }

NAKED void FUN_081772cc(Sandworm* p, s32 timer) { INCFUNC("asm/func/FUN_081772cc.inc"); }

NAKED void FUN_0817734c(Sandworm* p, s32 param_2) { INCFUNC("asm/func/FUN_0817734c.inc"); }

NAKED void FUN_08177548(Sandworm* p) { INCFUNC("asm/func/FUN_08177548.inc"); }

NAKED void FUN_0817759c(Sandworm* p) { INCFUNC("asm/func/FUN_0817759c.inc"); }

NAKED void FUN_081775d8(Sandworm* p, s32 param_2, Vec3* pos) { INCFUNC("asm/func/FUN_081775d8.inc"); }

NAKED void FUN_081775f8(Sandworm* p) { INCFUNC("asm/func/FUN_081775f8.inc"); }

NAKED void FUN_081776ac(Sandworm* p) { INCFUNC("asm/func/FUN_081776ac.inc"); }

NAKED void FUN_081776d0(Sandworm* p) { INCFUNC("asm/func/FUN_081776d0.inc"); }

NAKED void FUN_08177724(Sandworm* p) { INCFUNC("asm/func/FUN_08177724.inc"); }

NAKED void FUN_081777d4(Sandworm* p) { INCFUNC("asm/func/FUN_081777d4.inc"); }

NAKED void FUN_08177890(Sandworm* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08177890.inc"); }

NAKED void FUN_081778f0(Sandworm* p) { INCFUNC("asm/func/FUN_081778f0.inc"); }

NAKED void FUN_08177908(Sandworm* p) { INCFUNC("asm/func/FUN_08177908.inc"); }

NAKED void FUN_081779cc(Sandworm* p, Vec3* pos, s32 param_3) { INCFUNC("asm/func/FUN_081779cc.inc"); }

NAKED void FUN_08177a4c(Sandworm* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08177a4c.inc"); }

NAKED void FUN_08177b88(Sandworm* p, Vec3* from, Vec3* to, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08177b88.inc"); }

NAKED void FUN_08177d34(Sandworm* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08177d34.inc"); }

NAKED void FUN_08177f7c(Sandworm* p, Vec3* pos) { INCFUNC("asm/func/FUN_08177f7c.inc"); }

NAKED void Sandworm_InitHitboxes(Sandworm* p) { INCFUNC("asm/func/Sandworm_InitHitboxes.inc"); }

NAKED void Sandworm_OnReset(Sandworm* p) { INCFUNC("asm/func/Sandworm_OnReset.inc"); }

NAKED void FUN_081781a0(Sandworm* p) { INCFUNC("asm/func/FUN_081781a0.inc"); }

NAKED void FUN_08178404(Sandworm* p) { INCFUNC("asm/func/FUN_08178404.inc"); }

NAKED s32 FUN_08178470(Sandworm* p) { INCFUNC("asm/func/FUN_08178470.inc"); }

NAKED void FUN_08178504(Sandworm* p) { INCFUNC("asm/func/FUN_08178504.inc"); }

NAKED void FUN_081785b0(Sandworm* p) { INCFUNC("asm/func/FUN_081785b0.inc"); }

NAKED void FUN_08178640(Sandworm* p, s32 param_2) { INCFUNC("asm/func/FUN_08178640.inc"); }

NAKED void FUN_08178660(Sandworm* p) { INCFUNC("asm/func/FUN_08178660.inc"); }

NAKED void FUN_081787a8(Sandworm* p) { INCFUNC("asm/func/FUN_081787a8.inc"); }

NAKED void FUN_08178914(Sandworm* p) { INCFUNC("asm/func/FUN_08178914.inc"); }

NAKED void FUN_08178a34(Sandworm* p) { INCFUNC("asm/func/FUN_08178a34.inc"); }

NAKED void FUN_08178ac8(Sandworm* p, HitboxData* hb, unknown* seg) { INCFUNC("asm/func/FUN_08178ac8.inc"); }

NAKED void FUN_08178b4c(HitboxData* a, HitboxData* b, unknown* seg) { INCFUNC("asm/func/FUN_08178b4c.inc"); }

NAKED void FUN_08178b50(HitboxData* a, HitboxData* b, unknown* seg) { INCFUNC("asm/func/FUN_08178b50.inc"); }

NAKED void FUN_08178d40(Sandworm* p) { INCFUNC("asm/func/FUN_08178d40.inc"); }

NAKED void FUN_08178dc4(Sandworm* p) { INCFUNC("asm/func/FUN_08178dc4.inc"); }

NAKED void Sandworm_InitAnims(Sandworm* p) { INCFUNC("asm/func/Sandworm_InitAnims.inc"); }

NAKED s32 Sandworm_GetMoveSpeed(Sandworm* p) { INCFUNC("asm/func/Sandworm_GetMoveSpeed.inc"); }

NAKED void FUN_0817909c(Sandworm* p) { INCFUNC("asm/func/FUN_0817909c.inc"); }

NAKED void FUN_081792fc(WorldPos* pos) { INCFUNC("asm/func/FUN_081792fc.inc"); }

NAKED void FUN_08179468(Sandworm* p) { INCFUNC("asm/func/FUN_08179468.inc"); }

NAKED void FUN_081794a8(Sandworm* p) { INCFUNC("asm/func/FUN_081794a8.inc"); }

NAKED bool8 FUN_081794e0(Sandworm* p, u32 param_2) { INCFUNC("asm/func/FUN_081794e0.inc"); }

NAKED void FUN_08179510(Sandworm* p, u32 param_2) { INCFUNC("asm/func/FUN_08179510.inc"); }

NAKED void FUN_08179540(Sandworm* p) { INCFUNC("asm/func/FUN_08179540.inc"); }

NAKED void FUN_081795a8(Sandworm* p) { INCFUNC("asm/func/FUN_081795a8.inc"); }

NAKED bool8 FUN_081795ac(Sandworm* p) { INCFUNC("asm/func/FUN_081795ac.inc"); }

NAKED void FUN_08179694(Sandworm* p) { INCFUNC("asm/func/FUN_08179694.inc"); }

NAKED void FUN_08179778(Sandworm* p) { INCFUNC("asm/func/FUN_08179778.inc"); }

NAKED void FUN_081797f0(Sandworm* p) { INCFUNC("asm/func/FUN_081797f0.inc"); }

NAKED s32 FUN_08179a94(Sandworm* p) { INCFUNC("asm/func/FUN_08179a94.inc"); }

NAKED void FUN_08179c00(unknown* seg) { INCFUNC("asm/func/FUN_08179c00.inc"); }

NAKED void FUN_08179c30(Sandworm* p) { INCFUNC("asm/func/FUN_08179c30.inc"); }

NAKED void FUN_08179d48(Sandworm* p) { INCFUNC("asm/func/FUN_08179d48.inc"); }

NAKED void FUN_08179ef0(Sandworm* p) { INCFUNC("asm/func/FUN_08179ef0.inc"); }

NAKED void FUN_08179f38(Sandworm* p) { INCFUNC("asm/func/FUN_08179f38.inc"); }

NAKED void FUN_0817a05c(Sandworm* p) { INCFUNC("asm/func/FUN_0817a05c.inc"); }

NAKED void FUN_0817a180(Sandworm* p) { INCFUNC("asm/func/FUN_0817a180.inc"); }

NAKED s32 FUN_0817a194(Sandworm* p) { INCFUNC("asm/func/FUN_0817a194.inc"); }

NAKED s32 FUN_0817a1b0(Sandworm* p) { INCFUNC("asm/func/FUN_0817a1b0.inc"); }

NAKED s32 FUN_0817a1f8(Sandworm* p) { INCFUNC("asm/func/FUN_0817a1f8.inc"); }

NAKED s32 FUN_0817a334(Sandworm* p) { INCFUNC("asm/func/FUN_0817a334.inc"); }

NAKED s32 Sandworm_Update(Sandworm* p) { INCFUNC("asm/func/Sandworm_Update.inc"); }

NAKED s32 Sandworm_Destroy(Sandworm* p) { INCFUNC("asm/func/Sandworm_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
NAKED s32 Sandworm_Init(Sandworm* p) { INCFUNC("asm/func/Sandworm_Init.inc"); }

NAKED void Sandworm_Create(void) { INCFUNC("asm/func/Sandworm_Create.inc"); }

NAKED void FUN_0817b848(Sandworm* p) { INCFUNC("asm/func/FUN_0817b848.inc"); }
