	movs r2, #0xe4
	lsls r2, r2, #2
	adds r3, r0, r2
	ldrh r2, [r3]
	bics r2, r1
	movs r1, #0
	strh r2, [r3]
	ldr r2, _0807A9B4 @ =0x00000392
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_0807A9B4: .4byte 0x00000392
