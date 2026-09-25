	push {lr}
	bl FUN_080d9974
	cmp r0, #0
	bne _080D99D0
	movs r0, #0
_080D99D0:
	pop {r1}
	bx r1
