
#include "global.h"

// newlib/libm/s_tan.c

// 0x0824ED44
NAKED f64 fdlibm_tan(f64 x) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #0x14\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r1, _0824ED68 @ =0x7FFFFFFF\n\
	ands r1, r2\n\
	ldr r0, _0824ED6C @ =0x3FE921FB\n\
	cmp r1, r0\n\
	bgt _0824ED78\n\
	movs r0, #1\n\
	str r0, [sp]\n\
	adds r1, r3, #0\n\
	adds r0, r2, #0\n\
	ldr r2, _0824ED70 @ =0x00000000\n\
	ldr r3, _0824ED74 @ =0x00000000\n\
	bl __kernel_tan\n\
	b _0824EDB0\n\
	.align 2, 0\n\
_0824ED68: .4byte 0x7FFFFFFF\n\
_0824ED6C: .4byte 0x3FE921FB\n\
_0824ED70: .4byte 0x00000000\n\
_0824ED74: .4byte 0x00000000\n\
_0824ED78:\n\
	ldr r0, _0824EDA4 @ =0x7FEFFFFF\n\
	cmp r1, r0\n\
	bgt _0824EDA8\n\
	adds r1, r3, #0\n\
	adds r0, r2, #0\n\
	add r2, sp, #4\n\
	bl __ieee754_rem_pio2\n\
	ldr r4, [sp, #4]\n\
	ldr r5, [sp, #8]\n\
	ldr r2, [sp, #0xc]\n\
	ldr r3, [sp, #0x10]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	lsls r0, r0, #1\n\
	subs r1, r1, r0\n\
	str r1, [sp]\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __kernel_tan\n\
	b _0824EDB0\n\
	.align 2, 0\n\
_0824EDA4: .4byte 0x7FEFFFFF\n\
_0824EDA8:\n\
	adds r1, r3, #0\n\
	adds r0, r2, #0\n\
	bl __subdf3\n\
_0824EDB0:\n\
	add sp, #0x14\n\
	pop {r4, r5, pc}\n\
 .syntax divided\n");
}
