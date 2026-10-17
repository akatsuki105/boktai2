	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080B6EAC
	ldr r1, _080B6E90 @ =0x00001429
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080B6E98
	ldr r1, _080B6E94 @ =0x0000130C
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080B6F9A
	.align 2, 0
_080B6E90: .4byte 0x00001429
_080B6E94: .4byte 0x0000130C
_080B6E98:
	ldr r1, _080B6EA8 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080B6F9A
	.align 2, 0
_080B6EA8: .4byte 0x0000130C
_080B6EAC:
	ldr r0, _080B6EE8 @ =0x0000142E
	adds r6, r4, r0
	ldrb r0, [r6]
	ldr r1, _080B6EEC @ =0x00001458
	adds r7, r4, r1
	adds r0, r7, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	bne _080B6EF8
	ldr r0, _080B6EF0 @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	beq _080B6F9A
	ldrb r1, [r5]
	adds r0, r4, #0
	bl Warehouse_FindRegisteredSlot
	cmp r0, #0
	blt _080B6F9A
	ldr r1, _080B6EF4 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	b _080B6F9A
	.align 2, 0
_080B6EE8: .4byte 0x0000142E
_080B6EEC: .4byte 0x00001458
_080B6EF0: .4byte 0x0000142B
_080B6EF4: .4byte 0x0000142C
_080B6EF8:
	ldr r0, _080B6F1C @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	ldrb r1, [r6]
	cmp r0, r1
	bne _080B6F3C
	ldr r1, _080B6F20 @ =0x00001428
	adds r0, r4, r1
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B6F68
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080B6F28
	ldr r1, _080B6F24 @ =0x00001413
	b _080B6F2A
	.align 2, 0
_080B6F1C: .4byte 0x0000142B
_080B6F20: .4byte 0x00001428
_080B6F24: .4byte 0x00001413
_080B6F28:
	ldr r1, _080B6F38 @ =0x00001412
_080B6F2A:
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mvns r0, r0
	lsrs r1, r0, #0x1f
	b _080B6F72
	.align 2, 0
_080B6F38: .4byte 0x00001412
_080B6F3C:
	ldrb r1, [r5]
	adds r0, r4, #0
	bl Warehouse_FindRegisteredSlot
	cmp r0, #0
	blt _080B6F50
	ldr r1, _080B6F4C @ =0x0000142C
	b _080B6F5E
	.align 2, 0
_080B6F4C: .4byte 0x0000142C
_080B6F50:
	ldrb r1, [r6]
	adds r0, r4, #0
	bl Warehouse_FindRegisteredSlot
	cmp r0, #0
	blt _080B6F70
	ldr r1, _080B6F6C @ =0x00001429
_080B6F5E:
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #3
	bls _080B6F72
_080B6F68:
	movs r1, #0
	b _080B6F72
	.align 2, 0
_080B6F6C: .4byte 0x00001429
_080B6F70:
	movs r1, #1
_080B6F72:
	cmp r1, #1
	bne _080B6F8C
	ldr r1, _080B6F88 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080B6F9A
	.align 2, 0
_080B6F88: .4byte 0x0000130C
_080B6F8C:
	ldr r1, _080B6FA0 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080B6F9A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B6FA0: .4byte 0x0000130C
