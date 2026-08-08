	push {lr}
	adds r0, #0xa0
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	pop {r0}
	bx r0
