	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r5, r0, #0
	ldr r0, _081A8048 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A804C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A804E
	.align 2, 0
_081A8048: .4byte 0x0000046D
_081A804C:
	movs r0, #0
_081A804E:
	cmp r0, #0
	beq _081A80B4
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r5, #0
	movs r1, #4
	bl Enemy_FadeParticles
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _081A81C4 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081A81C8 @ =0x0000021E
	adds r0, r5, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	ldr r4, _081A81CC @ =0x00000202
	adds r0, r5, r4
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081A81D0 @ =0x000003DB
	bl PlaySound_082406e0
_081A80B4:
	adds r4, r5, #0
	adds r4, #8
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	movs r3, #0x80
	bl SpawnAttackBox
	ldr r0, _081A81D4 @ =0x0000046D
	adds r0, r5, r0
	str r0, [sp, #0x40]
	adds r6, r4, #0
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r7, r5, r1
	ldr r2, _081A81D8 @ =0x000001DF
	adds r2, r2, r5
	mov sb, r2
	movs r3, #0x90
	lsls r3, r3, #3
	adds r3, r3, r5
	mov r8, r3
	ldr r4, _081A81DC @ =0x0000046B
	adds r4, r5, r4
	str r4, [sp, #0x38]
	ldr r0, _081A81E0 @ =0x00000553
	adds r0, r5, r0
	str r0, [sp, #0x48]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x50]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r2, r5, r2
	str r2, [sp, #0x4c]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r5, r3
	str r3, [sp, #0x54]
	ldr r4, _081A81E4 @ =0x00000469
	adds r4, r5, r4
	str r4, [sp, #0x58]
	ldr r0, _081A81E8 @ =0x0000046A
	adds r0, r5, r0
	str r0, [sp, #0x34]
	ldr r1, _081A81EC @ =0x00000484
	adds r1, r5, r1
	str r1, [sp, #0x44]
	ldr r2, _081A81F0 @ =0x0000046C
	adds r2, r5, r2
	str r2, [sp, #0x3c]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r3, r3, r5
	mov sl, r3
	movs r4, #0xb
_081A8132:
	adds r0, r6, #0
	bl Salamander_SpawnFireDebris
	subs r4, #1
	cmp r4, #0
	bge _081A8132
	adds r0, r5, #0
	bl Salamander_DestroyAllSegments
	ldrh r0, [r7]
	cmp r0, #0
	beq _081A81A0
	movs r4, #8
	ldrsh r0, [r5, r4]
	str r0, [sp, #0xc]
	movs r1, #0xa
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x10]
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	str r0, [sp, #0x14]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0x18]
	movs r4, #0xd0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r2, #0x94
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldrh r0, [r5]
	str r0, [sp, #0x28]
	ldr r1, _081A81F4 @ =0xFFFF0000
	ldr r0, [sp, #0x2c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x2c]
	add r1, sp, #0x2c
	add r3, sp, #0xc
	str r3, [r1, #4]
	ldrh r0, [r7]
	bl VM_ExecByID
_081A81A0:
	mov r4, sb
	ldrb r0, [r4]
	mov r2, r8
	ldrh r1, [r2]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081A81FC
	ldr r0, _081A81F8 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	movs r1, #1
	lsls r1, r3
	b _081A820E
	.align 2, 0
_081A81C4: .4byte 0xFFFEBE3F
_081A81C8: .4byte 0x0000021E
_081A81CC: .4byte 0x00000202
_081A81D0: .4byte 0x000003DB
_081A81D4: .4byte 0x0000046D
_081A81D8: .4byte 0x000001DF
_081A81DC: .4byte 0x0000046B
_081A81E0: .4byte 0x00000553
_081A81E4: .4byte 0x00000469
_081A81E8: .4byte 0x0000046A
_081A81EC: .4byte 0x00000484
_081A81F0: .4byte 0x0000046C
_081A81F4: .4byte 0xFFFF0000
_081A81F8: .4byte 0x030046A0
_081A81FC:
	ldr r0, _081A826C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_081A820E:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r3, _081A8270 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	movs r0, #0
	movs r2, #1
	ldr r4, [sp, #0x40]
	strb r2, [r4]
	ldr r4, [sp, #0x38]
	strb r0, [r4]
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r1, [sp, #0x50]
	str r3, [r1]
	movs r3, #0
	ldr r4, [sp, #0x4c]
	strh r0, [r4]
	movs r1, #2
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r4, [sp, #0x58]
	strb r3, [r4]
	ldr r3, [sp, #0x34]
	strb r1, [r3]
	ldr r4, [sp, #0x44]
	str r0, [r4]
	ldr r0, [sp, #0x3c]
	strb r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	mov r3, sl
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r4, _081A8274 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A826C: .4byte 0x030046A0
_081A8270: .4byte Enemy_ClearStateBegun
_081A8274: .4byte 0x0000046B
