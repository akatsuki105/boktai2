	ldr r0, _08063D10 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08063D14 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08063D10: .4byte 0x030046A0
_08063D14: .4byte 0x00000942
