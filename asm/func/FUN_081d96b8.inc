	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r5, r1, #0
	adds r1, #0x74
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D978C
	movs r0, #0
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x75
	ldrb r3, [r4]
	ldr r2, _081D9714 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D9718 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D971C @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r6, r5, #0
	adds r6, #0x58
	adds r7, r1, #0
	adds r7, #0xc
	ldr r2, _081D9720 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _081D9724
	asrs r1, r0, #0xc
	b _081D972A
	.align 2, 0
_081D9714: .4byte 0x030046B8
_081D9718: .4byte 0x000003FF
_081D971C: .4byte 0x0203B400
_081D9720: .4byte 0x085B0A08
_081D9724:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D972A:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081D9742
	asrs r1, r0, #0xc
	b _081D9748
_081D9742:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D9748:
	movs r0, #0
	strh r1, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrb r0, [r4]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r5, #0
	adds r0, #0x2c
	mov r2, r8
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0
	bl AuxAnim_SetAnim
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0x80
	lsls r1, r1, #4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #1
	strb r0, [r5, #7]
_081D978C:
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r2, [r5, #0x20]
	adds r0, r0, r2
	strh r0, [r5, #0x20]
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D97D4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D97DC
_081D97D4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D97DC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D9800
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D9808
_081D9800:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9808:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D9840 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9878
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9844
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9838
	ldrb r0, [r4, #5]
_081D9838:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9854
	.align 2, 0
_081D9840: .4byte 0x0000FFFF
_081D9844:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9854
	strh r1, [r4, #8]
_081D9854:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9878
	movs r0, #1
	strb r0, [r4, #7]
_081D9878:
	adds r0, r5, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9892
	adds r1, r5, #0
	adds r1, #0x68
	movs r0, #5
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
_081D9892:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
