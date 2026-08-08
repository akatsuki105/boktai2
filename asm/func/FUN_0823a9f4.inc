	push {lr}
	bl FUN_0824082c
	ldr r2, _0823AA0C @ =0x030044BC
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0823AA0C: .4byte 0x030044BC
