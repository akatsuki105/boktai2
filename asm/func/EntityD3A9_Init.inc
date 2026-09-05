	push {lr}
	adds r0, #0x1c
	movs r2, #8
	bl FUN_080223f4
	movs r0, #0
	pop {r1}
	bx r1
