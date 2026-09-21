	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _08006964
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0800696C
_08006964:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800696C:
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
	beq _08006990
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006998
_08006990:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006998:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080069D0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006A08
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080069D4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080069C8
	ldrb r0, [r4, #5]
_080069C8:
	subs r0, #1
	strh r0, [r4, #8]
	b _080069E4
	.align 2, 0
_080069D0: .4byte 0x0000FFFF
_080069D4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080069E4
	strh r1, [r4, #8]
_080069E4:
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
	bne _08006A08
	movs r0, #1
	strb r0, [r4, #7]
_08006A08:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006A18
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006A18:
	ldr r1, [r7, #0x18]
	cmp r1, #8
	bne _08006A58
	ldr r0, _08006A54 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08006A34
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08006A34:
	ldrh r4, [r7, #0x34]
	movs r1, #0
	ldrsh r0, [r7, r1]
	movs r2, #2
	ldrsh r1, [r7, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _08006A4A
	movs r2, #1
_08006A4A:
	adds r0, r7, #0
	adds r1, r4, #0
	bl MapItem_ExecScript
	b _08006A74
	.align 2, 0
_08006A54: .4byte 0x030047A4
_08006A58:
	cmp r1, #8
	bls _08006A74
	ldr r0, [r7, #0x20]
	movs r2, #0x1e
	movs r3, #0x5a
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08006A74
	ldrb r1, [r7, #6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #6]
_08006A74:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
