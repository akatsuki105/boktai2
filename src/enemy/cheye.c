#include "enemy.h"
#include "global.h"
#include "malloc.h"

// 中ボス, シャイアン(ENEID_SHAIAN)
// 攻撃: トマホーク, 回転斬り, 振り下ろし
// HPが減るとアイテムを使おうとする, そのときに怯ませれば妨害できそのアイテムも落とす
typedef struct {
  Enemy e;
  u8 unk_654[2276 - sizeof(Enemy)];
} Shaian;
static_assert(sizeof(Shaian) == 2276);

const STRING_DATA char s_eneinline_08252180[] = "../system/eneinline.h";
const STRING_DATA char s_cheyecom_c_08252198[] = "cheyecom.c";

const u16 u16_ARRAY_085adb6c[16] = {576, 696, 864, 480, 576, 624, 840, 696, 748, 904, 1123, 624, 748, 811, 1092, 904};  // 0x085ADB6C

void FUN_08180ad4(Shaian*);
void FUN_081811b0(Shaian*);

void (*const PTR_ARRAY_085adb8c[2])(Shaian*) = {
    FUN_08180ad4,
    FUN_081811b0,
};  // 0x085ADB8C

void FUN_08181a88(Shaian*);
void FUN_08181c00(Shaian*);
void FUN_08181d78(Shaian*);
void FUN_08181f70(Shaian*);

void (*const PTR_ARRAY_085adb94[4])(Shaian*) = {
    FUN_08181a88,
    FUN_08181c00,
    FUN_08181d78,
    FUN_08181f70,
};  // 0x085ADB94

void FUN_081829e8(Shaian*);
void FUN_0818266c(Shaian*);
void FUN_08182fec(Shaian*);
void FUN_081831c4(Shaian*);
void FUN_0818327c(Shaian*);
void FUN_08182d1c(Shaian*);
void FUN_08182e98(Shaian*);
void FUN_08182de8(Shaian*);
void FUN_08182410(Shaian*);

// clang-format off
void (*const PTR_ARRAY_085adba4[22])(Shaian*) = {
    FUN_081829e8,
    NULL,
    FUN_0818266c,
    (void*)FUN_080f2364,
    NULL,
    (void*)FUN_080f2ec0,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    (void*)FUN_080f31c4,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    (void*)FUN_080f0e78,
    (void*)FUN_080f11d0,
    (void*)FUN_080f12c4,
    FUN_08182fec,
    FUN_081831c4,
    FUN_0818327c,
    FUN_08182d1c,
    FUN_08182e98,
    FUN_08182de8,
    FUN_08182410,
};  // 0x085ADBA4
// clang-format on

NAKED void Shaian_InitAnims(Shaian* p) { INCFUNC("asm/func/Shaian_InitAnims.inc"); }

NAKED void FUN_0817b9e8(Shaian* p) { INCFUNC("asm/func/FUN_0817b9e8.inc"); }

NAKED s32 FUN_0817ba7c(Shaian* p) { INCFUNC("asm/func/FUN_0817ba7c.inc"); }

NAKED bool8 FUN_0817bb7c(Shaian* p) { INCFUNC("asm/func/FUN_0817bb7c.inc"); }

NAKED void FUN_0817bbe0(Shaian* p) { INCFUNC("asm/func/FUN_0817bbe0.inc"); }

NAKED void FUN_0817bbe4(Shaian* p) { INCFUNC("asm/func/FUN_0817bbe4.inc"); }

NAKED s32 Shaian_GetMoveSpeed(Shaian* p) { INCFUNC("asm/func/Shaian_GetMoveSpeed.inc"); }

NAKED s32 FUN_0817bc74(Shaian* p, s32 angle) { INCFUNC("asm/func/FUN_0817bc74.inc"); }

NAKED void FUN_0817c02c(Shaian* p) { INCFUNC("asm/func/FUN_0817c02c.inc"); }

NAKED void FUN_0817c068(Shaian* p) { INCFUNC("asm/func/FUN_0817c068.inc"); }

NAKED s32 FUN_0817c094(Shaian* p, s32 angle) { INCFUNC("asm/func/FUN_0817c094.inc"); }

NAKED bool8 FUN_0817c328(Shaian* p) { INCFUNC("asm/func/FUN_0817c328.inc"); }

NAKED void FUN_0817c44c(Shaian* p) { INCFUNC("asm/func/FUN_0817c44c.inc"); }

NAKED void cheye_0817c5e0(Shaian* p) { INCFUNC("asm/func/cheye_0817c5e0.inc"); }

NAKED void FUN_0817cdb8(Shaian* p) { INCFUNC("asm/func/FUN_0817cdb8.inc"); }

NAKED void Shaian_GetAnimVariant(u16 angle, u32* variant, u32* xflip) { INCFUNC("asm/func/Shaian_GetAnimVariant.inc"); }

NAKED void FUN_0817ce48(Shaian* p) { INCFUNC("asm/func/FUN_0817ce48.inc"); }

NAKED s32 FUN_0817d204(Shaian* p, NavAgent* nav, u32 rangeX, u32 rangeZ, s32 param_5) { INCFUNC("asm/func/FUN_0817d204.inc"); }

NAKED void FUN_0817d6d4(Shaian* p) { INCFUNC("asm/func/FUN_0817d6d4.inc"); }

NAKED void FUN_0817d71c(Shaian* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0817d71c.inc"); }

NAKED s32 FUN_0817d85c(Shaian* p) { INCFUNC("asm/func/FUN_0817d85c.inc"); }

NAKED void FUN_0817da34(Shaian* p) { INCFUNC("asm/func/FUN_0817da34.inc"); }

NAKED void FUN_0817da80(Shaian* p) { INCFUNC("asm/func/FUN_0817da80.inc"); }

NAKED void FUN_0817db8c(Shaian* p, u32 param_2) { INCFUNC("asm/func/FUN_0817db8c.inc"); }

NAKED void FUN_0817dbf0(Shaian* p, rgb555* pltt, u16 plttID) { INCFUNC("asm/func/FUN_0817dbf0.inc"); }

NAKED void FUN_0817dbfc(Shaian* p) { INCFUNC("asm/func/FUN_0817dbfc.inc"); }

NAKED void FUN_0817dd08(Shaian* p) { INCFUNC("asm/func/FUN_0817dd08.inc"); }

NAKED void FUN_0817deb8(Shaian* p) { INCFUNC("asm/func/FUN_0817deb8.inc"); }

NAKED void FUN_0817ded0(Shaian* p) { INCFUNC("asm/func/FUN_0817ded0.inc"); }

NAKED s32 FUN_0817dfcc(Shaian* p) { INCFUNC("asm/func/FUN_0817dfcc.inc"); }

NAKED void FUN_0817e004(Shaian* p, s32 param_2) { INCFUNC("asm/func/FUN_0817e004.inc"); }

NAKED s32 FUN_0817e02c(Shaian* p) { INCFUNC("asm/func/FUN_0817e02c.inc"); }

NAKED void FUN_0817e1a0(Shaian* p) { INCFUNC("asm/func/FUN_0817e1a0.inc"); }

NAKED void FUN_0817e404(Shaian* p) { INCFUNC("asm/func/FUN_0817e404.inc"); }

NAKED void FUN_0817e51c(Shaian* p) { INCFUNC("asm/func/FUN_0817e51c.inc"); }

NAKED void FUN_0817e5dc(Shaian* p) { INCFUNC("asm/func/FUN_0817e5dc.inc"); }

NAKED bool8 FUN_0817e83c(Shaian* p) { INCFUNC("asm/func/FUN_0817e83c.inc"); }

NAKED void FUN_0817e870(Shaian* p) { INCFUNC("asm/func/FUN_0817e870.inc"); }

NAKED void FUN_0817e8a8(Shaian* p, s32 param_2) { INCFUNC("asm/func/FUN_0817e8a8.inc"); }

NAKED s32 FUN_0817e8dc(Shaian* p, s32 param_2) { INCFUNC("asm/func/FUN_0817e8dc.inc"); }

NAKED void FUN_0817e910(Shaian* p, Vec3* out, Vec3* pos, s32 param_4) { INCFUNC("asm/func/FUN_0817e910.inc"); }

NAKED s32 FUN_0817ea84(Shaian* p) { INCFUNC("asm/func/FUN_0817ea84.inc"); }

NAKED s32 FUN_0817eb28(Shaian* p, Vec3* pos) { INCFUNC("asm/func/FUN_0817eb28.inc"); }

NAKED void FUN_0817ec04(Shaian* p, WorldPos* pos) { INCFUNC("asm/func/FUN_0817ec04.inc"); }

NAKED void FUN_0817ecac(Shaian* p) { INCFUNC("asm/func/FUN_0817ecac.inc"); }

NAKED void Shaian_InitHitboxes(Shaian* p) { INCFUNC("asm/func/Shaian_InitHitboxes.inc"); }

NAKED s32 FUN_0817ee6c(Shaian* p) { INCFUNC("asm/func/FUN_0817ee6c.inc"); }

NAKED s32 FUN_0817ee94(Shaian* p) { INCFUNC("asm/func/FUN_0817ee94.inc"); }

NAKED void FUN_0817eeb0(HitboxData* a, HitboxData* b, Shaian* p) { INCFUNC("asm/func/FUN_0817eeb0.inc"); }

NAKED void Shaian_OnHit(HitboxData* a, HitboxData* b, Shaian* p) { INCFUNC("asm/func/Shaian_OnHit.inc"); }

NAKED void Shaian_OnHurt(HitboxData* a, HitboxData* b, Shaian* p) { INCFUNC("asm/func/Shaian_OnHurt.inc"); }

NAKED void FUN_0817fab0(Shaian* p) { INCFUNC("asm/func/FUN_0817fab0.inc"); }

NAKED void FUN_0817fac8(Shaian* p) { INCFUNC("asm/func/FUN_0817fac8.inc"); }

NAKED void FUN_0817fbe0(Shaian* p) { INCFUNC("asm/func/FUN_0817fbe0.inc"); }

NAKED void FUN_0817fc24(Shaian* p) { INCFUNC("asm/func/FUN_0817fc24.inc"); }

NAKED void FUN_0817fc84(Shaian* p) { INCFUNC("asm/func/FUN_0817fc84.inc"); }

NAKED void FUN_0817fd8c(Shaian* p) { INCFUNC("asm/func/FUN_0817fd8c.inc"); }

NAKED void FUN_0817fee4(Shaian* p) { INCFUNC("asm/func/FUN_0817fee4.inc"); }

NAKED void FUN_0818023c(Shaian* p) { INCFUNC("asm/func/FUN_0818023c.inc"); }

NAKED void FUN_08180314(Shaian* p, s32 timer) { INCFUNC("asm/func/FUN_08180314.inc"); }

NAKED void FUN_0818039c(Shaian* p) { INCFUNC("asm/func/FUN_0818039c.inc"); }

NAKED void FUN_0818041c(Shaian* p, s32 timer) { INCFUNC("asm/func/FUN_0818041c.inc"); }

NAKED void FUN_08180494(Shaian* p) { INCFUNC("asm/func/FUN_08180494.inc"); }

NAKED void FUN_081804f8(Shaian* p) { INCFUNC("asm/func/FUN_081804f8.inc"); }

NAKED void FUN_081804fc(Shaian* p) { INCFUNC("asm/func/FUN_081804fc.inc"); }

NAKED void Shaian_StateDamaged(Shaian* p) { INCFUNC("asm/func/Shaian_StateDamaged.inc"); }

NAKED void FUN_0818069c(Shaian* p) { INCFUNC("asm/func/FUN_0818069c.inc"); }

NAKED void FUN_081807dc(Shaian* p) { INCFUNC("asm/func/FUN_081807dc.inc"); }

NAKED void Shaian_StateDying(Shaian* p) { INCFUNC("asm/func/Shaian_StateDying.inc"); }

NAKED void FUN_08180ad4(Shaian* p) { INCFUNC("asm/func/FUN_08180ad4.inc"); }

NAKED void FUN_081811b0(Shaian* p) { INCFUNC("asm/func/FUN_081811b0.inc"); }

NAKED void FUN_08181a78(Shaian* p) { INCFUNC("asm/func/FUN_08181a78.inc"); }

NAKED void FUN_08181a88(Shaian* p) { INCFUNC("asm/func/FUN_08181a88.inc"); }

NAKED void FUN_08181c00(Shaian* p) { INCFUNC("asm/func/FUN_08181c00.inc"); }

NAKED void FUN_08181d78(Shaian* p) { INCFUNC("asm/func/FUN_08181d78.inc"); }

NAKED void FUN_08181f70(Shaian* p) { INCFUNC("asm/func/FUN_08181f70.inc"); }

NAKED void FUN_08182240(Shaian* p) { INCFUNC("asm/func/FUN_08182240.inc"); }

NAKED bool8 FUN_08182254(Shaian* p) { INCFUNC("asm/func/FUN_08182254.inc"); }

NAKED void FUN_08182410(Shaian* p) { INCFUNC("asm/func/FUN_08182410.inc"); }

NAKED void FUN_0818266c(Shaian* p) { INCFUNC("asm/func/FUN_0818266c.inc"); }

NAKED void FUN_081829e8(Shaian* p) { INCFUNC("asm/func/FUN_081829e8.inc"); }

NAKED void FUN_08182d1c(Shaian* p) { INCFUNC("asm/func/FUN_08182d1c.inc"); }

NAKED void FUN_08182de8(Shaian* p) { INCFUNC("asm/func/FUN_08182de8.inc"); }

NAKED void FUN_08182e98(Shaian* p) { INCFUNC("asm/func/FUN_08182e98.inc"); }

NAKED void FUN_08182fec(Shaian* p) { INCFUNC("asm/func/FUN_08182fec.inc"); }

NAKED void FUN_081831c4(Shaian* p) { INCFUNC("asm/func/FUN_081831c4.inc"); }

NAKED void FUN_0818327c(Shaian* p) { INCFUNC("asm/func/FUN_0818327c.inc"); }

NAKED void FUN_08183368(Shaian* p) { INCFUNC("asm/func/FUN_08183368.inc"); }

NAKED s32 FUN_0818337c(Shaian* p) { INCFUNC("asm/func/FUN_0818337c.inc"); }

NAKED s32 Shaian_Update(Shaian* p) { INCFUNC("asm/func/Shaian_Update.inc"); }

NAKED s32 Shaian_Destroy(Shaian* p) { INCFUNC("asm/func/Shaian_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
NAKED s32 Shaian_Init(Shaian* p) { INCFUNC("asm/func/Shaian_Init.inc"); }

NAKED void Shaian_Create(void) { INCFUNC("asm/func/Shaian_Create.inc"); }
