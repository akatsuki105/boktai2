	ldr r1, _08238408 @ =0x03000820
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08238408: .4byte 0x03000820
