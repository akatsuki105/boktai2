	push {lr}
	adds r2, r0, #0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #1
	bls _080CFA74
	cmp r0, #5
	bne _080CFA92
_080CFA74:
	cmp r1, #0
	beq _080CFA9A
	cmp r1, #3
	beq _080CFA9A
	cmp r1, #6
	beq _080CFA9A
	cmp r1, #4
	bne _080CFA9E
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CFA9A
	b _080CFA9E
_080CFA92:
	cmp r1, #0
	beq _080CFA9A
	cmp r1, #4
	bne _080CFA9E
_080CFA9A:
	movs r0, #1
	b _080CFAA0
_080CFA9E:
	movs r0, #0
_080CFAA0:
	pop {r1}
	bx r1
