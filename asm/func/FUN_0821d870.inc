	push {r4, r5, lr}
	adds r5, r3, #0
	ldr r3, [sp, #0xc]
	adds r4, r0, #0
	adds r4, #0xa4
	strb r1, [r4]
	adds r1, r2, #0
	adds r2, r5, #0
	bl FUN_0821d85c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
