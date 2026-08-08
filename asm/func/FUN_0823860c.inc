	ldr r1, _08238614 @ =0x04000208
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
_08238614: .4byte 0x04000208
