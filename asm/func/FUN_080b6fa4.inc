	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B6FE8 @ =0x0000142E
	adds r5, r4, r0
	ldrb r0, [r5]
	ldr r1, _080B6FEC @ =0x00001458
	adds r6, r4, r1
	adds r0, r6, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	bne _080B6FF8
	ldr r3, _080B6FF0 @ =0x0000142B
	adds r5, r4, r3
	ldrb r0, [r5]
	adds r0, r6, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	beq _080B709A
	ldrb r1, [r5]
	adds r0, r4, #0
	bl Warehouse_FindRegisteredSlot
	cmp r0, #0
	blt _080B70A4
_080B6FDC:
	ldr r1, _080B6FF4 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080B709A
	b _080B70A4
	.align 2, 0
_080B6FE8: .4byte 0x0000142E
_080B6FEC: .4byte 0x00001458
_080B6FF0: .4byte 0x0000142B
_080B6FF4: .4byte 0x0000142C
_080B6FF8:
	ldr r3, _080B7044 @ =0x0000142B
	adds r6, r4, r3
	ldrb r0, [r6]
	ldrb r1, [r5]
	cmp r0, r1
	bne _080B7070
	subs r3, #3
	adds r0, r4, r3
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B709A
	ldrb r0, [r6]
	cmp r0, #0xf
	bhi _080B7050
	ldr r0, _080B7048 @ =0x00001413
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B709A
	movs r0, #3
	ands r0, r1
_080B702A:
	ldr r3, _080B704C @ =0x00001429
	adds r1, r4, r3
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	subs r0, #0x10
	asrs r0, r0, #2
	adds r3, #1
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	strb r0, [r6]
	b _080B70A4
	.align 2, 0
_080B7044: .4byte 0x0000142B
_080B7048: .4byte 0x00001413
_080B704C: .4byte 0x00001429
_080B7050:
	ldr r0, _080B706C @ =0x00001412
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B709A
	adds r0, r1, #0
	subs r0, #0x10
	movs r1, #3
	ands r0, r1
	adds r0, #4
	b _080B702A
	.align 2, 0
_080B706C: .4byte 0x00001412
_080B7070:
	cmp r0, #0x20
	bne _080B7078
	movs r0, #2
	b _080B70A6
_080B7078:
	ldrb r1, [r6]
	adds r0, r4, #0
	bl Warehouse_FindRegisteredSlot
	cmp r0, #0
	bge _080B6FDC
	ldrb r1, [r5]
	adds r0, r4, #0
	bl Warehouse_FindRegisteredSlot
	cmp r0, #0
	blt _080B70A4
	ldr r3, _080B70A0 @ =0x00001429
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bls _080B70A4
_080B709A:
	movs r0, #0
	b _080B70A6
	.align 2, 0
_080B70A0: .4byte 0x00001429
_080B70A4:
	movs r0, #1
_080B70A6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
