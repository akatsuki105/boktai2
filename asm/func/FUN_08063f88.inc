	push {lr}
	movs r2, #4
	ldr r0, [r1, #0x38]
	ands r0, r2
	cmp r0, #0
	bne _08063F98
	movs r0, #0
	b _08063F9A
_08063F98:
	movs r0, #0xa
_08063F9A:
	pop {r1}
	bx r1
	.align 2, 0
