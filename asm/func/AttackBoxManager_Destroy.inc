	ldr r1, _080DDAB0 @ =0x03000170
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DDAB0: .4byte 0x03000170
