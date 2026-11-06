	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r5, #0
	adds r0, r5, #0
	adds r0, #0x98
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _081EFC18
	movs r2, #2
	cmp r0, #0x32
	bhi _081EFBB8
	movs r2, #0
	cmp r0, #0x1e
	bls _081EFBB8
	movs r2, #1
_081EFBB8:
	adds r4, r6, #0
	adds r4, #0x98
	ldrh r0, [r4]
	ldr r1, _081EFBE0 @ =0x085AE508
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _081EFBE8
	ldr r1, [r5]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081EFBE4
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081EFBE6
	.align 2, 0
_081EFBE0: .4byte 0x085AE508
_081EFBE4:
	orrs r1, r2
_081EFBE6:
	str r1, [r5]
_081EFBE8:
	ldrh r0, [r4]
	cmp r0, #0x46
	bls _081EFC18
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r4, r6, #0
	adds r4, #0x97
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r1, r0
	ldr r0, [r7, #0x38]
	bics r0, r1
	str r0, [r7, #0x38]
	adds r1, r6, #0
	adds r1, #0x96
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r4]
_081EFC18:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
