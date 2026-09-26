	movs r3, #0xc9
	lsls r3, r3, #2
	adds r2, r0, r3
	movs r3, #0
	strb r1, [r2]
	ldr r1, _08211BC0 @ =0x00000322
	adds r0, r0, r1
	strh r3, [r0]
	bx lr
	.align 2, 0
_08211BC0: .4byte 0x00000322
