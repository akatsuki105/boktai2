	ldr r1, _0822CE88 @ =0x04000048
	ldr r0, _0822CE8C @ =0x03000696
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0822CE90 @ =0x03000698
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.align 2, 0
_0822CE88: .4byte 0x04000048
_0822CE8C: .4byte 0x03000696
_0822CE90: .4byte 0x03000698
