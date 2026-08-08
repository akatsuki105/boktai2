#include "global.h"

// newlib/libm/e_rem_pio2.c

// clang-format off
static const s32 two_over_pi[] = {
  0xA2F983, 0x6E4E44, 0x1529FC, 0x2757D1, 0xF534DD, 0xC0DB62, 
  0x95993C, 0x439041, 0xFE5163, 0xABDEBB, 0xC561B7, 0x246E3A, 
  0x424DD2, 0xE00649, 0x2EEA09, 0xD1921C, 0xFE1DEB, 0x1CB129, 
  0xA73EE8, 0x8235F5, 0x2EBB44, 0x84E99C, 0x7026B4, 0x5F7E41, 
  0x3991D6, 0x398353, 0x39F49C, 0x845F8B, 0xBDF928, 0x3B1FF8, 
  0x97FFDE, 0x05980F, 0xEF2F11, 0x8B5A0A, 0x6D1F6D, 0x367ECF, 
  0x27CB09, 0xB74F46, 0x3F669E, 0x5FEA2D, 0x7527BA, 0xC7EBE5, 
  0xF17B3D, 0x0739F7, 0x8A5292, 0xEA6BFB, 0x5FB11F, 0x8D5D08, 
  0x560330, 0x46FC7B, 0x6BABF0, 0xCFBC20, 0x9AF436, 0x1DA9E3, 
  0x91615E, 0xE61B08, 0x659985, 0x5F14A0, 0x68408D, 0xFFD880, 
  0x4D7327, 0x310606, 0x1556CA, 0x73A8C9, 0x60E27B, 0xC08C6B, 
};

static const s32 npio2_hw[] = {
  0x3FF921FB, 0x400921FB, 0x4012D97C, 0x401921FB, 0x401F6A7A, 0x4022D97C,
  0x4025FDBB, 0x402921FB, 0x402C463A, 0x402F6A7A, 0x4031475C, 0x4032D97C,
  0x40346B9C, 0x4035FDBB, 0x40378FDB, 0x403921FB, 0x403AB41B, 0x403C463A,
  0x403DD85A, 0x403F6A7A, 0x40407E4C, 0x4041475C, 0x4042106C, 0x4042D97C,
  0x4043A28C, 0x40446B9C, 0x404534AC, 0x4045FDBB, 0x4046C6CB, 0x40478FDB,
  0x404858EB, 0x404921FB,
};
// clang-format on

static const f64 zero = 0.00000000000000000000e+00;    /* 0x00000000, 0x00000000 */
static const f64 half = 5.00000000000000000000e-01;    /* 0x3FE00000, 0x00000000 */
static const f64 two24 = 1.67772160000000000000e+07;   /* 0x41700000, 0x00000000 */
static const f64 invpio2 = 6.36619772367581382433e-01; /* 0x3FE45F30, 0x6DC9C883 */
static const f64 pio2_1 = 1.57079632673412561417e+00;  /* 0x3FF921FB, 0x54400000 */
static const f64 pio2_1t = 6.07710050650619224932e-11; /* 0x3DD0B461, 0x1A626331 */
static const f64 pio2_2 = 6.07710050630396597660e-11;  /* 0x3DD0B461, 0x1A600000 */
static const f64 pio2_2t = 2.02226624879595063154e-21; /* 0x3BA3198A, 0x2E037073 */
static const f64 pio2_3 = 2.02226624871116645580e-21;  /* 0x3BA3198A, 0x2E000000 */
static const f64 pio2_3t = 8.47842766036889956997e-32; /* 0x397B839A, 0x252049C1 */

// 0x0824FCCC
NAKED s32 __ieee754_rem_pio2(f64 x, f64* y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x3c\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	mov r8, r2\n\
	adds r2, r5, #0\n\
	adds r1, r4, #0\n\
	str r1, [sp, #0x38]\n\
	ldr r0, _0824FD08 @ =0x7FFFFFFF\n\
	adds r3, r1, #0\n\
	ands r3, r0\n\
	mov sb, r3\n\
	ldr r0, _0824FD0C @ =0x3FE921FB\n\
	cmp sb, r0\n\
	bgt _0824FD18\n\
	mov r0, r8\n\
	str r4, [r0]\n\
	str r5, [r0, #4]\n\
	ldr r0, _0824FD10 @ =0x00000000\n\
	ldr r1, _0824FD14 @ =0x00000000\n\
	mov r2, r8\n\
	str r0, [r2, #8]\n\
	str r1, [r2, #0xc]\n\
	movs r0, #0\n\
	b _08250124\n\
	.align 2, 0\n\
_0824FD08: .4byte 0x7FFFFFFF\n\
_0824FD0C: .4byte 0x3FE921FB\n\
_0824FD10: .4byte 0x00000000\n\
_0824FD14: .4byte 0x00000000\n\
_0824FD18:\n\
	ldr r0, _0824FD44 @ =0x4002D97B\n\
	cmp sb, r0\n\
	ble _0824FD20\n\
	b _0824FE34\n\
_0824FD20:\n\
	cmp r1, #0\n\
	ble _0824FDAC\n\
	ldr r2, _0824FD48 @ =0x3FF921FB\n\
	ldr r3, _0824FD4C @ =0x54400000\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __subdf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, _0824FD50 @ =0x3FF921FB\n\
	cmp sb, r0\n\
	beq _0824FD5C\n\
	ldr r4, _0824FD54 @ =0x3DD0B461\n\
	ldr r5, _0824FD58 @ =0x1A626331\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	b _0824FD70\n\
	.align 2, 0\n\
_0824FD44: .4byte 0x4002D97B\n\
_0824FD48: .4byte 0x3FF921FB\n\
_0824FD4C: .4byte 0x54400000\n\
_0824FD50: .4byte 0x3FF921FB\n\
_0824FD54: .4byte 0x3DD0B461\n\
_0824FD58: .4byte 0x1A626331\n\
_0824FD5C:\n\
	ldr r3, _0824FDA0 @ =0x1A600000\n\
	ldr r2, _0824FD9C @ =0x3DD0B461\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __subdf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r4, _0824FDA4 @ =0x3BA3198A\n\
	ldr r5, _0824FDA8 @ =0x2E037073\n\
_0824FD70:\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	mov r0, r8\n\
	str r2, [r0]\n\
	str r3, [r0, #4]\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __subdf3\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __subdf3\n\
	mov r2, r8\n\
	str r0, [r2, #8]\n\
	str r1, [r2, #0xc]\n\
	movs r0, #1\n\
	b _08250124\n\
	.align 2, 0\n\
_0824FD9C: .4byte 0x3DD0B461\n\
_0824FDA0: .4byte 0x1A600000\n\
_0824FDA4: .4byte 0x3BA3198A\n\
_0824FDA8: .4byte 0x2E037073\n\
_0824FDAC:\n\
	ldr r3, _0824FDD0 @ =0x54400000\n\
	ldr r2, _0824FDCC @ =0x3FF921FB\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __adddf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, _0824FDD4 @ =0x3FF921FB\n\
	cmp sb, r0\n\
	beq _0824FDE0\n\
	ldr r4, _0824FDD8 @ =0x3DD0B461\n\
	ldr r5, _0824FDDC @ =0x1A626331\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	b _0824FDF4\n\
	.align 2, 0\n\
_0824FDCC: .4byte 0x3FF921FB\n\
_0824FDD0: .4byte 0x54400000\n\
_0824FDD4: .4byte 0x3FF921FB\n\
_0824FDD8: .4byte 0x3DD0B461\n\
_0824FDDC: .4byte 0x1A626331\n\
_0824FDE0:\n\
	ldr r3, _0824FE28 @ =0x1A600000\n\
	ldr r2, _0824FE24 @ =0x3DD0B461\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __adddf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r4, _0824FE2C @ =0x3BA3198A\n\
	ldr r5, _0824FE30 @ =0x2E037073\n\
_0824FDF4:\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	mov r0, r8\n\
	str r2, [r0]\n\
	str r3, [r0, #4]\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __subdf3\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __adddf3\n\
	mov r2, r8\n\
	str r0, [r2, #8]\n\
	str r1, [r2, #0xc]\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	b _08250124\n\
	.align 2, 0\n\
_0824FE24: .4byte 0x3DD0B461\n\
_0824FE28: .4byte 0x1A600000\n\
_0824FE2C: .4byte 0x3BA3198A\n\
_0824FE30: .4byte 0x2E037073\n\
_0824FE34:\n\
	ldr r0, _0824FFF0 @ =0x413921FB\n\
	cmp sb, r0\n\
	ble _0824FE3C\n\
	b _08250040\n\
_0824FE3C:\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl fdlibm_fp_fabs\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r2, _0824FFF4 @ =0x3FE45F30\n\
	ldr r3, _0824FFF8 @ =0x6DC9C883\n\
	bl __muldf3\n\
	ldr r2, _0824FFFC @ =0x3FE00000\n\
	ldr r3, _08250000 @ =0x00000000\n\
	bl __adddf3\n\
	bl __fixdfsi\n\
	mov sl, r0\n\
	bl __floatsidf\n\
	str r0, [sp, #0x30]\n\
	str r1, [sp, #0x34]\n\
	ldr r2, _08250004 @ =0x3FF921FB\n\
	ldr r3, _08250008 @ =0x54400000\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __subdf3\n\
	str r0, [sp, #0x28]\n\
	str r1, [sp, #0x2c]\n\
	ldr r2, _0825000C @ =0x3DD0B461\n\
	ldr r3, _08250010 @ =0x1A626331\n\
	ldr r0, [sp, #0x30]\n\
	ldr r1, [sp, #0x34]\n\
	bl __muldf3\n\
	str r0, [sp, #0x20]\n\
	str r1, [sp, #0x24]\n\
	mov r3, sl\n\
	cmp r3, #0x1f\n\
	bgt _0824FEA6\n\
	ldr r0, _08250014 @ =0x085A8E70\n\
	mov r1, sl\n\
	subs r1, #1\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r0, [r1]\n\
	cmp sb, r0\n\
	beq _0824FEA6\n\
	b _0824FF9E\n\
_0824FEA6:\n\
	mov r3, sb\n\
	asrs r3, r3, #0x14\n\
	mov sb, r3\n\
	ldr r0, [sp, #0x28]\n\
	ldr r1, [sp, #0x2c]\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __subdf3\n\
	mov r2, r8\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	lsrs r0, r0, #0x14\n\
	ldr r3, _08250018 @ =0x000007FF\n\
	ands r0, r3\n\
	mov r1, sb\n\
	subs r4, r1, r0\n\
	cmp r4, #0x10\n\
	bgt _0824FECE\n\
	b _0824FFB0\n\
_0824FECE:\n\
	ldr r6, [sp, #0x28]\n\
	ldr r7, [sp, #0x2c]\n\
	ldr r2, _0825001C @ =0x3DD0B461\n\
	ldr r3, _08250020 @ =0x1A600000\n\
	ldr r0, [sp, #0x30]\n\
	ldr r1, [sp, #0x34]\n\
	bl __muldf3\n\
	str r0, [sp, #0x20]\n\
	str r1, [sp, #0x24]\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __subdf3\n\
	str r0, [sp, #0x28]\n\
	str r1, [sp, #0x2c]\n\
	ldr r2, _08250024 @ =0x3BA3198A\n\
	ldr r3, _08250028 @ =0x2E037073\n\
	ldr r0, [sp, #0x30]\n\
	ldr r1, [sp, #0x34]\n\
	bl __muldf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	ldr r2, [sp, #0x28]\n\
	ldr r3, [sp, #0x2c]\n\
	bl __subdf3\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __subdf3\n\
	str r0, [sp, #0x20]\n\
	str r1, [sp, #0x24]\n\
	ldr r0, [sp, #0x28]\n\
	ldr r1, [sp, #0x2c]\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __subdf3\n\
	mov r2, r8\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	lsrs r0, r0, #0x14\n\
	ldr r3, _08250018 @ =0x000007FF\n\
	ands r0, r3\n\
	mov r1, sb\n\
	subs r4, r1, r0\n\
	cmp r4, #0x31\n\
	ble _0824FFB0\n\
	ldr r6, [sp, #0x28]\n\
	ldr r7, [sp, #0x2c]\n\
	ldr r2, _0825002C @ =0x3BA3198A\n\
	ldr r3, _08250030 @ =0x2E000000\n\
	ldr r0, [sp, #0x30]\n\
	ldr r1, [sp, #0x34]\n\
	bl __muldf3\n\
	str r0, [sp, #0x20]\n\
	str r1, [sp, #0x24]\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __subdf3\n\
	str r0, [sp, #0x28]\n\
	str r1, [sp, #0x2c]\n\
	ldr r2, _08250034 @ =0x397B839A\n\
	ldr r3, _08250038 @ =0x252049C1\n\
	ldr r0, [sp, #0x30]\n\
	ldr r1, [sp, #0x34]\n\
	bl __muldf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	ldr r2, [sp, #0x28]\n\
	ldr r3, [sp, #0x2c]\n\
	bl __subdf3\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __subdf3\n\
	str r0, [sp, #0x20]\n\
	str r1, [sp, #0x24]\n\
_0824FF9E:\n\
	ldr r0, [sp, #0x28]\n\
	ldr r1, [sp, #0x2c]\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __subdf3\n\
	mov r2, r8\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
_0824FFB0:\n\
	mov r3, r8\n\
	ldr r6, [r3]\n\
	ldr r7, [r3, #4]\n\
	ldr r0, [sp, #0x28]\n\
	ldr r1, [sp, #0x2c]\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __subdf3\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __subdf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	mov r0, r8\n\
	str r4, [r0, #8]\n\
	str r5, [r0, #0xc]\n\
	ldr r1, [sp, #0x38]\n\
	cmp r1, #0\n\
	bge _0825003C\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __negdf2\n\
	mov r2, r8\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	b _08250116\n\
	.align 2, 0\n\
_0824FFF0: .4byte 0x413921FB\n\
_0824FFF4: .4byte 0x3FE45F30\n\
_0824FFF8: .4byte 0x6DC9C883\n\
_0824FFFC: .4byte 0x3FE00000\n\
_08250000: .4byte 0x00000000\n\
_08250004: .4byte 0x3FF921FB\n\
_08250008: .4byte 0x54400000\n\
_0825000C: .4byte 0x3DD0B461\n\
_08250010: .4byte 0x1A626331\n\
_08250014: .4byte npio2_hw\n\
_08250018: .4byte 0x000007FF\n\
_0825001C: .4byte 0x3DD0B461\n\
_08250020: .4byte 0x1A600000\n\
_08250024: .4byte 0x3BA3198A\n\
_08250028: .4byte 0x2E037073\n\
_0825002C: .4byte 0x3BA3198A\n\
_08250030: .4byte 0x2E000000\n\
_08250034: .4byte 0x397B839A\n\
_08250038: .4byte 0x252049C1\n\
_0825003C:\n\
	mov r0, sl\n\
	b _08250124\n\
_08250040:\n\
	ldr r0, _08250064 @ =0x7FEFFFFF\n\
	cmp sb, r0\n\
	ble _08250068\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __subdf3\n\
	mov r2, r8\n\
	str r0, [r2, #8]\n\
	str r1, [r2, #0xc]\n\
	mov r3, r8\n\
	str r0, [r3]\n\
	str r1, [r3, #4]\n\
	movs r0, #0\n\
	b _08250124\n\
	.align 2, 0\n\
_08250064: .4byte 0x7FEFFFFF\n\
_08250068:\n\
	adds r1, r5, #0\n\
	mov r3, sb\n\
	asrs r2, r3, #0x14\n\
	ldr r3, _082500BC @ =0xFFFFFBEA\n\
	adds r3, r3, r2\n\
	mov sl, r3\n\
	lsls r2, r3, #0x14\n\
	mov r3, sb\n\
	subs r0, r3, r2\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, _082500C0 @ =0x085A8D68\n\
	mov sb, r0\n\
	add r5, sp, #8\n\
	movs r4, #1\n\
_08250086:\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __fixdfsi\n\
	bl __floatsidf\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	stm r5!, {r2, r3}\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __subdf3\n\
	ldr r2, _082500C4 @ =0x41700000\n\
	ldr r3, _082500C8 @ =0x00000000\n\
	bl __muldf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _08250086\n\
	str r6, [sp, #0x18]\n\
	str r7, [sp, #0x1c]\n\
	movs r5, #3\n\
	b _082500CE\n\
	.align 2, 0\n\
_082500BC: .4byte 0xFFFFFBEA\n\
_082500C0: .4byte two_over_pi\n\
_082500C4: .4byte 0x41700000\n\
_082500C8: .4byte 0x00000000\n\
_082500CC:\n\
	adds r5, r4, #0\n\
_082500CE:\n\
	subs r4, r5, #1\n\
	lsls r0, r4, #3\n\
	add r0, sp\n\
	adds r0, #8\n\
	ldr r1, [r0, #4]\n\
	ldr r0, [r0]\n\
	ldr r3, _08250134 @ =0x00000000\n\
	ldr r2, _08250130 @ =0x00000000\n\
	bl __eqdf2\n\
	cmp r0, #0\n\
	beq _082500CC\n\
	movs r0, #2\n\
	str r0, [sp]\n\
	mov r1, sb\n\
	str r1, [sp, #4]\n\
	add r0, sp, #8\n\
	mov r1, r8\n\
	mov r2, sl\n\
	adds r3, r5, #0\n\
	bl __kernel_rem_pio2\n\
	mov sl, r0\n\
	ldr r2, [sp, #0x38]\n\
	cmp r2, #0\n\
	bge _08250124\n\
	mov r3, r8\n\
	ldr r0, [r3]\n\
	ldr r1, [r3, #4]\n\
	bl __negdf2\n\
	mov r2, r8\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	ldr r0, [r2, #8]\n\
	ldr r1, [r2, #0xc]\n\
_08250116:\n\
	bl __negdf2\n\
	mov r3, r8\n\
	str r0, [r3, #8]\n\
	str r1, [r3, #0xc]\n\
	mov r1, sl\n\
	rsbs r0, r1, #0\n\
_08250124:\n\
	add sp, #0x3c\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7, pc}\n\
	.align 2, 0\n\
_08250130: .4byte 0x00000000\n\
_08250134: .4byte 0x00000000\n\
 .syntax divided\n");
}
