#include "global.h"

// newlib/libm/w_fmod.c

static const char name[] = "fmod";

// 0x0824EF24
NAKED f64 fdlibm_fmod(f64 x, f64 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #0x2c\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	adds r5, r3, #0\n\
	adds r4, r2, #0\n\
	bl __ieee754_fmod\n\
	str r0, [sp, #0x24]\n\
	str r1, [sp, #0x28]\n\
	ldr r0, _0824EF94 @ =u32_085a90b8\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r8, r0\n\
	beq _0824EFE8\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl isnan\n\
	cmp r0, #0\n\
	bne _0824EFE8\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl isnan\n\
	cmp r0, #0\n\
	bne _0824EFE8\n\
	ldr r2, _0824EF98 @ =0x00000000\n\
	ldr r3, _0824EF9C @ =0x00000000\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __eqdf2\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bne _0824EFE8\n\
	movs r0, #1\n\
	str r0, [sp]\n\
	ldr r0, _0824EFA0 @ =name\n\
	str r0, [sp, #4]\n\
	str r6, [sp, #8]\n\
	str r7, [sp, #0xc]\n\
	str r4, [sp, #0x10]\n\
	str r5, [sp, #0x14]\n\
	str r1, [sp, #0x20]\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	bne _0824EFA4\n\
	str r6, [sp, #0x18]\n\
	str r7, [sp, #0x1c]\n\
	b _0824EFAC\n\
	.align 2, 0\n\
_0824EF94: .4byte u32_085a90b8\n\
_0824EF98: .4byte 0x00000000\n\
_0824EF9C: .4byte 0x00000000\n\
_0824EFA0: .4byte name\n\
_0824EFA4:\n\
	ldr r1, _0824EFE0 @ =0xFFFFFFFF\n\
	ldr r0, _0824EFDC @ =0x7FFFFFFF\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
_0824EFAC:\n\
	ldr r0, _0824EFE4 @ =u32_085a90b8\n\
	ldr r0, [r0]\n\
	cmp r0, #2\n\
	beq _0824EFBE\n\
	mov r0, sp\n\
	bl matherr\n\
	cmp r0, #0\n\
	bne _0824EFC6\n\
_0824EFBE:\n\
	bl __errno\n\
	movs r1, #0x21\n\
	str r1, [r0]\n\
_0824EFC6:\n\
	ldr r0, [sp, #0x20]\n\
	cmp r0, #0\n\
	beq _0824EFD4\n\
	bl __errno\n\
	ldr r1, [sp, #0x20]\n\
	str r1, [r0]\n\
_0824EFD4:\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	b _0824EFEC\n\
	.align 2, 0\n\
_0824EFDC: .4byte 0x7FFFFFFF\n\
_0824EFE0: .4byte 0xFFFFFFFF\n\
_0824EFE4: .4byte u32_085a90b8\n\
_0824EFE8:\n\
	ldr r0, [sp, #0x24]\n\
	ldr r1, [sp, #0x28]\n\
_0824EFEC:\n\
	add sp, #0x2c\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7, pc}\n\
 .syntax divided\n");
}
