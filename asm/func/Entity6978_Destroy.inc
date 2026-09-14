	ldr r2, _080028DC @ =0x03002B30
	movs r1, #0
	str r1, [r2]
	bx lr
	.align 2, 0
_080028DC: .4byte 0x03002B30
