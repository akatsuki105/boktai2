	ldr r1, _0817A18C @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _0817A190 @ =0x085ADB4C
	str r1, [r0]
	bx lr
	.align 2, 0
_0817A18C: .4byte 0x0000063C
_0817A190: .4byte 0x085ADB4C
