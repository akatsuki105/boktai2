	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r7, r0, #0
	ldr r0, _0811AA88 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811AA8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811AA8E
	.align 2, 0
_0811AA88: .4byte 0x0000046D
_0811AA8C:
	movs r0, #0
_0811AA8E:
	cmp r0, #0
	beq _0811AB04
	adds r0, r7, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	ldr r1, _0811ABAC @ =0x0000046E
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
	ldr r1, _0811ABB0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0811ABB4 @ =0x0000021E
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
_0811AB04:
	adds r0, r7, #0
	bl Enemy_ClearDamage
	ldr r1, _0811ABAC @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811AB16
	b _0811AE1E
_0811AB16:
	ldr r2, _0811ABB8 @ =0x0000046B
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
	beq _0811AB82
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
	ldr r1, _0811ABBC @ =0xFFFF0000
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
_0811AB82:
	ldr r1, _0811ABC0 @ =0x000001DF
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
	bgt _0811ABC8
	ldr r0, _0811ABC4 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r5, #0
	lsls r1, r3
	b _0811ABDA
	.align 2, 0
_0811ABAC: .4byte 0x0000046E
_0811ABB0: .4byte 0xFFFEBE3F
_0811ABB4: .4byte 0x0000021E
_0811ABB8: .4byte 0x0000046B
_0811ABBC: .4byte 0xFFFF0000
_0811ABC0: .4byte 0x000001DF
_0811ABC4: .4byte 0x030046A0
_0811ABC8:
	ldr r0, _0811ADDC @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r5, #0
	lsls r1, r0
_0811ABDA:
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
	beq _0811ABF4
	b _0811AD70
_0811ABF4:
	ldr r2, _0811ADE0 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _0811ADE4 @ =0x0000FFFF
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
	ldr r4, _0811ADE8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
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
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
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
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
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
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
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
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
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
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
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
	beq _0811AD6A
	cmp r4, #1
	beq _0811AD6A
	cmp r4, #5
	beq _0811AD6A
	cmp r4, #7
	beq _0811AD6A
	cmp r4, #6
	beq _0811AD6A
	cmp r4, #0x18
	bne _0811AD70
_0811AD6A:
	movs r0, #0xe5
	bl PlaySound_082406e0
_0811AD70:
	ldr r3, _0811ADF4 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r5, _0811ADF8 @ =0x0000046D
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
	ldr r2, _0811ADFC @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r1, [r0]
	ldr r1, _0811AE00 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r7, r2
	bl ParticleShadow_Hide
	ldr r5, _0811AE04 @ =0x0000025D
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811AE08
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	b _0811AE12
	.align 2, 0
_0811ADDC: .4byte 0x030046A0
_0811ADE0: .4byte 0xFFFF0000
_0811ADE4: .4byte 0x0000FFFF
_0811ADE8: .4byte 0x030046B8
_0811ADEC: .4byte 0x000003FF
_0811ADF0: .4byte 0x0203B400
_0811ADF4: .4byte Enemy_ClearStateBegun
_0811ADF8: .4byte 0x0000046D
_0811ADFC: .4byte 0x0000046A
_0811AE00: .4byte 0x0000046C
_0811AE04: .4byte 0x0000025D
_0811AE08:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r4
	str r0, [r1, #8]
_0811AE12:
	adds r0, r7, #0
	bl FUN_080f8ae0
	adds r0, r7, #0
	bl PlayEnemyDeathCry
_0811AE1E:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
