	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08190f34
	adds r0, r4, #0
	bl FUN_08192774
	adds r0, r4, #0
	bl FUN_08192a14
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
