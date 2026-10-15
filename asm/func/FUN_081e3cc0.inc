	movs r2, #0x80
	lsls r2, r2, #0xf
	ldr r1, _081E3CD0 @ =0x00001610
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_081E3CD0: .4byte 0x00001610
