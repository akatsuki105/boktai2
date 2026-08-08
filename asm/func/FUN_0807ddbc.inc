	push {lr}
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r2, r0, r1
	ldrh r1, [r0, #0x24]
	adds r0, r2, #0
	movs r2, #2
	bl FUN_080223f4
	pop {r0}
	bx r0
	.align 2, 0
