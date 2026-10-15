	movs r0, #4
	movs r1, #0
	strb r0, [r2, #1]
	movs r0, #1
	strb r0, [r2]
	strh r1, [r2, #6]
	bx lr
	.align 2, 0
