	ldr r1, _081F45A8 @ =0x030001F4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F45A8: .4byte 0x030001F4
