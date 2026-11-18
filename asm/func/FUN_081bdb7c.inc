	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r7, r0, #0
	ldr r0, _081BDB9C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BDBA0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BDBA2
	.align 2, 0
_081BDB9C: .4byte 0x0000046D
_081BDBA0:
	movs r0, #0
_081BDBA2:
	cmp r0, #0
	beq _081BDC18
	adds r0, r7, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	ldr r1, _081BDCC0 @ =0x0000046E
	adds r0, r7, r1
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
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _081BDCC4 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081BDCC8 @ =0x0000021E
	adds r0, r7, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r4, [r0]
	adds r5, #0x8a
	adds r0, r7, r5
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #1
	bl PlayGolemSound
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081BDC18:
	adds r0, r7, #0
	bl Enemy_ClearDamage
	ldr r1, _081BDCC0 @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BDC2A
	b _081BDF32
_081BDC2A:
	ldr r2, _081BDCCC @ =0x0000046B
	adds r0, r7, r2
	movs r5, #1
	strb r5, [r0]
	adds r0, r7, #0
	bl FUN_080e6658
	movs r0, #0xcd
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _081BDC96
	movs r1, #8
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x14]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x18]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	adds r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r7]
	str r0, [sp, #0x2c]
	ldr r1, _081BDCD0 @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x30]
	add r1, sp, #0x30
	add r0, sp, #0x10
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_081BDC96:
	ldr r1, _081BDCD4 @ =0x000001DF
	adds r4, r7, r1
	ldrb r0, [r4]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	str r4, [sp, #0x40]
	cmp r3, #0x1f
	bgt _081BDCDC
	ldr r0, _081BDCD8 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r5, #0
	lsls r1, r3
	b _081BDCEE
	.align 2, 0
_081BDCC0: .4byte 0x0000046E
_081BDCC4: .4byte 0xFFFEBE3F
_081BDCC8: .4byte 0x0000021E
_081BDCCC: .4byte 0x0000046B
_081BDCD0: .4byte 0xFFFF0000
_081BDCD4: .4byte 0x000001DF
_081BDCD8: .4byte 0x030046A0
_081BDCDC:
	ldr r0, _081BDEF0 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r5, #0
	lsls r1, r0
_081BDCEE:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081BDD08
	b _081BDE84
_081BDD08:
	ldr r2, _081BDEF4 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _081BDEF8 @ =0x0000FFFF
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
	ldr r4, _081BDEFC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r6, r7, #0
	adds r6, #8
	movs r2, #4
	str r2, [sp]
	movs r0, #0x14
	mov sb, r0
	str r0, [sp, #4]
	movs r2, #2
	mov r8, r2
	str r2, [sp, #8]
	movs r0, #1
	mov sl, r0
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x40
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x5e
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x80
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xc4
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xf0
	bl EmitSmoke
	ldr r1, [sp, #0x40]
	ldrb r4, [r1]
	cmp r4, #4
	beq _081BDE7E
	cmp r4, #1
	beq _081BDE7E
	cmp r4, #5
	beq _081BDE7E
	cmp r4, #7
	beq _081BDE7E
	cmp r4, #6
	beq _081BDE7E
	cmp r4, #0x18
	bne _081BDE84
_081BDE7E:
	movs r0, #0xe5
	bl PlaySound_082406e0
_081BDE84:
	ldr r3, _081BDF08 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r5, _081BDF0C @ =0x0000046D
	adds r0, r7, r5
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r1, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r2, #0
	strh r1, [r0]
	movs r3, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #1
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _081BDF10 @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r1, [r0]
	ldr r1, _081BDF14 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r7, r2
	bl ParticleShadow_Hide
	ldr r5, _081BDF18 @ =0x0000025D
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BDF1C
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	b _081BDF26
	.align 2, 0
_081BDEF0: .4byte 0x030046A0
_081BDEF4: .4byte 0xFFFF0000
_081BDEF8: .4byte 0x0000FFFF
_081BDEFC: .4byte 0x030046B8
_081BDF00: .4byte 0x000003FF
_081BDF04: .4byte 0x0203B400
_081BDF08: .4byte Enemy_ClearStateBegun
_081BDF0C: .4byte 0x0000046D
_081BDF10: .4byte 0x0000046A
_081BDF14: .4byte 0x0000046C
_081BDF18: .4byte 0x0000025D
_081BDF1C:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r4
	str r0, [r1, #8]
_081BDF26:
	adds r0, r7, #0
	bl Golem_ScatterDebris
	adds r0, r7, #0
	bl PlayEnemyDeathCry
_081BDF32:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
