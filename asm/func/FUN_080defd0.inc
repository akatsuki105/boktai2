	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	adds r0, #0xf3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DF02A
	adds r0, r5, #0
	adds r0, #0xf4
	ldrh r0, [r0]
	movs r2, #1
	ands r2, r0
	cmp r2, #0
	beq _080DF006
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, #0xec
	ldr r1, [r1]
	movs r2, #0
	str r2, [sp]
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	b _080DF01A
_080DF006:
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r5, #0
	adds r1, #0xec
	ldr r1, [r1]
	str r2, [sp]
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
_080DF01A:
	adds r0, r5, #0
	adds r0, #0x8c
	bl FUN_08236424
	adds r1, r5, #0
	adds r1, #0xf3
	movs r0, #0
	strb r0, [r1]
_080DF02A:
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
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
	beq _080DF05A
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080DF062
_080DF05A:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DF062:
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
	beq _080DF086
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080DF08E
_080DF086:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DF08E:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DF0C8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080DF10E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DF0D2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DF0CC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DF0E8
	.align 2, 0
_080DF0C8: .4byte 0x0000FFFF
_080DF0CC:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DF0E6
_080DF0D2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DF0E6
	strh r1, [r4, #8]
	movs r2, #1
	b _080DF0E8
_080DF0E6:
	movs r2, #0
_080DF0E8:
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
	bne _080DF110
	movs r0, #1
	strb r0, [r4, #7]
	b _080DF110
_080DF10E:
	movs r2, #0
_080DF110:
	cmp r2, #0
	beq _080DF13E
	adds r0, r5, #0
	bl FUN_0822a4e0
	adds r2, r5, #0
	adds r2, #0xf7
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r7, #0x38]
	bics r0, r1
	str r0, [r7, #0x38]
	ldrh r0, [r7, #0x3e]
	subs r0, #1
	movs r1, #0
	strh r0, [r7, #0x3e]
	movs r0, #0xff
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf6
	strb r1, [r0]
_080DF13E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
