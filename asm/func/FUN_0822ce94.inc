	ldr r0, _0822CEA0 @ =0x0300068C
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r1, [r1]
	strh r1, [r0]
	bx lr
	.align 2, 0
_0822CEA0: .4byte 0x0300068C
