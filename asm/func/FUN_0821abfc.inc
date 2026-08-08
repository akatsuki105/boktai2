	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r2, #1
	adds r3, r6, #0
	adds r3, #0xf8
	ldr r1, [r3]
	ands r2, r1
	cmp r2, #0
	beq _0821AC14
	movs r2, #1
_0821AC14:
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r3]
	adds r7, r6, #0
	adds r7, #0xf4
	cmp r2, #0
	beq _0821AC30
	ldr r0, [r7]
	cmp r0, #0
	bne _0821AC30
	ldr r0, _0821AC44 @ =0x00000125
	bl PlaySound_082406e0
_0821AC30:
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0821AC48
	cmp r0, #1
	beq _0821AC62
	b _0821ACA8
	.align 2, 0
_0821AC44: .4byte 0x00000125
_0821AC48:
	movs r0, #2
	adds r2, r6, #0
	adds r2, #0xf8
	ldr r1, [r2]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	adds r0, r6, #0
	bl FUN_0821aa3c
	b _0821ACA8
_0821AC62:
	movs r5, #2
	adds r4, r6, #0
	adds r4, #0xf8
	ldr r1, [r4]
	adds r0, r1, #0
	ands r0, r5
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4]
	adds r0, r6, #0
	bl FUN_0821aac0
	cmp r0, #0
	beq _0821ACA8
	movs r1, #0
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #1
	adds r0, r6, r3
	str r1, [r0]
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	movs r5, #0x9c
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r0, [r0]
	cmp r0, #0
	beq _0821ACA8
	bl FUN_082318ac
_0821ACA8:
	movs r0, #0x9b
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _0821ACEE
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #0
	ldrsh r2, [r4, r5]
	muls r0, r2, r0
	movs r3, #0x99
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r5, #0
	ldrsh r3, [r1, r5]
	movs r5, #0x9a
	lsls r5, r5, #1
	adds r1, r6, r5
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r2, r1, r2
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	mov r8, r0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _0821ACFA
_0821ACEE:
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	mov r8, r2
_0821ACFA:
	ldr r0, [r7]
	cmp r0, #0
	bne _0821AD1A
	adds r0, r6, #0
	adds r0, #0x38
	adds r1, r6, #0
	adds r1, #0x18
	bl FUN_082372cc
	adds r0, r6, #0
	adds r0, #0x6c
	mov r5, r8
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	b _0821ADFC
_0821AD1A:
	adds r5, r6, #0
	adds r5, #0x98
	adds r4, r6, #0
	adds r4, #0xe0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0821AD4E
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0821AD56
_0821AD4E:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0821AD56:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0821AD7A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0821AD82
_0821AD7A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0821AD82:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0821ADB8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0821ADF0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0821ADBC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0821ADB2
	ldrb r0, [r4, #5]
_0821ADB2:
	subs r0, #1
	strh r0, [r4, #8]
	b _0821ADCC
	.align 2, 0
_0821ADB8: .4byte 0x0000FFFF
_0821ADBC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r5, [r4, #5]
	cmp r0, r5
	blo _0821ADCC
	strh r1, [r4, #8]
_0821ADCC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _0821ADF0
	movs r0, #1
	strb r0, [r4, #7]
_0821ADF0:
	adds r0, r6, #0
	adds r0, #0xa0
	mov r1, r8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_0821ADFC:
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r4, r6, r2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r0, #0
	blt _0821AE12
	asrs r0, r0, #0x10
	b _0821AE18
_0821AE12:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0821AE18:
	strh r0, [r4, #0x1c]
	movs r5, #0x88
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r0, [r0]
	cmp r0, #0
	blt _0821AE2A
	asrs r0, r0, #0x10
	b _0821AE30
_0821AE2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0821AE30:
	strh r0, [r4, #0x1e]
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	movs r1, #4
	bl Div
	strb r0, [r4, #8]
	strb r0, [r4, #9]
	ldr r1, [r4]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0821AE56
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _0821AE58
_0821AE56:
	orrs r1, r2
_0821AE58:
	str r1, [r4]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
