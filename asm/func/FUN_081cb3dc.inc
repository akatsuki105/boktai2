	push {r4, lr}
	adds r4, r0, #0
	bl DogLink_UpdateHitboxes
	adds r0, r4, #0
	bl FUN_081c6ba8
	adds r0, r4, #0
	bl FUN_081c6bd8
	adds r0, r4, #0
	bl FUN_081c74b4
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
