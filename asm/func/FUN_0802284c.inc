	movs r3, #8
	ldrsh r1, [r2, r3]
	str r1, [r0, #0x50]
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	str r1, [r0, #0x54]
	bx lr
	.align 2, 0
