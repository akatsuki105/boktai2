	ldr r1, _08063D90 @ =0x00000362
	adds r0, r0, r1
	ldrh r0, [r0]
	lsrs r0, r0, #3
	bx lr
	.align 2, 0
_08063D90: .4byte 0x00000362
