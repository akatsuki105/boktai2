	ldr r1, _080A953C @ =0x03002C50
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080A953C: .4byte 0x03002C50
