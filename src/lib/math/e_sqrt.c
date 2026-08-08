#include "global.h"

// newlib/libm/e_sqrt.c

static const f64 one = 1.0, tiny = 1.0e-300;

// 0x08250138
NAKED f64 __ieee754_sqrt(f64 x) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0xc\n\
	adds r6, r1, #0\n\
	adds r5, r0, #0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x18\n\
	mov sl, r0\n\
	adds r3, r6, #0\n\
	adds r2, r5, #0\n\
	adds r4, r2, #0\n\
	adds r7, r3, #0\n\
	ldr r1, _08250174 @ =0x7FF00000\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, r1\n\
	bne _08250178\n\
	adds r1, r6, #0\n\
	adds r0, r5, #0\n\
	bl __muldf3\n\
	adds r3, r6, #0\n\
	adds r2, r5, #0\n\
	bl __adddf3\n\
	b _0825032C\n\
	.align 2, 0\n\
_08250174: .4byte 0x7FF00000\n\
_08250178:\n\
	cmp r2, #0\n\
	bgt _082501A8\n\
	adds r0, r4, #0\n\
	mov r1, sl\n\
	bics r0, r1\n\
	orrs r0, r7\n\
	cmp r0, #0\n\
	bne _0825018E\n\
	adds r1, r6, #0\n\
	adds r0, r5, #0\n\
	b _0825032C\n\
_0825018E:\n\
	cmp r2, #0\n\
	bge _082501A8\n\
	adds r1, r6, #0\n\
	adds r0, r5, #0\n\
	adds r3, r6, #0\n\
	adds r2, r5, #0\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __divdf3\n\
	b _0825032C\n\
_082501A8:\n\
	asrs r5, r4, #0x14\n\
	cmp r5, #0\n\
	bne _082501E8\n\
	cmp r4, #0\n\
	bne _082501BE\n\
_082501B2:\n\
	subs r5, #0x15\n\
	lsrs r0, r7, #0xb\n\
	orrs r4, r0\n\
	lsls r7, r7, #0x15\n\
	cmp r4, #0\n\
	beq _082501B2\n\
_082501BE:\n\
	movs r2, #0\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xd\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	adds r3, r5, #1\n\
	cmp r0, #0\n\
	bne _082501DA\n\
_082501CE:\n\
	lsls r4, r4, #1\n\
	adds r2, #1\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _082501CE\n\
_082501DA:\n\
	subs r5, r3, r2\n\
	movs r1, #0x20\n\
	subs r1, r1, r2\n\
	adds r0, r7, #0\n\
	lsrs r0, r1\n\
	orrs r4, r0\n\
	lsls r7, r2\n\
_082501E8:\n\
	ldr r0, _082502C8 @ =0xFFFFFC01\n\
	adds r5, r5, r0\n\
	ldr r0, _082502CC @ =0x000FFFFF\n\
	ands r4, r0\n\
	adds r0, #1\n\
	orrs r4, r0\n\
	movs r0, #1\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _0825020A\n\
	adds r0, r7, #0\n\
	mov r1, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #0x1f\n\
	adds r0, r4, r0\n\
	adds r4, r4, r0\n\
	lsls r7, r7, #1\n\
_0825020A:\n\
	asrs r5, r5, #1\n\
	adds r0, r7, #0\n\
	mov r1, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #0x1f\n\
	adds r0, r4, r0\n\
	adds r4, r4, r0\n\
	lsls r7, r7, #1\n\
	movs r0, #0\n\
	mov ip, r0\n\
	movs r6, #0\n\
	mov r8, r6\n\
	mov sb, r6\n\
	movs r3, #0x80\n\
	lsls r3, r3, #0xe\n\
_08250228:\n\
	adds r1, r6, r3\n\
	cmp r1, r4\n\
	bgt _08250234\n\
	adds r6, r1, r3\n\
	subs r4, r4, r1\n\
	add sb, r3\n\
_08250234:\n\
	adds r0, r7, #0\n\
	mov r1, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #0x1f\n\
	adds r0, r4, r0\n\
	adds r4, r4, r0\n\
	lsls r7, r7, #1\n\
	lsrs r3, r3, #1\n\
	cmp r3, #0\n\
	bne _08250228\n\
	mov r3, sl\n\
	lsls r5, r5, #0x14\n\
	str r5, [sp, #8]\n\
	cmp r1, #0\n\
	beq _0825029C\n\
_08250252:\n\
	mov r5, ip\n\
	adds r2, r5, r3\n\
	adds r1, r6, #0\n\
	cmp r1, r4\n\
	blt _08250264\n\
	cmp r1, r4\n\
	bne _08250288\n\
	cmp r2, r7\n\
	bhi _08250288\n\
_08250264:\n\
	adds r0, r2, r3\n\
	mov ip, r0\n\
	adds r0, r2, #0\n\
	mov r5, sl\n\
	ands r0, r5\n\
	cmp r0, sl\n\
	bne _0825027C\n\
	mov r0, ip\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	bne _0825027C\n\
	adds r6, r1, #1\n\
_0825027C:\n\
	subs r4, r4, r1\n\
	cmp r7, r2\n\
	bhs _08250284\n\
	subs r4, #1\n\
_08250284:\n\
	subs r7, r7, r2\n\
	add r8, r3\n\
_08250288:\n\
	adds r0, r7, #0\n\
	mov r1, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #0x1f\n\
	adds r0, r4, r0\n\
	adds r4, r4, r0\n\
	lsls r7, r7, #1\n\
	lsrs r3, r3, #1\n\
	cmp r3, #0\n\
	bne _08250252\n\
_0825029C:\n\
	orrs r4, r7\n\
	cmp r4, #0\n\
	beq _08250302\n\
	ldr r4, _082502D0 @ =0x3FF00000\n\
	ldr r5, _082502D4 @ =0x00000000\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __gedf2\n\
	cmp r0, #0\n\
	blt _08250302\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r8, r0\n\
	bne _082502D8\n\
	movs r5, #0\n\
	mov r8, r5\n\
	movs r0, #1\n\
	add sb, r0\n\
	b _08250302\n\
	.align 2, 0\n\
_082502C8: .4byte 0xFFFFFC01\n\
_082502CC: .4byte 0x000FFFFF\n\
_082502D0: .4byte 0x3FF00000\n\
_082502D4: .4byte 0x00000000\n\
_082502D8:\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __gtdf2\n\
	cmp r0, #0\n\
	ble _082502FA\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	cmp r8, r0\n\
	bne _082502F4\n\
	movs r1, #1\n\
	add sb, r1\n\
_082502F4:\n\
	movs r5, #2\n\
	add r8, r5\n\
	b _08250302\n\
_082502FA:\n\
	movs r0, #1\n\
	mov r1, r8\n\
	ands r0, r1\n\
	add r8, r0\n\
_08250302:\n\
	mov r5, sb\n\
	asrs r0, r5, #1\n\
	ldr r1, _08250338 @ =0x3FE00000\n\
	adds r4, r0, r1\n\
	mov r5, r8\n\
	lsrs r7, r5, #1\n\
	movs r0, #1\n\
	mov r1, sb\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0825031C\n\
	mov r5, sl\n\
	orrs r7, r5\n\
_0825031C:\n\
	ldr r0, [sp, #8]\n\
	adds r4, r4, r0\n\
	str r4, [sp]\n\
	str r7, [sp, #4]\n\
	ldr r4, [sp]\n\
	ldr r5, [sp, #4]\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
_0825032C:\n\
	add sp, #0xc\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7, pc}\n\
	.align 2, 0\n\
_08250338: .4byte 0x3FE00000\n\
 .syntax divided\n");
}
