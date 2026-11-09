	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldr r0, _08124D20 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08124D24
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08124D26
	.align 2, 0
_08124D20: .4byte 0x0000046D
_08124D24:
	movs r0, #0
_08124D26:
	cmp r0, #0
	beq _08124E00
	movs r1, #0x80
	lsls r1, r1, #0xa
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08124D66
	ldr r3, _08124D54 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08124D58
	ldr r2, [r7, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08124D66
	.align 2, 0
_08124D54: .4byte 0x0000025D
_08124D58:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_08124D66:
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _08124EE0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08124EE4 @ =0x0000021E
	adds r0, r7, r1
	movs r5, #0
	movs r4, #0
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r4, [r0]
	ldr r3, _08124EE8 @ =0x00000202
	adds r0, r7, r3
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	ldr r1, _08124EEC @ =0x0000046E
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _08124EF0 @ =0x00000494
	adds r1, r7, r2
	movs r0, #0x20
	strh r0, [r1]
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
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r4, [r0]
	adds r0, r7, #0
	bl PlayEnemyDeathCry
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08124DF4
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08124DF4:
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
_08124E00:
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _08124E70
	movs r5, #8
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _08124E70
	ldr r3, _08124EF4 @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r3
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _08124EF8 @ =0x0000FFFF
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
	ldr r3, _08124EFC @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _08124F00 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08124F04 @ =0x0203B400
	adds r0, r0, r1
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
_08124E70:
	cmp r6, #0x22
	bgt _08124E7A
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0xe]
_08124E7A:
	adds r0, r7, #0
	bl Enemy_UpdateJump
	adds r0, r7, #0
	bl Enemy_SnapToFloor
	ldr r3, _08124EEC @ =0x0000046E
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08124E92
	b _081251E4
_08124E92:
	ldr r5, _08124F08 @ =0x0000046B
	adds r0, r7, r5
	movs r6, #1
	strb r6, [r0]
	movs r4, #0x80
	lsls r4, r4, #3
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ands r0, r4
	ldr r2, _08124F0C @ =0x000001DF
	adds r2, r7, r2
	str r2, [sp, #0x48]
	cmp r0, #0
	beq _08124EB4
	b _08125090
_08124EB4:
	ldr r1, _08124F10 @ =0x0000A007
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08124F14
	adds r0, r7, #0
	bl Mummy_Explode
	movs r5, #8
	ldrsh r0, [r7, r5]
	movs r6, #0xc
	ldrsh r1, [r7, r6]
	movs r2, #1
	str r2, [sp]
	adds r2, r4, #0
	movs r3, #0
	bl FUN_08240cc4
	b _08125090
	.align 2, 0
_08124EE0: .4byte 0xFFFEBE3F
_08124EE4: .4byte 0x0000021E
_08124EE8: .4byte 0x00000202
_08124EEC: .4byte 0x0000046E
_08124EF0: .4byte 0x00000494
_08124EF4: .4byte 0xFFFF0000
_08124EF8: .4byte 0x0000FFFF
_08124EFC: .4byte 0x030046B8
_08124F00: .4byte 0x000003FF
_08124F04: .4byte 0x0203B400
_08124F08: .4byte 0x0000046B
_08124F0C: .4byte 0x000001DF
_08124F10: .4byte 0x0000A007
_08124F14:
	ldr r2, _0812511C @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _08125120 @ =0x0000FFFF
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
	ldr r4, _08125124 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _08125128 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r6, _0812512C @ =0x0203B400
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r6, r7, #0
	adds r6, #8
	movs r2, #4
	mov sb, r2
	str r2, [sp]
	movs r3, #0x14
	mov r8, r3
	str r3, [sp, #4]
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
	ldr r3, _08125128 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0812512C @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #3
	ands r1, r2
	adds r1, #1
	mov r3, sb
	str r3, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x40
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08125128 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0812512C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x5e
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08125128 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0812512C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x80
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08125128 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0812512C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xc4
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08125128 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0812512C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xf0
	bl EmitSmoke
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	cmp r0, #4
	beq _0812508A
	cmp r0, #1
	beq _0812508A
	cmp r0, #5
	beq _0812508A
	cmp r0, #7
	beq _0812508A
	cmp r0, #6
	beq _0812508A
	cmp r0, #0x18
	bne _08125090
_0812508A:
	movs r0, #0xe5
	bl PlaySound_082406e0
_08125090:
	adds r0, r7, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081250F6
	movs r5, #8
	ldrsh r0, [r7, r5]
	str r0, [sp, #0x10]
	movs r6, #0xa
	ldrsh r0, [r7, r6]
	str r0, [sp, #0x14]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x18]
	adds r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r5, #0xd0
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r6, #0xd2
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r7]
	str r0, [sp, #0x2c]
	ldr r1, _0812511C @ =0xFFFF0000
	ldr r0, [sp, #0x40]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x40]
	add r1, sp, #0x40
	add r3, sp, #0x10
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_081250F6:
	ldr r5, [sp, #0x48]
	ldrb r0, [r5]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r1, r7, r6
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08125134
	ldr r0, _08125130 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #1
	lsls r1, r3
	b _08125146
	.align 2, 0
_0812511C: .4byte 0xFFFF0000
_08125120: .4byte 0x0000FFFF
_08125124: .4byte 0x030046B8
_08125128: .4byte 0x000003FF
_0812512C: .4byte 0x0203B400
_08125130: .4byte 0x030046A0
_08125134:
	ldr r0, _081251B4 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_08125146:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r4, #0
	movs r1, #0
	strh r1, [r0]
	ldr r3, _081251B8 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r5, _081251BC @ =0x0000046D
	adds r0, r7, r5
	movs r5, #1
	strb r5, [r0]
	ldr r6, _081251C0 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r7, r6
	strb r5, [r0]
	ldr r3, _081251C4 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r2, [r0]
	ldr r2, _081251C8 @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	ldr r6, _081251CC @ =0x0000025D
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081251D0
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	b _081251DA
	.align 2, 0
_081251B4: .4byte 0x030046A0
_081251B8: .4byte Enemy_ClearStateBegun
_081251BC: .4byte 0x0000046D
_081251C0: .4byte 0x0000046B
_081251C4: .4byte 0x00000469
_081251C8: .4byte 0x00000484
_081251CC: .4byte 0x0000025D
_081251D0:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r5
	str r0, [r1, #8]
_081251DA:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r7, r1
	bl ParticleShadow_Hide
_081251E4:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
