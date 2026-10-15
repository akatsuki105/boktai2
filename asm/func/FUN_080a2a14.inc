	movs r3, #0xe1
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080A2A28 @ =0x00000382
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080A2A28: .4byte 0x00000382
