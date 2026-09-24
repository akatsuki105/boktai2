	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r3, r5, #0
	adds r3, #0xc6
	ldrb r0, [r3]
	cmp r0, #0
	beq _081D1502
	adds r1, #0xc4
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	strb r2, [r3]
_081D1502:
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
	beq _081D1532
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D153A
_081D1532:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D153A:
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
	beq _081D155E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D1566
_081D155E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D1566:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D159C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D15D4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D15A0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D1596
	ldrb r0, [r4, #5]
_081D1596:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D15B0
	.align 2, 0
_081D159C: .4byte 0x0000FFFF
_081D15A0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D15B0
	strh r1, [r4, #8]
_081D15B0:
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
	bne _081D15D4
	movs r0, #1
	strb r0, [r4, #7]
_081D15D4:
	adds r0, r5, #0
	bl FUN_081d1260
	adds r0, r5, #0
	bl FUN_081d1470
	adds r0, r5, #0
	bl FUN_081d1744
	adds r1, r5, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
