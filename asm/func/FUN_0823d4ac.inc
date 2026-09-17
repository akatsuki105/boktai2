	push {lr}
	ldr r2, _0823D4C0 @ =gSentinel02020400
	ldr r0, [r2]
	ldr r1, _0823D4C4 @ =0x516B92EE
	cmp r0, r1
	beq _0823D4BA
	str r1, [r2]
_0823D4BA:
	pop {r0}
	bx r0
	.align 2, 0
_0823D4C0: .4byte gSentinel02020400
_0823D4C4: .4byte 0x516B92EE
