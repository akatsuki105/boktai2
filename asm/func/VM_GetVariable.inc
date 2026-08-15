	ldr r1, _082314BC @ =gVM
	lsls r0, r0, #2
	adds r0, #4
	ldr r1, [r1, #0x6c]
	subs r1, r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
_082314BC: .4byte gVM
