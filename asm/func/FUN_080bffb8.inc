	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080bfce4
	adds r0, r4, #0
	bl FUN_080bff78
	pop {r4}
	pop {r0}
	bx r0
