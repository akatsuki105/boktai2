	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _080AFBF4 @ =0x0000067E
	adds r1, r6, r0
	movs r2, #0xd0
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r2, [r1, r4]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	bge _080AFBF8
	adds r0, r3, #1
	b _080AFBFE
	.align 2, 0
_080AFBF4: .4byte 0x0000067E
_080AFBF8:
	cmp r2, r0
	ble _080AFC00
	subs r0, r3, #1
_080AFBFE:
	strh r0, [r1]
_080AFC00:
	ldr r0, _080AFCF4 @ =0x00000682
	adds r4, r6, r0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AFC62
	ldr r1, _080AFCF8 @ =0x0203B400
	mov ip, r1
	ldr r5, _080AFCFC @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r7, _080AFD00 @ =0x000003FF
	ands r1, r7
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r3, r0, #0
	adds r3, #0xc
	movs r0, #0xd0
	lsls r0, r0, #3
	adds r2, r6, r0
	strh r3, [r2]
	adds r1, #1
	ands r1, r7
	str r1, [r5]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AFC4C
	rsbs r0, r3, #0
	strh r0, [r2]
_080AFC4C:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x20
	strh r0, [r4]
_080AFC62:
	ldr r1, _080AFD04 @ =0x0000067C
	adds r3, r6, r1
	ldr r4, _080AFD08 @ =0x00000FFF
	adds r2, r4, #0
	ldrh r5, [r3]
	adds r1, r2, r5
	ldr r4, _080AFD0C @ =0x0000067E
	adds r0, r6, r4
	ldrh r0, [r0]
	adds r0, r0, r1
	ands r0, r2
	strh r0, [r3]
	lsrs r0, r0, #4
	mov ip, r0
	movs r5, #0xd1
	lsls r5, r5, #3
	adds r7, r6, r5
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AFCBC
	ldr r5, _080AFCF8 @ =0x0203B400
	ldr r4, _080AFCFC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080AFD00 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrb r1, [r1]
	adds r1, #0xc0
	ldr r2, _080AFD10 @ =0x00000686
	strh r1, [r2, r6]
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	strh r0, [r7]
_080AFCBC:
	ldr r3, _080AFD14 @ =0x00000684
	adds r1, r6, r3
	ldrh r2, [r1]
	lsls r0, r2, #4
	ldr r4, _080AFD10 @ =0x00000686
	adds r3, r6, r4
	subs r0, r0, r2
	ldrh r3, [r3]
	adds r0, r0, r3
	asrs r0, r0, #4
	strh r0, [r1]
	ldrh r3, [r1]
	ldr r1, _080AFD18 @ =0x085B0A08
	mov r2, ip
	adds r2, #0x40
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _080AFD1C
	asrs r0, r0, #0xc
	b _080AFD22
	.align 2, 0
_080AFCF4: .4byte 0x00000682
_080AFCF8: .4byte 0x0203B400
_080AFCFC: .4byte 0x030046B8
_080AFD00: .4byte 0x000003FF
_080AFD04: .4byte 0x0000067C
_080AFD08: .4byte 0x00000FFF
_080AFD0C: .4byte 0x0000067E
_080AFD10: .4byte 0x00000686
_080AFD14: .4byte 0x00000684
_080AFD18: .4byte 0x085B0A08
_080AFD1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFD22:
	adds r3, r0, #0
	ldr r1, _080AFD4C @ =0x0000068C
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFD50
	asrs r1, r0, #0x18
	b _080AFD56
	.align 2, 0
_080AFD4C: .4byte 0x0000068C
_080AFD50:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_080AFD56:
	movs r5, #0xce
	lsls r5, r5, #3
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r3
	adds r0, r0, r1
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r1, r6, r2
	strh r0, [r1]
	ldr r3, _080AFD84 @ =0x00000684
	adds r0, r6, r3
	ldrh r1, [r0]
	mov r5, ip
	lsls r0, r5, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFD88
	asrs r0, r0, #0xc
	b _080AFD8E
	.align 2, 0
_080AFD84: .4byte 0x00000684
_080AFD88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFD8E:
	adds r2, r0, #0
	ldr r3, _080AFDB4 @ =0x0000068C
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	mov r3, ip
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFDB8
	asrs r1, r0, #0x18
	b _080AFDBE
	.align 2, 0
_080AFDB4: .4byte 0x0000068C
_080AFDB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_080AFDBE:
	ldr r5, _080AFDFC @ =0x00000674
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r2, _080AFE00 @ =0x0000061C
	adds r1, r6, r2
	strh r0, [r1]
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r1, r6, r3
	ldrh r0, [r1]
	cmp r0, #2
	bhi _080AFE08
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080af53c
	ldr r4, _080AFE04 @ =0x00000692
	adds r1, r6, r4
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _080AFE0C
	adds r0, r6, #0
	movs r1, #4
	bl FUN_080af374
	b _080AFE0C
	.align 2, 0
_080AFDFC: .4byte 0x00000674
_080AFE00: .4byte 0x0000061C
_080AFE04: .4byte 0x00000692
_080AFE08:
	subs r0, #2
	strh r0, [r1]
_080AFE0C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
