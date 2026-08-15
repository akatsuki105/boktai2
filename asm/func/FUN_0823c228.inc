	push {lr}
	ldrh r1, [r0, #0x1e]
	cmp r1, #1
	bne _0823C236
	bl FUN_0823c1f8
	b _0823C23E
_0823C236:
	cmp r1, #2
	bne _0823C23E
	bl FUN_0823c0ac
_0823C23E:
	pop {r0}
	bx r0
	.align 2, 0
