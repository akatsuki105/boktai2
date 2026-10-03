	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0804D388 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804D390
	cmp r1, #0x27
	bne _0804D38C
	bl rfu_REQ_changeMasterSlave
	bl rfu_waitREQComplete
	b _0804D390
	.align 2, 0
_0804D388: .4byte 0x03002B58
_0804D38C:
	bl rfu_REQ_recvData
_0804D390:
	pop {r0}
	bx r0
