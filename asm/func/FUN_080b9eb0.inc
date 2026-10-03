	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r1, r3, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	subs r2, r3, #1
	cmp r3, #0
	bne _080B9F04
_080B9ECC:
	movs r2, #8
	b _080B9F04
_080B9ED0:
	lsls r1, r2, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080B9EFE
	cmp r0, r5
	beq _080B9EFE
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl MenuCursor_GetSlot
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _080B9F0A
_080B9EFE:
	cmp r2, #0
	beq _080B9ECC
	subs r2, #1
_080B9F04:
	cmp r2, r3
	bne _080B9ED0
	movs r0, #0
_080B9F0A:
	pop {r4, r5}
	pop {r1}
	bx r1
