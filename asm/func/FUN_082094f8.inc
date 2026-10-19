	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_082091f0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
