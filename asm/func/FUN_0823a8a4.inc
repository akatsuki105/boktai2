	push {lr}
	bl Script_ExecById
	pop {r1}
	bx r1
	.align 2, 0
