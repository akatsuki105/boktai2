#include "entity.h"
#include "global.h"

// EntityFB53 とは独立した通信まわりのモジュール, FUN_0804e2c0 が Malloc(908) した領域を gUnkEntity1Ptr_03002b58 に持ち、
// PTR_ARRAY_085ab5e0 の 33 状態で回す。スクリプト命令 0x3699 / 0xD935 / 0x025E の入口を持つ

IWRAM_DATA u8 u8_030000dc = 0;    // 0x030000DC
IWRAM_DATA u32 u32_030000e0 = 0;  // 0x030000E0, 型不明

extern const u8 u8_ARRAY_085ab5b0[8];  // src/entity_fb53.c

s32 FUN_0804c3cc(unknown*);
s32 FUN_0804c3e4(unknown*);
s32 FUN_0804c438(unknown*);
s32 FUN_0804c57c(unknown*);
s32 FUN_0804c5c0(unknown*);
s32 FUN_0804c5d8(unknown*);
s32 FUN_0804c650(unknown*);
s32 FUN_0804c6ac(unknown*);
s32 FUN_0804c7c8(unknown*);
s32 FUN_0804c888(unknown*);
s32 FUN_0804c8bc(unknown*);
s32 FUN_0804c8f4(unknown*);
s32 FUN_0804c940(unknown*);
s32 FUN_0804c978(unknown*);
s32 FUN_0804c9a8(unknown*);
s32 FUN_0804cb6c(unknown*);
s32 FUN_0804cb84(unknown*);
s32 FUN_0804cb9c(unknown*);
s32 FUN_0804cbb4(unknown*);
s32 FUN_0804cbcc(unknown*);
s32 FUN_0804cbfc(unknown*);
s32 FUN_0804cc38(unknown*);
s32 FUN_0804cc7c(unknown*);
s32 FUN_0804cc98(unknown*);
s32 FUN_0804ccbc(unknown*);
s32 FUN_0804d698(unknown*);
s32 FUN_0804d6d0(unknown*);
s32 FUN_0804da50(unknown*);
s32 FUN_0804da78(unknown*);
s32 FUN_0804dae4(unknown*);
s32 FUN_0804de18(unknown*);
s32 FUN_0804de40(unknown*);
s32 FUN_0804de58(unknown*);

s32 (*const PTR_ARRAY_085ab5e0[33])(unknown*) = {
    FUN_0804c3cc, FUN_0804c3e4, FUN_0804c438, FUN_0804c57c, FUN_0804c5c0, FUN_0804c5d8, FUN_0804c650, FUN_0804c6ac, FUN_0804c7c8, FUN_0804c888, FUN_0804c8bc, FUN_0804c8f4, FUN_0804c940, FUN_0804c978, FUN_0804c9a8, FUN_0804cb6c, FUN_0804cb84, FUN_0804cb9c, FUN_0804cbb4, FUN_0804d698, FUN_0804d6d0, FUN_0804da50, FUN_0804de18, FUN_0804da78, FUN_0804de40, FUN_0804dae4, FUN_0804de58, FUN_0804cbcc, FUN_0804cbfc, FUN_0804cc38, FUN_0804cc7c, FUN_0804cc98, FUN_0804ccbc,
};  // 0x085AB5E0

NAKED s32 FUN_0804b9f4(void) { INCFUNC("asm/func/FUN_0804b9f4.inc"); }

NAKED void FUN_0804ba3c(void) { INCFUNC("asm/func/FUN_0804ba3c.inc"); }

NAKED s32 FUN_0804ba48(void) { INCFUNC("asm/func/FUN_0804ba48.inc"); }

NAKED void FUN_0804ba64(s32 param_1) { INCFUNC("asm/func/FUN_0804ba64.inc"); }

NAKED void FUN_0804bb30(s32 param_1) { INCFUNC("asm/func/FUN_0804bb30.inc"); }

NAKED void FUN_0804bb68(s32 param_1, u16 param_2) { INCFUNC("asm/func/FUN_0804bb68.inc"); }

NAKED s32 FUN_0804bb70(s32 param_1) { INCFUNC("asm/func/FUN_0804bb70.inc"); }

NAKED s32 FUN_0804bb98(s32 param_1) { INCFUNC("asm/func/FUN_0804bb98.inc"); }

NAKED s32 FUN_0804bbf8(s32 param_1) { INCFUNC("asm/func/FUN_0804bbf8.inc"); }

NAKED s32 FUN_0804bc10(s32 param_1) { INCFUNC("asm/func/FUN_0804bc10.inc"); }

NAKED void FUN_0804bc28(s32 param_1) { INCFUNC("asm/func/FUN_0804bc28.inc"); }

NAKED s32 FUN_0804bcc8(s32 param_1) { INCFUNC("asm/func/FUN_0804bcc8.inc"); }

NAKED s32 FUN_0804bdd4(s32 param_1) { INCFUNC("asm/func/FUN_0804bdd4.inc"); }

NAKED void FUN_0804bed4(s32 param_1) { INCFUNC("asm/func/FUN_0804bed4.inc"); }

NAKED void FUN_0804bf90(u8 param_1) { INCFUNC("asm/func/FUN_0804bf90.inc"); }

NAKED void FUN_0804c190(u8 param_1) { INCFUNC("asm/func/FUN_0804c190.inc"); }

NAKED void FUN_0804c3a8(void) { INCFUNC("asm/func/FUN_0804c3a8.inc"); }

NAKED void FUN_0804c3b4(void) { INCFUNC("asm/func/FUN_0804c3b4.inc"); }

NAKED s32 FUN_0804c3cc(unknown* p) { INCFUNC("asm/func/FUN_0804c3cc.inc"); }

NAKED s32 FUN_0804c3e4(unknown* p) { INCFUNC("asm/func/FUN_0804c3e4.inc"); }

NAKED s32 FUN_0804c438(unknown* p) { INCFUNC("asm/func/FUN_0804c438.inc"); }

NAKED s32 FUN_0804c57c(unknown* p) { INCFUNC("asm/func/FUN_0804c57c.inc"); }

NAKED s32 FUN_0804c5c0(unknown* p) { INCFUNC("asm/func/FUN_0804c5c0.inc"); }

NAKED s32 FUN_0804c5d8(unknown* p) { INCFUNC("asm/func/FUN_0804c5d8.inc"); }

NAKED s32 FUN_0804c650(unknown* p) { INCFUNC("asm/func/FUN_0804c650.inc"); }

NAKED s32 FUN_0804c6ac(unknown* p) { INCFUNC("asm/func/FUN_0804c6ac.inc"); }

NAKED s32 FUN_0804c7c8(unknown* p) { INCFUNC("asm/func/FUN_0804c7c8.inc"); }

NAKED s32 FUN_0804c888(unknown* p) { INCFUNC("asm/func/FUN_0804c888.inc"); }

NAKED s32 FUN_0804c8bc(unknown* p) { INCFUNC("asm/func/FUN_0804c8bc.inc"); }

NAKED s32 FUN_0804c8f4(unknown* p) { INCFUNC("asm/func/FUN_0804c8f4.inc"); }

NAKED s32 FUN_0804c940(unknown* p) { INCFUNC("asm/func/FUN_0804c940.inc"); }

NAKED s32 FUN_0804c978(unknown* p) { INCFUNC("asm/func/FUN_0804c978.inc"); }

NAKED s32 FUN_0804c9a8(unknown* p) { INCFUNC("asm/func/FUN_0804c9a8.inc"); }

NAKED s32 FUN_0804cb6c(unknown* p) { INCFUNC("asm/func/FUN_0804cb6c.inc"); }

NAKED s32 FUN_0804cb84(unknown* p) { INCFUNC("asm/func/FUN_0804cb84.inc"); }

NAKED s32 FUN_0804cb9c(unknown* p) { INCFUNC("asm/func/FUN_0804cb9c.inc"); }

NAKED s32 FUN_0804cbb4(unknown* p) { INCFUNC("asm/func/FUN_0804cbb4.inc"); }

NAKED s32 FUN_0804cbcc(unknown* p) { INCFUNC("asm/func/FUN_0804cbcc.inc"); }

NAKED s32 FUN_0804cbfc(unknown* p) { INCFUNC("asm/func/FUN_0804cbfc.inc"); }

NAKED s32 FUN_0804cc38(unknown* p) { INCFUNC("asm/func/FUN_0804cc38.inc"); }

NAKED s32 FUN_0804cc7c(unknown* p) { INCFUNC("asm/func/FUN_0804cc7c.inc"); }

NAKED s32 FUN_0804cc98(unknown* p) { INCFUNC("asm/func/FUN_0804cc98.inc"); }

NAKED s32 FUN_0804ccbc(unknown* p) { INCFUNC("asm/func/FUN_0804ccbc.inc"); }

NAKED void FUN_0804ccd0(s32 param_1) { INCFUNC("asm/func/FUN_0804ccd0.inc"); }

NAKED s32 FUN_0804cd1c(s32 param_1) { INCFUNC("asm/func/FUN_0804cd1c.inc"); }

NAKED void FUN_0804cde8(s32 param_1) { INCFUNC("asm/func/FUN_0804cde8.inc"); }

NAKED void FUN_0804ce0c(s32 param_1) { INCFUNC("asm/func/FUN_0804ce0c.inc"); }

NAKED void FUN_0804ce3c(s32 param_1) { INCFUNC("asm/func/FUN_0804ce3c.inc"); }

NAKED void FUN_0804cf4c(s32 param_1) { INCFUNC("asm/func/FUN_0804cf4c.inc"); }

NAKED void FUN_0804d05c(s32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_0804d05c.inc"); }

NAKED void FUN_0804d0ac(u8 param_1) { INCFUNC("asm/func/FUN_0804d0ac.inc"); }

NAKED void FUN_0804d214(u8 param_1) { INCFUNC("asm/func/FUN_0804d214.inc"); }

NAKED void FUN_0804d308(void) { INCFUNC("asm/func/FUN_0804d308.inc"); }

NAKED void FUN_0804d36c(s16 param_1) { INCFUNC("asm/func/FUN_0804d36c.inc"); }

NAKED void FUN_0804d394(s32 param_1) { INCFUNC("asm/func/FUN_0804d394.inc"); }

NAKED void FUN_0804d548(s32 param_1) { INCFUNC("asm/func/FUN_0804d548.inc"); }

NAKED s32 FUN_0804d680(s32 param_1) { INCFUNC("asm/func/FUN_0804d680.inc"); }

NAKED s32 FUN_0804d698(unknown* p) { INCFUNC("asm/func/FUN_0804d698.inc"); }

NAKED s32 FUN_0804d6d0(unknown* p) { INCFUNC("asm/func/FUN_0804d6d0.inc"); }

NAKED void FUN_0804d708(u8 param_1) { INCFUNC("asm/func/FUN_0804d708.inc"); }

NAKED void FUN_0804d85c(void) { INCFUNC("asm/func/FUN_0804d85c.inc"); }

NAKED void FUN_0804d868(s32 param_1) { INCFUNC("asm/func/FUN_0804d868.inc"); }

NAKED s32 FUN_0804d90c(unknown* p) { INCFUNC("asm/func/FUN_0804d90c.inc"); }

NAKED void FUN_0804d9a4(s32 param_1) { INCFUNC("asm/func/FUN_0804d9a4.inc"); }

NAKED s32 FUN_0804da50(unknown* p) { INCFUNC("asm/func/FUN_0804da50.inc"); }

NAKED s32 FUN_0804da78(unknown* p) { INCFUNC("asm/func/FUN_0804da78.inc"); }

NAKED s32 FUN_0804dae4(unknown* p) { INCFUNC("asm/func/FUN_0804dae4.inc"); }

NAKED void FUN_0804dafc(u8 param_1) { INCFUNC("asm/func/FUN_0804dafc.inc"); }

NAKED void FUN_0804dbc8(void) { INCFUNC("asm/func/FUN_0804dbc8.inc"); }

NAKED void FUN_0804dbe0(s32 param_1) { INCFUNC("asm/func/FUN_0804dbe0.inc"); }

NAKED s32 FUN_0804dc90(s32 param_1) { INCFUNC("asm/func/FUN_0804dc90.inc"); }

NAKED void FUN_0804dd80(s32 param_1) { INCFUNC("asm/func/FUN_0804dd80.inc"); }

NAKED s32 FUN_0804de18(unknown* p) { INCFUNC("asm/func/FUN_0804de18.inc"); }

NAKED s32 FUN_0804de40(unknown* p) { INCFUNC("asm/func/FUN_0804de40.inc"); }

NAKED s32 FUN_0804de58(unknown* p) { INCFUNC("asm/func/FUN_0804de58.inc"); }

NAKED s32 FUN_0804de70(unknown* p) { INCFUNC("asm/func/FUN_0804de70.inc"); }

NAKED s32 FUN_0804dee8(unknown* param_1) { INCFUNC("asm/func/FUN_0804dee8.inc"); }

NAKED s32 FUN_0804df18(unknown* param_1) { INCFUNC("asm/func/FUN_0804df18.inc"); }

NAKED s32 FUN_0804e028(unknown* param_1) { INCFUNC("asm/func/FUN_0804e028.inc"); }

NAKED void FUN_0804e0bc(unknown* p) { INCFUNC("asm/func/FUN_0804e0bc.inc"); }

NAKED s32 FUN_0804e128(unknown* param_1) { INCFUNC("asm/func/FUN_0804e128.inc"); }

NAKED unknown* FUN_0804e164(unknown* p) { INCFUNC("asm/func/FUN_0804e164.inc"); }

NAKED s32 FUN_0804e25c(unknown* p) { INCFUNC("asm/func/FUN_0804e25c.inc"); }

NAKED Entity* FUN_0804e2c0(void) { INCFUNC("asm/func/FUN_0804e2c0.inc"); }

NAKED void FUN_0804e36c(void) { INCFUNC("asm/func/FUN_0804e36c.inc"); }

NAKED void FUN_0804e384(void) { INCFUNC("asm/func/FUN_0804e384.inc"); }

NAKED s32 FUN_0804e3a0(void) { INCFUNC("asm/func/FUN_0804e3a0.inc"); }

NAKED s32 FUN_0804e3c0(void) { INCFUNC("asm/func/FUN_0804e3c0.inc"); }

NAKED s32 FUN_0804e3ec(void) { INCFUNC("asm/func/FUN_0804e3ec.inc"); }

NAKED s32 FUN_0804e438(void) { INCFUNC("asm/func/FUN_0804e438.inc"); }

NAKED s32 FUN_0804e458(void) { INCFUNC("asm/func/FUN_0804e458.inc"); }

NAKED s32 FUN_0804e474(void) { INCFUNC("asm/func/FUN_0804e474.inc"); }

NAKED s32 FUN_0804e490(void) { INCFUNC("asm/func/FUN_0804e490.inc"); }

NAKED void FUN_0804e4ac(void) { INCFUNC("asm/func/FUN_0804e4ac.inc"); }

NAKED void FUN_0804e4c4(void) { INCFUNC("asm/func/FUN_0804e4c4.inc"); }

NAKED void FUN_0804e4dc(unknown* param_1, Entity* param_2, EntityFunc* param_3, EntityFunc* param_4) { INCFUNC("asm/func/FUN_0804e4dc.inc"); }

NAKED s32 FUN_0804e514(unknown* param_1) { INCFUNC("asm/func/FUN_0804e514.inc"); }

NAKED s32 FUN_0804e55c(unknown* param_1) { INCFUNC("asm/func/FUN_0804e55c.inc"); }

NAKED void FUN_0804e584(u8 param_1) { INCFUNC("asm/func/FUN_0804e584.inc"); }

NAKED s32 FUN_0804e59c(void) { INCFUNC("asm/func/FUN_0804e59c.inc"); }

NAKED void FUN_0804e5bc(void) { INCFUNC("asm/func/FUN_0804e5bc.inc"); }

NAKED void FUN_0804e5e8(void) { INCFUNC("asm/func/FUN_0804e5e8.inc"); }

NAKED void FUN_0804e604(void) { INCFUNC("asm/func/FUN_0804e604.inc"); }

NAKED s32 FUN_0804e61c(void) { INCFUNC("asm/func/FUN_0804e61c.inc"); }

NAKED s32 FUN_0804e638(void) { INCFUNC("asm/func/FUN_0804e638.inc"); }

NAKED void FUN_0804e654(void) { INCFUNC("asm/func/FUN_0804e654.inc"); }

NAKED s32 FUN_0804e65c(u32 param_1) { INCFUNC("asm/func/FUN_0804e65c.inc"); }

NAKED s32 FUN_0804e674(s16 param_1) { INCFUNC("asm/func/FUN_0804e674.inc"); }

NAKED void FUN_0804e69c(s32 param_1, u8* param_2, s32 param_3) { INCFUNC("asm/func/FUN_0804e69c.inc"); }

NAKED void FUN_0804e6d8(unknown* s, s32 param_2, s32 charcount) { INCFUNC("asm/func/FUN_0804e6d8.inc"); }

NAKED void Crossover_LoadMappingBuf(void) { INCFUNC("asm/func/Crossover_LoadMappingBuf.inc"); }
