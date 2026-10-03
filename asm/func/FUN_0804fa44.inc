	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x54
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804FA60
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0804FA60
	movs r0, #1
	rsbs r0, r0, #0
	b _0804FA8E
_0804FA60:
	strb r1, [r4, #1]
	cmp r3, #0
	ble _0804FA72
	adds r1, r4, #4
_0804FA68:
	ldm r2!, {r0}
	stm r1!, {r0}
	subs r3, #1
	cmp r3, #0
	bne _0804FA68
_0804FA72:
	adds r0, r4, #0
	bl FUN_0804e514
	adds r2, r0, #0
	cmp r2, #0
	bge _0804FA8C
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0804FA8C
	adds r1, r5, #0
	adds r1, #0x2a
	movs r0, #1
	strb r0, [r1]
_0804FA8C:
	adds r0, r2, #0
_0804FA8E:
	pop {r4, r5}
	pop {r1}
	bx r1
