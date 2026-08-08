#include "global.h"

// newlib/libm/e_fmod.c

static const f64 one = 1.0;
static const f64 Zero[] = {0.0, -0.0};

// 0x0824FA34
NAKED f64 __ieee754_fmod(f64 x, f64 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #0x18\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	str r2, [sp, #0x10]\n\
	str r3, [sp, #0x14]\n\
	adds r6, r0, #0\n\
	adds r7, r1, #0\n\
	adds r1, r3, #0\n\
	adds r0, r2, #0\n\
	mov ip, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x18\n\
	mov sb, r2\n\
	ands r2, r6\n\
	mov sb, r2\n\
	eors r6, r2\n\
	ldr r2, _0824FA98 @ =0x7FFFFFFF\n\
	mov r8, r2\n\
	ands r2, r0\n\
	mov r8, r2\n\
	mov r0, r8\n\
	orrs r0, r1\n\
	cmp r0, #0\n\
	beq _0824FA80\n\
	ldr r0, _0824FA9C @ =0x7FEFFFFF\n\
	cmp r6, r0\n\
	bgt _0824FA80\n\
	rsbs r0, r1, #0\n\
	orrs r0, r1\n\
	lsrs r0, r0, #0x1f\n\
	orrs r0, r2\n\
	ldr r1, _0824FAA0 @ =0x7FF00000\n\
	cmp r0, r1\n\
	bls _0824FAA4\n\
_0824FA80:\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [sp, #0x10]\n\
	ldr r3, [sp, #0x14]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __divdf3\n\
	b _0824FCC2\n\
	.align 2, 0\n\
_0824FA98: .4byte 0x7FFFFFFF\n\
_0824FA9C: .4byte 0x7FEFFFFF\n\
_0824FAA0: .4byte 0x7FF00000\n\
_0824FAA4:\n\
	cmp r6, r8\n\
	bgt _0824FABA\n\
	cmp r6, r8\n\
	bge _0824FAAE\n\
	b _0824FCBE\n\
_0824FAAE:\n\
	cmp r7, ip\n\
	bhs _0824FAB4\n\
	b _0824FCBE\n\
_0824FAB4:\n\
	cmp r7, ip\n\
	bne _0824FABA\n\
	b _0824FC92\n\
_0824FABA:\n\
	ldr r0, _0824FAD8 @ =0x000FFFFF\n\
	cmp r6, r0\n\
	bgt _0824FAF8\n\
	cmp r6, #0\n\
	bne _0824FAE0\n\
	ldr r3, _0824FADC @ =0xFFFFFBED\n\
	adds r0, r7, #0\n\
	cmp r7, #0\n\
	ble _0824FAFE\n\
_0824FACC:\n\
	subs r3, #1\n\
	lsls r0, r0, #1\n\
	cmp r0, #0\n\
	bgt _0824FACC\n\
	b _0824FAFE\n\
	.align 2, 0\n\
_0824FAD8: .4byte 0x000FFFFF\n\
_0824FADC: .4byte 0xFFFFFBED\n\
_0824FAE0:\n\
	ldr r3, _0824FAF4 @ =0xFFFFFC02\n\
	lsls r0, r6, #0xb\n\
	cmp r0, #0\n\
	ble _0824FAFE\n\
_0824FAE8:\n\
	subs r3, #1\n\
	lsls r0, r0, #1\n\
	cmp r0, #0\n\
	bgt _0824FAE8\n\
	b _0824FAFE\n\
	.align 2, 0\n\
_0824FAF4: .4byte 0xFFFFFC02\n\
_0824FAF8:\n\
	asrs r0, r6, #0x14\n\
	ldr r1, _0824FB1C @ =0xFFFFFC01\n\
	adds r3, r0, r1\n\
_0824FAFE:\n\
	ldr r0, _0824FB20 @ =0x000FFFFF\n\
	cmp r8, r0\n\
	bgt _0824FB40\n\
	mov r2, r8\n\
	cmp r2, #0\n\
	bne _0824FB28\n\
	ldr r4, _0824FB24 @ =0xFFFFFBED\n\
	mov r0, ip\n\
	cmp r0, #0\n\
	ble _0824FB48\n\
_0824FB12:\n\
	subs r4, #1\n\
	lsls r0, r0, #1\n\
	cmp r0, #0\n\
	bgt _0824FB12\n\
	b _0824FB48\n\
	.align 2, 0\n\
_0824FB1C: .4byte 0xFFFFFC01\n\
_0824FB20: .4byte 0x000FFFFF\n\
_0824FB24: .4byte 0xFFFFFBED\n\
_0824FB28:\n\
	ldr r4, _0824FB3C @ =0xFFFFFC02\n\
	mov r1, r8\n\
	lsls r0, r1, #0xb\n\
	cmp r0, #0\n\
	ble _0824FB48\n\
_0824FB32:\n\
	subs r4, #1\n\
	lsls r0, r0, #1\n\
	cmp r0, #0\n\
	bgt _0824FB32\n\
	b _0824FB48\n\
	.align 2, 0\n\
_0824FB3C: .4byte 0xFFFFFC02\n\
_0824FB40:\n\
	mov r2, r8\n\
	asrs r0, r2, #0x14\n\
	ldr r1, _0824FB58 @ =0xFFFFFC01\n\
	adds r4, r0, r1\n\
_0824FB48:\n\
	ldr r0, _0824FB5C @ =0xFFFFFC02\n\
	cmp r3, r0\n\
	blt _0824FB64\n\
	ldr r0, _0824FB60 @ =0x000FFFFF\n\
	ands r6, r0\n\
	adds r0, #1\n\
	orrs r6, r0\n\
	b _0824FB84\n\
	.align 2, 0\n\
_0824FB58: .4byte 0xFFFFFC01\n\
_0824FB5C: .4byte 0xFFFFFC02\n\
_0824FB60: .4byte 0x000FFFFF\n\
_0824FB64:\n\
	subs r2, r0, r3\n\
	cmp r2, #0x1f\n\
	bgt _0824FB7A\n\
	lsls r6, r2\n\
	movs r1, #0x20\n\
	subs r1, r1, r2\n\
	adds r0, r7, #0\n\
	lsrs r0, r1\n\
	orrs r6, r0\n\
	lsls r7, r2\n\
	b _0824FB84\n\
_0824FB7A:\n\
	adds r0, r2, #0\n\
	subs r0, #0x20\n\
	adds r6, r7, #0\n\
	lsls r6, r0\n\
	movs r7, #0\n\
_0824FB84:\n\
	ldr r0, _0824FB98 @ =0xFFFFFC02\n\
	cmp r4, r0\n\
	blt _0824FBA0\n\
	ldr r0, _0824FB9C @ =0x000FFFFF\n\
	mov r2, r8\n\
	ands r2, r0\n\
	adds r0, #1\n\
	orrs r2, r0\n\
	mov r8, r2\n\
	b _0824FBD0\n\
	.align 2, 0\n\
_0824FB98: .4byte 0xFFFFFC02\n\
_0824FB9C: .4byte 0x000FFFFF\n\
_0824FBA0:\n\
	subs r2, r0, r4\n\
	cmp r2, #0x1f\n\
	bgt _0824FBC2\n\
	mov r0, r8\n\
	lsls r0, r2\n\
	mov r8, r0\n\
	movs r1, #0x20\n\
	subs r1, r1, r2\n\
	mov r0, ip\n\
	lsrs r0, r1\n\
	mov r1, r8\n\
	orrs r1, r0\n\
	mov r8, r1\n\
	mov r0, ip\n\
	lsls r0, r2\n\
	mov ip, r0\n\
	b _0824FBD0\n\
_0824FBC2:\n\
	adds r0, r2, #0\n\
	subs r0, #0x20\n\
	mov r1, ip\n\
	lsls r1, r0\n\
	mov r8, r1\n\
	movs r2, #0\n\
	mov ip, r2\n\
_0824FBD0:\n\
	subs r2, r3, r4\n\
	b _0824FC00\n\
_0824FBD4:\n\
	mov r0, r8\n\
	subs r1, r6, r0\n\
	mov r0, ip\n\
	subs r3, r7, r0\n\
	cmp r7, ip\n\
	bhs _0824FBE2\n\
	subs r1, #1\n\
_0824FBE2:\n\
	cmp r1, #0\n\
	bge _0824FBF0\n\
	lsls r1, r6, #1\n\
	lsrs r0, r7, #0x1f\n\
	adds r6, r1, r0\n\
	lsls r7, r7, #1\n\
	b _0824FC00\n\
_0824FBF0:\n\
	adds r0, r1, #0\n\
	orrs r0, r3\n\
	cmp r0, #0\n\
	beq _0824FC92\n\
	lsls r1, r1, #1\n\
	lsrs r0, r3, #0x1f\n\
	adds r6, r1, r0\n\
	lsls r7, r3, #1\n\
_0824FC00:\n\
	adds r0, r2, #0\n\
	subs r2, #1\n\
	cmp r0, #0\n\
	bne _0824FBD4\n\
	mov r2, r8\n\
	subs r1, r6, r2\n\
	mov r0, ip\n\
	subs r3, r7, r0\n\
	cmp r7, ip\n\
	bhs _0824FC16\n\
	subs r1, #1\n\
_0824FC16:\n\
	cmp r1, #0\n\
	blt _0824FC1E\n\
	adds r6, r1, #0\n\
	adds r7, r3, #0\n\
_0824FC1E:\n\
	adds r0, r6, #0\n\
	orrs r0, r7\n\
	cmp r0, #0\n\
	beq _0824FC92\n\
	ldr r2, _0824FC5C @ =0x000FFFFF\n\
	cmp r6, r2\n\
	bgt _0824FC3A\n\
_0824FC2C:\n\
	lsls r1, r6, #1\n\
	lsrs r0, r7, #0x1f\n\
	adds r6, r1, r0\n\
	lsls r7, r7, #1\n\
	subs r4, #1\n\
	cmp r6, r2\n\
	ble _0824FC2C\n\
_0824FC3A:\n\
	ldr r0, _0824FC60 @ =0xFFFFFC02\n\
	cmp r4, r0\n\
	blt _0824FC6C\n\
	ldr r0, _0824FC64 @ =0xFFF00000\n\
	adds r6, r6, r0\n\
	ldr r1, _0824FC68 @ =0x000003FF\n\
	adds r0, r4, r1\n\
	lsls r0, r0, #0x14\n\
	orrs r6, r0\n\
	mov r2, sb\n\
	orrs r2, r6\n\
	str r2, [sp]\n\
	str r7, [sp, #4]\n\
	ldr r4, [sp]\n\
	ldr r5, [sp, #4]\n\
	b _0824FCBE\n\
	.align 2, 0\n\
_0824FC5C: .4byte 0x000FFFFF\n\
_0824FC60: .4byte 0xFFFFFC02\n\
_0824FC64: .4byte 0xFFF00000\n\
_0824FC68: .4byte 0x000003FF\n\
_0824FC6C:\n\
	subs r2, r0, r4\n\
	cmp r2, #0x14\n\
	bgt _0824FC82\n\
	lsrs r7, r2\n\
	movs r1, #0x20\n\
	subs r1, r1, r2\n\
	adds r0, r6, #0\n\
	lsls r0, r1\n\
	orrs r7, r0\n\
	asrs r6, r2\n\
	b _0824FCB2\n\
_0824FC82:\n\
	cmp r2, #0x1f\n\
	bgt _0824FCA8\n\
	movs r0, #0x20\n\
	subs r0, r0, r2\n\
	lsls r6, r0\n\
	lsrs r7, r2\n\
	orrs r7, r6\n\
	b _0824FCB0\n\
_0824FC92:\n\
	ldr r0, _0824FCA4 @ =Zero\n\
	mov r2, sb\n\
	lsrs r1, r2, #0x1f\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r0\n\
	ldr r0, [r1]\n\
	ldr r1, [r1, #4]\n\
	b _0824FCC2\n\
	.align 2, 0\n\
_0824FCA4: .4byte Zero\n\
_0824FCA8:\n\
	adds r0, r2, #0\n\
	subs r0, #0x20\n\
	adds r7, r6, #0\n\
	asrs r7, r0\n\
_0824FCB0:\n\
	mov r6, sb\n\
_0824FCB2:\n\
	mov r0, sb\n\
	orrs r0, r6\n\
	str r0, [sp, #8]\n\
	str r7, [sp, #0xc]\n\
	ldr r4, [sp, #8]\n\
	ldr r5, [sp, #0xc]\n\
_0824FCBE:\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
_0824FCC2:\n\
	add sp, #0x18\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7, pc}\n\
 .syntax divided\n");
}
