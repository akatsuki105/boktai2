	ldr r1, _081B3FAC @ =0x00000634
	adds r0, r0, r1
	ldr r1, _081B3FB0 @ =0x085ADF50
	str r1, [r0]
	bx lr
	.align 2, 0
_081B3FAC: .4byte 0x00000634
_081B3FB0: .4byte 0x085ADF50
