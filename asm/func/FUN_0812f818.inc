	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08130460
	adds r0, r4, #0
	bl FUN_08130610
	adds r0, r4, #0
	bl FUN_0813069c
	adds r0, r4, #0
	bl FUN_080e8614
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
