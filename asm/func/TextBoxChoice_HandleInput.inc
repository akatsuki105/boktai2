	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0x18
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _08005394
	ldr r0, _0800538C @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	bne _08005378
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800539E
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _08005378
	b _08005522
_08005378:
	movs r1, #0x19
	ldrsb r1, [r5, r1]
	adds r0, r5, #0
	bl TextBoxChoice_SetCursor
	ldr r0, _08005390 @ =0x00000107
	bl PlaySound_082406e0
	b _08005522
	.align 2, 0
_0800538C: .4byte 0x030044E0
_08005390: .4byte 0x00000107
_08005394:
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	beq _080053A4
_0800539E:
	subs r0, #1
	strb r0, [r1]
	b _08005522
_080053A4:
	ldr r0, _080053C4 @ =0x030044E0
	ldrh r0, [r0]
	ldr r1, [r5, #0x40]
	ands r1, r0
	cmp r1, #0
	beq _080053C8
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	beq _080053D0
	subs r0, r1, #1
	mov r1, r8
	strb r0, [r1]
	b _080053D0
	.align 2, 0
_080053C4: .4byte 0x030044E0
_080053C8:
	adds r0, r5, #0
	adds r0, #0x3e
	strb r1, [r0]
	mov r8, r0
_080053D0:
	ldr r0, _08005408 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	str r0, [r5, #0x40]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080054C8
	movs r2, #0x18
	ldrsb r2, [r5, r2]
	lsls r0, r2, #2
	adds r0, #0x64
	adds r7, r5, r0
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800540C
	subs r1, r2, #1
	adds r0, r5, #0
	adds r0, #0x1c
	ldrb r7, [r7, #3]
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r1, r0
	bge _08005468
	b _08005466
	.align 2, 0
_08005408: .4byte 0x030044E0
_0800540C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08005420
	adds r1, r2, #1
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r7, [r7, #3]
	adds r0, r0, r7
	b _080054B4
_08005420:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08005476
	ldrb r1, [r7, #3]
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r6, r2, r0
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	bl TextBoxChoice_FindLine
	adds r2, r0, #0
	ldrb r0, [r7, #3]
	cmp r0, r2
	bne _0800544C
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	b _08005452
_0800544C:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r1, r0, r6
_08005452:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	blt _08005466
	adds r0, r5, #0
	adds r0, #0x24
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r1, r0
	ble _08005468
_08005466:
	adds r1, r0, #0
_08005468:
	adds r0, r5, #0
	bl TextBoxChoice_SetCursor
	movs r0, #0x1e
	mov r1, r8
	strb r0, [r1]
	b _080054C8
_08005476:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080054C8
	ldrb r1, [r7, #3]
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r6, r2, r0
	adds r0, r5, #0
	movs r2, #1
	bl TextBoxChoice_FindLine
	adds r2, r0, #0
	ldrb r0, [r7, #3]
	cmp r0, r2
	bne _080054A0
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	b _080054A6
_080054A0:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r1, r0, r6
_080054A6:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	blt _080054BA
	adds r0, r5, #0
	adds r0, #0x24
	adds r0, r0, r2
_080054B4:
	ldrb r0, [r0]
	cmp r1, r0
	ble _080054BC
_080054BA:
	adds r1, r0, #0
_080054BC:
	adds r0, r5, #0
	bl TextBoxChoice_SetCursor
	movs r0, #0x1e
	mov r2, r8
	strb r0, [r2]
_080054C8:
	ldr r0, _080054FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08005500
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005522
	movs r0, #0xde
	bl PlaySound_082406e0
	bl FUN_08047864
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r5, #0
	bl TextBoxChoice_Finish
	adds r0, r5, #0
	bl KillEntity
	b _08005522
	.align 2, 0
_080054FC: .4byte 0x030044E0
_08005500:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08005522
	movs r0, #0xdd
	bl PlaySound_082406e0
	bl FUN_08047864
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	adds r0, r5, #0
	bl TextBoxChoice_Finish
	adds r0, r5, #0
	bl KillEntity
_08005522:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
