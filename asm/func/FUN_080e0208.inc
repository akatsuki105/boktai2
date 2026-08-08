	ldr r1, _080E0210 @ =0x0300017C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080E0210: .4byte 0x0300017C
