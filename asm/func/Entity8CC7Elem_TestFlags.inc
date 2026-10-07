	push {lr}
	adds r0, #0x6e
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D8A34
	movs r0, #0
	b _081D8A36
_081D8A34:
	movs r0, #1
_081D8A36:
	pop {r1}
	bx r1
	.align 2, 0
