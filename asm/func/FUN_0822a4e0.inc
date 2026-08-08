	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #4]
	cmp r0, #0
	beq _0822A4F2
	ldrb r1, [r2, #0xa]
	adds r0, r2, #0
	bl FUN_0822a36c
_0822A4F2:
	pop {r0}
	bx r0
	.align 2, 0
