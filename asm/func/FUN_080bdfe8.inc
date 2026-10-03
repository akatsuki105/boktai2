	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080BE048 @ =0x00001690
	adds r0, r4, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080BE040
	ldr r1, _080BE04C @ =0x0000178A
	adds r0, r4, r1
	ldrb r5, [r0]
	adds r0, r5, #0
	bl FUN_080bce64
	ldr r3, _080BE050 @ =0x030046A0
	ldr r2, [r3]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, _080BE054 @ =0x0000270F
	cmp r1, r2
	ble _080BE028
	ldr r0, [r3]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	strh r2, [r0]
_080BE028:
	adds r0, r5, #0
	bl FUN_08242c08
	ldr r1, _080BE058 @ =0x00001659
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r1, _080BE05C @ =FUN_080be060
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080bcdf8
_080BE040:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE048: .4byte 0x00001690
_080BE04C: .4byte 0x0000178A
_080BE050: .4byte 0x030046A0
_080BE054: .4byte 0x0000270F
_080BE058: .4byte 0x00001659
_080BE05C: .4byte FUN_080be060
