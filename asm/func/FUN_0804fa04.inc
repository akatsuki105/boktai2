	push {lr}
	adds r1, r0, #0
	adds r3, r1, #0
	adds r3, #0x3c
	adds r2, r1, #0
	adds r2, #0x48
	ldrb r0, [r3, #6]
	cmp r0, #0
	bne _0804FA2E
	ldrb r0, [r2, #6]
	cmp r0, #0
	bne _0804FA28
	ldr r0, [r1, #0x3c]
	cmp r0, #0
	bne _0804FA28
	ldr r0, [r1, #0x48]
	cmp r0, #0
	beq _0804FA3E
_0804FA28:
	ldrb r0, [r3, #6]
	cmp r0, #0
	beq _0804FA3A
_0804FA2E:
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804FA3A
	subs r0, #1
	strb r0, [r1]
_0804FA3A:
	movs r0, #1
	b _0804FA40
_0804FA3E:
	movs r0, #0
_0804FA40:
	pop {r1}
	bx r1
