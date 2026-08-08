	push {lr}
	adds r1, r0, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	beq _08210C5A
	cmp r0, #1
	bgt _08210C52
	cmp r0, #0
	beq _08210C5A
	b _08210C6C
_08210C52:
	cmp r0, #2
	beq _08210C5A
	cmp r0, #3
	bne _08210C6C
_08210C5A:
	ldr r0, [r1, #0x50]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1, #0x50]
	adds r1, #0xb0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_08210C6C:
	pop {r0}
	bx r0
