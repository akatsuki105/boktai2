	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x38
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _0805397A
	adds r0, r6, #0
	bl BlackPanther_ResetCombo
	adds r0, r6, #0
	movs r1, #0x64
	bl BlackPanther_AddGap
	b _080539E6
_0805397A:
	ldrh r0, [r5, #6]
	movs r1, #1
	orrs r1, r0
	strh r1, [r5, #6]
	ldr r0, [r5, #0xc]
	cmp r0, #0x40
	bne _080539A6
	adds r0, r5, #0
	adds r0, #0x64
	ldr r2, _080539F0 @ =0x000017E4
	adds r1, r6, r2
	ldr r1, [r1]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl AuxAnim_SetAnim
	movs r0, #0xf2
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080539A6:
	ldr r0, [r5, #0xc]
	cmp r0, #0x3f
	bls _080539F8
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	ldr r1, _080539F4 @ =0x0F9F0000
	cmp r0, r1
	ble _08053A38
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
_080539E6:
	adds r0, r6, #0
	adds r1, r5, #0
	bl BlackPantherObj_Remove
	b _08053B10
	.align 2, 0
_080539F0: .4byte 0x000017E4
_080539F4: .4byte 0x0F9F0000
_080539F8:
	ldrh r0, [r5, #4]
	lsrs r0, r0, #1
	ldrh r2, [r7, #0x20]
	adds r0, r0, r2
	strh r0, [r7, #0x20]
	ldr r2, _08053A20 @ =gSineTable
	ldr r0, [r5, #0xc]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08053A24
	asrs r2, r0, #0xc
	b _08053A2A
	.align 2, 0
_08053A20: .4byte gSineTable
_08053A24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08053A2A:
	ldr r0, _08053A68 @ =0x085AB740
	ldrb r1, [r5, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
_08053A38:
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
	beq _08053A6C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08053A74
	.align 2, 0
_08053A68: .4byte 0x085AB740
_08053A6C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08053A74:
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
	beq _08053A98
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08053AA0
_08053A98:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08053AA0:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08053AD8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08053B10
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08053ADC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08053AD0
	ldrb r0, [r4, #5]
_08053AD0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08053AEC
	.align 2, 0
_08053AD8: .4byte 0x0000FFFF
_08053ADC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08053AEC
	strh r1, [r4, #8]
_08053AEC:
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
	bne _08053B10
	movs r0, #1
	strb r0, [r4, #7]
_08053B10:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
