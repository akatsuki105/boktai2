	push {lr}
	ldr r1, [r0, #0xc]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #0xc]
	ldr r1, _0801399C @ =FUN_080139b8
	str r1, [r0, #0x60]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0801399C: .4byte FUN_080139b8
