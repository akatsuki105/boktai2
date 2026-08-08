	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0821D6AA
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0821D6AC
_0821D6AA:
	movs r0, #0
_0821D6AC:
	cmp r0, #0
	beq _0821D6BA
	adds r0, r2, #0
	movs r1, #0x13
	movs r2, #1
	bl FUN_08221268
_0821D6BA:
	pop {r0}
	bx r0
	.align 2, 0
