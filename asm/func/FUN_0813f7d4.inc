	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _0813F7F0 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F7F4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F7F6
	.align 2, 0
_0813F7F0: .4byte 0x0000046D
_0813F7F4:
	movs r0, #0
_0813F7F6:
	cmp r0, #0
	beq _0813F838
	adds r0, r6, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	adds r0, r6, #0
	bl PlayEnemyDeathCry
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _0813F8E0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _0813F8E4 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r7, _0813F8E8 @ =0x00000202
	adds r0, r6, r7
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_0813F838:
	ldr r0, [r6, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0813F84C
	b _0813F98A
_0813F84C:
	ldr r1, _0813F8EC @ =0x0000046B
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0813F8B6
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
	ldr r1, _0813F8F0 @ =0xFFFF0000
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
_0813F8B6:
	ldr r1, _0813F8F4 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0813F8FC
	ldr r0, _0813F8F8 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _0813F90E
	.align 2, 0
_0813F8E0: .4byte 0xFFFEBE3F
_0813F8E4: .4byte 0x0000021E
_0813F8E8: .4byte 0x00000202
_0813F8EC: .4byte 0x0000046B
_0813F8F0: .4byte 0xFFFF0000
_0813F8F4: .4byte 0x000001DF
_0813F8F8: .4byte 0x030046A0
_0813F8FC:
	ldr r0, _0813F994 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0813F90E:
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
	bne _0813F92C
	adds r0, r6, #0
	bl FUN_080e6658
_0813F92C:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _0813F998 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r7, _0813F99C @ =0x0000046D
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
	ldr r4, _0813F9A0 @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _0813F9A4 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r6, r7
	bl ParticleShadow_Hide
_0813F98A:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813F994: .4byte 0x030046A0
_0813F998: .4byte Enemy_ClearStateBegun
_0813F99C: .4byte 0x0000046D
_0813F9A0: .4byte 0x00000469
_0813F9A4: .4byte 0x00000484
