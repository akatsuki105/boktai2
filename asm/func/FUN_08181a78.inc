	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _08181A84 @ =0x085ADB8C
	str r1, [r0]
	bx lr
	.align 2, 0
_08181A84: .4byte 0x085ADB8C
