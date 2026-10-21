	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B81A4 @ =0x00001428
	adds r4, r5, r0
	ldr r2, _080B81A8 @ =0x00000D98
	adds r1, r5, r2
	ldr r3, _080B81AC @ =0x00000E58
	adds r2, r5, r3
	ldr r0, _080B81B0 @ =0x00000EB8
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B81B4
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080B81C2
	.align 2, 0
_080B81A4: .4byte 0x00001428
_080B81A8: .4byte 0x00000D98
_080B81AC: .4byte 0x00000E58
_080B81B0: .4byte 0x00000EB8
_080B81B4:
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080B81C2:
	str r1, [r0]
	ldr r4, _080B8224 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080B8234
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5ac8
	ldr r3, _080B8228 @ =0x000010F8
	adds r0, r5, r3
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _080B822C @ =0x0000130C
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B8202
	b _080B83F8
_080B8202:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080B8230 @ =0x00001478
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080B821C
	b _080B83F8
_080B821C:
	movs r0, #0
	strb r0, [r1]
	b _080B83F8
	.align 2, 0
_080B8224: .4byte 0x030044E0
_080B8228: .4byte 0x000010F8
_080B822C: .4byte 0x0000130C
_080B8230: .4byte 0x00001478
_080B8234:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5ac8
	ldr r3, _080B82A4 @ =0x000010F8
	adds r6, r5, r3
	adds r7, r5, #0
	adds r7, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_AdvanceAnim
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B8258
	b _080B83D4
_080B8258:
	ldr r1, _080B82A8 @ =0x0000142B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _080B82C4
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080B82AC @ =0x00001428
	adds r0, r5, r2
	bl FUN_080b9fd8
	ldr r3, _080B82B0 @ =0x000013F4
	adds r0, r5, r3
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl Warehouse_ShowMessage
	ldr r1, _080B82B4 @ =0x000011B8
	adds r0, r5, r1
	ldr r3, _080B82B8 @ =0x0000140D
	adds r2, r5, r3
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B82BC @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B82C0 @ =FUN_080b86bc
	b _080B83C4
	.align 2, 0
_080B82A4: .4byte 0x000010F8
_080B82A8: .4byte 0x0000142B
_080B82AC: .4byte 0x00001428
_080B82B0: .4byte 0x000013F4
_080B82B4: .4byte 0x000011B8
_080B82B8: .4byte 0x0000140D
_080B82BC: .4byte 0x0000130C
_080B82C0: .4byte FUN_080b86bc
_080B82C4:
	cmp r0, #0x22
	bne _080B8324
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080B830C @ =0x00001428
	adds r0, r5, r2
	bl FUN_080b9fd8
	ldr r3, _080B8310 @ =0x000013F4
	adds r0, r5, r3
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #4
	adds r3, r4, #0
	bl Warehouse_ShowMessage
	ldr r1, _080B8314 @ =0x000011B8
	adds r0, r5, r1
	ldr r3, _080B8318 @ =0x0000140D
	adds r2, r5, r3
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B831C @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B8320 @ =FUN_080b8728
	b _080B83C4
	.align 2, 0
_080B830C: .4byte 0x00001428
_080B8310: .4byte 0x000013F4
_080B8314: .4byte 0x000011B8
_080B8318: .4byte 0x0000140D
_080B831C: .4byte 0x0000130C
_080B8320: .4byte FUN_080b8728
_080B8324:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080B8390 @ =0x00001428
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fd8
	movs r3, #0x8b
	lsls r3, r3, #5
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080B8394 @ =0x00001178
	adds r2, r5, r0
	ldr r1, _080B8398 @ =0x00001118
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080B839C @ =0x0000142E
	adds r1, r5, r2
	ldr r3, _080B83A0 @ =0x00001458
	adds r0, r5, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r0, _080B83A4 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _080B83B2
	adds r0, r1, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bne _080B83A8
	adds r0, r4, #0
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080B83BA
	.align 2, 0
_080B8390: .4byte 0x00001428
_080B8394: .4byte 0x00001178
_080B8398: .4byte 0x00001118
_080B839C: .4byte 0x0000142E
_080B83A0: .4byte 0x00001458
_080B83A4: .4byte 0x030046A0
_080B83A8:
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_080b9d94
	b _080B83BA
_080B83B2:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_080b9d94
_080B83BA:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b7c18
	ldr r1, _080B83D0 @ =FUN_080b8404
_080B83C4:
	adds r0, r5, #0
	movs r2, #0
	bl Warehouse_SetSubState
	b _080B83F8
	.align 2, 0
_080B83D0: .4byte FUN_080b8404
_080B83D4:
	ldr r2, _080B8400 @ =0x00001428
	adds r4, r5, r2
	adds r0, r4, #0
	bl ShopCursor_Move
	cmp r0, #0
	beq _080B83F8
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b7900
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b7c18
_080B83F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8400: .4byte 0x00001428
