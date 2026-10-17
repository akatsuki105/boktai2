	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B6264 @ =0x00001428
	adds r4, r5, r0
	ldr r2, _080B6268 @ =0x00000D98
	adds r1, r5, r2
	ldr r0, _080B626C @ =0x00000E58
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B6270
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080B627E
	.align 2, 0
_080B6264: .4byte 0x00001428
_080B6268: .4byte 0x00000D98
_080B626C: .4byte 0x00000E58
_080B6270:
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080B627E:
	str r1, [r0]
	ldr r4, _080B62E0 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080B62F0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5ac8
	ldr r1, _080B62E4 @ =0x000010F8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _080B62E8 @ =0x0000130C
	adds r0, r5, r2
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B62BE
	b _080B6490
_080B62BE:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B62EC @ =0x00001478
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080B62D8
	b _080B6490
_080B62D8:
	movs r0, #0
	strb r0, [r1]
	b _080B6490
	.align 2, 0
_080B62E0: .4byte 0x030044E0
_080B62E4: .4byte 0x000010F8
_080B62E8: .4byte 0x0000130C
_080B62EC: .4byte 0x00001478
_080B62F0:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5ac8
	ldr r1, _080B6360 @ =0x000010F8
	adds r6, r5, r1
	adds r7, r5, #0
	adds r7, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_AdvanceAnim
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B6314
	b _080B646C
_080B6314:
	ldr r2, _080B6364 @ =0x0000142B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _080B6380
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B6368 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r2, _080B636C @ =0x000013F4
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl Warehouse_ShowMessage
	ldr r1, _080B6370 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B6374 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080B6378 @ =0x0000130C
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B637C @ =FUN_080b6754
	b _080B63C4
	.align 2, 0
_080B6360: .4byte 0x000010F8
_080B6364: .4byte 0x0000142B
_080B6368: .4byte 0x00001428
_080B636C: .4byte 0x000013F4
_080B6370: .4byte 0x000011B8
_080B6374: .4byte 0x0000140D
_080B6378: .4byte 0x0000130C
_080B637C: .4byte FUN_080b6754
_080B6380:
	cmp r0, #0x22
	bne _080B63E8
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B63D0 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r2, _080B63D4 @ =0x000013F4
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #4
	adds r3, r4, #0
	bl Warehouse_ShowMessage
	ldr r1, _080B63D8 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B63DC @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080B63E0 @ =0x0000130C
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B63E4 @ =FUN_080b67c0
_080B63C4:
	adds r0, r5, #0
	movs r2, #0
	bl Warehouse_SetSubState
	b _080B6490
	.align 2, 0
_080B63D0: .4byte 0x00001428
_080B63D4: .4byte 0x000013F4
_080B63D8: .4byte 0x000011B8
_080B63DC: .4byte 0x0000140D
_080B63E0: .4byte 0x0000130C
_080B63E4: .4byte FUN_080b67c0
_080B63E8:
	ldr r0, _080B6434 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fd8
	movs r1, #0x8b
	lsls r1, r1, #5
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080B6438 @ =0x00001178
	adds r2, r5, r0
	ldr r1, _080B643C @ =0x00001118
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080B6440 @ =0x0000142E
	adds r1, r5, r2
	adds r2, #0x2a
	adds r0, r5, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	blt _080B6444
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_080b9d94
	b _080B644C
	.align 2, 0
_080B6434: .4byte 0x00001428
_080B6438: .4byte 0x00001178
_080B643C: .4byte 0x00001118
_080B6440: .4byte 0x0000142E
_080B6444:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_080b9d94
_080B644C:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B6468 @ =FUN_080b649c
	adds r0, r5, #0
	movs r2, #0
	bl Warehouse_SetSubState
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5e48
	b _080B6490
	.align 2, 0
_080B6468: .4byte FUN_080b649c
_080B646C:
	ldr r0, _080B6498 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B6490
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b5b94
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5e48
_080B6490:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B6498: .4byte 0x00001428
