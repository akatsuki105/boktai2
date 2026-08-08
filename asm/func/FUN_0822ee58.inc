	ldr r3, _0822EE68 @ =0x030044A0
	str r0, [r3]
	ldr r0, _0822EE6C @ =0x030044A8
	str r1, [r0]
	ldr r0, _0822EE70 @ =0x030044A4
	str r2, [r0]
	bx lr
	.align 2, 0
_0822EE68: .4byte 0x030044A0
_0822EE6C: .4byte 0x030044A8
_0822EE70: .4byte 0x030044A4
