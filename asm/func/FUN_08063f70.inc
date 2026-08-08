	push {lr}
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08063F82
	movs r0, #0
	b _08063F84
_08063F82:
	movs r0, #0xa
_08063F84:
	pop {r1}
	bx r1
