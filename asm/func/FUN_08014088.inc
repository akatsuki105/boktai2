	ldr r1, _08014090 @ =0x03000058
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08014090: .4byte 0x03000058
