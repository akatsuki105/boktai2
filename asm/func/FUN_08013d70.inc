	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r1, #0x4c]
	ldr r2, [r1, #0x50]
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _08013D84
	movs r0, #1
	rsbs r0, r0, #0
	b _08013D98
_08013D84:
	cmp r3, #0
	beq _08013D8C
	str r2, [r3, #0x50]
	b _08013D8E
_08013D8C:
	str r2, [r4, #0x18]
_08013D8E:
	cmp r2, #0
	beq _08013D94
	str r3, [r2, #0x4c]
_08013D94:
	movs r0, #0
	strb r0, [r1, #2]
_08013D98:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
