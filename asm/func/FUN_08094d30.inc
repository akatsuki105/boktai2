	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	movs r0, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_08094cdc
	pop {r4, r5}
	pop {r0}
	bx r0
