	ldr r2, _0822A338 @ =0x03003568
	ldr r1, _0822A33C @ =0x03003530
	ldr r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_0822A338: .4byte 0x03003568
_0822A33C: .4byte 0x03003530
