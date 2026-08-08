	ldr r2, _08231798 @ =0x03000768
	ldr r1, [r2]
	str r1, [r0]
	str r0, [r2]
	movs r0, #0
	bx lr
	.align 2, 0
_08231798: .4byte 0x03000768
