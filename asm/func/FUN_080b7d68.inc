	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080B7DC4 @ =0x0000142E
	adds r0, r4, r1
	ldrb r3, [r0]
	ldr r2, _080B7DC8 @ =0x00001458
	adds r1, r4, r2
	adds r0, r1, r3
	ldrb r6, [r0]
	ldr r0, _080B7DCC @ =0x030046A0
	ldr r2, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	bge _080B7DD8
	ldr r3, _080B7DD0 @ =0x0000142B
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, r1, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _080B7E7C
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _080B7E84
_080B7DB8:
	ldr r1, _080B7DD4 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080B7E7C
	b _080B7E84
	.align 2, 0
_080B7DC4: .4byte 0x0000142E
_080B7DC8: .4byte 0x00001458
_080B7DCC: .4byte 0x030046A0
_080B7DD0: .4byte 0x0000142B
_080B7DD4: .4byte 0x0000142C
_080B7DD8:
	ldr r0, _080B7E24 @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, r3
	bne _080B7E54
	ldr r1, _080B7E28 @ =0x00001428
	adds r0, r4, r1
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B7E7C
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080B7E34
	ldr r3, _080B7E2C @ =0x00001413
	adds r2, r4, r3
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B7E7C
	movs r0, #3
	ands r0, r1
_080B7E08:
	ldr r3, _080B7E30 @ =0x00001429
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
	strb r0, [r5]
	b _080B7E84
	.align 2, 0
_080B7E24: .4byte 0x0000142B
_080B7E28: .4byte 0x00001428
_080B7E2C: .4byte 0x00001413
_080B7E30: .4byte 0x00001429
_080B7E34:
	ldr r0, _080B7E50 @ =0x00001412
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B7E7C
	adds r0, r1, #0
	subs r0, #0x10
	movs r1, #3
	ands r0, r1
	adds r0, #4
	b _080B7E08
	.align 2, 0
_080B7E50: .4byte 0x00001412
_080B7E54:
	cmp r0, #0x20
	bne _080B7E5C
	movs r0, #2
	b _080B7E86
_080B7E5C:
	ldrb r0, [r5]
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	beq _080B7DB8
	cmp r6, r0
	bne _080B7E84
	ldr r2, _080B7E80 @ =0x00001429
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080B7E84
_080B7E7C:
	movs r0, #0
	b _080B7E86
	.align 2, 0
_080B7E80: .4byte 0x00001429
_080B7E84:
	movs r0, #1
_080B7E86:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
