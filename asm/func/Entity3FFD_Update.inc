	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldr r0, [r0, #0x18]
	cmp r0, #0x32
	bhi _081FA34A
	mov r7, sb
	adds r7, #0x38
	ldrh r0, [r7, #0x1e]
	adds r0, #0x28
	strh r0, [r7, #0x1e]
	mov r4, sp
	movs r0, #6
	mov sl, r0
	mov r6, sb
	adds r6, #0x80
_081FA298:
	ldrh r1, [r6]
	movs r2, #0x1c
	adds r2, r2, r7
	mov r8, r2
	ldrh r0, [r7, #0x1c]
	subs r1, r1, r0
	strh r1, [r4]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r4, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	ble _081FA332
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081FA316
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #7
	adds r1, r5, #0
	bl Div
	strh r0, [r4]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #7
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r1, #4
	ldrsh r0, [r4, r1]
	lsls r0, r0, #7
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_081FA316:
	ldrh r0, [r4]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r6]
	ldrh r0, [r4, #2]
	mov r1, r8
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r4, #4]
	mov r2, r8
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r6, #4]
_081FA332:
	adds r7, #0x2c
	adds r6, #0x2c
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r1, sl
	cmp r1, #0
	bge _081FA298
	mov r2, sb
	ldr r0, [r2, #0x18]
	adds r0, #1
	str r0, [r2, #0x18]
_081FA34A:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
