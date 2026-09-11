	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	mov r8, r1
	adds r5, r2, #0
	adds r7, r3, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _0800E5EC @ =0x03002B3C
	ldr r0, [r0]
	cmp r0, #0
	bne _0800E5BE
	ldr r0, _0800E5F0 @ =0x0000C0DB
	movs r1, #0
	bl Entity0800f110_Create
	cmp r0, #0
	bne _0800E5BE
	b _0800E832
_0800E5BE:
	movs r0, #0xf4
	bl Malloc
	adds r6, r0, #0
	cmp r6, #0
	bne _0800E5CC
	b _0800E832
_0800E5CC:
	adds r0, r6, #0
	movs r1, #0xf4
	bl ClearMemory
	strh r4, [r6]
	movs r0, #0
	mov sb, r0
	mov r3, r8
	cmp r3, #1
	ble _0800E5F4
	movs r0, #2
	strb r0, [r6, #2]
	subs r0, #4
	add r0, r8
	mov sb, r0
	b _0800E5F8
	.align 2, 0
_0800E5EC: .4byte 0x03002B3C
_0800E5F0: .4byte 0x0000C0DB
_0800E5F4:
	mov r3, r8
	strb r3, [r6, #2]
_0800E5F8:
	movs r0, #0
	strb r0, [r6, #4]
	strh r0, [r6, #6]
	movs r2, #1
	strb r2, [r6, #3]
	strb r5, [r6, #5]
	strh r7, [r6, #8]
	ldr r0, [sp, #0x58]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _0800E61A
	strb r2, [r6, #0xc]
	b _0800E61E
_0800E61A:
	movs r0, #0
	strb r0, [r6, #0xc]
_0800E61E:
	ldr r0, [sp, #0x48]
	strh r0, [r6, #0x12]
	adds r5, r6, #0
	adds r5, #0x18
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r5, #0
	cmp r2, #0
	blt _0800E64C
	cmp r1, #0
	blt _0800E64C
	ldr r0, _0800E650 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800E64C
	ldr r0, _0800E654 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800E658
_0800E64C:
	movs r4, #0
	b _0800E666
	.align 2, 0
_0800E650: .4byte 0x030046A8
_0800E654: .4byte 0x030046AC
_0800E658:
	ldr r0, _0800E678 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800E666:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800E67C
	adds r0, #4
	b _0800E688
	.align 2, 0
_0800E678: .4byte 0x030046A4
_0800E67C:
	ldr r0, _0800E69C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800E688:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0800E6A0
	cmp r2, #2
	beq _0800E6A4
	b _0800E6A8
	.align 2, 0
_0800E69C: .4byte 0x030046A4
_0800E6A0:
	ldrb r0, [r5, #4]
	b _0800E6A6
_0800E6A4:
	ldrb r0, [r5]
_0800E6A6:
	subs r1, r1, r0
_0800E6A8:
	strh r1, [r6, #0x14]
	ldr r0, [sp, #0x4c]
	strh r0, [r6, #0x10]
	ldrb r0, [r6, #5]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0800E760
	movs r0, #0x50
	bl Malloc
	str r0, [r6, #0x20]
	cmp r0, #0
	bne _0800E6C6
	b _0800E832
_0800E6C6:
	movs r1, #0x50
	bl ClearMemory
	ldrb r1, [r6, #5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800E6F4
	ldr r2, _0800E6EC @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0xb4
	orrs r0, r3
	ldr r1, _0800E6F0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	b _0800E706
	.align 2, 0
_0800E6EC: .4byte 0xFFFF0000
_0800E6F0: .4byte 0x0000FFFF
_0800E6F4:
	ldr r2, _0800E750 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x5a
	orrs r0, r3
	ldr r1, _0800E754 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
_0800E706:
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r5, r1, #0
	ldr r0, [r6, #0x20]
	ldrh r1, [r6]
	ldr r2, _0800E758 @ =0x00004001
	movs r3, #0x10
	str r3, [sp]
	add r3, sp, #0x1c
	str r3, [sp, #4]
	str r5, [sp, #8]
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r6, #0x20]
	ldr r1, _0800E75C @ =FUN_0800e4a8
	adds r2, r6, #0
	bl FUN_0823651c
	ldr r0, [r6, #0x20]
	bl FUN_08236400
	ldr r0, [r6, #0x20]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _0800E762
	.align 2, 0
_0800E750: .4byte 0xFFFF0000
_0800E754: .4byte 0x0000FFFF
_0800E758: .4byte 0x00004001
_0800E75C: .4byte FUN_0800e4a8
_0800E760:
	str r1, [r6, #0x20]
_0800E762:
	ldrb r1, [r6, #5]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _0800E818
	movs r0, #0x50
	bl Malloc
	str r0, [r6, #0x24]
	cmp r0, #0
	beq _0800E832
	movs r1, #0x50
	bl ClearMemory
	ldrb r1, [r6, #5]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0800E7A8
	movs r3, #0
	movs r2, #0x78
	add r0, sp, #0x1c
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0xa0
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r0, sp, #0x24
	strh r3, [r0]
	movs r1, #0x50
	b _0800E7BC
_0800E7A8:
	movs r2, #0x3c
	add r0, sp, #0x1c
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x50
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r0, sp, #0x24
	strh r3, [r0]
	movs r1, #0x28
_0800E7BC:
	strh r1, [r0, #2]
	strh r3, [r0, #4]
	adds r5, r0, #0
	movs r4, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _0800E7CC
	ldr r4, _0800E80C @ =0x00200004
_0800E7CC:
	ldr r0, [r6, #0x24]
	ldrh r1, [r6]
	ldr r2, _0800E810 @ =0x00002001
	movs r3, #0x20
	str r3, [sp]
	add r3, sp, #0x1c
	str r3, [sp, #4]
	str r5, [sp, #8]
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r6, #0x24]
	movs r3, #0x80
	lsls r3, r3, #6
	str r4, [sp]
	movs r1, #0x3c
	str r1, [sp, #4]
	ldr r1, [sp, #0x50]
	ldr r2, [sp, #0x54]
	bl FUN_082364f8
	ldr r0, [r6, #0x24]
	ldr r1, _0800E814 @ =FUN_0800e4d8
	adds r2, r6, #0
	bl FUN_0823651c
	ldr r0, [r6, #0x24]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _0800E81A
	.align 2, 0
_0800E80C: .4byte 0x00200004
_0800E810: .4byte 0x00002001
_0800E814: .4byte FUN_0800e4d8
_0800E818:
	str r0, [r6, #0x24]
_0800E81A:
	adds r4, r6, #0
	adds r4, #0x28
	ldr r1, _0800E838 @ =0x085AA790
	ldrb r0, [r6, #2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _0800E83C
_0800E832:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800E8F6
	.align 2, 0
_0800E838: .4byte 0x085AA790
_0800E83C:
	adds r0, r6, #0
	adds r0, #0x44
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r6, #0
	adds r0, #0x4b
	movs r5, #2
	strb r5, [r0]
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	str r0, [r6, #0x60]
	str r1, [r6, #0x64]
	mov r0, r8
	cmp r0, #1
	ble _0800E868
	ldr r1, _0800E880 @ =0x0000027B
	add r1, sb
	adds r0, r4, #0
	bl Video_SetActorSpritePltt
_0800E868:
	ldrb r1, [r6, #5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800E884
	ldr r0, [r6, #0x44]
	orrs r0, r5
	str r0, [r6, #0x44]
	adds r0, r6, #0
	adds r0, #0x4d
	movs r1, #0x78
	b _0800E894
	.align 2, 0
_0800E880: .4byte 0x0000027B
_0800E884:
	ldr r0, [r6, #0x44]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x44]
	adds r0, r6, #0
	adds r0, #0x4d
	movs r1, #0x40
_0800E894:
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	ldrb r0, [r6, #0xc]
	cmp r0, #0
	beq _0800E8B6
	adds r0, r6, #0
	adds r0, #0x70
	ldr r1, _0800E904 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
_0800E8B6:
	adds r0, r6, #0
	adds r0, #0x80
	movs r1, #0x6b
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0xc8
	lsls r1, r1, #4
	str r1, [sp, #8]
	movs r5, #1
	str r5, [sp, #0xc]
	movs r1, #5
	str r1, [sp, #0x10]
	str r5, [sp, #0x14]
	movs r4, #0
	str r4, [sp, #0x18]
	adds r1, r7, #0
	movs r2, #0x50
	movs r3, #7
	bl FUN_08013ba8
	strb r5, [r6, #0xb]
	strb r4, [r6, #0xd]
	adds r0, r6, #0
	adds r0, #0xec
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	ldr r0, _0800E904 @ =0x03002B3C
	ldr r0, [r0]
	adds r1, r6, #0
	bl FUN_0800e4dc
_0800E8F6:
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E904: .4byte 0x03002B3C
