	push {lr}
	movs r1, #0x80
	ldr r0, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08063F20
	movs r0, #0
	b _08063F22
_08063F20:
	movs r0, #0xa
_08063F22:
	pop {r1}
	bx r1
	.align 2, 0
