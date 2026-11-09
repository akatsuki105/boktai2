	ldr r1, _08183374 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08183378 @ =0x085ADBA4
	str r1, [r0]
	bx lr
	.align 2, 0
_08183374: .4byte 0x00000634
_08183378: .4byte 0x085ADBA4
