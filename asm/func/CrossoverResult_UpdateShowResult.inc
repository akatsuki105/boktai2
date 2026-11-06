	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0x1d]
	cmp r0, #0
	beq _08052668
	movs r0, #0
	strb r0, [r7, #0x1d]
	adds r0, r7, #0
	adds r0, #0x24
	ldrb r1, [r0]
	movs r5, #0x48
	adds r3, r0, #0
	cmp r1, #0
	beq _080525F4
	movs r5, #0x4a
	cmp r1, #1
	bne _080525F4
	movs r5, #0x49
_080525F4:
	ldr r0, _0805262C @ =gSystemSaveData
	ldr r1, [r0]
	ldrh r1, [r1, #0x14]
	adds r1, #1
	ldr r2, _08052630 @ =0x0000270F
	adds r4, r0, #0
	cmp r1, r2
	ble _08052606
	adds r1, r2, #0
_08052606:
	ldr r0, [r4]
	strh r1, [r0, #0x14]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08052634
	movs r0, #0xb0
	bl sound_08240264
	ldr r0, [r4]
	ldrh r0, [r0, #0x16]
	adds r1, r0, #1
	ldr r0, _08052630 @ =0x0000270F
	cmp r1, r0
	ble _08052624
	adds r1, r0, #0
_08052624:
	ldr r0, _0805262C @ =gSystemSaveData
	ldr r0, [r0]
	strh r1, [r0, #0x16]
	b _08052646
	.align 2, 0
_0805262C: .4byte gSystemSaveData
_08052630: .4byte 0x0000270F
_08052634:
	cmp r0, #1
	bne _08052640
	movs r0, #0xb1
	bl sound_08240264
	b _08052646
_08052640:
	movs r0, #0xb1
	bl sound_08240264
_08052646:
	adds r6, r7, #0
	adds r6, #0x70
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	adds r1, r7, #0
	adds r1, #0x30
	adds r2, r5, #0
	adds r0, r6, #0
	movs r3, #0
	bl MainSprite_SetPose
	movs r0, #0
	strh r0, [r6, #0x20]
	strh r0, [r6, #0x22]
_08052668:
	ldr r0, [r7, #0x18]
	cmp r0, #7
	bhi _080526AC
	adds r6, r7, #0
	adds r6, #0x70
	ldr r5, _080526A0 @ =0x0203B400
	ldr r2, _080526A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _080526A8 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #3
	ands r1, r3
	subs r1, #2
	strh r1, [r6, #0x20]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	subs r0, #2
	b _080526B8
	.align 2, 0
_080526A0: .4byte 0x0203B400
_080526A4: .4byte 0x030046B8
_080526A8: .4byte 0x000003FF
_080526AC:
	cmp r0, #8
	bne _080526BA
	adds r6, r7, #0
	adds r6, #0x70
	movs r0, #0
	strh r0, [r6, #0x20]
_080526B8:
	strh r0, [r6, #0x22]
_080526BA:
	ldr r0, [r7, #0x18]
	cmp r0, #0x1d
	bls _080526CE
	movs r0, #3
	movs r1, #0
	strb r0, [r7, #0x1c]
	movs r0, #1
	strb r0, [r7, #0x1d]
	str r1, [r7, #0x18]
	b _080526D2
_080526CE:
	adds r0, #1
	str r0, [r7, #0x18]
_080526D2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
