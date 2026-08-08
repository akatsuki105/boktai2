#include "global.h"

static const f64 huge = 1.0e300;

// 0x08251250
NAKED f64 fdlibm_floor(f64 x) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0xc\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	adds r7, r5, #0\n\
	adds r6, r4, #0\n\
	mov r8, r6\n\
	mov sl, r7\n\
	lsls r0, r6, #1\n\
	lsrs r0, r0, #0x15\n\
	ldr r1, _082512A0 @ =0xFFFFFC01\n\
	adds r1, r1, r0\n\
	mov sb, r1\n\
	cmp r1, #0x13\n\
	bgt _08251334\n\
	cmp r1, #0\n\
	bge _082512D8\n\
	ldr r2, _082512A4 @ =0x7E37E43C\n\
	ldr r3, _082512A8 @ =0x8800759C\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __adddf3\n\
	ldr r2, _082512AC @ =0x00000000\n\
	ldr r3, _082512B0 @ =0x00000000\n\
	bl __gtdf2\n\
	cmp r0, #0\n\
	bgt _08251294\n\
	b _082513BE\n\
_08251294:\n\
	cmp r6, #0\n\
	blt _082512B4\n\
	movs r0, #0\n\
	mov sl, r0\n\
	mov r8, r0\n\
	b _082513BE\n\
	.align 2, 0\n\
_082512A0: .4byte 0xFFFFFC01\n\
_082512A4: .4byte 0x7E37E43C\n\
_082512A8: .4byte 0x8800759C\n\
_082512AC: .4byte 0x00000000\n\
_082512B0: .4byte 0x00000000\n\
_082512B4:\n\
	ldr r0, _082512D0 @ =0x7FFFFFFF\n\
	mov r1, r8\n\
	ands r0, r1\n\
	mov r1, sl\n\
	orrs r0, r1\n\
	cmp r0, #0\n\
	bne _082512C4\n\
	b _082513BE\n\
_082512C4:\n\
	ldr r0, _082512D4 @ =0xBFF00000\n\
	mov r8, r0\n\
	movs r1, #0\n\
	mov sl, r1\n\
	b _082513BE\n\
	.align 2, 0\n\
_082512D0: .4byte 0x7FFFFFFF\n\
_082512D4: .4byte 0xBFF00000\n\
_082512D8:\n\
	ldr r0, _08251320 @ =0x000FFFFF\n\
	mov r1, sb\n\
	asrs r0, r1\n\
	str r0, [sp]\n\
	mov r0, r8\n\
	ldr r1, [sp]\n\
	ands r0, r1\n\
	mov r1, sl\n\
	orrs r0, r1\n\
	cmp r0, #0\n\
	beq _082513CA\n\
	ldr r2, _08251324 @ =0x7E37E43C\n\
	ldr r3, _08251328 @ =0x8800759C\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __adddf3\n\
	ldr r2, _0825132C @ =0x00000000\n\
	ldr r3, _08251330 @ =0x00000000\n\
	bl __gtdf2\n\
	cmp r0, #0\n\
	ble _082513BE\n\
	cmp r6, #0\n\
	bge _08251314\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0xd\n\
	mov r1, sb\n\
	asrs r0, r1\n\
	add r8, r0\n\
_08251314:\n\
	mov r0, r8\n\
	ldr r1, [sp]\n\
	bics r0, r1\n\
	mov r8, r0\n\
	movs r0, #0\n\
	b _082513BC\n\
	.align 2, 0\n\
_08251320: .4byte 0x000FFFFF\n\
_08251324: .4byte 0x7E37E43C\n\
_08251328: .4byte 0x8800759C\n\
_0825132C: .4byte 0x00000000\n\
_08251330: .4byte 0x00000000\n\
_08251334:\n\
	mov r1, sb\n\
	cmp r1, #0x33\n\
	ble _08251350\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	cmp sb, r0\n\
	bne _082513CA\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __adddf3\n\
	b _082513CE\n\
_08251350:\n\
	ldr r1, _0825138C @ =0xFFFFFBED\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	rsbs r1, r1, #0\n\
	lsrs r1, r0\n\
	str r1, [sp]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _082513CA\n\
	ldr r2, _08251390 @ =0x7E37E43C\n\
	ldr r3, _08251394 @ =0x8800759C\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __adddf3\n\
	ldr r2, _08251398 @ =0x00000000\n\
	ldr r3, _0825139C @ =0x00000000\n\
	bl __gtdf2\n\
	cmp r0, #0\n\
	ble _082513BE\n\
	cmp r6, #0\n\
	bge _082513B6\n\
	mov r0, sb\n\
	cmp r0, #0x14\n\
	bne _082513A0\n\
	movs r1, #1\n\
	add r8, r1\n\
	b _082513B6\n\
	.align 2, 0\n\
_0825138C: .4byte 0xFFFFFBED\n\
_08251390: .4byte 0x7E37E43C\n\
_08251394: .4byte 0x8800759C\n\
_08251398: .4byte 0x00000000\n\
_0825139C: .4byte 0x00000000\n\
_082513A0:\n\
	movs r1, #0x34\n\
	mov r0, sb\n\
	subs r1, r1, r0\n\
	movs r0, #1\n\
	lsls r0, r1\n\
	add r0, sl\n\
	cmp r0, sl\n\
	bhs _082513B4\n\
	movs r1, #1\n\
	add r8, r1\n\
_082513B4:\n\
	mov sl, r0\n\
_082513B6:\n\
	mov r0, sl\n\
	ldr r1, [sp]\n\
	bics r0, r1\n\
_082513BC:\n\
	mov sl, r0\n\
_082513BE:\n\
	mov r0, r8\n\
	str r0, [sp, #4]\n\
	mov r1, sl\n\
	str r1, [sp, #8]\n\
	ldr r4, [sp, #4]\n\
	ldr r5, [sp, #8]\n\
_082513CA:\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
_082513CE:\n\
	add sp, #0xc\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7, pc}\n\
 .syntax divided\n");
}
