	ldr r1, _08234634 @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #0xc]
	ldr r1, _08234638 @ =0x0300077C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08234634: .4byte 0x030046A4
_08234638: .4byte 0x0300077C
