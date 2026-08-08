#include "global.h"

// newlib/libm/w_asin.c

static const char name[] = "asin";

// 0x0824EE6C
NAKED f64 fdlibm_asin(f64 x) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #0x24\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	bl __ieee754_asin\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, _0824EEFC @ =u32_085a90b8\n\
	ldr r0, [r0]\n\
	mov sb, r0\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp sb, r0\n\
	beq _0824EF14\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl isnan\n\
	mov r8, r0\n\
	cmp r0, #0\n\
	bne _0824EF14\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl fdlibm_fp_fabs\n\
	ldr r2, _0824EF00 @ =0x3FF00000\n\
	ldr r3, _0824EF04 @ =0x00000000\n\
	bl __gtdf2\n\
	cmp r0, #0\n\
	ble _0824EF14\n\
	movs r0, #1\n\
	str r0, [sp]\n\
	ldr r0, _0824EF08 @ =name\n\
	str r0, [sp, #4]\n\
	mov r0, r8\n\
	str r0, [sp, #0x20]\n\
	str r4, [sp, #0x10]\n\
	str r5, [sp, #0x14]\n\
	str r4, [sp, #8]\n\
	str r5, [sp, #0xc]\n\
	ldr r0, _0824EF0C @ =0x00000000\n\
	ldr r1, _0824EF10 @ =0x00000000\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	mov r0, sb\n\
	cmp r0, #2\n\
	beq _0824EEDE\n\
	mov r0, sp\n\
	bl matherr\n\
	cmp r0, #0\n\
	bne _0824EEE6\n\
_0824EEDE:\n\
	bl __errno\n\
	movs r1, #0x21\n\
	str r1, [r0]\n\
_0824EEE6:\n\
	ldr r0, [sp, #0x20]\n\
	cmp r0, #0\n\
	beq _0824EEF4\n\
	bl __errno\n\
	ldr r1, [sp, #0x20]\n\
	str r1, [r0]\n\
_0824EEF4:\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	b _0824EF18\n\
	.align 2, 0\n\
_0824EEFC: .4byte u32_085a90b8\n\
_0824EF00: .4byte 0x3FF00000\n\
_0824EF04: .4byte 0x00000000\n\
_0824EF08: .4byte name\n\
_0824EF0C: .4byte 0x00000000\n\
_0824EF10: .4byte 0x00000000\n\
_0824EF14:\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
_0824EF18:\n\
	add sp, #0x24\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7, pc}\n\
 .syntax divided\n");
}
