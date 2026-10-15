	ldr r1, _080ACC1C @ =0x03002C54
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080ACC1C: .4byte 0x03002C54
