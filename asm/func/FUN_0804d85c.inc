	push {lr}
	bl rfu_REQ_recvData
	pop {r0}
	bx r0
	.align 2, 0
