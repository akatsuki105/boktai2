	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080f8da4
	bl FUN_080f9b34
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r1}
	bx r1
