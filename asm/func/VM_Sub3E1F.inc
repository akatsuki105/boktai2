	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Entity08004fac_FreeNodesById
	pop {r1}
	bx r1
	.align 2, 0
