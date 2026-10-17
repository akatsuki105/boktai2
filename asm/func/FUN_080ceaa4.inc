	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r1, #0x63
	asrs r1, r1, #1
	ldrb r2, [r4, #1]
	cmp r2, #3
	beq _080CEADC
	cmp r2, #3
	ble _080CEAC6
	cmp r2, #4
	beq _080CEAE0
	b _080CEAF6
_080CEAC6:
	cmp r2, #0
	blt _080CEAF6
	ldrb r0, [r4, #4]
	adds r0, r1, r0
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	cmp r0, #0
	bgt _080CEAF6
	movs r0, #1
	b _080CEAF6
_080CEADC:
	adds r0, r1, #0
	b _080CEAF6
_080CEAE0:
	movs r0, #0x28
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	subs r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	lsls r0, r0, #1
_080CEAF6:
	pop {r4}
	pop {r1}
	bx r1
