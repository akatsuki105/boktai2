	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	b _0823767C
_08237674:
	strb r3, [r1]
	adds r4, #1
	adds r1, #1
	adds r0, #1
_0823767C:
	cmp r0, r2
	bge _08237686
	ldrb r3, [r4]
	cmp r3, #0
	bne _08237674
_08237686:
	adds r2, #1
	cmp r0, r2
	bge _0823769A
	movs r3, #0
	subs r0, r2, r0
_08237690:
	strb r3, [r1]
	adds r1, #1
	subs r0, #1
	cmp r0, #0
	bne _08237690
_0823769A:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
