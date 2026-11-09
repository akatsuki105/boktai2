	ldr r1, _081355B8 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _081355BC @ =0x085AD72C
	str r1, [r0]
	bx lr
	.align 2, 0
_081355B8: .4byte 0x00000634
_081355BC: .4byte 0x085AD72C
