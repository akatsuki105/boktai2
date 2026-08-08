	ldr r1, _08231500 @ =gVM
	ldr r0, [r1, #8]
	subs r0, #4
	str r0, [r1, #8]
	bx lr
	.align 2, 0
_08231500: .4byte gVM
