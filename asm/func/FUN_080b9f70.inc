	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b9da8
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080B9F8A
	adds r0, r4, #0
	bl FUN_080b9df0
	b _080B9FBC
_080B9F8A:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080B9F9A
	adds r0, r4, #0
	bl FUN_080b9e50
	b _080B9FBC
_080B9F9A:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B9FAA
	adds r0, r4, #0
	bl FUN_080b9eb0
	b _080B9FBC
_080B9FAA:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080B9FB6
	movs r0, #0
	b _080B9FBC
_080B9FB6:
	adds r0, r4, #0
	bl FUN_080b9f10
_080B9FBC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
