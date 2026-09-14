	ldr r1, _080137F4 @ =0x03000050
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080137F4: .4byte 0x03000050
