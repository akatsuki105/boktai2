	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A8638 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A8690
	ldr r0, [r0, #0x1c]
	cmp r0, #4
	bne _080A863C
	adds r2, r4, #0
	adds r2, #0x62
	ldrh r1, [r2]
	cmp r1, #1
	bne _080A8690
	ldr r0, [r4, #0x18]
	orrs r0, r1
	str r0, [r4, #0x18]
	movs r0, #0
	strh r0, [r2]
	movs r6, #1
	movs r5, #0
	adds r2, #0x56
	adds r1, r4, #0
	adds r1, #0x80
	movs r3, #7
_080A8622:
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	strh r5, [r2]
	adds r2, #0x3c
	adds r1, #0x3c
	subs r3, #1
	cmp r3, #0
	bge _080A8622
	b _080A8690
	.align 2, 0
_080A8638: .4byte 0x03002BE0
_080A863C:
	adds r0, r4, #0
	bl FUN_080a841c
	adds r0, r4, #0
	bl TryPlayerLevelUp
	cmp r0, #0
	beq _080A865C
	adds r0, r4, #0
	bl FUN_080a8384
	movs r0, #0xe2
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080A867C
_080A865C:
	adds r0, r4, #0
	adds r0, #0x60
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A867C
	adds r0, r4, #0
	bl IsWeaponLevelChanged
	cmp r0, #0
	beq _080A867C
	adds r0, r4, #0
	bl FUN_080a83dc
	ldr r0, _080A8698 @ =0x00000381
	bl PlaySound_082406e0
_080A867C:
	movs r5, #0
	adds r4, #0x68
_080A8680:
	adds r0, r5, #0
	bl GetWeaponSkillLevel
	strh r0, [r4]
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble _080A8680
_080A8690:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A8698: .4byte 0x00000381
