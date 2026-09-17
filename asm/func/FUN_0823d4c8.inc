	push {lr}
	ldr r0, _0823D4D8 @ =gSentinel02020400
	ldr r1, [r0]
	ldr r0, _0823D4DC @ =0x516B92EE
	cmp r1, r0
	beq _0823D4E0
	movs r0, #0
	b _0823D4E2
	.align 2, 0
_0823D4D8: .4byte gSentinel02020400
_0823D4DC: .4byte 0x516B92EE
_0823D4E0:
	movs r0, #1
_0823D4E2:
	pop {r1}
	bx r1
	.align 2, 0
