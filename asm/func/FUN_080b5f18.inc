	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B5F48 @ =0x0000142E
	adds r6, r4, r0
	ldrb r0, [r6]
	ldr r1, _080B5F4C @ =0x00001458
	adds r5, r4, r1
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	bge _080B5F54
	ldr r1, _080B5F50 @ =0x0000142B
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	blt _080B5F8E
	b _080B5FBA
	.align 2, 0
_080B5F48: .4byte 0x0000142E
_080B5F4C: .4byte 0x00001458
_080B5F50: .4byte 0x0000142B
_080B5F54:
	ldr r5, _080B5F78 @ =0x0000142B
	adds r3, r4, r5
	ldrb r0, [r3]
	ldrb r6, [r6]
	cmp r0, r6
	bne _080B5FC4
	cmp r0, #0xf
	bhi _080B5F80
	ldr r0, _080B5F7C @ =0x00001413
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B5F8E
	movs r0, #3
	ands r0, r1
	b _080B5FA2
	.align 2, 0
_080B5F78: .4byte 0x0000142B
_080B5F7C: .4byte 0x00001413
_080B5F80:
	ldr r0, _080B5F94 @ =0x00001412
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bge _080B5F98
_080B5F8E:
	movs r0, #0
	b _080B5FCA
	.align 2, 0
_080B5F94: .4byte 0x00001412
_080B5F98:
	adds r0, r1, #0
	subs r0, #0x10
	movs r1, #3
	ands r0, r1
	adds r0, #4
_080B5FA2:
	ldr r5, _080B5FC0 @ =0x00001429
	adds r1, r4, r5
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	subs r0, #0x10
	asrs r0, r0, #2
	adds r5, #1
	adds r1, r4, r5
	strb r0, [r1]
	ldrb r0, [r2]
	strb r0, [r3]
_080B5FBA:
	movs r0, #1
	b _080B5FCA
	.align 2, 0
_080B5FC0: .4byte 0x00001429
_080B5FC4:
	cmp r0, #0x20
	bne _080B5FBA
	movs r0, #2
_080B5FCA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
