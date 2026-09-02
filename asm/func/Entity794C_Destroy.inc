	ldr r2, _08240E24 @ =0x03001700
	movs r1, #0
	str r1, [r2]
	bx lr
	.align 2, 0
_08240E24: .4byte 0x03001700
