	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r0, _0819FD08 @ =0x00000A7C
	adds r2, r2, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	bx lr
	.align 2, 0
_0819FD08: .4byte 0x00000A7C
