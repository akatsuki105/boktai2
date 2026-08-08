	ldr r1, _08222CDC @ =0x03000248
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08222CDC: .4byte 0x03000248
