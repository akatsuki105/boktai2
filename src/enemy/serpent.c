#include "enemy.h"
#include "global.h"
#include "malloc.h"

// 中ボス, ENEK_SERPENT(ENEID_SERPENT)
typedef struct {
  Enemy e;
  u8 unk_654[3988 - sizeof(Enemy)];
} Serpent;
static_assert(sizeof(Serpent) == 3988);

void FUN_0818bc28(Serpent*);
void FUN_0818b818(Serpent*);
void FUN_0818b4a8(Serpent*);
void FUN_0818c1bc(Serpent*);
void FUN_0818bee0(Serpent*);
void FUN_0818bdf0(Serpent*);
void FUN_0818c3bc(Serpent*);
void FUN_0818cb5c(Serpent*);
void FUN_0818cfb8(Serpent*);
void FUN_0818d3d8(Serpent*);
void FUN_0818d804(Serpent*);
void FUN_0818dd0c(Serpent*);
void FUN_0818c894(Serpent*);
void FUN_0818de20(Serpent*);
void FUN_0818c080(Serpent*);
void FUN_0818e158(Serpent*);
void FUN_0818d5b0(Serpent*);
void FUN_0818c31c(Serpent*);

// clang-format off
void (*const PTR_ARRAY_085adcf4[24])(Serpent*) = {
    FUN_0818bc28,
    FUN_0818b818,
    FUN_0818b4a8,
    (void*)FUN_080f2364,
    FUN_0818c1bc,
    FUN_0818bee0,
    FUN_0818bdf0,
    NULL,
    NULL,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    FUN_0818c3bc,
    FUN_0818cb5c,
    FUN_0818cfb8,
    FUN_0818d3d8,
    FUN_0818d804,
    FUN_0818dd0c,
    FUN_0818c894,
    FUN_0818de20,
    FUN_0818c080,
    FUN_0818e158,
    FUN_0818d5b0,
    FUN_0818c31c,
};  // 0x085ADCF4
// clang-format on

const u32 u32_ARRAY_085add54[4] = {16, 16, 19, 24};  // 0x085ADD54

void FUN_08193ca4(Serpent*);
void FUN_08193dc8(Serpent*);
void FUN_08193fa4(Serpent*);
void FUN_081940d8(Serpent*);

void (*const PTR_ARRAY_085add64[4])(Serpent*) = {
    FUN_08193ca4,
    FUN_08193dc8,
    FUN_08193fa4,
    FUN_081940d8,
};  // 0x085ADD64

void FUN_0818e2b8(Serpent*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085add74[7])(Serpent*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_0818e2b8,
};  // 0x085ADD74

const s32 s32_ARRAY_085add90[6] = {-100, 0, 100, -70, 0, 130};  // 0x085ADD90

NAKED void Serpent_OnHit(HitboxData* a, HitboxData* b, Serpent* p) { INCFUNC("asm/func/Serpent_OnHit.inc"); }

NAKED void Serpent_OnHurt(HitboxData* a, HitboxData* b, Serpent* p) { INCFUNC("asm/func/Serpent_OnHurt.inc"); }

NAKED void FUN_08189104(Serpent* p) { INCFUNC("asm/func/FUN_08189104.inc"); }

NAKED void FUN_081892fc(Serpent* p) { INCFUNC("asm/func/FUN_081892fc.inc"); }

NAKED void FUN_081894fc(Serpent* p) { INCFUNC("asm/func/FUN_081894fc.inc"); }

NAKED void FUN_08189608(Serpent* p) { INCFUNC("asm/func/FUN_08189608.inc"); }

NAKED void FUN_0818960c(Serpent* p) { INCFUNC("asm/func/FUN_0818960c.inc"); }

NAKED void FUN_08189610(Serpent* p) { INCFUNC("asm/func/FUN_08189610.inc"); }

NAKED void FUN_08189614(Serpent* p) { INCFUNC("asm/func/FUN_08189614.inc"); }

NAKED void FUN_08189958(Serpent* p, s32 timer) { INCFUNC("asm/func/FUN_08189958.inc"); }

NAKED void FUN_08189bb4(Serpent* p, s32 timer) { INCFUNC("asm/func/FUN_08189bb4.inc"); }

NAKED void FUN_0818a47c(Serpent* p) { INCFUNC("asm/func/FUN_0818a47c.inc"); }

NAKED void FUN_0818a604(Serpent* p) { INCFUNC("asm/func/FUN_0818a604.inc"); }

NAKED void FUN_0818a7e4(Serpent* p) { INCFUNC("asm/func/FUN_0818a7e4.inc"); }

NAKED void FUN_0818a904(Serpent* p, s32 timer) { INCFUNC("asm/func/FUN_0818a904.inc"); }

NAKED void FUN_0818abd4(Serpent* p) { INCFUNC("asm/func/FUN_0818abd4.inc"); }

NAKED void FUN_0818adc4(Serpent* p, s32 timer) { INCFUNC("asm/func/FUN_0818adc4.inc"); }

NAKED void FUN_0818afc0(Serpent* p) { INCFUNC("asm/func/FUN_0818afc0.inc"); }

NAKED void Serpent_StateDamaged(Serpent* p) { INCFUNC("asm/func/Serpent_StateDamaged.inc"); }

NAKED void Serpent_StateDying(Serpent* p, s32 timer) { INCFUNC("asm/func/Serpent_StateDying.inc"); }

NAKED void FUN_0818b4a8(Serpent* p) { INCFUNC("asm/func/FUN_0818b4a8.inc"); }

NAKED void FUN_0818b818(Serpent* p) { INCFUNC("asm/func/FUN_0818b818.inc"); }

NAKED void FUN_0818bc28(Serpent* p) { INCFUNC("asm/func/FUN_0818bc28.inc"); }

NAKED void FUN_0818bdf0(Serpent* p) { INCFUNC("asm/func/FUN_0818bdf0.inc"); }

NAKED void FUN_0818bee0(Serpent* p) { INCFUNC("asm/func/FUN_0818bee0.inc"); }

NAKED void FUN_0818c080(Serpent* p) { INCFUNC("asm/func/FUN_0818c080.inc"); }

NAKED void FUN_0818c1bc(Serpent* p) { INCFUNC("asm/func/FUN_0818c1bc.inc"); }

NAKED void FUN_0818c31c(Serpent* p) { INCFUNC("asm/func/FUN_0818c31c.inc"); }

NAKED void FUN_0818c3bc(Serpent* p) { INCFUNC("asm/func/FUN_0818c3bc.inc"); }

NAKED void FUN_0818c894(Serpent* p) { INCFUNC("asm/func/FUN_0818c894.inc"); }

NAKED void FUN_0818cb5c(Serpent* p) { INCFUNC("asm/func/FUN_0818cb5c.inc"); }

NAKED void FUN_0818cfb8(Serpent* p) { INCFUNC("asm/func/FUN_0818cfb8.inc"); }

NAKED void FUN_0818d3d8(Serpent* p) { INCFUNC("asm/func/FUN_0818d3d8.inc"); }

NAKED void FUN_0818d5b0(Serpent* p) { INCFUNC("asm/func/FUN_0818d5b0.inc"); }

NAKED void FUN_0818d804(Serpent* p) { INCFUNC("asm/func/FUN_0818d804.inc"); }

NAKED void FUN_0818dd0c(Serpent* p) { INCFUNC("asm/func/FUN_0818dd0c.inc"); }

NAKED void FUN_0818de20(Serpent* p) { INCFUNC("asm/func/FUN_0818de20.inc"); }

NAKED void FUN_0818e158(Serpent* p) { INCFUNC("asm/func/FUN_0818e158.inc"); }

NAKED void FUN_0818e2a4(Serpent* p) { INCFUNC("asm/func/FUN_0818e2a4.inc"); }

NAKED void FUN_0818e2b8(Serpent* p, u16* msg) { INCFUNC("asm/func/FUN_0818e2b8.inc"); }

NAKED void FUN_0818e30c(Serpent* p) { INCFUNC("asm/func/FUN_0818e30c.inc"); }

NAKED s32 FUN_0818e524(Serpent* p, s32 dir) { INCFUNC("asm/func/FUN_0818e524.inc"); }

NAKED void Serpent_GetAnimVariant(u16 angle, u32* variant, u32* xflip) { INCFUNC("asm/func/Serpent_GetAnimVariant.inc"); }

NAKED void FUN_0818e6fc(Serpent* p) { INCFUNC("asm/func/FUN_0818e6fc.inc"); }

NAKED void FUN_0818ee24(Serpent* p, Vec3* pos) { INCFUNC("asm/func/FUN_0818ee24.inc"); }

NAKED void FUN_0818ee98(Serpent* p, SpriteID32 sprite, u32 param_3, u32 angle) { INCFUNC("asm/func/FUN_0818ee98.inc"); }

NAKED s32 FUN_0818f008(Serpent* p) { INCFUNC("asm/func/FUN_0818f008.inc"); }

NAKED void FUN_0818f17c(Serpent* p, s32 idx) { INCFUNC("asm/func/FUN_0818f17c.inc"); }

NAKED void FUN_0818f1e4(Serpent* p, s32 idx) { INCFUNC("asm/func/FUN_0818f1e4.inc"); }

NAKED void FUN_0818f3ac(Serpent* p, s32 idx) { INCFUNC("asm/func/FUN_0818f3ac.inc"); }

NAKED void FUN_0818f574(Serpent* p, s32 timer) { INCFUNC("asm/func/FUN_0818f574.inc"); }

NAKED void FUN_0818f5f4(Serpent* p, s32 idx, s32 variant, s32 flags) { INCFUNC("asm/func/FUN_0818f5f4.inc"); }

NAKED void FUN_0818f7b4(Serpent* p) { INCFUNC("asm/func/FUN_0818f7b4.inc"); }

NAKED void FUN_0818f808(Serpent* p) { INCFUNC("asm/func/FUN_0818f808.inc"); }

NAKED void FUN_0818f844(Serpent* p, s32 idx, Vec3* pos) { INCFUNC("asm/func/FUN_0818f844.inc"); }

NAKED void FUN_0818f864(Serpent* p) { INCFUNC("asm/func/FUN_0818f864.inc"); }

NAKED void FUN_0818f918(Serpent* p) { INCFUNC("asm/func/FUN_0818f918.inc"); }

NAKED void FUN_0818f938(Serpent* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0818f938.inc"); }

NAKED void FUN_0818f994(Serpent* p) { INCFUNC("asm/func/FUN_0818f994.inc"); }

NAKED void FUN_0818f9ac(Serpent* p) { INCFUNC("asm/func/FUN_0818f9ac.inc"); }

NAKED void FUN_0818fa70(Serpent* p, Vec3* pos, s32 idx) { INCFUNC("asm/func/FUN_0818fa70.inc"); }

NAKED void FUN_0818faf0(Serpent* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0818faf0.inc"); }

NAKED void FUN_0818fc2c(Serpent* p, Vec3* from, Vec3* to, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_0818fc2c.inc"); }

NAKED void FUN_0818fdd8(Serpent* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0818fdd8.inc"); }

NAKED void FUN_0819014c(Serpent* p, Vec3* pos) { INCFUNC("asm/func/FUN_0819014c.inc"); }

NAKED void Serpent_InitHitboxes(Serpent* p) { INCFUNC("asm/func/Serpent_InitHitboxes.inc"); }

NAKED void Serpent_OnReset(Serpent* p) { INCFUNC("asm/func/Serpent_OnReset.inc"); }

NAKED void FUN_08190364(Serpent* p) { INCFUNC("asm/func/FUN_08190364.inc"); }

NAKED void FUN_081905c8(Serpent* p) { INCFUNC("asm/func/FUN_081905c8.inc"); }

NAKED s32 FUN_08190634(Serpent* p) { INCFUNC("asm/func/FUN_08190634.inc"); }

NAKED void FUN_081906d4(Serpent* p) { INCFUNC("asm/func/FUN_081906d4.inc"); }

NAKED void FUN_0819076c(Serpent* p) { INCFUNC("asm/func/FUN_0819076c.inc"); }

NAKED void FUN_08190804(Serpent* p, s32 param_2) { INCFUNC("asm/func/FUN_08190804.inc"); }

NAKED void FUN_08190824(Serpent* p) { INCFUNC("asm/func/FUN_08190824.inc"); }

NAKED void FUN_08190974(Serpent* p) { INCFUNC("asm/func/FUN_08190974.inc"); }

NAKED void FUN_08190ae0(Serpent* p) { INCFUNC("asm/func/FUN_08190ae0.inc"); }

NAKED void FUN_08190c00(Serpent* p) { INCFUNC("asm/func/FUN_08190c00.inc"); }

NAKED void FUN_08190c94(Serpent* p, HitboxData* hb, unknown* seg) { INCFUNC("asm/func/FUN_08190c94.inc"); }

NAKED void FUN_08190d18(HitboxData* a, HitboxData* b, unknown* seg) { INCFUNC("asm/func/FUN_08190d18.inc"); }

NAKED void FUN_08190d1c(HitboxData* a, HitboxData* b, unknown* seg) { INCFUNC("asm/func/FUN_08190d1c.inc"); }

NAKED void FUN_08190f34(Serpent* p) { INCFUNC("asm/func/FUN_08190f34.inc"); }

NAKED void FUN_08190fb8(Serpent* p) { INCFUNC("asm/func/FUN_08190fb8.inc"); }

NAKED void Serpent_InitAnims(Serpent* p) { INCFUNC("asm/func/Serpent_InitAnims.inc"); }

NAKED s32 Serpent_GetMoveSpeed(Serpent* p) { INCFUNC("asm/func/Serpent_GetMoveSpeed.inc"); }

NAKED void FUN_08191294(Serpent* p) { INCFUNC("asm/func/FUN_08191294.inc"); }

NAKED void FUN_08191774(Serpent* p, s32 idx, s32 param_3) { INCFUNC("asm/func/FUN_08191774.inc"); }

NAKED void FUN_08191a14(Vec3* pos, s32 param_2) { INCFUNC("asm/func/FUN_08191a14.inc"); }

NAKED void FUN_08191a9c(Serpent* p) { INCFUNC("asm/func/FUN_08191a9c.inc"); }

NAKED void FUN_08191ca0(Serpent* p, s32 idx) { INCFUNC("asm/func/FUN_08191ca0.inc"); }

NAKED void FUN_08191ee0(WorldPos* pos) { INCFUNC("asm/func/FUN_08191ee0.inc"); }

NAKED void FUN_0819204c(Serpent* p) { INCFUNC("asm/func/FUN_0819204c.inc"); }

NAKED void FUN_0819208c(Serpent* p) { INCFUNC("asm/func/FUN_0819208c.inc"); }

NAKED bool8 FUN_081920c4(Serpent* p, u32 param_2) { INCFUNC("asm/func/FUN_081920c4.inc"); }

NAKED void FUN_081920f4(Serpent* p, s32 param_2) { INCFUNC("asm/func/FUN_081920f4.inc"); }

NAKED void FUN_08192124(Serpent* p) { INCFUNC("asm/func/FUN_08192124.inc"); }

NAKED void FUN_0819218c(Serpent* p) { INCFUNC("asm/func/FUN_0819218c.inc"); }

NAKED bool8 FUN_08192190(Serpent* p) { INCFUNC("asm/func/FUN_08192190.inc"); }

NAKED void FUN_08192278(Serpent* p) { INCFUNC("asm/func/FUN_08192278.inc"); }

NAKED void FUN_0819235c(Serpent* p) { INCFUNC("asm/func/FUN_0819235c.inc"); }

NAKED void FUN_081923e0(Serpent* p) { INCFUNC("asm/func/FUN_081923e0.inc"); }

NAKED bool8 FUN_0819267c(Serpent* p) { INCFUNC("asm/func/FUN_0819267c.inc"); }

NAKED void FUN_08192744(unknown* seg) { INCFUNC("asm/func/FUN_08192744.inc"); }

NAKED void FUN_08192774(Serpent* p) { INCFUNC("asm/func/FUN_08192774.inc"); }

NAKED void FUN_081928e0(Serpent* p) { INCFUNC("asm/func/FUN_081928e0.inc"); }

NAKED void FUN_081929cc(Serpent* p) { INCFUNC("asm/func/FUN_081929cc.inc"); }

NAKED void FUN_08192a14(Serpent* p) { INCFUNC("asm/func/FUN_08192a14.inc"); }

NAKED void FUN_08192ae0(Vec3* pos, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08192ae0.inc"); }

NAKED void FUN_08192bf4(Serpent* p) { INCFUNC("asm/func/FUN_08192bf4.inc"); }

NAKED void FUN_08192db0(Serpent* p, s32 idx, s32 param_3) { INCFUNC("asm/func/FUN_08192db0.inc"); }

NAKED void FUN_08192f64(Serpent* p) { INCFUNC("asm/func/FUN_08192f64.inc"); }

NAKED void FUN_08192fe4(Serpent* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08192fe4.inc"); }

NAKED s32 FUN_08193100(Serpent* p) { INCFUNC("asm/func/FUN_08193100.inc"); }

NAKED void FUN_0819328c(Serpent* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0819328c.inc"); }

NAKED void FUN_08193328(Serpent* p, Vec3* out, Vec3* pos) { INCFUNC("asm/func/FUN_08193328.inc"); }

NAKED void FUN_08193648(Serpent* p, Vec3* out, Vec3* pos) { INCFUNC("asm/func/FUN_08193648.inc"); }

NAKED void FUN_0819394c(Serpent* p) { INCFUNC("asm/func/FUN_0819394c.inc"); }

NAKED void FUN_081939c0(Serpent* p) { INCFUNC("asm/func/FUN_081939c0.inc"); }

NAKED void FUN_081939f8(Serpent* p, s32 param_2) { INCFUNC("asm/func/FUN_081939f8.inc"); }

NAKED bool8 FUN_08193a2c(Serpent* p, s32 param_2) { INCFUNC("asm/func/FUN_08193a2c.inc"); }

NAKED void FUN_08193a60(Serpent* p, Vec3* out, Vec3* pos) { INCFUNC("asm/func/FUN_08193a60.inc"); }

NAKED void FUN_08193b50(Serpent* p, Vec3* out, Vec3* pos, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08193b50.inc"); }

NAKED void FUN_08193ca4(Serpent* p) { INCFUNC("asm/func/FUN_08193ca4.inc"); }

NAKED void FUN_08193dc8(Serpent* p) { INCFUNC("asm/func/FUN_08193dc8.inc"); }

NAKED void FUN_08193fa4(Serpent* p) { INCFUNC("asm/func/FUN_08193fa4.inc"); }

NAKED void FUN_081940d8(Serpent* p) { INCFUNC("asm/func/FUN_081940d8.inc"); }

NAKED void FUN_081941bc(Serpent* p) { INCFUNC("asm/func/FUN_081941bc.inc"); }

NAKED s32 FUN_081941d0(Serpent* p) { INCFUNC("asm/func/FUN_081941d0.inc"); }

NAKED s32 FUN_081941ec(Serpent* p) { INCFUNC("asm/func/FUN_081941ec.inc"); }

NAKED bool8 FUN_08194240(Serpent* p) { INCFUNC("asm/func/FUN_08194240.inc"); }

NAKED s32 FUN_08194264(Serpent* p) { INCFUNC("asm/func/FUN_08194264.inc"); }

NAKED s32 Serpent_Update(Serpent* p) { INCFUNC("asm/func/Serpent_Update.inc"); }

NAKED s32 Serpent_Destroy(Serpent* p) { INCFUNC("asm/func/Serpent_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
NAKED s32 Serpent_Init(Serpent* p) { INCFUNC("asm/func/Serpent_Init.inc"); }

NAKED void Serpent_Create(void) { INCFUNC("asm/func/Serpent_Create.inc"); }

NAKED void FUN_081957c4(Serpent* p) { INCFUNC("asm/func/FUN_081957c4.inc"); }
