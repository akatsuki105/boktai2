	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0800A196:
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x2c
	adds r1, r5, r0
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A1AA
	adds r0, r5, #0
	bl FUN_08009c08
_0800A1AA:
	adds r4, #1
	cmp r4, #0xf
	ble _0800A196
	ldr r1, _0800A1BC @ =0x03000040
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800A1BC: .4byte 0x03000040
