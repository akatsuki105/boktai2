	ldr r1, _081EEED4 @ =0x030001D8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EEED4: .4byte 0x030001D8
