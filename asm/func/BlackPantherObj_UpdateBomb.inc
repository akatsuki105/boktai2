	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x38
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _080536B0
	ldr r2, _080536A4 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #8]
	ldrh r1, [r5, #4]
	lsrs r1, r1, #1
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r1, _080536A8 @ =0x00001004
	adds r2, r5, #0
	adds r2, #0x54
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0xfa
	str r0, [sp, #4]
	movs r0, #0
	add r3, sp, #8
	bl MinigameExplosionManager_Spawn
	adds r0, r6, #0
	bl BlackPanther_ResetCombo
	adds r0, r6, #0
	movs r1, #0x64
	bl BlackPanther_AddGap
	adds r0, r6, #0
	adds r1, r5, #0
	bl BlackPantherObj_Remove
	ldr r0, _080536AC @ =0x00000195
	bl PlaySound_082406e0
	b _080537D4
	.align 2, 0
_080536A4: .4byte 0xFFFF0000
_080536A8: .4byte 0x00001004
_080536AC: .4byte 0x00000195
_080536B0:
	movs r3, #1
	ldrh r1, [r5, #6]
	movs r0, #1
	orrs r0, r1
	strh r0, [r5, #6]
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	ldr r1, _08053700 @ =0x0F9F0000
	cmp r0, r1
	ble _08053704
	adds r0, r6, #0
	bl BlackPanther_IncrementCombo
	ldr r0, [r6, #0x2c]
	movs r1, #0x10
	rsbs r1, r1, #0
	subs r1, r1, r0
	adds r0, r6, #0
	bl BlackPanther_AddGap
	movs r4, #2
	ldrsb r4, [r5, r4]
	adds r0, r6, #0
	bl BlackPanther_GetComboMultiplier
	adds r2, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl BlackPanther_AddScore
	adds r0, r6, #0
	adds r1, r5, #0
	bl BlackPantherObj_Remove
	b _080537D4
	.align 2, 0
_08053700: .4byte 0x0F9F0000
_08053704:
	adds r4, r5, #0
	adds r4, #0x64
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x64]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08053732
	ldr r0, [r5, #0x38]
	movs r1, #4
	orrs r0, r1
	b _0805373A
_08053732:
	ldr r0, [r5, #0x38]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805373A:
	str r0, [r5, #0x38]
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
	beq _0805375E
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08053766
_0805375E:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08053766:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0805379C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080537D4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080537A0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08053796
	ldrb r0, [r4, #5]
_08053796:
	subs r0, #1
	strh r0, [r4, #8]
	b _080537B0
	.align 2, 0
_0805379C: .4byte 0x0000FFFF
_080537A0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080537B0
	strh r1, [r4, #8]
_080537B0:
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
	bne _080537D4
	movs r0, #1
	strb r0, [r4, #7]
_080537D4:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
