	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _0817EE40 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	mov r8, r3
	orrs r0, r3
	ldr r1, _0817EE44 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	add r7, sp, #0xc
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r3, _0817EE48 @ =Shaian_OnHurt
	str r5, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Enemy_RegisterHurtbox
	movs r1, #0x40
	add r0, sp, #0xc
	strh r1, [r0]
	movs r0, #0x64
	strh r0, [r7, #2]
	strh r1, [r7, #4]
	movs r0, #0
	strh r0, [r4]
	mov r1, r8
	strh r1, [r4, #2]
	strh r0, [r4, #4]
	movs r2, #0
	str r2, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	add r1, sp, #0xc
	adds r2, r4, #0
	ldr r3, _0817EE4C @ =Shaian_OnHit
	bl Enemy_InitAtkHitbox
	add r0, sp, #0xc
	mov r3, r8
	strh r3, [r0]
	strh r3, [r7, #2]
	strh r3, [r7, #4]
	movs r0, #0
	strh r0, [r4]
	strh r3, [r4, #2]
	strh r0, [r4, #4]
	ldr r1, _0817EE50 @ =0x000007B4
	add r1, sl
	mov sb, r1
	ldr r2, _0817EE54 @ =0x00002101
	movs r3, #0x10
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, sb
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0817EE58 @ =0x0000022A
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _0817EE5C @ =0x00000232
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xe
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	mov r0, sb
	movs r3, #0
	bl Hitbox_SetAttack
	adds r6, r5, #0
	adds r6, #8
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0817EE60 @ =FUN_0817eeb0
	mov r0, sb
	adds r2, r5, #0
	bl Hitbox_SetHandler
	movs r1, #0x96
	lsls r1, r1, #1
	add r0, sp, #0xc
	strh r1, [r0]
	mov r0, r8
	strh r0, [r7, #2]
	strh r1, [r7, #4]
	movs r1, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	strh r1, [r4, #4]
	ldr r2, _0817EE64 @ =0x00000804
	add sl, r2
	ldr r2, _0817EE68 @ =0x00002001
	movs r3, #0x10
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, sl
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x91
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xc
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	mov r0, sl
	movs r3, #0
	bl Hitbox_SetAttack
	mov r0, sl
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, sl
	ldr r1, _0817EE4C @ =Shaian_OnHit
	adds r2, r5, #0
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817EE40: .4byte 0xFFFF0000
_0817EE44: .4byte 0x0000FFFF
_0817EE48: .4byte Shaian_OnHurt
_0817EE4C: .4byte Shaian_OnHit
_0817EE50: .4byte 0x000007B4
_0817EE54: .4byte 0x00002101
_0817EE58: .4byte 0x0000022A
_0817EE5C: .4byte 0x00000232
_0817EE60: .4byte FUN_0817eeb0
_0817EE64: .4byte 0x00000804
_0817EE68: .4byte 0x00002001
