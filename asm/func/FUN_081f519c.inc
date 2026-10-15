	push {lr}
	bl FUN_081f5138
	cmp r0, #0
	bne _081F51A8
	movs r0, #0
_081F51A8:
	pop {r1}
	bx r1
