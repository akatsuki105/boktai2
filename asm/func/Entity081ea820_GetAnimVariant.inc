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
	bls _081EA518
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081EA51E
_081EA518:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_081EA51E:
	pop {r0}
	bx r0
	.align 2, 0
