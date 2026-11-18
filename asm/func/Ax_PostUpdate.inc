	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0819f894
	adds r0, r4, #0
	bl Ax_TickAfterimages
	adds r0, r4, #0
	bl FUN_0819ec50
	adds r0, r4, #0
	bl FUN_0819ffc4
	adds r0, r4, #0
	bl FUN_0819e5f4
	adds r0, r4, #0
	bl FUN_081a0248
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
