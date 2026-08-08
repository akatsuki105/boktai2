	ldr r1, _08063DAC @ =0x0000035E
	adds r0, r0, r1
	ldrh r0, [r0]
	lsrs r0, r0, #3
	bx lr
	.align 2, 0
_08063DAC: .4byte 0x0000035E
