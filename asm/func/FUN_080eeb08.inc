	ldr r1, _080EEB10 @ =0x03002C5C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080EEB10: .4byte 0x03002C5C
