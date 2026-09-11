	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08024500
	adds r0, r4, #0
	bl FUN_08025630
	adds r0, r4, #0
	bl FUN_08027588
	adds r0, r4, #0
	bl FUN_080245e4
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
