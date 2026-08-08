	ldr r2, _082239B4 @ =0x00000F42
	adds r1, r0, r2
	ldrb r2, [r1]
	ldr r3, _082239B8 @ =0x00000DEC
	adds r1, r0, r3
	strh r2, [r1]
	ldr r2, _082239BC @ =0x00000F43
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r3, #6
	adds r0, r0, r3
	strh r1, [r0]
	bx lr
	.align 2, 0
_082239B4: .4byte 0x00000F42
_082239B8: .4byte 0x00000DEC
_082239BC: .4byte 0x00000F43
