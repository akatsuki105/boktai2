	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r3, [r1, #0x60]
	movs r4, #1
	orrs r3, r4
	str r3, [r1, #0x60]
	lsls r4, r2
	ldr r1, [r5, #0x18]
	bics r1, r4
	str r1, [r5, #0x18]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
