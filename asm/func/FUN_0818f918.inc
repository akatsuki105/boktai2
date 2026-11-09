	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _0818F934 @ =0x00000F34
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	movs r0, #0xf3
	lsls r0, r0, #4
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0818F934: .4byte 0x00000F34
