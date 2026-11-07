	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _081434FC @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143500
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143502
	.align 2, 0
_081434FC: .4byte 0x0000046D
_08143500:
	movs r0, #0
_08143502:
	cmp r0, #0
	beq _08143544
	adds r0, r6, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	adds r0, r6, #0
	bl PlayEnemyDeathCry
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _081435EC @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081435F0 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r7, _081435F4 @ =0x00000202
	adds r0, r6, r7
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_08143544:
	ldr r0, [r6, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08143558
	b _08143696
_08143558:
	ldr r1, _081435F8 @ =0x0000046B
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081435C2
	movs r7, #8
	ldrsh r0, [r6, r7]
	str r0, [sp]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	str r0, [sp, #4]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
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
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _081435FC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_081435C2:
	ldr r1, _08143600 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08143608
	ldr r0, _08143604 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _0814361A
	.align 2, 0
_081435EC: .4byte 0xFFFEBE3F
_081435F0: .4byte 0x0000021E
_081435F4: .4byte 0x00000202
_081435F8: .4byte 0x0000046B
_081435FC: .4byte 0xFFFF0000
_08143600: .4byte 0x000001DF
_08143604: .4byte 0x030046A0
_08143608:
	ldr r0, _081436A0 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0814361A:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08143638
	adds r0, r6, #0
	bl FUN_080e6658
_08143638:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _081436A4 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r7, _081436A8 @ =0x0000046D
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
	ldr r4, _081436AC @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _081436B0 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r6, r7
	bl ParticleShadow_Hide
_08143696:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081436A0: .4byte 0x030046A0
_081436A4: .4byte Enemy_ClearStateBegun
_081436A8: .4byte 0x0000046D
_081436AC: .4byte 0x00000469
_081436B0: .4byte 0x00000484
