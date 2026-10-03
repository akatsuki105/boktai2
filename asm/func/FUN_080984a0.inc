	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _080984C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080984C4
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_0809820c
	b _080985C6
	.align 2, 0
_080984C0: .4byte 0x030044E0
_080984C4:
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0809859E
	adds r0, r5, #0
	bl FUN_0808c700
	adds r0, r5, #0
	bl FUN_080980a8
	cmp r0, #1
	beq _080984E8
	cmp r0, #1
	ble _08098594
	cmp r0, #4
	beq _08098528
	b _08098594
_080984E8:
	ldr r0, _08098518 @ =0x0000144C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r1, _0809851C @ =0x00003AEE
	adds r0, r5, r1
	ldrb r3, [r0]
	ldr r2, _08098520 @ =0x00003FF0
	adds r0, r5, r2
	adds r0, r0, r3
	movs r2, #0
	ldrsb r2, [r0, r2]
	subs r1, #3
	adds r0, r5, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08097f48
	ldr r1, _08098524 @ =FUN_080985ec
	b _08098570
	.align 2, 0
_08098518: .4byte 0x0000144C
_0809851C: .4byte 0x00003AEE
_08098520: .4byte 0x00003FF0
_08098524: .4byte FUN_080985ec
_08098528:
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r2, _0809857C @ =0x0000144C
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, _08098580 @ =0x00003AEE
	adds r1, r5, r0
	ldr r2, _08098584 @ =0x00003FF0
	adds r0, r5, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldr r0, _08098588 @ =0x00003AEB
	adds r4, r5, r0
	ldrb r3, [r4]
	str r3, [sp]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08097f48
	ldrb r0, [r4]
	adds r0, #0x14
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _0809858C @ =0x00000F6C
	adds r2, r5, r0
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r6
	str r0, [r2]
	ldr r1, _08098590 @ =FUN_08098684
_08098570:
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
	b _080985C6
	.align 2, 0
_0809857C: .4byte 0x0000144C
_08098580: .4byte 0x00003AEE
_08098584: .4byte 0x00003FF0
_08098588: .4byte 0x00003AEB
_0809858C: .4byte 0x00000F6C
_08098590: .4byte FUN_08098684
_08098594:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080985C6
_0809859E:
	ldr r1, _080985DC @ =0x00003AE8
	adds r0, r5, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _080985C6
	ldr r2, _080985E0 @ =0x00001464
	adds r0, r5, r2
	ldr r2, _080985E4 @ =0x00003AEB
	adds r1, r5, r2
	ldrb r1, [r1]
	bl FUN_08097ca0
	adds r0, r5, #0
	bl FUN_08097c04
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08097fb4
_080985C6:
	ldr r1, _080985E8 @ =0x00001444
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x60
	bl MainSprite_AdvanceAnim
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080985DC: .4byte 0x00003AE8
_080985E0: .4byte 0x00001464
_080985E4: .4byte 0x00003AEB
_080985E8: .4byte 0x00001444
