	ldr r1, _0819DD08 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _0819DD0C @ =0x085ADDB8
	str r1, [r0]
	bx lr
	.align 2, 0
_0819DD08: .4byte 0x00000634
_0819DD0C: .4byte 0x085ADDB8
