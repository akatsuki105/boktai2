	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, _080BF0B0 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BF0B8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080beaf4
	ldr r1, _080BF0B4 @ =0x00000BB8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BF08C
	b _080BF1B8
_080BF08C:
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r2, #0x87
	lsls r2, r2, #5
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BF0A8
	b _080BF1B8
_080BF0A8:
	movs r0, #0
	strb r0, [r1]
	b _080BF1B8
	.align 2, 0
_080BF0B0: .4byte 0x030044E0
_080BF0B4: .4byte 0x00000BB8
_080BF0B8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080beaf4
	ldr r0, _080BF11C @ =0x00000BB8
	adds r6, r5, r0
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r6, #0
	bl MainSprite_AdvanceAnim
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BF18C
	ldr r1, _080BF120 @ =0x00000FD3
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BF124 @ =0x00000EBC
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r3, #1
	cmp r1, #0
	blt _080BF110
	ldr r0, _080BF128 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x91
	lsls r4, r4, #4
	adds r0, r0, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	ldr r0, _080BF12C @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, [r1]
	cmp r2, r0
	bhs _080BF10C
	movs r3, #0
_080BF10C:
	cmp r3, #0
	bne _080BF130
_080BF110:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BF1B8
	.align 2, 0
_080BF11C: .4byte 0x00000BB8
_080BF120: .4byte 0x00000FD3
_080BF124: .4byte 0x00000EBC
_080BF128: .4byte 0x030046A0
_080BF12C: .4byte 0x08DAA8D8
_080BF130:
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fd8
	movs r1, #0xc2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080BF180 @ =0x00000C38
	adds r2, r5, r0
	ldr r1, _080BF184 @ =0x00000BD8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bef00
	ldr r1, _080BF188 @ =CoffinShop_HandleSelectInput
	adds r0, r5, #0
	movs r2, #0
	bl CoffinShop_SetSubState
	b _080BF1B8
	.align 2, 0
_080BF180: .4byte 0x00000C38
_080BF184: .4byte 0x00000BD8
_080BF188: .4byte CoffinShop_HandleSelectInput
_080BF18C:
	movs r2, #0xfd
	lsls r2, r2, #4
	adds r4, r5, r2
	adds r0, r4, #0
	bl ShopCursor_Move
	cmp r0, #0
	beq _080BF1B8
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl CoffinShop_UpdateDescription
	adds r0, r5, #0
	bl CoffinShop_DrawPrice
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bef00
_080BF1B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
