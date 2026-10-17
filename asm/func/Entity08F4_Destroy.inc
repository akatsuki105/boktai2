	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081db310
	adds r0, r4, #0
	bl FUN_081db128
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
