	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0805454C
	movs r1, #0
	strb r1, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	movs r0, #0xc0
	strb r0, [r4, #0xf]
	movs r1, #1
	strb r1, [r4, #0x11]
	movs r0, #0
	strb r0, [r4, #0x10]
	adds r0, r5, #0
	adds r0, #0x30
	strb r1, [r0]
_0805454C:
	ldrb r0, [r4, #0xd]
	adds r6, r4, #0
	adds r6, #0x78
	cmp r0, #3
	bne _080545AE
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #2
	ldrb r0, [r0, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _080545AE
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	ldrb r1, [r4, #8]
	cmp r0, r1
	bne _080545AE
	adds r2, #0x70
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08054588
	rsbs r1, r1, #0
_08054588:
	cmp r1, #0x7f
	bgt _080545AE
	ldr r1, _080545C0 @ =0x00001E18
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x40
	movs r3, #1
	bl BlackPanther_AddScore
	movs r0, #6
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	ldr r0, _080545C4 @ =0x0000028B
	bl PlaySound_082406e0
_080545AE:
	ldr r3, [r5, #0x28]
	ldr r1, [r5, #0x24]
	subs r2, r3, r1
	cmp r2, #3
	ble _080545C8
	adds r0, r1, #4
	str r0, [r5, #0x24]
	b _080545D8
	.align 2, 0
_080545C0: .4byte 0x00001E18
_080545C4: .4byte 0x0000028B
_080545C8:
	movs r0, #4
	rsbs r0, r0, #0
	cmp r2, r0
	bgt _080545D6
	subs r0, r1, #4
	str r0, [r5, #0x24]
	b _080545D8
_080545D6:
	str r3, [r5, #0x24]
_080545D8:
	ldr r0, [r5, #0x24]
	ldr r2, _080545F8 @ =0x00000CE4
	adds r1, r2, #0
	subs r1, r1, r0
	strh r1, [r6]
	ldr r1, _080545FC @ =0x000003E7
	cmp r0, r1
	ble _08054600
	movs r0, #7
	strb r0, [r4, #0xb]
	movs r0, #1
	strb r0, [r4, #0xc]
	movs r0, #0
	str r0, [r4, #0x18]
	b _08054668
	.align 2, 0
_080545F8: .4byte 0x00000CE4
_080545FC: .4byte 0x000003E7
_08054600:
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _08054668
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl BlackPantherElem_CheckObjHit
	cmp r0, #0
	beq _08054668
	ldrb r0, [r4, #8]
	cmp r0, #1
	beq _0805462A
	cmp r0, #1
	bgt _08054624
	cmp r0, #0
	beq _08054658
	b _0805465C
_08054624:
	cmp r0, #2
	beq _08054658
	b _0805465C
_0805462A:
	ldr r2, _08054648 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805464C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08054650 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08054654
	movs r0, #0
	b _0805465A
	.align 2, 0
_08054648: .4byte 0x030046B8
_0805464C: .4byte 0x000003FF
_08054650: .4byte 0x0203B400
_08054654:
	movs r0, #2
	b _0805465A
_08054658:
	movs r0, #1
_0805465A:
	strb r0, [r4, #9]
_0805465C:
	movs r0, #5
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
_08054668:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
