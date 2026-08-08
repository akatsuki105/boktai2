	ldr r0, _080EDD9C @ =0x03002C60
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bx lr
	.align 2, 0
_080EDD9C: .4byte 0x03002C60
