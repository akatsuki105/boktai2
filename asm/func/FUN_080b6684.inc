	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B66D8 @ =0x000010F8
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B66DC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B66E8
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B66E0 @ =0x00001428
	adds r0, r4, r1
	adds r1, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b5b94
	ldr r1, _080B66E4 @ =FUN_080b649c
	adds r0, r4, #0
	movs r2, #0
	bl Warehouse_SetSubState
	b _080B673A
	.align 2, 0
_080B66D8: .4byte 0x000010F8
_080B66DC: .4byte 0x030044E0
_080B66E0: .4byte 0x00001428
_080B66E4: .4byte FUN_080b649c
_080B66E8:
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080B673A
	movs r0, #0x88
	lsls r0, r0, #5
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B6740 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080B6744 @ =0x000013F4
	adds r0, r4, r1
	ldr r2, [r0]
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r4, #0
	movs r1, #2
	bl Warehouse_ShowMessage
	ldr r1, _080B6748 @ =0x000011B8
	adds r0, r4, r1
	ldr r1, _080B674C @ =0x0000140D
	adds r2, r4, r1
	adds r1, r6, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B6750 @ =FUN_080b685c
	adds r0, r4, #0
	movs r2, #0
	bl Warehouse_SetSubState
_080B673A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B6740: .4byte 0x00000107
_080B6744: .4byte 0x000013F4
_080B6748: .4byte 0x000011B8
_080B674C: .4byte 0x0000140D
_080B6750: .4byte FUN_080b685c
