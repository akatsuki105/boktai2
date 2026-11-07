	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _08163BB8 @ =0x085AD9C4
	str r1, [r0]
	bx lr
	.align 2, 0
_08163BB8: .4byte 0x085AD9C4
