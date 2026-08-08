	ldr r1, _08072684 @ =0x000004AA
	adds r2, r0, r1
	movs r1, #2
	strb r1, [r2]
	ldr r1, _08072688 @ =0x000004AB
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08072684: .4byte 0x000004AA
_08072688: .4byte 0x000004AB
