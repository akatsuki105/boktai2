	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #2]
	cmp r0, #0
	beq _08019B76
	movs r0, #0
	strb r0, [r2, #2]
	movs r0, #1
	b _08019B78
_08019B76:
	movs r0, #0
_08019B78:
	cmp r0, #0
	beq _08019B84
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
_08019B84:
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0
