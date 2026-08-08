	ldr r1, _082417E8 @ =0x08DBD7BA
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_082417E8: .4byte 0x08DBD7BA
