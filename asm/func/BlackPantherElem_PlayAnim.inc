	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r3, #0
	ldr r7, [sp, #0x1c]
	str r2, [r4, #0x20]
	cmp r2, #3
	bgt _0805337E
	ldr r0, [r4]
	cmp r0, #0
	bne _08053368
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08053368
	adds r2, #0xa
_08053368:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r2, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	b _0805338C
_0805337E:
	subs r0, r2, #4
	ldr r1, _080533A4 @ =0x085AB924
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r2, [r0, #2]
	ldrb r3, [r0, #1]
_0805338C:
	cmp r1, #1
	bne _080533A8
	str r7, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl BlackPantherElem_SetAnimMode1
	b _080533E4
	.align 2, 0
_080533A4: .4byte 0x085AB924
_080533A8:
	cmp r1, #2
	bne _080533BE
	str r7, [sp]
	ldr r1, [sp, #0x20]
	str r1, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl BlackPantherElem_SetAnimMode2
	b _080533E4
_080533BE:
	cmp r1, #3
	bne _080533D4
	str r7, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl BlackPantherElem_SetAnimMode3
	b _080533E4
_080533D4:
	str r7, [sp]
	ldr r1, [sp, #0x20]
	str r1, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl BlackPantherElem_SetAnimMode0
_080533E4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
