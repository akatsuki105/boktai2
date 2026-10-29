	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r0, r6, #0
	adds r0, #0x4c
	str r0, [sp, #0xc]
	ldrb r0, [r6, #8]
	cmp r0, #0
	beq _08057A04
	movs r0, #0
	strb r0, [r6, #8]
	ldr r1, _08057A38 @ =0x0203B400
	mov sb, r1
	ldr r4, _08057A3C @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08057A40 @ =0x000003FF
	ands r1, r3
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	movs r2, #3
	mov r5, r8
	ands r2, r5
	lsls r2, r2, #3
	adds r2, r7, r2
	ands r0, r3
	ldrh r5, [r2, #0x3c]
	adds r0, r0, r5
	strh r0, [r6, #0x1c]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	adds r2, #0x40
	ands r0, r3
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r6, #0x1e]
_08057A04:
	ldr r1, [r7, #0x18]
	movs r3, #0
	ldrb r2, [r6, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r6, #0
	adds r4, #0x78
	cmp r0, #1
	bhi _08057A1A
	movs r3, #1
_08057A1A:
	movs r0, #0
	cmp r2, #1
	bls _08057A22
	movs r0, #1
_08057A22:
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08057A44
	subs r0, #1
	strb r0, [r6, #0xe]
	b _08057A78
	.align 2, 0
_08057A38: .4byte 0x0203B400
_08057A3C: .4byte 0x030046B8
_08057A40: .4byte 0x000003FF
_08057A44:
	ldr r1, [r6, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057A78
	ldrb r0, [r6, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057A5C
	subs r0, #1
	strb r0, [r6, #0xf]
	b _08057A78
_08057A5C:
	movs r0, #0x1e
	strb r0, [r6, #0xf]
	movs r0, #0x78
	strb r0, [r6, #0xe]
	movs r1, #5
	ldr r0, [r7, #0x30]
	cmp r0, #0
	beq _08057A6E
	movs r1, #8
_08057A6E:
	strb r1, [r6, #4]
	movs r0, #1
	strb r0, [r6, #8]
	str r2, [r6, #0x14]
	b _08057D9E
_08057A78:
	ldrb r3, [r6, #0x10]
	cmp r3, #0
	bne _08057AA4
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r6, #0x18]
	movs r2, #0
	cmp r0, r1
	bhi _08057A8C
	movs r2, #1
_08057A8C:
	cmp r2, #0
	beq _08057AA4
	movs r1, #4
	ldr r0, [r7, #0x30]
	cmp r0, #0
	beq _08057A9A
	movs r1, #8
_08057A9A:
	strb r1, [r6, #4]
	movs r0, #1
	strb r0, [r6, #8]
	str r3, [r6, #0x14]
	b _08057D9E
_08057AA4:
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	bne _08057AC4
	ldr r2, _08057AC0 @ =0x085AB9A4
	ldrh r1, [r4, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #3
	asrs r0, r0, #6
	b _08057AC6
	.align 2, 0
_08057AC0: .4byte 0x085AB9A4
_08057AC4:
	movs r0, #0
_08057AC6:
	movs r4, #0
	strb r0, [r6, #6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08057AD2
	b _08057D98
_08057AD2:
	adds r2, r6, #0
	adds r2, #0x4c
	movs r0, #0x1c
	ldrsh r1, [r6, r0]
	movs r3, #0x1c
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	movs r5, #0x1e
	ldrsh r1, [r6, r5]
	movs r5, #0x20
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _08057AF2
	rsbs r0, r3, #0
_08057AF2:
	cmp r0, #0x17
	bgt _08057B2C
	adds r0, r1, #0
	cmp r1, #0
	bge _08057AFE
	rsbs r0, r1, #0
_08057AFE:
	cmp r0, #0x17
	bgt _08057B1E
	strb r4, [r6, #6]
	movs r0, #0xff
	strb r0, [r6, #0xb]
	movs r3, #1
	ldr r1, [r7, #0x30]
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r6, #4]
	strb r3, [r6, #8]
	str r4, [r6, #0x14]
	b _08057D9E
_08057B1E:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
	ldrb r4, [r6, #0xb]
	b _08057B82
_08057B2C:
	adds r0, r1, #0
	cmp r1, #0
	bge _08057B34
	rsbs r0, r1, #0
_08057B34:
	cmp r0, #0x17
	bgt _08057B4C
	movs r2, #1
	cmp r3, #0
	bge _08057B40
	movs r2, #3
_08057B40:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	ldrb r4, [r6, #0xb]
	b _08057B88
_08057B4C:
	movs r0, #0xb
	ldrsb r0, [r6, r0]
	ldrb r4, [r6, #0xb]
	cmp r0, #0
	blt _08057B5C
	movs r0, #1
	ands r0, r4
	b _08057B62
_08057B5C:
	movs r0, #1
	mov r7, r8
	ands r0, r7
_08057B62:
	cmp r0, #0
	bne _08057B78
	movs r2, #1
	cmp r3, #0
	bge _08057B6E
	movs r2, #3
_08057B6E:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	b _08057B88
_08057B78:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
_08057B82:
	cmp r3, #0
	bge _08057B88
	movs r5, #3
_08057B88:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08057B9E
	movs r0, #1
	adds r1, r5, #0
	ands r1, r0
	ands r0, r4
	cmp r1, r0
	bne _08057B9E
	movs r5, #0xb
	ldrsb r5, [r6, r5]
_08057B9E:
	str r6, [sp, #0x10]
	mov r8, r2
	mov sl, r5
	ldrb r0, [r6, #6]
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x20
	str r1, [sp, #0x14]
_08057BAE:
	ldr r0, [sp, #0x10]
	adds r0, #0x68
	ldrh r0, [r0]
	ldr r1, _08057BE4 @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #0x6c
	ldrh r0, [r0]
	add r4, sp, #4
	ldr r2, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	movs r0, #1
	mov r7, r8
	ands r0, r7
	cmp r0, #0
	bne _08057BF8
	cmp r7, #0
	bne _08057BE8
	ldrh r0, [r4, #4]
	mov r3, sb
	subs r0, r0, r3
	b _08057BEC
	.align 2, 0
_08057BE4: .4byte 0xFFFF0000
_08057BE8:
	ldrh r0, [r4, #4]
	add r0, sb
_08057BEC:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	b _08057C18
_08057BF8:
	mov r7, r8
	cmp r7, #1
	bne _08057C06
	add r0, sp, #4
	ldrh r0, [r0]
	add r0, sb
	b _08057C0E
_08057C06:
	add r0, sp, #4
	ldrh r0, [r0]
	mov r2, sb
	subs r0, r0, r2
_08057C0E:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
_08057C18:
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08057C40
	cmp r1, #0
	blt _08057C40
	ldr r0, _08057C44 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08057C40
	ldr r0, _08057C48 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08057C4C
_08057C40:
	movs r4, #0
	b _08057C5A
	.align 2, 0
_08057C44: .4byte 0x030046A8
_08057C48: .4byte 0x030046AC
_08057C4C:
	ldr r0, _08057C6C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08057C5A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08057C70
	adds r0, #4
	b _08057C7C
	.align 2, 0
_08057C6C: .4byte 0x030046A4
_08057C70:
	ldr r0, _08057CB4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057C7C:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08057D18
	add r7, sp, #4
	adds r0, r7, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08057CAE
	cmp r1, #0
	blt _08057CAE
	ldr r0, _08057CB8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08057CAE
	ldr r0, _08057CBC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08057CC0
_08057CAE:
	movs r4, #0
	b _08057CCE
	.align 2, 0
_08057CB4: .4byte 0x030046A4
_08057CB8: .4byte 0x030046A8
_08057CBC: .4byte 0x030046AC
_08057CC0:
	ldr r0, _08057CE0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08057CCE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08057CE4
	adds r0, #4
	b _08057CF0
	.align 2, 0
_08057CE0: .4byte 0x030046A4
_08057CE4:
	ldr r0, _08057D04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057CF0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08057D08
	cmp r2, #2
	beq _08057D0C
	b _08057D10
	.align 2, 0
_08057D04: .4byte 0x030046A4
_08057D08:
	ldrb r0, [r7, #4]
	b _08057D0E
_08057D0C:
	ldrb r0, [r7]
_08057D0E:
	subs r1, r1, r0
_08057D10:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _08057D2E
_08057D18:
	mov r3, sl
	cmp r3, #0
	blt _08057D28
	mov r8, sl
	movs r7, #1
	rsbs r7, r7, #0
	mov sl, r7
	b _08057BAE
_08057D28:
	movs r2, #1
	rsbs r2, r2, #0
	b _08057D30
_08057D2E:
	mov r2, r8
_08057D30:
	cmp r2, r5
	bne _08057D38
	strb r2, [r6, #0xb]
	b _08057D3C
_08057D38:
	movs r0, #0xff
	strb r0, [r6, #0xb]
_08057D3C:
	cmp r2, #0
	bge _08057D44
	movs r2, #0
	strb r2, [r6, #6]
_08057D44:
	strb r2, [r6, #5]
	movs r3, #0
	ldrb r1, [r6, #5]
	ldrb r0, [r6, #6]
	ldr r2, [sp, #0x14]
	strh r3, [r2, #2]
	cmp r1, #1
	beq _08057D70
	cmp r1, #1
	bgt _08057D5E
	cmp r1, #0
	beq _08057D68
	b _08057D84
_08057D5E:
	cmp r1, #2
	beq _08057D76
	cmp r1, #3
	beq _08057D7C
	b _08057D84
_08057D68:
	strh r3, [r6, #0x20]
	rsbs r0, r0, #0
	strh r0, [r2, #4]
	b _08057D84
_08057D70:
	strh r0, [r6, #0x20]
	strh r3, [r2, #4]
	b _08057D84
_08057D76:
	strh r3, [r6, #0x20]
	strh r0, [r2, #4]
	b _08057D84
_08057D7C:
	rsbs r0, r0, #0
	strh r0, [r6, #0x20]
	ldr r0, [sp, #0x14]
	strh r3, [r0, #4]
_08057D84:
	ldrh r0, [r6, #0x20]
	ldr r1, [sp, #0xc]
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	strh r0, [r2, #0x1c]
	ldrh r0, [r6, #0x24]
	ldrh r3, [r2, #0x20]
	adds r0, r0, r3
	strh r0, [r2, #0x20]
_08057D98:
	ldr r0, [r6, #0x14]
	adds r0, #1
	str r0, [r6, #0x14]
_08057D9E:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
