	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r3, [r0]
	ldr r2, _0817E028 @ =0x000007A4
	adds r0, r3, r2
	adds r0, r0, r1
	movs r2, #0xff
	strb r2, [r0]
	lsls r1, r1, #1
	movs r0, #0xf5
	lsls r0, r0, #3
	adds r3, r3, r0
	adds r3, r3, r1
	movs r0, #0
	strh r0, [r3]
	bx lr
	.align 2, 0
_0817E028: .4byte 0x000007A4
