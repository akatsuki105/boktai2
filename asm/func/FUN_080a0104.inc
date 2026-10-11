	push {lr}
	adds r2, r1, #0
	ldrb r1, [r0, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A0120
	ldr r0, _080A011C @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x2c]
	b _080A0126
	.align 2, 0
_080A011C: .4byte 0x03002BE0
_080A0120:
	ldr r0, _080A0134 @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x30]
_080A0126:
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	ble _080A0138
	movs r0, #0
	b _080A013A
	.align 2, 0
_080A0134: .4byte 0x03002BE0
_080A0138:
	movs r0, #1
_080A013A:
	pop {r1}
	bx r1
	.align 2, 0
