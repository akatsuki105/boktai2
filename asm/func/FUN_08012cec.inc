	adds r2, r0, #0
	ldr r1, [r2, #0x24]
	ldr r0, _08012CFC @ =0x6262C05D
	muls r0, r1, r0
	adds r0, #1
	str r0, [r2, #0x24]
	bx lr
	.align 2, 0
_08012CFC: .4byte 0x6262C05D
