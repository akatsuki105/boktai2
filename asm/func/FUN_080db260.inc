	push {lr}
	adds r3, r1, #0
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bls _080DB284
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _080DB28A
_080DB284:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_080DB28A:
	pop {r0}
	bx r0
	.align 2, 0
