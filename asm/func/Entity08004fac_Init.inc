	ldr r1, _08004FA8 @ =0x03000024
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x18]
	movs r0, #0
	bx lr
	.align 2, 0
_08004FA8: .4byte 0x03000024
