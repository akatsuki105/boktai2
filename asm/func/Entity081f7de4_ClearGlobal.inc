	ldr r1, _081F7E38 @ =0x03000204
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F7E38: .4byte 0x03000204
