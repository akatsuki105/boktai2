	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0822CF70 @ =0x05000200
	adds r0, r0, r1
	strh r2, [r0]
	bx lr
	.align 2, 0
_0822CF70: .4byte 0x05000200
