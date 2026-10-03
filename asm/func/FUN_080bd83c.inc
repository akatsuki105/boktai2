	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080BD888 @ =0x00001788
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD8DC
	ldr r2, _080BD88C @ =0x0000178A
	adds r6, r4, r2
	ldrb r5, [r6]
	adds r0, r5, #0
	bl GetWeaponID
	cmp r0, #0
	ble _080BD8C4
	ldr r3, _080BD890 @ =0x00001785
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BD898
	adds r0, r5, #0
	bl FindRegisteredWeaponSlot
	cmp r0, #0
	bge _080BD938
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	beq _080BD938
	ldr r1, _080BD894 @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BD938
	movs r0, #5
	b _080BD93A
	.align 2, 0
_080BD888: .4byte 0x00001788
_080BD88C: .4byte 0x0000178A
_080BD890: .4byte 0x00001785
_080BD894: .4byte 0x00001787
_080BD898:
	ldr r2, _080BD8C0 @ =0x00001787
	adds r4, r4, r2
	ldrb r0, [r4]
	ldrb r6, [r6]
	cmp r0, r6
	bne _080BD8D2
	adds r0, r5, #0
	bl FindRegisteredWeaponSlot
	cmp r0, #0
	bge _080BD938
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	beq _080BD938
	movs r0, #0x22
	strb r0, [r4]
	movs r0, #5
	b _080BD93A
	.align 2, 0
_080BD8C0: .4byte 0x00001787
_080BD8C4:
	ldr r3, _080BD8D8 @ =0x00001787
	adds r0, r4, r3
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	ble _080BD938
_080BD8D2:
	movs r0, #1
	b _080BD93A
	.align 2, 0
_080BD8D8: .4byte 0x00001787
_080BD8DC:
	ldr r0, _080BD90C @ =0x00001787
	adds r2, r4, r0
	ldr r3, _080BD910 @ =0x0000178A
	adds r1, r4, r3
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BD91C
	ldr r1, _080BD914 @ =0x0000168C
	adds r0, r4, r1
	ldrh r1, [r0]
	strb r1, [r2]
	movs r0, #3
	ands r0, r1
	subs r3, #5
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsrs r0, r0, #2
	ldr r2, _080BD918 @ =0x00001786
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #4
	b _080BD93A
	.align 2, 0
_080BD90C: .4byte 0x00001787
_080BD910: .4byte 0x0000178A
_080BD914: .4byte 0x0000168C
_080BD918: .4byte 0x00001786
_080BD91C:
	ldr r3, _080BD934 @ =0x00001785
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD938
	ldrb r0, [r2]
	bl GetWeaponID
	cmp r0, #0
	bne _080BD938
	movs r0, #4
	b _080BD93A
	.align 2, 0
_080BD934: .4byte 0x00001785
_080BD938:
	movs r0, #0
_080BD93A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
