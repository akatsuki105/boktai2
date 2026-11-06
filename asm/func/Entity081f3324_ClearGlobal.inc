	ldr r1, _081F3378 @ =0x030001F0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F3378: .4byte 0x030001F0
