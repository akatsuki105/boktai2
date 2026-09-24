	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x34
	mov r8, r0
	ldr r2, _081D67A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D67A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D67AC @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _081D67B0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081D67B4
	asrs r1, r0, #0xc
	b _081D67BA
	.align 2, 0
_081D67A4: .4byte 0x030046B8
_081D67A8: .4byte 0x000003FF
_081D67AC: .4byte 0x0203B400
_081D67B0: .4byte 0x085B0A08
_081D67B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D67BA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081D67D4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081D67D8
	asrs r0, r0, #0xc
	b _081D67DE
	.align 2, 0
_081D67D4: .4byte 0x085B0A08
_081D67D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D67DE:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x40
	strh r0, [r2, #2]
	mov r4, r8
	adds r4, #0x1c
	ldr r2, _081D6850 @ =0x00009385
	ldr r3, _081D6854 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r4, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6858 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D685C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D6860 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r6, #0xa
	ldr r1, _081D6864 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _081D6868
	asrs r1, r0, #0xc
	b _081D686E
	.align 2, 0
_081D6850: .4byte 0x00009385
_081D6854: .4byte 0x000074C9
_081D6858: .4byte 0x030046B8
_081D685C: .4byte 0x000003FF
_081D6860: .4byte 0x0203B400
_081D6864: .4byte 0x085B0A08
_081D6868:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D686E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6888 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081D688C
	asrs r0, r0, #0xc
	b _081D6892
	.align 2, 0
_081D6888: .4byte 0x085B0A08
_081D688C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D6892:
	movs r1, #0
	strh r0, [r5, #4]
	add r2, sp, #0x2c
	movs r0, #0x22
	strh r0, [r2, #2]
	ldr r2, _081D68FC @ =0x00009385
	ldr r3, _081D6900 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6904 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D6908 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D690C @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D6910 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6914
	asrs r1, r0, #0xc
	b _081D691A
	.align 2, 0
_081D68FC: .4byte 0x00009385
_081D6900: .4byte 0x000074C9
_081D6904: .4byte 0x030046B8
_081D6908: .4byte 0x000003FF
_081D690C: .4byte 0x0203B400
_081D6910: .4byte 0x085B0A08
_081D6914:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D691A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6934 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6938
	asrs r0, r0, #0xc
	b _081D693E
	.align 2, 0
_081D6934: .4byte 0x085B0A08
_081D6938:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D693E:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D69A8 @ =0x00009385
	ldr r3, _081D69AC @ =0x000074C9
	movs r1, #1
	str r1, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r1, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D69B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D69B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D69B8 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D69BC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D69C0
	asrs r1, r0, #0xc
	b _081D69C6
	.align 2, 0
_081D69A8: .4byte 0x00009385
_081D69AC: .4byte 0x000074C9
_081D69B0: .4byte 0x030046B8
_081D69B4: .4byte 0x000003FF
_081D69B8: .4byte 0x0203B400
_081D69BC: .4byte 0x085B0A08
_081D69C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D69C6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D69E0 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D69E4
	asrs r0, r0, #0xc
	b _081D69EA
	.align 2, 0
_081D69E0: .4byte 0x085B0A08
_081D69E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D69EA:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D6A54 @ =0x00009385
	ldr r3, _081D6A58 @ =0x000074C9
	movs r1, #1
	str r1, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6A5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D6A60 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D6A64 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D6A68 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6A6C
	asrs r1, r0, #0xc
	b _081D6A72
	.align 2, 0
_081D6A54: .4byte 0x00009385
_081D6A58: .4byte 0x000074C9
_081D6A5C: .4byte 0x030046B8
_081D6A60: .4byte 0x000003FF
_081D6A64: .4byte 0x0203B400
_081D6A68: .4byte 0x085B0A08
_081D6A6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D6A72:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6A8C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6A90
	asrs r0, r0, #0xc
	b _081D6A96
	.align 2, 0
_081D6A8C: .4byte 0x085B0A08
_081D6A90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D6A96:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D6AE0 @ =0x00009385
	ldr r3, _081D6AE4 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	mov r0, r8
	bl FUN_081d65e8
	add sp, #0x34
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6AE0: .4byte 0x00009385
_081D6AE4: .4byte 0x000074C9
