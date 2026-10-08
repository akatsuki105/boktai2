	ldr r1, _080A0DF0 @ =0x03002C3C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080A0DF0: .4byte 0x03002C3C
