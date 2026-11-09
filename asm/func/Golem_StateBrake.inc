	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	mov sl, r6
	ldr r2, _08118DC8 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08118DCC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08118DCE
	.align 2, 0
_08118DC8: .4byte 0x0000046D
_08118DCC:
	movs r0, #0
_08118DCE:
	cmp r0, #0
	bne _08118DD4
	b _08118ED8
_08118DD4:
	ldrb r5, [r6, #5]
	ldr r0, _08118E30 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	strb r0, [r6, #5]
	mov r4, sp
	adds r4, #5
	adds r0, r6, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	strb r5, [r6, #5]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _08118E34 @ =0x085AD608
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _08118E38 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08118E44
	ldr r2, _08118E3C @ =0x000004B7
	adds r0, r6, r2
	mov r1, ip
	strb r1, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl AuxAnim_SetAnim
	ldr r2, _08118E40 @ =0x0000046E
	adds r7, r6, r2
	b _08118EC6
	.align 2, 0
_08118E30: .4byte 0x000006C5
_08118E34: .4byte 0x085AD608
_08118E38: .4byte 0x0000025D
_08118E3C: .4byte 0x000004B7
_08118E40: .4byte 0x0000046E
_08118E44:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov ip, r3
	ldr r3, _08118EB4 @ =0x000004B7
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _08118EB8 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, ip
	bne _08118E80
	ldrb r0, [r7]
	cmp r0, #0
	bne _08118E80
	cmp r4, #1
	bne _08118E72
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08118ECA
_08118E72:
	cmp r4, #0
	bne _08118E80
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08118ECA
_08118E80:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov sb, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _08118E94
	movs r3, #6
_08118E94:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08118EBC
	ldr r0, [r5, #8]
	mov r3, sb
	orrs r0, r3
	b _08118EC4
	.align 2, 0
_08118EB4: .4byte 0x000004B7
_08118EB8: .4byte 0x0000046E
_08118EBC:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08118EC4:
	str r0, [r5, #8]
_08118EC6:
	movs r0, #0
	strb r0, [r7]
_08118ECA:
	ldr r1, _08118F20 @ =0x0000046E
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08118F24 @ =0x000006C3
	add r0, r8
	strb r1, [r0]
_08118ED8:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08118F28 @ =gSineTable
	ldr r0, _08118F2C @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, _08118F30 @ =0x000006B6
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08118F34
	asrs r0, r0, #0x10
	b _08118F3A
	.align 2, 0
_08118F20: .4byte 0x0000046E
_08118F24: .4byte 0x000006C3
_08118F28: .4byte gSineTable
_08118F2C: .4byte 0x000006C5
_08118F30: .4byte 0x000006B6
_08118F34:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_08118F3A:
	adds r3, r0, #0
	ldr r0, _08118F5C @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08118F60 @ =0x000006B6
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08118F64
	asrs r0, r0, #0x10
	b _08118F6A
	.align 2, 0
_08118F5C: .4byte 0x000006C5
_08118F60: .4byte 0x000006B6
_08118F64:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_08118F6A:
	adds r2, r3, #0
	cmp r3, #0
	bge _08118F72
	rsbs r2, r3, #0
_08118F72:
	adds r1, r0, #0
	cmp r0, #0
	bge _08118F7A
	rsbs r1, r0, #0
_08118F7A:
	cmp r2, r1
	bge _08118F84
	mov r3, sl
	strh r0, [r3, #0x14]
	b _08118F88
_08118F84:
	mov r0, sl
	strh r3, [r0, #0x10]
_08118F88:
	ldr r2, _08118FB8 @ =0x000006B6
	add r2, r8
	ldrh r1, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bgt _08118FC4
	movs r3, #0
	strh r3, [r2]
	ldr r1, _08118FBC @ =0x000006C3
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _08118FCA
	ldr r0, _08118FC0 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	strh r3, [r2]
	b _08118FCA
	.align 2, 0
_08118FB8: .4byte 0x000006B6
_08118FBC: .4byte 0x000006C3
_08118FC0: .4byte 0x0000046B
_08118FC4:
	adds r0, r1, #0
	subs r0, #0x10
	strh r0, [r2]
_08118FCA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
