#include "global.h"

// newlib/libm/k_sin.c

static const f64 half = 5.00000000000000000000e-01; /* 0x3FE00000, 0x00000000 */
static const f64 S1 = -1.66666666666666324348e-01;  /* 0xBFC55555, 0x55555549 */
static const f64 S2 = 8.33333333332248946124e-03;   /* 0x3F811111, 0x1110F8A6 */
static const f64 S3 = -1.98412698298579493134e-04;  /* 0xBF2A01A0, 0x19C161D5 */
static const f64 S4 = 2.75573137070700676789e-06;   /* 0x3EC71DE3, 0x57B1FE7D */
static const f64 S5 = -2.50507602534068634195e-08;  /* 0xBE5AE5E6, 0x8A2B9CEB */
static const f64 S6 = 1.58969099521155010221e-10;   /* 0x3DE5D93A, 0x5ACFD57C */

// 0x08250D10
NAKED f64 __kernel_sin(f64 x, f64 y, s32 iy) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #0x20\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	str r2, [sp, #8]\n\
	str r3, [sp, #0xc]\n\
	ldr r0, _08250D3C @ =0x7FFFFFFF\n\
	ldr r1, [sp]\n\
	ands r0, r1\n\
	ldr r1, _08250D40 @ =0x3E3FFFFF\n\
	cmp r0, r1\n\
	bgt _08250D44\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __fixdfsi\n\
	cmp r0, #0\n\
	bne _08250D44\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	b _08250E84\n\
	.align 2, 0\n\
_08250D3C: .4byte 0x7FFFFFFF\n\
_08250D40: .4byte 0x3E3FFFFF\n\
_08250D44:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __muldf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r2, [sp]\n\
	ldr r3, [sp, #4]\n\
	bl __muldf3\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	ldr r3, _08250E24 @ =0x5ACFD57C\n\
	ldr r2, _08250E20 @ =0x3DE5D93A\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	ldr r2, _08250E28 @ =0xBE5AE5E6\n\
	ldr r3, _08250E2C @ =0x8A2B9CEB\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	ldr r2, _08250E30 @ =0x3EC71DE3\n\
	ldr r3, _08250E34 @ =0x57B1FE7D\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	ldr r2, _08250E38 @ =0xBF2A01A0\n\
	ldr r3, _08250E3C @ =0x19C161D5\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	ldr r2, _08250E40 @ =0x3F811111\n\
	ldr r3, _08250E44 @ =0x1110F8A6\n\
	bl __adddf3\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	ldr r0, [sp, #0x34]\n\
	cmp r0, #0\n\
	beq _08250E58\n\
	ldr r2, _08250E48 @ =0x3FE00000\n\
	ldr r3, _08250E4C @ =0x00000000\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	ldr r2, [sp, #0x10]\n\
	ldr r3, [sp, #0x14]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	ldr r2, [sp, #8]\n\
	ldr r3, [sp, #0xc]\n\
	bl __subdf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r2, _08250E50 @ =0xBFC55555\n\
	ldr r3, _08250E54 @ =0x55555549\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __subdf3\n\
	b _08250E84\n\
	.align 2, 0\n\
_08250E20: .4byte 0x3DE5D93A\n\
_08250E24: .4byte 0x5ACFD57C\n\
_08250E28: .4byte 0xBE5AE5E6\n\
_08250E2C: .4byte 0x8A2B9CEB\n\
_08250E30: .4byte 0x3EC71DE3\n\
_08250E34: .4byte 0x57B1FE7D\n\
_08250E38: .4byte 0xBF2A01A0\n\
_08250E3C: .4byte 0x19C161D5\n\
_08250E40: .4byte 0x3F811111\n\
_08250E44: .4byte 0x1110F8A6\n\
_08250E48: .4byte 0x3FE00000\n\
_08250E4C: .4byte 0x00000000\n\
_08250E50: .4byte 0xBFC55555\n\
_08250E54: .4byte 0x55555549\n\
_08250E58:\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	ldr r2, [sp, #0x10]\n\
	ldr r3, [sp, #0x14]\n\
	bl __muldf3\n\
	ldr r3, _08250E8C @ =0x55555549\n\
	ldr r2, _08250E88 @ =0xBFC55555\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __adddf3\n\
_08250E84:\n\
	add sp, #0x20\n\
	pop {r4, r5, r6, r7, pc}\n\
	.align 2, 0\n\
_08250E88: .4byte 0xBFC55555\n\
_08250E8C: .4byte 0x55555549\n\
 .syntax divided\n");
}
