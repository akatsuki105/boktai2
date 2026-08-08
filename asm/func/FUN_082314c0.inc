	ldr r2, _082314D0 @ =gVM
	lsls r0, r0, #2
	adds r0, #4
	ldr r2, [r2, #0x6c]
	subs r2, r2, r0
	str r1, [r2]
	bx lr
	.align 2, 0
_082314D0: .4byte gVM
