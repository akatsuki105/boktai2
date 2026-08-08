	ldr r1, _08241008 @ =0x03001700
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08241008: .4byte 0x03001700
