	ldr r2, _0803CEC8 @ =0x00000169
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r3, _0803CECC @ =0x000002B6
	adds r1, r0, r3
	strb r2, [r1]
	subs r3, #0xa
	adds r1, r0, r3
	strh r2, [r1]
	ldr r3, _0803CED0 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0803CED4 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0803CED8 @ =0x0203B400
	adds r1, r1, r2
	ldrh r2, [r1]
	ldr r1, _0803CEDC @ =0x03002CF0
	ldr r1, [r1]
	adds r1, r1, r2
	movs r2, #3
	ands r1, r2
	ldr r3, _0803CEE0 @ =0x000002B7
	adds r0, r0, r3
	strb r1, [r0]
	bx lr
	.align 2, 0
_0803CEC8: .4byte 0x00000169
_0803CECC: .4byte 0x000002B6
_0803CED0: .4byte 0x030046B8
_0803CED4: .4byte 0x000003FF
_0803CED8: .4byte 0x0203B400
_0803CEDC: .4byte 0x03002CF0
_0803CEE0: .4byte 0x000002B7
