	adds r2, r0, #0
	ldr r1, [r2, #0x7c]
	ldr r0, _08011120 @ =0x6262C05D
	muls r0, r1, r0
	adds r0, #1
	str r0, [r2, #0x7c]
	bx lr
	.align 2, 0
_08011120: .4byte 0x6262C05D
