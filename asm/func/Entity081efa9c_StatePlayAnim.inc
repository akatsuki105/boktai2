	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r1, #0
	mov ip, r5
	adds r2, r5, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	cmp r0, #0
	beq _081EF420
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r0, #0
	strb r0, [r2]
_081EF420:
	adds r0, r5, #0
	adds r0, #0x1c
	ldrh r1, [r5, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r0
	cmp r2, #0
	blt _081EF44A
	cmp r1, #0
	blt _081EF44A
	ldr r0, _081EF450 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EF44A
	ldr r0, _081EF454 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EF458
_081EF44A:
	movs r1, #0
	b _081EF466
	.align 2, 0
_081EF450: .4byte 0x030046A8
_081EF454: .4byte 0x030046AC
_081EF458:
	ldr r0, _081EF4A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081EF466:
	adds r0, r5, #0
	adds r0, #0xc8
	strh r1, [r0]
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
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
	beq _081EF4A4
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081EF4B0
	.align 2, 0
_081EF4A0: .4byte 0x030046A4
_081EF4A4:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081EF4B0:
	str r0, [r2]
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
	beq _081EF4D6
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081EF4E0
_081EF4D6:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081EF4E0:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081EF51C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081EF562
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EF526
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081EF520
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r7, #1
	b _081EF53C
	.align 2, 0
_081EF51C: .4byte 0x0000FFFF
_081EF520:
	subs r0, #1
	strh r0, [r4, #8]
	b _081EF53A
_081EF526:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081EF53A
	strh r1, [r4, #8]
	movs r7, #1
	b _081EF53C
_081EF53A:
	movs r7, #0
_081EF53C:
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
	bne _081EF564
	movs r0, #1
	strb r0, [r4, #7]
	b _081EF564
_081EF562:
	movs r7, #0
_081EF564:
	adds r0, r5, #0
	adds r0, #0xb7
	ldrb r1, [r0]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	beq _081EF588
	adds r4, r5, #0
	adds r4, #0x58
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_081EF588:
	adds r6, r5, #0
	adds r6, #0xc6
	ldrh r0, [r6]
	cmp r0, #0
	beq _081EF596
	cmp r7, #0
	beq _081EF5DC
_081EF596:
	ldr r0, _081EF5D4 @ =0x030001DC
	ldr r2, [r0]
	adds r7, r5, #0
	adds r7, #0xbd
	movs r0, #0
	ldrsb r0, [r7, r0]
	ldr r1, _081EF5D8 @ =0x00000838
	adds r2, r2, r1
	mov r1, r8
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r7]
	adds r0, r5, #0
	adds r0, #0xba
	strh r4, [r0]
	strh r4, [r6]
	adds r0, #0xa
	mov r2, r8
	strb r2, [r0]
	b _081EF5E0
	.align 2, 0
_081EF5D4: .4byte 0x030001DC
_081EF5D8: .4byte 0x00000838
_081EF5DC:
	subs r0, #1
	strh r0, [r6]
_081EF5E0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
