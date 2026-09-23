	push {r4, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _080489A6
	ldrb r1, [r3]
	adds r1, #1
	b _080489AA
_080489A6:
	ldrb r1, [r3]
	adds r1, #2
_080489AA:
	strb r1, [r3]
	ldrb r4, [r3]
	ldrb r2, [r3, #2]
	ldrb r1, [r3, #4]
	adds r1, r2, r1
	cmp r4, r1
	blt _080489BC
	subs r1, r4, r1
	strb r1, [r3]
_080489BC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
