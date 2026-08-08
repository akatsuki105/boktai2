#include "global.h"

// newlib/libm/k_cos.c

static const f64 one = 1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
static const f64 C1 = 4.16666666666666019037e-02;  /* 0x3FA55555, 0x5555554C */
static const f64 C2 = -1.38888888888741095749e-03; /* 0xBF56C16C, 0x16C15177 */
static const f64 C3 = 2.48015872894767294178e-05;  /* 0x3EFA01A0, 0x19CB1590 */
static const f64 C4 = -2.75573143513906633035e-07; /* 0xBE927E4F, 0x809C52AD */
static const f64 C5 = 2.08757232129817482790e-09;  /* 0x3E21EE9E, 0xBDB4B1C4 */
static const f64 C6 = -1.13596475577881948265e-11; /* 0xBDA8FAE9, 0xBE8838D4 */

// 0x0825033C
NAKED f64 __kernel_cos(f64 x, f64 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #0x20\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	str r2, [sp, #8]\n\
	str r3, [sp, #0xc]\n\
	ldr r0, _0825036C @ =0x7FFFFFFF\n\
	ldr r1, [sp]\n\
	ands r1, r0\n\
	mov r8, r1\n\
	ldr r0, _08250370 @ =0x3E3FFFFF\n\
	cmp r8, r0\n\
	bgt _0825037C\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __fixdfsi\n\
	cmp r0, #0\n\
	bne _0825037C\n\
	ldr r0, _08250374 @ =0x3FF00000\n\
	ldr r1, _08250378 @ =0x00000000\n\
	b _0825051A\n\
	.align 2, 0\n\
_0825036C: .4byte 0x7FFFFFFF\n\
_08250370: .4byte 0x3E3FFFFF\n\
_08250374: .4byte 0x3FF00000\n\
_08250378: .4byte 0x00000000\n\
_0825037C:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __muldf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r3, _08250454 @ =0xBE8838D4\n\
	ldr r2, _08250450 @ =0xBDA8FAE9\n\
	bl __muldf3\n\
	ldr r2, _08250458 @ =0x3E21EE9E\n\
	ldr r3, _0825045C @ =0xBDB4B1C4\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	ldr r2, _08250460 @ =0xBE927E4F\n\
	ldr r3, _08250464 @ =0x809C52AD\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	ldr r2, _08250468 @ =0x3EFA01A0\n\
	ldr r3, _0825046C @ =0x19CB1590\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	ldr r2, _08250470 @ =0xBF56C16C\n\
	ldr r3, _08250474 @ =0x16C15177\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	ldr r2, _08250478 @ =0x3FA55555\n\
	ldr r3, _0825047C @ =0x5555554C\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	ldr r0, _08250480 @ =0x3FD33332\n\
	cmp r8, r0\n\
	bgt _08250494\n\
	ldr r2, _08250484 @ =0x3FE00000\n\
	ldr r3, _08250488 @ =0x00000000\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [sp, #0x10]\n\
	ldr r3, [sp, #0x14]\n\
	bl __muldf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	ldr r2, [sp, #8]\n\
	ldr r3, [sp, #0xc]\n\
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
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, _0825048C @ =0x3FF00000\n\
	ldr r1, _08250490 @ =0x00000000\n\
	b _08250516\n\
	.align 2, 0\n\
_08250450: .4byte 0xBDA8FAE9\n\
_08250454: .4byte 0xBE8838D4\n\
_08250458: .4byte 0x3E21EE9E\n\
_0825045C: .4byte 0xBDB4B1C4\n\
_08250460: .4byte 0xBE927E4F\n\
_08250464: .4byte 0x809C52AD\n\
_08250468: .4byte 0x3EFA01A0\n\
_0825046C: .4byte 0x19CB1590\n\
_08250470: .4byte 0xBF56C16C\n\
_08250474: .4byte 0x16C15177\n\
_08250478: .4byte 0x3FA55555\n\
_0825047C: .4byte 0x5555554C\n\
_08250480: .4byte 0x3FD33332\n\
_08250484: .4byte 0x3FE00000\n\
_08250488: .4byte 0x00000000\n\
_0825048C: .4byte 0x3FF00000\n\
_08250490: .4byte 0x00000000\n\
_08250494:\n\
	ldr r0, _082504A0 @ =0x3FE90000\n\
	cmp r8, r0\n\
	ble _082504AC\n\
	ldr r6, _082504A4 @ =0x3FD20000\n\
	ldr r7, _082504A8 @ =0x00000000\n\
	b _082504B2\n\
	.align 2, 0\n\
_082504A0: .4byte 0x3FE90000\n\
_082504A4: .4byte 0x3FD20000\n\
_082504A8: .4byte 0x00000000\n\
_082504AC:\n\
	ldr r6, _08250524 @ =0xFFE00000\n\
	add r6, r8\n\
	movs r7, #0\n\
_082504B2:\n\
	ldr r2, _08250528 @ =0x3FE00000\n\
	ldr r3, _0825052C @ =0x00000000\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __subdf3\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	ldr r0, _08250530 @ =0x3FF00000\n\
	ldr r1, _08250534 @ =0x00000000\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __subdf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [sp, #0x10]\n\
	ldr r3, [sp, #0x14]\n\
	bl __muldf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	ldr r2, [sp, #8]\n\
	ldr r3, [sp, #0xc]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
_08250516:\n\
	bl __subdf3\n\
_0825051A:\n\
	add sp, #0x20\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7, pc}\n\
	.align 2, 0\n\
_08250524: .4byte 0xFFE00000\n\
_08250528: .4byte 0x3FE00000\n\
_0825052C: .4byte 0x00000000\n\
_08250530: .4byte 0x3FF00000\n\
_08250534: .4byte 0x00000000\n\
 .syntax divided\n");
}
