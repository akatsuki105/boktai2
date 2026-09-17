	ldr r1, [r0, #0xc]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0xc]
	ldr r1, _080139B0 @ =nop_080139b4
	str r1, [r0, #0x60]
	bx lr
	.align 2, 0
_080139B0: .4byte nop_080139b4
