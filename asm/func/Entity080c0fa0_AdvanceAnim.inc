	push {r4, r5, lr}
	adds r2, r0, #0
	adds r0, #0x76
	ldrh r0, [r0]
	cmp r0, #2
	bhi _080C0D90
	adds r0, r2, #0
	adds r0, #0x6a
	ldrh r0, [r0]
	lsrs r0, r0, #1
	adds r0, #4
	b _080C0DD2
_080C0D90:
	adds r1, r2, #0
	adds r1, #0x6c
	ldrh r3, [r1]
	movs r0, #1
	ands r0, r3
	adds r5, r1, #0
	cmp r0, #0
	beq _080C0DA4
	movs r4, #1
	b _080C0DB4
_080C0DA4:
	lsrs r1, r3, #1
	movs r0, #1
	ands r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r4, r0, #0x1f
	movs r0, #2
	ands r4, r0
_080C0DB4:
	ldrh r1, [r5]
	movs r3, #0
	cmp r1, #2
	bls _080C0DCA
	movs r3, #8
	cmp r1, #4
	bls _080C0DCA
	movs r3, #4
	cmp r1, #5
	bhi _080C0DCA
	movs r3, #0xc
_080C0DCA:
	ldr r0, [r2, #0x18]
	orrs r0, r3
	str r0, [r2, #0x18]
	adds r0, r4, #6
_080C0DD2:
	strh r0, [r2, #0x28]
	adds r1, r2, #0
	adds r1, #0x76
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080C0DEC
	adds r0, r2, #0
	bl KillEntity
_080C0DEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
