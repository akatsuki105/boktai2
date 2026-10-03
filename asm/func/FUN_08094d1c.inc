	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl FUN_08094cdc
	pop {r0}
	bx r0
