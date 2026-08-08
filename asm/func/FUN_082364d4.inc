	push {r4, r5, lr}
	ldr r4, [r1]
	ldr r5, [r1, #4]
	str r4, [r0, #0xc]
	str r5, [r0, #0x10]
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0, #0x14]
	str r2, [r0, #0x18]
	strh r3, [r0, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
