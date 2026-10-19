	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r1, #0
	adds r5, r6, #0
	adds r5, #0x20
	adds r7, r6, #0
	adds r7, #0x64
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _08208B98
	movs r0, #0
	strb r0, [r6, #9]
	strb r0, [r6, #7]
	strb r0, [r6, #0x1b]
	adds r1, #0x61
	strb r0, [r1]
	movs r0, #3
	strb r0, [r6, #0x1a]
	movs r0, #1
	strb r0, [r6, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
	movs r0, #0x14
	strh r0, [r5, #0xc]
	ldrh r0, [r5, #0x10]
	strh r0, [r7]
	ldrh r0, [r5, #0x12]
	strh r0, [r7, #2]
	ldrh r0, [r5, #0x14]
	strh r0, [r7, #4]
_08208B98:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08208C5A
	movs r0, #0x80
	lsls r0, r0, #3
	ldrh r1, [r6, #0xe]
	movs r2, #0
	orrs r0, r1
	strh r0, [r6, #0xe]
	ldrh r0, [r5, #4]
	cmp r0, #0
	beq _08208BC6
	cmp r0, #1
	beq _08208C58
	b _08208C5A
_08208BC6:
	strh r2, [r5, #6]
	adds r0, r6, #0
	adds r0, #0x54
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r5, #0x10]
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r4, [r0, r2]
	ldrh r0, [r5, #0x14]
	subs r4, r4, r0
	ldr r0, [r5, #8]
	muls r0, r1, r0
	ldrh r1, [r5, #0xe]
	bl Div
	ldrh r1, [r5, #0x10]
	adds r1, r1, r0
	strh r1, [r7]
	ldr r0, [r5, #8]
	muls r0, r4, r0
	ldrh r1, [r5, #0xe]
	bl Div
	ldrh r1, [r5, #0x14]
	adds r1, r1, r0
	strh r1, [r7, #4]
	ldr r0, [r5, #8]
	lsls r0, r0, #7
	ldrh r1, [r5, #0xe]
	bl Div
	ldr r2, _08208C28 @ =gSineTable
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r1, [r1, r0]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r2, r5, #0
	cmp r0, #0
	blt _08208C2C
	asrs r1, r0, #0xc
	b _08208C32
	.align 2, 0
_08208C28: .4byte gSineTable
_08208C2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08208C32:
	ldrh r0, [r5, #0x12]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldr r0, [r5, #8]
	ldrh r5, [r5, #0xe]
	cmp r0, r5
	blo _08208C5A
	adds r0, r6, #0
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r7, #2]
	movs r0, #1
	movs r1, #1
	strh r0, [r2, #4]
	strh r0, [r2, #6]
	movs r0, #0
	str r0, [r2, #8]
	strb r1, [r6, #7]
	b _08208C5A
_08208C58:
	strh r2, [r5, #6]
_08208C5A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
