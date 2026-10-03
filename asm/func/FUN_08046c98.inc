	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r1, [r4, #5]
	cmp r1, #0
	beq _08046CC0
	movs r0, #0
	strb r0, [r4, #5]
	strb r0, [r4, #8]
	adds r2, r4, #0
	adds r2, #0xa4
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r4, r1
	bl ParticleShadow_Hide
_08046CC0:
	ldrh r1, [r4, #0x1c]
	cmp r1, #0
	bne _08046D6A
	adds r1, r5, #0
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	bne _08046D6E
	ldrb r1, [r5, #0x1e]
	adds r3, r5, #0
	adds r3, #0x20
	adds r6, r4, #0
	adds r6, #0x24
	cmp r1, #0
	beq _08046D1E
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _08046D1E
	ldrb r1, [r3]
	ldrb r2, [r6]
	cmp r1, r2
	bne _08046D04
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x25
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08046D5A
_08046D04:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r2, [r6]
	cmp r1, r2
	bne _08046D1E
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x25
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bls _08046D5A
_08046D1E:
	ldrb r3, [r3]
	ldrb r6, [r6]
	cmp r3, r6
	bne _08046D36
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x25
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08046D5A
_08046D36:
	adds r1, r4, #0
	adds r1, #0x26
	cmp r3, r6
	bls _08046D44
	ldrb r2, [r1]
	cmp r3, r2
	blo _08046D5A
_08046D44:
	ldrb r1, [r1]
	cmp r3, r1
	bne _08046D6E
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08046D6E
_08046D5A:
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0x10]
	movs r0, #0
	b _08046D6E
_08046D6A:
	subs r1, #1
	strh r1, [r4, #0x1c]
_08046D6E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
