	ldr r1, _08175684 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08175688 @ =0x085ADAE4
	str r1, [r0]
	bx lr
	.align 2, 0
_08175684: .4byte 0x00000634
_08175688: .4byte 0x085ADAE4
