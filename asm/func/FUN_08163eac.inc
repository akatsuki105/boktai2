	ldr r1, _08163EB8 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08163EBC @ =0x085AD9C8
	str r1, [r0]
	bx lr
	.align 2, 0
_08163EB8: .4byte 0x00000634
_08163EBC: .4byte 0x085AD9C8
