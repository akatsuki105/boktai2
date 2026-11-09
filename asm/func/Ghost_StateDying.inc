	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x4c
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0816BC64 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816BC68
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816BC6A
	.align 2, 0
_0816BC64: .4byte 0x0000046D
_0816BC68:
	movs r0, #0
_0816BC6A:
	cmp r0, #0
	beq _0816BD1A
	adds r0, r4, #0
	movs r1, #0xa
	bl Enemy_PlayAnim
	adds r0, r4, #0
	bl PlayEnemyDeathCry
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r4, r3
	ldr r1, _0816BDC0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r7, _0816BDC4 @ =0x0000021E
	adds r0, r4, r7
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, #0x8a
	adds r0, r4, r3
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl Ghost_RestorePlayerSpeed
	movs r1, #0x80
	lsls r1, r1, #7
	subs r7, #0x9e
	adds r0, r4, r7
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816BD1A
	ldr r2, _0816BDC8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816BDCC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816BDD0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r6, r0, #1
	adds r7, r4, #0
	adds r7, #8
	ldrh r3, [r4, #8]
	ldrh r5, [r4, #0xa]
	ldrh r2, [r4, #0xc]
	add r0, sp, #0xc
	movs r1, #2
_0816BCEC:
	strh r3, [r0]
	strh r5, [r0, #2]
	strh r2, [r0, #4]
	adds r0, #8
	subs r1, #1
	cmp r1, #0
	bge _0816BCEC
	movs r0, #0x84
	lsls r0, r0, #4
	add r0, r8
	ldrb r2, [r0]
	add r3, sp, #0xc
	str r3, [sp]
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [sp, #4]
	movs r0, #0x78
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	adds r3, r7, #0
	bl SpawnSpiritBugsAt
_0816BD1A:
	ldr r7, _0816BDD4 @ =0x0000046E
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816BD26
	b _0816BE6A
_0816BD26:
	ldr r1, _0816BDD8 @ =0x0000046B
	adds r0, r4, r1
	movs r5, #1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0816BD96
	movs r7, #8
	ldrsh r0, [r4, r7]
	str r0, [sp, #0x24]
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x28]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	str r0, [sp, #0x2c]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r4, r7
	ldr r0, [r0]
	str r0, [sp, #0x30]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	str r0, [sp, #0x34]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [sp, #0x38]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r4, r7
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	ldrh r0, [r4]
	str r0, [sp, #0x40]
	ldr r1, _0816BDDC @ =0xFFFF0000
	ldr r0, [sp, #0x44]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x44]
	add r0, sp, #0x24
	add r1, sp, #0x44
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_0816BD96:
	ldr r1, _0816BDE0 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r4, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0816BDE8
	ldr r0, _0816BDE4 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r5, #0
	lsls r1, r3
	b _0816BDFA
	.align 2, 0
_0816BDC0: .4byte 0xFFFEBE3F
_0816BDC4: .4byte 0x0000021E
_0816BDC8: .4byte 0x030046B8
_0816BDCC: .4byte 0x000003FF
_0816BDD0: .4byte 0x0203B400
_0816BDD4: .4byte 0x0000046E
_0816BDD8: .4byte 0x0000046B
_0816BDDC: .4byte 0xFFFF0000
_0816BDE0: .4byte 0x000001DF
_0816BDE4: .4byte 0x030046A0
_0816BDE8:
	ldr r0, _0816BE78 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r5, #0
	lsls r1, r0
_0816BDFA:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r6, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0816BE6A
	ldr r3, _0816BE7C @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r7, _0816BE80 @ =0x0000046D
	adds r0, r4, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
	adds r0, r4, r7
	strb r6, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	movs r2, #2
	subs r7, #0xeb
	adds r0, r4, r7
	strb r1, [r0]
	ldr r3, _0816BE84 @ =0x00000469
	adds r0, r4, r3
	strb r6, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r2, [r0]
	ldr r2, _0816BE88 @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r1, [r0]
_0816BE6A:
	add sp, #0x4c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816BE78: .4byte 0x030046A0
_0816BE7C: .4byte Enemy_ClearStateBegun
_0816BE80: .4byte 0x0000046D
_0816BE84: .4byte 0x00000469
_0816BE88: .4byte 0x00000484
