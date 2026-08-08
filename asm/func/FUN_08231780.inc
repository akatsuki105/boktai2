	ldr r1, _08231788 @ =0x03000768
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08231788: .4byte 0x03000768
