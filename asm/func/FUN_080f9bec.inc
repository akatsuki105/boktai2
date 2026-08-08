	ldr r1, _080F9BF4 @ =0x03000184
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080F9BF4: .4byte 0x03000184
