	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _081A17C0 @ =0x085ADE08
	str r1, [r0]
	bx lr
	.align 2, 0
_081A17C0: .4byte 0x085ADE08
