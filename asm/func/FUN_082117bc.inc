	push {lr}
	adds r2, r0, #0
	adds r2, #0x24
	strb r1, [r2]
	bl FUN_08211640
	pop {r0}
	bx r0
