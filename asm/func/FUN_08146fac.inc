	ldr r1, _08146FB8 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08146FBC @ =0x085AD874
	str r1, [r0]
	bx lr
	.align 2, 0
_08146FB8: .4byte 0x00000634
_08146FBC: .4byte 0x085AD874
