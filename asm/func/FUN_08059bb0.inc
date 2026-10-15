	push {lr}
	movs r0, #5
	movs r1, #0
	strb r0, [r2, #2]
	movs r0, #1
	strb r0, [r2, #1]
	strh r1, [r2, #8]
	movs r0, #0xb8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0
