	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08009C3E
	movs r0, #0
	strb r0, [r2, #7]
	ldr r0, [r2, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x64]
_08009C3E:
	pop {r0}
	bx r0
	.align 2, 0
