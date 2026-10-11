	movs r1, #0
	strh r1, [r0, #0x18]
	ldr r1, _0809FF40 @ =0x03000144
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_0809FF40: .4byte 0x03000144
