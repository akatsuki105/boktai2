	ldr r1, _081DC690 @ =0x030001A8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081DC690: .4byte 0x030001A8
