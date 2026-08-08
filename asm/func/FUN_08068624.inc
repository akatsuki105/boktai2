	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r1, _08068640 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _08068634
	b _0806893C
_08068634:
	lsls r0, r0, #2
	ldr r1, _08068644 @ =_08068648
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08068640: .4byte 0x0000037D
_08068644: .4byte _08068648
_08068648: @ jump table
	.4byte _0806865C @ case 0
	.4byte _080687A2 @ case 1
	.4byte _0806882C @ case 2
	.4byte _080688DA @ case 3
	.4byte _08068910 @ case 4
_0806865C:
	movs r2, #0xec
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x2c
	ldrsh r0, [r5, r2]
	subs r6, r1, r0
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r4, r1, r0
	adds r0, r5, #0
	bl FUN_08066fd4
	adds r7, r0, #0
	ldr r0, _080686E8 @ =0x00000951
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	muls r0, r6, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	adds r1, r7, #0
	muls r1, r7, r1
	cmp r0, r1
	bgt _08068714
	movs r7, #0
	strh r6, [r5, #0x34]
	strh r4, [r5, #0x38]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r4, r5, r2
	strb r0, [r4]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrb r0, [r4]
	cmp r0, #4
	bls _080686F4
	ldr r2, _080686EC @ =0x000002E6
	adds r0, r5, r2
	strb r7, [r0]
	ldr r0, _080686F0 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08068700
	.align 2, 0
_080686E8: .4byte 0x00000951
_080686EC: .4byte 0x000002E6
_080686F0: .4byte 0x000002E7
_080686F4:
	ldr r1, _0806870C @ =0x000002E6
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _08068710 @ =0x000002E7
	adds r0, r5, r2
	strb r7, [r0]
_08068700:
	adds r0, r5, #0
	movs r1, #8
	movs r2, #1
	bl FUN_08060b84
	b _0806893C
	.align 2, 0
_0806870C: .4byte 0x000002E6
_08068710: .4byte 0x000002E7
_08068714:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _08068738 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0806873C
	asrs r0, r0, #0xc
	b _08068742
	.align 2, 0
_08068738: .4byte 0x085B0A08
_0806873C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08068742:
	strh r0, [r5, #0x34]
	ldr r0, _0806875C @ =0x085B0A08
	movs r1, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _08068760
	asrs r0, r0, #0xc
	b _08068766
	.align 2, 0
_0806875C: .4byte 0x085B0A08
_08068760:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08068766:
	strh r0, [r5, #0x38]
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0806893C
_080687A2:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrb r0, [r4]
	movs r1, #0xc
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _080687C0
	b _0806893C
_080687C0:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080687DA
	b _08068904
_080687DA:
	ldrb r0, [r4]
	cmp r0, #5
	beq _080688B2
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080687F8
	movs r0, #0x97
	lsls r0, r0, #1
	b _080688B6
_080687F8:
	ldr r0, _08068824 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _080688B2
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r2, _08068828 @ =0x00000409
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #2
	bl FUN_08060b84
	b _0806893C
	.align 2, 0
_08068824: .4byte 0x030046A0
_08068828: .4byte 0x00000409
_0806882C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0xd
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r0, [r0]
	movs r4, #1
	ands r4, r0
	cmp r4, #0
	bne _08068868
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _08068864 @ =0x00000409
	adds r0, r5, r1
	strb r4, [r0]
	b _08068904
	.align 2, 0
_08068864: .4byte 0x00000409
_08068868:
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _08068894
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _08068890 @ =0x00000409
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x97
	lsls r0, r0, #1
	b _080688B6
	.align 2, 0
_08068890: .4byte 0x00000409
_08068894:
	ldr r0, _080688C8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	bgt _080688D0
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _080688CC @ =0x00000409
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
_080688B2:
	movs r0, #0x92
	lsls r0, r0, #1
_080688B6:
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #8
	movs r2, #3
	bl FUN_08060b84
	b _0806893C
	.align 2, 0
_080688C8: .4byte 0x030046A0
_080688CC: .4byte 0x00000409
_080688D0:
	movs r1, #0x40
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	b _0806893C
_080688DA:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0xe
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806893C
_08068904:
	adds r0, r5, #0
	movs r1, #8
	movs r2, #4
	bl FUN_08060b84
	b _0806893C
_08068910:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0xf
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806893C
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_080609dc
_0806893C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
