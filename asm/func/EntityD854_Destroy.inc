	ldr r2, _080F9B7C @ =0x03000184
	movs r1, #0
	str r1, [r2]
	bx lr
	.align 2, 0
_080F9B7C: .4byte 0x03000184
