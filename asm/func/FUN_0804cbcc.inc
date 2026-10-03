	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CBE2
	movs r0, #0
	strb r0, [r1]
	strb r0, [r4, #0x1b]
	strb r0, [r4, #0x1c]
_0804CBE2:
	adds r0, r4, #0
	bl FUN_0804bc10
	cmp r0, #0
	beq _0804CBF2
	adds r0, r4, #0
	bl FUN_0804ba64
_0804CBF2:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
