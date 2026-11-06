	push {lr}
	bl Entity081f73ec_AllocElem_Internal
	cmp r0, #0
	bne _081F7244
	movs r0, #0
_081F7244:
	pop {r1}
	bx r1
