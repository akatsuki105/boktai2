	push {lr}
	ldr r0, _0804DBDC @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DBD6
	bl rfu_REQ_recvData
_0804DBD6:
	pop {r0}
	bx r0
	.align 2, 0
_0804DBDC: .4byte 0x03002B58
