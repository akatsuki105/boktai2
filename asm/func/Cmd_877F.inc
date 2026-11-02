	ldr r0, _08050E28 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #5
	orrs r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_08050E28: .4byte 0x030047A4
