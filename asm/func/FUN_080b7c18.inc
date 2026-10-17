	push {r4, r5, r6, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080B7C54
	ldr r1, _080B7C38 @ =0x00001429
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080B7C40
	ldr r2, _080B7C3C @ =0x0000130C
	adds r0, r4, r2
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080B7D5E
	.align 2, 0
_080B7C38: .4byte 0x00001429
_080B7C3C: .4byte 0x0000130C
_080B7C40:
	ldr r3, _080B7C50 @ =0x0000130C
	adds r0, r4, r3
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080B7D5E
	.align 2, 0
_080B7C50: .4byte 0x0000130C
_080B7C54:
	ldr r5, _080B7CA8 @ =0x0000142E
	adds r0, r4, r5
	ldrb r3, [r0]
	ldr r0, _080B7CAC @ =0x00001458
	adds r1, r4, r0
	adds r0, r1, r3
	ldrb r6, [r0]
	ldr r0, _080B7CB0 @ =0x030046A0
	ldr r2, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	bge _080B7CBC
	ldr r3, _080B7CB4 @ =0x0000142B
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
	blt _080B7D5E
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _080B7D5E
	ldr r1, _080B7CB8 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	b _080B7D5E
	.align 2, 0
_080B7CA8: .4byte 0x0000142E
_080B7CAC: .4byte 0x00001458
_080B7CB0: .4byte 0x030046A0
_080B7CB4: .4byte 0x0000142B
_080B7CB8: .4byte 0x0000142C
_080B7CBC:
	ldr r0, _080B7CE0 @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, r3
	bne _080B7D00
	ldr r1, _080B7CE4 @ =0x00001428
	adds r0, r4, r1
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B7D2C
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080B7CEC
	ldr r2, _080B7CE8 @ =0x00001413
	adds r0, r4, r2
	b _080B7CF0
	.align 2, 0
_080B7CE0: .4byte 0x0000142B
_080B7CE4: .4byte 0x00001428
_080B7CE8: .4byte 0x00001413
_080B7CEC:
	ldr r3, _080B7CFC @ =0x00001412
	adds r0, r4, r3
_080B7CF0:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mvns r0, r0
	lsrs r1, r0, #0x1f
	b _080B7D36
	.align 2, 0
_080B7CFC: .4byte 0x00001412
_080B7D00:
	ldrb r0, [r5]
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _080B7D1C
	ldr r1, _080B7D18 @ =0x0000142C
	adds r0, r4, r1
	b _080B7D24
	.align 2, 0
_080B7D18: .4byte 0x0000142C
_080B7D1C:
	cmp r6, r0
	bne _080B7D34
	ldr r2, _080B7D30 @ =0x00001429
	adds r0, r4, r2
_080B7D24:
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #3
	bls _080B7D36
_080B7D2C:
	movs r1, #0
	b _080B7D36
	.align 2, 0
_080B7D30: .4byte 0x00001429
_080B7D34:
	movs r1, #1
_080B7D36:
	cmp r1, #1
	bne _080B7D50
	ldr r3, _080B7D4C @ =0x0000130C
	adds r0, r4, r3
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080B7D5E
	.align 2, 0
_080B7D4C: .4byte 0x0000130C
_080B7D50:
	ldr r5, _080B7D64 @ =0x0000130C
	adds r0, r4, r5
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080B7D5E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B7D64: .4byte 0x0000130C
