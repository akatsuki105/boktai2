	ldr r1, _080DC4A0 @ =0x03000168
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DC4A0: .4byte 0x03000168
