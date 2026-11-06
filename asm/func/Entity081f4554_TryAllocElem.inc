	push {lr}
	bl Entity081f4554_AllocElem
	cmp r0, #0
	bne _081F42C8
	movs r0, #0
_081F42C8:
	pop {r1}
	bx r1
