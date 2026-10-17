	ldr r1, _08002740 @ =0x03002B30
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08002740: .4byte 0x03002B30
