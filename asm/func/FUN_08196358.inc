	movs r2, #0
	strh r2, [r0, #0x1c]
	strh r2, [r0, #0x1e]
	strh r2, [r0, #0x20]
	strh r2, [r0, #0x24]
	movs r1, #1
	strh r1, [r0, #0x26]
	strh r2, [r0, #0x28]
	ldr r1, _08196374 @ =0x00000C68
	adds r0, r0, r1
	movs r1, #0x14
	str r1, [r0]
	bx lr
	.align 2, 0
_08196374: .4byte 0x00000C68
