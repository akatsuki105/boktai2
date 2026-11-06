	push {lr}
	bl Entity081f3324_AllocElem
	cmp r0, #0
	bne _081F310C
	movs r0, #0
_081F310C:
	pop {r1}
	bx r1
