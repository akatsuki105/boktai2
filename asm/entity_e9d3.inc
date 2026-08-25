	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b4818
FUN_080b4818: @ 0x080B4818
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _080B4850 @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r2, _080B4854 @ =0x0000082E
	adds r0, r5, r2
	ldrh r2, [r0]
	ldr r3, _080B4858 @ =0x0000082C
	adds r0, r5, r3
	ldrh r0, [r0]
	muls r2, r0, r2
	ldr r0, [r1]
	adds r4, r0, r2
	cmp r4, #0
	bne _080B485C
	adds r6, r5, #0
	adds r6, #0x38
	movs r1, #0
	add r0, sp, #0xc
_080B4846:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B4846
	b _080B489C
	.align 2, 0
_080B4850: .4byte 0x030046A0
_080B4854: .4byte 0x0000082E
_080B4858: .4byte 0x0000082C
_080B485C:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	str r1, [sp, #0xc]
	adds r6, r5, #0
	adds r6, #0x38
_080B489C:
	mov r7, sp
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r5, #3
_080B48A6:
	ldm r7!, {r2}
	adds r2, #0x14
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B48A6
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start dark_loans_080b48c8
dark_loans_080b48c8: @ 0x080B48C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	ldr r1, _080B48FC @ =0x0000082E
	adds r0, r7, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _080B4900
	adds r2, r7, #0
	adds r2, #0x60
	str r2, [sp, #0x10]
	movs r0, #0x18
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0
	add r0, sp, #0xc
_080B48F0:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B48F0
	b _080B4948
	.align 2, 0
_080B48FC: .4byte 0x0000082E
_080B4900:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	str r1, [sp, #0xc]
	adds r1, r7, #0
	adds r1, #0x60
	str r1, [sp, #0x10]
	movs r2, #0x18
	adds r2, r2, r7
	mov sl, r2
_080B4948:
	mov sb, sp
	movs r0, #0x83
	lsls r0, r0, #3
	adds r5, r7, r0
	ldr r1, [sp, #0x10]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r4, r1, r2
	movs r6, #3
_080B495A:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r4]
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	mov r1, sl
	movs r3, #1
	bl Sprite_SetSprite
	adds r5, #0x60
	adds r4, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B495A
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	ldr r1, _080B49BC @ =0x0000082E
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _080B49C0 @ =0x0000082C
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r4, r1, #0
	muls r4, r0, r4
	cmp r4, #0
	bne _080B49C4
	movs r1, #0
	add r0, sp, #0xc
_080B49B0:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B49B0
	b _080B4A00
	.align 2, 0
_080B49BC: .4byte 0x0000082E
_080B49C0: .4byte 0x0000082C
_080B49C4:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	str r1, [sp, #0xc]
_080B4A00:
	mov r8, sp
	movs r0, #0xbf
	lsls r0, r0, #3
	adds r5, r7, r0
	ldr r1, [sp, #0x10]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r4, r1, r2
	movs r6, #3
_080B4A12:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r0, r8
	adds r0, #4
	mov r8, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	mov r1, sl
	movs r3, #1
	bl Sprite_SetSprite
	adds r5, #0x60
	adds r4, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B4A12
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b4a50
FUN_080b4a50: @ 0x080B4A50
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B4A70 @ =0x030046A0
	ldr r2, [r0]
	ldr r0, _080B4A74 @ =0x0000082E
	adds r1, r4, r0
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0x2e
	ldrsh r2, [r2, r1]
	cmp r0, #0
	bne _080B4A78
	movs r3, #0
	b _080B4A8A
	.align 2, 0
_080B4A70: .4byte 0x030046A0
_080B4A74: .4byte 0x0000082E
_080B4A78:
	subs r1, r0, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r2, #1
	bl Div
	adds r3, r0, #1
_080B4A8A:
	movs r0, #0xf0
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r3, #0
	subs r1, #0x98
	movs r2, #0xf3
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _080B4AB4 @ =0x0000079A
	adds r1, r4, r3
	ldr r0, _080B4AB8 @ =0x0000FFD8
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4AB4: .4byte 0x0000079A
_080B4AB8: .4byte 0x0000FFD8

	thumb_func_start FUN_080b4abc
FUN_080b4abc: @ 0x080B4ABC
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	adds r1, r3, #0
	adds r1, #0x60
	movs r2, #0x13
_080B4AC8:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B4AC8
	movs r1, #0xfb
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b4aec
FUN_080b4aec: @ 0x080B4AEC
	ldr r3, _080B4AFC @ =0x0000084C
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080B4B00 @ =0x00000844
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080B4AFC: .4byte 0x0000084C
_080B4B00: .4byte 0x00000844

	thumb_func_start FUN_080b4b04
FUN_080b4b04: @ 0x080B4B04
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r6, #0
	bl FUN_080b4abc
	ldr r0, [r6, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0x58
	adds r1, r6, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #4
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0
	bl FUN_08047a28
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B4B9C @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B4BA0 @ =FUN_080b4f08
	adds r0, r6, #0
	bl FUN_080b4aec
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B4B9C: .4byte 0x0000FFFF
_080B4BA0: .4byte FUN_080b4f08

	thumb_func_start FUN_080b4ba4
FUN_080b4ba4: @ 0x080B4BA4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r6, #0
	bl FUN_080b4abc
	ldr r0, [r6, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0x58
	adds r1, r6, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #7
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r0, _080B4C50 @ =0x00000842
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	subs r1, #0x88
	str r5, [sp]
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	movs r0, #1
	bl FUN_08047a28
	ldr r1, _080B4C54 @ =0x0000082E
	adds r0, r6, r1
	strh r5, [r0]
	ldr r1, _080B4C58 @ =FUN_080b4f48
	adds r0, r6, #0
	bl FUN_080b4aec
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B4C50: .4byte 0x00000842
_080B4C54: .4byte 0x0000082E
_080B4C58: .4byte FUN_080b4f48

	thumb_func_start FUN_080b4c5c
FUN_080b4c5c: @ 0x080B4C5C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #4
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_080b4abc
	ldr r0, [r7, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x58
	adds r6, r7, #0
	adds r6, #0x18
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #5
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0x90
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0x12
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B4D80 @ =0x0000082E
	adds r0, r7, r1
	strh r5, [r0]
	adds r6, #0x48
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #3
_080B4CD2:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B4CD2
	adds r0, r7, #0
	bl FUN_080b4818
	adds r0, r7, #0
	bl FUN_080b4a50
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r3, r6, r3
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r5, #3
_080B4D06:
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	adds r3, #0x60
	adds r2, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B4D06
	movs r4, #0
	adds r0, r7, #0
	bl dark_loans_080b48c8
	ldr r1, _080B4D84 @ =0x00000848
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B4D88 @ =0x00000804
	adds r0, r7, r1
	ldr r1, _080B4D8C @ =0x00000143
	bl FUN_0822b20c
	movs r0, #4
	bl FUN_08047a28
	ldr r1, _080B4D90 @ =0x0000083A
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	subs r1, #8
	adds r0, r7, r1
	strh r4, [r0]
	ldr r1, _080B4D94 @ =dark_loans_080b5020
	adds r0, r7, #0
	bl FUN_080b4aec
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B4D80: .4byte 0x0000082E
_080B4D84: .4byte 0x00000848
_080B4D88: .4byte 0x00000804
_080B4D8C: .4byte 0x00000143
_080B4D90: .4byte 0x0000083A
_080B4D94: .4byte dark_loans_080b5020

	thumb_func_start FUN_080b4d98
FUN_080b4d98: @ 0x080B4D98
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #5
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b4abc
	ldr r0, _080B4DFC @ =0x000002C1
	bl PlaySound_082406e0
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	movs r0, #3
	bl FUN_08047a28
	ldr r1, _080B4E00 @ =FUN_080b539c
	adds r0, r4, #0
	bl FUN_080b4aec
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B4DFC: .4byte 0x000002C1
_080B4E00: .4byte FUN_080b539c

	thumb_func_start FUN_080b4e04
FUN_080b4e04: @ 0x080B4E04
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #5
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b4abc
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	ldr r0, _080B4E54 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	bgt _080B4E58
	movs r0, #9
	bl FUN_08047a28
	b _080B4E76
	.align 2, 0
_080B4E54: .4byte 0x030046A0
_080B4E58:
	cmp r0, #5
	bgt _080B4E64
	movs r0, #0xa
	bl FUN_08047a28
	b _080B4E76
_080B4E64:
	cmp r0, #7
	bgt _080B4E70
	movs r0, #0xb
	bl FUN_08047a28
	b _080B4E76
_080B4E70:
	movs r0, #0xc
	bl FUN_08047a28
_080B4E76:
	ldr r1, _080B4E88 @ =0x080B54A1
	adds r0, r4, #0
	bl FUN_080b4aec
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4E88: .4byte 0x080B54A1

	thumb_func_start FUN_080b4e8c
FUN_080b4e8c: @ 0x080B4E8C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #5
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b4abc
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B4F00 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0xd
	bl FUN_08047a28
	ldr r1, _080B4F04 @ =FUN_080b5528
	adds r0, r4, #0
	bl FUN_080b4aec
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B4F00: .4byte 0x0000FFFF
_080B4F04: .4byte FUN_080b5528

	thumb_func_start FUN_080b4f08
FUN_080b4f08: @ 0x080B4F08
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldr r0, _080B4F44 @ =0x00000844
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x20
	bne _080B4F28
	movs r0, #0xb0
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080B4F28:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x68
	bls _080B4F3C
	adds r0, r5, #0
	bl FUN_080b4ba4
_080B4F3C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B4F44: .4byte 0x00000844

	thumb_func_start FUN_080b4f48
FUN_080b4f48: @ 0x080B4F48
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldr r0, _080B4F7C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B4F84
	ldr r1, _080B4F80 @ =0x00000842
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B4F90
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b4c5c
	b _080B4FF4
	.align 2, 0
_080B4F7C: .4byte 0x030044E0
_080B4F80: .4byte 0x00000842
_080B4F84:
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080B4F9E
_080B4F90:
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b4d98
	b _080B4FF4
_080B4F9E:
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _080B4FE8
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B4FD0 @ =0x00000842
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _080B4FD4
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	str r5, [sp]
	movs r2, #4
	b _080B4FE0
	.align 2, 0
_080B4FD0: .4byte 0x00000842
_080B4FD4:
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	str r3, [sp]
	movs r2, #5
_080B4FE0:
	movs r3, #1
	bl FUN_082370cc
	b _080B4FF4
_080B4FE8:
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	bl FUN_082372cc
_080B4FF4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b4ffc
FUN_080b4ffc: @ 0x080B4FFC
	push {lr}
	asrs r0, r0, #2
	cmp r0, #1
	beq _080B5016
	cmp r0, #1
	ble _080B501A
	cmp r0, #2
	beq _080B5012
	cmp r0, #3
	beq _080B5016
	b _080B501A
_080B5012:
	movs r0, #2
	b _080B501C
_080B5016:
	movs r0, #1
	b _080B501C
_080B501A:
	movs r0, #0
_080B501C:
	pop {r1}
	bx r1

	thumb_func_start dark_loans_080b5020
dark_loans_080b5020: @ 0x080B5020
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r0, #0x58
	movs r1, #0x18
	adds r1, r1, r5
	mov r8, r1
	bl FUN_082372cc
	ldr r1, _080B5054 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080B50B4
	ldr r2, _080B5058 @ =0x0000082E
	adds r6, r5, r2
	ldrh r0, [r6]
	cmp r0, #0
	bne _080B505C
	movs r0, #0xde
	bl PlaySound_082406e0
	b _080B509E
	.align 2, 0
_080B5054: .4byte 0x030044E0
_080B5058: .4byte 0x0000082E
_080B505C:
	ldr r3, _080B50A8 @ =0x030046A0
	ldr r1, [r3]
	ldrh r7, [r1, #0x2c]
	adds r0, r0, r7
	strh r0, [r1, #0x2c]
	ldr r1, [r3]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r2, [r6]
	ldr r7, _080B50AC @ =0x0000082C
	adds r4, r5, r7
	ldrh r0, [r4]
	muls r2, r0, r2
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, [r3]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r2, r0, r1
	ldrh r1, [r6]
	ldrh r0, [r4]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	cmp r0, #0
	bge _080B5096
	ldr r0, _080B50B0 @ =0x7FFFFFFF
_080B5096:
	str r0, [r2]
	movs r0, #0xdd
	bl PlaySound_082406e0
_080B509E:
	adds r0, r5, #0
	bl FUN_080b4d98
	b _080B538C
	.align 2, 0
_080B50A8: .4byte 0x030046A0
_080B50AC: .4byte 0x0000082C
_080B50B0: .4byte 0x7FFFFFFF
_080B50B4:
	movs r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _080B50D0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b4ba4
	b _080B538C
_080B50D0:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B5198
	ldr r0, _080B5178 @ =0x030046A0
	ldr r3, [r0]
	movs r7, #0xe2
	lsls r7, r7, #1
	adds r2, r3, r7
	ldr r0, _080B517C @ =0x0000082E
	adds r4, r5, r0
	ldrh r6, [r4]
	adds r1, r6, #1
	ldr r7, _080B5180 @ =0x0000082C
	adds r0, r5, r7
	ldrh r0, [r0]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, _080B5184 @ =0x0000270F
	cmp r0, r1
	bgt _080B5198
	movs r1, #0x2c
	ldrsh r0, [r3, r1]
	adds r0, r0, r6
	movs r2, #0x2e
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bge _080B5198
	ldr r0, _080B5188 @ =0x0000037D
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_080b4818
	adds r0, r5, #0
	bl FUN_080b4a50
	adds r0, r5, #0
	bl dark_loans_080b48c8
	movs r3, #0x84
	lsls r3, r3, #4
	adds r4, r5, r3
	movs r0, #0x13
	strh r0, [r4]
	ldr r0, _080B518C @ =0x0000083E
	adds r7, r5, r0
	ldrh r0, [r7]
	bl FUN_080b4ffc
	adds r6, r0, #0
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r4]
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B5190 @ =0x00000804
	adds r0, r5, r2
	ldr r3, _080B5194 @ =0x00000143
	adds r1, r6, r3
	bl FUN_0822b20c
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080B5172
	b _080B52BC
_080B5172:
	mov r0, sb
	strh r0, [r7]
	b _080B52BC
	.align 2, 0
_080B5178: .4byte 0x030046A0
_080B517C: .4byte 0x0000082E
_080B5180: .4byte 0x0000082C
_080B5184: .4byte 0x0000270F
_080B5188: .4byte 0x0000037D
_080B518C: .4byte 0x0000083E
_080B5190: .4byte 0x00000804
_080B5194: .4byte 0x00000143
_080B5198:
	ldr r0, _080B5228 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080B5244
	ldr r1, _080B522C @ =0x0000082E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #0
	beq _080B5244
	ldr r0, _080B5230 @ =0x0000037D
	bl PlaySound_082406e0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_080b4818
	adds r0, r5, #0
	bl FUN_080b4a50
	adds r0, r5, #0
	bl dark_loans_080b48c8
	movs r2, #0x84
	lsls r2, r2, #4
	adds r4, r5, r2
	movs r0, #0x16
	strh r0, [r4]
	ldr r3, _080B5234 @ =0x0000083E
	adds r7, r5, r3
	ldrh r0, [r7]
	bl FUN_080b4ffc
	adds r6, r0, #0
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	ldrh r2, [r4]
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B5238 @ =0x00000804
	adds r0, r5, r2
	ldr r3, _080B523C @ =0x00000143
	adds r1, r6, r3
	bl FUN_0822b20c
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080B5218
	movs r0, #0
	strh r0, [r7]
_080B5218:
	ldr r7, _080B5240 @ =0x00000848
	adds r1, r5, r7
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B52BC
	movs r0, #1
	strh r0, [r1]
	b _080B52BC
	.align 2, 0
_080B5228: .4byte 0x030044E0
_080B522C: .4byte 0x0000082E
_080B5230: .4byte 0x0000037D
_080B5234: .4byte 0x0000083E
_080B5238: .4byte 0x00000804
_080B523C: .4byte 0x00000143
_080B5240: .4byte 0x00000848
_080B5244:
	ldr r0, _080B5294 @ =0x0000083E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _080B52A0
	bl FUN_080b4ffc
	adds r6, r0, #0
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r3, #0x84
	lsls r3, r3, #4
	adds r2, r5, r3
	ldrh r2, [r2]
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	ldr r7, _080B5298 @ =0x00000804
	adds r0, r5, r7
	ldr r2, _080B529C @ =0x00000143
	adds r1, r6, r2
	bl FUN_0822b20c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080B52BC
	movs r0, #0
	strh r0, [r4]
	b _080B52BC
	.align 2, 0
_080B5294: .4byte 0x0000083E
_080B5298: .4byte 0x00000804
_080B529C: .4byte 0x00000143
_080B52A0:
	ldr r3, _080B5320 @ =0x00000804
	adds r0, r5, r3
	ldr r1, _080B5324 @ =0x00000143
	bl FUN_0822b20c
	movs r7, #0x8e
	lsls r7, r7, #2
	adds r0, r5, r7
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x12
	movs r3, #1
	bl Sprite_SetSprite
_080B52BC:
	ldr r0, _080B5328 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B52F4
	ldr r0, _080B532C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _080B5330 @ =0x0000082E
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #1
	ldr r3, _080B5334 @ =0x0000082C
	adds r1, r5, r3
	ldrh r1, [r1]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, _080B5338 @ =0x0000270F
	cmp r0, r1
	ble _080B52F4
	ldr r7, _080B533C @ =0x00000848
	adds r1, r5, r7
	movs r0, #0x3c
	strh r0, [r1]
_080B52F4:
	ldr r0, _080B533C @ =0x00000848
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B538C
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _080B5344
	adds r0, r5, #0
	bl dark_loans_080b48c8
	movs r0, #4
	bl FUN_08047a28
	ldr r1, _080B5340 @ =0x0000084A
	adds r0, r5, r1
	strh r4, [r0]
	b _080B538C
	.align 2, 0
_080B5320: .4byte 0x00000804
_080B5324: .4byte 0x00000143
_080B5328: .4byte 0x030044E0
_080B532C: .4byte 0x030046A0
_080B5330: .4byte 0x0000082E
_080B5334: .4byte 0x0000082C
_080B5338: .4byte 0x0000270F
_080B533C: .4byte 0x00000848
_080B5340: .4byte 0x0000084A
_080B5344:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r4, #1
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r2, r5, r3
	movs r7, #0x84
	lsls r7, r7, #3
	adds r1, r5, r7
	movs r3, #3
_080B5362:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _080B5362
	ldr r0, _080B5398 @ =0x0000084A
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080B538C
	movs r0, #6
	bl FUN_08047a28
	movs r0, #1
	strh r0, [r4]
_080B538C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B5398: .4byte 0x0000084A

	thumb_func_start FUN_080b539c
FUN_080b539c: @ 0x080B539C
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldr r0, _080B53E4 @ =0x00000844
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _080B5422
	ldr r1, _080B53E8 @ =0x0000082E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _080B5404
	movs r0, #5
	bl FUN_08047a28
	movs r1, #0x83
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B53EC
	movs r1, #0
	bl Script_ExecById
	b _080B53F4
	.align 2, 0
_080B53E4: .4byte 0x00000844
_080B53E8: .4byte 0x0000082E
_080B53EC:
	movs r0, #0
	movs r1, #3
	bl FUN_08047c40
_080B53F4:
	ldr r1, _080B5400 @ =FUN_080b5434
	adds r0, r4, #0
	bl FUN_080b4aec
	b _080B5422
	.align 2, 0
_080B5400: .4byte FUN_080b5434
_080B5404:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B542C @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B5430 @ =FUN_080b54ec
	adds r0, r4, #0
	bl FUN_080b4aec
_080B5422:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B542C: .4byte 0x0000FFFF
_080B5430: .4byte FUN_080b54ec

	thumb_func_start FUN_080b5434
FUN_080b5434: @ 0x080B5434
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _080B5480 @ =0x00000844
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _080B5496
	ldr r0, _080B5484 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bne _080B5490
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B5488 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B548C @ =FUN_080b54ec
	adds r0, r4, #0
	bl FUN_080b4aec
	b _080B5496
	.align 2, 0
_080B5480: .4byte 0x00000844
_080B5484: .4byte 0x030046A0
_080B5488: .4byte 0x0000FFFF
_080B548C: .4byte FUN_080b54ec
_080B5490:
	adds r0, r4, #0
	bl FUN_080b4e04
_080B5496:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B54A0:
	.byte 0x10, 0xB5, 0x83, 0xB0, 0x04, 0x1C, 0x0E, 0x48, 0x21, 0x18, 0x08, 0x88, 0x01, 0x30, 0x08, 0x80
	.byte 0x00, 0x04, 0x00, 0x0C, 0x95, 0x28, 0x0F, 0xD9, 0x04, 0x20, 0x00, 0x90, 0x09, 0x48, 0x01, 0x90
	.byte 0x00, 0x20, 0x02, 0x90, 0x03, 0x20, 0x05, 0x21, 0x04, 0x22, 0x04, 0x23, 0x87, 0xF1, 0xCC, 0xFC
	.byte 0x05, 0x49, 0x20, 0x1C, 0xFF, 0xF7, 0x0A, 0xFB, 0x03, 0xB0, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x44, 0x08, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xED, 0x54, 0x0B, 0x08

	thumb_func_start FUN_080b54ec
FUN_080b54ec: @ 0x080B54EC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B5520 @ =0x00000844
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080B5518
	ldr r1, _080B5524 @ =0x00000834
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B5518
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_080B5518:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B5520: .4byte 0x00000844
_080B5524: .4byte 0x00000834

	thumb_func_start FUN_080b5528
FUN_080b5528: @ 0x080B5528
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldr r0, _080B5584 @ =0x00000844
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x96
	bne _080B555A
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B5588 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080B555A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb5
	bls _080B557A
	ldr r1, _080B558C @ =0x00000834
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0
	bl Script_ExecById
	adds r0, r5, #0
	bl KillEntity
_080B557A:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B5584: .4byte 0x00000844
_080B5588: .4byte 0x0000FFFF
_080B558C: .4byte 0x00000834

	thumb_func_start EntityE9D3_Update
EntityE9D3_Update: @ 0x080B5590
	push {lr}
	ldr r2, _080B55A4 @ =0x0000084C
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080B55A4: .4byte 0x0000084C

	thumb_func_start EntityE9D3_Destroy
EntityE9D3_Destroy: @ 0x080B55A8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x58
	movs r5, #0x13
_080B55B2:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B55B2
	movs r1, #0xfb
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_0822a4e0
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b55d4
FUN_080b55d4: @ 0x080B55D4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080B560C @ =0x0000C091
	ldr r1, _080B5610 @ =0x000083C0
	bl GetFile
	adds r2, r0, #0
	movs r0, #0x82
	lsls r0, r0, #4
	adds r4, r4, r0
	str r2, [r4]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B560C: .4byte 0x0000C091
_080B5610: .4byte 0x000083C0

	thumb_func_start FUN_080b5614
FUN_080b5614: @ 0x080B5614
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B563C @ =0x000092B3
	ldr r1, _080B5640 @ =0x0000EAA8
	bl GetFile
	ldr r1, _080B5644 @ =0x00000824
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080B5648 @ =0x030043F0
	ldr r2, _080B564C @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B563C: .4byte 0x000092B3
_080B5640: .4byte 0x0000EAA8
_080B5644: .4byte 0x00000824
_080B5648: .4byte 0x030043F0
_080B564C: .4byte 0x04000018

