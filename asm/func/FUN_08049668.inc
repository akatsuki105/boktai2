	movs r1, #0
	strb r1, [r0, #8]
	ldr r1, _08049678 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x12
	ldrsh r1, [r1, r2]
	strb r1, [r0, #9]
	bx lr
	.align 2, 0
_08049678: .4byte 0x030046A0
