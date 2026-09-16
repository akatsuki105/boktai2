	ldr r1, [r0, #0xc]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0xc]
	ldr r1, _080136C4 @ =FUN_080136c8
	str r1, [r0, #0x34]
	bx lr
	.align 2, 0
_080136C4: .4byte FUN_080136c8
