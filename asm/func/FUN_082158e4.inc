	ldr r1, _082158F8 @ =0x00000DBC
	adds r2, r0, r1
	adds r1, #0xc0
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	strh r0, [r2, #0x22]
	bx lr
	.align 2, 0
_082158F8: .4byte 0x00000DBC
