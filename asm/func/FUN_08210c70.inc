	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08210ab0
	adds r0, r4, #0
	bl FUN_08210c3c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
