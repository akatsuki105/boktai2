	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r0, _0814E698 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814E69C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814E69E
	.align 2, 0
_0814E698: .4byte 0x0000046D
_0814E69C:
	movs r0, #0
_0814E69E:
	cmp r0, #0
	beq _0814E712
	adds r0, r5, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	ldr r1, _0814E7D8 @ =0x0000046E
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
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
	adds r0, r5, #0
	bl PlayEnemyDeathCry
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r1, _0814E7DC @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0814E7E0 @ =0x0000021E
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	adds r6, #0x8a
	adds r0, r5, r6
	strh r4, [r0]
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_0814E712:
	adds r0, r5, #0
	bl Enemy_ClearDamage
	adds r0, r5, #0
	bl Enemy_UpdateJump
	adds r0, r5, #0
	bl Enemy_SnapToFloor
	ldr r1, _0814E7D8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814E730
	b _0814E8D8
_0814E730:
	subs r1, #0x6e
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _0814E742
	b _0814E8B0
_0814E742:
	ldr r6, _0814E7E4 @ =0x0000046B
	adds r0, r5, r6
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_0814afc8
	movs r0, #0xcd
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _0814E7B0
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r6, #0xa
	ldrsh r0, [r5, r6]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r6, #8
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	str r0, [sp, #0x1c]
	ldr r1, _0814E7E8 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r6, sp
	str r6, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_0814E7B0:
	ldr r1, _0814E7EC @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0814E7F4
	ldr r0, _0814E7F0 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe2
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r1, r4, #0
	lsls r1, r3
	b _0814E806
	.align 2, 0
_0814E7D8: .4byte 0x0000046E
_0814E7DC: .4byte 0xFFFEBE3F
_0814E7E0: .4byte 0x0000021E
_0814E7E4: .4byte 0x0000046B
_0814E7E8: .4byte 0xFFFF0000
_0814E7EC: .4byte 0x000001DF
_0814E7F0: .4byte 0x030046A0
_0814E7F4:
	ldr r0, _0814E890 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0814E806:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0814E86E
	ldr r3, _0814E894 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r6, _0814E898 @ =0x0000046D
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r2, #0
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _0814E89C @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
_0814E86E:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl ParticleShadow_Hide
	movs r2, #1
	ldr r1, _0814E8A0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814E8A4
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0814E8D8
	.align 2, 0
_0814E890: .4byte 0x030046A0
_0814E894: .4byte Enemy_ClearStateBegun
_0814E898: .4byte 0x0000046D
_0814E89C: .4byte 0x0000046A
_0814E8A0: .4byte 0x0000025D
_0814E8A4:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	b _0814E8D8
_0814E8B0:
	ldr r3, _0814E8E0 @ =FUN_0814e8ec
	movs r2, #0x26
	ldr r6, _0814E8E4 @ =0x0000046D
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814E8E8 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
_0814E8D8:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814E8E0: .4byte FUN_0814e8ec
_0814E8E4: .4byte 0x0000046D
_0814E8E8: .4byte 0x0000046B
