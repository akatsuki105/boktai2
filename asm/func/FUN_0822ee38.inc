	ldr r1, _0822EE4C @ =0x030044A0
	movs r0, #2
	str r0, [r1]
	ldr r0, _0822EE50 @ =0x030044A8
	movs r1, #0
	str r1, [r0]
	ldr r0, _0822EE54 @ =0x030044A4
	str r1, [r0]
	bx lr
	.align 2, 0
_0822EE4C: .4byte 0x030044A0
_0822EE50: .4byte 0x030044A8
_0822EE54: .4byte 0x030044A4
