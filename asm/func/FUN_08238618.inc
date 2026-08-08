	ldr r1, _08238620 @ =0x04000208
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_08238620: .4byte 0x04000208
