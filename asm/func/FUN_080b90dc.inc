	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080B911C @ =0x0000140C
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080B90EE
	b _080B920C
_080B90EE:
	ldr r2, _080B9120 @ =0x00001479
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080B9124
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	b _080B913C
	.align 2, 0
_080B911C: .4byte 0x0000140C
_080B9120: .4byte 0x00001479
_080B9124:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
_080B913C:
	str r0, [r1]
	adds r0, r4, #0
	bl Warehouse_HandleTabInput
	adds r5, r0, #0
	cmp r5, #0
	beq _080B91CA
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _080B9170 @ =0x00001410
	adds r1, r4, r2
	adds r2, #4
	adds r0, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #4
	bhi _080B91BC
	lsls r0, r0, #2
	ldr r1, _080B9174 @ =_080B9178
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B9170: .4byte 0x00001410
_080B9174: .4byte _080B9178
_080B9178: @ jump table
	.4byte _080B918C @ case 0
	.4byte _080B9196 @ case 1
	.4byte _080B91A0 @ case 2
	.4byte _080B91AA @ case 3
	.4byte _080B91B4 @ case 4
_080B918C:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b695c
	b _080B91BC
_080B9196:
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080b695c
	b _080B91BC
_080B91A0:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b78a4
	b _080B91BC
_080B91AA:
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080b78a4
	b _080B91BC
_080B91B4:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b88c4
_080B91BC:
	adds r0, r4, #0
	bl FUN_080b8fa4
	adds r0, r4, #0
	bl FUN_080b9030
	b _080B922A
_080B91CA:
	ldr r0, _080B91FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B922A
	ldr r0, _080B9200 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B9204 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B9208 @ =FUN_080b9248
	adds r0, r4, #0
	bl Warehouse_SetState
	b _080B9236
	.align 2, 0
_080B91FC: .4byte 0x030044E0
_080B9200: .4byte 0x00000119
_080B9204: .4byte 0x0000FFFF
_080B9208: .4byte FUN_080b9248
_080B920C:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080B9240 @ =0x00001479
	adds r0, r4, r1
	strb r3, [r0]
_080B922A:
	ldr r2, _080B9244 @ =0x00001498
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080B9236:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B9240: .4byte 0x00001479
_080B9244: .4byte 0x00001498
