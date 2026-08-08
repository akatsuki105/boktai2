	ldr r1, _080DF474 @ =0x03000178
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DF474: .4byte 0x03000178
