	movs r2, #0xd8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
	strh r2, [r1]
	ldr r3, _081DBC58 @ =0x00000362
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0x3a
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	movs r1, #0x3b
	strh r1, [r2]
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0x3c
	strh r1, [r2]
	ldr r2, _081DBC5C @ =0x0000036E
	adds r0, r0, r2
	movs r1, #0x3d
	strh r1, [r0]
	bx lr
	.align 2, 0
_081DBC58: .4byte 0x00000362
_081DBC5C: .4byte 0x0000036E
