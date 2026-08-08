	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _082284E8
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _082284E4 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _082284EA
	.align 2, 0
_082284E4: .4byte 0x00000F14
_082284E8:
	movs r0, #0
_082284EA:
	cmp r0, #0
	beq _08228524
	ldr r3, _08228568 @ =0x00000F15
	adds r1, r6, r3
	movs r0, #7
	strb r0, [r1]
	ldr r1, _0822856C @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _08228570 @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	adds r3, #0x13
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #7
	movs r3, #0
	bl FUN_08236fac
	adds r0, r6, #0
	bl FUN_08223998
	ldr r1, _08228574 @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_080136b4
	adds r0, r6, #0
	bl FUN_082239fc
_08228524:
	ldr r2, _08228578 @ =0x00000F4C
	adds r0, r6, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08228534
	adds r0, r6, #0
	bl _call_via_r1
_08228534:
	ldr r0, _0822857C @ =0x00000D9C
	adds r3, r6, r0
	ldr r2, _08228580 @ =0x00000E38
	adds r1, r6, r2
	ldrh r2, [r1]
	adds r0, r2, #1
	strh r0, [r1]
	movs r1, #3
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _082285DE
	ldr r2, _08228584 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #2
	bgt _0822858C
	cmp r2, #1
	bge _082285B4
	cmp r2, #0
	beq _08228594
	ldr r0, _08228588 @ =0x00000E3A
	adds r1, r6, r0
	b _082285D4
	.align 2, 0
_08228568: .4byte 0x00000F15
_0822856C: .4byte 0x00000DE4
_08228570: .4byte 0x00000E34
_08228574: .4byte 0x00000DF4
_08228578: .4byte 0x00000F4C
_0822857C: .4byte 0x00000D9C
_08228580: .4byte 0x00000E38
_08228584: .4byte 0x00000DEC
_08228588: .4byte 0x00000E3A
_0822858C:
	ldr r0, _082285A8 @ =0x00000E3A
	adds r1, r6, r0
	cmp r2, #3
	bne _082285D4
_08228594:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _082285AC
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #1
	b _082285D2
	.align 2, 0
_082285A8: .4byte 0x00000E3A
_082285AC:
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #0xf8
	b _082285D2
_082285B4:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _082285CC
	ldr r2, _082285C8 @ =0x00000E3A
	adds r1, r6, r2
	movs r0, #0xff
	b _082285D2
	.align 2, 0
_082285C8: .4byte 0x00000E3A
_082285CC:
	ldr r0, _08228614 @ =0x00000E3A
	adds r1, r6, r0
	movs r0, #8
_082285D2:
	strb r0, [r1]
_082285D4:
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
_082285DE:
	ldr r2, _08228618 @ =0x00000D9C
	adds r5, r6, r2
	ldr r3, _0822861C @ =0x00000DE4
	adds r4, r6, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08228620
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08228628
	.align 2, 0
_08228614: .4byte 0x00000E3A
_08228618: .4byte 0x00000D9C
_0822861C: .4byte 0x00000DE4
_08228620:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08228628:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0822864C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08228654
_0822864C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08228654:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0822868C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _082286D2
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08228696
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08228690
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _082286AC
	.align 2, 0
_0822868C: .4byte 0x0000FFFF
_08228690:
	subs r0, #1
	strh r0, [r4, #8]
	b _082286AA
_08228696:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _082286AA
	strh r1, [r4, #8]
	movs r2, #1
	b _082286AC
_082286AA:
	movs r2, #0
_082286AC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _082286D4
	movs r0, #1
	strb r0, [r4, #7]
	b _082286D4
_082286D2:
	movs r2, #0
_082286D4:
	ldr r3, _082286E4 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082286E4: .4byte 0x00000F14
