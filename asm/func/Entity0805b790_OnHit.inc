	movs r0, #2
	movs r1, #0
	strb r0, [r2, #2]
	movs r0, #1
	strb r0, [r2, #1]
	strh r1, [r2, #4]
	bx lr
	.align 2, 0
