	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #4]
	mov r8, r1
	mov sb, r2
	str r3, [sp, #8]
	cmp r0, #0
	beq _080DBA30
	ldr r0, _080DBA38 @ =0x03000164
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _080DBA3C
	movs r0, #0
	movs r1, #0
	bl Entity080dbe54_Create
	mov sl, r0
	cmp r0, #0
	bne _080DBA3C
_080DBA30:
	movs r0, #1
	rsbs r0, r0, #0
	b _080DBCCE
	.align 2, 0
_080DBA38: .4byte 0x03000164
_080DBA3C:
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r1, [sp, #8]
	cmp r0, r1
	blt _080DBA48
	b _080DBCCC
_080DBA48:
	ldr r7, _080DBB1C @ =0x030046B8
_080DBA4A:
	mov r0, sl
	bl FUN_080db9b4
	adds r6, r0, #0
	cmp r6, #0
	beq _080DBA30
	movs r1, #0x13
	ldrsb r1, [r6, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	add r0, sl
	str r0, [sp, #0xc]
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6]
	str r1, [r6, #4]
	mov r3, sb
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	beq _080DBAA4
	ldr r0, [r7]
	adds r0, #1
	ldr r2, _080DBB20 @ =0x000003FF
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080DBB24 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r3, [r6]
	adds r0, r0, r3
	strh r0, [r6]
_080DBAA4:
	mov r1, sb
	movs r2, #2
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080DBAD8
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _080DBB20 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DBB24 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	ldrh r3, [r6, #2]
	adds r0, r0, r3
	strh r0, [r6, #2]
_080DBAD8:
	mov r1, sb
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080DBB0C
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _080DBB20 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DBB24 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #4
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, sb
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	ldrh r3, [r6, #4]
	adds r0, r0, r3
	strh r0, [r6, #4]
_080DBB0C:
	mov r0, r8
	cmp r0, #0
	bne _080DBB28
	strh r0, [r6, #8]
	mov r1, r8
	strh r1, [r6, #0xa]
	strh r1, [r6, #0xc]
	b _080DBBF8
	.align 2, 0
_080DBB1C: .4byte 0x030046B8
_080DBB20: .4byte 0x000003FF
_080DBB24: .4byte 0x0203B400
_080DBB28:
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne _080DBB3C
	ldr r0, _080DBB38 @ =0xFFFF0000
	ands r4, r0
	b _080DBB64
	.align 2, 0
_080DBB38: .4byte 0xFFFF0000
_080DBB3C:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DBB74 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080DBB78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	movs r2, #0
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DBB7C @ =0xFFFF0000
	ands r1, r4
	adds r4, r1, #0
	orrs r4, r0
_080DBB64:
	mov r3, r8
	movs r1, #2
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _080DBB84
	ldr r0, _080DBB80 @ =0x0000FFFF
	ands r4, r0
	b _080DBBAA
	.align 2, 0
_080DBB74: .4byte 0x000003FF
_080DBB78: .4byte 0x0203B400
_080DBB7C: .4byte 0xFFFF0000
_080DBB80: .4byte 0x0000FFFF
_080DBB84:
	ldr r0, [r7]
	adds r0, #1
	ldr r2, _080DBBBC @ =0x000003FF
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080DBBC0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, r8
	movs r3, #2
	ldrsh r1, [r2, r3]
	bl Mod
	lsls r0, r0, #0x10
	ldr r1, _080DBBC4 @ =0x0000FFFF
	ands r1, r4
	adds r4, r1, #0
	orrs r4, r0
_080DBBAA:
	mov r1, r8
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _080DBBCC
	ldr r3, _080DBBC8 @ =0xFFFF0000
	ands r5, r3
	b _080DBBF4
	.align 2, 0
_080DBBBC: .4byte 0x000003FF
_080DBBC0: .4byte 0x0203B400
_080DBBC4: .4byte 0x0000FFFF
_080DBBC8: .4byte 0xFFFF0000
_080DBBCC:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DBC40 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080DBC44 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DBC48 @ =0xFFFF0000
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_080DBBF4:
	str r4, [r6, #8]
	str r5, [r6, #0xc]
_080DBBF8:
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _080DBC40 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DBC44 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x10
	bl Mod
	strh r0, [r6, #0x16]
	mov r2, sl
	ldr r1, [r2, #0x1c]
	ldr r0, [sp, #0xc]
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	ldr r0, [sp, #0xc]
	adds r1, r2, #0
	bl Particle_SetOffset
	movs r1, #8
	ldr r0, _080DBC4C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080DBC50 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080DBC54
	movs r0, #1
	b _080DBC56
	.align 2, 0
_080DBC40: .4byte 0x000003FF
_080DBC44: .4byte 0x0203B400
_080DBC48: .4byte 0xFFFF0000
_080DBC4C: .4byte 0x030046A0
_080DBC50: .4byte 0x00000934
_080DBC54:
	movs r0, #0
_080DBC56:
	movs r2, #0xd
	cmp r0, #0
	beq _080DBC5E
	movs r2, #0xe
_080DBC5E:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DBCE0 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080DBCE4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #2
	str r2, [sp, #0x14]
	bl Mod
	adds r3, r0, #0
	ldr r0, [sp, #0x3c]
	orrs r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov ip, r3
	movs r0, #0x13
	ldrsb r0, [r6, r0]
	lsls r0, r0, #4
	movs r1, #0xa4
	lsls r1, r1, #3
	adds r0, r0, r1
	add r0, sl
	mov r3, sl
	ldr r1, [r3, #0x18]
	ldr r2, [sp, #0x14]
	mov r3, ip
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r1, [sp, #0xc]
	ldr r0, [r1]
	ldr r1, _080DBCE8 @ =0x00000201
	orrs r0, r1
	ldr r2, [sp, #0xc]
	str r0, [r2]
	add r3, sp, #0x38
	ldrb r3, [r3]
	strb r3, [r2, #0xf]
	movs r0, #1
	strb r0, [r6, #0x12]
	add r0, sp, #0x40
	ldrh r0, [r0]
	strh r0, [r6, #0x10]
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r2, [sp, #8]
	cmp r1, r2
	bge _080DBCCC
	b _080DBA4A
_080DBCCC:
	movs r0, #0
_080DBCCE:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DBCE0: .4byte 0x000003FF
_080DBCE4: .4byte 0x0203B400
_080DBCE8: .4byte 0x00000201
