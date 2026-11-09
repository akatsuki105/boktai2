	lsls r3, r1, #3
	adds r3, r3, r1
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, _0813A268 @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0]
	str r2, [r0, #4]
	bx lr
	.align 2, 0
_0813A268: .4byte 0x00000674
