	push {lr}
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r0, r1
	bl FUN_08022428
	pop {r0}
	bx r0
