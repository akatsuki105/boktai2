	ldr r1, _08141454 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _08141458 @ =0x085AD804
	str r1, [r0]
	bx lr
	.align 2, 0
_08141454: .4byte 0x0000063C
_08141458: .4byte 0x085AD804
