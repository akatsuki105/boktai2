	ldr r1, _081518B8 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _081518BC @ =0x085AD8F0
	str r1, [r0]
	bx lr
	.align 2, 0
_081518B8: .4byte 0x00000634
_081518BC: .4byte 0x085AD8F0
