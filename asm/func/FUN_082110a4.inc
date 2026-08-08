	ldr r1, _082110B8 @ =0x00000D89
	adds r2, r0, r1
	movs r1, #0
	strb r1, [r2]
	ldr r1, _082110BC @ =0x00000D88
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_082110B8: .4byte 0x00000D89
_082110BC: .4byte 0x00000D88
