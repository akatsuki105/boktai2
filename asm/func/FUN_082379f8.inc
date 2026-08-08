	ldr r1, _08237A00 @ =0x04000208
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_08237A00: .4byte 0x04000208
