	movs r0, #0x80
	lsls r0, r0, #0x13
	ldr r1, _0822CEB0 @ =0x0300068C
	ldrh r1, [r1]
	strh r1, [r0]
	bx lr
	.align 2, 0
_0822CEB0: .4byte 0x0300068C
