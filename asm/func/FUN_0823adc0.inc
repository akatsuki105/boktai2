	push {lr}
	bl VM_GetPC
	bl FUN_082321e0
	pop {r1}
	bx r1
	.align 2, 0
