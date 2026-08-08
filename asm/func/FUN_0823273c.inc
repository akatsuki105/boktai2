	ldr r0, _08232758 @ =0x030046A4
	ldr r1, [r0]
	ldr r2, [r1, #4]
	ldrh r0, [r2, #4]
	rsbs r0, r0, #0
	strh r0, [r1, #0x1c]
	movs r0, #1
	strh r0, [r1, #0x1e]
	ldrh r0, [r2, #4]
	strh r0, [r1, #0x20]
	ldr r0, _0823275C @ =0x0000FFFF
	strh r0, [r1, #0x22]
	bx lr
	.align 2, 0
_08232758: .4byte 0x030046A4
_0823275C: .4byte 0x0000FFFF
