	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B73F0 @ =0x00001428
	adds r4, r5, r0
	ldr r0, _080B73F4 @ =0x00000D98
	adds r1, r5, r0
	adds r0, #0xc0
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B73F8
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080B743C
	.align 2, 0
_080B73F0: .4byte 0x00001428
_080B73F4: .4byte 0x00000D98
_080B73F8:
	ldr r1, _080B7414 @ =0x0000140E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _080B7418
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080B7424
	.align 2, 0
_080B7414: .4byte 0x0000140E
_080B7418:
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080B7424:
	str r1, [r0]
	ldr r0, _080B74A8 @ =0x0000140E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080B743C
	movs r0, #0
	strh r0, [r1]
_080B743C:
	ldr r1, _080B74AC @ =0x000010F8
	adds r6, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	ldr r0, _080B74B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #4
	ands r0, r1
	adds r7, r4, #0
	cmp r0, #0
	beq _080B74C4
	ldr r1, _080B74B4 @ =0x00001428
	adds r0, r5, r1
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B74C4
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B74B8 @ =0x00001118
	adds r0, r5, r1
	movs r1, #0x20
	bl FUN_080b9938
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _080B74BC @ =0x0000130C
	adds r0, r5, r1
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r0, _080B74C0 @ =0x00000107
	bl PlaySound_082406e0
	b _080B7514
	.align 2, 0
_080B74A8: .4byte 0x0000140E
_080B74AC: .4byte 0x000010F8
_080B74B0: .4byte 0x030044E0
_080B74B4: .4byte 0x00001428
_080B74B8: .4byte 0x00001118
_080B74BC: .4byte 0x0000130C
_080B74C0: .4byte 0x00000107
_080B74C4:
	ldr r0, _080B74FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B7554
	adds r0, r5, #0
	bl FUN_080b6fa4
	adds r4, r0, #0
	ldr r1, _080B7500 @ =0x0000130C
	adds r0, r5, r1
	movs r6, #1
	rsbs r6, r6, #0
	adds r1, r6, #0
	adds r2, r6, #0
	bl FUN_080b98c0
	cmp r4, #1
	beq _080B7504
	cmp r4, #2
	beq _080B7514
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080B7590
	.align 2, 0
_080B74FC: .4byte 0x030044E0
_080B7500: .4byte 0x0000130C
_080B7504:
	adds r0, r5, #0
	bl FUN_080b6ca8
	ldr r1, _080B7510 @ =FUN_080b7750
	b _080B7538
	.align 2, 0
_080B7510: .4byte FUN_080b7750
_080B7514:
	ldr r1, _080B7544 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r3, #1
	rsbs r3, r3, #0
	bl Warehouse_ShowMessage
	ldr r1, _080B7548 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B754C @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B7550 @ =FUN_080b7794
_080B7538:
	adds r0, r5, #0
	movs r2, #0
	bl Warehouse_SetSubState
	b _080B7590
	.align 2, 0
_080B7544: .4byte 0x000013F4
_080B7548: .4byte 0x000011B8
_080B754C: .4byte 0x0000140D
_080B7550: .4byte FUN_080b7794
_080B7554:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B756A
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b70ac
	b _080B7590
_080B756A:
	ldr r0, _080B7598 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl ShopCursor_Move
	cmp r0, #0
	beq _080B7590
	ldr r0, _080B759C @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b69b8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b6e70
_080B7590:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B7598: .4byte 0x00001428
_080B759C: .4byte 0x000010F8
