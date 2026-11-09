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
	mov sb, r0
	ldr r2, _0813824C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08138250 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0
	mov r8, r2
	ldr r0, _08138254 @ =0x00000B3A
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov sl, r1
	cmp r8, r0
	bge _08138192
	ldr r7, _08138258 @ =0x00000674
	add r7, sb
	movs r4, #0xde
	lsls r4, r4, #3
	add r4, sb
	movs r6, #0xcb
	lsls r6, r6, #3
	add r6, sb
_0813813A:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	adds r0, r4, #0
	ldr r2, _0813825C @ =0x00004109
	movs r3, #0
	bl Hitbox_Init
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	ldr r1, _08138260 @ =FUN_08137f30
	adds r2, r6, #0
	bl Hitbox_SetHandler
	movs r0, #0x90
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, r6, r0
	movs r1, #1
	add r8, r1
	ldr r0, _08138254 @ =0x00000B3A
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	blt _0813813A
_08138192:
	movs r3, #0
	movs r2, #0x40
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	mov r0, sl
	strh r3, [r0]
	add r1, sp, #0x14
	movs r0, #0x80
	strh r0, [r1, #2]
	strh r3, [r1, #4]
	mov r8, r3
	ldr r0, _08138254 @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	bge _0813823C
	ldr r7, _08138258 @ =0x00000674
	add r7, sb
	movs r4, #0xd4
	lsls r4, r4, #3
	add r4, sb
	movs r6, #0xcb
	lsls r6, r6, #3
	add r6, sb
_081381CC:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r2, sp, #0xc
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	adds r0, r4, #0
	ldr r2, _08138264 @ =0x00002401
	movs r3, #0
	bl Hitbox_Init
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	ldr r1, _08138268 @ =FUN_08137f2c
	adds r2, r6, #0
	bl Hitbox_SetHandler
	movs r0, #0x90
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, r6, r0
	movs r1, #1
	add r8, r1
	ldr r0, _08138254 @ =0x00000B3A
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	blt _081381CC
_0813823C:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813824C: .4byte 0xFFFF0000
_08138250: .4byte 0x0000FFFF
_08138254: .4byte 0x00000B3A
_08138258: .4byte 0x00000674
_0813825C: .4byte 0x00004109
_08138260: .4byte FUN_08137f30
_08138264: .4byte 0x00002401
_08138268: .4byte FUN_08137f2c
