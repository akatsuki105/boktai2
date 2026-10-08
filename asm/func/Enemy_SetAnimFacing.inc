	push {r4, lr}
	adds r4, r1, #0
	adds r3, r2, #0
	ldrb r1, [r0, #5]
	adds r1, #0x20
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r2, #3
	ands r2, r1
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r2, #0
	strb r2, [r0]
	cmp r1, #1
	bls _080E5D74
	movs r0, #1
	strb r0, [r3]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r4]
	b _080E5D7A
_080E5D74:
	movs r0, #0
	strb r0, [r3]
	strb r2, [r4]
_080E5D7A:
	pop {r4}
	pop {r0}
	bx r0
