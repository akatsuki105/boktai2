	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xd0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080DE7B2
	subs r0, #1
	strh r0, [r1]
_080DE7B2:
	adds r4, r3, #0
	adds r4, #0xf4
	ldrh r2, [r4]
	movs r5, #4
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne _080DE7D6
	adds r1, r3, #0
	adds r1, #0x3c
	ldrh r0, [r1, #6]
	orrs r0, r5
	strh r0, [r1, #6]
	adds r1, #0x50
	ldrh r0, [r1, #6]
	orrs r0, r5
	strh r0, [r1, #6]
	b _080DE814
_080DE7D6:
	movs r1, #5
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r4]
	adds r5, r3, #0
	adds r5, #0x3c
	ldrh r2, [r5, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r5, #6]
	adds r4, r3, #0
	adds r4, #0x8c
	ldrh r0, [r4, #6]
	ands r1, r0
	strh r1, [r4, #6]
	adds r6, r3, #0
	adds r6, #0x1c
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
_080DE814:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
