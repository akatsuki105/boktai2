	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	adds r6, r1, #0
	adds r2, r6, #0
	adds r2, #0x34
	ldrb r0, [r2]
	cmp r0, #0
	beq _081EDDD8
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r0, #0
	strb r0, [r2]
_081EDDD8:
	ldrh r1, [r6, #0x30]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081EDDE4
	b _081EDFFA
_081EDDE4:
	adds r0, r6, #0
	adds r0, #0x18
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r3, r0, #0
	cmp r2, #0
	blt _081EDE0E
	cmp r1, #0
	blt _081EDE0E
	ldr r0, _081EDE14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EDE0E
	ldr r0, _081EDE18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EDE1C
_081EDE0E:
	movs r0, #0
	b _081EDE2A
	.align 2, 0
_081EDE14: .4byte 0x030046A8
_081EDE18: .4byte 0x030046AC
_081EDE1C:
	ldr r0, _081EDE58 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081EDE2A:
	strh r0, [r6, #0x3a]
	ldrh r0, [r6, #0x2a]
	subs r0, #1
	strh r0, [r6, #0x2a]
	adds r7, r3, #0
	adds r4, r6, #0
	adds r4, #0x28
	ldrh r0, [r6, #0x3a]
	mov r8, r0
	movs r1, #0x28
	ldrsh r0, [r6, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	mov r0, r8
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EDE5C
	adds r0, #4
	b _081EDE6A
	.align 2, 0
_081EDE58: .4byte 0x030046A4
_081EDE5C:
	ldr r0, _081EDE80 @ =0x030046A4
	ldr r1, [r0]
	mov r3, r8
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EDE6A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EDE84
	cmp r2, #2
	beq _081EDE88
	b _081EDE8C
	.align 2, 0
_081EDE80: .4byte 0x030046A4
_081EDE84:
	ldrb r0, [r7, #4]
	b _081EDE8A
_081EDE88:
	ldrb r0, [r7]
_081EDE8A:
	subs r1, r1, r0
_081EDE8C:
	mov sb, r1
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	cmn r1, r0
	bne _081EDEB4
	movs r0, #1
	b _081EDFEE
_081EDEB4:
	movs r1, #2
	ldrsh r0, [r7, r1]
	cmp r0, sb
	bgt _081EDEF0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #2
	rsbs r0, r0, #0
	movs r1, #0xa
	bl Div
	strh r0, [r4, #2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	strh r0, [r4, #4]
	mov r0, sb
	strh r0, [r7, #2]
_081EDEF0:
	ldrh r0, [r4]
	ldrh r1, [r7]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r3, _081EDF48 @ =0xFFFF0000
	ldrh r1, [r4, #2]
	ldrh r2, [r7, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r4, #4]
	ldrh r0, [r7, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, sp
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _081EDF42
	cmp r1, #0
	blt _081EDF42
	ldr r0, _081EDF4C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081EDF42
	ldr r0, _081EDF50 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EDF54
_081EDF42:
	movs r5, #0
	b _081EDF62
	.align 2, 0
_081EDF48: .4byte 0xFFFF0000
_081EDF4C: .4byte 0x030046A8
_081EDF50: .4byte 0x030046AC
_081EDF54:
	ldr r0, _081EDF78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r3
_081EDF62:
	cmp r8, r5
	beq _081EDFD4
	mov r8, sp
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EDF7C
	adds r0, #4
	b _081EDF88
	.align 2, 0
_081EDF78: .4byte 0x030046A4
_081EDF7C:
	ldr r0, _081EDF9C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EDF88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EDFA0
	cmp r2, #2
	beq _081EDFA6
	b _081EDFAC
	.align 2, 0
_081EDF9C: .4byte 0x030046A4
_081EDFA0:
	mov r2, r8
	ldrb r0, [r2, #4]
	b _081EDFAA
_081EDFA6:
	mov r3, r8
	ldrb r0, [r3]
_081EDFAA:
	subs r1, r1, r0
_081EDFAC:
	cmp sb, r1
	bge _081EDFD4
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4]
	movs r2, #4
	ldrsh r1, [r4, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4, #4]
_081EDFD4:
	ldrh r0, [r4]
	ldrh r3, [r7]
	adds r0, r0, r3
	strh r0, [r7]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	strh r0, [r7, #4]
	movs r0, #0
_081EDFEE:
	cmp r0, #0
	beq _081EDFFA
	ldrh r1, [r6, #0x30]
	movs r0, #1
	orrs r0, r1
	strh r0, [r6, #0x30]
_081EDFFA:
	mov r0, sl
	adds r1, r6, #0
	bl Entity081ee2a0Elem_UpdateAnim
	ldrh r0, [r6, #0x38]
	cmp r0, #0
	beq _081EE00E
	subs r0, #1
	strh r0, [r6, #0x38]
	b _081EE01C
_081EE00E:
	adds r1, r6, #0
	adds r1, #0x32
	movs r0, #2
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
_081EE01C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
