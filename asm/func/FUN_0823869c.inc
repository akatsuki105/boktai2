	ldr r3, _082386C8 @ =0x04000208
	movs r0, #0
	strh r0, [r3]
	ldr r2, _082386CC @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _082386D0 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, _082386D4 @ =0x03002CB0
	ldr r0, _082386D8 @ =IntrDummy
	str r0, [r1, #4]
	movs r0, #1
	strh r0, [r3]
	ldr r1, _082386DC @ =0x04000128
	ldr r2, _082386E0 @ =0x00002003
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0xda
	movs r0, #0x80
	strh r0, [r1]
	bx lr
	.align 2, 0
_082386C8: .4byte 0x04000208
_082386CC: .4byte 0x04000200
_082386D0: .4byte 0x0000FF7F
_082386D4: .4byte 0x03002CB0
_082386D8: .4byte IntrDummy
_082386DC: .4byte 0x04000128
_082386E0: .4byte 0x00002003
