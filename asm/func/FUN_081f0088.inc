	push {lr}
	bl Entity081f0298_AllocElem
	cmp r0, #0
	bne _081F0094
	movs r0, #0
_081F0094:
	pop {r1}
	bx r1
