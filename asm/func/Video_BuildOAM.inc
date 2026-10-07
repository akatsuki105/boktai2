	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x114
	add r0, sp, #0x100
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [r0]
	ldr r2, _0822B494 @ =0x01000040
	mov r1, sp
	bl CpuFastSet
	ldr r5, _0822B498 @ =0x03003A40
	movs r4, #0
	ldr r3, _0822B49C @ =0x03003A3C
	b _0822B4B4
	.align 2, 0
_0822B494: .4byte 0x01000040
_0822B498: .4byte 0x03003A40
_0822B49C: .4byte 0x03003A3C
_0822B4A0:
	ldrh r1, [r5, #6]
	lsrs r0, r1, #8
	mov r6, sp
	adds r2, r6, r0
	ldrb r0, [r2]
	orrs r0, r1
	strh r0, [r5, #6]
	strb r4, [r2]
	adds r5, #8
	adds r4, #1
_0822B4B4:
	ldr r0, [r3]
	cmp r4, r0
	blt _0822B4A0
	ldr r0, _0822B598 @ =0x03003A38
	ldr r1, [r0]
	adds r5, r0, #0
	ldr r0, _0822B59C @ =0x03003630
	mov sb, r0
	ldr r2, _0822B5A0 @ =0x03003A30
	add r3, sp, #0x104
	movs r4, #3
_0822B4CA:
	stm r3!, {r1}
	ldrh r0, [r2]
	adds r1, r1, r0
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0822B4CA
	ldr r5, [r5]
	movs r4, #0xff
	cmp r5, #0x7f
	bgt _0822B534
	ldr r1, _0822B5A4 @ =0x03003A40
	mov sl, r1
_0822B4E4:
	mov r2, sp
	adds r0, r2, r4
	ldrb r0, [r0]
	subs r4, #1
	mov r8, r4
	cmp r0, #0xff
	beq _0822B52A
	add r7, sp, #0x104
	ldr r6, _0822B59C @ =0x03003630
	mov ip, r6
	mov r6, sl
_0822B4FA:
	lsls r0, r0, #3
	adds r4, r0, r6
	ldrh r0, [r4, #4]
	lsrs r0, r0, #0xa
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r3, r7, r0
	ldr r0, [r3]
	cmp r0, #0x7f
	bgt _0822B524
	lsls r0, r0, #3
	add r0, ip
	ldr r1, [r4]
	ldr r2, [r4, #4]
	str r1, [r0]
	str r2, [r0, #4]
	adds r5, #1
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
_0822B524:
	ldrb r0, [r4, #6]
	cmp r0, #0xff
	bne _0822B4FA
_0822B52A:
	mov r4, r8
	cmp r4, #0
	blt _0822B534
	cmp r5, #0x7f
	ble _0822B4E4
_0822B534:
	adds r4, r5, #0
	lsls r0, r4, #3
	mov r1, sb
	adds r5, r0, r1
	cmp r4, #0x7f
	bgt _0822B54E
	movs r0, #0x80
	lsls r0, r0, #2
_0822B544:
	str r0, [r5]
	adds r4, #1
	adds r5, #8
	cmp r4, #0x7f
	ble _0822B544
_0822B54E:
	mov r5, sb
	ldr r6, _0822B5A8 @ =0x030035B0
	ldr r1, _0822B5AC @ =0x03003E40
	ldr r0, [r1]
	cmp r0, #0x1f
	ble _0822B55E
	movs r0, #0x20
	str r0, [r1]
_0822B55E:
	movs r4, #0
	ldr r2, _0822B5AC @ =0x03003E40
	ldr r0, [r2]
	cmp r4, r0
	bge _0822B600
	ldr r0, _0822B5B0 @ =0x085B0A08
	mov sb, r0
_0822B56C:
	ldrb r1, [r6]
	lsls r0, r1, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	mov r8, r0
	adds r1, #0x40
	movs r0, #0xff
	ands r1, r0
	lsls r1, r1, #1
	add r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r7, r0, #2
	movs r0, #1
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bne _0822B5B4
	strh r0, [r5, #6]
	b _0822B5CC
	.align 2, 0
_0822B598: .4byte 0x03003A38
_0822B59C: .4byte 0x03003630
_0822B5A0: .4byte 0x03003A30
_0822B5A4: .4byte 0x03003A40
_0822B5A8: .4byte 0x030035B0
_0822B5AC: .4byte 0x03003E40
_0822B5B0: .4byte 0x085B0A08
_0822B5B4:
	movs r1, #1
	ldrsb r1, [r6, r1]
	adds r0, r7, #0
	bl Div
	strh r0, [r5, #6]
	mov r1, r8
	rsbs r0, r1, #0
	movs r1, #1
	ldrsb r1, [r6, r1]
	bl Div
_0822B5CC:
	strh r0, [r5, #0xe]
	movs r0, #2
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bne _0822B5DA
	strh r0, [r5, #0x16]
	b _0822B5F0
_0822B5DA:
	movs r1, #2
	ldrsb r1, [r6, r1]
	mov r0, r8
	bl Div
	strh r0, [r5, #0x16]
	movs r1, #2
	ldrsb r1, [r6, r1]
	adds r0, r7, #0
	bl Div
_0822B5F0:
	strh r0, [r5, #0x1e]
	adds r5, #0x20
	adds r6, #4
	adds r4, #1
	ldr r0, _0822B61C @ =0x03003E40
	ldr r0, [r0]
	cmp r4, r0
	blt _0822B56C
_0822B600:
	ldr r0, _0822B620 @ =0x03002CA4
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	add sp, #0x114
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822B61C: .4byte 0x03003E40
_0822B620: .4byte 0x03002CA4
