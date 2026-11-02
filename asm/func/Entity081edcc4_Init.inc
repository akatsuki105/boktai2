	ldr r1, _081EDCC0 @ =0x030001C8
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_081EDCC0: .4byte 0x030001C8
