	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08136AE4 @ =0x00000B38
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	ldr r0, _08136AE8 @ =0x00000B34
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08136AE4: .4byte 0x00000B38
_08136AE8: .4byte 0x00000B34
