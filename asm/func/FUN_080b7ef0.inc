	ldr r2, _080B7F18 @ =0x0000142E
	adds r1, r0, r2
	adds r2, #0x2a
	adds r0, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _080B7F1C @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080B7F18: .4byte 0x0000142E
_080B7F1C: .4byte 0x030046A0
