	push {lr}
	bl Script_ExecByPointer
	pop {r1}
	bx r1
	.align 2, 0
