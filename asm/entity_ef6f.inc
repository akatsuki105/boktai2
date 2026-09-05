	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0801e26c
FUN_0801e26c: @ 0x0801E26C
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x18]
	cmp r0, #1
	beq _0801E27A
	movs r0, #0
	b _0801E280
_0801E27A:
	movs r0, #0
	strb r0, [r1, #0x18]
	movs r0, #1
_0801E280:
	pop {r1}
	bx r1

	thumb_func_start FUN_0801e284
FUN_0801e284: @ 0x0801E284
	movs r2, #0
	strb r1, [r0, #0x19]
	str r2, [r0, #0x24]
	movs r1, #1
	strb r1, [r0, #0x18]
	bx lr

	thumb_func_start FUN_0801e290
FUN_0801e290: @ 0x0801E290
	push {lr}
	strb r1, [r0, #0x1c]
	strb r2, [r0, #0x1d]
	ldrb r1, [r0, #0x1e]
	adds r1, #1
	strb r1, [r0, #0x1e]
	movs r1, #0
	bl FUN_0801e284
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801e2a8
FUN_0801e2a8: @ 0x0801E2A8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0801E310 @ =0x0000C091
	ldr r1, _0801E314 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x28]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #2
	movs r1, #2
	bl SetBGPrioDirect
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0801E318 @ =0x000092B3
	ldr r1, _0801E31C @ =0x0000A41A
	bl GetFile
	adds r1, r0, #0
	adds r0, #0x14
	str r0, [r5, #0x2c]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, _0801E320 @ =0x030043F0
	ldr r2, _0801E324 @ =0x04000018
	bl CpuSet
	movs r0, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801E310: .4byte 0x0000C091
_0801E314: .4byte 0x00009F57
_0801E318: .4byte 0x000092B3
_0801E31C: .4byte 0x0000A41A
_0801E320: .4byte 0x030043F0
_0801E324: .4byte 0x04000018

	thumb_func_start FUN_0801e328
FUN_0801e328: @ 0x0801E328
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _0801E370 @ =0x0000C091
	ldr r1, _0801E374 @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x28]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #0x18
	rsbs r0, r0, #0
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801E370: .4byte 0x0000C091
_0801E374: .4byte 0x0000A413

	thumb_func_start FUN_0801e378
FUN_0801e378: @ 0x0801E378
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r6, #0x3a
	ldrb r1, [r6]
	lsls r5, r1, #2
	adds r5, #0x9c
	adds r5, r0, r5
	lsls r4, r1, #1
	adds r4, r4, r1
	lsls r4, r4, #5
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r4, r4, r1
	adds r4, r0, r4
	adds r1, r0, #0
	adds r1, #0xb0
	adds r0, #0x66
	ldrb r2, [r0]
	adds r2, #0x14
	adds r0, r4, #0
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r1, #0
	movs r0, #1
	strh r0, [r5]
	strh r1, [r5, #2]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _0801E3CA
	movs r0, #0
	strb r0, [r6]
_0801E3CA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801e3d0
FUN_0801e3d0: @ 0x0801E3D0
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r2, #0x9c
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r3, r0, r1
	movs r6, #0
	movs r5, #4
_0801E3E0:
	ldrh r0, [r2]
	cmp r0, #1
	beq _0801E3F4
	cmp r0, #1
	ble _0801E43E
	cmp r0, #2
	beq _0801E414
	cmp r0, #3
	beq _0801E428
	b _0801E43E
_0801E3F4:
	ldrh r0, [r2, #2]
	movs r1, #8
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, #4
	movs r4, #0
	strh r1, [r3, #0x20]
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801E43E
	movs r0, #4
	strh r0, [r3, #0x20]
	movs r0, #2
	strh r0, [r2]
	strh r4, [r2, #2]
	b _0801E43E
_0801E414:
	ldrh r0, [r2, #2]
	cmp r0, #0x3f
	bls _0801E43E
	movs r0, #3
	strh r0, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	b _0801E43A
_0801E428:
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801E43E
	strh r6, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	ldr r1, _0801E454 @ =0xFFFFFDFF
	ands r0, r1
	movs r1, #1
_0801E43A:
	orrs r0, r1
	str r0, [r3, #8]
_0801E43E:
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	subs r5, #1
	adds r2, #4
	adds r3, #0x60
	cmp r5, #0
	bge _0801E3E0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E454: .4byte 0xFFFFFDFF

	thumb_func_start FUN_0801e458
FUN_0801e458: @ 0x0801E458
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801E4AC @ =0x05000002
	bl CpuSet
	mov r8, r4
	movs r7, #0
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #0xc
_0801E47E:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xb0
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801E47E
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801E4AC: .4byte 0x05000002

	thumb_func_start FUN_0801e4b0
FUN_0801e4b0: @ 0x0801E4B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	movs r2, #0xea
	lsls r2, r2, #1
	add r2, sl
	mov r1, sl
	adds r1, #0x8c
	movs r0, #0xe1
	lsls r0, r0, #4
	str r0, [r1]
	ldrb r0, [r2, #5]
	mov r1, sl
	strh r0, [r1, #0x34]
	adds r1, r0, #0
	subs r1, #0x14
	mov r2, sl
	strh r1, [r2, #0x30]
	adds r0, #0x14
	strh r0, [r2, #0x32]
	cmp r1, #0
	bge _0801E4EA
	movs r0, #0
	strh r0, [r2, #0x30]
	b _0801E4F4
_0801E4EA:
	cmp r1, #0xb0
	ble _0801E4F4
	movs r0, #0xb0
	mov r1, sl
	strh r0, [r1, #0x30]
_0801E4F4:
	mov r2, sl
	movs r1, #0x32
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _0801E502
	movs r0, #0
	b _0801E50A
_0801E502:
	cmp r0, #0xb0
	ble _0801E50C
	movs r0, #0xb0
	mov r2, sl
_0801E50A:
	strh r0, [r2, #0x32]
_0801E50C:
	movs r1, #0
	mov r0, sl
	strh r1, [r0, #0x36]
	movs r7, #0xfc
	lsls r7, r7, #1
	add r7, sl
	strh r1, [r7, #0x20]
	mov r5, sl
	adds r5, #0xb0
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #4
	movs r3, #0
	bl Sprite_SetSprite
	movs r2, #2
	mov r8, r2
	mov r0, r8
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r4, #1
	orrs r0, r4
	str r0, [r7, #8]
	movs r7, #0x96
	lsls r7, r7, #2
	add r7, sl
	movs r1, #0
	strh r1, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #3
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	mov r2, r8
	strb r2, [r7, #0x1a]
	movs r7, #0xae
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x30]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #1
	movs r3, #0
	bl Sprite_SetSprite
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	movs r7, #0xc6
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x32]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #2
	movs r3, #0
	bl Sprite_SetSprite
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	movs r7, #0xde
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x34]
	strh r0, [r7, #0x20]
	movs r2, #6
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #0
	bl Sprite_SetSprite
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r6, #2
	rsbs r6, r6, #0
	ands r0, r6
	str r0, [r7, #8]
	movs r7, #0xf6
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x36]
	subs r0, #0xb0
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #9
	movs r3, #0
	bl Sprite_SetSprite
	movs r2, #3
	mov sb, r2
	mov r0, sb
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	ands r0, r6
	str r0, [r7, #8]
	ldr r0, _0801E694 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0801E698 @ =0x000053E0
	adds r0, r0, r1
	movs r4, #0xe7
	lsls r4, r4, #3
	add r4, sl
	ldr r2, _0801E69C @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x81
	lsls r0, r0, #8
	strh r0, [r7, #0x3a]
	str r4, [r7, #0x48]
	movs r7, #0x87
	lsls r7, r7, #3
	add r7, sl
	movs r2, #0
	strh r2, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_SetSprite
	mov r0, sb
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	ands r0, r6
	str r0, [r7, #8]
	movs r7, #0x93
	lsls r7, r7, #3
	add r7, sl
	movs r1, #0
	strh r1, [r7, #0x20]
	movs r2, #0
	str r2, [sp]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	mov r0, r8
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	ands r0, r6
	str r0, [r7, #8]
	movs r7, #0x9f
	lsls r7, r7, #3
	add r7, sl
	movs r6, #0x20
	movs r1, #0
	mov r8, r1
	movs r4, #4
_0801E65A:
	movs r0, #8
	strh r0, [r7, #0x20]
	strh r6, [r7, #0x22]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0x16
	movs r3, #0
	bl Sprite_SetSprite
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #8]
	subs r4, #1
	adds r7, #0x60
	adds r6, #8
	cmp r4, #0
	bge _0801E65A
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801E694: .4byte 0x03003584
_0801E698: .4byte 0x000053E0
_0801E69C: .4byte 0x04000008

	thumb_func_start FUN_0801e6a0
FUN_0801e6a0: @ 0x0801E6A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0801E6FC @ =0x03003584
	ldr r5, [r0]
	ldr r0, _0801E700 @ =0x000053E0
	adds r5, r5, r0
	ldr r0, [r6, #0x60]
	lsls r0, r0, #5
	movs r1, #5
	bl Div
	movs r2, #0x20
	subs r2, r2, r0
	lsls r4, r2, #5
	subs r4, r4, r2
	ldrh r3, [r5, #0x1e]
	movs r5, #0x1f
	movs r1, #0x1f
	ands r1, r3
	muls r1, r0, r1
	adds r4, r4, r1
	asrs r4, r4, #5
	lsls r2, r2, #2
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x15
	ands r1, r5
	muls r1, r0, r1
	adds r2, r2, r1
	asrs r2, r2, #5
	lsrs r3, r3, #0x1a
	ands r3, r5
	muls r0, r3, r0
	asrs r0, r0, #5
	ands r4, r5
	ands r2, r5
	lsls r2, r2, #5
	adds r4, r4, r2
	ands r0, r5
	lsls r0, r0, #0xa
	adds r4, r4, r0
	ldr r0, _0801E704 @ =0x00000756
	adds r6, r6, r0
	strh r4, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E6FC: .4byte 0x03003584
_0801E700: .4byte 0x000053E0
_0801E704: .4byte 0x00000756

	thumb_func_start FUN_0801e708
FUN_0801e708: @ 0x0801E708
	push {lr}
	movs r3, #1
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #0xc
_0801E714:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0801E714
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801e728
FUN_0801e728: @ 0x0801E728
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r0, #0xf6
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrh r0, [r7, #0x36]
	subs r0, #0xb0
	movs r3, #0
	strh r0, [r2, #0x20]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r2, r7, r1
	movs r4, #0x36
	ldrsh r1, [r7, r4]
	movs r4, #0x30
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bge _0801E770
	adds r1, r7, #0
	adds r1, #0x38
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xb0
	cmp r0, #1
	beq _0801E7BA
	movs r0, #1
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #0
	b _0801E792
_0801E770:
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bge _0801E79A
	adds r1, r7, #0
	adds r1, #0x38
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xb0
	cmp r0, #2
	beq _0801E7BA
	movs r0, #2
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #1
_0801E792:
	movs r3, #1
	bl FUN_082370cc
	b _0801E7BA
_0801E79A:
	adds r1, r7, #0
	adds r1, #0x38
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xb0
	cmp r0, #3
	beq _0801E7BA
	movs r0, #3
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl FUN_082370cc
_0801E7BA:
	movs r0, #0x20
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r4, r7, r1
	movs r5, #0xc
_0801E7C8:
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_082372cc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801E7C8
	movs r5, #0xd
	mov r0, r8
	ldrb r4, [r0]
	cmp r4, #0
	beq _0801E806
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	subs r5, #0x10
	movs r6, #0
	movs r4, #0xf
_0801E7EE:
	adds r1, r5, #6
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	adds r5, #1
	cmp r5, #0xa
	ble _0801E7EE
	b _0801E888
_0801E806:
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #3
	movs r2, #0x10
	movs r3, #2
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #4
	movs r2, #0x10
	movs r3, #3
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #5
	movs r2, #0x10
	movs r3, #4
	bl FUN_0822bcf4
	movs r5, #0
	b _0801E850
_0801E83A:
	adds r1, r5, #6
	movs r0, #0
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #2
	movs r2, #0x10
	movs r3, #5
	bl FUN_0822bcf4
	adds r5, #1
_0801E850:
	ldr r0, [r7, #0x40]
	cmp r5, r0
	blo _0801E83A
	cmp r5, #9
	bgt _0801E874
	movs r6, #0
	movs r4, #0xd
_0801E85E:
	adds r1, r5, #6
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r2, #0x10
	movs r3, #6
	bl FUN_0822bcf4
	adds r5, #1
	cmp r5, #9
	ble _0801E85E
_0801E874:
	movs r0, #0
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x10
	movs r3, #7
	bl FUN_0822bcf4
_0801E888:
	ldrb r4, [r7, #0x1f]
	mov sb, r4
	cmp r4, #0
	beq _0801E8E8
	movs r4, #0
	strb r4, [r7, #0x1f]
	str r4, [sp]
	movs r5, #0xf
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x15
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x16
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x17
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x18
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x19
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	b _0801E944
_0801E8E8:
	adds r4, r7, #0
	adds r4, #0x8c
	ldr r0, [r4]
	movs r1, #0x3c
	bl Mod
	movs r1, #0x64
	muls r0, r1, r0
	movs r1, #0x3c
	bl Div
	mov r8, r0
	ldr r0, [r4]
	movs r1, #0x3c
	bl Div
	adds r3, r0, #0
	movs r6, #0x11
	str r6, [sp]
	movs r5, #2
	str r5, [sp, #4]
	movs r4, #0xd
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #0x15
	movs r2, #0x10
	bl FUN_0822be3c
	mov r0, sb
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r1, #0x17
	movs r2, #0x10
	movs r3, #0x1b
	bl FUN_0822bcf4
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #0x18
	movs r2, #0x10
	mov r3, r8
	bl FUN_0822be3c
_0801E944:
	adds r0, r7, #0
	bl FUN_0801e6a0
	adds r0, r7, #0
	bl FUN_0801e3d0
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801e960
FUN_0801e960: @ 0x0801E960
	push {r4, r5, lr}
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r4, r0, r1
	movs r5, #0xc
_0801E96A:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801E96A
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801e980
FUN_0801e980: @ 0x0801E980
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r2, r0, r1
	adds r0, #0x67
	ldrb r0, [r0]
	strh r0, [r2, #0x20]
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	bx lr

	thumb_func_start FUN_0801e998
FUN_0801e998: @ 0x0801E998
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r2, r0, r1
	adds r0, #0x67
	ldrb r0, [r0]
	strh r0, [r2, #0x20]
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0801e9b0
FUN_0801e9b0: @ 0x0801E9B0
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x54]
	asrs r4, r0, #5
	movs r0, #0xae
	lsls r0, r0, #2
	adds r2, r3, r0
	adds r0, r4, #0
	subs r0, #0x18
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801E9D0
	movs r0, #0
	b _0801E9D6
_0801E9D0:
	cmp r0, #0xb0
	ble _0801E9D8
	movs r0, #0xb0
_0801E9D6:
	strh r0, [r2, #0x20]
_0801E9D8:
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r0, #0xc6
	lsls r0, r0, #2
	adds r2, r3, r0
	adds r0, r4, #0
	adds r0, #0x18
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801E9FA
	movs r0, #0
	b _0801EA00
_0801E9FA:
	cmp r0, #0xb0
	ble _0801EA02
	movs r0, #0xb0
_0801EA00:
	strh r0, [r2, #0x20]
_0801EA02:
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801ea14
FUN_0801ea14: @ 0x0801EA14
	adds r3, r0, #0
	movs r0, #0xae
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r0, #0xc6
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2, #8]
	orrs r0, r1
	str r0, [r2, #8]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0801ea34
FUN_0801ea34: @ 0x0801EA34
	push {lr}
	adds r2, r0, #0
	movs r3, #0
	ldr r0, [r2, #0x5c]
	cmp r0, #0
	beq _0801EA60
	ldr r0, [r2, #0x40]
	adds r0, #2
	lsls r0, r0, #2
	ldr r1, [r2, #0x50]
	adds r1, r1, r0
	str r1, [r2, #0x50]
	ldr r0, _0801EA5C @ =0x000002FF
	cmp r1, r0
	ble _0801EA78
	adds r0, #1
	str r0, [r2, #0x50]
	str r3, [r2, #0x5c]
	b _0801EA78
	.align 2, 0
_0801EA5C: .4byte 0x000002FF
_0801EA60:
	ldr r0, [r2, #0x40]
	adds r0, #2
	lsls r0, r0, #2
	ldr r1, [r2, #0x50]
	subs r1, r1, r0
	str r1, [r2, #0x50]
	ldr r0, _0801EA88 @ =0xFFFFFD00
	cmp r1, r0
	bgt _0801EA78
	str r0, [r2, #0x50]
	movs r0, #1
	str r0, [r2, #0x5c]
_0801EA78:
	ldr r1, [r2, #0x54]
	ldr r0, [r2, #0x50]
	adds r1, r1, r0
	str r1, [r2, #0x58]
	cmp r1, #0
	bge _0801EA8C
	movs r0, #0
	b _0801EA94
	.align 2, 0
_0801EA88: .4byte 0xFFFFFD00
_0801EA8C:
	movs r0, #0xb0
	lsls r0, r0, #5
	cmp r1, r0
	ble _0801EA96
_0801EA94:
	str r0, [r2, #0x58]
_0801EA96:
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	lsls r0, r0, #5
	ldr r1, [r2, #0x58]
	cmp r1, r0
	bne _0801EAA4
	movs r3, #1
_0801EAA4:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801eaac
FUN_0801eaac: @ 0x0801EAAC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	subs r5, r1, r0
	cmp r5, #0
	bge _0801EAC2
	rsbs r5, r5, #0
_0801EAC2:
	ldrh r0, [r4, #0x36]
	adds r1, r4, #0
	adds r1, #0x67
	movs r6, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0801e980
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt _0801EB32
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bgt _0801EB32
	cmp r5, #1
	bgt _0801EB0A
	adds r2, r4, #0
	adds r2, #0x39
	movs r0, #1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x80
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x7c]
	adds r0, #0x64
	str r0, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x66
	strb r6, [r0]
	b _0801EB48
_0801EB0A:
	adds r0, r4, #0
	adds r0, #0x39
	strb r6, [r0]
	adds r2, r0, #0
	cmp r5, #0x63
	bgt _0801EB1E
	ldr r0, [r4, #0x7c]
	adds r0, #0x64
	subs r0, r0, r5
	str r0, [r4, #0x7c]
_0801EB1E:
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0x66
	movs r0, #1
	strb r0, [r1]
	b _0801EB48
_0801EB32:
	adds r0, r4, #0
	adds r0, #0x88
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0x66
	movs r0, #2
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x39
_0801EB48:
	ldrb r0, [r2]
	adds r1, r7, #0
	bl FUN_0801c0d8
	adds r0, r4, #0
	bl FUN_0801e378
	ldr r0, [r4, #0x60]
	adds r0, #1
	str r0, [r4, #0x60]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801eb64
FUN_0801eb64: @ 0x0801EB64
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801EB7E
	ldrb r0, [r4, #0x1e]
	bl FUN_08047a28
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0
	strb r0, [r1]
_0801EB7E:
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	beq _0801EB9C
	ldr r1, [r4, #0x24]
	cmp r1, #0xf
	bhi _0801EB9C
	lsrs r1, r1, #1
	movs r0, #8
	subs r3, r0, r1
	adds r2, r1, #0
	adds r2, #8
	movs r0, #0
	adds r1, r3, #0
	bl FUN_0822f178
_0801EB9C:
	ldr r0, [r4, #0x24]
	adds r5, r4, #0
	adds r5, #0x22
	cmp r0, #0x1f
	bls _0801EBD8
	ldrb r0, [r5]
	cmp r0, #0
	bne _0801EBDE
	ldr r0, _0801EBF8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0801EBD8
	adds r1, r4, #0
	adds r1, #0x21
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #1
	strb r0, [r5]
	ldr r0, _0801EBFC @ =0x00000107
	bl PlaySound_082406e0
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [r1, #8]
	orrs r0, r6
	str r0, [r1, #8]
_0801EBD8:
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801EC20
_0801EBDE:
	adds r1, r4, #0
	adds r1, #0x21
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801EC00
	ldrb r0, [r4, #0x1b]
	adds r0, #1
	strb r0, [r4, #0x1b]
	ldrb r1, [r4, #0x1b]
	adds r0, r4, #0
	bl FUN_0801e284
	b _0801EC46
	.align 2, 0
_0801EBF8: .4byte 0x030044E0
_0801EBFC: .4byte 0x00000107
_0801EC00:
	subs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _0801EC46
	ldrb r0, [r1]
	movs r1, #0x10
	subs r3, r1, r0
	lsrs r0, r0, #1
	adds r2, r0, #0
	adds r2, #8
	movs r0, #0
	adds r1, r3, #0
	bl FUN_0822f178
	b _0801EC46
_0801EC20:
	ldr r0, [r4, #0x24]
	cmp r0, #0x20
	bne _0801EC36
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
_0801EC36:
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r4, r2
	bl FUN_082372cc
_0801EC46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801ec4c
FUN_0801ec4c: @ 0x0801EC4C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	ldr r0, [r4, #0x24]
	cmp r0, #0x3b
	bls _0801EC64
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_0801e290
_0801EC64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801ec6c
FUN_0801ec6c: @ 0x0801EC6C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801EC82
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0x36]
	strb r1, [r4, #0x1a]
	str r0, [r4, #0x6c]
_0801EC82:
	ldrb r5, [r4, #0x1a]
	cmp r5, #0
	beq _0801EC8E
	cmp r5, #1
	beq _0801ECC0
	b _0801ED0C
_0801EC8E:
	ldr r0, [r4, #0x24]
	movs r2, #0x1f
	ands r0, r2
	cmp r0, #0xf
	bhi _0801ECA0
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
_0801ECA0:
	ldr r0, [r4, #0x24]
	ands r0, r2
	cmp r0, #0x10
	bne _0801ECB0
	movs r0, #0xac
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801ECB0:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x59
	bls _0801ED0C
	ldrb r0, [r4, #0x1a]
	adds r0, #1
	strb r0, [r4, #0x1a]
	str r5, [r4, #0x6c]
	b _0801ED0C
_0801ECC0:
	ldr r0, [r4, #0x24]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0801ECD4
	ldr r0, [r4, #0x40]
	cmp r0, #9
	bhi _0801ECD4
	adds r0, #1
	str r0, [r4, #0x40]
_0801ECD4:
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0801ECF0
	lsls r0, r0, #3
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, _0801ECEC @ =0x000015FF
	cmp r1, r0
	ble _0801ECFC
	adds r0, #1
	b _0801ECFA
	.align 2, 0
_0801ECEC: .4byte 0x000015FF
_0801ECF0:
	ldr r1, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
_0801ECFA:
	str r0, [r4, #0x58]
_0801ECFC:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x8b
	bls _0801ED0C
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801ED0C:
	ldr r0, [r4, #0x6c]
	adds r0, #1
	str r0, [r4, #0x6c]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801ed18
FUN_0801ed18: @ 0x0801ED18
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801ED28
	movs r0, #0xb0
	strh r0, [r4, #0x36]
_0801ED28:
	ldr r1, [r4, #0x24]
	movs r0, #7
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	bne _0801ED3E
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0801ED5C
	subs r0, #1
	str r0, [r4, #0x40]
_0801ED3E:
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0801ED5C
	lsls r0, r0, #3
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, _0801ED58 @ =0x000015FF
	cmp r1, r0
	ble _0801ED68
	adds r0, #1
	b _0801ED66
	.align 2, 0
_0801ED58: .4byte 0x000015FF
_0801ED5C:
	ldr r1, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
_0801ED66:
	str r0, [r4, #0x58]
_0801ED68:
	cmp r2, #0x8b
	bls _0801ED76
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801ED76:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801ed7c
FUN_0801ed7c: @ 0x0801ED7C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801ED9A
	movs r0, #0
	strh r0, [r4, #0x36]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #0x3c
	strb r0, [r1]
	adds r1, #1
	movs r0, #3
	strb r0, [r1]
_0801ED9A:
	ldr r0, [r4, #0x24]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0801EDAE
	ldr r0, [r4, #0x40]
	cmp r0, #3
	bhi _0801EDAE
	adds r0, #1
	str r0, [r4, #0x40]
_0801EDAE:
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	subs r0, #0x28
	cmp r1, r0
	bge _0801EDF2
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0801EDE0
	lsls r0, r0, #3
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, _0801EDDC @ =0x000015FF
	adds r5, r4, #0
	adds r5, #0x6a
	cmp r1, r0
	ble _0801EE4E
	adds r0, #1
	str r0, [r4, #0x58]
	b _0801EE4E
	.align 2, 0
_0801EDDC: .4byte 0x000015FF
_0801EDE0:
	ldr r1, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
	str r0, [r4, #0x58]
	adds r5, r4, #0
	adds r5, #0x6a
	b _0801EE4E
_0801EDF2:
	lsls r0, r0, #5
	str r0, [r4, #0x58]
	adds r1, r4, #0
	adds r1, #0x6a
	ldrb r0, [r1]
	adds r5, r1, #0
	cmp r0, #0
	beq _0801EE54
	adds r3, r4, #0
	adds r3, #0x69
	ldrb r0, [r3]
	cmp r0, #0
	beq _0801EE4E
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _0801EE28
	movs r1, #0xf6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	b _0801EE4E
_0801EE28:
	cmp r0, #0
	bne _0801EE4E
	movs r0, #0xf6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r0, #0x1e
	strb r0, [r3]
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	movs r0, #0xac
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801EE4E:
	ldrb r0, [r5]
	cmp r0, #0
	bne _0801EE64
_0801EE54:
	ldr r0, [r4, #0x24]
	cmp r0, #0xef
	bls _0801EE64
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801EE64:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801ee6c
FUN_0801ee6c: @ 0x0801EE6C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801EE86
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #0x3c
	strb r0, [r1]
	adds r1, #1
	movs r0, #3
	strb r0, [r1]
_0801EE86:
	adds r0, r4, #0
	adds r0, #0x6a
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _0801EEE4
	adds r3, r4, #0
	adds r3, #0x69
	ldrb r0, [r3]
	cmp r0, #0
	beq _0801EEDE
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _0801EEB8
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	b _0801EEDE
_0801EEB8:
	cmp r0, #0
	bne _0801EEDE
	movs r0, #0xde
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r0, #0x1e
	strb r0, [r3]
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	movs r0, #0xac
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801EEDE:
	ldrb r0, [r5]
	cmp r0, #0
	bne _0801EEF4
_0801EEE4:
	ldr r0, [r4, #0x24]
	cmp r0, #0xef
	bls _0801EEF4
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801EEF4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801eefc
FUN_0801eefc: @ 0x0801EEFC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r4, r0
	adds r0, r4, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801EF32
	movs r2, #0
	movs r3, #0
	movs r0, #0x81
	strh r0, [r5, #0x18]
	movs r0, #0x78
	strh r0, [r5, #0x1a]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	strb r2, [r4, #0x1a]
	str r3, [r4, #0x6c]
	adds r1, r4, #0
	adds r1, #0x6a
	movs r0, #3
	strb r0, [r1]
_0801EF32:
	ldrb r0, [r4, #0x1a]
	cmp r0, #3
	bhi _0801EF84
	adds r0, r4, #0
	adds r0, #0x6a
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _0801EF7A
	ldr r0, [r4, #0x24]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0xf
	bhi _0801EF56
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	b _0801EF5E
_0801EF56:
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0801EF5E:
	str r0, [r5]
	ldr r0, [r4, #0x6c]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bne _0801EF84
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	movs r0, #0xac
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0801EF84
_0801EF7A:
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
_0801EF84:
	ldrb r0, [r4, #0x1a]
	cmp r0, #4
	bhi _0801F048
	lsls r0, r0, #2
	ldr r1, _0801EF94 @ =_0801EF98
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801EF94: .4byte _0801EF98
_0801EF98: @ jump table
	.4byte _0801EFAC @ case 0
	.4byte _0801EFB4 @ case 1
	.4byte _0801EFF8 @ case 2
	.4byte _0801F000 @ case 3
	.4byte _0801F02E @ case 4
_0801EFAC:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x78
	bls _0801F048
	b _0801F03E
_0801EFB4:
	movs r2, #0x36
	ldrsh r1, [r4, r2]
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge _0801EFEE
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0801EFE0
	lsls r0, r0, #3
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, _0801EFDC @ =0x000015FF
	cmp r1, r0
	ble _0801F048
	adds r0, #1
	str r0, [r4, #0x58]
	b _0801F048
	.align 2, 0
_0801EFDC: .4byte 0x000015FF
_0801EFE0:
	ldr r1, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
	str r0, [r4, #0x58]
	b _0801F048
_0801EFEE:
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	lsls r0, r0, #5
	str r0, [r4, #0x58]
	b _0801F03E
_0801EFF8:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x3c
	bls _0801F048
	b _0801F03E
_0801F000:
	ldr r0, [r4, #0x6c]
	cmp r0, #8
	bls _0801F048
	movs r0, #0x96
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r4, #0x1a]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x6c]
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x54]
	asrs r0, r0, #5
	strh r0, [r2, #0x20]
	adds r0, r4, #0
	bl FUN_0801e9b0
	b _0801F048
_0801F02E:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x3c
	bls _0801F048
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801F03E:
	ldrb r0, [r4, #0x1a]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x6c]
_0801F048:
	ldr r0, [r4, #0x6c]
	adds r0, #1
	str r0, [r4, #0x6c]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801f054
FUN_0801f054: @ 0x0801F054
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F076
	movs r1, #0
	str r1, [r4, #0x5c]
	str r1, [r4, #0x50]
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x64
	strb r1, [r0]
	subs r0, #0x2a
	strb r1, [r0]
	adds r0, #0x31
	strb r1, [r0]
_0801F076:
	adds r0, r4, #0
	bl FUN_0801ea34
	cmp r0, #0
	beq _0801F09C
	adds r1, r4, #0
	adds r1, #0x6b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0801F09C
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801F09C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801f0a4
FUN_0801f0a4: @ 0x0801F0A4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F0B8
	adds r1, r4, #0
	adds r1, #0x6b
	movs r0, #0
	strb r0, [r1]
_0801F0B8:
	adds r0, r4, #0
	bl FUN_0801ea34
	cmp r0, #0
	beq _0801F0DE
	adds r1, r4, #0
	adds r1, #0x6b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0801F0DE
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801F0DE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801f0e4
FUN_0801f0e4: @ 0x0801F0E4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F10E
	adds r2, r4, #0
	adds r2, #0x69
	movs r0, #0
	movs r1, #0x3c
	strb r1, [r2]
	adds r2, #1
	movs r1, #3
	strb r1, [r2]
	adds r1, r4, #0
	adds r1, #0x6b
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0801eaac
_0801F10E:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x3c
	bne _0801F11E
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801F11E:
	adds r0, r4, #0
	bl FUN_0801ea34
	ldr r0, [r4, #0x6c]
	adds r0, #1
	str r0, [r4, #0x6c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801f130
FUN_0801f130: @ 0x0801F130
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F14A
	movs r0, #0
	strb r0, [r4, #0x1a]
	str r0, [r4, #0x6c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0801eaac
_0801F14A:
	ldrb r5, [r4, #0x1a]
	cmp r5, #1
	beq _0801F17C
	cmp r5, #1
	bgt _0801F15A
	cmp r5, #0
	beq _0801F164
	b _0801F1C0
_0801F15A:
	cmp r5, #2
	beq _0801F188
	cmp r5, #3
	beq _0801F1A8
	b _0801F1C0
_0801F164:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x28
	bne _0801F1C0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0801eaac
	ldrb r0, [r4, #0x1a]
	adds r0, #1
	strb r0, [r4, #0x1a]
	str r5, [r4, #0x6c]
	b _0801F1C0
_0801F17C:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x28
	bne _0801F1C0
	adds r0, r4, #0
	movs r1, #1
	b _0801F198
_0801F188:
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0801F1C0
	adds r0, r4, #0
	movs r1, #0
_0801F198:
	bl FUN_0801eaac
	ldrb r0, [r4, #0x1a]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x6c]
	b _0801F1C0
_0801F1A8:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x14
	bne _0801F1C0
	movs r0, #4
	movs r1, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x6c]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0801e290
_0801F1C0:
	adds r0, r4, #0
	bl FUN_0801ea34
	ldr r0, [r4, #0x6c]
	adds r0, #1
	str r0, [r4, #0x6c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801f1d4
FUN_0801f1d4: @ 0x0801F1D4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F1EC
	adds r0, r4, #0
	bl FUN_0801ea14
	adds r0, r4, #0
	bl FUN_0801e998
_0801F1EC:
	ldr r0, [r4, #0x58]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	asrs r1, r1, #5
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x6c]
	cmp r0, #0x78
	bne _0801F208
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_0801e290
_0801F208:
	ldr r0, [r4, #0x6c]
	adds r0, #1
	str r0, [r4, #0x6c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801f214
FUN_0801f214: @ 0x0801F214
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F228
	movs r0, #0
	strb r0, [r5, #0x1a]
	str r0, [r5, #0x6c]
_0801F228:
	ldrb r0, [r5, #0x1a]
	cmp r0, #0
	beq _0801F234
	cmp r0, #1
	beq _0801F284
	b _0801F2E2
_0801F234:
	ldr r0, [r5, #0x6c]
	cmp r0, #0x59
	bhi _0801F256
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0xf
	bhi _0801F246
	movs r0, #1
	strb r0, [r5, #0x1f]
_0801F246:
	ldr r0, [r5, #0x6c]
	ands r0, r1
	cmp r0, #0x10
	bne _0801F256
	movs r0, #0xac
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801F256:
	ldr r0, [r5, #0x6c]
	cmp r0, #0x78
	bne _0801F2E2
	ldrb r0, [r5, #0x1a]
	adds r0, #1
	movs r1, #0
	strb r0, [r5, #0x1a]
	str r1, [r5, #0x6c]
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801F280 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _0801F2E2
	.align 2, 0
_0801F280: .4byte 0x0000FFFF
_0801F284:
	ldr r0, [r5, #0x6c]
	cmp r0, #0x20
	bne _0801F2E2
	movs r0, #2
	movs r4, #0
	strb r0, [r5, #0x1a]
	str r4, [r5, #0x6c]
	subs r0, #0x62
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r2, _0801F2F0 @ =0x03003E78
	ldr r0, _0801F2F4 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	ldr r1, _0801F2F8 @ =0xFFFFFBFF
	ands r0, r1
	ldr r1, _0801F2FC @ =0xFFFFF7FF
	ands r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_0801e708
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801F300 @ =0x0000FFFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0801e290
	ldr r0, _0801F304 @ =0x000006FA
	adds r1, r5, r0
	movs r0, #0x8c
	strh r0, [r1]
_0801F2E2:
	ldr r0, [r5, #0x6c]
	adds r0, #1
	str r0, [r5, #0x6c]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F2F0: .4byte 0x03003E78
_0801F2F4: .4byte 0xFFFFFDFF
_0801F2F8: .4byte 0xFFFFFBFF
_0801F2FC: .4byte 0xFFFFF7FF
_0801F300: .4byte 0x0000FFFF
_0801F304: .4byte 0x000006FA

	thumb_func_start FUN_0801f308
FUN_0801f308: @ 0x0801F308
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	ldr r0, [r4, #0x24]
	cmp r0, #0x3f
	bls _0801F320
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0801e290
_0801F320:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801f328
FUN_0801f328: @ 0x0801F328
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F354
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801F380 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #5
	bl FUN_082403d0
_0801F354:
	ldr r0, [r4, #0x24]
	cmp r0, #0x1f
	bls _0801F378
	adds r4, #0x90
	ldr r3, [r4]
	cmp r3, #0
	beq _0801F378
	ldr r2, _0801F384 @ =0x03003E78
	ldr r0, _0801F388 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r3, #0
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	str r0, [r4]
_0801F378:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801F380: .4byte 0x0000FFFF
_0801F384: .4byte 0x03003E78
_0801F388: .4byte 0xFFFFFEFF

	thumb_func_start FUN_0801f38c
FUN_0801f38c: @ 0x0801F38C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F3C6
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801F408 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #5
	bl FUN_082403d0
_0801F3C6:
	ldr r0, [r5, #0x24]
	cmp r0, #0x1f
	bls _0801F3FE
	adds r4, r5, #0
	adds r4, #0x90
	ldr r0, [r4]
	cmp r0, #0
	beq _0801F3FE
	ldr r2, _0801F40C @ =0x03003E78
	ldr r0, _0801F410 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	ldr r1, _0801F414 @ =0xFFFFFBFF
	ands r0, r1
	ldr r1, _0801F418 @ =0xFFFFFDFF
	ands r0, r1
	ldr r1, _0801F41C @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_0801e708
	ldr r0, [r4]
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	str r0, [r4]
_0801F3FE:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F408: .4byte 0x0000FFFF
_0801F40C: .4byte 0x03003E78
_0801F410: .4byte 0xFFFFF7FF
_0801F414: .4byte 0xFFFFFBFF
_0801F418: .4byte 0xFFFFFDFF
_0801F41C: .4byte 0xFFFFFEFF

	thumb_func_start EntityEF6F_Update
EntityEF6F_Update: @ 0x0801F420
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0801F470 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0801F438
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_0801e284
_0801F438:
	ldr r1, _0801F474 @ =0x085AA98C
	ldrb r0, [r4, #0x19]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0801F45C
	adds r1, r4, #0
	adds r1, #0x8c
	ldr r0, [r1]
	cmp r0, #0
	beq _0801F45C
	subs r0, #1
	str r0, [r1]
_0801F45C:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
	ldr r0, [r4, #0x58]
	movs r1, #0xb0
	lsls r1, r1, #5
	cmp r0, r1
	ble _0801F478
	str r1, [r4, #0x58]
	b _0801F480
	.align 2, 0
_0801F470: .4byte 0x030044E0
_0801F474: .4byte 0x085AA98C
_0801F478:
	cmp r0, #0
	bge _0801F480
	movs r0, #0
	str r0, [r4, #0x58]
_0801F480:
	ldr r0, [r4, #0x58]
	asrs r0, r0, #5
	strh r0, [r4, #0x36]
	ldrb r0, [r4, #0x19]
	cmp r0, #0xc
	bhi _0801F492
	adds r0, r4, #0
	bl FUN_0801e728
_0801F492:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityEF6F_Destroy
EntityEF6F_Destroy: @ 0x0801F49C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_0801e960
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #3
_0801F4AC:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge _0801F4AC
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_0822f1c0
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start EntityEF6F_Init
EntityEF6F_Init: @ 0x0801F4CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, _0801F5C8 @ =0x08DAA084
	movs r2, #0x24
	bl CopyMemory
	ldr r4, _0801F5CC @ =0x0000CB05
	ldr r1, _0801F5D0 @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r2, #0xb0
	adds r2, r2, r6
	mov r8, r2
	adds r1, r3, #0
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	mov r0, r8
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801F5D4 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r0, #0xd0
	adds r0, r0, r6
	mov r8, r0
	mov r2, r8
	adds r1, r3, #0
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	mov r0, r8
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801F5D8 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r0, #0xf0
	adds r0, r0, r6
	mov r8, r0
	mov r2, r8
	adds r1, r3, #0
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	mov r0, r8
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801F5DC @ =0x000082F1
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0x90
	str r0, [r1]
	movs r0, #0x45
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801F5C0
	bl FUN_0823d340
	adds r1, r0, #0
	movs r7, #0xeb
	lsls r7, r7, #3
	adds r0, r6, r7
	str r1, [r0]
	cmp r1, #0
	bne _0801F5E0
_0801F5C0:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801F6FE
	.align 2, 0
_0801F5C8: .4byte 0x08DAA084
_0801F5CC: .4byte 0x0000CB05
_0801F5D0: .4byte 0x0000414C
_0801F5D4: .4byte 0x0000B343
_0801F5D8: .4byte 0x00005D04
_0801F5DC: .4byte 0x000082F1
_0801F5E0:
	adds r0, r1, #0
	bl FUN_080478f0
	movs r0, #1
	movs r1, #1
	movs r2, #0x1e
	movs r3, #6
	bl FUN_08047b8c
	ldr r0, _0801F710 @ =0x0000A41A
	bl FUN_08047dc0
	movs r0, #1
	bl FUN_080477e4
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0801e2a8
	adds r0, r6, #0
	bl FUN_0801e328
	adds r0, r6, #0
	bl FUN_0801e458
	adds r0, r6, #0
	bl FUN_0801e4b0
	ldr r0, _0801F714 @ =0x00001C1A
	bl GetParticleGroup
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	add r4, sp, #0x14
	mov sl, r4
	adds r7, r1, #0
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r4, r6, r1
	movs r2, #8
	rsbs r2, r2, #0
	mov sb, r2
	movs r0, #3
	mov r8, r0
_0801F642:
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #0x11
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #0x33
	bl FUN_0822dafc
	movs r1, #1
	strb r1, [r4, #0xf]
	movs r2, #0
	str r2, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0801F718 @ =0x05000002
	bl CpuSet
	adds r5, #0x28
	adds r4, #0x28
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _0801F642
	movs r4, #0
	movs r0, #4
	str r0, [sp]
	ldr r5, _0801F71C @ =0x0000FFFF
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0801e284
	strb r4, [r6, #0x1b]
	strb r4, [r6, #0x1e]
	ldr r2, _0801F720 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0xdf
	orrs r0, r1
	ands r0, r5
	movs r1, #0x88
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x14]
	mov r5, sl
	ldr r0, [r5, #4]
	ands r0, r2
	str r0, [r5, #4]
	movs r7, #0xdb
	lsls r7, r7, #3
	adds r5, r6, r7
	movs r0, #0x88
	lsls r0, r0, #1
	adds r6, r6, r0
	str r4, [sp]
	movs r1, #1
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, sl
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #8
	movs r3, #0x51
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xaa
	bl sound_08240264
	movs r0, #0
_0801F6FE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801F710: .4byte 0x0000A41A
_0801F714: .4byte 0x00001C1A
_0801F718: .4byte 0x05000002
_0801F71C: .4byte 0x0000FFFF
_0801F720: .4byte 0xFFFF0000

	thumb_func_start EntityEF6F_Create
EntityEF6F_Create: @ 0x0801F724
	push {r4, lr}
	ldr r1, _0801F750 @ =0x0000075C
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801F75C
	ldr r1, _0801F754 @ =EntityEF6F_Update
	ldr r2, _0801F758 @ =EntityEF6F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityEF6F_Init
	cmp r0, #0
	bge _0801F75C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801F75E
	.align 2, 0
_0801F750: .4byte 0x0000075C
_0801F754: .4byte EntityEF6F_Update
_0801F758: .4byte EntityEF6F_Destroy
_0801F75C:
	adds r0, r4, #0
_0801F75E:
	pop {r4}
	pop {r1}
	bx r1
