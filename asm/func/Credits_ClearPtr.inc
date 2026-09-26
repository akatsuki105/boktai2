	ldr r1, _0804A600 @ =gCredits
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0804A600: .4byte gCredits
