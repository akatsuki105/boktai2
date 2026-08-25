	adds r3, r0, #0
	ldr r0, [r3, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x18]
	movs r0, #3
	movs r2, #0
	strh r0, [r3, #0x28]
	ldr r0, _080A8418 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	ldrh r0, [r3, #0x36]
	adds r0, #0xfa
	strh r0, [r3, #0x36]
	adds r0, r3, #0
	adds r0, #0x64
	strh r2, [r0]
	adds r1, r3, #0
	adds r1, #0x62
	movs r0, #1
	strh r0, [r1]
	subs r1, #2
	movs r0, #2
	strh r0, [r1]
	bx lr
	.align 2, 0
_080A8418: .4byte 0x03002BE0
