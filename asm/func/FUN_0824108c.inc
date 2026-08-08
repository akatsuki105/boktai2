	push {r4, lr}
	bl FUN_08241044
	adds r4, r0, #0
	bl FUN_08241054
	subs r0, r0, r4
	pop {r4}
	pop {r1}
	bx r1
