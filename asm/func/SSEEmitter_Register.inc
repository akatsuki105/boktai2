	push {r4, lr}
	adds r3, r0, #0
	ldrb r2, [r1]
	cmp r2, #0
	beq _08246680
	movs r0, #1
	rsbs r0, r0, #0
	b _082466A2
_08246680:
	movs r4, #0x98
	lsls r4, r4, #1
	adds r0, r1, r4
	str r2, [r0]
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r2, [r3, #0x20]
	str r2, [r0]
	cmp r2, #0
	beq _0824669A
	adds r0, r2, r4
	str r1, [r0]
_0824669A:
	str r1, [r3, #0x20]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_082466A2:
	pop {r4}
	pop {r1}
	bx r1
