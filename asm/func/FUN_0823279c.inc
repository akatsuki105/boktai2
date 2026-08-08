	ldr r1, _082327B4 @ =0x030046A8
	ldr r0, _082327B8 @ =0x030046A4
	ldr r0, [r0]
	ldr r2, [r0, #4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	str r0, [r1]
	ldr r1, _082327BC @ =0x030046AC
	movs r3, #6
	ldrsh r0, [r2, r3]
	str r0, [r1]
	bx lr
	.align 2, 0
_082327B4: .4byte 0x030046A8
_082327B8: .4byte 0x030046A4
_082327BC: .4byte 0x030046AC
