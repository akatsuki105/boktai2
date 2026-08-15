	push {lr}
	bl FUN_0823baa8
	ldr r0, _0823BE0C @ =gCamera
	ldr r0, [r0]
	bl FUN_0823bd98
	pop {r0}
	bx r0
	.align 2, 0
_0823BE0C: .4byte gCamera
