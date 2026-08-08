	ldr r1, _08231444 @ =gVM
	adds r0, r1, #0
	adds r0, #0x70
	str r0, [r1, #0x6c]
	bx lr
	.align 2, 0
_08231444: .4byte gVM
