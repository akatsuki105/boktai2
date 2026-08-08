	ldr r1, _08235920 @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #0x14]
	bx lr
	.align 2, 0
_08235920: .4byte 0x030046A4
