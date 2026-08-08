	ldr r1, _082314E0 @ =gVM
	adds r0, r1, #0
	adds r0, #0xc
	str r0, [r1, #8]
	bx lr
	.align 2, 0
_082314E0: .4byte gVM
