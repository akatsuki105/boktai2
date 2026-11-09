	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x48
	adds r6, r0, #0
	mov sb, r1
	ldr r0, _081340F4 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081340F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081340FA
	.align 2, 0
_081340F4: .4byte 0x0000046D
_081340F8:
	movs r0, #0
_081340FA:
	cmp r0, #0
	bne _08134100
	b _08134248
_08134100:
	ldrb r0, [r6, #5]
	add r1, sp, #0x30
	add r2, sp, #0x34
	bl Centipede_GetAnimVariant
	ldr r1, _08134140 @ =0x00000504
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #0x30]
	ldr r4, [sp, #0x34]
	ldr r7, _08134144 @ =0x0000025D
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813414C
	subs r1, #0x4d
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _08134148 @ =0x0000046E
	adds r7, r6, r2
	b _081341CE
	.align 2, 0
_08134140: .4byte 0x00000504
_08134144: .4byte 0x0000025D
_08134148: .4byte 0x0000046E
_0813414C:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r3, _081341BC @ =0x000004B7
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081341C0 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _08134186
	ldrb r0, [r7]
	cmp r0, #0
	bne _08134186
	cmp r4, #1
	bne _08134178
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081341D2
_08134178:
	cmp r4, #0
	bne _08134186
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081341D2
_08134186:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08134198
	movs r3, #6
_08134198:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081341C4
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _081341CC
	.align 2, 0
_081341BC: .4byte 0x000004B7
_081341C0: .4byte 0x0000046E
_081341C4:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081341CC:
	str r0, [r5, #8]
_081341CE:
	movs r0, #0
	strb r0, [r7]
_081341D2:
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	movs r1, #0x12
	bl FUN_0813652c
	ldr r4, _08134380 @ =0x0000046E
	adds r0, r6, r4
	movs r4, #0
	strb r4, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r6, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r6, #0
	movs r1, #4
	bl Enemy_FadeParticles
	adds r0, r6, #0
	bl PlayEnemyDeathCry
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r1, _08134384 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08134388 @ =0x0000021E
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r4, [r0]
	ldr r3, _0813438C @ =0x00000202
	adds r0, r6, r3
	strh r4, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_08134248:
	mov r0, sb
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081342AA
	ldr r3, _08134390 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r3
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _08134394 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x38]
	add r2, sp, #0x38
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	ldr r3, _08134398 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0813439C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r4, _081343A0 @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r6, #0
	adds r0, #8
	ldrb r3, [r6, #5]
	adds r3, #0x80
	movs r4, #0xa
	str r4, [sp]
	movs r4, #8
	str r4, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl EmitSmoke
_081342AA:
	adds r0, r6, #0
	mov r1, sb
	bl FUN_08136720
	ldr r0, [r6, #0x44]
	mov r1, sb
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081342C6
	b _08134426
_081342C6:
	ldr r7, _081343A4 @ =0x0000046B
	adds r0, r6, r7
	movs r4, #1
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_081378fc
	adds r0, r6, #0
	adds r0, #8
	bl FUN_08138504
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081342F4
	adds r0, r6, #0
	bl FUN_080e6658
_081342F4:
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _08134356
	movs r7, #8
	ldrsh r0, [r6, r7]
	str r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	str r0, [sp, #0x14]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
	str r0, [sp, #0x18]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r6]
	str r0, [sp, #0x2c]
	ldr r1, _08134390 @ =0xFFFF0000
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
_08134356:
	ldr r1, _081343A8 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081343B0
	ldr r0, _081343AC @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _081343C2
	.align 2, 0
_08134380: .4byte 0x0000046E
_08134384: .4byte 0xFFFEBE3F
_08134388: .4byte 0x0000021E
_0813438C: .4byte 0x00000202
_08134390: .4byte 0xFFFF0000
_08134394: .4byte 0x0000FFFF
_08134398: .4byte 0x030046B8
_0813439C: .4byte 0x000003FF
_081343A0: .4byte 0x0203B400
_081343A4: .4byte 0x0000046B
_081343A8: .4byte 0x000001DF
_081343AC: .4byte 0x030046A0
_081343B0:
	ldr r0, _08134434 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_081343C2:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _08134438 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r7, _0813443C @ =0x0000046D
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _08134440 @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _08134444 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r6, r7
	bl ParticleShadow_Hide
_08134426:
	add sp, #0x48
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08134434: .4byte 0x030046A0
_08134438: .4byte Enemy_ClearStateBegun
_0813443C: .4byte 0x0000046D
_08134440: .4byte 0x00000469
_08134444: .4byte 0x00000484
