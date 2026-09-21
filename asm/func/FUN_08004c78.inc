	ldr r1, _08004C80 @ =0x03000024
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08004C80: .4byte 0x03000024
