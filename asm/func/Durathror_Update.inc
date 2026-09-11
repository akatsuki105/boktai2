	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080390f8
	adds r0, r4, #0
	bl FUN_0803a104
	adds r0, r4, #0
	bl FUN_0803b7c4
	adds r0, r4, #0
	bl FUN_08039280
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
