	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r6, r4, #0
	adds r6, #0x20
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08208D32
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	ldrb r0, [r4, #0x19]
	movs r2, #0xc0
	cmp r0, #1
	bls _08208D08
	movs r2, #0x80
_08208D08:
	adds r0, r4, #0
	adds r0, #0x61
	strb r2, [r0]
	lsrs r1, r2, #5
	adds r1, #3
	movs r0, #7
	ands r0, r1
	strb r0, [r4, #0x1a]
	lsrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
_08208D32:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08208E0E
	ldrh r5, [r6, #4]
	cmp r5, #1
	beq _08208D94
	cmp r5, #1
	bgt _08208D58
	cmp r5, #0
	beq _08208D62
	b _08208E0E
_08208D58:
	cmp r5, #2
	beq _08208DAC
	cmp r5, #3
	beq _08208DE2
	b _08208E0E
_08208D62:
	adds r6, r4, #0
	adds r6, #0x20
	ldrh r0, [r6, #6]
	strh r5, [r6, #6]
	cmp r0, #0
	beq _08208D7E
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_08208D7E:
	adds r0, r4, #0
	adds r0, #0xd0
	bl SpriteHolder_IsAnimEnded
	cmp r0, #0
	beq _08208E0E
	movs r0, #1
	strh r0, [r6, #4]
	strh r0, [r6, #6]
	str r5, [r6, #8]
	b _08208E0E
_08208D94:
	adds r1, r4, #0
	adds r1, #0x20
	movs r2, #0
	strh r2, [r1, #6]
	ldr r0, [r6, #8]
	cmp r0, #0x1e
	bls _08208E0E
	movs r0, #2
	strh r0, [r1, #4]
	strh r5, [r1, #6]
	str r2, [r1, #8]
	b _08208E0E
_08208DAC:
	adds r5, r4, #0
	adds r5, #0x20
	ldrh r0, [r5, #6]
	movs r6, #0
	strh r6, [r5, #6]
	cmp r0, #0
	beq _08208DCA
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_08208DCA:
	adds r0, r4, #0
	adds r0, #0xd0
	bl SpriteHolder_IsAnimEnded
	cmp r0, #0
	beq _08208E0E
	movs r0, #3
	strh r0, [r5, #4]
	movs r0, #1
	strh r0, [r5, #6]
	str r6, [r5, #8]
	b _08208E0E
_08208DE2:
	adds r0, r4, #0
	adds r0, #0x20
	ldrh r2, [r0, #6]
	movs r1, #0
	strh r1, [r0, #6]
	cmp r2, #0
	beq _08208DFE
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_08208DFE:
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r0, [r0]
	ldrb r1, [r4, #0x1b]
	cmp r0, r1
	bne _08208E0E
	movs r0, #1
	strb r0, [r4, #7]
_08208E0E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
