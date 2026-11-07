	push {lr}
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814B79E
	subs r0, #1
	strb r0, [r1]
_0814B79E:
	pop {r0}
	bx r0
	.align 2, 0
