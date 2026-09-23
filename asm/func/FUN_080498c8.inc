	ldr r1, _080498D0 @ =0x030000C8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080498D0: .4byte 0x030000C8
