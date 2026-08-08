	ldr r1, _082379F4 @ =0x04000208
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
_082379F4: .4byte 0x04000208
