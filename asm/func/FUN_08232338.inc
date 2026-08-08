	push {lr}
	bl FUN_082322dc
	cmp r0, #0
	bne _08232346
	movs r0, #0
	b _0823234E
_08232346:
	movs r1, #0
	movs r2, #0
	bl FUN_08231ad0
_0823234E:
	pop {r1}
	bx r1
	.align 2, 0
