	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x20
	movs r6, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08205076
	strb r6, [r5, #9]
	strb r6, [r5, #7]
	ldrb r2, [r5, #0x1b]
	adds r0, r5, #0
	adds r0, #0x61
	movs r4, #0
	strb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	movs r6, #1
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	strh r4, [r7, #6]
_08205076:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082050F0
	cmp r6, #0
	beq _08205098
	movs r0, #0x8f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08205098:
	ldrh r0, [r5, #0xe]
	movs r4, #1
	movs r6, #0
	orrs r0, r4
	strh r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _082050F0
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	ldr r1, _082050F8 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r5, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0
	str r0, [r5, #0x10]
	strb r4, [r5, #9]
	strb r6, [r5, #0x18]
	ldrh r0, [r5, #0xc]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _082050F0
	movs r0, #0x90
	lsls r0, r0, #1
	bl PlaySound_082406e0
	mvns r0, r4
	ldrh r1, [r5, #0xc]
	ands r0, r1
	strh r0, [r5, #0xc]
_082050F0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082050F8: .4byte FUN_080421bc
