	push {lr}
	movs r2, #8
	ldr r0, [r1, #0x38]
	ands r0, r2
	cmp r0, #0
	bne _08063FB0
	movs r0, #0
	b _08063FB2
_08063FB0:
	movs r0, #0xa
_08063FB2:
	pop {r1}
	bx r1
	.align 2, 0
