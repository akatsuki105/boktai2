	ldr r1, _0822D23C @ =0x040000D4
	str r0, [r1]
	ldr r0, _0822D240 @ =0x030043F0
	str r0, [r1, #4]
	ldr r0, _0822D244 @ =0x84000018
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.align 2, 0
_0822D23C: .4byte 0x040000D4
_0822D240: .4byte 0x030043F0
_0822D244: .4byte 0x84000018
