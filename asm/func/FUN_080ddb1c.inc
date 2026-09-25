	ldr r1, _080DDB24 @ =0x03000170
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DDB24: .4byte 0x03000170
