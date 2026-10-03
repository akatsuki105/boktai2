	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	ldr r0, _080B97A0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080B97A4
	ldr r0, [r5, #8]
	orrs r0, r2
	str r0, [r5, #8]
	ldrb r0, [r4]
	b _080B980C
	.align 2, 0
_080B97A0: .4byte 0x030044E0
_080B97A4:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B97B6
	ldr r0, [r5, #8]
	orrs r0, r2
	str r0, [r5, #8]
	movs r0, #0
	b _080B980C
_080B97B6:
	movs r2, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080B97CC
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r2, r0, #0x1f
	b _080B97D6
_080B97CC:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B97D6
	movs r2, #1
_080B97D6:
	cmp r2, #0
	beq _080B9800
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldrb r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r4]
	ldrb r0, [r4]
	movs r2, #5
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
_080B9800:
	adds r0, r5, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	movs r0, #1
	rsbs r0, r0, #0
_080B980C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
