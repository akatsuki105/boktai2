	push {r4, r5, r6, lr}
	adds r5, r1, #0
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F35F4
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r6, #0xb7
	lsls r6, r6, #1
	adds r2, r5, r6
	movs r1, #0
	movs r0, #0x14
	strh r0, [r2]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _081F3588 @ =0x0203B400
	ldr r1, _081F358C @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081F3590 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	subs r6, #0x15
	adds r3, r5, r6
	strb r0, [r3]
	ldrb r3, [r3]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0xff
	ldrb r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r6, r5, r1
	adds r4, r0, #0
	adds r4, #0x40
	ldr r1, _081F3594 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081F3598
	asrs r2, r0, #0xc
	b _081F359E
	.align 2, 0
_081F3588: .4byte 0x0203B400
_081F358C: .4byte 0x030046B8
_081F3590: .4byte 0x000003FF
_081F3594: .4byte gSineTable
_081F3598:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F359E:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081F35B6
	asrs r0, r0, #0xc
	b _081F35BC
_081F35B6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F35BC:
	movs r4, #0
	movs r3, #0
	strh r0, [r6, #4]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r2, r5, #0
	adds r2, #0x1c
	ldrh r0, [r1]
	ldrh r6, [r5, #0x1c]
	adds r0, r0, r6
	strh r0, [r1]
	ldrh r0, [r1, #2]
	ldrh r6, [r2, #2]
	adds r0, r0, r6
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
	movs r2, #0xab
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r4, [r0]
_081F35F4:
	movs r6, #0xb7
	lsls r6, r6, #1
	adds r4, r5, r6
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _081F3660
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r2, #0x1c
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r6, #0
	ldrsh r1, [r4, r6]
	bl Div
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0xd2
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x1e
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r6, #0
	ldrsh r1, [r4, r6]
	bl Div
	ldrh r1, [r5, #0x1e]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r6, #0x20
	ldrsh r1, [r5, r6]
	subs r0, r0, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	bl Div
	ldrh r1, [r5, #0x20]
	adds r1, r1, r0
	strh r1, [r5, #0x20]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
_081F3660:
	movs r6, #0xac
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081F375C
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
	beq _081F369C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F36A4
_081F369C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F36A4:
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
	beq _081F36C8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F36D0
_081F36C8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F36D0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F3708 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _081F374E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F3712
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F370C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F3728
	.align 2, 0
_081F3708: .4byte 0x0000FFFF
_081F370C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F3726
_081F3712:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F3726
	strh r1, [r4, #8]
	movs r2, #1
	b _081F3728
_081F3726:
	movs r2, #0
_081F3728:
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
	bne _081F3750
	movs r0, #1
	strb r0, [r4, #7]
	b _081F3750
_081F374E:
	movs r2, #0
_081F3750:
	movs r6, #0xac
	lsls r6, r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	cmp r2, #0
	beq _081F3796
_081F375C:
	movs r1, #0xb7
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081F3796
	movs r6, #0xa4
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xa9
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _081F379C @ =0x00000157
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	adds r6, #0x1e
	adds r1, r5, r6
	strb r0, [r1]
	subs r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_081F3796:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F379C: .4byte 0x00000157
