	push {lr}
	cmp r1, #0
	beq _0822A570
	str r1, [r0, #0xc]
_0822A570:
	pop {r0}
	bx r0
