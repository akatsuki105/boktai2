	push {lr}
	adds r3, r0, #0
	movs r2, #2
	adds r1, r3, #0
	adds r1, #0x98
	ldr r1, [r1]
	ands r1, r2
	cmp r1, #0
	beq _080CA000
	movs r1, #1
	movs r2, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	movs r0, #1
_080CA000:
	pop {r1}
	bx r1
