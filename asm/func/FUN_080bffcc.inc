	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080bfd04
	adds r0, r4, #0
	bl FUN_080bfef8
	adds r0, r4, #0
	bl FUN_080bff98
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
