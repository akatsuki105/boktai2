	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	str r0, [sp, #0x48]
	adds r0, #0x48
	mov r8, r0
	ldr r2, _081B1A60 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B1A64
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B1A66
	.align 2, 0
_081B1A60: .4byte 0x0000046D
_081B1A64:
	movs r0, #0
_081B1A66:
	cmp r0, #0
	beq _081B1AFE
	adds r0, r7, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	ldr r4, _081B1B90 @ =0x0000046E
	adds r0, r7, r4
	movs r4, #0
	strb r4, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #4
	bl Enemy_FadeParticles
	ldr r1, [sp, #0x48]
	ldr r0, [r1]
	movs r1, #2
	orrs r0, r1
	ldr r2, [sp, #0x48]
	str r0, [r2]
	adds r0, r7, #0
	bl PlayEnemyDeathCry
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B1AD0
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081B1AD0:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _081B1B94 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081B1B98 @ =0x0000021E
	adds r0, r7, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r4, [r0]
	subs r1, #0x1c
	adds r0, r7, r1
	strh r4, [r0]
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081B1AFE:
	adds r0, r7, #0
	bl Enemy_ClearDamage
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _081B1B74
	movs r5, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _081B1B74
	ldr r3, _081B1B9C @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r3
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _081B1BA0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x30]
	add r2, sp, #0x30
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	ldr r3, _081B1BA4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081B1BA8 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r4, _081B1BAC @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r4, #0xa
	str r4, [sp]
	str r5, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl EmitSmoke
_081B1B74:
	cmp r6, #0x22
	bgt _081B1B7E
	movs r0, #0
	mov r6, r8
	strh r0, [r6, #0xe]
_081B1B7E:
	mov r1, r8
	ldrh r0, [r1, #8]
	cmp r0, #2
	bhi _081B1BB0
	movs r0, #0x46
	ldr r2, [sp, #0x48]
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	b _081B1BB8
	.align 2, 0
_081B1B90: .4byte 0x0000046E
_081B1B94: .4byte 0xFFFEBE3F
_081B1B98: .4byte 0x0000021E
_081B1B9C: .4byte 0xFFFF0000
_081B1BA0: .4byte 0x0000FFFF
_081B1BA4: .4byte 0x030046B8
_081B1BA8: .4byte 0x000003FF
_081B1BAC: .4byte 0x0203B400
_081B1BB0:
	movs r0, #0x40
	ldr r4, [sp, #0x48]
	strb r0, [r4, #8]
	strb r0, [r4, #9]
_081B1BB8:
	ldr r6, _081B1DF0 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B1BC4
	b _081B1E9E
_081B1BC4:
	ldr r1, _081B1DF4 @ =0x0000046B
	adds r0, r7, r1
	movs r2, #1
	strb r2, [r0]
	subs r1, #0x6b
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	ands r0, r1
	ldr r6, _081B1DF8 @ =0x000001DF
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	cmp r0, #0
	beq _081B1BE4
	b _081B1D66
_081B1BE4:
	adds r0, r7, #0
	bl FUN_080e6658
	ldr r2, _081B1DFC @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _081B1E00 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x38]
	add r5, sp, #0x38
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _081B1E04 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r6, #3
	ands r1, r6
	adds r1, #1
	adds r6, r7, #0
	adds r6, #8
	movs r0, #4
	mov sb, r0
	str r0, [sp]
	movs r2, #0x14
	mov r8, r2
	str r2, [sp, #4]
	movs r0, #2
	mov sl, r0
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x40
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x5e
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x80
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xc4
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081B1E08 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081B1E0C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r4, #3
	ands r1, r4
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r4, sl
	str r4, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xf0
	bl EmitSmoke
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	cmp r0, #4
	beq _081B1D60
	cmp r0, #1
	beq _081B1D60
	cmp r0, #5
	beq _081B1D60
	cmp r0, #7
	beq _081B1D60
	cmp r0, #6
	beq _081B1D60
	cmp r0, #0x18
	bne _081B1D66
_081B1D60:
	movs r0, #0xe5
	bl PlaySound_082406e0
_081B1D66:
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r0, [r2]
	cmp r0, #0
	beq _081B1DC8
	movs r6, #8
	ldrsh r0, [r7, r6]
	str r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x14]
	movs r4, #0xc
	ldrsh r0, [r7, r4]
	str r0, [sp, #0x18]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r4, #0xd2
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r6, #0x94
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r7]
	str r0, [sp, #0x2c]
	ldr r1, _081B1DFC @ =0xFFFF0000
	ldr r0, [sp, #0x40]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x40]
	add r1, sp, #0x40
	add r0, sp, #0x10
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_081B1DC8:
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081B1E14
	ldr r0, _081B1E10 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	movs r1, #1
	lsls r1, r3
	b _081B1E26
	.align 2, 0
_081B1DF0: .4byte 0x0000046E
_081B1DF4: .4byte 0x0000046B
_081B1DF8: .4byte 0x000001DF
_081B1DFC: .4byte 0xFFFF0000
_081B1E00: .4byte 0x0000FFFF
_081B1E04: .4byte 0x030046B8
_081B1E08: .4byte 0x000003FF
_081B1E0C: .4byte 0x0203B400
_081B1E10: .4byte 0x030046A0
_081B1E14:
	ldr r0, _081B1EB0 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe3
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_081B1E26:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r5, #0
	movs r3, #0
	strh r3, [r0]
	movs r0, #0x40
	ldr r2, [sp, #0x48]
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r4, _081B1EB4 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r6, _081B1EB8 @ =0x0000046D
	adds r0, r7, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r3, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r4, _081B1EBC @ =0x00000469
	adds r0, r7, r4
	strb r5, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r2, [r0]
	ldr r2, _081B1EC0 @ =0x00000484
	adds r0, r7, r2
	str r3, [r0]
	adds r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r7, r6
	bl ParticleShadow_Hide
_081B1E9E:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B1EB0: .4byte 0x030046A0
_081B1EB4: .4byte Enemy_ClearStateBegun
_081B1EB8: .4byte 0x0000046D
_081B1EBC: .4byte 0x00000469
_081B1EC0: .4byte 0x00000484
