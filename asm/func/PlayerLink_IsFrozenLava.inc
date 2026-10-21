	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFC36
	movs r1, #0x10
	ldr r0, _080CFC24 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFC28 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFC2C
	movs r0, #1
	b _080CFC2E
	.align 2, 0
_080CFC24: .4byte 0x030046A0
_080CFC28: .4byte 0x00000934
_080CFC2C:
	movs r0, #0
_080CFC2E:
	cmp r0, #0
	beq _080CFC36
	movs r0, #1
	b _080CFC38
_080CFC36:
	movs r0, #0
_080CFC38:
	pop {r1}
	bx r1
