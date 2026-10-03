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
	adds r2, r3, #1
	cmp r3, #8
	bne _080B9F64
_080B9F2C:
	movs r2, #0
	b _080B9F64
_080B9F30:
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
	blt _080B9F5E
	cmp r0, r5
	beq _080B9F5E
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl MenuCursor_GetSlot
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _080B9F6A
_080B9F5E:
	cmp r2, #8
	beq _080B9F2C
	adds r2, #1
_080B9F64:
	cmp r2, r3
	bne _080B9F30
	movs r0, #0
_080B9F6A:
	pop {r4, r5}
	pop {r1}
	bx r1
