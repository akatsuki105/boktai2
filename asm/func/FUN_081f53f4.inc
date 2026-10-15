	ldr r1, _081F53FC @ =0x030001F8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F53FC: .4byte 0x030001F8
