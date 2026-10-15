	ldr r1, _08019AF0 @ =0x03000090
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08019AF0: .4byte 0x03000090
