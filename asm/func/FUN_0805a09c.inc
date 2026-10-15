	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0805A0BE
	movs r0, #0
	strb r0, [r4, #1]
	adds r3, r4, #0
	adds r3, #0x6c
	ldrh r1, [r3, #6]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3, #6]
	strb r2, [r4, #4]
_0805A0BE:
	ldrh r0, [r4, #8]
	cmp r0, #0x1f
	bls _0805A0D0
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08059d38
	b _0805A0D4
_0805A0D0:
	adds r0, #1
	strh r0, [r4, #8]
_0805A0D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
