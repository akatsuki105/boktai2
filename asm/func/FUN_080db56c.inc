	ldr r1, _080DB574 @ =0x03000160
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DB574: .4byte 0x03000160
