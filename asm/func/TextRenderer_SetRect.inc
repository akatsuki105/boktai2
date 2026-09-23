	push {r4, lr}
	ldr r4, [sp, #8]
	strb r1, [r0, #2]
	strb r2, [r0, #3]
	strb r3, [r0, #4]
	strb r4, [r0, #5]
	strb r1, [r0]
	strb r2, [r0, #1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
