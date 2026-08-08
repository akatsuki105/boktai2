	ldr r1, _0807264C @ =0x000004AA
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_0807264C: .4byte 0x000004AA
