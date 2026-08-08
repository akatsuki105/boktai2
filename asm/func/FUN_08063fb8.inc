	push {lr}
	movs r2, #0x10
	ldr r0, [r1, #0x38]
	ands r0, r2
	cmp r0, #0
	bne _08063FC8
	movs r0, #0
	b _08063FCA
_08063FC8:
	movs r0, #0xa
_08063FCA:
	pop {r1}
	bx r1
	.align 2, 0
