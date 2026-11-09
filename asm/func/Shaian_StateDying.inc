	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _081808D0 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081808D4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081808D6
	.align 2, 0
_081808D0: .4byte 0x0000046D
_081808D4:
	movs r0, #0
_081808D6:
	cmp r0, #0
	bne _081808DC
	b _08180A3C
_081808DC:
	adds r0, r6, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	ldr r7, _08180900 @ =0x0000046E
	adds r1, r6, r7
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r2, _08180904 @ =0x00000898
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08180908
	movs r0, #1
	b _0818090A
	.align 2, 0
_08180900: .4byte 0x0000046E
_08180904: .4byte 0x00000898
_08180908:
	movs r0, #0
_0818090A:
	cmp r0, #0
	beq _08180918
	movs r7, #0xf6
	lsls r7, r7, #3
	adds r1, r4, r7
	movs r0, #0x1e
	strh r0, [r1]
_08180918:
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
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08180A0C @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08180A10 @ =0x0000021E
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	ldr r4, _08180A14 @ =0x00000202
	adds r0, r6, r4
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xd8
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	bl Entity081f7de4_RemoveAll
	bl FUN_080e0214
	movs r7, #0xcd
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r0, [r2]
	cmp r0, #0
	beq _081809E4
	movs r1, #8
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r4, #0xa
	ldrsh r0, [r6, r4]
	str r0, [sp, #4]
	movs r7, #0xc
	ldrsh r0, [r6, r7]
	str r0, [sp, #8]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r4, #0xd0
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r7, #0xd2
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _08180A18 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r4, sp
	str r4, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_081809E4:
	ldr r7, _08180A1C @ =0x000001DF
	adds r0, r6, r7
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08180A24
	ldr r0, _08180A20 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	movs r1, #1
	lsls r1, r3
	b _08180A36
	.align 2, 0
_08180A0C: .4byte 0xFFFEBE3F
_08180A10: .4byte 0x0000021E
_08180A14: .4byte 0x00000202
_08180A18: .4byte 0xFFFF0000
_08180A1C: .4byte 0x000001DF
_08180A20: .4byte 0x030046A0
_08180A24:
	ldr r0, _08180AB8 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe3
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_08180A36:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08180A3C:
	adds r0, r6, #0
	bl Enemy_ClearDamage
	ldr r1, _08180ABC @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08180AB0
	ldr r2, _08180AC0 @ =0x0000046B
	adds r0, r6, r2
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	movs r4, #0xc9
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r5, #0
	strh r3, [r0]
	ldr r4, _08180AC4 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r7, _08180AC8 @ =0x0000046D
	adds r0, r6, r7
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r3, [r0]
	movs r2, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _08180ACC @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _08180AD0 @ =0x00000484
	adds r0, r6, r2
	str r3, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r6, r7
	bl ParticleShadow_Hide
_08180AB0:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08180AB8: .4byte 0x030046A0
_08180ABC: .4byte 0x0000046E
_08180AC0: .4byte 0x0000046B
_08180AC4: .4byte Enemy_ClearStateBegun
_08180AC8: .4byte 0x0000046D
_08180ACC: .4byte 0x00000469
_08180AD0: .4byte 0x00000484
