	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0
	movs r1, #1
	movs r2, #3
	bl FUN_080b5b30
	adds r2, r0, #0
	movs r3, #0
	ldr r0, _080B90C4 @ =0x00001410
	adds r1, r5, r0
	ldrb r0, [r1]
	ldr r6, _080B90C8 @ =0x0000141E
	adds r4, r5, r6
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r3, r0
	bge _080B9076
	ldr r0, _080B90CC @ =0x00001419
	adds r6, r5, r0
	ldr r0, _080B90D0 @ =0xFFFFF000
	adds r7, r0, #0
_080B905C:
	ldrb r0, [r1]
	adds r0, r6, r0
	ldrb r0, [r0]
	adds r0, r0, r3
	orrs r0, r7
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	ldrb r0, [r1]
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r3, r0
	blt _080B905C
_080B9076:
	movs r1, #0
	ldr r6, _080B90D0 @ =0xFFFFF000
	adds r4, r6, #0
_080B907C:
	adds r0, r1, #0
	adds r0, #0x1d
	orrs r0, r4
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	adds r1, #1
	cmp r1, #2
	ble _080B907C
	ldr r0, _080B90C4 @ =0x00001410
	adds r1, r5, r0
	ldr r4, _080B90D4 @ =0x00001423
	adds r0, r5, r4
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0xf0
	lsls r6, r6, #8
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0xa
	bgt _080B90BC
	ldr r1, _080B90D8 @ =0x0000F010
	adds r0, r1, #0
_080B90B2:
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0xa
	ble _080B90B2
_080B90BC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B90C4: .4byte 0x00001410
_080B90C8: .4byte 0x0000141E
_080B90CC: .4byte 0x00001419
_080B90D0: .4byte 0xFFFFF000
_080B90D4: .4byte 0x00001423
_080B90D8: .4byte 0x0000F010
