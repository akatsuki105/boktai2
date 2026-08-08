	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r6, r0, #0
	b _082322CC
_08232274:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _082322B8
	ldrb r0, [r5]
	adds r1, r0, #0
	subs r1, #0x80
	ldrb r2, [r5, #1]
	adds r5, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0823229A
	adds r4, r2, #0
	subs r4, #0x61
	cmp r4, #0x7e
	ble _0823229C
	adds r4, #1
	b _0823229C
_0823229A:
	subs r4, r2, #2
_0823229C:
	adds r0, r1, #0
	subs r0, #0x21
	movs r1, #2
	bl Div
	adds r1, r0, #0
	adds r1, #0x81
	cmp r1, #0x9f
	ble _082322B0
	adds r1, #0x40
_082322B0:
	strb r1, [r6]
	strb r4, [r6, #1]
	adds r6, #1
	b _082322BA
_082322B8:
	strb r1, [r6]
_082322BA:
	ldrb r0, [r5]
	cmp r0, #0xd
	bne _082322C8
	ldrb r0, [r5, #1]
	cmp r0, #0xa
	bne _082322C8
	adds r5, #1
_082322C8:
	adds r5, #1
	adds r6, #1
_082322CC:
	ldrb r1, [r5]
	cmp r1, #0
	bne _08232274
	movs r0, #0
	strb r0, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
