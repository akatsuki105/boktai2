	ldr r1, _081E9D00 @ =0x030001B4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081E9D00: .4byte 0x030001B4
