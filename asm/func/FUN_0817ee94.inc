	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0817da34
	adds r0, r4, #0
	bl FUN_0817da80
	adds r0, r4, #0
	bl FUN_0817deb8
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
