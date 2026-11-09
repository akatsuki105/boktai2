	ldr r1, _0818E2B0 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _0818E2B4 @ =0x085ADCF4
	str r1, [r0]
	bx lr
	.align 2, 0
_0818E2B0: .4byte 0x00000634
_0818E2B4: .4byte 0x085ADCF4
