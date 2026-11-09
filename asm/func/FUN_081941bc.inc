	ldr r1, _081941C8 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _081941CC @ =0x085ADD64
	str r1, [r0]
	bx lr
	.align 2, 0
_081941C8: .4byte 0x0000063C
_081941CC: .4byte 0x085ADD64
