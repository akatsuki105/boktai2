	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	str r1, [sp, #8]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _081BAA00 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BAA04
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BAA06
	.align 2, 0
_081BAA00: .4byte 0x0000046D
_081BAA04:
	movs r0, #0
_081BAA06:
	cmp r0, #0
	beq _081BAAE4
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq _081BAA30
	cmp r0, #1
	bgt _081BAA28
	cmp r0, #0
	beq _081BAA8C
	b _081BAADC
_081BAA28:
	cmp r0, #3
	beq _081BAA30
	cmp r0, #5
	bne _081BAADC
_081BAA30:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _081BAA48 @ =0x0000065C
	adds r1, r1, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081BAA4C
	movs r0, #1
	b _081BAA4E
	.align 2, 0
_081BAA48: .4byte 0x0000065C
_081BAA4C:
	movs r0, #0
_081BAA4E:
	cmp r0, #0
	beq _081BAA60
_081BAA52:
	ldr r1, _081BAA5C @ =0xFFFFF7FF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081BAADC
	.align 2, 0
_081BAA5C: .4byte 0xFFFFF7FF
_081BAA60:
	ldr r2, _081BAA80 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081BAA84 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081BAA88 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x1e
	b _081BAADE
	.align 2, 0
_081BAA80: .4byte 0x030046B8
_081BAA84: .4byte 0x000003FF
_081BAA88: .4byte 0x0203B400
_081BAA8C:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _081BAAA4 @ =0x0000065C
	adds r1, r1, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081BAAA8
	movs r0, #1
	b _081BAAAA
	.align 2, 0
_081BAAA4: .4byte 0x0000065C
_081BAAA8:
	movs r0, #0
_081BAAAA:
	cmp r0, #0
	bne _081BAA52
	ldr r2, _081BAAD0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081BAAD4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081BAAD8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #4
	adds r1, r0, #0
	adds r1, #0x32
	b _081BAADE
	.align 2, 0
_081BAAD0: .4byte 0x030046B8
_081BAAD4: .4byte 0x000003FF
_081BAAD8: .4byte 0x0203B400
_081BAADC:
	movs r1, #0
_081BAADE:
	ldr r0, _081BAB34 @ =0x000006BE
	add r0, sb
	strh r1, [r0]
_081BAAE4:
	mov r4, sp
	adds r4, #5
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _081BAB38 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _081BAB3C @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	bne _081BAB48
	ldr r2, _081BAB40 @ =0x000004B7
	adds r0, r5, r2
	mov r1, ip
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl AuxAnim_SetAnim
	ldr r2, _081BAB44 @ =0x0000046E
	adds r7, r5, r2
	b _081BABCA
	.align 2, 0
_081BAB34: .4byte 0x000006BE
_081BAB38: .4byte 0x085ADFA8
_081BAB3C: .4byte 0x0000025D
_081BAB40: .4byte 0x000004B7
_081BAB44: .4byte 0x0000046E
_081BAB48:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r3, #8
	mov ip, r3
	ldr r1, _081BABB8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _081BABBC @ =0x0000046E
	adds r7, r5, r0
	cmp r1, ip
	bne _081BAB84
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BAB84
	cmp r4, #1
	bne _081BAB76
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BABCE
_081BAB76:
	cmp r4, #0
	bne _081BAB84
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BABCE
_081BAB84:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _081BAB98
	movs r3, #6
_081BAB98:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081BABC0
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081BABC8
	.align 2, 0
_081BABB8: .4byte 0x000004B7
_081BABBC: .4byte 0x0000046E
_081BABC0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BABC8:
	str r0, [r6, #8]
_081BABCA:
	movs r0, #0
	strb r0, [r7]
_081BABCE:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r5, r2
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r2, _081BAC14 @ =0x000006B6
	add r2, sb
	ldrh r4, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _081BAC18 @ =0x0000017F
	cmp r1, r0
	bgt _081BABF4
	adds r0, r4, #0
	adds r0, #0x10
	strh r0, [r2]
_081BABF4:
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _081BAC1C @ =0x00000482
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _081BAC20 @ =0x0000A02F
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081BAC24
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BAC34
	.align 2, 0
_081BAC14: .4byte 0x000006B6
_081BAC18: .4byte 0x0000017F
_081BAC1C: .4byte 0x00000482
_081BAC20: .4byte 0x0000A02F
_081BAC24:
	ldr r1, _081BAC58 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BAC34
	movs r0, #1
	strh r0, [r2]
_081BAC34:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _081BAC5C
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081BAC74
	.align 2, 0
_081BAC58: .4byte 0x00000482
_081BAC5C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081BAC74:
	ldr r0, _081BACA0 @ =0x000006BE
	add r0, sb
	ldr r2, [sp, #8]
	ldrh r0, [r0]
	cmp r2, r0
	ble _081BAC90
	ldr r0, _081BACA4 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #4
	bl PlayGolemSound
_081BAC90:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BACA0: .4byte 0x000006BE
_081BACA4: .4byte 0x0000046B
