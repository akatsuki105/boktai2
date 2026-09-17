	push {lr}
	adds r3, r0, #0
	cmp r1, #0
	beq _08013CC8
	ldr r1, [r3, #0xc]
	movs r2, #2
	orrs r1, r2
	b _08013CD0
_08013CC8:
	ldr r1, [r3, #0xc]
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
_08013CD0:
	str r1, [r3, #0xc]
	pop {r1}
	bx r1
	.align 2, 0
