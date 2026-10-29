	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r5, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C8DDC
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x2a
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C8DDC:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C8E0C
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r6, #0x83
	ble _080C8E06
	adds r1, #0xf
	movs r0, #1
	strb r0, [r1]
_080C8E06:
	adds r0, r5, #0
	bl Jormungandr_EasePos
_080C8E0C:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
