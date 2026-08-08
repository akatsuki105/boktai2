	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _080EFF2C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080EFF30
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080EFF32
	.align 2, 0
_080EFF2C: .4byte 0x0000046D
_080EFF30:
	movs r0, #0
_080EFF32:
	cmp r0, #0
	beq _080EFF56
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _080EFFDC @ =0x00000482
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
_080EFF56:
	ldr r3, _080EFFE0 @ =0x00000542
	adds r5, r6, r3
	ldrb r1, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _080F0050
	cmp r4, #0x3c
	bgt _080EFF6A
	b _080F00CC
_080EFF6A:
	movs r1, #3
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r3, #0
	strb r1, [r0]
	ldr r7, _080EFFE4 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _080EFFE8 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r4, #0x1c
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #3
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r4, [r0]
	movs r1, #2
	adds r7, #1
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _080EFFEC @ =0x0000046B
	adds r0, r6, r2
	strb r3, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r3, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #1
	bne _080EFFF4
	ldr r3, _080EFFF0 @ =0x00000541
	adds r0, r6, r3
	ldrb r0, [r0]
	lsrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r6, r4
	b _080F0030
	.align 2, 0
_080EFFDC: .4byte 0x00000482
_080EFFE0: .4byte 0x00000542
_080EFFE4: .4byte 0x00000469
_080EFFE8: .4byte 0x0000046A
_080EFFEC: .4byte 0x0000046B
_080EFFF0: .4byte 0x00000541
_080EFFF4:
	movs r1, #0
	ldrb r4, [r6, #5]
	ldr r7, _080F0040 @ =0x0203B400
	mov ip, r7
	ldr r2, _080F0044 @ =0x030046B8
	ldr r7, _080F0048 @ =0x000003FF
	movs r5, #3
	adds r3, r4, #0
_080F0004:
	ldr r0, [r2]
	adds r0, #1
	ands r0, r7
	str r0, [r2]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r3
	bne _080F0022
	adds r1, #1
	cmp r1, #3
	ble _080F0004
	adds r0, r4, #0
_080F0022:
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
_080F0030:
	strb r0, [r1]
	ldr r3, _080F004C @ =0x00000542
	adds r1, r6, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _080F00CC
	.align 2, 0
_080F0040: .4byte 0x0203B400
_080F0044: .4byte 0x030046B8
_080F0048: .4byte 0x000003FF
_080F004C: .4byte 0x00000542
_080F0050:
	movs r0, #0xff
	orrs r0, r1
	strb r0, [r5]
	cmp r4, #0x1e
	ble _080F00CC
	ldr r4, _080F00D4 @ =0x0000054F
	adds r0, r6, r4
	ldrb r2, [r0]
	movs r7, #0xa9
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r3, [r0]
	ldr r1, _080F00D8 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #0
	movs r5, #1
	strb r5, [r0]
	subs r4, #0xe4
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #0xb
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	adds r4, #0xe1
	adds r0, r6, r4
	ldrb r2, [r0]
	subs r7, #6
	adds r0, r6, r7
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r4, [r0]
	subs r7, #0xe5
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _080F00DC @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _080F00E0 @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _080F00E4 @ =0x00000484
	adds r0, r6, r4
	str r1, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _080F00E8 @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_080F00CC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F00D4: .4byte 0x0000054F
_080F00D8: .4byte 0x0000046D
_080F00DC: .4byte 0x00000469
_080F00E0: .4byte 0x0000046A
_080F00E4: .4byte 0x00000484
_080F00E8: .4byte 0xFFFFFBFF
