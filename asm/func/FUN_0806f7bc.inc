	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x99
	lsls r1, r1, #2
	adds r3, r5, r1
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _0806F7E6
	movs r4, #0xd8
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrh r1, [r1]
	ldrh r2, [r3, #0xc]
	adds r1, r1, r2
	movs r4, #0x14
	ldrsh r2, [r3, r4]
	adds r6, r1, r2
	b _0806F7F8
_0806F7E6:
	movs r2, #0xd8
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	ldrh r2, [r3, #0xc]
	adds r1, r1, r2
	movs r4, #0x14
	ldrsh r2, [r3, r4]
	subs r6, r1, r2
_0806F7F8:
	ldr r4, _0806F81C @ =0x030046A0
	ldr r1, [r4]
	adds r1, #0x40
	movs r2, #0
	ldrsh r3, [r1, r2]
	adds r1, r6, r3
	asrs r6, r1, #1
	ldr r2, _0806F820 @ =0x00000A75
	adds r1, r5, r2
	ldrb r2, [r1]
	cmp r2, #3
	beq _0806F874
	cmp r2, #3
	ble _0806F824
	cmp r2, #4
	beq _0806F8BC
	b _0806F8F4
	.align 2, 0
_0806F81C: .4byte 0x030046A0
_0806F820: .4byte 0x00000A75
_0806F824:
	cmp r2, #0
	blt _0806F8F4
	movs r1, #8
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r5, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806F850
	adds r4, r3, #0
	cmp r4, #0x3c
	ble _0806F840
	movs r4, #0x3c
_0806F840:
	adds r0, r4, #0
	muls r0, r2, r0
	movs r1, #6
	bl Div
	adds r0, #5
	adds r4, r4, r0
	b _0806F86C
_0806F850:
	ldr r0, _0806F870 @ =0x00000A78
	adds r1, r5, r0
	movs r2, #0xa7
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r1]
	adds r4, r0, r1
	cmp r4, #0
	bge _0806F86C
	movs r4, #0
_0806F86C:
	adds r0, r6, r4
	b _0806F8F4
	.align 2, 0
_0806F870: .4byte 0x00000A78
_0806F874:
	movs r0, #3
	bl GetWeaponSkillLevel
	ldr r1, [r4]
	adds r1, #0x40
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
	asrs r0, r0, #2
	adds r4, r6, r0
	movs r1, #0x80
	lsls r1, r1, #0x15
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806F8B4
	ldr r1, _0806F8B8 @ =0x00000366
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r2, #0x14
	adds r0, r5, r2
	ldrh r2, [r0]
	subs r2, r1, r2
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	bl Div
	adds r4, r4, r0
_0806F8B4:
	adds r0, r4, #0
	b _0806F8F4
	.align 2, 0
_0806F8B8: .4byte 0x00000366
_0806F8BC:
	movs r0, #4
	bl GetWeaponSkillLevel
	cmp r0, #0x62
	ble _0806F8D8
	ldr r4, _0806F8D4 @ =0x00000A78
	adds r0, r5, r4
	ldrh r0, [r0]
	adds r0, #0xa
	lsls r0, r0, #1
	b _0806F8F4
	.align 2, 0
_0806F8D4: .4byte 0x00000A78
_0806F8D8:
	movs r0, #4
	bl GetWeaponSkillLevel
	movs r1, #0xa
	bl Div
	ldr r1, _0806F8FC @ =0x00000A78
	adds r2, r5, r1
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	ldrh r2, [r2]
	adds r4, r1, r2
	lsls r0, r4, #1
_0806F8F4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0806F8FC: .4byte 0x00000A78
