	push {r4, lr}
	movs r4, #0xa5
	strb r1, [r4, r0]
	adds r1, r2, #0
	adds r2, r3, #0
	bl FUN_0821d824
	pop {r4}
	pop {r0}
	bx r0
