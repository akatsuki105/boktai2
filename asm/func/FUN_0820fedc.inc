	ldr r1, _0820FEE4 @ =0x085AF9AC
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0820FEE4: .4byte 0x085AF9AC
