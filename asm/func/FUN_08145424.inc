	ldr r1, _08145430 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _08145434 @ =0x085AD84C
	str r1, [r0]
	bx lr
	.align 2, 0
_08145430: .4byte 0x0000063C
_08145434: .4byte 0x085AD84C
