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
	ldr r6, [r0]
	ldr r2, _08191060 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08191064 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
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
	mov sb, r2
	ldr r3, _08191068 @ =0x00000F36
	adds r0, r6, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov sl, r1
	cmp sb, r0
	bge _081910C8
	ldr r3, _0819106C @ =0x00000674
	adds r3, r3, r6
	mov r8, r3
	movs r0, #0xde
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r7, r6, r1
_0819101A:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r2, sp, #0xc
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	adds r0, r4, #0
	ldr r2, _08191070 @ =0x00005009
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _08191068 @ =0x00000F36
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #1
	cmp sb, r0
	bne _08191078
	ldr r3, _08191074 @ =0x00000ED3
	adds r0, r6, r3
	ldrb r1, [r0]
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r3, [r0]
	adds r0, r4, #0
	bl Hitbox_SetPowerAndAttributes
	b _08191094
	.align 2, 0
_08191060: .4byte 0xFFFF0000
_08191064: .4byte 0x0000FFFF
_08191068: .4byte 0x00000F36
_0819106C: .4byte 0x00000674
_08191070: .4byte 0x00005009
_08191074: .4byte 0x00000ED3
_08191078:
	ldr r1, _08191184 @ =0x00000ED2
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r3, [r0]
	adds r0, r4, #0
	bl Hitbox_SetPowerAndAttributes
_08191094:
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	ldr r1, _08191188 @ =FUN_08190d1c
	adds r2, r7, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	movs r0, #0x92
	lsls r0, r0, #1
	add r8, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r1, #1
	add sb, r1
	ldr r2, _0819118C @ =0x00000F36
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp sb, r0
	blt _0819101A
_081910C8:
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
	mov sb, r3
	ldr r1, _0819118C @ =0x00000F36
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	bge _08191174
	ldr r3, _08191190 @ =0x00000674
	adds r3, r3, r6
	mov r8, r3
	movs r0, #0xd4
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r7, r6, r1
_08191104:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r2, sp, #0xc
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	adds r0, r4, #0
	ldr r2, _08191194 @ =0x00002401
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
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	ldr r1, _08191198 @ =FUN_08190d18
	adds r2, r7, #0
	bl Hitbox_SetHandler
	movs r0, #0x92
	lsls r0, r0, #1
	add r8, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r1, #1
	add sb, r1
	ldr r2, _0819118C @ =0x00000F36
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp sb, r0
	blt _08191104
_08191174:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08191184: .4byte 0x00000ED2
_08191188: .4byte FUN_08190d1c
_0819118C: .4byte 0x00000F36
_08191190: .4byte 0x00000674
_08191194: .4byte 0x00002401
_08191198: .4byte FUN_08190d18
