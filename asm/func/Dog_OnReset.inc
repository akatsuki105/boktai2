	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r3, #0
	str r3, [r1]
	adds r2, #0x18
	adds r1, r0, r2
	movs r5, #0
	strh r3, [r1]
	movs r1, #0xda
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, _0814A814 @ =0x0000FFFF
	strh r1, [r2]
	ldr r2, _0814A818 @ =0x000006D4
	adds r1, r0, r2
	strh r3, [r1]
	adds r2, #2
	adds r1, r0, r2
	strb r5, [r1]
	adds r2, #1
	adds r1, r0, r2
	strb r5, [r1]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #8
	bl ClearMemory
	adds r0, r4, #0
	bl Enemy_StepTowardPathNode
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
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
	beq _0814A81C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0814A824
	.align 2, 0
_0814A814: .4byte 0x0000FFFF
_0814A818: .4byte 0x000006D4
_0814A81C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0814A824:
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
	beq _0814A848
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0814A850
_0814A848:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0814A850:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0814A888 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0814A8C0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0814A88C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0814A880
	ldrb r0, [r4, #5]
_0814A880:
	subs r0, #1
	strh r0, [r4, #8]
	b _0814A89C
	.align 2, 0
_0814A888: .4byte 0x0000FFFF
_0814A88C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0814A89C
	strh r1, [r4, #8]
_0814A89C:
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
	bne _0814A8C0
	movs r0, #1
	strb r0, [r4, #7]
_0814A8C0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
