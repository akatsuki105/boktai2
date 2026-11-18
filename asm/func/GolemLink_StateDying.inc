	push {r4, r5, r6, lr}
	sub sp, #0x34
	adds r5, r0, #0
	ldr r0, _081C1C78 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C1C7C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C1C7E
	.align 2, 0
_081C1C78: .4byte 0x0000046D
_081C1C7C:
	movs r0, #0
_081C1C7E:
	cmp r0, #0
	beq _081C1CF4
	adds r0, r5, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	ldr r1, _081C1D9C @ =0x0000046E
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
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r1, _081C1DA0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081C1DA4 @ =0x0000021E
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	adds r3, #0x8a
	adds r0, r5, r3
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl PlayGolemSound
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081C1CF4:
	adds r0, r5, #0
	bl Enemy_ClearDamage
	ldr r1, _081C1D9C @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C1D06
	b _081C1E7C
_081C1D06:
	ldr r2, _081C1DA8 @ =0x0000046B
	adds r0, r5, r2
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081C1D74
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp, #0xc]
	movs r3, #0xa
	ldrsh r0, [r5, r3]
	str r0, [sp, #0x10]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x14]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0x18]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	adds r3, #8
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldrh r0, [r5]
	str r0, [sp, #0x28]
	ldr r1, _081C1DAC @ =0xFFFF0000
	ldr r0, [sp, #0x2c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x2c]
	add r1, sp, #0x2c
	add r3, sp, #0xc
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_081C1D74:
	ldr r1, _081C1DB0 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081C1DB8
	ldr r0, _081C1DB4 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r4, #0
	lsls r1, r3
	b _081C1DCA
	.align 2, 0
_081C1D9C: .4byte 0x0000046E
_081C1DA0: .4byte 0xFFFEBE3F
_081C1DA4: .4byte 0x0000021E
_081C1DA8: .4byte 0x0000046B
_081C1DAC: .4byte 0xFFFF0000
_081C1DB0: .4byte 0x000001DF
_081C1DB4: .4byte 0x030046A0
_081C1DB8:
	ldr r0, _081C1E54 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_081C1DCA:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r5, #0
	adds r0, #8
	movs r1, #0x40
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0x80
	bl SpawnAttackBox
	ldr r2, _081C1E58 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _081C1E5C @ =0x0000046D
	adds r0, r5, r3
	movs r6, #1
	strb r6, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #2
	subs r3, #0xeb
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081C1E60 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081C1E64 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl ParticleShadow_Hide
	ldr r2, _081C1E68 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C1E6C
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	b _081C1E76
	.align 2, 0
_081C1E54: .4byte 0x030046A0
_081C1E58: .4byte Enemy_ClearStateBegun
_081C1E5C: .4byte 0x0000046D
_081C1E60: .4byte 0x0000046A
_081C1E64: .4byte 0x00000484
_081C1E68: .4byte 0x0000025D
_081C1E6C:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r6
	str r0, [r1, #8]
_081C1E76:
	adds r0, r5, #0
	bl PlayEnemyDeathCry
_081C1E7C:
	add sp, #0x34
	pop {r4, r5, r6}
	pop {r0}
	bx r0
