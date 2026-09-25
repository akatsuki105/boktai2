	ldr r1, _080DBEAC @ =0x03000164
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DBEAC: .4byte 0x03000164
