	lsls r3, r1, #3
	adds r3, r3, r1
	lsls r3, r3, #3
	adds r3, r3, r1
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r1, _0818F860 @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0]
	str r2, [r0, #4]
	bx lr
	.align 2, 0
_0818F860: .4byte 0x00000674
