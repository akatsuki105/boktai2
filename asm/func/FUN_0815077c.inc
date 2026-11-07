	ldr r1, _08150788 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _0815078C @ =0x085AD8E8
	str r1, [r0]
	bx lr
	.align 2, 0
_08150788: .4byte 0x0000063C
_0815078C: .4byte 0x085AD8E8
