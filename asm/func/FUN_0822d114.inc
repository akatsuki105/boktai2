	ldr r2, _0822D124 @ =0x03004044
	ldr r1, _0822D128 @ =0x03004450
	ldr r0, [r1]
	adds r0, #2
	str r0, [r2]
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0822D124: .4byte 0x03004044
_0822D128: .4byte 0x03004450
