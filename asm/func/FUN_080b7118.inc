	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B714C @ =0x00001428
	adds r4, r5, r0
	ldr r0, _080B7150 @ =0x00000D98
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
	beq _080B7154
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080B7162
	.align 2, 0
_080B714C: .4byte 0x00001428
_080B7150: .4byte 0x00000D98
_080B7154:
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080B7162:
	str r1, [r0]
	ldr r0, _080B71D0 @ =0x000010F8
	adds r6, r5, r0
	adds r7, r5, #0
	adds r7, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_AdvanceAnim
	ldr r4, _080B71D4 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080B71E0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5ac8
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _080B71D8 @ =0x0000130C
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B71AE
	b _080B73AC
_080B71AE:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B71DC @ =0x00001478
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080B71C8
	b _080B73AC
_080B71C8:
	movs r0, #0
	strb r0, [r1]
	b _080B73AC
	.align 2, 0
_080B71D0: .4byte 0x000010F8
_080B71D4: .4byte 0x030044E0
_080B71D8: .4byte 0x0000130C
_080B71DC: .4byte 0x00001478
_080B71E0:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5ac8
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_AdvanceAnim
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B71FC
	b _080B7388
_080B71FC:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B7250 @ =0x0000142B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _080B726C
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B7254 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r1, _080B7258 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl Warehouse_ShowMessage
	ldr r1, _080B725C @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B7260 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B7264 @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B7268 @ =FUN_080b7670
	b _080B7378
	.align 2, 0
_080B7250: .4byte 0x0000142B
_080B7254: .4byte 0x00001428
_080B7258: .4byte 0x000013F4
_080B725C: .4byte 0x000011B8
_080B7260: .4byte 0x0000140D
_080B7264: .4byte 0x0000130C
_080B7268: .4byte FUN_080b7670
_080B726C:
	cmp r0, #0x22
	bne _080B72CC
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B72B4 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r1, _080B72B8 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #4
	adds r3, r4, #0
	bl Warehouse_ShowMessage
	ldr r1, _080B72BC @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B72C0 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B72C4 @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B72C8 @ =FUN_080b76dc
	b _080B7378
	.align 2, 0
_080B72B4: .4byte 0x00001428
_080B72B8: .4byte 0x000013F4
_080B72BC: .4byte 0x000011B8
_080B72C0: .4byte 0x0000140D
_080B72C4: .4byte 0x0000130C
_080B72C8: .4byte FUN_080b76dc
_080B72CC:
	ldr r0, _080B7324 @ =0x00001428
	adds r7, r5, r0
	adds r0, r7, #0
	bl FUN_080b9fd8
	movs r1, #0x8b
	lsls r1, r1, #5
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080B7328 @ =0x00001178
	adds r2, r5, r0
	ldr r1, _080B732C @ =0x00001118
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080B7330 @ =0x0000142E
	adds r6, r5, r0
	ldr r1, _080B7334 @ =0x00001458
	adds r0, r5, r1
	ldrb r1, [r6]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetWeaponID
	adds r4, r0, #0
	cmp r4, #0
	ble _080B7366
	ldrb r1, [r6]
	adds r0, r5, #0
	bl Warehouse_FindRegisteredSlot
	cmp r0, #0
	blt _080B7338
	adds r0, r7, #0
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080B736E
	.align 2, 0
_080B7324: .4byte 0x00001428
_080B7328: .4byte 0x00001178
_080B732C: .4byte 0x00001118
_080B7330: .4byte 0x0000142E
_080B7334: .4byte 0x00001458
_080B7338:
	adds r0, r4, #0
	subs r0, #0x3a
	cmp r0, #3
	bls _080B734C
	cmp r4, #0x3f
	beq _080B734C
	cmp r4, #0x40
	beq _080B734C
	cmp r4, #0x41
	bne _080B735C
_080B734C:
	ldr r1, _080B7358 @ =0x00001428
	adds r0, r5, r1
	movs r1, #0x1c
	bl FUN_080b9d94
	b _080B736E
	.align 2, 0
_080B7358: .4byte 0x00001428
_080B735C:
	adds r0, r7, #0
	movs r1, #0x18
	bl FUN_080b9d94
	b _080B736E
_080B7366:
	adds r0, r7, #0
	movs r1, #0x1c
	bl FUN_080b9d94
_080B736E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b6e70
	ldr r1, _080B7384 @ =FUN_080b73b8
_080B7378:
	adds r0, r5, #0
	movs r2, #0
	bl Warehouse_SetSubState
	b _080B73AC
	.align 2, 0
_080B7384: .4byte FUN_080b73b8
_080B7388:
	ldr r0, _080B73B4 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B73AC
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b69b8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b6e70
_080B73AC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B73B4: .4byte 0x00001428
