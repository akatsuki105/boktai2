	ldr r1, _08236E9C @ =0x03000780
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08236E9C: .4byte 0x03000780
