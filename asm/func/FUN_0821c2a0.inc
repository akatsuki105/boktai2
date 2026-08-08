	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r1, #0
	mov sb, r2
	mov r8, r3
	movs r0, #0xc0
	lsls r0, r0, #3
	adds r0, r4, r0
	str r0, [sp]
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _0821C2CC
	b _0821C3EA
_0821C2CC:
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0821C2E8
	ldr r0, _0821C2E4 @ =0x03003584
	ldr r0, [r0]
	adds r0, #0xe0
	mov sl, r0
	b _0821C2F4
	.align 2, 0
_0821C2E4: .4byte 0x03003584
_0821C2E8:
	ldr r0, _0821C31C @ =0x03003584
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r1, r1, r0
	mov sl, r1
_0821C2F4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0821c238
	mov r2, sb
	lsls r2, r2, #2
	mov sb, r2
	mov r3, r8
	lsls r3, r3, #2
	mov r8, r3
	subs r3, r3, r2
	str r3, [sp, #0xc]
	cmp r5, #1
	beq _0821C320
	cmp r5, #2
	beq _0821C334
	movs r0, #0
	str r0, [sp, #4]
	b _0821C340
	.align 2, 0
_0821C31C: .4byte 0x03003584
_0821C320:
	ldr r0, _0821C330 @ =0x03003584
	ldr r0, [r0]
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r1, r0, r1
	str r1, [sp, #4]
	b _0821C340
	.align 2, 0
_0821C330: .4byte 0x03003584
_0821C334:
	ldr r0, _0821C3FC @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r2, r0, r2
	str r2, [sp, #4]
_0821C340:
	movs r3, #0
	str r3, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x14]
	movs r1, #0
	str r1, [sp, #0x10]
	movs r7, #0x1f
	movs r2, #0x1f
	str r2, [sp, #8]
_0821C352:
	mov r3, sl
	ldrh r0, [r3]
	movs r4, #0x1f
	ands r4, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x15
	ands r5, r7
	lsrs r6, r0, #0x1a
	ands r6, r7
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _0821C386
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r1, r0
	str r1, [sp, #0x10]
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x15
	ands r2, r7
	str r2, [sp, #0x14]
	lsrs r0, r0, #0x1a
	ands r0, r7
	str r0, [sp, #0x18]
	ldr r3, [sp, #4]
	adds r3, #2
	str r3, [sp, #4]
_0821C386:
	mov r0, sb
	muls r0, r4, r0
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0xc]
	adds r1, r2, #0
	muls r1, r3, r1
	adds r0, r0, r1
	mov r1, r8
	bl Div
	adds r4, r0, #0
	ands r4, r7
	mov r0, sb
	muls r0, r5, r0
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #0xc]
	adds r1, r2, #0
	muls r1, r3, r1
	adds r0, r0, r1
	mov r1, r8
	bl Div
	adds r5, r0, #0
	ands r5, r7
	mov r0, sb
	muls r0, r6, r0
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0xc]
	adds r1, r2, #0
	muls r1, r3, r1
	adds r0, r0, r1
	mov r1, r8
	bl Div
	ands r0, r7
	lsls r0, r0, #0xa
	lsls r1, r5, #5
	orrs r0, r1
	orrs r4, r0
	ldr r0, [sp]
	strh r4, [r0]
	movs r1, #2
	add sl, r1
	adds r0, #2
	str r0, [sp]
	ldr r2, [sp, #8]
	subs r2, #1
	str r2, [sp, #8]
	cmp r2, #0
	bge _0821C352
_0821C3EA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821C3FC: .4byte 0x03003584
