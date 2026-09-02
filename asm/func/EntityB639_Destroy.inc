	ldr r0, _082415D0 @ =0x03001704
	movs r1, #0
	str r1, [r0]
	ldr r0, _082415D4 @ =0x03004860
	str r1, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
_082415D0: .4byte 0x03001704
_082415D4: .4byte 0x03004860
