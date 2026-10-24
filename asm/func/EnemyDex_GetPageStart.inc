	ldr r1, _0820CBE8 @ =0x085AF034
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0820CBE8: .4byte 0x085AF034
