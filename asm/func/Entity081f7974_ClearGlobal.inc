	ldr r1, _081F79C8 @ =0x03000200
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F79C8: .4byte 0x03000200
