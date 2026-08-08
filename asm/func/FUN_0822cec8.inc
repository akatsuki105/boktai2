	ldr r2, _0822CED4 @ =0x04000052
	lsls r1, r1, #8
	orrs r1, r0
	strh r1, [r2]
	bx lr
	.align 2, 0
_0822CED4: .4byte 0x04000052
