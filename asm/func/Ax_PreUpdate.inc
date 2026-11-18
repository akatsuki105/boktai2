	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0819dd10
	adds r0, r4, #0
	bl Ax_UpdateChaseTimeout
	adds r0, r4, #0
	bl FUN_0819e88c
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
