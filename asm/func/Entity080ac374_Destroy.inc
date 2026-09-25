	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ac21c
	adds r0, r4, #0
	bl FUN_080abfec
	pop {r4}
	pop {r1}
	bx r1
