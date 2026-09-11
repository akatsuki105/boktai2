	push {r4, r5, lr}
	ldr r0, _0800A484 @ =0x03000040
	ldr r5, [r0]
	cmp r5, #0
	beq _0800A47E
	movs r4, #0
_0800A464:
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x2c
	adds r1, r5, r0
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A478
	adds r0, r5, #0
	bl FUN_08009c08
_0800A478:
	adds r4, #1
	cmp r4, #0xf
	ble _0800A464
_0800A47E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800A484: .4byte 0x03000040
