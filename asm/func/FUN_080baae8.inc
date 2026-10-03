	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080BAB54 @ =0x00001408
	adds r6, r5, r0
	ldr r1, _080BAB58 @ =0x00000C78
	adds r2, r5, r1
	ldr r0, _080BAB5C @ =0x00000C18
	adds r3, r5, r0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080b95d0
	ldr r7, _080BAB60 @ =0x030044E0
	ldrh r1, [r7]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BAB6C
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba048
	ldr r1, _080BAB64 @ =0x00000D98
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BAB34
	b _080BAD26
_080BAB34:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080BAB68 @ =0x0000151A
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BAB4E
	b _080BAD26
_080BAB4E:
	movs r0, #0
	strb r0, [r1]
	b _080BAD26
	.align 2, 0
_080BAB54: .4byte 0x00001408
_080BAB58: .4byte 0x00000C78
_080BAB5C: .4byte 0x00000C18
_080BAB60: .4byte 0x030044E0
_080BAB64: .4byte 0x00000D98
_080BAB68: .4byte 0x0000151A
_080BAB6C:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba048
	ldr r0, _080BABD4 @ =0x00000D98
	adds r4, r5, r0
	movs r1, #0x18
	adds r1, r1, r5
	mov r8, r1
	adds r0, r4, #0
	bl MainSprite_AdvanceAnim
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BAB90
	b _080BAD00
_080BAB90:
	ldr r2, _080BABD8 @ =0x0000140B
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0x21
	bne _080BABF4
	ldr r0, _080BABDC @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BABE0 @ =0x000012E4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080ba07c
	ldr r2, _080BABE4 @ =0x00001278
	adds r0, r5, r2
	ldr r1, _080BABE8 @ =0x000012EF
	adds r2, r5, r1
	mov r1, r8
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080BABEC @ =0x00001438
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080BABF0 @ =FUN_080baeb0
	b _080BACF2
	.align 2, 0
_080BABD4: .4byte 0x00000D98
_080BABD8: .4byte 0x0000140B
_080BABDC: .4byte 0x00000107
_080BABE0: .4byte 0x000012E4
_080BABE4: .4byte 0x00001278
_080BABE8: .4byte 0x000012EF
_080BABEC: .4byte 0x00001438
_080BABF0: .4byte FUN_080baeb0
_080BABF4:
	ldr r2, _080BAC44 @ =0x00001409
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080BAC90
	movs r7, #1
	ldrb r0, [r1]
	adds r0, r5, r0
	ldr r1, _080BAC48 @ =0x000012E4
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	blt _080BAC3A
	ldr r0, _080BAC4C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r4, [r0, r2]
	adds r0, r1, #0
	bl FUN_080ba220
	cmp r4, r0
	blt _080BAC3A
	ldr r1, _080BAC50 @ =0x000012F2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bge _080BAC36
	movs r7, #0
_080BAC36:
	cmp r7, #0
	bne _080BAC54
_080BAC3A:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BAD26
	.align 2, 0
_080BAC44: .4byte 0x00001409
_080BAC48: .4byte 0x000012E4
_080BAC4C: .4byte 0x030046A0
_080BAC50: .4byte 0x000012F2
_080BAC54:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BAC8C @ =0x00000E18
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	b _080BACE8
	.align 2, 0
_080BAC8C: .4byte 0x00000E18
_080BAC90:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BACD8 @ =0x00000E18
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080BACDC @ =0x0000140E
	adds r0, r5, r2
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r1, r0, #0
	cmp r1, #0
	bge _080BACE0
	adds r0, r6, #0
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080BACE8
	.align 2, 0
_080BACD8: .4byte 0x00000E18
_080BACDC: .4byte 0x0000140E
_080BACE0:
	adds r0, r6, #0
	movs r1, #0xe
	bl FUN_080b9d94
_080BACE8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba85c
	ldr r1, _080BACFC @ =FUN_080bad30
_080BACF2:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAD26
	.align 2, 0
_080BACFC: .4byte FUN_080bad30
_080BAD00:
	adds r0, r6, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BAD26
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080ba2d8
	adds r0, r5, #0
	bl FUN_080ba57c
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba85c
_080BAD26:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
