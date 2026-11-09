	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	mov sl, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r6, [r7, #0x44]
	ldr r2, _081860E4 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081860E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081860EA
	.align 2, 0
_081860E4: .4byte 0x0000046D
_081860E8:
	movs r0, #0
_081860EA:
	cmp r0, #0
	bne _081860F0
	b _0818620C
_081860F0:
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnimFlipOnly
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
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	movs r3, #0
	mov sb, r3
	orrs r0, r1
	ldr r1, _081861E0 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r5, _081861E4 @ =0x00000474
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r0, #0x41
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #1
	strh r0, [r1]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r5, sb
	strh r5, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, r8
	movs r1, #8
	bl ClearMemory
	ldr r5, _081861E8 @ =0x0203B400
	ldr r4, _081861EC @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _081861F0 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r0, #0x48
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r2, r2, r7
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #0x20
	rsbs r1, r1, #0
	orrs r0, r1
	ldr r1, _081861F4 @ =0x0000065E
	add r1, r8
	strh r0, [r1]
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r5, sb
	strh r5, [r0]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _081861C2
	rsbs r0, r0, #0
_081861C2:
	cmp r0, #9
	bgt _081861CA
	movs r0, #0xa
	strh r0, [r1]
_081861CA:
	movs r2, #2
	ldr r3, _081861F8 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081861FC
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08186206
	.align 2, 0
_081861E0: .4byte 0x0000FFF7
_081861E4: .4byte 0x00000474
_081861E8: .4byte 0x0203B400
_081861EC: .4byte 0x030046B8
_081861F0: .4byte 0x000003FF
_081861F4: .4byte 0x0000065E
_081861F8: .4byte 0x0000025D
_081861FC:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08186206:
	adds r0, r7, #0
	bl PlayEnemyDeathCry
_0818620C:
	ldr r0, _081862B8 @ =0x0000065E
	add r0, r8
	ldrb r0, [r0]
	ldrb r5, [r6, #6]
	adds r0, r0, r5
	strb r0, [r6, #6]
	ldrb r0, [r6, #6]
	movs r2, #0xd0
	lsls r2, r2, #1
	subs r2, r2, r0
	movs r3, #0xff
	ands r2, r3
	ldr r4, _081862BC @ =gSineTable
	adds r0, r2, #0
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #5
	adds r1, r1, r0
	asrs r1, r1, #0xb
	ldrh r0, [r6, #0x20]
	subs r0, r0, r1
	strh r0, [r6, #0x20]
	adds r2, #0x40
	ands r2, r3
	lsls r2, r2, #1
	adds r2, r2, r4
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r1, r0, #5
	adds r1, r1, r0
	asrs r1, r1, #0xb
	ldrh r0, [r6, #0x1c]
	subs r0, r0, r1
	strh r0, [r6, #0x1c]
	movs r1, #0x10
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08186268
	b _08186434
_08186268:
	movs r0, #0x40
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #8
	movs r1, #0x8a
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #1
	movs r2, #2
	movs r3, #0
	bl Entity081ea120_Spawn
	movs r0, #0xec
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r4, #1
	ldr r3, _081862C0 @ =0x0000025D
	adds r0, r7, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _081862C4
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r2, r1, #0
	b _081862D0
	.align 2, 0
_081862B8: .4byte 0x0000065E
_081862BC: .4byte gSineTable
_081862C0: .4byte 0x0000025D
_081862C4:
	ldr r2, [r7, #0x44]
	adds r1, r2, #0
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r4
	str r0, [r1, #8]
_081862D0:
	ldrb r0, [r3]
	cmp r0, #0
	bne _081862E2
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081862EE
_081862E2:
	adds r2, #0x20
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2, #8]
	ands r0, r1
	str r0, [r2, #8]
_081862EE:
	adds r0, r7, #0
	bl FUN_080e6658
	movs r5, #0xcd
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r0, [r2]
	cmp r0, #0
	beq _08186356
	movs r1, #8
	ldrsh r0, [r7, r1]
	str r0, [sp, #4]
	movs r3, #0xa
	ldrsh r0, [r7, r3]
	str r0, [sp, #8]
	movs r5, #0xc
	ldrsh r0, [r7, r5]
	str r0, [sp, #0xc]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r5, #0xd2
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	str r0, [sp, #0x18]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	ldrh r0, [r7]
	str r0, [sp, #0x20]
	ldr r1, _08186380 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	add r3, sp, #4
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_08186356:
	ldr r5, _08186384 @ =0x000001DF
	adds r0, r7, r5
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0818638C
	ldr r0, _08186388 @ =0x030046A0
	ldr r2, [r0]
	movs r5, #0xe2
	lsls r5, r5, #2
	adds r2, r2, r5
	movs r1, #1
	lsls r1, r3
	b _0818639E
	.align 2, 0
_08186380: .4byte 0xFFFF0000
_08186384: .4byte 0x000001DF
_08186388: .4byte 0x030046A0
_0818638C:
	ldr r0, _0818641C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_0818639E:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r4, _08186420 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r1, _08186424 @ =0x0000046D
	adds r0, r7, r1
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	ldr r5, _08186428 @ =0x0000046B
	adds r0, r7, r5
	strb r3, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r2, #0
	strh r3, [r0]
	movs r4, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _0818642C @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r3, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	movs r5, #0xe6
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	add r2, sp, #4
	movs r0, #8
	strh r0, [r2]
	adds r0, r2, #0
	strh r3, [r0, #2]
	ldr r0, _08186430 @ =0x00000664
	adds r1, r1, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _0818644C
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0xf
	add r1, sp, #4
	bl Enemy_SendMsgById
	b _0818644C
	.align 2, 0
_0818641C: .4byte 0x030046A0
_08186420: .4byte Enemy_ClearStateBegun
_08186424: .4byte 0x0000046D
_08186428: .4byte 0x0000046B
_0818642C: .4byte 0x0000046A
_08186430: .4byte 0x00000664
_08186434:
	mov r0, sl
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0818644C
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #8
	strh r0, [r1]
_0818644C:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
