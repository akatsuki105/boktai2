	push {lr}
	bl FUN_08060e1c
	cmp r0, #0
	bne _08063D7E
	movs r0, #0
	b _08063D80
_08063D7E:
	movs r0, #0xa
_08063D80:
	pop {r1}
	bx r1
