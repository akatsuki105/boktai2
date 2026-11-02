	ldr r1, _081F0BE4 @ =0x030001E4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F0BE4: .4byte 0x030001E4
