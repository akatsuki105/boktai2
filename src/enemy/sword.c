#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "malloc.h"

// ENEK_SWORD, "ソード"という名前の見た目が剣の敵
// variant: ENEID_SWORD, ENEID_SWORD_P
// 技: 接触, 残像, スレイブソード(小さい剣を飛ばして攻撃してくる(こちらの攻撃で弾き返せる))
// これだけ Entity?, 他の Enemy とは全く違う構造なのかもしれない
typedef struct {
  Entity e;                 // 0x00, ENTITY_UNK_8
  u8 unk_18[3316 - 0x018];  // 0x18
} EneSword;
static_assert(sizeof(EneSword) == 3316);

const s32 s32_ARRAY_085add90[6] = {-100, 0, 100, -70, 0, 130};  // 0x085ADD90

void FUN_08198250(EneSword*);
void FUN_08198254(EneSword*);

void (*const PTR_ARRAY_085adda8[2])(EneSword*) = {
    FUN_08198250,
    FUN_08198254,
};  // 0x085ADDA8

void FUN_08199eec(EneSword*);
void FUN_08199ef0(EneSword*);

void (*const PTR_ARRAY_085addb0[2])(EneSword*) = {
    FUN_08199eec,
    FUN_08199ef0,
};  // 0x085ADDB0

NAKED s32 FUN_081958b4(EneSword* p) { INCFUNC("asm/func/FUN_081958b4.inc"); }

NAKED s32 FUN_081958f4(EneSword* p) { INCFUNC("asm/func/FUN_081958f4.inc"); }

NAKED s32 FUN_08195970(EneSword* p) { INCFUNC("asm/func/FUN_08195970.inc"); }

NAKED s32 FUN_081959f0(EneSword* p) { INCFUNC("asm/func/FUN_081959f0.inc"); }

NAKED s32 FUN_08195aac(EneSword* p) { INCFUNC("asm/func/FUN_08195aac.inc"); }

NAKED s32 FUN_08195b30(EneSword* p) { INCFUNC("asm/func/FUN_08195b30.inc"); }

NAKED s32 FUN_08195bb4(EneSword* p) { INCFUNC("asm/func/FUN_08195bb4.inc"); }

NAKED s32 FUN_08195c68(EneSword* p) { INCFUNC("asm/func/FUN_08195c68.inc"); }

NAKED s32 FUN_08195c94(EneSword* p) { INCFUNC("asm/func/FUN_08195c94.inc"); }

NAKED void FUN_08195cd4(EneSword* p) { INCFUNC("asm/func/FUN_08195cd4.inc"); }

NAKED void FUN_08195d5c(EneSword* p) { INCFUNC("asm/func/FUN_08195d5c.inc"); }

NAKED void FUN_08195f1c(EneSword* p) { INCFUNC("asm/func/FUN_08195f1c.inc"); }

NAKED void EneSword_OnHit(Hitbox* a, Hitbox* b, EneSword* p) { INCFUNC("asm/func/EneSword_OnHit.inc"); }

NAKED void EneSword_OnHurt(Hitbox* a, Hitbox* b, EneSword* p) { INCFUNC("asm/func/EneSword_OnHurt.inc"); }

NAKED void FUN_08196358(EneSword* p) { INCFUNC("asm/func/FUN_08196358.inc"); }

NAKED void FUN_08196378(EneSword* p) { INCFUNC("asm/func/FUN_08196378.inc"); }

NAKED void FUN_081963c0(EneSword* p) { INCFUNC("asm/func/FUN_081963c0.inc"); }

NAKED void FUN_081963f0(EneSword* p) { INCFUNC("asm/func/FUN_081963f0.inc"); }

NAKED void FUN_08196420(EneSword* p) { INCFUNC("asm/func/FUN_08196420.inc"); }

NAKED void FUN_08196580(EneSword* p) { INCFUNC("asm/func/FUN_08196580.inc"); }

NAKED void FUN_081965d0(EneSword* p) { INCFUNC("asm/func/FUN_081965d0.inc"); }

NAKED void FUN_08196728(EneSword* p) { INCFUNC("asm/func/FUN_08196728.inc"); }

NAKED void FUN_08196830(EneSword* p) { INCFUNC("asm/func/FUN_08196830.inc"); }

NAKED void FUN_08196894(EneSword* p) { INCFUNC("asm/func/FUN_08196894.inc"); }

NAKED void FUN_08196978(EneSword* p) { INCFUNC("asm/func/FUN_08196978.inc"); }

NAKED void FUN_08196a64(EneSword* p) { INCFUNC("asm/func/FUN_08196a64.inc"); }

NAKED void FUN_08196ab4(EneSword* p) { INCFUNC("asm/func/FUN_08196ab4.inc"); }

NAKED void FUN_08196b08(EneSword* p) { INCFUNC("asm/func/FUN_08196b08.inc"); }

NAKED void FUN_08196bdc(EneSword* p) { INCFUNC("asm/func/FUN_08196bdc.inc"); }

NAKED void FUN_08196c2c(EneSword* p) { INCFUNC("asm/func/FUN_08196c2c.inc"); }

NAKED void FUN_08196d40(EneSword* p) { INCFUNC("asm/func/FUN_08196d40.inc"); }

NAKED void FUN_08196dfc(EneSword* p) { INCFUNC("asm/func/FUN_08196dfc.inc"); }

NAKED void FUN_08196e54(EneSword* p) { INCFUNC("asm/func/FUN_08196e54.inc"); }

NAKED void FUN_08197040(EneSword* p) { INCFUNC("asm/func/FUN_08197040.inc"); }

NAKED void FUN_081970b8(EneSword* p) { INCFUNC("asm/func/FUN_081970b8.inc"); }

NAKED void FUN_08197244(EneSword* p) { INCFUNC("asm/func/FUN_08197244.inc"); }

NAKED void FUN_081972a8(EneSword* p) { INCFUNC("asm/func/FUN_081972a8.inc"); }

NAKED void FUN_0819734c(EneSword* p) { INCFUNC("asm/func/FUN_0819734c.inc"); }

NAKED void FUN_081973e4(EneSword* p) { INCFUNC("asm/func/FUN_081973e4.inc"); }

NAKED void FUN_0819742c(EneSword* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0819742c.inc"); }

NAKED void FUN_081974c4(EneSword* p) { INCFUNC("asm/func/FUN_081974c4.inc"); }

NAKED void FUN_081974f4(EneSword* p, unknown* param_2) { INCFUNC("asm/func/FUN_081974f4.inc"); }

NAKED void FUN_0819750c(EneSword* p, unknown* param_2, u16 param_3) { INCFUNC("asm/func/FUN_0819750c.inc"); }

NAKED void FUN_08197530(EneSword* p) { INCFUNC("asm/func/FUN_08197530.inc"); }

NAKED void FUN_081975b8(EneSword* p) { INCFUNC("asm/func/FUN_081975b8.inc"); }

NAKED void FUN_08197650(EneSword* p) { INCFUNC("asm/func/FUN_08197650.inc"); }

NAKED void FUN_081976c4(EneSword* p) { INCFUNC("asm/func/FUN_081976c4.inc"); }

NAKED void FUN_081976f4(EneSword* p) { INCFUNC("asm/func/FUN_081976f4.inc"); }

NAKED void FUN_08197858(EneSword* p) { INCFUNC("asm/func/FUN_08197858.inc"); }

NAKED void FUN_08197ad4(EneSword* p) { INCFUNC("asm/func/FUN_08197ad4.inc"); }

NAKED void FUN_08197c30(EneSword* p) { INCFUNC("asm/func/FUN_08197c30.inc"); }

NAKED void FUN_08197de8(EneSword* p) { INCFUNC("asm/func/FUN_08197de8.inc"); }

NAKED void FUN_08198250(EneSword* p) { INCFUNC("asm/func/FUN_08198250.inc"); }

NAKED void FUN_08198254(EneSword* p) { INCFUNC("asm/func/FUN_08198254.inc"); }

NAKED void FUN_081982b0(EneSword* p) { INCFUNC("asm/func/FUN_081982b0.inc"); }

NAKED void EneSword_OnSlaveSwordHit(Hitbox* a, Hitbox* b, unknown* p) { INCFUNC("asm/func/EneSword_OnSlaveSwordHit.inc"); }

NAKED void EneSword_OnSlaveSwordHurt(Hitbox* a, Hitbox* b, unknown* p) { INCFUNC("asm/func/EneSword_OnSlaveSwordHurt.inc"); }

NAKED void FUN_08198588(EneSword* p) { INCFUNC("asm/func/FUN_08198588.inc"); }

NAKED void FUN_081985d8(EneSword* p) { INCFUNC("asm/func/FUN_081985d8.inc"); }

NAKED void FUN_08198618(EneSword* p) { INCFUNC("asm/func/FUN_08198618.inc"); }

NAKED void FUN_08198680(EneSword* p) { INCFUNC("asm/func/FUN_08198680.inc"); }

NAKED void FUN_08198720(EneSword* p) { INCFUNC("asm/func/FUN_08198720.inc"); }

NAKED void FUN_08198760(EneSword* p) { INCFUNC("asm/func/FUN_08198760.inc"); }

NAKED void FUN_08198860(EneSword* p) { INCFUNC("asm/func/FUN_08198860.inc"); }

NAKED void FUN_08198898(EneSword* p) { INCFUNC("asm/func/FUN_08198898.inc"); }

NAKED void FUN_081989cc(EneSword* p) { INCFUNC("asm/func/FUN_081989cc.inc"); }

NAKED void FUN_08198a88(EneSword* p) { INCFUNC("asm/func/FUN_08198a88.inc"); }

NAKED void FUN_08198b44(EneSword* p) { INCFUNC("asm/func/FUN_08198b44.inc"); }

NAKED void FUN_08198c28(EneSword* p) { INCFUNC("asm/func/FUN_08198c28.inc"); }

NAKED void FUN_08198d0c(EneSword* p) { INCFUNC("asm/func/FUN_08198d0c.inc"); }

NAKED void FUN_08198e4c(EneSword* p) { INCFUNC("asm/func/FUN_08198e4c.inc"); }

NAKED void FUN_08198fb8(EneSword* p) { INCFUNC("asm/func/FUN_08198fb8.inc"); }

NAKED void FUN_08199064(EneSword* p) { INCFUNC("asm/func/FUN_08199064.inc"); }

NAKED void FUN_08199094(EneSword* p) { INCFUNC("asm/func/FUN_08199094.inc"); }

NAKED void FUN_0819911c(EneSword* p) { INCFUNC("asm/func/FUN_0819911c.inc"); }

NAKED void FUN_081991b0(EneSword* p) { INCFUNC("asm/func/FUN_081991b0.inc"); }

NAKED void FUN_0819926c(EneSword* p) { INCFUNC("asm/func/FUN_0819926c.inc"); }

NAKED void FUN_0819936c(EneSword* p) { INCFUNC("asm/func/FUN_0819936c.inc"); }

NAKED void FUN_081994e8(EneSword* p) { INCFUNC("asm/func/FUN_081994e8.inc"); }

NAKED void FUN_08199568(EneSword* p) { INCFUNC("asm/func/FUN_08199568.inc"); }

NAKED void FUN_081996f0(EneSword* p) { INCFUNC("asm/func/FUN_081996f0.inc"); }

NAKED void FUN_08199824(EneSword* p) { INCFUNC("asm/func/FUN_08199824.inc"); }

NAKED void FUN_081999f4(EneSword* p) { INCFUNC("asm/func/FUN_081999f4.inc"); }

NAKED void FUN_08199a3c(EneSword* p) { INCFUNC("asm/func/FUN_08199a3c.inc"); }

NAKED void FUN_08199aa4(EneSword* p) { INCFUNC("asm/func/FUN_08199aa4.inc"); }

NAKED void FUN_08199c38(EneSword* p) { INCFUNC("asm/func/FUN_08199c38.inc"); }

NAKED void FUN_08199c98(EneSword* p) { INCFUNC("asm/func/FUN_08199c98.inc"); }

NAKED void FUN_08199cf0(EneSword* p) { INCFUNC("asm/func/FUN_08199cf0.inc"); }

NAKED void FUN_08199d48(EneSword* p) { INCFUNC("asm/func/FUN_08199d48.inc"); }

NAKED void FUN_08199da0(EneSword* p) { INCFUNC("asm/func/FUN_08199da0.inc"); }

NAKED void FUN_08199eec(EneSword* p) { INCFUNC("asm/func/FUN_08199eec.inc"); }

NAKED void FUN_08199ef0(EneSword* p) { INCFUNC("asm/func/FUN_08199ef0.inc"); }

NAKED void FUN_08199f44(EneSword* p) { INCFUNC("asm/func/FUN_08199f44.inc"); }

NAKED s32 EneSword_Update(EneSword* p) { INCFUNC("asm/func/EneSword_Update.inc"); }

NAKED s32 EneSword_Destroy(EneSword* p) { INCFUNC("asm/func/EneSword_Destroy.inc"); }

NAKED void FUN_0819a0ac(EneSword* p) { INCFUNC("asm/func/FUN_0819a0ac.inc"); }

NAKED void EneSword_InitSlaveSwords(EneSword* p) { INCFUNC("asm/func/EneSword_InitSlaveSwords.inc"); }

NAKED s32 EneSword_Init(EneSword* p) { INCFUNC("asm/func/EneSword_Init.inc"); }

NAKED EneSword* EneSword_Create(u16 id) { INCFUNC("asm/func/EneSword_Create.inc"); }
