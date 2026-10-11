	mov ip, r0
	adds r0, #0xdc
	movs r3, #0
	strb r1, [r0]
	adds r0, #0x14
	str r2, [r0]
	subs r0, #4
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	bx lr
	.align 2, 0
