	ldr r1, _081EE7FC @ =0x030001D0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EE7FC: .4byte 0x030001D0
