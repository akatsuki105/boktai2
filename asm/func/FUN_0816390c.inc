	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08163928 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816392C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816392E
	.align 2, 0
_08163928: .4byte 0x0000046D
_0816392C:
	movs r0, #0
_0816392E:
	cmp r0, #0
	beq _08163956
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_080efe38
	adds r0, r5, #0
	bl PlayEnemyDeathCry
	adds r0, r5, #0
	bl FUN_081647c8
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x39
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08163956:
	movs r2, #0x80
	lsls r2, r2, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0816396C
	b _08163AFA
_0816396C:
	ldr r0, [r5, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08163980
	b _08163AB4
_08163980:
	ldr r1, _08163A10 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081639E8
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r5, r3]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r3, #8
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	str r0, [sp, #0x1c]
	ldr r1, _08163A14 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r3, sp
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_081639E8:
	ldr r1, _08163A18 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08163A20
	ldr r0, _08163A1C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r4, #0
	lsls r1, r3
	b _08163A32
	.align 2, 0
_08163A10: .4byte 0x0000046B
_08163A14: .4byte 0xFFFF0000
_08163A18: .4byte 0x000001DF
_08163A1C: .4byte 0x030046A0
_08163A20:
	ldr r0, _08163A9C @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_08163A32:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _08163A4A
	adds r0, r5, #0
	bl FUN_080e6658
_08163A4A:
	ldr r4, _08163AA0 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r2, _08163AA4 @ =0x0000046D
	adds r0, r5, r2
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	ldr r6, _08163AA8 @ =0x0000046B
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r1, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r3, [r0]
	ldr r3, _08163AAC @ =0x0000046A
	adds r0, r5, r3
	strb r4, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r1, _08163AB0 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _08163AFA
	.align 2, 0
_08163A9C: .4byte 0x030046A0
_08163AA0: .4byte Enemy_ClearStateBegun
_08163AA4: .4byte 0x0000046D
_08163AA8: .4byte 0x0000046B
_08163AAC: .4byte 0x0000046A
_08163AB0: .4byte 0x0000046C
_08163AB4:
	movs r1, #1
	ldr r2, _08163ACC @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08163AD0
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08163ADA
	b _08163ADE
	.align 2, 0
_08163ACC: .4byte 0x0000025D
_08163AD0:
	ldr r0, [r5, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _08163ADE
_08163ADA:
	movs r0, #1
	b _08163AE0
_08163ADE:
	movs r0, #0
_08163AE0:
	cmp r0, #0
	beq _08163AF0
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r5, r3
	bl ParticleShadow_Hide
	b _08163AFA
_08163AF0:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl ParticleShadow_Show
_08163AFA:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
