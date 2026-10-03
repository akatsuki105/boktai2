	push {r4, r5, lr}
	bl GetWeapon
	adds r5, r0, #0
	ldr r2, _080BCE84 @ =0x08DA9E68
	ldrb r1, [r5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0, #0xa]
	cmp r2, #0
	bne _080BCE88
	movs r0, #0
	b _080BCECE
	.align 2, 0
_080BCE84: .4byte 0x08DA9E68
_080BCE88:
	movs r3, #0
	adds r1, r5, #0
	movs r4, #2
_080BCE8E:
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	beq _080BCE96
	adds r3, #1
_080BCE96:
	adds r1, #4
	subs r4, #1
	cmp r4, #0
	bge _080BCE8E
	cmp r3, #0
	bne _080BCEB2
	movs r0, #1
	ldrsb r0, [r5, r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	adds r1, #0x32
	adds r0, r2, #0
	muls r0, r1, r0
	b _080BCEBC
_080BCEB2:
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, #0x64
	muls r0, r2, r0
_080BCEBC:
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	ble _080BCECC
	adds r0, r2, #0
	b _080BCECE
_080BCECC:
	movs r0, #1
_080BCECE:
	pop {r4, r5}
	pop {r1}
	bx r1
