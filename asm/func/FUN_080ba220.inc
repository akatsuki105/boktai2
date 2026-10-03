	push {lr}
	adds r1, r0, #0
	cmp r1, #4
	bls _080BA238
	cmp r1, #6
	beq _080BA238
	cmp r1, #7
	beq _080BA238
	cmp r1, #9
	beq _080BA238
	cmp r1, #0xa
	bne _080BA274
_080BA238:
	ldr r0, _080BA268 @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, _080BA26C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xef
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r0, [r1]
	muls r0, r2, r0
	movs r1, #0x64
	bl Div
	cmp r0, #0
	bgt _080BA25E
	movs r0, #1
_080BA25E:
	ldr r1, _080BA270 @ =0x0000270F
	cmp r0, r1
	ble _080BA27E
	adds r0, r1, #0
	b _080BA27E
	.align 2, 0
_080BA268: .4byte 0x08DAA8D8
_080BA26C: .4byte 0x030046A0
_080BA270: .4byte 0x0000270F
_080BA274:
	ldr r0, _080BA284 @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, [r1]
_080BA27E:
	pop {r1}
	bx r1
	.align 2, 0
_080BA284: .4byte 0x08DAA8D8
