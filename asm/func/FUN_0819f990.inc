	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r7, [r0]
	ldr r0, _0819FA10 @ =0x00000A8C
	adds r4, r7, r0
	ldr r1, _0819FA14 @ =0x00005291
	adds r0, r4, #0
	bl Video_GetAuxSprite
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r5, r7, r1
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, _0819FA18 @ =0x0000922E
	ldr r1, _0819FA1C @ =0x00003F72
	bl GetFile
	adds r1, r0, #0
	mov r2, r8
	ldr r0, [r2, #0x44]
	adds r0, #0x48
	ldrh r2, [r0, #0xa]
	ldr r0, _0819FA20 @ =0x00000AA8
	adds r4, r7, r0
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl AuxAnim_SetAnim
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0819FA24
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0819FA2C
	.align 2, 0
_0819FA10: .4byte 0x00000A8C
_0819FA14: .4byte 0x00005291
_0819FA18: .4byte 0x0000922E
_0819FA1C: .4byte 0x00003F72
_0819FA20: .4byte 0x00000AA8
_0819FA24:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0819FA2C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0819FA50
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0819FA58
_0819FA50:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0819FA58:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0819FA90 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0819FAC8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0819FA94
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0819FA88
	ldrb r0, [r4, #5]
_0819FA88:
	subs r0, #1
	strh r0, [r4, #8]
	b _0819FAA4
	.align 2, 0
_0819FA90: .4byte 0x0000FFFF
_0819FA94:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0819FAA4
	strh r1, [r4, #8]
_0819FAA4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819FAC8
	movs r0, #1
	strb r0, [r4, #7]
_0819FAC8:
	movs r4, #0xa6
	lsls r4, r4, #4
	adds r1, r7, r4
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	ldr r0, _0819FC28 @ =0x00000A7C
	adds r2, r7, r0
	mov r4, r8
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0819FC2C @ =0x00000A67
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _0819FC30 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _0819FC34 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x8c
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	mov sl, r1
	add r2, sp, #0x1c
	mov sb, r2
	add r6, sp, #0x24
	ldr r0, _0819FC38 @ =0x00000BA8
	adds r4, r7, r0
	movs r5, #2
_0819FB22:
	movs r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _0819FC3C @ =0x00005001
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r4, #0
	ldr r2, _0819FC40 @ =0x00000C98
	adds r1, r7, r2
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	ldr r1, _0819FC44 @ =FUN_0819aa5c
	adds r2, r7, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0819FB22
	ldr r2, _0819FC30 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _0819FC34 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x1c]
	mov r4, sb
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r4, #4]
	movs r0, #0
	str r0, [sp, #0x24]
	ldr r0, [r6, #4]
	ands r0, r2
	str r0, [r6, #4]
	ldr r0, _0819FC48 @ =0x00000AB8
	adds r4, r7, r0
	movs r5, #2
_0819FB9A:
	movs r0, #0x10
	str r0, [sp]
	mov r1, sb
	str r1, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _0819FC4C @ =0x00002401
	movs r3, #0
	bl Hitbox_Init
	movs r0, #0x89
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r0]
	movs r0, #0x8b
	lsls r0, r0, #2
	add r0, r8
	ldrh r2, [r0]
	movs r0, #0x8f
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r0, [sp]
	movs r0, #0x8d
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	adds r0, r4, #0
	ldr r2, _0819FC40 @ =0x00000C98
	adds r1, r7, r2
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	ldr r1, _0819FC50 @ =FUN_0819aa58
	adds r2, r7, #0
	bl Hitbox_SetHandler
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0819FB9A
	ldr r0, _0819FC54 @ =0x00000CBC
	adds r4, r7, r0
	ldr r2, _0819FC28 @ =0x00000A7C
	adds r1, r7, r2
	adds r0, r4, #0
	movs r2, #0
	bl ParticleShadow_Init
	ldr r2, _0819FC58 @ =0x00000CB7
	adds r1, r7, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl ParticleShadow_Hide
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819FC28: .4byte 0x00000A7C
_0819FC2C: .4byte 0x00000A67
_0819FC30: .4byte 0xFFFF0000
_0819FC34: .4byte 0x0000FFFF
_0819FC38: .4byte 0x00000BA8
_0819FC3C: .4byte 0x00005001
_0819FC40: .4byte 0x00000C98
_0819FC44: .4byte FUN_0819aa5c
_0819FC48: .4byte 0x00000AB8
_0819FC4C: .4byte 0x00002401
_0819FC50: .4byte FUN_0819aa58
_0819FC54: .4byte 0x00000CBC
_0819FC58: .4byte 0x00000CB7
