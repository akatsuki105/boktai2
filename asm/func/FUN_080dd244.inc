	ldr r1, _080DD24C @ =0x0300016C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DD24C: .4byte 0x0300016C
