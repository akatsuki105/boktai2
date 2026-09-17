	ldr r1, _08013B64 @ =0x03000054
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x1c]
	movs r0, #0
	bx lr
	.align 2, 0
_08013B64: .4byte 0x03000054
