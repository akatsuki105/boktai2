	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	ldr r2, _0819DF9C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _0819DFA0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x8c
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r3, _0819DFA4 @ =Ax_OnHurt
	str r6, [sp]
	adds r0, r6, #0
	add r1, sp, #0xc
	adds r2, r4, #0
	bl Enemy_RegisterHurtbox
	add r2, sp, #0x1c
	mov sl, r2
	add r3, sp, #0x24
	mov sb, r3
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp, #0x30]
	ldr r1, [sp, #0x2c]
	ldr r2, _0819DFA8 @ =0x00000D9C
	adds r5, r1, r2
	movs r7, #1
_0819DE3E:
	ldrh r1, [r6]
	movs r3, #0x10
	mov r8, r3
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	ldr r2, _0819DFAC @ =0x00004001
	movs r3, #0
	bl Hitbox_Init
	movs r1, #0xc3
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r3, [r0]
	adds r0, r5, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r5, #0
	adds r1, r6, #0
	adds r1, #8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	ldr r1, _0819DFA4 @ =Ax_OnHurt
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r5, #0
	bl Hitbox_Register
	adds r5, #0x50
	subs r7, #1
	cmp r7, #0
	bge _0819DE3E
	ldr r2, _0819DF9C @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _0819DFA0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x1c]
	mov r1, sl
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	movs r0, #0
	str r0, [sp, #0x24]
	mov r3, sb
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r5, _0819DFB0 @ =0x00002401
	movs r0, #0x94
	lsls r0, r0, #1
	adds r4, r6, r0
	ldrh r1, [r6]
	mov r2, r8
	str r2, [sp]
	mov r3, sl
	str r3, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl Hitbox_Init
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r6, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	adds r0, r4, #0
	ldr r1, [sp, #0x30]
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0819DFB4 @ =Ax_OnHit
	adds r0, r4, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	ldr r0, [sp, #0x2c]
	ldr r1, _0819DFB8 @ =0x00000CFC
	adds r4, r0, r1
	lsls r5, r5, #0x10
	movs r7, #1
_0819DF2C:
	ldrh r1, [r6]
	movs r0, #0x10
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	mov r3, sb
	str r3, [sp, #8]
	adds r0, r4, #0
	lsrs r2, r5, #0x10
	movs r3, #0
	bl Hitbox_Init
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r6, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	adds r0, r4, #0
	ldr r1, [sp, #0x30]
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	ldr r1, _0819DFB4 @ =Ax_OnHit
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r4, #0x50
	subs r7, #1
	cmp r7, #0
	bge _0819DF2C
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819DF9C: .4byte 0xFFFF0000
_0819DFA0: .4byte 0x0000FFFF
_0819DFA4: .4byte Ax_OnHurt
_0819DFA8: .4byte 0x00000D9C
_0819DFAC: .4byte 0x00004001
_0819DFB0: .4byte 0x00002401
_0819DFB4: .4byte Ax_OnHit
_0819DFB8: .4byte 0x00000CFC
