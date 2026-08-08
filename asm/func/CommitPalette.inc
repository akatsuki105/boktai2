	ldr r1, _0822D218 @ =0x040000D4
	ldr r0, _0822D21C @ =0x03004468
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r2, _0822D220 @ =0x84000080
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0822D224 @ =gObjectPlttBuffer
	str r0, [r1]
	ldr r0, _0822D228 @ =0x05000200
	str r0, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.align 2, 0
_0822D218: .4byte 0x040000D4
_0822D21C: .4byte 0x03004468
_0822D220: .4byte 0x84000080
_0822D224: .4byte gObjectPlttBuffer
_0822D228: .4byte 0x05000200
