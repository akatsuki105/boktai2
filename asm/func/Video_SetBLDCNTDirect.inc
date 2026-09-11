	ldr r3, _0822CEC4 @ =0x04000050
	lsls r2, r2, #8
	orrs r2, r1
	lsls r0, r0, #6
	orrs r0, r2
	strh r0, [r3]
	bx lr
	.align 2, 0
_0822CEC4: .4byte 0x04000050
