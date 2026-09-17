	ldr r1, _08013B54 @ =0x03000054
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08013B54: .4byte 0x03000054
