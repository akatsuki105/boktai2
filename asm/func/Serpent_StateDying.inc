	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r0, _0818B1E4 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818B1E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818B1EA
	.align 2, 0
_0818B1E4: .4byte 0x0000046D
_0818B1E8:
	movs r0, #0
_0818B1EA:
	cmp r0, #0
	beq _0818B252
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
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _0818B34C @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _0818B350 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r4, _0818B354 @ =0x00000202
	adds r0, r6, r4
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xd8
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0xd2
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0818B252:
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _0818B27A
	adds r4, r6, #0
	adds r4, #8
	ldrb r2, [r6, #5]
	adds r0, r4, #0
	movs r1, #5
	movs r3, #0
	bl FUN_08192ae0
	ldrb r2, [r6, #5]
	adds r0, r4, #0
	movs r1, #5
	movs r3, #1
	bl FUN_08192ae0
_0818B27A:
	ldr r0, [r6, #0x44]
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818B28E
	b _0818B488
_0818B28E:
	adds r4, r6, #0
	adds r4, #8
	ldrb r2, [r6, #5]
	adds r0, r4, #0
	movs r1, #8
	movs r3, #0
	bl FUN_08192ae0
	ldrb r2, [r6, #5]
	adds r0, r4, #0
	movs r1, #8
	movs r3, #1
	bl FUN_08192ae0
	adds r0, r6, #0
	bl FUN_081906d4
	movs r1, #0x80
	lsls r1, r1, #3
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0818B2C8
	adds r0, r6, #0
	bl FUN_080e6658
_0818B2C8:
	movs r0, #0xcd
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _0818B32A
	movs r1, #8
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r6, r3]
	str r0, [sp, #4]
	movs r4, #0xc
	ldrsh r0, [r6, r4]
	str r0, [sp, #8]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _0818B358 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r7, sp
	str r7, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_0818B32A:
	ldr r1, _0818B35C @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	cmp r0, #0x1f
	bgt _0818B364
	ldr r3, _0818B360 @ =0x030046A0
	ldr r2, [r3]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	b _0818B370
	.align 2, 0
_0818B34C: .4byte 0xFFFEBE3F
_0818B350: .4byte 0x0000021E
_0818B354: .4byte 0x00000202
_0818B358: .4byte 0xFFFF0000
_0818B35C: .4byte 0x000001DF
_0818B360: .4byte 0x030046A0
_0818B364:
	ldr r3, _0818B390 @ =0x030046A0
	ldr r2, [r3]
	movs r7, #0xe3
	lsls r7, r7, #2
	adds r2, r2, r7
	subs r0, #0x20
_0818B370:
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r3]
	ldr r1, _0818B394 @ =0x00000948
	adds r2, r0, r1
	ldrh r4, [r2]
	movs r7, #0
	ldrsh r1, [r2, r7]
	ldr r0, _0818B398 @ =0x0000270E
	cmp r1, r0
	bgt _0818B39C
	adds r0, r4, #1
	b _0818B3A0
	.align 2, 0
_0818B390: .4byte 0x030046A0
_0818B394: .4byte 0x00000948
_0818B398: .4byte 0x0000270E
_0818B39C:
	ldr r1, _0818B3BC @ =0x0000270F
	adds r0, r1, #0
_0818B3A0:
	strh r0, [r2]
	ldr r0, [r3]
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r3, r0, r2
	ldrh r2, [r3]
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldr r0, _0818B3C0 @ =0x0000270E
	cmp r1, r0
	bgt _0818B3C4
	adds r0, r2, #1
	b _0818B3C8
	.align 2, 0
_0818B3BC: .4byte 0x0000270F
_0818B3C0: .4byte 0x0000270E
_0818B3C4:
	ldr r7, _0818B400 @ =0x0000270F
	adds r0, r7, #0
_0818B3C8:
	strh r0, [r3]
	adds r0, r6, #0
	bl Enemy_AddKillCount
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl AddPlayerExp
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ldr r3, _0818B404 @ =0x00000189
	adds r1, r6, r3
	ldrb r1, [r1]
	bl Player_AddWeaponExp
	ldr r0, _0818B408 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0818B40C
	movs r0, #1
	b _0818B40E
	.align 2, 0
_0818B400: .4byte 0x0000270F
_0818B404: .4byte 0x00000189
_0818B408: .4byte 0x030047A4
_0818B40C:
	movs r0, #0
_0818B40E:
	cmp r0, #0
	bne _0818B42E
	movs r1, #0x80
	lsls r1, r1, #4
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0818B42E
	ldr r0, _0818B490 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r6]
	bl DefeatedEnemyLog_Add
_0818B42E:
	movs r7, #0xc9
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _0818B494 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r1, _0818B498 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r7, _0818B49C @ =0x0000046B
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
	ldr r4, _0818B4A0 @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _0818B4A4 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #1
	adds r0, r6, r7
	strb r1, [r0]
_0818B488:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818B490: .4byte 0x03002B28
_0818B494: .4byte Enemy_ClearStateBegun
_0818B498: .4byte 0x0000046D
_0818B49C: .4byte 0x0000046B
_0818B4A0: .4byte 0x00000469
_0818B4A4: .4byte 0x00000484
