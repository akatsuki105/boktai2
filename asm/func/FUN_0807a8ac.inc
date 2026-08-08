	ldr r1, _0807A8BC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0807A8BC: .4byte 0x030046A0
