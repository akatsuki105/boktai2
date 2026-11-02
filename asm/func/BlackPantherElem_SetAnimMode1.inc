	push {r4, r5, lr}
	sub sp, #0xc
	adds r3, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	adds r4, r3, #0
	adds r4, #0x7c
	ldr r0, [r3, #0x7c]
	cmp r0, #1
	bne _0805329E
	ldrb r2, [r3, #0x10]
	movs r3, #0
	cmp r2, #1
	bls _080532AA
	b _080532A8
_0805329E:
	movs r2, #0
	ldrb r0, [r3, #0x10]
	movs r3, #0
	cmp r0, #1
	bls _080532AA
_080532A8:
	movs r3, #1
_080532AA:
	str r1, [sp]
	ldr r0, [sp, #0x18]
	str r0, [sp, #4]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r5, #0
	bl SpriteHolder_SetAnim
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
