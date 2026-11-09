	ldr r1, _08138C60 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _08138C64 @ =0x085AD76C
	str r1, [r0]
	bx lr
	.align 2, 0
_08138C60: .4byte 0x0000063C
_08138C64: .4byte 0x085AD76C
