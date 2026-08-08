	ldr r1, _082417D8 @ =0x08DBD7A4
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_082417D8: .4byte 0x08DBD7A4
