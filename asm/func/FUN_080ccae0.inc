	adds r1, r0, #0
	adds r1, #0xc2
	ldrh r2, [r1]
	ldr r3, _080CCB14 @ =0x000006DE
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _080CCB18 @ =0x000006E4
	adds r2, r0, r1
	adds r1, r0, #0
	adds r1, #0xd0
	ldr r1, [r1]
	str r1, [r2]
	ldr r1, _080CCB1C @ =0x000006AC
	adds r3, r0, r1
	ldr r1, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r3]
	movs r3, #0xe2
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_080CCB14: .4byte 0x000006DE
_080CCB18: .4byte 0x000006E4
_080CCB1C: .4byte 0x000006AC
