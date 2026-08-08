	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _080FF068 @ =0x085AD488
	str r1, [r0]
	bx lr
	.align 2, 0
_080FF068: .4byte 0x085AD488
