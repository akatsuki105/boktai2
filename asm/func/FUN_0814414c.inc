	ldr r1, _08144158 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _0814415C @ =0x085AD828
	str r1, [r0]
	bx lr
	.align 2, 0
_08144158: .4byte 0x00000634
_0814415C: .4byte 0x085AD828
