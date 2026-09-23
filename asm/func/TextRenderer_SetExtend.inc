	push {r4, lr}
	adds r3, r0, #0
	lsls r1, r1, #2
	movs r4, #0x86
	lsls r4, r4, #1
	adds r3, r3, r4
	adds r3, r3, r1
	str r2, [r3]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
