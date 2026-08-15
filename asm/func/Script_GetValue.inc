	push {lr}
	bl VM_GetPC
	bl VM_GetValueAt
	pop {r1}
	bx r1
	.align 2, 0
