	ldr r2, _0822A320 @ =0x03003570
	ldr r1, _0822A324 @ =0x03003530
	ldr r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_0822A320: .4byte 0x03003570
_0822A324: .4byte 0x03003530
