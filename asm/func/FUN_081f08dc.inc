	push {lr}
	bl Entity081f0b90_AllocElem
	cmp r0, #0
	bne _081F08E8
	movs r0, #0
_081F08E8:
	pop {r1}
	bx r1
