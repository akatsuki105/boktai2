	ldr r2, _080F9C1C @ =0x0000021E
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	subs r3, #0x1e
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r0, r1
	str r2, [r0]
	bx lr
	.align 2, 0
_080F9C1C: .4byte 0x0000021E
