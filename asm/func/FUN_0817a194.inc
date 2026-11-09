	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08178d40
	adds r0, r4, #0
	bl FUN_08179c30
	adds r0, r4, #0
	bl FUN_08179f38
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
