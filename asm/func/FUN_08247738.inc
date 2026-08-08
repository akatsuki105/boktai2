	push {lr}
	ldr r1, _08247750 @ =0x030057B4
	movs r0, #0
	str r0, [r1]
	ldr r1, _08247754 @ =0x030026C4
	movs r0, #1
	str r0, [r1]
	bl FUN_08247538
	pop {r0}
	bx r0
	.align 2, 0
_08247750: .4byte 0x030057B4
_08247754: .4byte 0x030026C4
