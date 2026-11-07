	ldr r1, _08140020 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08140024 @ =0x085AD7D0
	str r1, [r0]
	bx lr
	.align 2, 0
_08140020: .4byte 0x00000634
_08140024: .4byte 0x085AD7D0
