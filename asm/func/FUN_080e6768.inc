	movs r2, #0xaa
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r3, _080E6790 @ =0x00000551
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	str r2, [r1]
	movs r1, #0xab
	lsls r1, r1, #3
	adds r0, r0, r1
	str r2, [r0]
	bx lr
	.align 2, 0
_080E6790: .4byte 0x00000551
