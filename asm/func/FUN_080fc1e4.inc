	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080FC1FC @ =0x0000046D
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080FC200
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _080FC202
	.align 2, 0
_080FC1FC: .4byte 0x0000046D
_080FC200:
	movs r0, #0
_080FC202:
	adds r5, r0, #0
	cmp r5, #0
	beq _080FC23A
	movs r2, #1
	ldr r1, _080FC220 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FC224
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080FC22E
	.align 2, 0
_080FC220: .4byte 0x0000025D
_080FC224:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_080FC22E:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080136b4
	b _080FC282
_080FC23A:
	cmp r1, #0x1a
	ble _080FC27C
	adds r0, r4, #0
	movs r1, #9
	bl FUN_080ef86c
	ldr r3, _080FC270 @ =FUN_080fc28c
	movs r2, #0xd
	ldr r0, _080FC274 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080FC278 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
	b _080FC282
	.align 2, 0
_080FC270: .4byte FUN_080fc28c
_080FC274: .4byte 0x0000046D
_080FC278: .4byte 0x0000046B
_080FC27C:
	ldr r1, _080FC288 @ =0x0000046E
	adds r0, r4, r1
	strb r5, [r0]
_080FC282:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080FC288: .4byte 0x0000046E
