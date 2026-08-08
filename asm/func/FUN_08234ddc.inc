	ldr r1, _08234DE4 @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #0x10]
	bx lr
	.align 2, 0
_08234DE4: .4byte 0x030046A4
