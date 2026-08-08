	push {lr}
	movs r1, #0xc6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl FUN_0820fea8
	pop {r0}
	bx r0
	.align 2, 0
