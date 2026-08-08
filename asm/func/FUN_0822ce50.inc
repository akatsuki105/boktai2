	ldr r1, _0822CE64 @ =0x03000696
	ldr r0, _0822CE68 @ =0x04000048
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0822CE6C @ =0x03000698
	ldr r0, _0822CE70 @ =0x0400004A
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.align 2, 0
_0822CE64: .4byte 0x03000696
_0822CE68: .4byte 0x04000048
_0822CE6C: .4byte 0x03000698
_0822CE70: .4byte 0x0400004A
