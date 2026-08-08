	push {r4, r5, lr}
	adds r5, r0, #0
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r3, [r0]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r1, r4
	ldr r2, [r0]
	ldrb r0, [r1]
	cmp r0, #0
	bne _082466C8
	movs r0, #1
	rsbs r0, r0, #0
	b _082466E4
_082466C8:
	cmp r3, #0
	beq _082466D2
	adds r0, r3, r4
	str r2, [r0]
	b _082466D4
_082466D2:
	str r2, [r5, #0x20]
_082466D4:
	cmp r2, #0
	beq _082466E0
	movs r4, #0x98
	lsls r4, r4, #1
	adds r0, r2, r4
	str r3, [r0]
_082466E0:
	movs r0, #0
	strb r0, [r1]
_082466E4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
