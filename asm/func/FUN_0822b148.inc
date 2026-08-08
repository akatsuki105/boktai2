	ldr r1, _0822B160 @ =0x030035A0
	str r0, [r1]
	ldr r2, _0822B164 @ =0x0300359C
	ldr r1, [r0, #0x14]
	adds r1, r0, r1
	str r1, [r2]
	ldr r2, _0822B168 @ =0x03003598
	ldr r1, [r0, #0xc]
	adds r0, r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0822B160: .4byte 0x030035A0
_0822B164: .4byte 0x0300359C
_0822B168: .4byte 0x03003598
