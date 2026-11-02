	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x38
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _080537FC
	adds r0, r6, #0
	bl BlackPanther_ResetCombo
	adds r0, r6, #0
	movs r1, #0x64
	bl BlackPanther_AddGap
	b _08053840
_080537FC:
	ldrh r1, [r5, #6]
	movs r0, #1
	orrs r0, r1
	strh r0, [r5, #6]
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	ldr r0, _0805384C @ =0x00000F9F
	cmp r1, r0
	ble _08053850
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
_08053840:
	adds r0, r6, #0
	adds r1, r5, #0
	bl BlackPantherObj_Remove
	b _08053950
	.align 2, 0
_0805384C: .4byte 0x00000F9F
_08053850:
	ldr r0, _08053864 @ =0x00000BB8
	cmp r1, r0
	bgt _08053878
	ldr r0, [r5, #0xc]
	movs r1, #3
	ands r0, r1
	cmp r0, #1
	bhi _08053868
	ldrb r0, [r5, #0x14]
	b _0805386A
	.align 2, 0
_08053864: .4byte 0x00000BB8
_08053868:
	ldrb r0, [r5, #0x15]
_0805386A:
	strb r0, [r5, #3]
	ldr r0, _080538A8 @ =0x085AB740
	ldrb r1, [r5, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r7, #0x1c]
_08053878:
	adds r4, r5, #0
	adds r4, #0x64
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x64]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080538AC
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080538B4
	.align 2, 0
_080538A8: .4byte 0x085AB740
_080538AC:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080538B4:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080538D8
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080538E0
_080538D8:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080538E0:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08053918 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08053950
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805391C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08053910
	ldrb r0, [r4, #5]
_08053910:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805392C
	.align 2, 0
_08053918: .4byte 0x0000FFFF
_0805391C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805392C
	strh r1, [r4, #8]
_0805392C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _08053950
	movs r0, #1
	strb r0, [r4, #7]
_08053950:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
