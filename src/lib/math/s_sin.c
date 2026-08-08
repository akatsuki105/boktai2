
#include "global.h"

// newlib/libm/s_sin.c

// 0x0824EC90
NAKED f64 fdlibm_sin(f64 x) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	sub sp, #0x14\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r1, _0824ECB4 @ =0x7FFFFFFF\n\
	ands r1, r2\n\
	ldr r0, _0824ECB8 @ =0x3FE921FB\n\
	cmp r1, r0\n\
	bgt _0824ECC4\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	adds r1, r3, #0\n\
	adds r0, r2, #0\n\
	ldr r2, _0824ECBC @ =0x00000000\n\
	ldr r3, _0824ECC0 @ =0x00000000\n\
	bl __kernel_sin\n\
	b _0824ED3E\n\
	.align 2, 0\n\
_0824ECB4: .4byte 0x7FFFFFFF\n\
_0824ECB8: .4byte 0x3FE921FB\n\
_0824ECBC: .4byte 0x00000000\n\
_0824ECC0: .4byte 0x00000000\n\
_0824ECC4:\n\
	ldr r0, _0824ECD4 @ =0x7FEFFFFF\n\
	cmp r1, r0\n\
	ble _0824ECD8\n\
	adds r1, r3, #0\n\
	adds r0, r2, #0\n\
	bl __subdf3\n\
	b _0824ED3E\n\
	.align 2, 0\n\
_0824ECD4: .4byte 0x7FEFFFFF\n\
_0824ECD8:\n\
	adds r1, r3, #0\n\
	adds r0, r2, #0\n\
	add r2, sp, #4\n\
	bl __ieee754_rem_pio2\n\
	adds r1, r0, #0\n\
	movs r0, #3\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	beq _0824ED0E\n\
	cmp r1, #1\n\
	bgt _0824ECF6\n\
	cmp r1, #0\n\
	beq _0824ECFC\n\
	b _0824ED2E\n\
_0824ECF6:\n\
	cmp r1, #2\n\
	beq _0824ED1C\n\
	b _0824ED2E\n\
_0824ECFC:\n\
	ldr r0, [sp, #4]\n\
	ldr r1, [sp, #8]\n\
	ldr r2, [sp, #0xc]\n\
	ldr r3, [sp, #0x10]\n\
	movs r4, #1\n\
	str r4, [sp]\n\
	bl __kernel_sin\n\
	b _0824ED3E\n\
_0824ED0E:\n\
	ldr r0, [sp, #4]\n\
	ldr r1, [sp, #8]\n\
	ldr r2, [sp, #0xc]\n\
	ldr r3, [sp, #0x10]\n\
	bl __kernel_cos\n\
	b _0824ED3E\n\
_0824ED1C:\n\
	ldr r0, [sp, #4]\n\
	ldr r1, [sp, #8]\n\
	ldr r2, [sp, #0xc]\n\
	ldr r3, [sp, #0x10]\n\
	movs r4, #1\n\
	str r4, [sp]\n\
	bl __kernel_sin\n\
	b _0824ED3A\n\
_0824ED2E:\n\
	ldr r0, [sp, #4]\n\
	ldr r1, [sp, #8]\n\
	ldr r2, [sp, #0xc]\n\
	ldr r3, [sp, #0x10]\n\
	bl __kernel_cos\n\
_0824ED3A:\n\
	bl __negdf2\n\
_0824ED3E:\n\
	add sp, #0x14\n\
	pop {r4, pc}\n\
 .syntax divided\n");
}
