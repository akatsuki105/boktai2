	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080BC2BC @ =0x00001314
	adds r0, r4, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080BC2B6
	ldr r2, _080BC2C0 @ =0x0000140E
	adds r0, r4, r2
	ldrb r6, [r0]
	ldr r2, _080BC2C4 @ =0x08DAA7B0
	ldr r5, _080BC2C8 @ =0x030046A0
	ldr r1, [r5]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r2, #6
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	ldr r2, [r5]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, _080BC2CC @ =0x0000270F
	cmp r1, r2
	ble _080BC29E
	ldr r0, [r5]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	strh r2, [r0]
_080BC29E:
	adds r0, r6, #0
	bl RemoveArmorFromInventory
	ldr r2, _080BC2D0 @ =0x0000151C
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	ldr r1, _080BC2D4 @ =FUN_080bc2d8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
_080BC2B6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BC2BC: .4byte 0x00001314
_080BC2C0: .4byte 0x0000140E
_080BC2C4: .4byte 0x08DAA7B0
_080BC2C8: .4byte 0x030046A0
_080BC2CC: .4byte 0x0000270F
_080BC2D0: .4byte 0x0000151C
_080BC2D4: .4byte FUN_080bc2d8
