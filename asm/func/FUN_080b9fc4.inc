	push {lr}
	adds r1, #0x20
	ldrb r2, [r0, #3]
	adds r0, r1, #0
	adds r1, r2, #0
	bl FUN_080b9938
	pop {r0}
	bx r0
	.align 2, 0
