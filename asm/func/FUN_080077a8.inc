	push {lr}
	movs r0, #0x74
	movs r1, #0
	bl VM_GetNamedArgValue
	bl FUN_08007770
	pop {r1}
	bx r1
	.align 2, 0
