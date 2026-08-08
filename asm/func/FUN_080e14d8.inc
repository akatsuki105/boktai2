	ldr r1, _080E14E0 @ =0x03000180
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080E14E0: .4byte 0x03000180
