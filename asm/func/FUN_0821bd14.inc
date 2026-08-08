	adds r3, r0, #0
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2, #8]
	ldr r1, _0821BD38 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r2, #8]
	movs r2, #0x80
	lsls r2, r2, #1
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_0821BD38: .4byte 0xFFFFFDFF
