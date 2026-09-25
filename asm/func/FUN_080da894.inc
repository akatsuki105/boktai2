	ldr r1, _080DA89C @ =0x0300015C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DA89C: .4byte 0x0300015C
