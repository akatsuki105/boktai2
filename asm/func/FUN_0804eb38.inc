	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x19]
	cmp r0, #0
	beq _0804EB46
	movs r0, #0
	strb r0, [r1, #0x19]
_0804EB46:
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
	pop {r0}
	bx r0
