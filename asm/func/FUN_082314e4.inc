	ldr r2, _082314F0 @ =gVM
	ldr r1, [r2, #8]
	stm r1!, {r0}
	str r1, [r2, #8]
	bx lr
	.align 2, 0
_082314F0: .4byte gVM
