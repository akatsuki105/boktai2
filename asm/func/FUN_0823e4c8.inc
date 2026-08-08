	ldr r0, _0823E4D0 @ =gClock
	ldrh r0, [r0, #0x14]
	bx lr
	.align 2, 0
_0823E4D0: .4byte gClock
