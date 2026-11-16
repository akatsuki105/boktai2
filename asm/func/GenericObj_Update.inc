	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldrb r1, [r7, #2]
	cmp r1, #0
	bne _080A51EA
	b _080A5556
_080A51EA:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A5284
	adds r6, r7, #0
	adds r6, #0x82
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0x80
	ldrh r1, [r5]
	ldrh r3, [r6]
	subs r4, r1, r3
	adds r0, r7, #0
	adds r0, #0x70
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r4, r2
	mov r8, r2
	adds r2, r7, #0
	adds r2, #0x78
	movs r0, #0
	ldrsh r2, [r2, r0]
	muls r2, r3, r2
	mov r3, r8
	adds r0, r3, r2
	bl Div
	adds r1, r7, #0
	adds r1, #0x44
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x72
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r1, r7, #0
	adds r1, #0x7a
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldrh r1, [r6]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5]
	bl Div
	adds r1, r7, #0
	adds r1, #0x46
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r1, r7, #0
	adds r1, #0x7c
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldrh r1, [r6]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5]
	bl Div
	adds r1, r7, #0
	adds r1, #0x48
	strh r0, [r1]
	ldrh r0, [r6]
	ldrh r5, [r5]
	cmp r0, r5
	blo _080A5284
	ldrb r1, [r7, #2]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #2]
_080A5284:
	ldrb r1, [r7, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080A5290
	b _080A53B6
_080A5290:
	adds r3, r7, #0
	adds r3, #0x8a
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x8c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	cmp r0, r1
	blo _080A52C8
	adds r0, r7, #0
	adds r0, #0x54
	adds r1, r7, #0
	adds r1, #0x84
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x88
	ldrh r2, [r2]
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
	ldrb r1, [r7, #2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r7, #2]
	b _080A53B6
_080A52C8:
	ldr r2, _080A5408 @ =0x03003584
	adds r0, r7, #0
	adds r0, #0x84
	ldrh r1, [r0]
	adds r0, #2
	ldrh r0, [r0]
	adds r0, r1, r0
	lsls r0, r0, #5
	ldr r2, [r2]
	adds r0, r2, r0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0x88
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r2, r1
	str r2, [sp, #8]
	ldrh r1, [r4]
	ldrh r0, [r3]
	subs r1, r1, r0
	str r1, [sp, #0xc]
	adds r2, r7, #0
	adds r2, #8
	str r2, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x5a
	str r0, [sp, #0x18]
	str r3, [sp, #0x10]
	mov sb, r4
	mov sl, r2
	movs r1, #0xf
	str r1, [sp]
_080A530A:
	ldr r2, [sp, #4]
	ldrh r5, [r2]
	movs r0, #0x1f
	ands r0, r5
	lsls r5, r5, #0x10
	lsrs r3, r5, #0x15
	movs r1, #0x1f
	ands r3, r1
	lsrs r5, r5, #0x1a
	ands r5, r1
	ldr r2, [sp, #8]
	ldrh r4, [r2]
	movs r2, #0x1f
	ands r2, r4
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x15
	ands r6, r1
	lsrs r4, r4, #0x1a
	ands r4, r1
	ldr r1, [sp, #0xc]
	muls r0, r1, r0
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	mov r8, r1
	mov r1, r8
	muls r1, r2, r1
	adds r0, r0, r1
	mov r2, sb
	ldrh r1, [r2]
	str r3, [sp, #0x1c]
	bl Div
	mov r8, r0
	ldr r3, [sp, #0x1c]
	ldr r1, [sp, #0xc]
	adds r0, r3, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	muls r1, r6, r1
	adds r0, r0, r1
	mov r3, sb
	ldrh r1, [r3]
	bl Div
	adds r6, r0, #0
	ldr r1, [sp, #0xc]
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r3, sb
	ldrh r1, [r3]
	bl Div
	lsls r0, r0, #0xa
	lsls r6, r6, #5
	orrs r0, r6
	mov r1, r8
	orrs r0, r1
	mov r2, sl
	strh r0, [r2]
	ldr r3, [sp, #4]
	adds r3, #2
	str r3, [sp, #4]
	ldr r0, [sp, #8]
	adds r0, #2
	str r0, [sp, #8]
	movs r1, #2
	add sl, r1
	ldr r2, [sp]
	subs r2, #1
	str r2, [sp]
	cmp r2, #0
	bge _080A530A
	ldr r3, [sp, #0x14]
	str r3, [r7, #0x60]
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r1, #0
	ldrh r2, [r7]
	adds r0, r0, r2
	ldr r3, [sp, #0x18]
	strh r0, [r3]
_080A53B6:
	ldrb r1, [r7, #2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080A543A
	adds r3, r7, #0
	adds r3, #0x94
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x96
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	cmp r0, r1
	blo _080A540C
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x31
	strb r0, [r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x40
	bne _080A53FC
	ldr r0, [r7, #0x28]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x28]
_080A53FC:
	ldrb r1, [r7, #2]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #2]
	b _080A543A
	.align 2, 0
_080A5408: .4byte 0x03003584
_080A540C:
	ldr r0, [r7, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x28]
	adds r0, r7, #0
	adds r0, #0x90
	ldrh r2, [r0]
	ldrh r1, [r4]
	ldrh r3, [r3]
	subs r0, r1, r3
	muls r0, r2, r0
	adds r2, r7, #0
	adds r2, #0x92
	ldrh r2, [r2]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_080A543A:
	ldrb r1, [r7, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A5446
	b _080A5556
_080A5446:
	adds r6, r7, #0
	adds r6, #0x28
	adds r4, r7, #0
	adds r4, #0x9c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080A547A
	ldr r0, [r7, #0x28]
	movs r1, #4
	orrs r0, r1
	b _080A5482
_080A547A:
	ldr r0, [r7, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5482:
	str r0, [r7, #0x28]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080A54A6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080A54AE
_080A54A6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080A54AE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080A54E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080A552E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080A54F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080A54EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080A5508
	.align 2, 0
_080A54E8: .4byte 0x0000FFFF
_080A54EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _080A5506
_080A54F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080A5506
	strh r1, [r4, #8]
	movs r2, #1
	b _080A5508
_080A5506:
	movs r2, #0
_080A5508:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _080A5530
	movs r0, #1
	strb r0, [r4, #7]
	b _080A5530
_080A552E:
	movs r2, #0
_080A5530:
	cmp r2, #0
	beq _080A5556
	adds r0, r7, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A5556
	ldrb r0, [r7, #2]
	movs r1, #0xf7
	ands r1, r0
	strb r1, [r7, #2]
	adds r0, r7, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5556
	movs r1, #0
	bl VM_ExecByID
_080A5556:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
