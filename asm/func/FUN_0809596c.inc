	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _08095A44
	ldr r0, _080959A8 @ =0x00003AEE
	adds r4, r5, r0
	ldrb r0, [r4]
	bl GetWeaponID
	cmp r0, #0
	bne _080959B0
	ldr r2, _080959AC @ =0x00003AEB
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _080959F6
	bl GetWeaponID
	cmp r0, #0
	beq _08095A44
	b _08095A48
	.align 2, 0
_080959A8: .4byte 0x00003AEE
_080959AC: .4byte 0x00003AEB
_080959B0:
	ldr r1, _080959FC @ =0x00003AEB
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0xf
	bhi _08095A4C
	ldrb r0, [r4]
	cmp r0, r1
	bne _08095A48
	bl GetWeaponKind
	movs r6, #1
	rsbs r6, r6, #0
	movs r2, #0
	ldr r0, _08095A00 @ =0x030046A0
	ldr r0, [r0]
	ldrb r3, [r4]
	adds r1, r0, #0
	adds r1, #0x60
_080959D4:
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _080959DE
	adds r6, r2, #0
_080959DE:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _080959D4
	cmp r6, #0
	blt _08095A04
	cmp r6, #3
	bne _08095A44
	ldr r0, _080959FC @ =0x00003AEB
	adds r1, r5, r0
	movs r0, #0x13
	strb r0, [r1]
_080959F6:
	movs r0, #4
	b _08095A56
	.align 2, 0
_080959FC: .4byte 0x00003AEB
_08095A00: .4byte 0x030046A0
_08095A04:
	movs r2, #0
	ldr r1, _08095A3C @ =0x00003AE8
	adds r3, r5, r1
	ldrb r0, [r3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08095A28
	adds r1, r3, #0
	movs r3, #1
_08095A18:
	adds r2, #1
	cmp r2, #3
	bgt _08095A44
	ldrb r0, [r1]
	asrs r0, r2
	ands r0, r3
	cmp r0, #0
	beq _08095A18
_08095A28:
	cmp r2, #3
	bgt _08095A44
	adds r1, r2, #0
	adds r1, #0x10
	ldr r2, _08095A40 @ =0x00003AEB
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #1
	b _08095A56
	.align 2, 0
_08095A3C: .4byte 0x00003AE8
_08095A40: .4byte 0x00003AEB
_08095A44:
	movs r0, #0
	b _08095A56
_08095A48:
	movs r0, #3
	b _08095A56
_08095A4C:
	cmp r1, #0x14
	beq _08095A54
	movs r0, #1
	b _08095A56
_08095A54:
	movs r0, #2
_08095A56:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
