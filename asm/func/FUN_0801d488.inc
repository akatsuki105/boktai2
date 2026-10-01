	ldr r1, _0801D4A0 @ =0x00000EC4
	adds r3, r0, r1
	ldr r1, [r3, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r3, #8]
	ldr r1, _0801D4A4 @ =0x00000F24
	adds r3, r0, r1
	ldr r0, [r3, #8]
	orrs r0, r2
	str r0, [r3, #8]
	bx lr
	.align 2, 0
_0801D4A0: .4byte 0x00000EC4
_0801D4A4: .4byte 0x00000F24
