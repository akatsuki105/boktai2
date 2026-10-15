	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x20]
	adds r7, r1, #0
	movs r1, #0
	movs r2, #0
	strb r1, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	strh r2, [r7, #6]
	strb r1, [r7, #0xa]
	strb r1, [r7, #0xb]
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r1, _0805A5A8 @ =0x00003668
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	movs r1, #0xc8
	bl Video_SetAuxSpritePltt
	adds r4, r7, #0
	adds r4, #0xf8
	movs r5, #0
	add r1, sp, #0x10
	mov sb, r1
	add r2, sp, #0x18
	mov sl, r2
_0805A580:
	adds r0, r4, #0
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #1
	bl AuxSprite_Add
	cmp r5, #0
	bne _0805A5AC
	ldr r0, [sp, #0x20]
	ldr r1, [r0, #0x20]
	str r5, [sp]
	adds r0, r7, #0
	adds r0, #0xe8
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #1
	b _0805A5B2
	.align 2, 0
_0805A5A8: .4byte 0x00003668
_0805A5AC:
	adds r0, r5, #3
	strh r0, [r4, #0x10]
	movs r0, #2
_0805A5B2:
	strb r0, [r4, #7]
	adds r1, r4, #0
	adds r1, #0x1c
	movs r2, #0
	mov r8, r2
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0805A6A8 @ =0x05000002
	bl CpuSet
	adds r5, #1
	adds r4, #0x2c
	cmp r5, #3
	ble _0805A580
	adds r6, r7, #0
	adds r6, #0x98
	ldr r2, _0805A6AC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #0x20
	orrs r0, r4
	ldr r1, _0805A6B0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r1, sb
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r1, #4]
	mov r0, r8
	str r0, [sp, #0x18]
	mov r1, sl
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805A6B4 @ =0x00005005
	movs r5, #0x10
	str r5, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r1, r7, #0
	adds r1, #0x14
	str r1, [sp, #0x24]
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805A6B8 @ =FUN_0805a470
	adds r0, r6, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1e]
	ldr r2, _0805A6BC @ =0x00000202
	adds r0, r6, #0
	movs r3, #1
	bl Hitbox_SetPowerAndAttributes
	adds r0, r6, #0
	bl Hitbox_Register
	subs r6, #0x50
	add r0, sp, #0x10
	strh r4, [r0]
	movs r0, #0x64
	mov r1, sb
	strh r0, [r1, #2]
	strh r4, [r1, #4]
	add r0, sp, #0x18
	mov r2, r8
	strh r2, [r0]
	mov r0, sl
	strh r2, [r0, #2]
	strh r2, [r0, #4]
	ldr r2, _0805A6C0 @ =0x00002001
	str r5, [sp]
	str r1, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r6, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805A6C4 @ =FUN_0805a52c
	adds r0, r6, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1c]
	movs r0, #2
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0x1e
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A6A8: .4byte 0x05000002
_0805A6AC: .4byte 0xFFFF0000
_0805A6B0: .4byte 0x0000FFFF
_0805A6B4: .4byte 0x00005005
_0805A6B8: .4byte FUN_0805a470
_0805A6BC: .4byte 0x00000202
_0805A6C0: .4byte 0x00002001
_0805A6C4: .4byte FUN_0805a52c
