	push {lr}
	ldr r1, [r0, #0xc]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #0xc]
	ldr r1, _080136B0 @ =FUN_080136cc
	str r1, [r0, #0x34]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080136B0: .4byte FUN_080136cc
