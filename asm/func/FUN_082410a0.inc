	push {r4, lr}
	bl FUN_08241044
	adds r4, r0, #0
	bl FUN_0824108c
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08231d5c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
