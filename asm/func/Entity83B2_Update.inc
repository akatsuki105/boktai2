	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _08009662
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5, #0x28]
	str r1, [r5, #0x2c]
_08009662:
	ldr r4, [r5, #0x20]
	movs r6, #0
	b _080096DA
_08009668:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r5, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _080096D6
	ldr r1, [r4, #8]
	cmp r1, #0
	blt _080096AA
	ldr r0, _08009690 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _08009694
	movs r0, #1
	b _08009696
	.align 2, 0
_08009690: .4byte 0x030046A0
_08009694:
	movs r0, #0
_08009696:
	cmp r0, #0
	bne _080096AA
	ldrb r0, [r4, #4]
	cmp r0, #1
	beq _080096D6
	ldr r0, [r4, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x24]
	b _080096D6
_080096AA:
	ldrb r0, [r4, #4]
	cmp r0, #1
	beq _080096BA
	ldr r0, [r4, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x24]
_080096BA:
	ldr r0, _08009714 @ =0x085AA6AC
	ldrb r1, [r4, #5]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r3, [r1]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080092f0
_080096D6:
	adds r6, #1
	adds r4, #0x6c
_080096DA:
	ldrb r0, [r5, #0x18]
	cmp r6, r0
	blt _08009668
	ldrb r3, [r5, #0x1a]
	movs r2, #0x1a
	ldrsb r2, [r5, r2]
	cmp r2, #0
	blt _08009734
	ldrb r6, [r5, #0x19]
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _08009734
	adds r1, r0, #0
	movs r0, #0x6c
	muls r1, r0, r1
	ldr r0, [r5, #0x20]
	adds r4, r0, r1
	cmp r2, #0
	bne _08009718
	movs r0, #0xff
	strb r0, [r5, #0x1a]
	ldrh r2, [r4, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08009398
	b _08009734
	.align 2, 0
_08009714: .4byte 0x085AA6AC
_08009718:
	cmp r2, #1
	bne _08009734
	movs r1, #0xff
	adds r0, r3, #0
	orrs r0, r1
	strb r0, [r5, #0x1a]
	adds r0, r6, #0
	orrs r0, r1
	strb r0, [r5, #0x19]
	ldrh r2, [r4, #0xe]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08009398
_08009734:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
