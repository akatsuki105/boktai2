	push {r4, r5, r6, lr}
	ldr r5, [sp, #0x10]
	ldr r6, [sp, #0x14]
	movs r4, #0
	strh r1, [r0, #2]
	strh r4, [r0]
	lsls r2, r2, #4
	orrs r2, r3
	strb r2, [r0, #4]
	strb r5, [r0, #5]
	strh r6, [r0, #6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
