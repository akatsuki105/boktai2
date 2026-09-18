	ldr r0, _0823CD20 @ =0x030047A4
	movs r1, #0
	str r1, [r0]
	ldr r0, _0823CD24 @ =0x030047A0
	str r1, [r0]
	ldr r0, _0823CD28 @ =0x0300479C
	str r1, [r0]
	ldr r0, _0823CD2C @ =0x030047C0
	str r1, [r0]
	ldr r0, _0823CD30 @ =0x0300478C
	str r1, [r0]
	ldr r0, _0823CD34 @ =0x030047C4
	str r1, [r0]
	bx lr
	.align 2, 0
_0823CD20: .4byte 0x030047A4
_0823CD24: .4byte 0x030047A0
_0823CD28: .4byte 0x0300479C
_0823CD2C: .4byte 0x030047C0
_0823CD30: .4byte 0x0300478C
_0823CD34: .4byte 0x030047C4
